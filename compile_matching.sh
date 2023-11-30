set -e

ASMSH_FLAGS="-debug=d -cpu=sh4 -endian=little -sjis"

assemble() {
  local src_file="$1"
  local base_name=$(basename "$src_file" .src)
  local obj_file="build\\$base_name.obj"

  wine "$SHC_BIN/asmsh.exe" $(echo "$src_file"| tr / '\\') -object="$obj_file" $ASMSH_FLAGS
}

compile() {
  local src_file="$1"
  local base_name=$(basename "$src_file" .c)
  local obj_file="build\\$base_name.obj"

  wine "$SHC_BIN/shc.exe" $(echo "$src_file" | tr / '\\') -object="$obj_file" -sub=shc.sub
}

rm -r build/*

assemble src/_000000_8c010000.src
compile  src/_000128_8c010080_main.c
assemble src/_000188_8c0100bc_sound.src
compile  src/_003728_8c010e90.c
assemble src/_004072_8c010fe8.src
assemble src/_004384_8c011120.src
assemble src/_008160_data.src
assemble src/_008996_8c012324.src
assemble src/_009476_8c012504.src
assemble src/_010700_8c0129cc.src
assemble src/_012100_8c012f44.src
assemble src/_015080_8c013ae8.src
compile  src/_018740_8c014934.c
compile  src/_018864_8c0149b0_sbinit.c
compile  src/_019100_8c014a9c_tasks.c
compile  src/_019340_8c014b8c_backup.c
assemble src/_020308_8c014f54.src
assemble src/_023224_8c015ab8_title.src
compile  src/_024840_8c016108.c
assemble src/_024908_8c01614c.src
assemble src/_027636_8c016bf4.src
assemble src/_027736_8c016c58.src
assemble src/_027948_8c016d2c.src
assemble src/_034372_8c018644.src
assemble src/_034692_8c018784.src
assemble src/_037832_8c0193c8.src
assemble src/_040600_8c019e98.src
assemble src/_041288_8c01a148.src
assemble src/_045468_8c01b19c.src
assemble src/_047944_8c01bb48.src
assemble src/_051584_8c01c980.src
assemble src/_053904_8c01d290.src
assemble src/_055292_8c01d7fc.src
assemble src/_057980_8c01e27c.src
assemble src/_062400_8c01f3c0.src
assemble src/_064120_8c01fa78.src
assemble src/_066068_8c020214.src
assemble src/_066856_8c020528.src
assemble src/_066964_8c020594.src
assemble src/_067312_8c0206f0.src
assemble src/_067540_8c0207d4.src
assemble src/_067612_8c02081c.src
assemble src/_067860_8c020914.src
assemble src/_068460_8c020b6c.src
assemble src/_071452_8c02171c.src
assemble src/_072604_8c021b9c.src
assemble src/_074460_8c0222dc.src
assemble src/_074852_8c022464.src
assemble src/_076764_8c022bdc.src
assemble src/_078608_8c023310.src
assemble src/_080184_8c023938.src
assemble src/_082220_8c02412c.src
assemble src/_082560_8c024280.src
assemble src/_084812_8c024b4c.src
assemble src/_088176_8c025870.src
assemble src/_088984_8c025b98.src
assemble src/_091920_8c026710.src
assemble src/_096364_8c02786c.src
assemble src/_096600_8c027958.src
assemble src/_098904_8c028258.src
assemble src/_110456_8c02af78.src
assemble src/_111344_8c02b2f0.src
assemble src/_111716_8c02b464.src
assemble src/_116868_8c02c884.src
assemble src/_118892_8c02d06c.src
assemble src/_119196_8c02d19c.src
assemble src/_121192_8c02d968.src
assemble src/_122684_8c02df3c.src
assemble src/_123612_8c02e2dc.src
assemble src/_123904_8c02e400.src
assemble src/_124188_8c02e51c.src
assemble src/_127176_8c02f0c8.src
assemble src/_127776_8c02f320.src
assemble src/_129872_8c02fb50_sh4nlfzn.src
assemble src/_143996_8c03327c_strt1_sectionC.src
assemble src/_144036_8c0332a4_sectionC.src
assemble src/_179584_8c03bd80_sectionD.src
assemble src/_259776_8c04f6c0_SDK.src
assemble src/_970016_8c0fcd20_sectionB.src

wine $SHC_BIN/lnk.exe -sub=lnk_matching.sub

rm -f build/tbg.bin
wine $KATANA_SDK_DIR/bin/elf2bin.exe -s 8c010000 build/tbg.elf

echo

if ! sha1sum --status -c <<<"a6df9e0de39b2d11e9339aef915d20e35763ec81 *build/tbg.bin"; then
    echo "======================"
    echo "Oops, build differs :/"
    echo "======================"
    exit 1
fi

echo "====================="
echo "Yay! Build matches :)"
echo "====================="

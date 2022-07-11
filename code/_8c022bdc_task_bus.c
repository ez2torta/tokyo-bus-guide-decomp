#include "includes.h"

extern int _8c0fcd28;
extern int _8c18ad20;
extern void *_8c1bb868;
extern int _8c1bb8c8;
extern void *bus_state_8c1bb9d0;
extern int _8c1bbd9c;
extern int _8c2264d4;
extern float _8c227db0;
extern float _8c227db4;
extern int _8c228660;

struct BusState {
    int distance_traveled_0x070;
    int ang_0x074;
    int acc_0x078;
    int ang_0x07c;
    int blinker_0x080;

    float field_0x0f4;
    float field_0x100;

    int ang_0x250;
    int ang_0x258;

    int mirror_0x268;

    int bus_state_0x2b4;

    float field_0x278;
    float speed_0x27c;
    float acc_hist_0x280[4];

    int gear_0x2f4;

    int boarding_state_0x3c0;
    int field_0x3c4;
}
typedef BusState;
BusState bus_state_8c1bb9d0;

void _8c022bdc_task_bus(Task *task, void *state) {
    int local_34;

    // 8c022bf4  add       #-0x4,r15

    // 8c022bf8  mov.l     ->bus_state_8c1bb9d0,r14                   = 8c1bb9d0

    // 8c022bfa  mov       #0x4,r9
    // 8c022bfe  mov       r9,r0
      // r0 = r9 = 4

    // 8c022c00  mov.l     DAT_8c022cec,r10                           = 8C1BB868h
    //  8c022c08  mov.l     @(0x4,r10)=>DAT_8c1bb86c,r3                = ??
    //  8c022c04  mov.l     DAT_8c022cf8,r2                            = 8C2264D4h
    //  8c022c0c  mov.l     r3,@r2=>DAT_8c2264d4
    _8c2264d4 = _8c1bb868->field_0x4;

    // 8c022c02  mov       #0x0,r13
    //  8c022c06  add       #0x7c,r0
    //  8c022c0a  mov.l     DAT_8c022cfc,r1                            = 8C228660h
    //  8c022c14  mov.l     r13,@r1=>DAT_8c228660
    //  8c022c16  mov.l     r13,@(r0,r14)=>DAT_8c1bba50                = ??
    _8c228660 = 0;
    bus_state_8c1bb9d0.blinker_0x080 = 0;

    // 8c022c1e  add       #-0x4,r0
    //  8c022bf6  mova      DAT_8c022ce4,r0                            = 47800000h
    //  8c022bfc  fmov.s    @r0=>DAT_8c022ce4,fr13                     = 47800000h (65536.0)
      // fr13 = 65536.0
    //  8c022c0e  mov.l     ->FUN_8c02ff08,r3                          = 8c02ff08
    // 8c022c20  jsr       @r3=>FUN_8c02ff08                          ulonglong FUN_8c02ff08(void)
    // 8c022c22  _fmov.s   @(r0,r14),fr4=>DAT_8c1bbc48                = ??
    // 8c022c24  fmul      fr13,fr0
    float fr0 = _8c02ff08(bus_state_8c1bb9d0.field_0x278);
    fr0 *= 65536.0;

    // 8c022c26  mova      FLOAT_8c022d04,r0                            = 6.283184
    // 8c022c28  fmov.s    @r0=>FLOAT_8c022d04,fr3                      = 6.283184
    // 8c022c2c  fdiv      fr3,fr0
    fr0 /= 6.283184;

    // 8c022c2e  ftrc      fr0,FPUL
    // 8c022c30  sts       FPUL,r3
    // 8c022c32  mov.l     r3,@r15=>local_34
    local_34 = (int) fr0;

    //  8c022c2a  mov.w     WORD_8c022cda,r0                           = 100h
    // 8c022c34  fmov.s    @(r0,r14),fr2=>DAT_8c1bbad0
    // 8c022c36  add       #-0xc,r0
    // 8c022c38  fmov.s    @(r0,r14),fr1=>DAT_8c1bbac4
    // 8c022c3a  fcmp/gt   fr2,fr1
    // 8c022c3c  bf        LAB_8c022c44
    // 8c022c3e  mov.l     @r15=>local_34,r2
    // 8c022c40  neg       r2,r2
    // 8c022c42  mov.l     r2,@r15=>local_34
    if (bus_state_8c1bb9d0.field_0x0f4 > bus_state_8c1bb9d0.field_0x100) {
        local_34 = -local_34;
    }

    // 8c022c44  mov.w     WORD_8c022cdc,r0                           = 250h
    // 8c022c46  mov.l     @r15=>local_34,r3
    //  8c022c4a  mov.l     r3,@(r0,r14)=>DAT_8c1bbc20                 = ??
    bus_state_8c1bb9d0.ang_0x250 = local_34;

    // ================
    // SHARED REGISTERS
    // ================

    // 8c022c18  mov.w     WORD_8c022cd8,r0                           = 27Ch
    //  8c022c1c  fmov.s    @(r0,r14),fr15=>DAT_8c1bbc4c               = ??
      // fr15 = bus_state_8c1bb9d0.speed_0x27c;
    float speed_fr15 = bus_state_8c1bb9d0.speed_0x27c;

    // 8c022c10  mov.l     ->FUN_8c051618,r8                          = 8c051618
    // 8c022c12  mov.l     DAT_8c022cf0,r11                           = 8C0FCD28h

    //  8c022c1a  fldi0     fr14
    
    //  8c022c48  mov.l     PTR_DAT_8c022d0c,r12                       = 8c227db0

    //  8c022c4c  mova      FLOAT_8c022d08,r0                          = 0.5
    //  8c022c4e  fmov.s    @r0=>FLOAT_8c022d08,fr4                    = 0.5

    //  8c022c50  mov.w     WORD_8c022cde,r0                           = 3C0h
    //  8c022c52  mov.l     @(r0,r14),r4=>DAT_8c1bbd90                 = ??

    // 8c022c54  mov.w     WORD_8c022ce0,r0                           = 2B4h
    // 8c022c56  mov.l     @(r0,r14),r0=>DAT_8c1bbc84                 = ??
    // 8c022c58  cmp/eq    #0x0,r0
    // 8c022c5a  bt        bus_state_boarding_8c022c7c
    // 8c022c5c  cmp/eq    #0x1,r0
    // 8c022c5e  bt        bus_state_driving_8c022cca
    // 8c022c60  cmp/eq    #0x2,r0
    // 8c022c62  bf        LAB_8c022c68
    // 8c022c64  bra       LAB_8c022e5a
    // 8c022c66  _nop

    switch (bus_state_8c1bb9d0.bus_state_0x2b4)
    {
        // Boarding
        case 0:
            // 8c022c7c
            switch (bus_state_8c1bb9d0.boarding_state_0x3c0)
            {
                // TODO
                case 0:
                    // 8c022c8a
                    if (!bus_state_8c1bb9d0.field_0x3c4) {
                        // 8c022c96  mov       #0x1,r5
                        // 8c022c98  mov       #0x1d,r6
                        // 8c022c9a  mov       #0x0,r7
                        // 8c022c9c  jsr       @r8=>FUN_8c051618                          int FUN_8c051618(undefined *
                        // 8c022c9e  _mov.l    @r11=>DAT_8c0fcd28,r4                      = ??
                        // 8c022ca0  mov.w     WORD_8c022cde,r0                           = 3C0h
                        // 8c022ca2  mov       #0x1,r3
                        // 8c022ca4  mov.l     r3,@(r0,r14)=>DAT_8c1bbd90                 = ??
                        int field = _8c051618(_8c0fcd28, 1, 0x1d, 0);
                        bus_state_8c1bb9d0.boarding_state_0x3c0 = 1;

                        // 8c022ca6  bra       LAB_8c022f72
                        // 8c022ca8  _fmov.s   fr14,@r12=>DAT_8c227db0
                        _8c227db0 = 0.f;
                    }
                    break;
                
                // TODO
                case 1:
                    // 8c022caa  fmov.s    @r12=>DAT_8c227db0,fr3
                    // 8c022cae  fadd      fr4,fr3
                    // 8c022cb0  fmov.s    fr3,@r12=>DAT_8c227db0
                    _8c227db0 += 0.5;

                    //  8c022cac  mov.l     PTR_DAT_8c022d10,r3                        = 8c227db4
                    // 8c022cb2  fmov.s    @r3=>DAT_8c227db4,fr4
                    // 8c022cb4  fcmp/gt   fr4,fr3
                    // 8c022cb6  bt        LAB_8c022cbc
                    // 8c022cb8  bra       LAB_8c022f72
                    // 8c022cba  _nop
                    if (_8c227db0 > _8c227db4) {
                        // 8c022cbc  mov.w     WORD_8c022cde,r0                           = 3C0h
                        // 8c022cbe  mov       #0x2,r1
                        //  8c022cc2  mov.l     r1,@(r0,r14)=>DAT_8c1bbd90                 = ??
                        bus_state_8c1bb9d0.boarding_state_0x3c0 = 2;
                        
                        // 8c022cc0  fmov.s    fr4,@r12=>DAT_8c227db0
                        _8c227db0 = _8c227db4;

                        // 8c022cc4  add       #0x4,r0
                        // 8c022cc6  bra       LAB_8c022f72
                        // 8c022cc8  _mov.l    r13,@(r0,r14)=>DAT_8c1bbd94                = ??
                        bus_state_8c1bb9d0.field_0x3c4 = 0;
                    }
                    break;
            }
            break;
        
        // Driving
        case 1:
            /* code */
            break;

        // TODO
        case 2:
            /* code */
            break;

        // TODO
        default:
            break;
    }

    // 8c022f72  mov.l     ->FUN_8c010c6e,r2                          = 8c010c6e
    // 8c022f74  jsr       @r2=>FUN_8c010c6e                          undefined FUN_8c010c6e(void)
    // 8c022f76  _nop
    // If nopped: no effect observed yet
    _8c010c6e();

    // 8c022f78  mov.w     DAT_8c023066,r0                            = 027Ch
    //  8c022f7c  fmov.s    @(r0,r14),fr2=>DAT_8c1bbc4c                = ??
    // 8c022f7a  fldi0     fr3
    // 8c022f7e  fcmp/eq   fr3,fr2
    // 8c022f80  bf        LAB_8c022f86
    if (bus_state_8c1bb9d0.speed_0x27c != 0.f) {
        // 8c022f86
        // ...
    }

    // 8c0230ec 31 d2         mov.l     DAT_8c0231b4,r2                            = 8C1BB8C8h
    // 8c0230ee 22 63         mov.l     @r2=>DAT_8c1bb8c8,r3                       = ??
    // 8c0230f0 38 23         tst       r3,r3
    // 8c0230f2 22 89         bt        LAB_8c02313a
    if (!_8c1bb8c8) {
        // 8c0230f2 (...)

        // 8c0230f4  mov.w     DAT_8c0231a2,r0                            = 0250h
        // 8c0230f6  mov.w     DAT_8c0231a4,r7                            = FF4Ah
        // 8c0230f8  mov.l     @(r0,r14),r3=>DAT_8c1bbc20                 = ??
        // 8c0230fa  add       #0x4,r0
        // 8c0230fc  mov.l     @(r0,r14),r4=>DAT_8c1bbc24                 = ??
        // 8c0230fe  add       #0x4,r0
        // 8c023100  mov.l     @(r0,r14),r5=>DAT_8c1bbc28                 = ??
        // 8c023102  sub       r3,r4
        // 8c023104  mov.l     @(r0,r14),r3=>DAT_8c1bbc28                 = ??
        // 8c023106  mov.w     DAT_8c0231a6,r6                            = 00B6h
        // 8c023108  cmp/ge    r4,r3
        // 8c02310a  bt/s      LAB_8c02311a
        // 8c02310c  _sub      r4,r5
        // 8c02310e  cmp/ge    r7,r5
        // 8c023110  bt        LAB_8c023124
        // 8c023112  mov.w     DAT_8c0231a8,r0                            = 0258h
        // 8c023114  mov.l     @(r0,r14),r4=>DAT_8c1bbc28                 = ??
        // 8c023116  bra       LAB_8c023124
        // 8c023118  _add      r6,r4
        // ...
    }

    //  8c023140  mov       r13,r5
    //  8c023144  mov       r9,r4
    //  8c023148  fmov      fr14,fr4

    // 8c02313c  mov       #0x70,r0
    // 8c02313e  mov.l     @(r0,r14),r2=>DAT_8c1bba40                 = ??
    //  8c02313a  mov.w     DAT_8c0231ae,r1                            = 027Ch
    // 8c023142  add       r14,r1
    // 8c023146  fmov.s    @r1=>DAT_8c1bbc4c,fr3                      = ??
    // 8c02314a  fmul      fr13,fr3
    // 8c02314c  ftrc      fr3,FPUL
    // 8c02314e  sts       FPUL,r3
    int speed_int = (int) bus_state_8c1bb9d0.speed_0x27c * 65536.0;

    // 8c023150  sub       r3,r2
    // 8c023152  mov.l     r2,@(r0,r14)=>DAT_8c1bba40                 = ??
    bus_state_8c1bb9d0.distance_traveled_0x070 -= speed_int;

    // 8c023154  mov.w     DAT_8c0231a8,r0                            = 0258h
    // 8c023156  mov.l     @(r0,r14),r3=>DAT_8c1bbc28                 = ??
    // 8c023158  mov       #0x74,r0
    // 8c02315a  mov.l     r3,@(r0,r14)=>DAT_8c1bba44                 = ??
    bus_state_8c1bb9d0.ang_0x074 = bus_state_8c1bb9d0.ang_0x258;

    // 8c02315c  bra       LAB_8c023170
    // 8c02315e  _mov      #0x10,r12

    // TODO

    int r5 = 0;
    int uVar2 = 4;
    float maybefr4 = 0.5;

    while (uVar2 < 0x10) {
        // 8c023160  mov.w     DAT_8c0231b0,r6                            = 0280h
        // 8c023162  add       r14,r6
        // 8c023164  mov       r6,r0
        // 8c023166  fmov.s    @(r0,r4),fr5=>DAT_8c1bbc54                 = ??
        float temp = bus_state_8c1bb9d0.acc_hist_0x280[uVar2];

        // 8c023168  add       #0x4,r4
        uVar2++;

        // 8c02316a  fadd      fr5,fr4
        maybefr4 += temp;

        // 8c02316c  fmov      fr5,@(r0,r5)=>DAT_8c1bbc50                 = ??
        bus_state_8c1bb9d0.acc_hist_0x280[r5] = temp;

        // 8c02316e  add       #0x4,r5
        r5++;
    }

    //  8c023176  mov       #-0x5b,r5

    // 8c023174  mov.w     WORD_8c0231ae,r0                           = 27Ch
    // 8c023178  fmov.s    @(r0,r14),fr5=>DAT_8c1bbc4c                = ??
    float speed_fr5 = bus_state_8c1bb9d0.speed_0x27c;

    // 8c02317c  fsub      fr15,fr5
    speed_fr5 -= speed_fr15;

    // 8c02317e  fadd      fr5,fr4
    maybefr4 += speed_fr5;

    //  8c02317a  add       #0x10,r0
    // 8c023180  fmov      fr5,@(r0,r14)=>DAT_8c1bbc5c                = ??
    bus_state_8c1bb9d0.acc_hist_0x280[3] = speed_fr5;

    // 8c023186  fmov      fr4,fr2
    float new_acc_float = maybefr4;

    //  8c023182  mova      FLOAT_8c0231b8,r0                          = 1024.0
    //  8c023184  fmov.s    @r0=>FLOAT_8c0231b8,fr3                    = 1024.0
    // 8c023188  fmul      fr3,fr2
    new_acc_float *= 1024.f;

    // 8c02318a  ftrc      fr2,FPUL
    // 8c02318c  sts       FPUL,r4
    int new_acc_int = (int) new_acc_float;

    // Clamp new acc
    // 8c02318e  cmp/ge    r5,r4
    // 8c023190  bt        LAB_8c0231bc
    // 8c023192  bra       LAB_8c0231c4
    // 8c023194  _mov      r5,r4
    if (new_acc_int < -91) {
        new_acc_int = -91;
    } else if (new_acc_int >= 91) {
        new_acc_int = 91;
    }

    // 8c0231c4  mov       #0x78,r0
    // 8c0231c8  mov.l     r4,@(r0,r14)=>DAT_8c1bba48                 = ??
    bus_state_8c1bb9d0.acc_0x078 = new_acc_int;

    // 8c0231ca  mov.w     DAT_8c023282,r0                            = 0258h
    // 8c0231cc  mov.l     @(r0,r14),r3=>DAT_8c1bbc28                 = ??
    //  8c0231d4  lds       r3,FPUL
    //  8c0231d6  float     FPUL,fr3
    int angular_0x258_int = bus_state_8c1bb9d0.ang_0x258;
    float angular_0x258_float = (float) angular_0x258_int;

    // 8c0231ce  add       #0x24,r0
    // 8c0231d0  fmov.s    @(r0,r14),fr2=>DAT_8c1bbc4c                = ??
    float new_angular_0x07c_float = bus_state_8c1bb9d0.speed_0x27c;

    // 8c0231d8  fmul      fr3,fr2
    new_angular_0x07c_float *= angular_0x258_float;

    //  8c0231d2  mova      FLOAT_8c023294,r0                            = 0.2
    // 8c0231da  fmov.s    @r0=>FLOAT_8c023294,fr3                      = 0.2
    // 8c0231dc  fmul      fr3,fr2
    new_angular_0x07c_float *= 0.2;

    // 8c0231de  fneg      fr2
    new_angular_0x07c_float = -new_angular_0x07c_float;

    // 8c0231e0  ftrc      fr2,FPUL
    // 8c0231e2  sts       FPUL,r4
    int new_angular_0x07c_int = (int) new_angular_0x07c_float;

    // Clamp new angular
    //  8c0231c6  mov.w     DAT_8c023284,r5                            = FD28h
    // 8c0231e4  cmp/ge    r5,r4
    // 8c0231e6  bt        LAB_8c0231ec
    // 8c0231e8  bra       LAB_8c0231f4
    // 8c0231ea  _mov      r5,r4
    // 8c0231ec  mov.w     DAT_8c023286,r5                            = 02D8h
    // 8c0231ee  cmp/gt    r5,r4
    // 8c0231f0  bf        LAB_8c0231f4
    // 8c0231f2  mov       r5,r4
    if (new_angular_0x07c_int < -728) {
        new_angular_0x07c_int = -728;
    } else if (new_angular_0x07c_int >= 728) {
        new_angular_0x07c_int = 728;
    }

    // 8c0231f6  mov       #0x7c,r0
    // 8c0231f8  mov.l     r4,@(r0,r14)=>DAT_8c1bba4c                 = ??
    bus_state_8c1bb9d0.ang_0x07c = new_angular_0x07c_int;

    //  8c0231f4  mov.l     PTR_DAT_8c023298,r3                        = 8c18ad20
    // 8c0231fa  mov.l     @r3=>DAT_8c18ad20,r0                       = ??
    // 8c0231fc  cmp/eq    #0x1,r0
    // 8c0231fe  bt        LAB_8c023208
    // 8c023200  cmp/eq    #0x2,r0
    // 8c023202  bt        LAB_8c023212
    // 8c023204  bra       LAB_8c02321a
    // 8c023206  _nop
    if (_8c18ad20 == 1) {
        // 8c023208  mov.w     DAT_8c023288,r0                            = 0080h
        // 8c02320a  mov.l     @(r0,r14),r2=>DAT_8c1bba50                 = ??
        // 8c02320c  or        r12,r2
        // 8c02320e  bra       LAB_8c02321a
        // 8c023210  _mov.l    r2,@(r0,r14)=>DAT_8c1bba50                 = ??
        bus_state_8c1bb9d0.blinker_0x080 |= 0x10;
    } else if (_8c18ad20 == 2) {
        // 8c023212  mov.l     ->FUN_8c028022,r2                          = 8c028022
        // 8c023214  mov.l     PTR_DAT_8c02329c,r0                        = 8c1bbd9c
        // 8c023216  jsr       @r2=>FUN_8c028022                          undefined FUN_8c028022(int p
        // 8c023218  _mov.l    @r0=>DAT_8c1bbd9c,r4                       = ??
        prob_blinker_8c028022(_8c1bbd9c);
    }

    // 8c02321a  mov.w     DAT_8c02328a,r0                            = 02F4h
    // 8c02321c  mov.l     @(r0,r14),r0=>DAT_8c1bbcc4                 = ??
    // 8c02321e  cmp/eq    #0x5,r0
    // 8c023220  bf        LAB_8c02323a
    // Not reverse gear
    if (bus_state_8c1bb9d0.gear_0x2f4 != 5) {
        // 8c02323a 28 90         mov.w     DAT_8c02328e,r0                            = 025Ch
        // 8c02323c ee 00         mov.l     @(r0,r14),r0=>DAT_8c1bbc2c                 = ??
        // 8c02323e 08 20         tst       r0,r0
        // 8c023240 06 8b         bf        LAB_8c023250

        // 8c023242 25 90         mov.w     DAT_8c023290,r0                            = 0260h
        // 8c023244 17 d3         mov.l     ->FUN_8c0518f8,r3                          = 8c0518f8
        // 8c023246 d6 0e         mov.l     r13,@(r0,r14)=>DAT_8c1bbc30                = ??
        // 8c023248 0b 43         jsr       @r3=>FUN_8c0518f8                          int FUN_8c0518f8(undefined *
        // 8c02324a b1 54         _mov.l    @(0x4,r11)=>DAT_8c0fcd2c,r4                = ??
        // 8c02324c 30 a0         bra       LAB_8c0232b0
        // 8c02324e 09 00         _nop

    }
    //...

    // 8c023222  mov.w     DAT_8c02328c,r0                            = 02F8h
    // 8c023224  mov.l     @(r0,r14),r2=>DAT_8c1bbcc8                 = ??
    // 8c023226  tst       r12,r2
    // 8c023228  add       #0x1,r2
    // 8c02322a  bt/s      LAB_8c0232b0
    // 8c02322c  _mov.l    r2,@(r0,r14)=>DAT_8c1bbcc8                 = ??
    // 8c02322e  mov.w     DAT_8c023288,r0                            = 0080h
    // 8c023230  mov       #0x6,r3
    // 8c023232  mov.l     @(r0,r14),r2=>DAT_8c1bba50                 = ??
    // 8c023234  or        r3,r2
    // 8c023236  bra       LAB_8c0232b0
    // 8c023238  _mov.l    r2,@(r0,r14)=>DAT_8c1bba50                 = ??

}

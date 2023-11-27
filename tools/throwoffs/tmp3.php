<?php

$syms = [
    '__8c02fb50',
    '__8c02fc04',
    '__8c02fcac',
    '__8c02fd74',
    '__8c02fe2c',
    '__8c02fe38',
    '__8c02fed0',
    '__8c02ff58',
    '__8c02ff58',
    '__8c02ffa8',
    '__8c02ffa8',
    '__8c02fff8',
    '__8c0300b8',
    '__8c0300d0',
    '__8c030108',
    '__8c030130',
    '__8c030140',
    '__8c030180',
    '__8c0301e8',
    '__8c0302f8',
    '__8c0303bc',
    '__8c0304b0',
    '__8c030508',
    '__8c03057c',
    '__8c0305b0',
    '__8c0305ec',
    '__8c03060c',
    '__8c03069c',
    '__8c031068',
    '__8c031248',
    '__8c031308',
    '__8c031338',
    '__8c031354',
    '__8c031378',
    '__8c03147c',
    '__8c031be4',
    '__8c031d14',
    '__8c032028',
    '__8c032078',
    '__8c0320ec',
    '__8c032154',
    '__8c032174',
    '__8c032274',
    '__8c032364',
    '__8c03264c',
    '__8c032698',
    '__8c0326bc',
    '__8c032714',
    '__8c03278c',
    '__8c0327c0',
    '__8c0328c8',
    '__8c032918',
    '__8c032968',
    '__8c032988',
    '__8c0329ac',
    '__8c032b40',
    '__8c032b84',
    '__8c032ba0',
    '__8c032be8',
    '__8c032c58',
    '__8c032c74',
    '__8c032dc8',
    '__8c032eb4',
    '__8c032f38',
    '__8c032f80',
    '__8c0330ac',
    '__8c033178',
    '__8c033210',
    '__8c03325c',
];

$replacements = [
    '__divls',
    '__divlu',
    '__modls',
    '__modlu',
    '__quick_evn_mvn',
    '__quick_odd_mvn',
    '__slow_mvn',
    '_asin',
    '_asinf',
    '_atan2',
    '_atan2f',
    '_memcpy',
    '_memset',
    '_rand',
    '_strcmp',
    '_strlen',
    '_strncmp',
    '__modws',
    '__quick_mvn',
    '__slow_strcmp1',
    '__in_asins',
    '__in_atan2s',
    '_frexp',
    '_memcmp',
    '_sprintf',
    '_strcat',
    '_vsprintf',
    '__fmtout',
    '__in_atans',
    '__in_ldexps',
    '_strncpy',
    '_toupper',
    '__app_atans',
    '__in_fmods',
    '__xtostr',
    '__its',
    '__xti',
    '_cos',
    '_longjmp',
    '_setjmp',
    '__allzero',
    '__calcnpw',
    '__in_coss',
    '__log10',
    '__lsfts',
    '__pow5',
    '__rsfts',
    '__sub',
    '__umemcmp',
    '__unpack',
    '_log10f',
    '__divws',
    '__app_coss',
    '__app_sins',
    '__div64',
    '__duchek',
    '__in_log10s',
    '__lsft',
    '__mult64',
    '__mvito4b',
    '__power',
    '__rnd',
    '__setsbit',
    '__add',
    '__in_logs',
    '__mult',
    '__pow10',
    '__rsft',
    '__mvsto2b',
];

$srcFiles = [
    'src/_000000_8c010000.src',
    'src/_008160_8c011fe0.src',
    'src/_144036_8c0332a4_sectionC.src',
    'src/_000188_8c0100bc_sound.src',
    'src/_020308_8c014f54.src',
    'src/_179584_8c03bd80_sectionD.src',
    'src/_004072_8c010fe8.src',
    'src/_023224_8c015ab8_title.src',
    'src/_259776_8c04f6c0_SDK.src',
    'src/_004384_8c011120.src',
    'src/_024908_8c01614c.src',
    'src/_970016_8c0fcd20_sectionB.src',
    'src/_005168_8c011430.src',
    'src/_143996_8c03327c_strt1_sectionC.src',
    'lnk.sub',
];

foreach ($srcFiles as $name) {
    file_put_contents($name, str_replace($syms, $replacements, file_get_contents($name)));
}

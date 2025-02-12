/**
 * @file input.h
 * @author Samuel Sánchez
 * @date 12 Feb 2025
 * @brief Definitions and test data for program input.
 *
 * This file contains the necessary definitions for testing the program's input,
 * including a set of test arguments and their expected outputs.
 *
 * Macros:
 *  - NUM_TEST: Total number of defined tests.
 *
 * Variables:
 *  - TEST_ARGUMENTS: Array of strings containing test arguments.
 *  - EXPECTED_OUTPUTS: Array of strings containing expected outputs.
 *
 */

#ifndef _INPUT_H
#define _INPUT_H

#define NUM_TEST 11

static const char* TEST_ARGUMENTS[NUM_TEST] = {
    "",                 /* Without arguments. */
    "-s 7",             /* Only --start. */
    "-s 7 -e 104",      /* --start & --end. */
    "-s 7 -n 35",       /* --start & --num-bytes. */
    "-s 7 -b 32",       /* --start & --byte-offset. */
    "-s 7 -n 40 -b 32", /* --start, --num-bytes & --byte-offset. */
    "-e 85",            /* --end. */
    "-e 85 -b 32",      /* --end & --byte-offset. */
    "-r 7:104",         /* --range. */
    "-b 32",            /* --byte-offset. */
    "-b 32 -n 40"      /* --byte-offset & --num-bytes */
};

static const char* EXPECTED_OUTPUTS[NUM_TEST] = {
    /*  */
    "         00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F\n"
    "00000000 D8 A2 45 BD 0D 00 D1 32 4A 45 1D 74 73 8F 21 5F   E    2JE ts !_\n"
    "00000010 0F BF 21 F5 76 A6 3D 3A F9 AD 51 C7 9D 15 65 20   ! v =:  Q   e \n"
    "00000020 2C DB A4 FF 9F 54 2E 55 81 55 7D 3A 75 B1 A9 96 ,    T.U U}:u   \n"
    "00000030 79 80 85 5A 2C F6 08 0B 80 55 CF BA 62 57 46 37 y  Z,    U  bWF7\n"
    "00000040 C0 AE 60 5D 84 11 0E 32 A7 C8 32 24 E4 A4 D8 98   `]   2  2$    \n"
    "00000050 03 61 26 64 1F 7A A4 E1 64 DE 2F FE F2 28 16 04  a&d z  d /  (  \n"
    "00000060 CA 2E 30 D6 B8 C5 63 87 A0 32 0B 89 2E CD 9E 21  .0   c  2  .  !\n"
    "00000070 BB 35 78 0C 72 66 B5 D4 F8 16 46 31 3B EC 50 97  5x rf    F1; P \n\0",
    /* --start 7 */
    "         00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F\n"
    "00000007 32 4A 45 1D 74 73 8F 21 5F 0F BF 21 F5 76 A6 3D 2JE ts !_  ! v =\n"
    "00000017 3A F9 AD 51 C7 9D 15 65 20 2C DB A4 FF 9F 54 2E :  Q   e ,    T.\n"
    "00000027 55 81 55 7D 3A 75 B1 A9 96 79 80 85 5A 2C F6 08 U U}:u   y  Z,  \n"
    "00000037 0B 80 55 CF BA 62 57 46 37 C0 AE 60 5D 84 11 0E   U  bWF7  `]   \n"
    "00000047 32 A7 C8 32 24 E4 A4 D8 98 03 61 26 64 1F 7A A4 2  2$     a&d z \n"
    "00000057 E1 64 DE 2F FE F2 28 16 04 CA 2E 30 D6 B8 C5 63  d /  (   .0   c\n"
    "00000067 87 A0 32 0B 89 2E CD 9E 21 BB 35 78 0C 72 66 B5   2  .  ! 5x rf \n"
    "00000077 D4 F8 16 46 31 3B EC 50 97                         F1; P \n\0",
    /* --start 7 --end 104 */
    "         00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F\n"
    "00000007 32 4A 45 1D 74 73 8F 21 5F 0F BF 21 F5 76 A6 3D 2JE ts !_  ! v =\n"
    "00000017 3A F9 AD 51 C7 9D 15 65 20 2C DB A4 FF 9F 54 2E :  Q   e ,    T.\n"
    "00000027 55 81 55 7D 3A 75 B1 A9 96 79 80 85 5A 2C F6 08 U U}:u   y  Z,  \n"
    "00000037 0B 80 55 CF BA 62 57 46 37 C0 AE 60 5D 84 11 0E   U  bWF7  `]   \n"
    "00000047 32 A7 C8 32 24 E4 A4 D8 98 03 61 26 64 1F 7A A4 2  2$     a&d z \n"
    "00000057 E1 64 DE 2F FE F2 28 16 04 CA 2E 30 D6 B8 C5 63  d /  (   .0   c\n"
    "00000067 87 A0                                             \n\0",
    /* --start 7 --num-bytes 35 */
    "         00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F\n"
    "00000007 32 4A 45 1D 74 73 8F 21 5F 0F BF 21 F5 76 A6 3D 2JE ts !_  ! v =\n"
    "00000017 3A F9 AD 51 C7 9D 15 65 20 2C DB A4 FF 9F 54 2E :  Q   e ,    T.\n"
    "00000027 55 81 55                                        U U\n\0",
    /* --start 7  --byte-offset 32*/
    "         00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F\n"
    "00000007 55 81 55 7D 3A 75 B1 A9 96 79 80 85 5A 2C F6 08 U U}:u   y  Z,  \n"
    "00000017 0B 80 55 CF BA 62 57 46 37 C0 AE 60 5D 84 11 0E   U  bWF7  `]   \n"
    "00000027 32 A7 C8 32 24 E4 A4 D8 98 03 61 26 64 1F 7A A4 2  2$     a&d z \n"
    "00000037 E1 64 DE 2F FE F2 28 16 04 CA 2E 30 D6 B8 C5 63  d /  (   .0   c\n"
    "00000047 87 A0 32 0B 89 2E CD 9E 21 BB 35 78 0C 72 66 B5   2  .  ! 5x rf \n"
    "00000057 D4 F8 16 46 31 3B EC 50 97                         F1; P \n\0",
    /* --start 7 --num-bytes 40 --byte-offset 32*/
    "         00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F\n"
    "00000007 55 81 55 7D 3A 75 B1 A9 96 79 80 85 5A 2C F6 08 U U}:u   y  Z,  \n"
    "00000017 0B 80 55 CF BA 62 57 46 37 C0 AE 60 5D 84 11 0E   U  bWF7  `]   \n"
    "00000027 32 A7 C8 32 24 E4 A4 D8                         2  2$   \n\0",
    /* --end 85 */
    "         00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F\n"
    "00000000 D8 A2 45 BD 0D 00 D1 32 4A 45 1D 74 73 8F 21 5F   E    2JE ts !_\n"
    "00000010 0F BF 21 F5 76 A6 3D 3A F9 AD 51 C7 9D 15 65 20   ! v =:  Q   e \n"
    "00000020 2C DB A4 FF 9F 54 2E 55 81 55 7D 3A 75 B1 A9 96 ,    T.U U}:u   \n"
    "00000030 79 80 85 5A 2C F6 08 0B 80 55 CF BA 62 57 46 37 y  Z,    U  bWF7\n"
    "00000040 C0 AE 60 5D 84 11 0E 32 A7 C8 32 24 E4 A4 D8 98   `]   2  2$    \n"
    "00000050 03 61 26 64 1F 7A                                a&d z\n\0",
    /* --end 85 --byte-offset 32*/
    "         00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F\n"
    "00000000 2C DB A4 FF 9F 54 2E 55 81 55 7D 3A 75 B1 A9 96 ,    T.U U}:u   \n"
    "00000010 79 80 85 5A 2C F6 08 0B 80 55 CF BA 62 57 46 37 y  Z,    U  bWF7\n"
    "00000020 C0 AE 60 5D 84 11 0E 32 A7 C8 32 24 E4 A4 D8 98   `]   2  2$    \n"
    "00000030 03 61 26 64 1F 7A A4 E1 64 DE 2F FE F2 28 16 04  a&d z  d /  (  \n"
    "00000040 CA 2E 30 D6 B8 C5 63 87 A0 32 0B 89 2E CD 9E 21  .0   c  2  .  !\n"
    "00000050 BB 35 78 0C 72 66                                5x rf\n\0",
    /* --range 7:104 */
    "         00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F\n"
    "00000007 32 4A 45 1D 74 73 8F 21 5F 0F BF 21 F5 76 A6 3D 2JE ts !_  ! v =\n"
    "00000017 3A F9 AD 51 C7 9D 15 65 20 2C DB A4 FF 9F 54 2E :  Q   e ,    T.\n"
    "00000027 55 81 55 7D 3A 75 B1 A9 96 79 80 85 5A 2C F6 08 U U}:u   y  Z,  \n"
    "00000037 0B 80 55 CF BA 62 57 46 37 C0 AE 60 5D 84 11 0E   U  bWF7  `]   \n"
    "00000047 32 A7 C8 32 24 E4 A4 D8 98 03 61 26 64 1F 7A A4 2  2$     a&d z \n"
    "00000057 E1 64 DE 2F FE F2 28 16 04 CA 2E 30 D6 B8 C5 63  d /  (   .0   c\n"
    "00000067 87 A0                                             \n\0",
    /* --byte-offset 32 */
    "         00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F\n"
    "00000000 2C DB A4 FF 9F 54 2E 55 81 55 7D 3A 75 B1 A9 96 ,    T.U U}:u   \n"
    "00000010 79 80 85 5A 2C F6 08 0B 80 55 CF BA 62 57 46 37 y  Z,    U  bWF7\n"
    "00000020 C0 AE 60 5D 84 11 0E 32 A7 C8 32 24 E4 A4 D8 98   `]   2  2$    \n"
    "00000030 03 61 26 64 1F 7A A4 E1 64 DE 2F FE F2 28 16 04  a&d z  d /  (  \n"
    "00000040 CA 2E 30 D6 B8 C5 63 87 A0 32 0B 89 2E CD 9E 21  .0   c  2  .  !\n"
    "00000050 BB 35 78 0C 72 66 B5 D4 F8 16 46 31 3B EC 50 97  5x rf    F1; P \n\0",
    /* --byte-offset 32 --num-bytes 40*/
    "         00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F\n"
    "00000000 2C DB A4 FF 9F 54 2E 55 81 55 7D 3A 75 B1 A9 96 ,    T.U U}:u   \n"
    "00000010 79 80 85 5A 2C F6 08 0B 80 55 CF BA 62 57 46 37 y  Z,    U  bWF7\n"
    "00000020 C0 AE 60 5D 84 11 0E 32                           `]   2\n\0",
};

#endif
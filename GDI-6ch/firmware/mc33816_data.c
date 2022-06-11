/*
 * mc33816_data.c
 *
 * For historic reasons rusEFI source code refers to all this as mc33816 while the microcode
 * is signed with MC33PT2001 key. to use real mc33816 you would have to replace binary data with true mc33816 version
 *
 * this is manual copy-paste of sample_code/PT2001_LoadData.c
 * see mc33816/rusefi/readme.md
 */

// Data to be loaded into the Code RAM 1 memory space
const unsigned short MC33816_code_RAM1[88] =
{
    0x7612, 0x6C2B, 0x917F, 0xA514, 0x8DD1, 0xC289, 0x7C38, 0xA73B, 0xF359, 0x56C3, 
    0xEE73, 0x812F, 0xDFA9, 0x2ED5, 0x2722, 0xBC58, 0x649B, 0xFB66, 0xFAD7, 0xBB51, 
    0xBD0C, 0xBEA9, 0x2F34, 0xDA2C, 0x41CF, 0x8DDD, 0xB4F4, 0xCA54, 0xAF19, 0x6707, 
    0xDA8A, 0x1D69, 0x6015, 0xA215, 0xB473, 0xF3AB, 0x6CC1, 0xE620, 0x8D0F, 0x5FC6, 
    0x3DA2, 0x4662, 0x0EF2, 0x63A6, 0xEFAD, 0x9915, 0xA134, 0xBB55, 0xD6E8, 0xBDC9, 
    0x433D, 0x3943, 0x4AEA, 0xCD3C, 0xE90A, 0xC413, 0xD3A3, 0xF690, 0xE423, 0x0106, 
    0x72BC, 0xD39A, 0x0329, 0x3AF3, 0x9F62, 0x9FA6, 0xD615, 0xEF1D, 0xAF32, 0x31BF, 
    0x5A43, 0x2FAD, 0xFD4E, 0xB35B, 0x56F3, 0xFAB7, 0x5ADE, 0x3A4C, 0xCA7D, 0x20AF, 
    0x24CE, 0x808E, 0x43CD, 0xDF83, 0xE8DF, 0x7CC1, 0xE738, 0x1B09
};

// Data to be loaded into the Code RAM 2 memory space
const unsigned short MC33816_code_RAM2[43] =
{
    0x761B, 0x6F45, 0x838D, 0x80B4, 0x53F2, 0x0EBC, 0x8F2D, 0xA78E, 0xE8AB, 0xE3DB, 
    0xF477, 0x800F, 0x2336, 0x2F77, 0x267B, 0xBC19, 0x007E, 0x4E55, 0x28AA, 0x52E4, 
    0x40CF, 0x0AFD, 0x8B32, 0xFF03, 0x3D8E, 0x802E, 0x1340, 0x95D0, 0x1E86, 0x6591, 
    0xDBEB, 0x786D, 0xB2DF, 0xF4BF, 0xBEB2, 0xF1F4, 0x9E53, 0xE743, 0xE842, 0x3DD7, 
    0x3DA2, 0x4663, 0x03AF
};

// Data to be loaded into the Data RAM memory space
const unsigned short MC33816_data_RAM[128] =
{
    0x00F0, 0x00F0, 0x008C, 0x2000, 0x01F4, 0x00B4, 0x003C, 0xEA60, 0x0000, 0x003D, 
    0x6000, 0x003C, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x00C1, 0x00BF, 0x002F, 0x001D, 0x0000, 0x0046, 
    0x0037, 0x003C, 0xEA60, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
};

// 0x1CE
// if set to '1' Driver_status register is reset on read.
#define Rsetbr 1

// Data to be loaded into the Main register memory space
const unsigned short MC33816_main_config[29] =
{
    0x0003, 0x1FFE, 0x0000, 0x1200, 0x0000, 0x0000, 0x0001, 0x0000, 0x001F, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, Rsetbr, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
};

// Data to be loaded into the CH1 register memory space
const unsigned short MC33816_ch1_config[19] =
{
    0x0008, 0x0000, 0x0000, 0x0000, 0x0303, 0x0000, 0x0000, 0x0058, 0x8E62, 0x7B23, 
    0x0000, 0x002C, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
};

// Data to be loaded into the CH2 register memory space
const unsigned short MC33816_ch2_config[19] =
{
    0x0008, 0x0000, 0x0000, 0x0000, 0x0C00, 0x0000, 0x0000, 0x002B, 0x218C, 0xDCB6, 
    0x0000, 0x0014, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
};

// Data to be loaded into the IO register memory space
const unsigned short MC33816_io_config[44] =
{
    0x0000, 0x0000, 0x0000, 0x0000, 0x0063, 0x018C, 0x0800, 0x0410, 0x0041, 0x0098, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0041, 0x0041, 0x0041, 0x0000, 0x0004, 0x1000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7F7F, 0x7F7F, 
    0x007F, 0x0000, 0x0000, 0x0000
};

// Data to be loaded into the Diag register memory space
const unsigned short MC33816_diag_config[44] =
{
    0x0000, 0x0000, 0x001E, 0x0000, 0x0000, 0x001E, 0x0000, 0x0000, 0x001E, 0x0000, 
    0x0000, 0x001E, 0x0000, 0x0000, 0x001E, 0x0000, 0x0000, 0x001E, 0x001E, 0x0000, 
    0x0000, 0x001E, 0x0000, 0x0000, 0x001E, 0x0000, 0x0000, 0x001E, 0x0000, 0x0000, 
    0x001E, 0x0000, 0x0000, 0x001E, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0001
};

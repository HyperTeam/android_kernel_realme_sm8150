/* 
 *
 * yixue.ge add for oppo project
 *
 *
 */
#ifndef _OPPO_PROJECT_H_
#define _OPPO_PROJECT_H_

enum{
        HW_VERSION__UNKNOWN,
        HW_VERSION__10,   /*1452mV*/
        HW_VERSION__11,   /*1636 mV*/
        HW_VERSION__12,   /*1224 mV*/
        HW_VERSION__13,   /*900 mV*/
        HW_VERSION__14,   /*720 mV*/
        HW_VERSION__15,
        HW_VERSION__16,
        HW_VERSION__17,
};


enum{
        RF_VERSION__UNKNOWN,
        RF_VERSION__11,
        RF_VERSION__12,
        RF_VERSION__13,
        RF_VERSION__14,
        RF_VERSION__15,
        RF_VERSION__16,
        RF_VERSION__17,
        RF_VERSION__18,
        RF_VERSION__19,
        RF_VERSION__1A,
		RF_VERSION__1B,
    	RF_VERSION__1C,
    	RF_VERSION__1D,
    	RF_VERSION__1E,
    	RF_VERSION__1F,
};


#define GET_PCB_VERSION() (get_PCB_Version())
#define GET_PCB_VERSION_STRING() (get_PCB_Version_String())

#define GET_MODEM_VERSION() (get_Modem_Version())
#define GET_OPERATOR_VERSION() (get_Operator_Version())



enum OPPO_PROJECT {
        OPPO_UNKOWN = 0,
        OPPO_18081 = 18081,
        OPPO_18085 = 18085,
        OPPO_18181 = 18181,
		OPPO_11870 = 11870,
		OPPO_18115 = 18115,
		OPPO_18117 = 18117,
		OPPO_18119 = 18119,
		OPPO_18501 = 18501,
		OPPO_18503 = 18503,
		OPPO_19071 = 19071,
		OPPO_19371 = 19371,
		OPPO_19081 = 19081,
		OPPO_19688 = 19688,
		OPPO_19781 = 19781,
		OPPO_19696 = 19696,
        OPPO_19031 = 19031,
        OPPO_19331 = 19331,
        OPPO_19111 = 19111,
        OPPO_19513 = 19513,
};

enum OPPO_OPERATOR {
        OPERATOR_UNKOWN                     = 0,
        OPERATOR_OPEN_MARKET          = 1,
        OPERATOR_CHINA_MOBILE             = 2,
        OPERATOR_CHINA_UNICOM              = 3,
        OPERATOR_CHINA_TELECOM                = 4,
        OPERATOR_FOREIGN                             = 5,
/*#ifdef VENDOR_EDIT*/
/*TongJing.Shi@EXP.DataComm.Phone, 2014.04.18, Add for exp just 3G no 4G*/
        OPERATOR_FOREIGN_WCDMA         = 6,   /*qifeng.liu 2014.08.07 FOR MAC*/
        OPERATOR_FOREIGN_RESERVED   = 7,    /*shaoming 2014/10/04 add for 14085's dual sim version*/
        OPERATOR_ALL_CHINA_CARRIER    = 8,   /*instead of TELECOM CARRIER because of history Tong.han@Bsp.Group.Tp add for all china carrier phone, 2015/03/23*/
        OPERATOR_ALL_CHINA_CARRIER_MOBILE = 9,    /*rendong.shi@Bsp.Group.Tp add for all china carrier MOBILE phone, 2016/01/07*/
        OPERATOR_ALL_CHINA_CARRIER_UNICOM = 10,    /*rendong.shi@Bsp.Group.Tp add for all china carrier UNICOM  phone, 2016/01/07*/
        OPERATOR_FOREIGN_EUROPE = 11,    //wanghao@Bsp.Group.Tp add for foreign europe  phone, 2018/07/14
		OPERATOR_RM_ASIA_PACIFIC_LOW = 30,    //guomingzhi@RM.BSP.BOOT add for realme low-config Asia&Pacific 2019/11/14 (19696)
		OPERATOR_RM_ASIA_PACIFIC_HIGH = 31,   //guomingzhi@RM.BSP.BOOT add for realme hign-config Asia&Pacific 2019/11/14 (19710)
		OPERATOR_RM_FULL_FREQ_LOW = 32,      //guomingzhi@RM.BSP.BOOT add for realme low-config full_freq 2019/11/14 (19697)
		OPERATOR_RM_FULL_FREQ_HIGH = 33,      //guomingzhi@RM.BSP.BOOT add for realme hign-config full_freq 2019/11/14 (19711)
		OPERATOR_RM_FULL_FREQ_NFC_LOW = 34,      //guomingzhi@RM.BSP.BOOT add for realme low-config full_freq +nfc 2019/11/14 (19698)
		OPERATOR_RM_FULL_FREQ_NFC_HIGH = 35,      //guomingzhi@RM.BSP.BOOT add for realme hign-config full_freq +nfc 2019/11/14 (19712)
};

typedef enum OPPO_PROJECT OPPO_PROJECT;
#define OCPCOUNTMAX 4
typedef struct
{
        unsigned int                  nproject;
        unsigned char                 nmodem;
        unsigned char                 noperator;
        unsigned char                 npcbversion;
        unsigned char                 noppobootmode;
        unsigned char                 npmicocp[OCPCOUNTMAX];
        unsigned char                 nmachinetype;
        int                           nEngVersion;
        unsigned int                  nEngVerConfidential;
} ProjectInfoCDTType;

/*#ifdef VENDOR_EDIT*/
/*Cong.Dai@psw.bsp.tp, 2019.06.27, Add for sw_version*/
#define OPPO_ENG_VERSION_NOT_INIT      -1
enum OPPO_ENG_VERSION {
    RELEASE                 = 0x00,
    AGING                   = 0x01,
    CTA                     = 0x02,
    PERFORMANCE             = 0x03,
    PREVERSION              = 0x04,
    ALL_NET_CMCC_TEST       = 0x05,
    ALL_NET_CMCC_FIELD      = 0x06,
    ALL_NET_CU_TEST         = 0x07,
    ALL_NET_CU_FIELD        = 0x08,
    ALL_NET_CT_TEST         = 0x09,
    ALL_NET_CT_FIELD        = 0x0A,
};
/*#endif VENDOR_EDIT*/
#ifdef VENDOR_EDIT
/*Fei.Mo@BSP.Bootloader.Bootflows, 2019/03/07, Add for diff manifest*/
#define MANIFEST_LEN 2
static const char* manifest = "manifest";
static const char* manifest_src[MANIFEST_LEN] = {
	"/vendor/etc/vintf/manifest_dsds.xml",
	"/vendor/etc/vintf/manifest_ssss.xml"
};
#endif

#ifdef CONFIG_OPPO_COMMON_SOFT
void init_project_version(void);
unsigned int get_project(void);
unsigned int is_project(OPPO_PROJECT project);
unsigned char get_PCB_Version(void);
unsigned char get_Modem_Version(void);
unsigned char get_Operator_Version(void);
unsigned char get_Machine_Type(void);
int get_eng_version(void);
bool is_confidential(void);
bool oppo_daily_build(void);
#else
unsigned int init_project_version(void) { return 0;}
unsigned int get_project(void) { return 0;}
unsigned int is_project(OPPO_PROJECT project) { return 0;}
unsigned char get_PCB_Version(void) { return 0;}
unsigned char get_Modem_Version(void) { return 0;}
unsigned char get_Operator_Version(void) { return 0;}
unsigned char get_Machine_Type(void) {return 0;}
int get_eng_version(void) { return 0;}
bool is_confidential(void) { return true;}
bool oppo_daily_build(void) { return false;}
#endif
#endif  /*_OPPO_PROJECT_H_*/

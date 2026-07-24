//
//  UTEDefine.h
//  UTEBluetoothRYApi
//
//  Created by VV on 23/03/07.
//  Copyright © 2023年 vv. All rights reserved.


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/*!
 *  All sleeps are categorized into each group (By default, from 8 o'clock last night to 8 o'clock tonight, it is classified as a day)
 *  Each set of data is of the same type (Sleep at night or Sporadic Sleep during the day)
 */
extern NSString *const kSDKQuerySleepDayByDay;


@interface UTEBluetoothEnum : NSObject

/*!
 *  @enum UTEDisplayDateType
 */
typedef NS_ENUM(NSInteger, UTEDisplayDateType) {
    UTEDisplayDateTypeyyyyMMdd = 1,
    UTEDisplayDateTypeMMddyyyy,
    UTEDisplayDateTypeddMMyyyy,
    UTEDisplayDateTypeMMddEEEE,
};

/*!
 *  @enum UTEDisplayTimeType
 */
typedef NS_ENUM(NSInteger, UTEDisplayTimeType) {
    UTEDisplayTimeType12 = 1,
    UTEDisplayTimeType24,
};

typedef NS_ENUM(NSInteger, UTEDevicePlatformType) {
    UTEDevicePlatformTypeDA1458x,
    UTEDevicePlatformTypeRTL8762Ax,
    UTEDevicePlatformTypeNRF52832,
    UTEDevicePlatformTypeRTL8762C,
    UTEDevicePlatformTypeSYD881x,
    UTEDevicePlatformTypeFR5080,
    UTEDevicePlatformTypeAC7012x,
    UTEDevicePlatformTypeATS308x,
    UTEDevicePlatformTypeATS3085S,
    UTEDevicePlatformTypeATS3028Sigmastar,
    UTEDevicePlatformTypeAB895,
};

typedef NS_ENUM(NSInteger, UTEDeviceDialType) {
    ///圆屏 circular disk
    UTEDeviceDialTypeCircle,
    ///方屏 Square Screen
    UTEDeviceDialTypeSquare,
};


/*!
 *  @enum UTEDeviceAlertType
 *
 *  @discussion When the application is in the background and interacts with the device, the system prompts the system dialog
 *  Note:This is useful for applications that have not specified background mode and cannot display their own alert. If more than one application has requested notification for a given device, the one that was most recently in the foreground will receive the alert.
 *
 */
typedef NS_ENUM(NSInteger, UTEBluetoothAlertType) {
    UTEBluetoothAlertTypeNone            = 0,      //Default, no system prompt box will pop up
    UTEBluetoothAlertTypeConnect         = 1 << 0, //indicating that the system should display a connection alert for a given device, if the application is suspended when a successful connection is made.
    UTEBluetoothAlertTypeDisconnect      = 1 << 1, //indicating that the system should display a disconnection alert for a given device, if the application is suspended at the time of the disconnection.
    UTEBluetoothAlertTypeCommunicate     = 1 << 2, //indicating that the system should display an alert for all notifications received from a device peripheral, if the application is suspended at the time.
    UTEBluetoothAlertTypeRequiresANCS    = 1 << 3, //indicating that the ANCS (Apple Notification Center Service) is required for the device is connected.  If there is a response, method uteManagerANCSAuthorization: will be called.
};

/*!
 *  @enum UTEBluetoothState
 */
typedef NS_ENUM(NSInteger, UTEBluetoothStatus) {
    ///系统蓝牙打开
    UTEBluetoothStatusOpen = 0,
    ///系统蓝牙关闭
    UTEBluetoothStatusClose,
    ///重置蓝牙，链接暂时断开
    UTEBluetoothStatusResetting,
    ///不支持蓝牙
    UTEBluetoothStatusUnsupported,
    ///应用尚未被授权
    UTEBluetoothStatusUnauthorized,
    ///未知状态
    UTEBluetoothStatusUnknown,
};

/*!
 *  @enum UTEDevicesStatus
 */
typedef NS_ENUM(NSInteger, UTEDevicesStatus) {
    ///配对失败 Pairing failed
    UTEDevicesStatusConnectCheckFail = -1,
    ///连接成功与配对成功 App connected to the device successfully
    UTEDevicesStatusConnected = 0,
    UTEDevicesStatusDisconnected,
    UTEDevicesStatusConnectingError,        //The connection failed during the connection of the device.
                                            //if error=14 or 15,Please ignore the device in the system Bluetooth interface.
    ///连接超时 Connection Timed out
    UTEDevicesStatusConnectionTimedout,
    UTEDevicesStatusConnecting,
    UTEDevicesStatusDisconnecting,
//    UTEDevicesStatusSyncBegin,
//    UTEDevicesStatusSyncSuccess,
//    UTEDevicesStatusSyncError,
};

/*!
 *  @enum UTEScreenType
 */
typedef NS_ENUM(NSInteger, UTEScreenType) {
    UTEScreenTypeCircle,
    UTEScreenTypeSquare,
    
};

/*!
 *  @enum UTEDisplayMode
 */
typedef NS_ENUM(NSInteger, UTEDisplayMode) {
    UTEDisplayModeDigital     = 1,
    UTEDisplayModePointer        ,
    
};

/*!
 *  @enum UTECameraStatus
 */
typedef NS_ENUM(NSInteger, UTECameraStatus) {
    ///无 none
    UTECameraStatusNone,
    ///打开相机 Turn on the camera
    UTECameraStatusIn,
    ///拍照 photograph
    UTECameraStatusTake,
    ///退出相机 Exit Camera
    UTECameraStatusOut,
};

/*!
 *  @enum UTEFindWearStatus
 */
typedef NS_ENUM(NSInteger, UTEFindWearStatus) {
    //无 none
    UTEFindWearStatusNone  = -1,
    //关闭 close
    UTEFindWearStatusClose,
    //开启 open
    UTEFindWearStatusOpen,
};

/*!
 *  @enum UTERYDeviceLanguage
 */
typedef NS_ENUM(NSInteger, UTERYDeviceLanguage) {
    
    UTERYDeviceLanguageChinese    = 1,        //中文
    UTERYDeviceLanguageEnglish    = 2,        //英语
    UTERYDeviceLanguageKorean     = 3,        //韩语
    UTERYDeviceLanguageJapanese   = 4,        //日语
    UTERYDeviceLanguageGerman     = 5,        //德语
    UTERYDeviceLanguageSpanish    = 6,        //西班牙语
    UTERYDeviceLanguageFrench     = 7,        //法语
    UTERYDeviceLanguageItalian    = 8,        //意大利语
    UTERYDeviceLanguagePortuguese  = 9,       //葡萄牙语
    UTERYDeviceLanguageArabic     = 10,       //阿拉伯语
    UTERYDeviceLanguageIndia      = 11,       //印度语
    UTERYDeviceLanguageHindi      = 12,       //印地语
    UTERYDeviceLanguagePolish     = 13,       //波兰语
    UTERYDeviceLanguageRussian    = 14,       //俄语
    UTERYDeviceLanguageDutch      = 15,       //荷兰语
    UTERYDeviceLanguageTurkey     = 16,       //土耳其
    UTERYDeviceLanguageBengal     = 17,       //孟加拉语
    UTERYDeviceLanguageUrdu       = 18,       //乌尔都语
    UTERYDeviceLanguageIndonesia  = 19,       //印度尼西亚语
    UTERYDeviceLanguagePunjabi    = 20,       //旁遮普语
    UTERYDeviceLanguageThai       = 21,       //泰语
    UTERYDeviceLanguageCzech      = 22,       //捷克语
    UTERYDeviceLanguageChinese_t  = 23,       //中文繁体
    UTERYDeviceLanguageHebrew     = 24,       //希伯来语
    UTERYDeviceLanguageSlovakia   = 25,       //斯洛伐克
    UTERYDeviceLanguageHungary    = 26,       //匈牙利
    UTERYDeviceLanguageRomania    = 27,       //罗马尼亚
    UTERYDeviceLanguageBelarus    = 28,       //白俄罗斯
    UTERYDeviceLanguageEesti      = 29,       //爱沙尼亚
    UTERYDeviceLanguageAlgeria    = 30,       //阿尔及利亚
    UTERYDeviceLanguageAmharic    = 31,       //阿姆哈拉
    UTERYDeviceLanguageAzerbaijan = 32,       //阿塞拜疆
    UTERYDeviceLanguageIreland    = 33,       //爱尔兰
    UTERYDeviceLanguageOccitan    = 34,       //欧西坦语(奥克语)
    UTERYDeviceLanguageOriya      = 35,       //奥里亚语
    UTERYDeviceLanguageOromoo     = 36,       //奥罗莫语
    UTERYDeviceLanguageEuskera    = 37,       //巴斯克语
    UTERYDeviceLanguageBulgaria   = 38,       //保加利亚
    UTERYDeviceLanguageBosnia     = 39,       //波斯尼亚
    UTERYDeviceLanguagePersian    = 40,       //波斯语
    UTERYDeviceLanguagePhilippines   = 41,    //菲律宾
    UTERYDeviceLanguageKhmer      = 42,       //高棉语
    UTERYDeviceLanguageGujarat    = 43,       //古吉拉特语
    UTERYDeviceLanguageKazakhstan = 44,       //哈萨克斯坦
    UTERYDeviceLanguageAyisyen    = 45,       //海地克里奥语(海地语/克里奥耳语)
    UTERYDeviceLanguageHausa      = 46,       //豪萨语
    UTERYDeviceLanguageMontenegrin = 47,      //黑山语
    UTERYDeviceLanguageCatalunya  = 48,       //加泰罗尼亚语
    UTERYDeviceLanguageKannada    = 49,       //卡纳达语
    UTERYDeviceLanguageXhosa      = 50,       //科萨语
    UTERYDeviceLanguageHrvatska   = 51,       //克罗地亚语
    UTERYDeviceLanguageQuechua    = 52,       //克丘亚语
    UTERYDeviceLanguageKurdish    = 53,       //库尔德语
    UTERYDeviceLanguageLatin      = 54,       //拉丁语
    UTERYDeviceLanguageTzebuergesch = 55,     //卢森堡语
    UTERYDeviceLanguageKinyarwanda  = 56,     //卢旺达语
    UTERYDeviceLanguageDenmark    = 57,       //丹麦语
    UTERYDeviceLanguageRome       = 58,       //罗马语
    UTERYDeviceLanguageRomansh    = 59,       //罗曼什语
    UTERYDeviceLanguageMalagasy   = 60,       //马达加斯加
    UTERYDeviceLanguageMarathi    = 61,       //马拉地语(मराठी)
    UTERYDeviceLanguageMarathi_1  = 62,       //马拉提语
    UTERYDeviceLanguageMalayalam  = 63,       //马拉雅拉姆语
    UTERYDeviceLanguageMalaysia   = 64,       //马来西亚
    UTERYDeviceLanguageMacedonia  = 65,       //马其顿语
    UTERYDeviceLanguageMaithili   = 66,       //迈蒂利语
    UTERYDeviceLanguageGaelg      = 67,       //曼克斯(曼岛语)
    UTERYDeviceLanguageMyanmar    = 68,       //缅甸语
    UTERYDeviceLanguageNaples     = 69,       //那不勒斯语
    UTERYDeviceLanguageNepal      = 70,       //尼泊尔语
    UTERYDeviceLanguageNorge      = 71,       //挪威语
    UTERYDeviceLanguagePashto     = 72,       //普什图语
    UTERYDeviceLanguageChichewa   = 73,       //齐切瓦语
    UTERYDeviceLanguageSverige    = 74,       //瑞典
    UTERYDeviceLanguageSerbia     = 75,       //赛尔维亚语
    UTERYDeviceLanguageSinhalese  = 76,       //僧伽罗语
    UTERYDeviceLanguageSlovenski  = 77,       //斯洛文尼亚语
    UTERYDeviceLanguageKiswahili  = 78,       //斯瓦希里语
    UTERYDeviceLanguageCebu       = 79,       //宿务语
    UTERYDeviceLanguageSomali     = 80,       //索马里语
    UTERYDeviceLanguageSamoan     = 81,       //萨摩亚语
    UTERYDeviceLanguageTagalog    = 82,       //他加禄语
    UTERYDeviceLanguageTajik      = 83,       //塔吉克语
    UTERYDeviceLanguageTelangana  = 84,       //泰卢固语
    UTERYDeviceLanguageTamil      = 85,       //泰米尔语
    UTERYDeviceLanguageTigray     = 86,       //提格利尼亚语
    UTERYDeviceLanguageTurkmen    = 87,       //土库曼语
    UTERYDeviceLanguageUkraine    = 88,       //乌克兰语
    UTERYDeviceLanguageUzbekistan = 89,       //乌兹别克语
    UTERYDeviceLanguageGreek      = 90,       //希腊语
    UTERYDeviceLanguageSindhi     = 91,       //信德语
    UTERYDeviceLanguageShona      = 92,       //修纳语
    UTERYDeviceLanguageSyriac     = 93,       //叙利亚语
    UTERYDeviceLanguageIgbo       = 94,       //伊博语
    UTERYDeviceLanguageIlokano    = 95,       //伊洛卡诺语
    UTERYDeviceLanguagePending2   = 96,       //预留、待定
    UTERYDeviceLanguageYoruba     = 97,       //约鲁巴语
    UTERYDeviceLanguageFinnish    = 98,       //芬兰语
    UTERYDeviceLanguageVietnam    = 99,       //越南语
    UTERYDeviceLanguageIsiZulu    = 100,      //祖鲁语
    UTERYDeviceLanguageMongolia   = 101,      //蒙古语
    UTERYDeviceLanguageSpanisha   = 102,      //西班牙（拉丁美洲）
    
    UTERYDeviceLanguageOther      = UTERYDeviceLanguageEnglish, //other
    UTERYDeviceLanguageNone       = -1,
};

/*!
 *  @enum UTEMotionType
 */
typedef NS_ENUM(NSInteger, UTEMotionType) {
    UTEMotionTypeNone,
    UTEMotionTypeWalk,
    UTEMotionTypeRun,
    UTEMotionTypeClimbing,
    UTEMotionTypeCycling,
    UTEMotionTypeStand,
    UTEMotionTypeSleepLight,
    UTEMotionTypeSleepDeep,
    UTEMotionTypeAwake,
    UTEMotionTypeSwim,
};

/*!
 *  @enum UTEWeekType
 */
typedef NS_ENUM(NSInteger, UTEWeekType) {
    UTEWeekTypeNoLoop   = 0,
    
    UTEWeekTypeMon      = 0x01,
    UTEWeekTypeTue      = 0x02,
    UTEWeekTypeWed      = 0x04,
    UTEWeekTypeThur     = 0x08,
    UTEWeekTypeFri      = 0x10,
    UTEWeekTypeSat      = 0x20,
    UTEWeekTypeSun      = 0x40,
    
    UTEWeekTypeEveryday = 0x7F,

};

/*!
 *  @enum UTEScheduleType
 */
typedef NS_ENUM(NSInteger, UTEScheduleType) {
    UTEScheduleTypeNoLoop   = 0,
    
    UTEScheduleTypeSun      = 0x01,
    UTEScheduleTypeMon      = 0x02,
    UTEScheduleTypeTue      = 0x04,
    UTEScheduleTypeWed      = 0x08,
    UTEScheduleTypeThur     = 0x10,
    UTEScheduleTypeFri      = 0x20,
    UTEScheduleTypeSat      = 0x40,
    
    UTEScheduleTypeEveryday = 0x7F,

};



/*!
 *  @enum UTEWeather
 */
typedef NS_ENUM(NSInteger, UTEWeather) {
    ///晴天
    UTEWeatherSunny             = 0,
    ///多云
    UTEWeatherCloudy            = 1,
    ///阴
    UTEWeatherOvercast          = 2,
    ///阵雨
    UTEWeatherShower            = 3,
    ///雷阵雨
    UTEWeatherThundershower     = 4,
    ///雷阵雨伴有冰雹
    UTEWeatherThundershower_Hail    = 5,
    ///雨夹雪
    UTEWeatherSleet             = 6,
    ///小雨
    UTEWeatherLight_Rain        = 7,
    ///中雨
    UTEWeatherModerate_Rain     = 8,
    ///大雨
    UTEWeatherHeavy_Rain        = 9,
    ///暴雨
    UTEWeatherStorm             = 10,
    ///大暴雨
    UTEWeatherHeavy_Storm       = 11,
    ///特大暴雨
    UTEWeatherSevery_Storm      = 12,
    ///阵雪
    UTEWeatherSnow_Flurry       = 13,
    ///小雪
    UTEWeatherLight_Snow        = 14,
    ///中雪
    UTEWeatherModerate_Snow     = 15,
    ///大雪
    UTEWeatherHeavy_Snow        = 16,
    ///暴雪
    UTEWeatherSnow_Storm        = 17,
    ///雾
    UTEWeatherFoggy             = 18,
    ///冻雨
    UTEWeatherIce_Rain          = 19,
    ///沙尘暴
    UTEWeatherDust_Storm        = 20,
    ///小到中雨
    UTEWeatherLight_To_Moderate_Rain = 21,
    ///中到大雨
    UTEWeatherModerate_To_Heavy_Rain = 22,
    ///大到暴雨
    UTEWeatherHeavy_Rain_To_Storm    = 23,
    ///暴雨到大暴雨
    UTEWeatherStorm_To_Heavy_Storm   = 24,
    ///大暴雨到特大暴雨
    UTEWeatherHeavy_To_Severe_Storm  = 25,
    ///小到中雪
    UTEWeatherLight_To_Moderate_Snow = 26,
    ///中到大雪
    UTEWeatherModerate_To_Heavy_Snow = 27,
    ///大到暴雪
    UTEWeatherHeavy_Snow_To_Snowstorm = 28,
    ///浮尘
    UTEWeatherDust              = 29,
    ///扬沙
    UTEWeatherSand              = 30,
    ///强沙尘暴
    UTEWeatherSandStorm         = 31,
    ///霾
    UTEWeatherHaze              = 53,
    ///无
    UTEWeatherUnkown            = 99,

};

/*!
 *  @enum UTEWindType
 */
typedef NS_ENUM(NSInteger, UTEWindType) {
    ///无持续风向
    UTEWindTypeNoWind,
    ///东北风
    UTEWindTypeNorth_East,
    ///东风
    UTEWindTypeEast,
    ///东南风
    UTEWindTypeSounh_east,
    ///南风
    UTEWindTypeSouth,
    ///西南风
    UTEWindTypeSouth_West,
    ///西风
    UTEWindTypeWest,
    ///西北风
    UTEWindTypeNorth_West,
    ///北风
    UTEWindTypeNorth,
    ///旋转风
    UTEWindTypeWhirl,
    
};

/*!
 *  @enum UTEWindLevel
 */
typedef NS_ENUM(NSInteger, UTEWindLevel) {
    UTEWindLevelBreeze,
    UTEWindLevel3_4,
    UTEWindLevel4_5,
    UTEWindLevel5_6,
    UTEWindLevel6_7,
    UTEWindLevel7_8,
    UTEWindLevel8_9,
    UTEWindLevel9_10,
    UTEWindLevel10_11,
    UTEWindLevel11_12,
    
};

/*!
 *  @enum UTESportMonitorState
 */
typedef NS_ENUM(NSInteger, UTESportMonitorState) {
    ///表示空闲，无运动 Indicates idle and no movement
    UTESportMonitorStateIdel,
    ///占用，正在运动 Occupy, in motion
    UTESportMonitorStateOccupy,
    
};

/*!
 *  @enum UTESportOperatorType
 */
typedef NS_ENUM(NSInteger, UTESportOperatorType) {
    ///未开启运动  Sports not turned on
    UTESportOperatorTypeNone,
    ///开始运动  Start exercising
    UTESportOperatorTypeStart,
    ///暂停运动  Pause movement
    UTESportOperatorTypePause,
    ///继续  continue
    UTESportOperatorTypeContinue,
    ///结束  finish
    UTESportOperatorTypeFinish,
    ///运动已开始  Sports have started
    UTESportOperatorTypeStarted,
    ///运动已暂停  Sports paused
    UTESportOperatorTypePaused,
    ///运动未启动  Sports not started
    UTESportOperatorTypeNoStarted,
};

/*!
 *  @enum UTESportType
 */
typedef NS_ENUM(NSInteger, UTESportType) {
    UTESportTypeWorkout         = 1, ///单次运动  Single movement
    UTESportTypeRunPlay         = 2, ///跑步计划  Running Plan
    
};

/*!
 *  @enum EnumRYSDKSDKSportType
 */
typedef NS_ENUM(NSUInteger,EnumRYSDKSportType) {
    EnumRYSDKSportType1RUNNING=1,                        //户外跑步
    EnumRYSDKSportType2OUTDOOR_WALK=35,                  //户外走路
    EnumRYSDKSportType3INDOOR_WALK=26,                   //室内走路
    EnumRYSDKSportType4INDOOR_RUNNING=166,               //室内跑步(APP上是跑步机) 所有项目（325）不用这个枚举，请使用下面的 All projects (325) do not use this enumeration, please use the following
    EnumRYSDKSportType5TREADMILL=21,                     //室内跑步 (跑步机改为室内跑步)
    EnumRYSDKSportType6RIDE_BIKE=2,                      //户外骑行
    EnumRYSDKSportType7INDOOR_BIKE=134,                  //室内单车
    EnumRYSDKSportType8SWIMMING=4,                       //泳池游泳
    EnumRYSDKSportType9OPEN_WATER_SWIMMING=141,          //开放式水域游泳
    EnumRYSDKSportType10TRIATHLON=151,                   //铁人三项
    
    EnumRYSDKSportType11CLIMBING=8,                      //登山
    EnumRYSDKSportType12ELLIPTICAL_TRAINER=31,           //椭圆机
    EnumRYSDKSportType13ROWING_MACHING=41,               //划船机
    EnumRYSDKSportType14DANCE=17,                        //舞蹈
    EnumRYSDKSportType15FREE_TRAINING=25,                //自由训练
    EnumRYSDKSportType16GENERAL_EXERCISE=167,            //一般锻炼
    EnumRYSDKSportType17TRAIL_RUNNING=36,                //越野跑
    EnumRYSDKSportType18STRENGTH_TRAINING=28,            //肌力训练
    EnumRYSDKSportType19STEP_TRAINING=29,                //踏步机
    EnumRYSDKSportType20AIR_WALKER=42,                   //漫步机
    
    EnumRYSDKSportType21HIIT=97,                         //HIIT
    EnumRYSDKSportType22FITNESS_GAMING=82,               //健身
    EnumRYSDKSportType23GROUP_TRAINING=84,               //团体操
    EnumRYSDKSportType24YOGA=19,                         //瑜伽
    EnumRYSDKSportType25YOGA_CAT_STYLE=168,              //瑜伽猫式
    EnumRYSDKSportType26YOGA_COW_STYLE=169,              //瑜伽牛式
    EnumRYSDKSportType27YOGA_COBRA_POSE=170,             //瑜伽眼镜蛇式
    EnumRYSDKSportType28YOGA_HERO_1=171,                 //瑜伽英雄式1
    EnumRYSDKSportType29YOGA_HERO_2=172,                 //瑜伽英雄式2
    EnumRYSDKSportType30YOGA_HERO_3=173,                 //瑜伽英雄式3
    
    EnumRYSDKSportType31YOGA_ROLLER=174,                 //瑜伽滚轮
    EnumRYSDKSportType32JUMP_ROPE=3,                     //跳绳
    EnumRYSDKSportType33PILATES=49,                      //皮拉提斯
    EnumRYSDKSportType34MIXED_FITNESS=175,               //混合健身
    EnumRYSDKSportType35FUNCTIONAL_TRAINING=51,          //功能性训练
    EnumRYSDKSportType36PHYSICAL_TRAINING=52,            //体能训练
    EnumRYSDKSportType37TAEKWONDO=39,                    //跆拳道
    EnumRYSDKSportType38BOXING=34,                       //拳击
    EnumRYSDKSportType39KICKBOXING=58,                   //自由搏击
    EnumRYSDKSportType30KARATE=46,                       //空手道
        
    EnumRYSDKSportType41FENCING=89,                      //击剑
    EnumRYSDKSportType42CORE_TRAINING=80,                //核心训练
    EnumRYSDKSportType43BOXING_AEROBICS=176,             //拳击有氧
    EnumRYSDKSportType44KENDO=85,                        //剑道
    EnumRYSDKSportType45SINGLE_BAR=91,                   //单杠
    EnumRYSDKSportType46PARALLEL_BARS=92,                //双杠
    EnumRYSDKSportType47CYCLIC_TRAINING=177,             //循环训练
    EnumRYSDKSportType48AEROBIC_TRAINING=178,            //有氧运动
    EnumRYSDKSportType49CALLISTHENICS=83,                //健美操
    EnumRYSDKSportType50P90X=180,                        //P90X
    
    EnumRYSDKSportType51KETTLEBELL_TRAINING=153,         //壶铃训练
    EnumRYSDKSportType52MIXED_MARTIAL_ARTS=154,          //综合格斗
    EnumRYSDKSportType53STAIR_CLIMBING_MACHINE=181,      //爬楼梯机
    EnumRYSDKSportType54WEIGHTLIFTING=155,               //举重
    EnumRYSDKSportType55BALLET=182,                      //Barre
    EnumRYSDKSportType56HANDWHEEL=183,                   //手轮
    EnumRYSDKSportType57TRACK_AND_FIELD=156,             //田径
    EnumRYSDKSportType58WRESTLING=88,                    //角力
    EnumRYSDKSportType59MIND_BODY_EXERCISE=184,          //身心运动
    EnumRYSDKSportType60SOFTNESS_EXERCISES=185,          //柔软操
    
    EnumRYSDKSportType61MIXED_AEROBIC=186,               //混合有氧
    EnumRYSDKSportType62TRADITION_STRENGTH_TRAINING=187, //传统肌力训练
    EnumRYSDKSportType63CROSS_TRAINING=48,               //交叉训练
    EnumRYSDKSportType64GYMNASTICS=22,                   //体操
    EnumRYSDKSportType65LADDER_TRAINING=188,             //阶梯训练
    EnumRYSDKSportType66GENERAL_DANCE=189,               //一般舞蹈
    EnumRYSDKSportType67BELLY_DANCE=120,                 //肚皮舞
    EnumRYSDKSportType68JAZZ=135,                        //爵士舞
    EnumRYSDKSportType69LATIN_DANCE=56,                  //拉丁舞
    EnumRYSDKSportType70BARRE=59,                        //芭蕾
    
    EnumRYSDKSportType71STREET_DANCE=57,                 //街舞
    EnumRYSDKSportType72SQUARE_DANCE=149,                //广场舞
    EnumRYSDKSportType73ZUMBA_DANCE=190,                 //尊巴
    EnumRYSDKSportType74SOCIAL_DANCE=157,                //社交舞
    EnumRYSDKSportType75TAP_DANCING=158,                 //踢踏舞
    EnumRYSDKSportType76GENERAL_LEISURE_SPORTS=191,      //一般休闲运动
    EnumRYSDKSportType77ROLLER_SKATING=93,               //滑轮溜冰
    EnumRYSDKSportType78MARTIAL_ARTS=61,                 //武术
    EnumRYSDKSportType79TAI_CHI=32,                      //太极拳
    EnumRYSDKSportType80HULA_HOOP=94,                    //呼啦圈
    
    EnumRYSDKSportType81DISC_SPORTS=73,                  //飞盘
    EnumRYSDKSportType82DARTS=95,                        //飞镖
    EnumRYSDKSportType83ARCHERY=53,                      //射箭
    EnumRYSDKSportType84HORSE_RIDING=30,                 //骑马
    EnumRYSDKSportType85BATTLE_GAME=165,                 //对战游戏
    EnumRYSDKSportType86FLY_A_KITE=131,                  //放风筝
    EnumRYSDKSportType87TUG_OF_WAR=125,                  //拔河
    EnumRYSDKSportType88SWING=150,                       //秋千
    EnumRYSDKSportType89STAIRS=62,                       //爬楼
    EnumRYSDKSportType90OBSTACLE=140,                    //障碍赛
    
    EnumRYSDKSportType91FISHING=72,                      //钓鱼
    EnumRYSDKSportType92HUNTING=67,                      //打猎
    EnumRYSDKSportType93SCOOTER=163,                     //滑板车
    EnumRYSDKSportType94PARAGLIDER=164,                  //滑翔伞
    EnumRYSDKSportType95TEAM_SPORT=192,                  //团队竞技
    EnumRYSDKSportType96FITNESS_VIDEO_GAMES=193,         //健身电玩
    EnumRYSDKSportType97AEROBICS=179,                    //健行
    EnumRYSDKSportType98EQUESTRIAN_SPORTS=159,           //马术运动
    EnumRYSDKSportType99PLAY=69,                         //玩乐
    EnumRYSDKSportType100GENERAL_BALL_GAMES=194,         //一般球类运动
    
    EnumRYSDKSportType101BASKETBALL=10,                  //篮球
    EnumRYSDKSportType102BADMINTON=5,                    //羽毛球
    EnumRYSDKSportType103TABLE_TENNIS=6,                 //乒乓球
    EnumRYSDKSportType104TENNIS=7,                       //网球
    EnumRYSDKSportType105BILLIARDS=122,                  //撞球
    EnumRYSDKSportType106BOWLING=64,                     //保龄球
    EnumRYSDKSportType107VOLLEYBALL=13,                  //排球
    EnumRYSDKSportType108SHUTTLECOCK=33,                 //毽子球
    EnumRYSDKSportType109HANDBALL=63,                    //手球
    EnumRYSDKSportType110BASEBALL=12,                    //棒球
        
    EnumRYSDKSportType111SOFTBALL=90,                    //垒球
    EnumRYSDKSportType112CRICKET=14,                     //板球
    EnumRYSDKSportType113RUGBY=15,                       //美式橄榄球
    EnumRYSDKSportType114BEACH_FOOTBALL=118,             //沙滩足球
    EnumRYSDKSportType115BEACH_VOLLEYBALL=119,           //沙滩排球
    EnumRYSDKSportType116HOCKEY=16,                      //曲棍球
    EnumRYSDKSportType117RACQUETBALL=65,                 //英式壁球
    EnumRYSDKSportType118JET_FOOTBALL=136,               //藤球
    EnumRYSDKSportType119DODGE_BALL=126,                 //躲避球
    EnumRYSDKSportType120FOOTBALL=11,                    //足球
    
    EnumRYSDKSportType121GOLF_BALL=195,                  //高尔夫球
    EnumRYSDKSportType122POLO=161,                       //马球
    EnumRYSDKSportType123AMERICAN_SQUASH=196,            //美式壁球
    EnumRYSDKSportType124ENGLISH_RUGBY=197,              //英式橄榄球
    EnumRYSDKSportType125GATE_BALL=132,                  //门球
    EnumRYSDKSportType126PICKLEBALL=96,                  //匹克球
    EnumRYSDKSportType127POCKET_STICK_BALL=162,          //袋棍球
    EnumRYSDKSportType128GENERAL_WATER_ACTIVITIES=198,   //一般水上活动
    EnumRYSDKSportType129SAILBOAT=147,                   //帆船
    EnumRYSDKSportType130SURFING=106,                    //冲浪
        
    EnumRYSDKSportType131BOATING=23,                     //泛舟
    EnumRYSDKSportType132DRAGON_BOAT=127,                //划龙舟
    EnumRYSDKSportType133CANOE=199,                      //轻艇
    EnumRYSDKSportType134RACING_BOAT=145,                //赛艇
    EnumRYSDKSportType135JET_SKI=200,                    //水上摩托车
    EnumRYSDKSportType136PADDLE_BOARD_SURFING=143,       //立桨冲浪
    EnumRYSDKSportType137GROUND_WATER=201,               //潜水
    EnumRYSDKSportType138DIVING=105,                     //跳水
    EnumRYSDKSportType139PARAGLIDER_SURFING=202,         //滑翔伞冲浪
    EnumRYSDKSportType140SURFING_AND_WATER_SKIING=203,   //冲浪滑水
    
    EnumRYSDKSportType141WATER_BALLOON=160,              //水球
    EnumRYSDKSportType142WINDSURFING=204,                //风帆冲浪
    EnumRYSDKSportType143DRIFTING=128,                   //漂流活动
    EnumRYSDKSportType144UNDERWATER_FITNESS=205,         //水中健身
    EnumRYSDKSportType145WATER_SPORTS=206,               //水上运动
    EnumRYSDKSportType146FREESTYLE_SWIMMING=207,         //游泳_自由式
    EnumRYSDKSportType147BREAST_STROKE=208,              //游泳_蛙式
    EnumRYSDKSportType148BACKSTROKE=209,                 //游泳_仰式
    EnumRYSDKSportType149BUTTERFLY_STROKE=210,           //游泳_蝶式
    EnumRYSDKSportType150GENERAL_ICE_SPORTS=211,         //一般冰上运动
    
    EnumRYSDKSportType151SKATING=81,                     //溜冰
    EnumRYSDKSportType152ICE_HOCKEY=38,                  //冰球
    EnumRYSDKSportType153CURLING=66,                     //冰壶
    EnumRYSDKSportType154SNOW_CAR=148,                   //雪上摩托车
    EnumRYSDKSportType155SLED=212,                       //雪橇
    EnumRYSDKSportType156BIATHLON=121,                   //冬季两项
    EnumRYSDKSportType157CROSS_COUNTRY_SKIING=124,       //越野滑雪
    EnumRYSDKSportType158SKIING=37,                      //滑雪
    EnumRYSDKSportType159SNOWBOARDING=68,                //单板滑雪
    EnumRYSDKSportType160SNOWSHOE_HIKING=213,            //雪鞋健行
    
    EnumRYSDKSportType161SNOW_SPORTS=78,                 //雪地运动
    EnumRYSDKSportType162GENERAL_EXTREME_SPORTS=214,     //一般极限运动
    EnumRYSDKSportType163SKATEBOARDING=101,              //滑板
    EnumRYSDKSportType164ROCK_CLIMBING=111,              //攀岩
    EnumRYSDKSportType165BUNGEE_JUMPING=113,             //蹦极活动
    EnumRYSDKSportType166PARKOUR=104,                    //跑酷
    EnumRYSDKSportType167BMX_BIKE=123,                   //BMX
    EnumRYSDKSportType168ORIENTEERING=142,               //定向越野
    EnumRYSDKSportType169PARACHUTE=144,                  //跳伞
    EnumRYSDKSportType170RACING_CAR=146,                 //赛车
    
    EnumRYSDKSportType171TAKE_ELEVATOR=215,              //乘电梯
    EnumRYSDKSportType172TAKE_ESCALATOR=216,             //乘手扶梯
    EnumRYSDKSportType173GARDENING=217,                  //做园艺
    EnumRYSDKSportType174DOING_HOUSEHOLD=218,            //做家务
    EnumRYSDKSportType175IN_THE_CAR=219,                 //在车里
    EnumRYSDKSportType176MEDITATION=220,                 //冥想
    EnumRYSDKSportType177STATIC=221,                     //静止
    EnumRYSDKSportType178TILT=222,                       //倾斜
    EnumRYSDKSportType179WHEELCHAIR_MOBILITY=223,        //轮椅移动
    
    //补充，仅338使用的枚举
    EnumRYSDKSportType9WALKING=9,//健走
    EnumRYSDKSportType18SPINNING=18,//动感单车
    EnumRYSDKSportType20SIT_UP=20,//仰卧起坐
    EnumRYSDKSportType24JUMPING_JACK=24,//开合跳
    EnumRYSDKSportType27INDOOR_RUN=27,//室内跑步
    EnumRYSDKSportType40VO2MAX_TEST=40,//最大摄氧量测试
    EnumRYSDKSportType43HIKING=43,//徒步
    EnumRYSDKSportType44ATHLETICS=44,//田径
    EnumRYSDKSportType45WAIST_TRAINING=45,//腰腹训练
    EnumRYSDKSportType47COOLDOWN=47,//整理放松
    EnumRYSDKSportType50CROSS_FIT=50,//交叉配合
    EnumRYSDKSportType54FLEXIBILITY=54,//柔韧度
    EnumRYSDKSportType55MIXED_CARDIO=55,//混合有氧
    EnumRYSDKSportType60AUSTRALIAN_FOOTBALL=60,//澳式足球
    EnumRYSDKSportType70AMERICAN_FOOTBALL=70,//美式橄榄球
    EnumRYSDKSportType71HAND_CYCLING=71,//手摇车
    EnumRYSDKSportType74RUGGER=74,//橄榄球
    EnumRYSDKSportType75GOLF=75,//高尔夫
    EnumRYSDKSportType76FOLK_DANCE=76,//民族舞
    EnumRYSDKSportType77DOWNHILL_SKIING=77,//高山滑雪
    EnumRYSDKSportType79MIND_BODY=79,//舒缓冥想类运动
    EnumRYSDKSportType86LACROSSE=86,//长曲棍球
    EnumRYSDKSportType87ROLLING=87,//泡沫轴筋膜放松
    EnumRYSDKSportType98SHOOTING=98,//射击
    EnumRYSDKSportType99JUDO=99,//柔道
    EnumRYSDKSportType100TRAMPOLINE=100,//蹦床
    EnumRYSDKSportType102HOVERBOARD=102,//平衡车
    EnumRYSDKSportType103BLADING=103,//溜旱冰
    EnumRYSDKSportType107SNORKELING=107,//浮潜
    EnumRYSDKSportType108PULL_UP=108,//引体向上
    EnumRYSDKSportType109PUSH_UP=109,//俯卧撑
    EnumRYSDKSportType110PLANKING=110,//平板支撑
    EnumRYSDKSportType112HIGHTJUMP=112,//跳高
    EnumRYSDKSportType114LONGJUMP=114,//跳远
    EnumRYSDKSportType115MARATHON=115,//马拉松
    //以下是目前所没有的运动类型
    EnumRYSDKSportType116FLEXIBILITY_TRAINING=116,//灵活性训练116
    EnumRYSDKSportType117SIDEPLANK=117,//侧板118
    EnumRYSDKSportType129ENDURANCE_RUN=129,//耐力跑
    EnumRYSDKSportType130FAT_BURN_RUN=130,//燃脂跑
    EnumRYSDKSportType133GOLF_DRIVING_RANGE_MODE=133,//高尔夫练习场模式
    EnumRYSDKSportType137KAYAKING=137,//皮划艇
    EnumRYSDKSportType138KICK_BOXING=138,//搏击操
    EnumRYSDKSportType139MOTOR_BOAT=139,//摩托艇
    EnumRYSDKSportType152FITNESS=152,//健身
    
    //p10项目
    EnumRYSDKSportType228DUMBBELL=228,//哑铃
    EnumRYSDKSportType243TRACKRUN=243,//操场跑圈
};

/*!
 *  @enum UTESportHealthType
 */
typedef NS_ENUM(NSInteger, UTESportHealthType) {
    UTESportHealthTypeMotion_Summry         = 0x01, //运动总计数据
    UTESportHealthTypeMotion_Real_Time      = 0x02, //运动实时数据
    UTESportHealthTypeSci_Sleep             = 0x04, //科学睡眠数据
    UTESportHealthTypeWorkout               = 0x08, //单次运动数据
    UTESportHealthTypeFall_Asleep           = 0x10, //入睡通知数据
    
};

/*!
 *  @enum UTEAppMsgType
 */
typedef NS_ENUM(NSInteger, UTEAppMsgType) {
    UTEAppMsgTypeIncomingCall         = 1,
    UTEAppMsgTypeShortMsg,
    UTEAppMsgTypeWxMsg,
    UTEAppMsgTypeLongSitting,
    UTEAppMsgTypeSystemAffair,
    UTEAppMsgTypeAffairAlarm,
    UTEAppMsgTypeFlight,
    UTEAppMsgTypeHightRall,
    UTEAppMsgTypeFatigue,
    UTEAppMsgTypeWeather,
    
    UTEAppMsgTypeQQMsg,
    UTEAppMsgTypeCallHangup,
    UTEAppMsgTypeCallAnswer,
    UTEAppMsgTypeMissedCall,
    UTEAppMsgTypeEmail,
    UTEAppMsgTypeMuteIncomingCall,
    UTEAppMsgTypeFindMobileApp,
    UTEAppMsgTypeCameraMode,
    UTEAppMsgTypeTakePicture,
    UTEAppMsgTypeSceneIntelligentEx,
    
    UTEAppMsgTypeIntelligenceFlight,
    UTEAppMsgTypeIntelligenceRail,
    UTEAppMsgTypeIntelligenceTired,
    UTEAppMsgTypeIntelligenceWeather,
    UTEAppMsgTypeIntelligenceHotel,
    UTEAppMsgTypeWhatsapp,
    UTEAppMsgTypeFacebookKatana,
    UTEAppMsgTypeTwitter,
    UTEAppMsgTypeFacebookOrca,
    UTEAppMsgTypeGoogleAndroid,
    
    UTEAppMsgTypeNetlixMediaclient,
    UTEAppMsgTypeNaverLine,
    UTEAppMsgTypeInstagram,
    UTEAppMsgTypeSnapchat,
    UTEAppMsgTypeNikeplus,
    UTEAppMsgTypeStrava,
    UTEAppMsgTypeEndomondo,
    UTEAppMsgTypeSynergyDisconnect,
    UTEAppMsgTypeMenstruationBegin,
    UTEAppMsgTypeMenstruationStop,
    
    UTEAppMsgTypePregnancyBegin,
    UTEAppMsgTypePregnancySop,
    UTEAppMsgTypePregnancyEnable,
    UTEAppMsgTypeAirPressureWarning,
    UTEAppMsgTypeTelegram,
    UTEAppMsgTypeKakao,
    UTEAppMsgTypeHealth,
    UTEAppMsgTypeHealthHealthyLivin,
    UTEAppMsgTypeWearEngine,
    UTEAppMsgTypeOutgoingCall,
    
    UTEAppMsgTypeCalendar,
    UTEAppMsgTypeNotepad,
    UTEAppMsgTypeUmetripFlight,
    UTEAppMsgTypeYoyo,
    UTEAppMsgTypeYoyoSchedule,
    UTEAppMsgTypeYoyoExpress,
    UTEAppMsgTypeYoyoBreath,
    UTEAppMsgTypeYoyoStand,
    UTEAppMsgTypeYoyoActivity,
    
    UTEAppMsgTypeRejectCall = 126,
    UTEAppMsgTypeUnknown    = 127,
};


/*!
 *  @enum UTEApp
 */
typedef NS_ENUM(NSInteger, UTEApp) {
    UTEAppSMS,
    UTEAppQQ,
    UTEAppWechat,
//    UTEAppPhone,//不使用该枚举设置来电，通过来电设置接口设置
    UTEAppFacebook,
    UTEAppTwitter,
    UTEAppWhatsApp,
    UTEAppFacebookMessenger,
    UTEAppLine,
    UTEAppSkype,
//    UTEAppHangouts,//已经停用下架
    
    UTEAppLinkedin,
    UTEAppInstagram,
    UTEAppViber,
    UTEAppKakaoTalk,
    UTEAppVKontakte,
    UTEAppSnapchat,
//    UTEAppGooglePlus,//已经停用下架
    UTEAppGmail,
    UTEAppFlickr,
    UTEAppTumblr,
    UTEAppPinterest,
    UTEAppYouTube,
    UTEAppTelegram,
    UTEAppTruecaller,
    UTEAppPaytm,
    UTEAppZalo,
    UTEAppImo,
    UTEAppMicrosoftTeams,

    UTEAppMicrosoftOutlook,
    UTEAppSwiggy,
    UTEAppZomato,
    UTEAppGpay,
    UTEAppPhonePe,
//    UTEAppHotstar,//找不到ID，屏蔽
    UTEAppPrimeVideo,
    UTEAppFlipkart,
    UTEAppAmazon,
    UTEAppMyntra,
//    UTEAppNoiseFit,//定制app，不再专设枚举，屏蔽
    UTEAppDailyHunt,
    UTEAppInshorts,
    UTEAppBookMyShow,
    UTEAppAppleCalendar,
    UTEAppJioTV,
    UTEAppMakeMyTrip,
    UTEAppNetflix,
//    UTEAppOla,//定制app，不再专设枚举，屏蔽
//    UTEAppFastrackReflex,//定制app，不再专设枚举，屏蔽
    UTEAppUber,
    UTEAppYTMusic,
    
    UTEAppWhatsAppBusiness,
//    UTEAppDunzo,//定制app，不再专设枚举，屏蔽
    UTEAppGaana,
    UTEAppGoogleDrive,
    UTEAppGoogleChat,
    UTEAppWynkMusic,
    UTEAppYahoo,
//    UTEAppTitanSmartWorld,//定制app，不再专设枚举，屏蔽
    UTEAppSlack,
    UTEAppOkru,
    UTEAppYandex,
    
    UTEAppSpotify,
    UTEAppiOSMail,
    
    ///其他APP
    ///Other App
    UTEAppiOSOther,
    
    //20240218新增
    UTEAppMagalu,
    UTEAppAmericanas,
    UTEAppEnjoei,
    UTEAppAliexpress,
    UTEAppShopee,
    UTEAppX,
    UTEAppTikTok,
    UTEApp99_taxi,
    UTEAppIfood,
    UTEAppMercadolivre,
    UTEAppAlarm,
    UTEAppTechnosConnect,
    UTEAppNubank,
    UTEAppBradesco,
    UTEAppItaú,
    UTEAppBanco_do_brasil,
    UTEAppCorreios,
    UTEAppBanco_inter,
    UTEAppCaixa_economica,
    UTEAppNeon,
    UTEAppSantander,
    UTEAppNext,
//    UTEAppPrime_vídeo,
    UTEAppGoogle_calendar,
    UTEAppShein,
    UTEAppGoogle_task,
    UTEAppMicrosoft_to_do,
    UTEAppTickTick,
    UTEAppTodoist,
    
    UTEAppDouYin,
    ///需要固件支持否则无效，还是属于其他提醒通知
    
    UTEAppMeesho,
    UTEAppZivame,
    UTEAppAjio,
    UTEAppUrbanic,
    UTEAppNykaa,
    UTEAppHealthifyme,
    UTEAppCultfit,
    UTEAppFlo,
    UTEAppHinge,
    UTEAppBumble,
    UTEAppAlipay,
    UTEAppMeituan,
    UTEAppWeibo,
    UTEAppAICOACH,
    UTEAppMorningpaper,
    UTEAppBlinkit,
    UTEAppZepto,
    UTEAppAha,
    UTEAppBigbasket,
    UTEAppYonoBySBI,
    UTEAppJioSaavn,
    UTEAppMyJio,
    UTEAppIMobilePay,
    UTEAppAirtel,
    UTEAppRapido,
    UTEApp365scores,
    UTEApp7eleven,
    UTEAppABABank,
    UTEAppAcleda,
    UTEAppAYAPay,
    UTEAppBangkokBank,
    UTEAppBe,
    UTEAppBkash,
    UTEAppBolt,
    UTEAppCabify,
    UTEAppCBPay,
    UTEAppChatGPT,
    UTEAppDcard,
    UTEAppDidi,
    UTEAppDISCORD,
    UTEAppFilgoal,
    UTEAppFoodpanda,
    UTEAppGoogle,
    UTEAppGrab,
    UTEAppHaraj,
    UTEAppHungerStation,
    UTEAppInstapay,
    UTEAppKBZPay,
    UTEAppKPLUS,
    UTEAppKrungsri,
    UTEAppKrungthaiNEXT,
    UTEAppLineman,
    UTEAppMessage,
    UTEAppMrsool,
    UTEAppNoon,
    UTEAppPickaboo,
    UTEAppRappi,
    UTEAppRednote,
    UTEAppSnapp,
    UTEAppSTCPay,
    UTEAppTADA,
    UTEAppThreads,
    UTEAppTinder,
    UTEAppTrueMoney,
    UTEAppTtb,
    UTEAppUABPay,
    UTEAppUala,
    UTEAppVeeka,
    UTEAppWaze,
    UTEAppXanhSM,
    UTEAppYassir,
    UTEAppZoom,
    UTEAppMAX,
    UTEAppFlipboard,
    UTEAppPandora,
    UTEAppGoogleMap,
    UTEAppLyft,
    UTEAppGoogleDuo,
    UTEAppShazam,
    UTEAppDingTalk,
    UTEAppStrava,
    UTEAppAVITO,
    UTEAppRussia_VK,
    UTEAppRussia_odnoklassniki,
    UTEAppRussia_yandex,
    UTEAppRussia_yandex_mobile,
    UTEAppRussia_Mail,
    UTEAppRussia_yandex_mail,
};

/*!
 *  @enum UTEModeSportRunningPostureType
 */
typedef NS_ENUM(NSInteger, UTEModeSportRunningPostureType) {
    UTEModeSportRunningPostureType0         = 0
    
};

typedef NS_ENUM(NSInteger, UTEHealthType0) {
    UTEHealthType0Step                  = 0x01,
    UTEHealthType0Calorie               = 0x02,
    UTEHealthType0Distance              = 0x04,
    UTEHealthType1RestingHeartRate      = 0x08,
    UTEHealthType0HRMMax                = 0x10,
    UTEHealthType0HRMMin                = 0x20,
    UTEHealthType0HRMDynamic            = 0x40,
};

typedef NS_ENUM(NSInteger, UTEHealthType1) {
    UTEHealthType1BloodOxygen           = 0x01,
    UTEHealthType1RestingHeartRateV2    = 0x02,
    UTEHealthType1Height                = 0x04,
    UTEHealthType1HRMAve                = 0x08,
    UTEHealthType1RestingHeartRateV3    = 0x10,
};

typedef NS_ENUM(NSInteger, UTEHealthType2) {
    UTEHealthType2BloodPressure         = 0x01,
    UTEHealthType2Mood                  = 0x02,

};


typedef NS_ENUM(NSInteger, UTEFirmwareType) {
    UTEFirmwareTypeBT           = 1 << 0,
    UTEFirmwareTypePatch        = 1 << 1,
    UTEFirmwareTypeUI           = 1 << 2,
    UTEFirmwareTypeM3           = 1 << 3,
    UTEFirmwareTypeDSP          = 1 << 4,
    UTEFirmwareTypePIC          = 1 << 5,
    UTEFirmwareTypeCLK0         = 1 << 6,
    UTEFirmwareTypeCLK1         = 1 << 7,
    
    UTEFirmwareTypeSGS          = 1 << 8,
    UTEFirmwareTypeBOOT         = 1 << 9,
    UTEFirmwareTypeLINUX        = 1 << 10,
    UTEFirmwareTypeWear         = 1 << 11,
};

typedef NS_ENUM(NSInteger, UTEHealthType3) {
    UTEHealthType3HighPAIDur         = 0x01,
    UTEHealthType3HRV                = 0x02,

};

typedef NS_ENUM(NSInteger, UTEBatteryStatus) {
    UTEBatteryStatusNormal              = 0,
    UTEBatteryStatusCharging,
    UTEBatteryStatusChargingFully,

};

/*!
 *  @enum UTEAIDialStatus
 */
typedef NS_ENUM(NSInteger, UTEAIDialStatus) {
    ///进入ai表盘
    UTEAIDialStatusEnterAIDial                 = 0x01,
    ///开始录音
    UTEAIDialStatusStartRecording              = 0x02,
    ///结束录音
    UTEAIDialStatusEndRecording                = 0x03,
    ///退出ai表盘
    UTEAIDialStatusExitAIDial                  = 0x04,
    ///提醒打开APP
    UTEAIDialStatusReminderOpenApp             = 0x05,
    ///识别失败
    UTEAIDialStatusIdentificationFailed        = 0x06,
    ///识别成功
    UTEAIDialStatusIdentificationSuccessful    = 0x07,
    ///重新录入
    UTEAIDialStatusReEnter                     = 0x08,
    ///开始生成
    UTEAIDialStatusStartGenerating             = 0x09,
    ///app等待超时
    UTEAIDialStatusWaitingForTimeout           = 0x0a,
    ///AI服务器繁忙
    UTEAIDialStatusAIServerBusy                = 0x0b,
    ///设为表盘
    UTEAIDialStatusSetDial                     = 0x0c,
    ///重新生成
    UTEAIDialStatusRegeneration                = 0x0d,
    ///剩余次数用完（250515新增）
    UTEAIDialStatusNoNumberTimes               = 0x0e,
};

/*!
 *  @enum UTEChatGPTStatus
 */
typedef NS_ENUM(NSInteger, UTEChatGPTStatus) {
    ///进入ChatGPT
    UTEChatGPTStatusEnterChatGPT                 = 0x01,
    ///开始录音
    UTEChatGPTStatusStartRecording               = 0x02,
    ///结束录音
    UTEChatGPTStatusEndRecording                 = 0x03,
    ///退出ChatGPT
    UTEChatGPTStatusExitChatGPT                  = 0x04,
    ///提醒打开APP
    UTEChatGPTStatusReminderOpenApp              = 0x05,
    ///识别失败
    UTEChatGPTStatusIdentificationFailed         = 0x06,
    ///识别成功
    UTEChatGPTStatusIdentificationSuccessful     = 0x07,
    ///确认内容
    UTEChatGPTStatusConfirmContent               = 0x08,
    ///开始回答
    UTEChatGPTStatusStartAnswer                  = 0x09,
    ///回答完成
    UTEChatGPTStatusAnswerCompleted              = 0x0a,
    ///APP正在回复上个问题
    UTEChatGPTStatusAnswering                    = 0x0b,

};

/*!
 *  @enum UTEChatGPTMemorandumStatus
 */
typedef NS_ENUM(NSInteger, UTEChatGPTMemorandumStatus) {
    ///准备发送数据,app端发送
    UTEChatGPTMemorandumStatusReadySending              = 0x00,
    ///准备完成，固件返回
    UTEChatGPTMemorandumStatusReadyComplete             = 0x01,
    ///当前一组数据处理完成
    UTEChatGPTMemorandumStatusCurrentDataComplete       = 0x02,
    ///校验不通过
    UTEChatGPTMemorandumStatusCRCError                  = 0x03,
    
    
};

/*!
 *  @enum Offline Voice Control (Activate Status)
 */
typedef NS_ENUM(NSInteger, UTEOVControlActivateStatus) {
    UTEOVControlActivateStatusAuthorized,
    UTEOVControlActivateStatusServerAuthorizationFailed,
    UTEOVControlActivateStatusUnauthorized,
    UTEOVControlActivateStatusAuthorizationFailed,
    UTEOVControlActivateStatusTimingAnomalies,
};

@end

/*!
 *  @enum UTEIntelligentAgentType
 */
typedef NS_ENUM(NSInteger, UTEIntelligentAgentType) {
    ///默认ChatGPT
    UTEIntelligentAgentTypeChatGPT                 = 0x00,
    ///十万个为什么
    UTEIntelligentAgentTypeWhys                    = 0x01,
    ///命题小作文
    UTEIntelligentAgentTypeProposition             = 0x02,
    ///掌上科技馆
    UTEIntelligentAgentTypeScience                 = 0x03,
    ///植物学家
    UTEIntelligentAgentTypeBotanist                = 0x04,
    ///动物学家
    UTEIntelligentAgentTypeZoologist               = 0x05,
    ///历史常识
    UTEIntelligentAgentTypeHistorical              = 0x06,
    ///儿童百科全书
    UTEIntelligentAgentTypeEncyclopedia            = 0x07,
    ///英语词典
    UTEIntelligentAgentTypeEnglishDictionary       = 0x08,
    ///数学解题
    UTEIntelligentAgentTypeMathematics             = 0x09,
    ///提示词大师
    UTEIntelligentAgentTypeCueWord                 = 0x0a,
    ///故事大王
    UTEIntelligentAgentTypeStoryKing               = 0x0b,
    ///诗句编写
    UTEIntelligentAgentTypeVerse                   = 0x0c,
    ///写作助手
    UTEIntelligentAgentTypeWriting                 = 0x0d,
    ///情绪疏解
    UTEIntelligentAgentTypeEmotional               = 0x0e,
    ///悄悄话
    UTEIntelligentAgentTypeWhisper                 = 0x0f,
    ///讲笑话
    UTEIntelligentAgentTypeTellJokes               = 0x10,
    ///数字炸弹
    UTEIntelligentAgentTypeDigitalBomb             = 0x11,
    ///魔镜
    UTEIntelligentAgentTypeMagicMirror             = 0x12,
    ///今天吃什么
    UTEIntelligentAgentTypeEatToday                = 0x13,
    ///星座运势
    UTEIntelligentAgentTypeConstellation           = 0x14,
    ///社交技巧
    UTEIntelligentAgentTypeSocialSkills            = 0x15,
    ///食物热量查询
    UTEIntelligentAgentTypeFoodCalorieInquiry      = 0x16,
    ///MBTI性格测试
    UTEIntelligentAgentTypeMBTI                    = 0x17,
    ///广告狂人
    UTEIntelligentAgentTypeMADMEN                  = 0x18,
    ///PAS销售文案
    UTEIntelligentAgentTypePAS                     = 0x19,
    ///活动策划
    UTEIntelligentAgentTypeEventPlanning           = 0x1a,
    ///周报生成
    UTEIntelligentAgentTypeWeeklyReport            = 0x1b,
    ///海绵
    UTEIntelligentAgentTypeSponge                  = 0x1c,
    ///小鳄鱼
    UTEIntelligentAgentTypeBabyCrocodile           = 0x1d,
    ///抱抱熊
    UTEIntelligentAgentTypeTeddyBear               = 0x1e,
    ///拼写改错
    UTEIntelligentAgentTypeSpellingCorrection      = 0x1f,
    ///嘲讽大师
    UTEIntelligentAgentTypeTaunt                   = 0x20,
    ///塔罗牌大师
    UTEIntelligentAgentTypeTarotCard               = 0x21,
    ///说唱歌手
    UTEIntelligentAgentTypeRAPPER                  = 0x22,


};

/*!
 *  @enum UTEAILargeModelType
 */
typedef NS_ENUM(NSInteger, UTEAILargeModelType) {
    ///不支持模型
    UTEAILargeModelTypeEmpty                             = -1,
    ///豆包
    UTEAILargeModelTypeDouBao                            = 0x00,
    ///DeepSeek
    UTEAILargeModelTypeDeepSeek                          = 0x01,
    ///智谱
    UTEAILargeModelTypeZhipu                             = 0x02,
    ///文心一言
    UTEAILargeModelTypeERNIEBot                          = 0x03,
    ///通义千问
    UTEAILargeModelTypeQWen                              = 0x04,
    ///星火
    UTEAILargeModelTypeStarfire                          = 0x05,
    ///Kimi
    UTEAILargeModelTypeKimi                              = 0x06,
};

/*!
 *  @enum UTEALICMD
 */
typedef NS_ENUM(NSInteger, UTEALICMD) {
    UTEALICMDERROR                                       = -1,
    ///01
    UTEALICMDCONNECT                                     = 0x01,
    ///02
    UTEALICMDWRITEDATA                                   = 0x02,
    ///03
    UTEALICMDREADDATA                                    = 0x03,
    ///04
    UTEALICMDCLOSE                                       = 0x04,
    
    
};

/*!
 *  @enum UTERegionType
 */
typedef NS_ENUM(NSInteger, UTERegionType) {
    UTERegionTypeChina               = 1,
    UTERegionTypeEurope,
    UTERegionTypeMideast,
    UTERegionTypeJapanKorea,
    UTERegionTypeTaiwanMacauHK,
    UTERegionTypeOther,
};

/*!
 *  @enum Device Settings Type
 */
typedef NS_ENUM(NSInteger, UTESystemSettingsType) {
    ///恢复出厂设置
    UTESystemSettingsTypeReset       = 0x01, //Reset factory settings
    ///关机
    UTESystemSettingsTypeShutdown      = 0x02,
    ///重启
    UTESystemSettingsTypeReboot        = 0x04,

};

/*!
 *  @enum Wear Status
 */
typedef NS_ENUM(NSInteger, UTEWearStatus) {
    UTEWearStatusIdle                   = 1 << 0,
    UTEWearStatusCameraOpen             = 1 << 1, //If not in this status, please remember to turn on your camera
    
    UTEWearStatusVideoMode              = 1 << 2,  //Recording video mode
    UTEWearStatusPhotoMode              = 1 << 3,  //Taking a photo
    UTEWearStatusAudioMode              = 1 << 4,  //Recording audio mode
    
    UTEWearStatusWearing                = 1 << 5,
    UTEWearStatusLowBattery             = 1 << 6,
    UTEWearStatusWiFiOpen               = 1 << 7,
    UTEWearStatusIdentifyingImg         = 1 << 8,
    UTEWearStatusCameraCalibrate        = 1 << 9,
    UTEWearStatusReset                  = 1 << 10,
    
    UTEWearStatusLiveNetworkConnecting  = 1 << 11,
    UTEWearStatusStreaming              = 1 << 12,
    UTEWearStatusMediaNumGetting        = 1 << 13,
    UTEWearStatusNetworkListGetting     = 1 << 14,
    
    UTEWearStatusLiveNetworkConnected   = 1 << 15,
    UTEWearStatusLiveNetworkDisconnecting   = 1 << 16,

};

/*!
 *  @enum Device Storage Type
 */
typedef NS_ENUM(NSInteger, UTEStorageType) {
    ///存储的总图片数量
    UTEStorageTypePhotoTotal          = 0x01, //The total number of photos
    ///新增拍的图片数量（未同步）
    UTEStorageTypePhotoNew            = 0x02,   //The number of new photos(Not syncing)
    ///录音的总数量
    UTEStorageTypeRecordingTotal      = 0x03,
    ///新增录音的数量
    UTEStorageTypeRecordingNew        = 0x04,
    ///录制视频的总数
    UTEStorageTypeVideoTotal          = 0x05,
    ///新增录制视频的数量
    UTEStorageTypeVideoNew            = 0x06,
    ///存储的总内存 （单位byte）
    UTEStorageTypeTotalSize           = 0x07,
    ///存储的剩余内存（单位byte）
    UTEStorageTypeTotalAvailable      = 0x08,
};

/*!
 *  @enum Device direction Type
 */
typedef NS_ENUM(NSInteger, UTEDirectionType) {
    ///横屏
    UTEDirectionTypeLandscape    = 0x01,
    ///竖屏
    UTEDirectionTypePortrait     = 0x02,

};

/*!
 *  @enum Device Audio Style
 */
typedef NS_ENUM(NSInteger, UTEAudioStyle) {
    ///音效标准模式
    UTEAudioStyleNormal           = 0x01,
    ///音效轻柔模式
    UTEAudioStyleSoft             = 0x02,
    ///音效增强模式
    UTEAudioStyleStrengthen       = 0x03,
    ///音效降噪模式
    UTEAudioStyleNoiseReduction   = 0x04,
    
    ///耳机工作异常
    UTEAudioStyleAbnormal         = 0xff,

};

/*!
 *  @enum Device Led Level
 */
typedef NS_ENUM(NSInteger, UTELedLevel) {
    UTELedLevelLow       = 1,
    UTELedLevelNormal,
    UTELedLevelHigh,

};

/*!
 *  @enum PasswordType
 */
typedef NS_ENUM(NSInteger, UTEPasswordStatus) {
    UTEPasswordStatusSame,      //Same as the previous account password
    UTEPasswordStatusNoAccount, //The device did not have an account password before
    UTEPasswordStatusDifferent, //Wrong password
};

/*!
 *  @enum UTEControlType
 */
typedef NS_ENUM(NSInteger, UTEControlType) {
    UTEControlTypeVideoStart,
    UTEControlTypeVideoStop,
    UTEControlTypeVoiceStart,
    UTEControlTypeVoiceStop,
    UTEControlTypeTakePic,
    UTEControlTypeAiPic,
};

/*!
 *  @enum UTEControlStatus
 */
typedef NS_ENUM(NSInteger, UTEControlStatus) {
    UTEControlStatusTakePicSuccess      = 1,
    UTEControlStatusTakePicFail,
    
    UTEControlStatusVideoStartSuccess,
    UTEControlStatusVideoStartFail,
    UTEControlStatusVideoStopSuccess,
    UTEControlStatusVideoStopFail,
    
    UTEControlStatusVoiceStartSuccess,
    UTEControlStatusVoiceStartFail,
    UTEControlStatusVoiceStopSuccess,
    UTEControlStatusVoiceStopFail,
    
    UTEControlStatusStreamingStartSuccess,
    UTEControlStatusStreamingStartFail,
    UTEControlStatusStreamingStopSuccess,
    UTEControlStatusStreamingStopFail,
    
    UTEControlStatusResetSuccess,
    UTEControlStatusResetFail,
    
    UTEControlStatusGetMediaFilesSuccess,
    UTEControlStatusGetMediaFilesFail,
    
};

/*!
 *  @enum UTEOfflineVoiceAuth
 */

typedef NS_ENUM(NSInteger, UTEOfflineVoiceAuth) {
    UTEOfflineVoiceAuthAuthorized,
    UTEOfflineVoiceAuthServerFail,
    UTEOfflineVoiceAuthUnauthorized,
    UTEOfflineVoiceAuthFail,
};
typedef NS_ENUM(NSInteger, UTEMediaStatus) {
    UTEMediaStatusStop,       //Stop recording audio or video
    UTEMediaStatusStart,      //Start recording audio or video
    UTEMediaStatusProcessing, //In the recording audio or video
    UTEMediaStatusTakePic,
    UTEMediaStatusOtherBusy,
};

/*!
 *  @enum UTEOfflineVoiceAuthorizationStatus
 */
typedef NS_ENUM(NSInteger, UTEOfflineVoiceAuthorizationStatus) {
    ///授权通过
    UTEOfflineVoiceAuthorizationStatusAuthorized,
    ///服务器授权失败
    UTEOfflineVoiceAuthorizationStatusServerFail,
    ///设备未授权
    UTEOfflineVoiceAuthorizationStatusUnauthorized,
    ///离线语音授权失败
    UTEOfflineVoiceAuthorizationStatusFail,
    ///设备时间异常
    UTEOfflineVoiceAuthorizationStatusNone,

};

/*!
 *  @enum UTEAiModel
 */
typedef NS_ENUM(NSInteger, UTEAiModel) {
    UTEAiModelERNIEBot,
    UTEAiModelAdFlash,
    UTEAiModelDoubao,
    UTEAiModeliFlytek,
    UTEAiModelChatGPT,
    UTEAiModelMicrosoft,
    UTEAiModelTencentYuanbao,
    UTEAiModelDeepseek,
    UTEAiModelYoujie,
};

/*!
 *  @enum UTEOffWristModel
 */
typedef NS_ENUM(NSInteger, UTEOffWristModel) {
    ///无
    UTEOffWristModelNone = 0,
    ///心率
    UTEOffWristModelHRM,
    ///血氧
    UTEOffWristModelSpo2,
    ///定时血氧
    UTEOffWristModelSpo2Time,
    ///hrv
    UTEOffWristModelHRV,
    ///压力
    UTEOffWristModelStress,
    ///佩戴
    UTEOffWristModelWear,
    ///工厂测试模式
    UTEOffWristModelFactcry,
    ///体温
    UTEOffWristModelTemperature,
    ///FPC测试
    UTEOffWristModelFPCTest,
    ///一键测量
    UTEOffWristModelOneKeyTest,
    ///情绪
    UTEOffWristModelEmo,
    ///血压
    UTEOffWristModelBP,
};

/*!
 *  @enum UTEDeviceError
 */
typedef NS_ENUM(NSInteger, UTEDeviceError) {
    
    UTEDeviceErrorDisconnect            = -1000, //设备已断开
    UTEDeviceErrorCRC                   = -999,  //数据校验失败
    UTEDeviceErrorAppParamEmpty         = -998,  //App参数为空
    
    UTEDeviceErrorCharacteristicNil     = -996,  //SDK的特征值为空
    UTEDeviceErrorNetworkTimeout        = -995,
    UTEDeviceErrorDownload              = -994,
    UTEDeviceErrorFolderOperation       = -993,
    
    UTEDeviceErrorDialSending           = -853,  //表盘数据指令在交互中
    UTEDeviceErrorBetaFile              = -852,  //Beta文件有错误
    UTEDeviceErrorDialCancel            = -851,  //设备主动取消表盘
    UTEDeviceErrorDialFail              = -850,  //表盘操作失败
    UTEDeviceErrorDialOpen              = -849,  //打开文件失败
    UTEDeviceErrorDialRest              = -848,  //重置失败
    UTEDeviceErrorDialCmd               = -847,  //指令失败
    UTEDeviceErrorDialSize              = -846,  //表盘的大小与传入的图片大小不一致
    
    UTEDeviceErrorOTABinNil             = -807,  //文件bin 不存在
    UTEDeviceErrorOTAConfigNil          = -806,  //文件config 不存在
    UTEDeviceErrorOTAUnzipFail          = -805,  //固件解压文件
    UTEDeviceErrorOTADeleteFail         = -804,  //固件删除文件
    UTEDeviceErrorOTADiffVersion        = -803,  //固件版本不一致
    UTEDeviceErrorOTAHighTemperature    = -802,  //设备温度过高
    UTEDeviceErrorOTACancelFail         = -801,  //设备升级取消失败
    UTEDeviceErrorOTAFirmwarePath       = -800,  //固件路径为空
    
    UTEDeviceErrorOTA_JLFail                = -724, //OTA升级失败
    UTEDeviceErrorOTA_JLDataIsNull          = -723, //OTA升级数据为空
    UTEDeviceErrorOTA_JLCommandFail         = -722, //OTA指令失败
    UTEDeviceErrorOTA_JLSeekFail            = -721, //OTA标示偏移查找失败
    UTEDeviceErrorOTA_JLInfoFail            = -720, //OTA升级固件信息错误
    UTEDeviceErrorOTA_JLLowPower            = -719, //OTA升级设备电压低
    UTEDeviceErrorOTA_JLEnterFail           = -718, //未能进入OTA升级模式
    UTEDeviceErrorOTA_JLUpgrading           = -717, //OTA升级中
    UTEDeviceErrorOTA_JLReconnect           = -716, //OTA需重连设备(uuid方式)
    UTEDeviceErrorOTA_JLReboot              = -715, //OTA需设备重启
    UTEDeviceErrorOTA_JLPreparing           = -714, //OTA准备中
    UTEDeviceErrorOTA_JLPrepared            = -713, //OTA准备完成
    UTEDeviceErrorOTA_JLFailVerification    = -712, //升级数据校验失败
    UTEDeviceErrorOTA_JLFailCompletely      = -711, //升级失败
    UTEDeviceErrorOTA_JLFailKey             = -710, //升级数据校验失败
    UTEDeviceErrorOTA_JLFailErrorFile       = -709, //升级文件出错
    UTEDeviceErrorOTA_JLFailUboot           = -708, //uboot不匹配
    UTEDeviceErrorOTA_JLFailLenght          = -707, //升级过程长度出错
    UTEDeviceErrorOTA_JLFailFlash           = -706, //升级过程flash读写失败
    UTEDeviceErrorOTA_JLFailCmdTimeout      = -705, //升级过程指令超时
    UTEDeviceErrorOTA_JLFailSameVersion     = -704, //相同版本
    UTEDeviceErrorOTA_JLFailTWSDisconnect   = -703, //TWS耳机未连接
    UTEDeviceErrorOTA_JLFailNotInBin        = -702, //耳机未在充电仓
    UTEDeviceErrorOTA_JLReconnectWithMacAddr= -701, //OTA需重连设备(mac方式)
    
    UTEDeviceErrorOTAFail               = -700,  //升级失败了，原因要看Log
    UTEDeviceErrorDataEmpty             = -601,   //设备返回空值
    UTEDeviceErrorNotSupport            = -600,   //不支持功能指令
    
    
    UTEDeviceErrorParamNotStandardized  = -100, //数据不符合规范
    UTEDeviceErrorStarburstAi           = -101, //AI库返回错误
    
    UTEDeviceErrorCommonFail            = -2,    //操作失败
    UTEDeviceErrorOTAUnknow             = -1,    //其他未知不能升级
    
    UTEDeviceErrorNone                  = 0,        //正常（无错误）
    UTEDeviceErrorCmdTimeout            = 408,      //指令超时
    UTEDeviceErrorFileEmpty             = 701,      //文件为空
    UTEDeviceErrorParamEmpty            = 40003,    //参数为空
    ///正常（无错误） normal No problem
    UTEDeviceErrorNil                   = 100000,   //正常（无错误）
    
    
    UTEDeviceErrorOTALowPower           = 109002,//ota传输错误手表电量低
    UTEDeviceErrorOTAProgress           = 109019,//设备ota升级中
    UTEDeviceErrorDialSizeTooBig        = 140009,//设备内存不足
    UTEDeviceErrorDialUpperLimit        = 140004,//表盘数量达上限
};
/*!
 *  @enum UTEMeasurementType
 */
typedef NS_ENUM(NSInteger, UTEMeasurementType) {
    UTEMeasurementTypeNONE              = 0,
    ///心率
    UTEMeasurementTypeHRM               = 0x0001,
    ///血氧
    UTEMeasurementTypeOXY               = 0x0002,
    ///心电
    UTEMeasurementTypeECG               = 0x0004,
    ///HRV
    UTEMeasurementTypeHRV               = 0x0008,
    ///压力
    UTEMeasurementTypePressure          = 0x0010,
    ///体温
    UTEMeasurementTypeTemperature       = 0x0020,
    ///血压
    UTEMeasurementTypeBlood             = 0x0040,
    ///情绪
    UTEMeasurementTypeEmo               = 0x0080,
    ///其他
    UTEMeasurementTypeOther             = 0x0100,

};
/*!
 *  @enum UTEAudioType
 */
typedef NS_ENUM(NSInteger, UTEAudioType) {
    
    UTEAudioTypeOPUS,
    UTEAudioTypeSBC,
    UTEAudioTypePCM,
    UTEAudioTypeWAV,
};
/*!
 *  @enum UTEWearFunction
 */
typedef NS_ENUM(NSInteger, UTEWearFunction) {
    
    UTEWearFunctionSpeaker = 1, //see UTESpeakerType (UTEWearFunctionModel.value)
    UTEWearFunctionLED,         //see UTELEDType (UTEWearFunctionModel.value)
    UTEWearFunctionMic,         //see UTEMicType (UTEWearFunctionModel.value)
    UTEWearFunctionButton,      //see UTEButtonKey | UTEButtonKeyEvent (UTEWearFunctionModel.value)
    UTEWearFunctionTP,          //see UTEButtonTP (UTEWearFunctionModel.value)
    UTEWearFunctionHall,
    UTEWearFunctionGsensor3,
    UTEWearFunctionSensorLight,
    UTEWearFunctionGsensor6,
    UTEWearFunctionTFCard,
    UTEWearFunctionWiFi,
    UTEWearFunctionCamera,

};

/*!
 *  @enum UTESpeakerType
 */
typedef NS_ENUM(NSInteger, UTESpeakerType) {
    
    UTESpeakerTypeLeft                  = 1 << 0,
    UTESpeakerTypeRight                 = 1 << 1,
    UTESpeakerTypeCenter                = 1 << 2,
    UTESpeakerTypeFourth                = 1 << 3,
};

/*!
 *  @enum UTELEDType
 */
typedef NS_ENUM(NSInteger, UTELEDType) {
    
    UTELEDTypeRed1                      = 1 << 0,
    UTELEDTypeGreen2                    = 1 << 1,
    UTELEDTypeBlue3                     = 1 << 2,
    UTELEDTypeLED4                      = 1 << 3,
};

/*!
 *  @enum UTEMicType
 */
typedef NS_ENUM(NSInteger, UTEMicType) {
    
    UTEMicTypeLeft                      = 1 << 0,
    UTEMicTypeRight                     = 1 << 1,
    UTEMicTypeCenter                    = 1 << 2,
};
/*!
 *  @enum UTEButtonKey
 */
typedef NS_ENUM(NSInteger, UTEButtonKey) {
    
    UTEButtonKeyPower                    = 0x0100,
    UTEButtonKeyPic                      = 0x0200,
    UTEButtonKeyAudio                    = 0x0400,
    UTEButtonKeyFourth                   = 0x0800,
};

typedef NS_ENUM(NSInteger, UTEButtonKeyEvent) {
    
    UTEButtonKeyEventClick               = 1 << 0,
    UTEButtonKeyEventDouble              = 1 << 1,
    UTEButtonKeyEventPress               = 1 << 2,

};
/*!
 *  @enum UTEButtonTP
 */
typedef NS_ENUM(NSInteger, UTEButtonTP) {
    
    UTEButtonTP_up                      = 1 << 0,
    UTEButtonTP_down                    = 1 << 1,
    UTEButtonTP_left                    = 1 << 2,
    UTEButtonTP_right                   = 1 << 3,
    UTEButtonTP_click                   = 1 << 4,
    UTEButtonTP_double                  = 1 << 5,
    UTEButtonTP_press                   = 1 << 6,
};

/*!
 *  @enum UTEVoiceAiStatus
 */
typedef NS_ENUM(NSInteger, UTEVoiceAiStatus) {
    
    UTEVoiceAiStatusStop,
    UTEVoiceAiStatusStart,
    UTEVoiceAiStatusContinue,
};

/*!
 *  @enum UTEWearOTAStatus
 */
typedef NS_ENUM(NSInteger, UTEWearOTAStatus) {
    
    UTEWearOTAStatusRebootSuccess,
    UTEWearOTAStatusRebootFail,
    UTEWearOTAStatusOpenISPSuccess,
    UTEWearOTAStatusOpenISPFail,
};

/*!
 *  @enum UTEControlMedia
 */
typedef NS_ENUM(NSInteger, UTEControlMedia) {
    
    UTEControlMediaPlay,
    UTEControlMediaPause,
    UTEControlMediaSongPre,
    UTEControlMediaSongNext,
    UTEControlMediaVolumeUp,
    UTEControlMediaVolumeDown,
};

/*!
 *  @enum UTEStabilizationCalibrationStatus
 */
typedef NS_ENUM(NSInteger, UTEStabilizationCalibrationStatus) {
    
    UTEStabilizationCalibrationStatusStart,
    UTEStabilizationCalibrationStatusSuccess,
    UTEStabilizationCalibrationStatusFail,
};
/*!
 *  @enum UTEMeasurementType
 */
typedef NS_ENUM(NSInteger, UTEHealthLabFunctionType) {
    
    ///血压
    UTEHealthLabFunctionTypeBloodPressure            = 0x01,
    ///血糖
    UTEHealthLabFunctionTypeBloodSugar               = 0x02,
    

};

/*!
 *  @enum UTEWearSDCardStatus
 */
typedef NS_ENUM(NSInteger, UTEWearSDCardStatus) {
    
    UTEWearSDCardStatusNormal,
    
    //The SD card needs to be formatted. please invoke setGlassesSystemSettingsType:UTESystemSettingsTypeRestore
    UTEWearSDCardStatusAbnormal,

};

/*!
 *  @enum UTEBPUnitType
 */
typedef NS_ENUM(NSInteger, UTEBPUnitType) {
    
    ///
    UTEBPUnitTypmmHg            = 0x00,
    ///
    UTEBPUnitTypeKPa            = 0x01,
    

};

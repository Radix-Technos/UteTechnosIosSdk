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
 *  @enum UTEDeviceLanguage
 */
typedef NS_ENUM(NSInteger, UTEDeviceLanguage) {
    
    UTEDeviceLanguageChinese    = 1,        //中文
    UTEDeviceLanguageEnglish    = 2,        //英语
    UTEDeviceLanguageKorean     = 3,        //韩语
    UTEDeviceLanguageJapanese   = 4,        //日语
    UTEDeviceLanguageGerman     = 5,        //德语
    UTEDeviceLanguageSpanish    = 6,        //西班牙语
    UTEDeviceLanguageFrench     = 7,        //法语
    UTEDeviceLanguageItalian    = 8,        //意大利语
    UTEDeviceLanguagePortuguese  = 9,       //葡萄牙语
    UTEDeviceLanguageArabic     = 10,       //阿拉伯语
    UTEDeviceLanguageIndia      = 11,       //印度语
    UTEDeviceLanguageHindi      = 12,       //印地语
    UTEDeviceLanguagePolish     = 13,       //波兰语
    UTEDeviceLanguageRussian    = 14,       //俄语
    UTEDeviceLanguageDutch      = 15,       //荷兰语
    UTEDeviceLanguageTurkey     = 16,       //土耳其
    UTEDeviceLanguageBengal     = 17,       //孟加拉语
    UTEDeviceLanguageUrdu       = 18,       //乌尔都语
    UTEDeviceLanguageIndonesia  = 19,       //印度尼西亚语
    UTEDeviceLanguagePunjabi    = 20,       //旁遮普语
    UTEDeviceLanguageThai       = 21,       //泰语
    UTEDeviceLanguageCzech      = 22,       //捷克语
    UTEDeviceLanguageChinese_t  = 23,       //中文繁体
    UTEDeviceLanguageHebrew     = 24,       //希伯来语
    UTEDeviceLanguageSlovakia   = 25,       //斯洛伐克
    UTEDeviceLanguageHungary    = 26,       //匈牙利
    UTEDeviceLanguageRomania    = 27,       //罗马尼亚
    UTEDeviceLanguageBelarus    = 28,       //白俄罗斯
    UTEDeviceLanguageEesti      = 29,       //爱沙尼亚
    UTEDeviceLanguageAlgeria    = 30,       //阿尔及利亚
    UTEDeviceLanguageAmharic    = 31,       //阿姆哈拉
    UTEDeviceLanguageAzerbaijan = 32,       //阿塞拜疆
    UTEDeviceLanguageIreland    = 33,       //爱尔兰
    UTEDeviceLanguageOccitan    = 34,       //欧西坦语(奥克语)
    UTEDeviceLanguageOriya      = 35,       //奥里亚语
    UTEDeviceLanguageOromoo     = 36,       //奥罗莫语
    UTEDeviceLanguageEuskera    = 37,       //巴斯克语
    UTEDeviceLanguageBulgaria   = 38,       //保加利亚
    UTEDeviceLanguageBosnia     = 39,       //波斯尼亚
    UTEDeviceLanguagePersian    = 40,       //波斯语
    UTEDeviceLanguagePhilippines   = 41,    //菲律宾
    UTEDeviceLanguageKhmer      = 42,       //高棉语
    UTEDeviceLanguageGujarat    = 43,       //古吉拉特语
    UTEDeviceLanguageKazakhstan = 44,       //哈萨克斯坦
    UTEDeviceLanguageAyisyen    = 45,       //海地克里奥语(海地语/克里奥耳语)
    UTEDeviceLanguageHausa      = 46,       //豪萨语
    UTEDeviceLanguageMontenegrin = 47,      //黑山语
    UTEDeviceLanguageCatalunya  = 48,       //加泰罗尼亚语
    UTEDeviceLanguageKannada    = 49,       //卡纳达语
    UTEDeviceLanguageXhosa      = 50,       //科萨语
    UTEDeviceLanguageHrvatska   = 51,       //克罗地亚语
    UTEDeviceLanguageQuechua    = 52,       //克丘亚语
    UTEDeviceLanguageKurdish    = 53,       //库尔德语
    UTEDeviceLanguageLatin      = 54,       //拉丁语
    UTEDeviceLanguageTzebuergesch = 55,     //卢森堡语
    UTEDeviceLanguageKinyarwanda  = 56,     //卢旺达语
    UTEDeviceLanguageDenmark    = 57,       //丹麦语
    UTEDeviceLanguageRome       = 58,       //罗马语
    UTEDeviceLanguageRomansh    = 59,       //罗曼什语
    UTEDeviceLanguageMalagasy   = 60,       //马达加斯加
    UTEDeviceLanguageMarathi    = 61,       //马拉地语(मराठी)
    UTEDeviceLanguageMarathi_1  = 62,       //马拉提语
    UTEDeviceLanguageMalayalam  = 63,       //马拉雅拉姆语
    UTEDeviceLanguageMalaysia   = 64,       //马来西亚
    UTEDeviceLanguageMacedonia  = 65,       //马其顿语
    UTEDeviceLanguageMaithili   = 66,       //迈蒂利语
    UTEDeviceLanguageGaelg      = 67,       //曼克斯(曼岛语)
    UTEDeviceLanguageMyanmar    = 68,       //缅甸语
    UTEDeviceLanguageNaples     = 69,       //那不勒斯语
    UTEDeviceLanguageNepal      = 70,       //尼泊尔语
    UTEDeviceLanguageNorge      = 71,       //挪威语
    UTEDeviceLanguagePashto     = 72,       //普什图语
    UTEDeviceLanguageChichewa   = 73,       //齐切瓦语
    UTEDeviceLanguageSverige    = 74,       //瑞典
    UTEDeviceLanguageSerbia     = 75,       //赛尔维亚语
    UTEDeviceLanguageSinhalese  = 76,       //僧伽罗语
    UTEDeviceLanguageSlovenski  = 77,       //斯洛文尼亚语
    UTEDeviceLanguageKiswahili  = 78,       //斯瓦希里语
    UTEDeviceLanguageCebu       = 79,       //宿务语
    UTEDeviceLanguageSomali     = 80,       //索马里语
    UTEDeviceLanguageSamoan     = 81,       //萨摩亚语
    UTEDeviceLanguageTagalog    = 82,       //他加禄语
    UTEDeviceLanguageTajik      = 83,       //塔吉克语
    UTEDeviceLanguageTelangana  = 84,       //泰卢固语
    UTEDeviceLanguageTamil      = 85,       //泰米尔语
    UTEDeviceLanguageTigray     = 86,       //提格利尼亚语
    UTEDeviceLanguageTurkmen    = 87,       //土库曼语
    UTEDeviceLanguageUkraine    = 88,       //乌克兰语
    UTEDeviceLanguageUzbekistan = 89,       //乌兹别克语
    UTEDeviceLanguageGreek      = 90,       //希腊语
    UTEDeviceLanguageSindhi     = 91,       //信德语
    UTEDeviceLanguageShona      = 92,       //修纳语
    UTEDeviceLanguageSyriac     = 93,       //叙利亚语
    UTEDeviceLanguageIgbo       = 94,       //伊博语
    UTEDeviceLanguageIlokano    = 95,       //伊洛卡诺语
    UTEDeviceLanguagePending2   = 96,       //预留、待定
    UTEDeviceLanguageYoruba     = 97,       //约鲁巴语
    UTEDeviceLanguageFinnish    = 98,       //芬兰语
    UTEDeviceLanguageVietnam    = 99,       //越南语
    UTEDeviceLanguageIsiZulu    = 100,      //祖鲁语
    UTEDeviceLanguageMongolia   = 101,      //蒙古语
    UTEDeviceLanguageSpanisha   = 102,      //西班牙（拉丁美洲）
    
    UTEDeviceLanguageOther      = UTEDeviceLanguageEnglish, //other
    UTEDeviceLanguageNone       = -1,
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
//    UTEAppPhone,//通过来电设置接口设置
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
//    UTEAppPrimeVideo,
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
};

/*!
 *  @enum UTEModeSportRunningPostureType
 */
typedef NS_ENUM(NSInteger, UTEModeSportRunningPostureType) {
    UTEModeSportRunningPostureType0         = 0
    
};

@end


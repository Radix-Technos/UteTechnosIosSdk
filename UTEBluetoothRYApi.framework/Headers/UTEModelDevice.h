//
//  UTEModelDevice.h
//  UTEBluetoothRYApi
//
//  Created by V V on 2023/3/8.
//  Copyright © 2023 vv. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <UTEBluetoothRYApi/UTEBluetoothEnum.h>


/*!
 *  UTEModelDeviceElement
 *
 */
@interface UTEModelDeviceElement  : NSObject
///蓝牙接口版本号 Bluetooth interface version number
@property (nonatomic, copy) NSString            *protocolVersion;
///设备类型 Device Type
@property (nonatomic, copy) NSString            *deviceType;
///设备硬件版本号 Device hardware version number
@property (nonatomic, copy) NSString            *deviceVersion;
///设备电话号码 Device phone number
@property (nonatomic, copy) NSString            *phoneNumber;
///设备蓝牙 mac 地址 Device Bluetooth MAC address
@property (nonatomic, copy) NSString            *address;
///设备 IMEI 号 Equipment IMEI number
@property (nonatomic, copy) NSString            *imei;
///设备软件版本号 Device software version number
@property (nonatomic, copy) NSString            *systemVersion;
///设备开源声明文档版本号 Device Open Source Declaration Document Version Number
@property (nonatomic, copy) NSString            *opensourceVersion;
///设备 SN 号 Device SN number
@property (nonatomic, copy) NSString            *serialNumber;
///设备型号 Equipment model
@property (nonatomic, copy) NSString            *model;
///设备 EMMC 号 Equipment EMMC number
@property (nonatomic, copy) NSString            *emmc;
///穿戴设备唯一标识上报云端类型，0：mac 地址；1：SN   Unique identification of wearable devices, reporting cloud type, 0: MAC address; 1: SN
@property (nonatomic, copy) NSString            *deviceIdToServerType;
///OTA 服务器包名 OTA server package name
@property (nonatomic, copy) NSString            *otaPackageName;
///设备型号 Equipment model
@property (nonatomic, copy) NSString            *certModel;
///手表模式。0：非增强手表模式；1：增强手表模式 Watch mode. 0: Non enhanced watch mode; 1: Enhanced Watch Mode
@property (nonatomic, copy) NSString            *powerSaveModel;
///OTA版本发布类型 OTA version release type
@property (nonatomic, copy) NSString            *otaArea;
///
@property (nonatomic, copy) NSString            *linkId;
///
@property (nonatomic, copy) NSString            *deviceBtModel;
///设备版本类型。0：release；1：beta；其他：预留 Device version type. 0: release; 1: Beta; Other: Reserved
@property (nonatomic, copy) NSString            *deviceVersionType;
///维测日志加密后唯一标识一台设备的 UDID The UDID that uniquely identifies a device after encrypting the maintenance log
@property (nonatomic, copy) NSString            *deviceUdId;
///
@property (nonatomic, copy) NSString            *deviceUdIdParameter;
///设备名 device name
@property (nonatomic, copy) NSString            *deviceName;
///
@property (nonatomic, copy) NSString            *sportVersion;

@end


/*!
 *  UTEModelDeviceElement
 *
 */
@interface UTEModelDeviceInfoStatus1  : NSObject

@property(nonatomic, assign) BOOL               isSciSleep;
@property(nonatomic, assign) BOOL               isContinuousHeartRate;
@property(nonatomic, assign) BOOL               isRunningCourse;
@property(nonatomic, assign) BOOL               isAutoHeartRate;
@property(nonatomic, assign) BOOL               isSupportJumpRope;
@property(nonatomic, assign) BOOL               isSupportScientificFatLoss;
@property(nonatomic, assign) BOOL               isSupportFitnessAge;


@end

/*!
 *  UTEModelDevice
 *  This model shows all the attributes of the device and which functions are supported.
 *  Note:Many attributes have values only when the device is connected,Expressed by ①.
 */
@interface UTEModelDevice : NSObject
/**
 *  Device connection status
 */
@property(nonatomic, assign) BOOL               isConnected;
/**
 *  Device name
 */
@property (nonatomic,copy  ) NSString           *name;
/**
 *  Unique identification of device
 *  Note:If the same phone is connected to the same device A, the identifier will not change; if different phone are connected to the same device A, the identifier will be different.
 */
@property (nonatomic,copy  ) NSString           *identifier;
/**
 *  Device signal strength
 *  Note:if isScanRepeat = true, it will change in real time during scanning, and the connected device will not be assigned a value.
 */
@property (nonatomic,assign) NSInteger          rssi;

/**
 *  The device is in an upgraded status
 */
@property (nonatomic,assign) BOOL               isUpdateMode;

/**
 *  Device broadcast contains (4 keys):
 *
 *    kCBAdvDataServiceUUIDs
 *    kCBAdvDataLocalName
 *    kCBAdvDataManufacturerData
 *    kCBAdvDataIsConnectable
 *
 *  Note:If the device is connected, this value will become empty.
 */
@property (nonatomic,strong) NSDictionary        *advertisementData;
/**
 *  During scanning, broadcast the Bluetooth address (The corresponding value of kCBAdvDataManufacturerData in advertisementData)
 *  Note:If the device is connected, this value will become empty.
 *  Some firmware does not support this broadcast data, so it is empty.
 *  e.g @"112233445566" is 11:22:33:44:55:66
 */
@property (nonatomic,copy  ) NSString            *advertisementAddress;
/**
 *  What broadcast services does the device have (kCBAdvDataServiceUUIDs in advertisementData).
 *  Note:If the device is connected, this value will become empty.
 */
@property (nonatomic,strong) NSMutableArray<NSString *>   *mServicesUUID;
/**
 *  ① After the device is connected, the UUID service owned.
 *  Note:If the device is not connected, this value is empty.
 */
@property (nonatomic,strong) NSMutableArray<NSString *>   *mServicesConnectedUUID;

/**
 *  ① Maximum length of Bluetooth 5.0 data packet
 *  Note:If the firmware does not support Bluetooth 5.0, the value is 0.
 */
@property (nonatomic,assign) NSInteger          maxBluetooth5DataLength;
/**
 *  ①Full firmware version e.g.@"CVD07V000888"
 */
@property (nonatomic,copy  ) NSString           *version;
/**
 *  ①Firmware name @"CVD07"
 */
@property (nonatomic,copy  ) NSString           *versionName;
/**
 *  ①Firmware version number e.g.@"000888"
 */
@property (nonatomic,copy  ) NSString           *versionNum;
/**
 *  ①battery (0~100)
 */
@property(nonatomic,assign)NSInteger            battery;
/**
 *  ①The Bluetooth address of the device.
 */
@property (nonatomic,strong) NSData             *address;
/**
 *  ①Device Bluetooth address (string type) e.g. @"152a354b5e66"
 */
@property (nonatomic,copy  ) NSString           *addressStr;

/**
 *  ①Firmware Platform
 */
@property (nonatomic,assign) UTEDevicePlatformType  platform;
/**
 *  See  UTEModelDeviceElement
 */
@property (nonatomic,strong) UTEModelDeviceElement  *element;
@property (nonatomic,strong) UTEModelDeviceInfoStatus1 *infoStatus1;

/**
 *  ①Support Acount
 */
@property(nonatomic,assign) BOOL                hasAccount;
/**
 *  ①Support Clock
 */
@property(nonatomic,assign) BOOL                hasClock;
/**
 *  ①Support App Market
 */
@property(nonatomic,assign) BOOL                hasAppMarket;
/**
 *  ①Support Telephone
 */
@property(nonatomic,assign) BOOL                hasTelephone;
/**
 *  ①Support File download
 */
@property(nonatomic,assign) BOOL                hasFileDownload;
/**
 *  ①Support Contact
 */
@property(nonatomic,assign) BOOL                hasContact;
/**
 *  ①Support Device Manager
 */
@property(nonatomic,assign) BOOL                hasDeviceMgr;
/**
 *  ①Support ECG
 */
@property(nonatomic,assign) BOOL                hasECG;


/**
 *  ①Support Ephemeris
 */
@property(nonatomic,assign) BOOL                hasEphemeris;
/**
 *  ①Support ESIM
 */
@property(nonatomic,assign) BOOL                hasESIM;
/**
 *  ①Support File manager
 */
@property(nonatomic,assign) BOOL                hasFileMgr;
/**
 *  ①Support File upload
 */
@property(nonatomic,assign) BOOL                hasFileUpload;
/**
 *  ①Support Health
 */
@property(nonatomic,assign) BOOL                hasHealth;
/**
 *  ①Support Font
 */
@property(nonatomic,assign) BOOL                hasFont;
/**
 *  ①Support HRM
 */
@property(nonatomic,assign) BOOL                hasHRM;
/**
 *  ①Support Account honour
 */
@property(nonatomic,assign) BOOL                hasAccountHonour;


/**
 *  ①Support Http Proxy
 */
@property(nonatomic,assign) BOOL                hasHttpProxy;
/**
 *  ①Support Position
 */
@property(nonatomic,assign) BOOL                hasPosition;
/**
 *  ①Support Lost
 */
@property(nonatomic,assign) BOOL                hasLost;
/**
 *  ①Support Maintainable and measurable
 */
@property(nonatomic,assign) BOOL                hasMAM;
/**
 *  ①Support Physiological Cycle
 */
@property(nonatomic,assign) BOOL                hasPhysiologicalCycle;
/**
 *  ①Support Middleware
 */
@property(nonatomic,assign) BOOL                hasMiddleware;
/**
 *  ①Support Music Control
 */
@property(nonatomic,assign) BOOL                hasMusicControl;
/**
 *  ①Support Notification
 */
@property(nonatomic,assign) BOOL                hasNotification;


/**
 *  ①Support OTA
 */
@property(nonatomic,assign) BOOL                hasOTA;
/**
 *  ①Support P2P
 */
@property(nonatomic,assign) BOOL                hasP2P;
/**
 *  ①Support PHDKIT
 */
@property(nonatomic,assign) BOOL                hasPHDKIT;
/**
 *  ①Support SleepBreathing
 */
@property(nonatomic,assign) BOOL                hasSleepBreathing;
/**
 *  ①Support Socket
 */
@property(nonatomic,assign) BOOL                hasSocket;
/**
 *  ①Support Pressure
 */
@property(nonatomic,assign) BOOL                hasPressure;
/**
 *  ①Support Synergy
 */
@property(nonatomic,assign) BOOL                hasSynergy;
/**
 *  ①Support AppServer
 */
@property(nonatomic,assign) BOOL                hasAppServer;


/**
 *  ①Support Voice Assistant
 */
@property(nonatomic,assign) BOOL                hasVoiceAssistant;
/**
 *  ①Support Dial
 */
@property(nonatomic,assign) BOOL                hasDial;
/**
 *  ①Support Event Upload
 */
@property(nonatomic,assign) BOOL                hasEventUpload;
/**
 *  ①Support Weather
 */
@property(nonatomic,assign) BOOL                hasWeather;
/**
 *  ①Support Web Socket Proxy
 */
@property(nonatomic,assign) BOOL                hasWebSocketProxy;
/**
 *  ①Support Sport
 */
@property(nonatomic,assign) BOOL                hasSport;
/**
 *  ①Support HID
 */
@property(nonatomic,assign) BOOL                hasHID;
/**
 *  ①Support WordClock
 */
@property(nonatomic,assign) BOOL                hasWorldClock;
/**
 *  ①Support Language File
 */
@property(nonatomic,assign) BOOL                hasLanguageFile;
/**
 *  ①Support HealthExpansion
 */
@property(nonatomic,assign) BOOL                hasHealthExpansion;

/**
 *  ①Support Blood
 */
@property(nonatomic,assign) BOOL                hasBlood;

/**
 *  ①Support Mood
 */
@property(nonatomic,assign) BOOL                hasMood;
@end

/*!
 *  UTEModelDialElement
 *
 */
@interface UTEModelDialElement  : NSObject

/**
 *  Defualt: Time display is 09-58, Format HH-mm
 */
@property (nonatomic, copy) NSString            *timeHHmm;
/**
 *  Defualt: Date display is 08-12 (August 12).  Format MM-dd
 */
@property (nonatomic, copy) NSString            *timeMMdd;
/**
 *  Defualt: Time display is AM
 */
@property(nonatomic,assign) BOOL                timePM;
/**
 *  Defualt: Week display is Sun .  0 is Sun, 1 is Mon , 2 is Tue  ... 6 is Sat
 */
@property(nonatomic,assign) NSInteger           timeWeek;

/**
 *  Morning or afternoon e.g. AM.  Whether it exists, or show and hide
 */
@property (nonatomic,assign) BOOL               hasAM_PM;
@property(nonatomic, strong) UIImage            *imgAM_PM;
@property(nonatomic, assign) CGRect             rectAM_PM;
/**
 *  Battery Icon
 */
@property (nonatomic,assign) BOOL               hasIconBattery;
@property(nonatomic, strong) UIImage            *imgBattery;
@property(nonatomic, assign) CGRect             rectBattery;
/**
 *  Date e.g. 08/12   is  August /12
 *  If you want to display 12/08 (August 12), you need to swap the coordinates of 0 and 1, 8 and 2.
 */
@property (nonatomic,assign) BOOL               hasDate;

/** e.g. 08/12  From left to right, first digit ,  @"0"  */
@property(nonatomic, strong) UIImage            *imgDate1;
@property(nonatomic, assign) CGRect             rectDate1;

/** e.g. 08/12  From left to right, the second digit ,  @"8"  */
@property(nonatomic, strong) UIImage            *imgDate2;
@property(nonatomic, assign) CGRect             rectDate2;

/** e.g. 08/12  From left to right, the third digit ,  @"1"  */
@property(nonatomic, strong) UIImage            *imgDate3;
@property(nonatomic, assign) CGRect             rectDate3;

/** e.g. 08/12  From left to right, the fourth digit ,  @"2"  */
@property(nonatomic, strong) UIImage            *imgDate4;
@property(nonatomic, assign) CGRect             rectDate4;

/** e.g. 08/12     @"/"  */
@property(nonatomic, strong) UIImage            *imgDateConnectionSymbol;
@property(nonatomic, assign) CGRect             rectDateConnectionSymbol;

/**
 *  Time e.g. 09:58
 */
@property (nonatomic,assign) BOOL               hasTime;

/** e.g. 09:58  From left to right, first digit  ,  @"0"  */
@property(nonatomic, strong) UIImage            *imgTime1;
@property(nonatomic, assign) CGRect             rectTime1;

/** e.g. 09:58  From left to right, the second digit  ,  @"9"  */
@property(nonatomic, strong) UIImage            *imgTime2;
@property(nonatomic, assign) CGRect             rectTime2;

/** e.g. 09:58  From left to right, the third digit ,   @"5"  */
@property(nonatomic, strong) UIImage            *imgTime3;
@property(nonatomic, assign) CGRect             rectTime3;

/** e.g. 09:58  From left to right, the fourth digit ,   @"8"  */
@property(nonatomic, strong) UIImage            *imgTime4;
@property(nonatomic, assign) CGRect             rectTime4;

/** e.g. 09:58     @":"  */
@property(nonatomic, strong) UIImage            *imgTimeConnectionSymbol;
@property(nonatomic, assign) CGRect             rectTimeConnectionSymbol;

/**
 *  Bluetooth Icon
 */
@property (nonatomic,assign) BOOL               hasIconBluetooth;
@property(nonatomic, strong) UIImage            *imgBluetooth;
@property(nonatomic, assign) CGRect             rectBluetooth;
/**
 *  Step Icon
 */
@property (nonatomic,assign) BOOL               hasIconStep;
@property(nonatomic, strong) UIImage            *imgIconStep;
@property(nonatomic, assign) CGRect             rectIconStep;
/**
 *  Step e.g. 12085  Numbers are right aligned
 */
@property (nonatomic,assign) BOOL               hasStep;

/** From left to right, first digit .   @"1" */
@property(nonatomic, strong) UIImage            *imgStep1;
@property(nonatomic, assign) CGRect             rectStep1;

/** From left to right, the second digit  .   @"2" */
@property(nonatomic, strong) UIImage            *imgStep2;
@property(nonatomic, assign) CGRect             rectStep2;

/** From left to right, the third digit .   @"0" */
@property(nonatomic, strong) UIImage            *imgStep3;
@property(nonatomic, assign) CGRect             rectStep3;

/** From left to right, the fourth digit.   @"8" */
@property(nonatomic, strong) UIImage            *imgStep4;
@property(nonatomic, assign) CGRect             rectStep4;

/** From left to right, the fifth digit .   @"5" */
@property(nonatomic, strong) UIImage            *imgStep5;
@property(nonatomic, assign) CGRect             rectStep5;

/**
 *  The progress bar of the number of steps has a total of 10 equal parts.
 */
@property (nonatomic,assign) BOOL               hasStepProgress;
@property(nonatomic, strong) UIImage            *imgStepProgress;
@property(nonatomic, assign) CGRect             rectStepProgress;
/**
 *  Week e.g. FRI
 */
@property (nonatomic,assign) BOOL               hasWeek;
@property(nonatomic, strong) UIImage            *imgWeek;
@property(nonatomic, assign) CGRect             rectWeek;

/**
 *  Heart Rate Icon
 */
@property (nonatomic,assign) BOOL               hasIconHRM;
@property(nonatomic, strong) UIImage            *imgIconHRM;
@property(nonatomic, assign) CGRect             rectIconHRM;
/**
 *  Heart Rate e.g. 120  Numbers are right aligned
 */
@property (nonatomic,assign) BOOL               hasHRM;

/** From left to right, first digit .   @"1" */
@property(nonatomic, strong) UIImage            *imgHRM1;
@property(nonatomic, assign) CGRect             rectHRM1;

/** From left to right, second digit .   @"2" */
@property(nonatomic, strong) UIImage            *imgHRM2;
@property(nonatomic, assign) CGRect             rectHRM2;

/** From left to right, third digit .   @"0" */
@property(nonatomic, strong) UIImage            *imgHRM3;
@property(nonatomic, assign) CGRect             rectHRM3;


@end

/*!
 *  UTEModelDialInfo
 */
@interface UTEModelDialInfor : NSObject
/**
    Dial index
*/
@property (nonatomic,assign) NSUInteger             index;
/**
    Dial width
*/
@property (nonatomic,assign) CGFloat                width;
/**
    Dial height
*/
@property (nonatomic,assign) CGFloat                height;
/**
    Bin file
*/
@property (nonatomic,strong) NSData                 *dataBin;
/**
    Background image
*/
@property(nonatomic, strong) UIImage                *bg;
/**
    Text Color
*/
@property(nonatomic, strong) UIColor                *textColor;
/**
    Image preview
*/
@property (nonatomic,strong) UIImage                *imagePreview;
/**
    Display Type. If 0, then it is undefined.
*/
@property (nonatomic,assign) UTEDisplayMode   type;
/**
    The corner radius of the preview image background
*/
@property (nonatomic,assign) CGFloat                radius;
/**
    What elements are there, and their coordinates, image.
*/
@property (nonatomic,strong) UTEModelDialElement     *status;

@end


/*!
 *  UTEModelSportGoal
 */
@interface UTEModelSportGoal : NSObject

//运动目标周期类型 Motion target cycle type
@property (nonatomic,assign) NSInteger                goalType;
//运动状态类型 Type of motion state
@property (nonatomic,assign) NSInteger                motionType;
//步数目标值，最小计步单位为1步 Target value of step count, with a minimum step count unit of 1 step
@property (nonatomic,assign) NSInteger                goalStep;
//卡路里目标值，单位：千卡 Calories target value, in kilocalories
@property (nonatomic,assign) NSInteger                goalCalorie;
//距离目标值，单位：米 Distance target value, in meters
@property (nonatomic,assign) NSInteger                goalDistance;
//时间目标值，单位：秒 Time target value, in seconds
@property (nonatomic,assign) NSInteger                goalDuration;

@end

/*!
 *  UTEModelPersonInfo
 */
@interface UTEModelPersonInfo : NSObject
//身高 单位：厘米 Height unit: centimeters
@property (nonatomic,assign) NSInteger                height;
//体重 单位：千克 Weight unit: kilogram
@property (nonatomic,assign) NSInteger                weight;
//年龄 age
@property (nonatomic,assign) NSInteger                age;
/** yyyy-MM-dd */
@property (nonatomic,copy  ) NSString                 *birthday;
//1:男性 2:女性 1: Male 2: Female
@property (nonatomic,assign) NSInteger                gender;
//走路时的步长，单位：厘米 Step length when walking, Unit: centimeters
@property (nonatomic,assign) NSInteger                walkStepLength;
//跑步时的步长，单位：厘米 Step length during running, Unit: centimeters
@property (nonatomic,assign) NSInteger                runStepLength;
//用户最近一次最大摄氧量值 The user's latest maximum oxygen uptake value
@property (nonatomic,assign) NSInteger                maximalOxygenUptake;
//最近一次最大摄氧量对应的时间戳 Time stamp corresponding to the latest maximum oxygen uptake
@property (nonatomic,assign) NSInteger                maximalOxygenUptakeTime;

@end

/*!
 *  UTEModelTodayDetail
 */
@interface UTEModelTodayDetail : NSObject
///运动状态类型 Type of motion state
@property (nonatomic,assign) UTEMotionType            motionType;
///运动步数 Exercise Steps
@property (nonatomic,assign) NSInteger                step;
///运动卡路里消耗值 单位：卡 Calories burned during exercise Unit: calories
@property (nonatomic,assign) NSInteger                kcal;
///运动距离 Movement distance
@property (nonatomic,assign) NSInteger                distance;
///睡眠时长 Sleep duration
@property (nonatomic,assign) NSInteger                sleepTime;
///高度差 Height difference
@property (nonatomic,assign) NSInteger                elevation;

@end

/*!
 *  UTEModelTodayHRM
 */
@interface UTEModelTodayHRM : NSObject
///心率测量时间戳，格林尼治时间，单位：秒 Heart rate measurement timestamp, Greenwich Mean Time,Unit: seconds
@property (nonatomic,assign) NSInteger                lastTime;
///心率测量值，单位：BPM Heart rate measurement value, Unit: BPM
@property (nonatomic,assign) NSInteger                rate;

@end


/*!
 *  UTEModelTodayStep
 */
@interface UTEModelTodayStep : NSObject
///当天总计运动卡路里消耗值 单位：卡 Total calorie consumption during daily exercise Unit: calories
@property (nonatomic,assign) NSInteger                totalCalorie;
///当天总计运动数据分类列表 Classification list of total exercise data for the day
@property (nonatomic,strong) NSMutableArray<UTEModelTodayDetail *> *motionData;
///当天最后一次心率测量结果 Last heart rate measurement of the day
@property (nonatomic,strong) UTEModelTodayHRM         *lastHeartRate;

@end

/*!
 *  UTEModelActivity
 */
@interface UTEModelActivity : NSObject
//true:开 false:关
@property (nonatomic,assign) BOOL                   enable;
/** 间隔时长 Unit: min */
@property (nonatomic,assign) NSInteger              interval;
/** 开始时间 HH-mm */
@property (nonatomic,copy  ) NSString               *startTime;
/** 结束时间 HH-mm */
@property (nonatomic,copy  ) NSString               *endTime;
///循环周期 Cycle Time
@property (nonatomic,assign) UTEWeekType            week;

@end

/*!
 *  UTEModelMotionFrameItemContent
 */
@interface UTEModelMotionFrameItemContent : NSObject
///步数 step number
@property (nonatomic,assign) NSInteger              step;
///卡路里 calorie
@property (nonatomic,assign) NSInteger              calorie;
///距离 distance
@property (nonatomic,assign) NSInteger              distance;
///高度 height
@property (nonatomic,assign) NSInteger              height;
///静态心率 Resting heart rate (defualt support) OR Static heart rate
@property (nonatomic,assign) NSInteger              restingHeartRate;
///动态心率 Dynamic heart rate
@property (nonatomic,assign) NSInteger              dynamicHeartRate;
///血氧 Blood oxygen
@property (nonatomic,assign) NSInteger              bloodOxygen;

@property (nonatomic,assign) BOOL                   isSupportHeartRateV2;
///静息心率(2.0方案) Resting heart rate (2.0 regimen)
@property (nonatomic,assign) NSInteger              restingHeartRateV2;

///心率最大值 Maximum heart rate
@property (nonatomic,assign) NSInteger              heartRateMax;
///心率最小值 Minimum heart rate
@property (nonatomic,assign) NSInteger              heartRateMin;
///心率平均值 Average heart rate
@property (nonatomic,assign) NSInteger              heartRateAve;

@property (nonatomic,assign) BOOL                   isSupportHeartRateV3;
///静息心率(3.0方案) Resting heart rate (3.0 regimen)
@property (nonatomic,assign) NSInteger              restingHeartRateV3;

/* 新增2024/03/21 需要判断是否支持健康拓展才有值
 To have value, it is necessary to determine whether it supports healthy expansion
 */
///收缩压 systolicPressure
@property (nonatomic,assign) NSInteger              systolicPressure;
///舒张压 diastolicPressure
@property (nonatomic,assign) NSInteger              diastolicPressure;
///情绪，1: 消极 2: 中性 3: 积极  Mood，1: Negative 2: Neutral 3: Positive
@property (nonatomic,assign) NSInteger              mood;
@end

/*!
 *  UTEModelMotionFrameItem
 */
@interface UTEModelMotionFrameItem : NSObject
///时间偏移量，单位：分钟 Time offset, in minutes
@property (nonatomic,assign) NSInteger              offset;
@property (nonatomic,copy  ) NSString               *time;//yyyy-MM-dd-HH-mm-ss
///列表项内容 List item content
@property (nonatomic,strong) UTEModelMotionFrameItemContent *content;

@end


/*!
 *  UTEModelMotionFrame
 */
@interface UTEModelMotionFrame : NSObject
///帧数据序号 Frame data sequence number
@property (nonatomic,assign) NSInteger              index;
///帧数据起始时间，格林尼治时间，单位：秒 Frame data start time, Greenwich Mean Time, in seconds
@property (nonatomic,assign) NSInteger              startTime;
@property (nonatomic,copy  ) NSString               *time;//yyyy-MM-dd-HH-mm-ss
///帧明细列表 Frame detail list
@property (nonatomic,strong) NSMutableArray<UTEModelMotionFrameItem *> *frameItemList;

@end


/*!
 *  UTEModelMotionFrameItemContent
 */
@interface UTEModelStatusFrameItem : NSObject

@property (nonatomic,assign) NSInteger              status;
@property (nonatomic,assign) NSInteger              startTime;
@property (nonatomic,assign) NSInteger              duration;

@end
/*!
 *  UTEModelStatusFrame
 */
@interface UTEModelStatusFrame : NSObject

@property (nonatomic,assign) NSInteger              index;
@property (nonatomic,strong) NSMutableArray<UTEModelStatusFrameItem *> *frameItemList;

@end


/*!
 *  UTEModelDesFrameDataList
 */
@interface UTEModelDesFrameDataList : NSObject

@property (nonatomic,assign) NSInteger              startTime;
@property (nonatomic,assign) NSInteger              endTime;
@property (nonatomic,assign) NSInteger              motionType;

@end
/*!
 *  UTEModelDesFrameData
 */
@interface UTEModelDesFrameData : NSObject

@property (nonatomic,assign) NSInteger              frameIndex;
@property (nonatomic,strong) NSMutableArray<UTEModelDesFrameDataList *> *stateDataList;

@end

/*!
 *  UTEModelClock
 */
@interface UTEModelClock : NSObject
///从1开始 Starting from 1
@property (nonatomic,assign) NSInteger              index;
///闹钟开关 true开启 false关闭 Alarm switch true:on false:off
@property (nonatomic,assign) BOOL                   enable;
///范围0 ~ 23 Range 0~23
@property (nonatomic,assign) NSInteger              timeHour;
///范围0 ~ 59 Range0~59
@property (nonatomic,assign) NSInteger              timeMin;
/*周期 cycle
循环说明：Loop description:
/// 0：不循环，仅执行一次 0: No loop, only execute once
/// 0B0000001:周一 Monday
/// 0B0000010:周二 Tuesday
/// 0B0000100:周三 Wednesday
/// 0B0001000:周四 Thursday
/// 0B0010000:周五 Friday
/// 0B0100000:周六 Saturday
/// 0B1000000:周日 Sunday
*/
@property (nonatomic,assign) UTEWeekType            cycle;
///标签 name
@property (nonatomic,copy  ) NSString               *name;

@end

/*!
 *  UTEModelHRMReal
 */
@interface UTEModelHRMReal : NSObject
///触发告警的心率值，单位：次/分钟 The heart rate value that triggers the alarm，Unit: times/minute
@property (nonatomic,assign) NSInteger              rate;
///心率告警时间，单位：秒 Heart rate alarm time，Unit: seconds
@property (nonatomic,assign) NSInteger              timestamp;

@end

/*!
 *  UTEModelWeatherHourForecast
 */
@interface UTEModelWeatherHourForecast : NSObject
//每小时的时间戳 Hourly timestamp
@property (nonatomic,assign) NSInteger              timestamp;
//每小时，天气现象 Every hour, weather phenomena
@property (nonatomic,assign) UTEWeather             phenomenon;
//每小时，温度， 单位：摄氏度 Hourly, temperature in degrees Celsius
@property (nonatomic,assign) NSInteger              temperature;

@end
/*!
 *  UTEModelWeatherWeekForecast
 */
@interface UTEModelWeatherWeekForecast : NSObject
///未来每天时间戳 Future Daily Timestamp
@property (nonatomic,assign) NSInteger              timestamp;
///每天天气现象 Daily weather phenomena
@property (nonatomic,assign) UTEWeather             phenomenon;
///最高气温 maximum temperature
@property (nonatomic,assign) NSInteger              highestTemperature;
///最低气温 minimum temperature
@property (nonatomic,assign) NSInteger              lowestTemperature;
///日出时间戳（可不填） Sunrise timestamp (optional)
@property (nonatomic,assign) NSInteger              sunriseTime;
///日落时间戳（可不填） Sunset timestamp (optional)
@property (nonatomic,assign) NSInteger              sunsetTime;
///月出时间戳（可不填） Monthly Time Stamp (optional)
@property (nonatomic,assign) NSInteger              moonRiseTime;
///月落时间戳（可不填） Monthly sunset timestamp (optional)
@property (nonatomic,assign) NSInteger              moonSetTime;
///设置月相（可不填） Set lunar phase (optional)
@property (nonatomic,assign) NSInteger              moonPhase;

@end

/*!
 *  UTEModelWeatherToday
 */
@interface UTEModelWeatherToday : NSObject
///天气数据的发布时间戳 Timestamp for publishing weather data
@property (nonatomic,assign) NSInteger              timestamp;
///天气现象 weather phenomenon
@property (nonatomic,assign) UTEWeather             phenomenon;
///城市名称 City name
@property (nonatomic,copy  ) NSString               *cityName;
///数据源 data source
@property (nonatomic,copy  ) NSString               *publishSource;
///当前实时温度，单位：摄氏度 Current real-time temperature，Unit: Celsius
@property (nonatomic,assign) NSInteger              currentTemperature;
///当天最高温度，单位：摄氏度 The highest temperature of the day，Unit: Celsius
@property (nonatomic,assign) NSInteger              highest;
///当天最低温度，单位：摄氏度 The lowest temperature of the day，Unit: Celsius
@property (nonatomic,assign) NSInteger              lowest;
///风力 wind power
@property (nonatomic,assign) NSInteger              wind;
///天气数据的发布时间戳 2个都要写 Both weather data release timestamps need to be written
@property (nonatomic,assign) NSInteger              publishTime;
///AQI 指数。AQI 为无效值时，推送默认值 -1 AQI index. When AQI is an invalid value, push the default value of -1
@property (nonatomic,assign) NSInteger              aqi;
///当前地区空气中的 pm2.5 颗粒物，单位：微克/立方米 PM2.5 particulate matter in the air of the current region, unit: micrograms/cubic meter
@property (nonatomic,assign) NSInteger              pm25;
//0:摄氏度 1:华氏度 0: Celsius 1: Fahrenheit
@property (nonatomic,assign) NSInteger              unit;

//紫外线 0 ~ 100 UV 0~100
@property (nonatomic,copy  ) NSString              *uv;
//湿度 0 ~ 100% Humidity 0~100%
@property (nonatomic,copy  ) NSString              *humidity;

@end


/*!
 *  UTEModelHRMRemindItem
 */
@interface UTEModelHRMRemindItem : NSObject
///心率告警开始时间，单位：秒 Heart rate alarm start time, unit: seconds
@property (nonatomic,assign) NSInteger              startTime;
///心率告警结束时间，单位：秒 End time of heart rate alarm, unit: seconds
@property (nonatomic,assign) NSInteger              endTime;
///触发告警的最小心率值，单位：次/分钟 The minimum heart rate value that triggers an alarm, Unit: times/minute
@property (nonatomic,assign) NSInteger              minHeartRate;
///触发告警的最大心率值，单位：次/分钟 The maximum heart rate value that triggers the alarm,Unit: times/minute
@property (nonatomic,assign) NSInteger              maxHeartRate;
///设置的心率告警值，单位：次/分钟 Set heart rate alarm value，Unit: times/minute
@property (nonatomic,assign) NSInteger              warningLimit;
///告警详细数据列表 Alarm detailed data list
@property (nonatomic,strong) NSMutableArray<UTEModelHRMReal *> *itemList;

@end

/*!
 *  UTEModelHRMRemind
 */
@interface UTEModelHRMRemind : NSObject
///0:心率升高 1:心率降低 0: Increased heart rate 1: Reduced heart rate
@property (nonatomic,assign) NSInteger              eventType;
///心率告警数据列表 Heart rate alarm data list
@property (nonatomic,strong) NSMutableArray<UTEModelHRMRemindItem *> *eventList;

@end

/*!
 *  UTEModelHRMZone
 */
@interface UTEModelHRMZone : NSObject
///warmUpRate 热身下限值
@property (nonatomic,assign) NSInteger              warmUpRate;
///fatBurnRate燃脂下限值
@property (nonatomic,assign) NSInteger              fatBurnRate;
///aerobicRate有氧耐力下限值
@property (nonatomic,assign) NSInteger              aerobicRate;
///anaerobicRate无氧耐力下限值
@property (nonatomic,assign) NSInteger              anaerobicRate;
///limitRate极限下限值
@property (nonatomic,assign) NSInteger              limitRate;
///maximumRate极限上限值
@property (nonatomic,assign) NSInteger              maximumRate;
///rateWarnSwitch心率告警开关
@property (nonatomic,assign) BOOL                   rateWarnSwitch;
///rateWarnMaxRate心率告警值
@property (nonatomic,assign) NSInteger              rateWarnMaxRate;
///heartRateType 心率类型 0: Maximum heart rate 1: Reserve heart rate 2: Lactate threshold heart rate 0:最大心率 1:储备心率 2:乳酸阈心率
@property (nonatomic,assign) NSInteger              heartRateType;
///maxHeartRate最大心率值
@property (nonatomic,assign) NSInteger              maxHeartRate;
///restHeartRate静息心率
@property (nonatomic,assign) NSInteger              restHeartRate;
///aerobicBase有氧基础下限值
@property (nonatomic,assign) NSInteger              aerobicBase;
///aerobicAdvance有氧进阶下限值
@property (nonatomic,assign) NSInteger              aerobicAdvance;
///lacticAcid乳酸阈值下限值
@property (nonatomic,assign) NSInteger              lacticAcid;
///anaerobicBase无氧基础下限值
@property (nonatomic,assign) NSInteger              anaerobicBase;
///anaerobicAdvance无氧进阶下限值
@property (nonatomic,assign) NSInteger              anaerobicAdvance;

@end

/*!
 *  UTEModelPaceZoneConfig
 */
@interface UTEModelPaceZoneConfig : NSObject

@property (nonatomic,assign) NSInteger              easyRunPace;
@property (nonatomic,assign) NSInteger              marathonPace;
@property (nonatomic,assign) NSInteger              lacticAcidPace;
@property (nonatomic,assign) NSInteger              anaerobicEndurancePace;
@property (nonatomic,assign) NSInteger              highIntensityPace;
@property (nonatomic,assign) NSInteger              upperHighIntensityPace;

@end



/*!
 *  UTEModelDeviceTargetInfo
 */
@interface UTEModelDeviceTargetInfo : NSObject
///运动目标为距离，单位：米 没有目标值也要写0 The motion target is distance, in meters. If there is no target value, write 0
@property (nonatomic,assign) NSInteger              distance;
///运动目标为卡路里，单位：卡 没有目标值也要写0 The exercise target is calories, unit: card. If there is no target value, write 0
@property (nonatomic,assign) NSInteger              calorie;
///运动目标为时间，单位：秒 没有目标值也要写0 The motion target is time, in seconds. If there is no target value, write 0
@property (nonatomic,assign) NSInteger              duration;

@end
/*!
 *  UTEModelDeviceOperator
 */
@interface UTEModelDeviceOperator : NSObject
///执行状态 Execution Status
@property (nonatomic,assign) UTESportOperatorType   operatorType;
///运动分类 Motion classification
@property (nonatomic,assign) UTESportType           sportType;
///跑步计划起始时间戳(必须) Start timestamp of running plan (required)
@property (nonatomic,assign) NSInteger              planStartDate;
///运动类型 Motion type
@property (nonatomic,assign) EnumRYSDKSportType     workoutType;
///当前操作运动开始时间戳(同上时间戳就可以) The start timestamp of the current operation motion (the same timestamp is sufficient)
@property (nonatomic,assign) NSInteger              operationTime;
///联动版本号 目前固定值1 The linkage version number is currently fixed at 1
@property (nonatomic,assign) NSInteger              version;
///当前运动开始时间戳(同上时间戳就可以) Current motion start timestamp (the same timestamp is sufficient)
@property (nonatomic,assign) NSInteger              startTime;
///跑步课程版本号 目前固定值0 The running course version number is currently fixed at 0
@property (nonatomic,assign) NSInteger              runCourseVersion;
///是否允许手表控制手机暂停 1允许 0不允许 Is it allowed for the watch to control the phone to pause? 1 is allowed, 0 is not allowed
@property (nonatomic,assign) NSInteger              forbidPause;
///运动目标 Moving Target
@property (nonatomic,strong) UTEModelDeviceTargetInfo *targetInfo;

@end


/*!
 *  UTEModelDeviceOperatorState
 */
@interface UTEModelDeviceOperatorState : NSObject
///运动监测占用状态 0空闲无运动状态 1正在运动无法发起新运动，需要关闭手环当前运动才可以发起新运动 Sports monitoring occupancy status. 0:idle no movement status. 1:in motion unable to initiate new movements. The wristband needs to be closed for current movement in order to initiate new movements
@property (nonatomic,assign) NSInteger              monitorState;
///执行状态 Execution Status
@property (nonatomic,assign) UTESportOperatorType   operatorType;
///运动分类 Motion classification
@property (nonatomic,assign) UTESportType           sportType;
///跑步计划起始时间戳 Start timestamp of running plan
@property (nonatomic,assign) NSInteger              planStartDate;
///运动类型 Motion type
@property (nonatomic,assign) EnumRYSDKSportType     workoutType;

@end

/*!
 *  UTEModelDeviceSportOneRecord
 */
@interface UTEModelDeviceSportOneRecord : NSObject
///运动记录 ID Sports record ID
@property (nonatomic,assign) NSInteger              recordId;
///单次运动状态, 1:完成 2:未完成(固件不支持) Single exercise status, 1: Completed 2: Unfinished (firmware not supported)
@property (nonatomic,assign) NSInteger              status;
///起始时间 starting time
@property (nonatomic,assign) NSInteger              startTime;
///结束时间 End Time
@property (nonatomic,assign) NSInteger              endTime;
///卡路里，单位：千卡 calorie Unit: kcal
@property (nonatomic,assign) NSInteger              calorie;
///距离，单位：米 distance Unit: meters
@property (nonatomic,assign) NSInteger              distance;
///步数（踏数、桨数、跳绳数复用） Step count (reuse of steps, paddles, and rope skipping)
@property (nonatomic,assign) NSInteger              step;
///总时长，单位：秒 Total duration Unit: seconds
@property (nonatomic,assign) NSInteger              totalTime;
///平均速度，单位：dm/s Average speed, unit: dm/s
@property (nonatomic,assign) NSInteger              speed;
///累计爬高高度：单位（分米） Climbing height difference: units (decimeters)
@property (nonatomic,assign) NSInteger              climb;
///心率最小值 Minimum heart rate
@property (nonatomic,assign) NSInteger              hrABSMinPeak;
///心率最大值 Maximum heart rate
@property (nonatomic,assign) NSInteger              hrABSMaxPeak;
///运动负荷 Exercise load
@property (nonatomic,assign) NSInteger              loadPeak;
///运动效果 Motion Effects
@property (nonatomic,assign) NSInteger              trainingEffect;
///最大耗氧量 Maximum oxygen consumption
@property (nonatomic,assign) NSInteger              oxygenConsumption;
///MET
@property (nonatomic,assign) NSInteger              oxygenUptake;
///完全恢复时长 Total recovery time
@property (nonatomic,assign) NSInteger              recoveryTime;
///活动时间：秒 Activity time: seconds
@property (nonatomic,assign) NSInteger              duration;
///运动类型 参考EnumRYSDKSportType注释 Sports type reference EnumRYSDK SportType annotation
@property (nonatomic,assign) NSInteger              workoutType;
///泳姿 1: 蛙泳 2: 自由泳 3: 蝶泳 4: 仰泳 5: 混合泳 Swimming posture 1: breaststroke 2: freestyle 3: butterfly 4: backstroke 5: medley
@property (nonatomic,assign) NSInteger              swimType;
///划水次数 Number of strokes
@property (nonatomic,assign) NSInteger              swimPullTimes;
///均划水频率：次/分钟 Average water frequency: times/minute
@property (nonatomic,assign) NSInteger              swimPullRate;
///泳池游泳：泳池长度（厘米） Swimming in the pool: Pool length (centimeters)
@property (nonatomic,assign) NSInteger              swimPoolLength;
///泳池游泳趟数,滑雪趟数（复用）Number of swimming and skiing trips in the swimming pool (reuse)
@property (nonatomic,assign) NSInteger              tripTimes;
///单趟泳池长度所需时间 （以秒为单位） The time required for a single swimming pool length (in seconds)
@property (nonatomic,assign) NSInteger              swimAverageSwolf;
///累计下降高度，单位分米 Accumulated descent height, Unit: Decimeter
@property (nonatomic,assign) NSInteger              totalDropHeight;
///最高海拔，单位分米 Maximum altitude, Unit: Decimeter
@property (nonatomic,assign) NSInteger              highestAltitude;
///最低海拔，单位分米 the lowest altitude, Unit: Decimeter
@property (nonatomic,assign) NSInteger              lowestAltitude;
///基于公里距离计算单位分米 Calculation based on kilometer distance, Unit: Decimeter
@property (nonatomic,assign) NSInteger              swolfBaseKilometerSwolf;
///基于英里距离计算，单位分米 Based on mile distance calculation , Unit: Decimeter
@property (nonatomic,assign) NSInteger              swolfBaseMileSwolf;
///无氧运动效果 Effects of anaerobic exercise
@property (nonatomic,assign) NSInteger              anaerobicSportsEffect;
///半马用时：秒 Half Horse Time,unit:second
@property (nonatomic,assign) NSInteger              halfMarathonTime;
///全马用时：秒 Whole horse time,unit:second
@property (nonatomic,assign) NSInteger              totalMarathonTime;
///运动记录类型，flag∈[0,5]，1byte Sports record type
@property (nonatomic,assign) NSInteger              recordFlag;
///0：最大心率方式 1：储备心率方式 2：乳酸阈心率方式 0: Maximum heart rate mode 1: Reserve heart rate mode 2: Lactate threshold heart rate mode
@property (nonatomic,assign) NSInteger              heartRateType;
///跑步课程 id，2byte; Running course id
@property (nonatomic,assign) NSInteger              courseId;
///活跃时长，有效的运动时长，单位：秒2byte; Active duration, effective exercise duration, Unit: seconds
@property (nonatomic,assign) NSInteger              activeTime;
///跳跃次数 单位：次2byte; hop count,Unit: Times
@property (nonatomic,assign) NSInteger              jumpTimes;
///最大跳跃高度 单位：厘米（cm）1byte; Maximum jumping height,Unit: centimeters
@property (nonatomic,assign) NSInteger              jumpHeight;
///最大腾空时间 单位：毫秒（ms）2byte; Maximum clearance time,Unit: milliseconds
@property (nonatomic,assign) NSInteger              maxJumpTime;
///最大冲刺速度 单位：分米每秒1byte; Maximum Sprint Speed,Unit: decimeters per second
@property (nonatomic,assign) NSInteger              maxRunSpeed;
///跑动得分，范围[0,100],1byte; Running score, range [0100]
@property (nonatomic,assign) NSInteger              runScore;
///突破移动得分，范围[0,100]1byte; Breakthrough movement score, range [0100]
@property (nonatomic,assign) NSInteger              moveScore;
///弹跳滞空得分，范围[0,100]1byte; Bounce hovering score, range [0100]
@property (nonatomic,assign) NSInteger              jumpScore;
///综合评分，范围[0,100]1byte; Comprehensive score, range [0100]
@property (nonatomic,assign) NSInteger              totalScore;
///最大加速度评分，范围[0,100]1byte; Maximum acceleration score, range [0100]
@property (nonatomic,assign) NSInteger              maxAccelerationScore;
///下肢力量评分范围，[0,100]，1byte; Lower limb strength score range, [0100]
@property (nonatomic,assign) NSInteger              lowerExtremityStrengthScore;
///最高血氧，百分比1byte; Maximum blood oxygen, percentage
@property (nonatomic,assign) NSInteger              highestBloodOxygen;
///最低血氧，百分比1byte; Minimum blood oxygen, percentage 1
@property (nonatomic,assign) NSInteger              lowestBloodOxygen;
///高尔夫：总挥杆数2byte; Golf: Total number of swings
@property (nonatomic,assign) NSInteger              golfSwingCount;
///高尔夫：平均上杆时间 单位： 毫秒（ms）1byte; Golf: Average Uptime Unit: milliseconds
@property (nonatomic,assign) NSInteger              golfAvgBackSwingTime;
///高尔夫：平均下杆时间 单位： 毫秒（ms）1byte; Golf: Average Downtime Unit: milliseconds
@property (nonatomic,assign) NSInteger              golfAvgDownSwingTime;
/// 高尔夫：平均挥杆速度 单位：厘米/秒2byte; Golf: Average swing speed Unit: centimeters/second
@property (nonatomic,assign) NSInteger              golfAvgSwingSpeed;
/// 高尔夫：最大挥杆速度 单位：厘米/秒2byte; Golf: Maximum swing speed，Unit: centimeters/second
@property (nonatomic,assign) NSInteger              golfMaxSwingSpeed;
///高尔夫：平均挥杆节奏，2byte; Golf: Average swing rhythm
@property (nonatomic,assign) NSInteger              golfTempo;
/// 滑雪：最大坡度 单位：度（0.1°）2byte; Skiing: Maximum Slope Unit: Degrees (0.1 °)
@property (nonatomic,assign) NSInteger              skiMaxSlopeDegree;
/// 滑雪：最大坡度2byte; Skiing: maximum slope
@property (nonatomic,assign) NSInteger              skiMaxSlopePercent;
///滑雪： 滑行时间 单位：秒2byte; Skiing: sliding time unit: seconds
@property (nonatomic,assign) NSInteger              skiTotalTime;
/// 滑雪： 滑行距离 单位： 厘米2byte; Skiing: gliding distance，Unit: centimeters
@property (nonatomic,assign) NSInteger              skiTotalDistance;
/// 运动开始时温度 单位：摄氏度2byte;  Temperature at the beginning of exercise ，Unit: Celsius
@property (nonatomic,assign) NSInteger              temperature;
/// 运动开始时天气（类型）,1byte; Weather at the beginning of the exercise (type)
@property (nonatomic,assign) NSInteger              weather;
/// 总踏圈数2byte; Total number of treads
@property (nonatomic,assign) NSInteger              circleNumber;
/// 最大踏频1byte; Maximum step frequency
@property (nonatomic,assign) NSInteger              maxCadence;
/// 平均踏频1byte; Average step frequency
@property (nonatomic,assign) NSInteger              avgCadence;
/// 目标完成度,单位：百分比1byte; Goal completion rate，Unit: percentage
@property (nonatomic,assign) NSInteger              targetPercent;
/// 0:无目标 1:距离目标 2:时间目标 3:卡路里目标 4:游泳趟数目标 5:半马 6:全马 7:健身目标，1byte; 0: No Goal 1: Distance Goal 2: Time Goal 3: Calories Goal 4: Swimming Trip Goal 5: Half Horse 6: All Horse 7: Fitness Goal
@property (nonatomic,assign) NSInteger              targetPercentType;
///算法类型，[0,1] Algorithm type, [0,1]
@property (nonatomic,assign) NSInteger              algType;
///跳绳最多连跳次数 Maximum number of consecutive jumps on jump rope
@property (nonatomic,assign) NSInteger              longestStreak;
///跳绳绊绳次数 Jumping rope and tripping rope times
@property (nonatomic,assign) NSInteger              trippedCount;
///脂肪消耗，单位：千卡 fat consumption，Unit: kcal
@property (nonatomic,assign) NSInteger              fatConsumption;
///脂肪占比，[0-100] Fat percentage, [0-100]
@property (nonatomic,assign) NSInteger              fatPercentage;
///脂肪估算重量，单位：mg Estimated weight of fat，Unit: mg
@property (nonatomic,assign) NSInteger              fatWeight;
///体能年龄 Physical age
@property (nonatomic,assign) NSInteger              fitnessAge;
///运动记录结构体列表，不涉及，忽略; List of motion recording structures, not involved, ignored;
@property (nonatomic,assign) NSInteger              motionRelationList;
///平均配速,单位：s/km ，2byte; AVERAGE PACE ，Unit: s/km
@property (nonatomic,assign) NSInteger              avgPace;
/// 平均步频（划船机桨频复用），单位:次/分 2byte; Average step frequency (rowing machine blade frequency reuse)，Unit: times/minute
@property (nonatomic,assign) NSInteger              stepFrequency;
/// 平均步幅，单位：cm  2byte; Average stride，Unit: cm
@property (nonatomic,assign) NSInteger              avgStride;
/// 拉浆时间 单位：秒 2byte; Slurry pulling time，Unit: seconds
@property (nonatomic,assign) NSInteger              pullTime;
/// 收桨时间 单位：秒 2byte; Harvest time，Unit: seconds
@property (nonatomic,assign) NSInteger              freeTime;
/// 上楼层数 2byte; Number of upper floors
@property (nonatomic,assign) NSInteger              floorsUp;
/// 下楼层数 2byte; Number of floors downstairs
@property (nonatomic,assign) NSInteger              floorsDown;



@end

/*!
 *  UTEModelDeviceSportRealData
 */
@interface UTEModelDeviceSportRealData : NSObject

@property (nonatomic,assign) NSInteger              duration;
@property (nonatomic,assign) NSInteger              heartRate;
@property (nonatomic,assign) NSInteger              heartRateZone;
@property (nonatomic,assign) NSInteger              step;///（步数、桨次、跳绳数复用）
@property (nonatomic,assign) NSInteger              cadence;
@property (nonatomic,assign) NSInteger              pace;
@property (nonatomic,assign) NSInteger              distance;
@property (nonatomic,assign) NSInteger              calorie;
@property (nonatomic,assign) NSInteger              totalRise; //累计爬升,单位: dm，2byte
@property (nonatomic,assign) NSInteger              totalDescend;//累计下降,单位: dm，2byte
@property (nonatomic,assign) NSInteger              altitude;//高度 单位:dm 2byte
@property (nonatomic,assign) NSInteger              aerobicEffect;
@property (nonatomic,assign) NSInteger              anaerobicEffect;
@property (nonatomic,assign) NSInteger              performanceCondition;
@property (nonatomic,assign) NSInteger              timeInfo;
@property (nonatomic,assign) NSInteger              operatorType;
@property (nonatomic,assign) NSInteger              recoveryTime;
@property (nonatomic,assign) NSInteger              oxygenUptake;
@property (nonatomic,assign) NSInteger              eteType;
@property (nonatomic,assign) NSInteger              jumpRopeFrequency;
@property (nonatomic,assign) NSInteger              fatBurnRate;
@property (nonatomic,assign) NSInteger              fatGlycogen;
@property (nonatomic,assign) NSInteger              fatPercent;
@property (nonatomic,assign) NSInteger              fatCalorie;
@property (nonatomic,assign) NSInteger              avgPace;
///新增
@property (nonatomic,assign) NSInteger              stride;//26步幅，单位：cm  2byte
@property (nonatomic,assign) NSInteger              tripTimes;//27泳池游泳趟数,滑雪趟数（复用）1byte
@property (nonatomic,assign) NSInteger              swimPullTimes;//28划水次数，2byte
@property (nonatomic,assign) NSInteger              swimPullRate;//29划水频率，1byte
@property (nonatomic,assign) NSInteger              swimType;//30泳姿1: 蛙泳 2: 自由泳 3: 蝶泳 4: 仰泳 5: 混合泳，1byte
@property (nonatomic,assign) NSInteger              swimSwolf;//31单趟泳池长度所需时间 （以秒为单位）2byte
@property (nonatomic,assign) NSInteger              pullTime;//32拉浆时间 单位：秒 2byte
@property (nonatomic,assign) NSInteger              freeTime;//33收桨时间 单位：秒 2byte
@property (nonatomic,assign) NSInteger              tripped;//34绊绳次数 2byte
@property (nonatomic,assign) NSInteger              maxRopeCombo;//35最大连跳 2byte
@property (nonatomic,assign) NSInteger              CurrRopeCombo;//36当前连跳 2byte
@property (nonatomic,assign) NSInteger              floorsUp;//37上楼层数 2byte
@property (nonatomic,assign) NSInteger              floorsDown;//38下楼层数 2byte


@end

/*!
 *  UTEModelDeviceWorkoutAbility
 */
@interface UTEModelDeviceWorkoutAbility : NSObject

@property (nonatomic,assign) BOOL              treadmill;

@end

/*!
 *  UTEModeSportRecordItem
 */
@interface UTEModeSportRecordItem : NSObject
///运动记录ID Sports record ID
@property (nonatomic,assign) NSInteger              ID;
///运动索引条数 Number of motion index entries
@property (nonatomic,assign) NSInteger              index;
///配速信息索引条数 Number of speed information indexes
@property (nonatomic,assign) NSInteger              paceIndex;
///分段信息索引条 Segmented information index bar
@property (nonatomic,assign) NSInteger              sectionIndex;
///血氧信息索引条数 Number of blood oxygen index entries
@property (nonatomic,assign) NSInteger              bloodOxygen;
///通用运动分段条数 Number of general motion segments
@property (nonatomic,assign) NSInteger              number;

@end
/*!
 *  UTEModeSportRecord
 */
@interface UTEModeSportRecord : NSObject
///运动记录条数 Number of exercise records
@property (nonatomic,assign) NSInteger              count;
///运动记录列表 Sports Record List
@property (nonatomic,strong) NSMutableArray<UTEModeSportRecordItem *>  *recordItemList;

@end


/*!
 *  UTEModeSportRecordSummaryRelation
 */
@interface UTEModeSportRecordSummaryRelation : NSObject

@property (nonatomic,assign) NSInteger              workoutType;
@property (nonatomic,assign) NSInteger              detailType;
@property (nonatomic,assign) NSInteger              detailStartTime;
@property (nonatomic,assign) NSInteger              detailEndTime;
@property (nonatomic,assign) NSInteger              detailTotalTime;
@property (nonatomic,assign) NSInteger              detailDistance;
@property (nonatomic,assign) NSInteger              detailCalorie;
@property (nonatomic,assign) NSInteger              transitionTime;
@property (nonatomic,assign) NSInteger              hasDetail;

@end
/*!
 *  UTEModeSportRecordSummary
 */
@interface UTEModeSportRecordSummary : NSObject
///运动记录idSports record ID
@property (nonatomic,assign) NSInteger              ID;
///单次运动状态, 1:完成 2:未完成 Single exercise state, 1: completed 2: incomplete
@property (nonatomic,assign) NSInteger              status;
///起始时间 starting time
@property (nonatomic,assign) NSInteger              startTime;
///结束时间 End Time
@property (nonatomic,assign) NSInteger              endTime;
///卡路里，单位：千卡 Calories, in kilocalories
@property (nonatomic,assign) NSInteger              calorie;
///距离，单位：米 Distance in meters
@property (nonatomic,assign) NSInteger              distance;
///步数（踏数、桨数） Steps (steps, paddles)
@property (nonatomic,assign) NSInteger              step;
///总时长，单位：秒 Total duration, in seconds
@property (nonatomic,assign) NSInteger              totalTime;
///平均速度，单位：dm/s（分米/秒）Average speed, unit: dm/s (decimeters per second)
@property (nonatomic,assign) NSInteger              speed;
///累计爬升高度：单位：分米 Accumulated Climb Altitude: Unit: Decimeters
@property (nonatomic,assign) NSInteger              totalRiseHeight;
///心率最大值 Maximum heart rate
@property (nonatomic,assign) NSInteger              hrABSMaxPeak;
///心率最小值 Minimum heart rate
@property (nonatomic,assign) NSInteger              hrABSMinPeak;
///运动负荷 Exercise load
@property (nonatomic,assign) NSInteger              sportsLoad;
///运动效果（有氧压力）Exercise effect (aerobic pressure)
@property (nonatomic,assign) NSInteger              sportsEffect;
///最大耗氧量 Maximum oxygen consumption
@property (nonatomic,assign) NSInteger              epoc;
///MET （最大摄氧量 = xx * 3.5/65536）(Maximum oxygen uptake=xx * 3.5/65536)
@property (nonatomic,assign) NSInteger              maxMET;
///完全恢复时长（单位分钟，app 展示小时）Total recovery time (in minutes, displayed on the app in hours)
@property (nonatomic,assign) NSInteger              recoveryTime;
///活动时间：秒 Activity time: seconds
@property (nonatomic,assign) NSInteger              sportTime;
///单次运动类型 Single motion type
@property (nonatomic,assign) NSInteger              type;
///1: 蛙泳 2: 自由泳 3: 蝶泳 4: 仰泳 5: 混合泳 1: Breaststroke 2: Freestyle 3: Butterfly 4: Backstroke 5: Medley
@property (nonatomic,assign) NSInteger              swimType;
///划水次数 Number of strokes
@property (nonatomic,assign) NSInteger              swimPullTimes;
///平均划水频率：次/分钟 Average stroke frequency: times/minute
@property (nonatomic,assign) NSInteger              swimPullRate;
///泳池游泳：泳池长度（厘米）Swimming in the pool: Pool length (centimeters)
@property (nonatomic,assign) NSInteger              swimPoolLength;
///泳池游泳趟数,滑雪趟数（复用） Number of swimming and skiing trips in the swimming pool (reuse)
@property (nonatomic,assign) NSInteger              tripTimes;
///单趟泳池长度所需时间 （以秒为单位）The time required for a single swimming pool length (in seconds)
@property (nonatomic,assign) NSInteger              swimAverageSwolf;
///累计下降高度，单位分米 Accumulated descent height in decimeters
@property (nonatomic,assign) NSInteger              totalDropHeight;
///最高海拔，单位分米 The highest altitude, in decimeters
@property (nonatomic,assign) NSInteger              highestAltitude;
///最低海拔，单位分米 The lowest altitude, in decimeters
@property (nonatomic,assign) NSInteger              lowestAltitude;
///Swolf 基于公里距离计算，单位分米 Swolf is calculated based on kilometer distance in decimeters
@property (nonatomic,assign) NSInteger              swolfBaseKilometer;
///Swolf 基于英里距离计算，单位分米 Swolf is calculated based on miles, in decimeters
@property (nonatomic,assign) NSInteger              swolfBaseMile;
///无氧运动效果 Effects of anaerobic exercise
@property (nonatomic,assign) NSInteger              anaerobicSportsEffect;
///半马用时：秒 Half horse time: seconds
@property (nonatomic,assign) NSInteger              halfMarathonTime;
///全马用时：秒 Whole horse time: seconds
@property (nonatomic,assign) NSInteger              totalMarathonTime;
///运动记录类型 Sports record type
@property (nonatomic,assign) NSInteger              recordFlag;
///0：最大心率方式 1：储备心率方式 2：乳酸阈心率方式 0: Maximum heart rate mode 1: Reserve heart rate mode 2: Lactate threshold heart rate mode
@property (nonatomic,assign) NSInteger              heartRateType;
///跑步课程 id Running course ID
@property (nonatomic,assign) NSInteger              courseId;
///活跃时长 Active duration
@property (nonatomic,assign) NSInteger              activityTime;
///跳跃次数 单位：次 Jump count unit: times
@property (nonatomic,assign) NSInteger              jumpTimes;
///最大跳跃高度 单位：厘米（cm） Maximum jumping height unit: centimeters (cm)
@property (nonatomic,assign) NSInteger              jumpHeight;
///最大腾空时间 单位：毫秒（ms） Maximum airborne time unit: milliseconds (ms)
@property (nonatomic,assign) NSInteger              maxJumpTime;
///最大冲刺速度 单位：分米每秒 Maximum sprint speed unit: decimeters per second
@property (nonatomic,assign) NSInteger              maxRunSpeed;
///跑动得分，范围[0,100] Running score, range [0100]
@property (nonatomic,assign) NSInteger              runScore;
///突破移动得分，范围[0,100] Breakthrough movement score, range [0100]
@property (nonatomic,assign) NSInteger              moveScore;
///弹跳滞空得分，范围[0,100] Bounce hovering score, range [0100]
@property (nonatomic,assign) NSInteger              jumpScore;
///综合评分，范围[0,100] Comprehensive score, range [0100]
@property (nonatomic,assign) NSInteger              totalScore;
///最大加速度评分，范围[0,100] Maximum acceleration score, range [0100]
@property (nonatomic,assign) NSInteger              maxAccelerationScore;
///下肢力量评分，范围[0,100] Lower limb strength score, range [0100]
@property (nonatomic,assign) NSInteger              lowerExtremityStrengthScore;
///最高血氧，百分比 Maximum blood oxygen, percentage
@property (nonatomic,assign) NSInteger              highestBloodOxygen;
///最低血氧，百分比 Minimum blood oxygen, percentage
@property (nonatomic,assign) NSInteger              lowestBloodOxygen;
///高尔夫：总挥杆数 Golf: Total number of swings
@property (nonatomic,assign) NSInteger              golfSwingCount;
///高尔夫：平均上杆时间 单位： 毫秒（ms） Golf: Average golf time in milliseconds (ms)
@property (nonatomic,assign) NSInteger              golfAvgBackSwingTime;
///高尔夫：平均下杆时间 单位： 毫秒（ms） Golf: Average down time in milliseconds (ms)
@property (nonatomic,assign) NSInteger              golfAvgDownSwingTime;
///高尔夫：平均挥杆速度 单位：厘米/秒 Golf: Average swing speed in centimeters per second
@property (nonatomic,assign) NSInteger              golfAvgSwingSpeed;
///高尔夫：最大挥杆速度 单位：厘米/秒 Golf: Maximum swing speed in centimeters per second
@property (nonatomic,assign) NSInteger              golfMaxSwingSpeed;
///高尔夫：平均挥杆节奏 Golf: Average swing rhythm
@property (nonatomic,assign) NSInteger              golfTempo;
///滑雪：最大坡度 单位：度（0.1°） Skiing: Maximum Slope Unit: Degrees (0.1 °)
@property (nonatomic,assign) NSInteger              skiMaxSlopeDegree;
///滑雪：最大坡度 Skiing: maximum slope
@property (nonatomic,assign) NSInteger              skiMaxSlopePercent;
///滑雪： 滑行时间 单位：秒 Skiing: sliding time unit: seconds
@property (nonatomic,assign) NSInteger              skiTotalTime;
///滑雪： 滑行距离 单位： 厘米 Skiing: sliding distance in centimeters
@property (nonatomic,assign) NSInteger              skiTotalDistance;
///运动开始时温度 单位：摄氏度 Temperature unit at the beginning of exercise: Celsius
@property (nonatomic,assign) NSInteger              temperature;
///运动开始时天气 Weather at the beginning of the exercise
@property (nonatomic,assign) NSInteger              weather;
///总踏圈数 Total number of treads
@property (nonatomic,assign) NSInteger              circleNumber;
///最大踏频 Maximum step frequency
@property (nonatomic,assign) NSInteger              maxCadence;
///平均踏频 Average step frequency
@property (nonatomic,assign) NSInteger              avgCadence;
///目标完成度,单位：百分比 Target completion rate, in percentage
@property (nonatomic,assign) NSInteger              targetPercent;
///0:无目标 1:距离目标 2:时间目标 3:卡路里目标 4:游泳趟数目标 5:半马 6:全马 7:健身目标 0: No Goal 1: Distance Goal 2: Time Goal 3: Calories Goal 4: Swimming Trip Goal 5: Half Horse 6: All Horse 7: Fitness Goal
@property (nonatomic,assign) NSInteger              targetPercentType;
///跳绳最多连跳次数 Maximum number of consecutive jumps on jump rope
@property (nonatomic,assign) NSInteger              longestStreak;
///跳绳绊绳次数 Jumping rope and tripping rope times
@property (nonatomic,assign) NSInteger              tripped;
///ete 算法类型 Algorithm type
@property (nonatomic,assign) NSInteger              algType;
///脂肪消耗，单位：千卡 Fat consumption, in kilocalories
@property (nonatomic,assign) NSInteger              fatConsumption;
///脂肪占比，[0-100] Fat percentage, [0-100]
@property (nonatomic,assign) NSInteger              fatPercentage;
///脂肪估算重量，单位：mg Estimated weight of fat, in mg
@property (nonatomic,assign) NSInteger              fatWeight;
///体能年龄 Physical age
@property (nonatomic,assign) NSInteger              physicalAge;
///平均配速,单位：s/km Average speed, in s/km
@property (nonatomic,assign) NSInteger              avgPace;
///平均步频（划船机桨频复用），单位:次/分 Average step frequency (rowing machine propeller frequency reuse), unit: times/minute
@property (nonatomic,assign) NSInteger              stepFrequency;
///平均步幅，单位：cm Average stride, unit: cm
@property (nonatomic,assign) NSInteger              avgStride;
///拉浆时间 单位：秒（暂无） Slurry pulling time unit: seconds (currently unavailable)
@property (nonatomic,assign) NSInteger              pullTime;
///收桨时间 单位：秒（暂无） Harvest time unit: seconds (currently unavailable)
@property (nonatomic,assign) NSInteger              freeTime;
///上楼层数 Number of upper floors
@property (nonatomic,assign) NSInteger              floorsUp;
///下楼层数 Number of floors downstairs
@property (nonatomic,assign) NSInteger              floorsDown;

//不涉及，暂时为空
@property (nonatomic,strong) NSMutableArray<UTEModeSportRecordSummaryRelation*> *motionRelationList;

@end

/*!
 *  UTEModeSportRunningPosture
 */
@interface UTEModeSportRunningPosture : NSObject

@property (nonatomic,assign) NSInteger              stepFrequency;
@property (nonatomic,assign) NSInteger              stride;
@property (nonatomic,assign) NSInteger              touchGroundTime;
@property (nonatomic,assign) NSInteger              landingForce;
@property (nonatomic,assign) NSInteger              swingAngle;
@property (nonatomic,assign) NSInteger              foreFootStep;
@property (nonatomic,assign) NSInteger              fullFootStep;
@property (nonatomic,assign) NSInteger              backFootStep;
@property (nonatomic,assign) NSInteger              outTurnRange;
@property (nonatomic,assign) NSInteger              flightTime;
@property (nonatomic,assign) NSInteger              groundFlightPercent;
@property (nonatomic,assign) NSInteger              steppingFrequency;

@end
/*!
 *  UTEModeSportRecordDetailList
 */
@interface UTEModeSportRecordDetailList : NSObject

///配速，单位：分米/秒 Pacing speed, in decimeters per second
@property (nonatomic,assign) NSInteger              speed;
///卡路里，单位：卡/5秒 Calories, in calories/5 seconds
@property (nonatomic,assign) NSInteger              calorie;
///海拔，单位：分米(海拔支持负数 Altitude, unit: decimeters (altitude supports negative numbers)
@property (nonatomic,assign) NSInteger              elevation;
///划水频率，单位：次/分钟 Swinging frequency, unit: times/minute
@property (nonatomic,assign) NSInteger              trashFrequency;
///步频，单位：步/5秒 Step frequency, unit: steps/5 seconds
@property (nonatomic,assign) NSInteger              stepFrequency;
///心率，单位：次/分钟 Heart rate, unit: beats per minute
@property (nonatomic,assign) NSInteger              heartRate;
///游泳效率 Swimming efficiency
@property (nonatomic,assign) NSInteger              swimEfficiency;
/** 以下参数都暂时不支持 The following parameters are currently not supported*/
///跳绳速度，单位：次/分钟 Jumping rope speed, unit: times/minute
@property (nonatomic,assign) NSInteger              jumpSpeed;
///燃脂速率，单位：千卡/min Fuel burning rate, unit: kcal/min
@property (nonatomic,assign) NSInteger              fatBurnRate;
///燃糖速率，单位：千卡/min Sugar burning rate, unit: kcal/min
@property (nonatomic,assign) NSInteger              sugarBurnRate;
//UTEModeSportRunningPosture
///跑姿数据 Running posture data
@property (nonatomic,assign) NSInteger              runningPosture;
///配速 s/km（新增2023/10/10），单位：s/km Pace, unit: s/km
@property (nonatomic,assign) NSInteger              pace;
@end
/*!
 *  UTEModeSportRecordDetail
 */
@interface UTEModeSportRecordDetail : NSObject
///单次运动记录ID Single exercise record ID
@property (nonatomic,assign) NSInteger              ID;
///单次运动索引 Single motion index
@property (nonatomic,assign) NSInteger              index;
///每组Data的实际时间间隔 The actual time interval between each set of Data
@property (nonatomic,assign) NSInteger              interval;
///次运动或者跑步计划记录的开始时间 The start time recorded for the next exercise or running plan
@property (nonatomic,assign) NSInteger              startTime;
///运动详情数据列表 Sports detail data list
@property (nonatomic,strong) NSMutableArray<UTEModeSportRecordDetailList *> *detailDataList;

@end


/*!
 *  UTEModeSportWorkoutRealTimeData
 */
@interface UTEModeSportWorkoutRealTimeData : NSObject
///运动时间，单位：秒 Exercise time, in seconds
@property (nonatomic,assign) NSInteger              workoutDuration;
///运动距离，单位：分米Movement distance, unit: decimeters
@property (nonatomic,assign) NSInteger              distance;
///运动卡路里消耗值，单位：卡 Calories burned during exercise, in calories
@property (nonatomic,assign) NSInteger              calorie;
///速度，单位：dm/s Speed, unit: dm/s
@property (nonatomic,assign) NSInteger              speed;
///配速，单位：s/km Speed, in s/km
@property (nonatomic,assign) NSInteger              pace;
///实时心率，单位：bpm Real time heart rate, unit: bpm
@property (nonatomic,assign) NSInteger              realTimeHeartRate;
///平均速度,单位: dm/s Average speed, unit: dm/s
@property (nonatomic,assign) NSInteger              avgSpeed;
///平均配速,单位:s/km Average speed, in s/km
@property (nonatomic,assign) NSInteger              avgPace;
///累计爬升,单位: dm Accumulated Climb, Unit: DM
@property (nonatomic,assign) NSInteger              totalRise;
///累计下降,单位: dm Accumulated decrease, unit: dm
@property (nonatomic,assign) NSInteger              totalDescend;
///高度，单位: dm Height, unit: dm
@property (nonatomic,assign) NSInteger              altitude;
///有氧训练效果 Aerobic training effect
@property (nonatomic,assign) NSInteger              aerobicEffect;
///无氧训练效果 Effect of anaerobic training
@property (nonatomic,assign) NSInteger              anaerobicEffect;
///效益指标 Benefit indicators
@property (nonatomic,assign) NSInteger              benefitIndex;
///执行状态 Execution Status
@property (nonatomic,assign) NSInteger              operatorType;
///跑步课程当前动作序号 Current action number for running course
@property (nonatomic,assign) NSInteger              runCourseNumber;
///跑步课程总动作数 Total number of running course actions
@property (nonatomic,assign) NSInteger              runCourseActionCount;
///动作编号 Action number
@property (nonatomic,assign) NSInteger              runCourseActionId;
///跑步课程剩余内容的类型 Types of remaining content in running courses
@property (nonatomic,assign) NSInteger              runCourseLeftType;
///剩余内容 Remaining content
@property (nonatomic,assign) NSInteger              runCourseContent;
///步频（单位：步数/分钟 steps/min） Step frequency (unit: steps/minute steps/min)
@property (nonatomic,assign) NSInteger              stepCadence;
///步数（踏数、桨数）复用 Reuse of steps (steps, paddles)
@property (nonatomic,assign) NSInteger              steps;
///速度，如单位：0.01km/h 要乘以100 再赋值,得到 1 The speed, in units of 0.01km/h, needs to be multiplied by 100 and then assigned a value to obtain 1
@property (nonatomic,assign) NSInteger              speedNew;
///平均速度，单位：0.02km/h 要乘以100 再赋值 得到 2 Average speed, unit: 0.02km/h, to be multiplied by 100 and assigned a value of 2
@property (nonatomic,assign) NSInteger              avgSpeedNew;
///新增踏频，单位：转/分钟 New tap frequency, unit: rpm
@property (nonatomic,assign) NSInteger              linkageCadence;
///新增浆频，单位：次/分钟 New slurry frequency, unit: times/minute
@property (nonatomic,assign) NSInteger              linkagePulpFrequency;
///新增浆次，单位：次 New pulp count, unit: times
@property (nonatomic,assign) NSInteger              linkageSlurry;
///新增功率，单位：瓦特 New power, in watts
@property (nonatomic,assign) NSInteger              linkagePower;
///新增阻力等级 New resistance level added
@property (nonatomic,assign) NSInteger              linkageResistanceLevel;
///新增阻力上限 Add upper limit of resistance
@property (nonatomic,assign) NSInteger              linkageResistanceRange;
///燃脂速率，单位：kcal/min Fuel burning rate, unit: kcal/min
@property (nonatomic,assign) NSInteger              fatBurnRate;
///燃糖速率，单位：kcal/min Sugar burning rate, unit: kcal/min
@property (nonatomic,assign) NSInteger              fatGlycogen;
///脂肪占比，[0-100] Fat percentage, [0-100]
@property (nonatomic,assign) NSInteger              fatPercent;
///累计脂肪，单位：mg Accumulated fat, unit: mg
@property (nonatomic,assign) NSInteger              fatCalorie;

@end

/*!
 *  UTEModeWorkoutPaceDataList
 */
@interface UTEModeWorkoutPaceDataList : NSObject

@property (nonatomic,assign) NSInteger              distance;
@property (nonatomic,assign) NSInteger              unit;
@property (nonatomic,assign) NSInteger              pace;
@property (nonatomic,assign) NSInteger              pointCount;
@property (nonatomic,assign) NSInteger              distanceTail;

@end
/*!
 *  UTEModeWorkoutPace
 */
@interface UTEModeWorkoutPace : NSObject

@property (nonatomic,assign) NSInteger              recordId;
@property (nonatomic,assign) NSInteger              paceIndex;

@property (nonatomic,strong) NSMutableArray<UTEModeWorkoutPaceDataList *> *paceDataList;

@end

/*!
 *  UTEModeGpsParam
 */
@interface UTEModeGpsParam : NSObject
//速度，单位：dm/s(分米/秒) Speed, unit: dm/s (decimeters/second)
@property (nonatomic,assign) NSInteger              speed;
//上个点到当前点距离，单位：分米 Distance from previous point to current point, in decimeters
@property (nonatomic,assign) NSInteger              distance;
//海拔高度，取值范围[-32768,32767]。单位：米 Altitude, value range [-3276832767]. Unit: meters
@property (nonatomic,assign) NSInteger              altitude;
//从运动开始到当前点的运动距离，单位：分米 The distance of movement from the beginning of the motion to the current point, in decimeters
@property (nonatomic,assign) NSInteger              totalDistance;
///当前点的起始时间 The starting time of the current point
@property (nonatomic,assign) NSInteger              startTime;
///当前点的结束时间 The end time of the current point
@property (nonatomic,assign) NSInteger              endTime;
///WGS84 纬度值，小数点后精度保留 7 位 WGS84 latitude value with a precision of 7 decimal places
@property (nonatomic,assign) double                 gpsLatitude;
///WGS84 经度值，小数点后精度保留 7 位 WGS84 longitude value, with a precision of 7 decimal places
@property (nonatomic,assign) double                 gpsLongitude;
///GCJ02 纬度值，小数点后精度保留 7 位 GCJ02 latitude value, with precision rounded to 7 decimal places
@property (nonatomic,assign) double                 gcj02Latitude;
///GCJ02 经度值，小数点后精度保留 7 位 GCJ02 Longitude value with a precision of 7 decimal places
@property (nonatomic,assign) double                 gcj02Longitude;
///方向，取值范围[0.0,360.0]，单位:度 Direction, value range [0.0360.0], unit: degrees
@property (nonatomic,assign) double                 bearing;
///位置精度（置信度为 68%），单位：米 Position accuracy (confidence level of 68%), in meters
@property (nonatomic,assign) double                 accuracy;

///当前GPS点相对上一个点的时间增量 The time increment of the current GPS point relative to the previous point
@property (nonatomic,assign) NSInteger              timeIndex;

@end

@interface UTEModeCurrentGPS : NSObject

///WGS84 纬度值，小数点后精度保留 7 位 WGS84 latitude value with a precision of 7 decimal places
@property (nonatomic,assign) double                 gpsLatitude;
///WGS84 经度值，小数点后精度保留 7 位 WGS84 longitude value, with a precision of 7 decimal places
@property (nonatomic,assign) double                 gpsLongitude;
///gps采样时间戳 gps timestamp
@property (nonatomic,assign) NSInteger              timeStamp;

@end

/*!
 *  UTEModelSciSleepFileData
 */
@interface UTEModelSciSleepFileData : NSObject
//Undefined
@property (nonatomic,assign) NSInteger              totalLength;
///睡眠开始时间戳 Sleep start timestamp
@property (nonatomic,assign) NSInteger              timeStamp;
///睡眠时长 Sleep duration (Unit : minute)
@property (nonatomic,assign) NSInteger              sleepTime;
///1为深睡，2为浅睡，3为清醒，4为快速眼动，5零星睡眠，6鼾睡，7睡眠开始，8睡眠结束。 1 is deep sleep, 2 is light sleep, 3 is awake, 4 is rapid eye movement, 5 is sporadic sleep, 6 is snoring, 7 is sleep beginning, and 8 is sleep ending.
@property (nonatomic,assign) NSInteger              sleepType;


//Sleep start time e.g. @"2015-08-08-23-30"
@property (nonatomic,copy  ) NSString               *startTime;
//Sleep end time e.g. @"2015-08-08-23-59"
@property (nonatomic,copy  ) NSString               *endTime;

@end



@interface UTEModeStressData : NSObject

@property (nonatomic,strong) NSMutableArray<NSString *> *startTimes;
@property (nonatomic,strong) NSMutableArray<NSString *> *intervals;
@property (nonatomic,strong) NSMutableArray<NSString *> *values;

@property (nonatomic,assign) NSInteger              stressValue;

@end

@interface UTEModeStressOneData : NSObject
///测量开始时间戳 Measurement start timestamp
@property (nonatomic,assign) NSInteger startTime;
///压力值 Pressure value
@property (nonatomic,assign) NSInteger stressValue;

@end


@interface UTEModeRecordDetailParam : NSObject
///单次运动记录ID
@property (nonatomic,assign) NSInteger      ID;
///单次运动索引
@property (nonatomic,assign) NSInteger      index;
///是否请求新算法的步频数据 默认为0
@property (nonatomic,assign) NSInteger      newAlgorithm;
//@property (nonatomic,assign) BOOL           fatBurnFitnessAge;

@end

@interface UTEModeBT3Info: NSObject
///mac地址 mac address
@property (nonatomic,copy  ) NSString       *mac;
///蓝牙名 Bluetooth name
@property (nonatomic,copy  ) NSString       *name;
///通话蓝牙开关是否打开 YES:打开 NO:关闭 Is the Bluetooth switch for calling turned on? YES: turned on NO: turned off
@property (nonatomic,assign) BOOL           isOpen;
///通话蓝牙配对是否配对 YES:配对 NO:没配对 Is Bluetooth pairing for calls paired? YES: Paired NO: Not paired
@property (nonatomic,assign) BOOL           isPair;
///通话蓝牙连接状态 YES:连接 NO:没连接 （根据这个来判断连接状态） Bluetooth connection status YES: connected NO: not connected (to determine connection status based on this)
@property (nonatomic,assign) BOOL           isConnected;

@end


@interface UTEModeDNDInfo: NSObject
///全天勿扰开关 YES:开启 NO:关闭 All day no disturbance switch YES: On NO: Off
@property (nonatomic,assign) BOOL           enableAllDay;
///定时勿扰开关 YES:开启 NO:关闭 Timed Do Not Disturb Switch YES: On NO: Off
@property (nonatomic,assign) BOOL           enableTime;
///定时勿扰开始时间 HH:mm Timed Do Not Disturb Start Time HH: mm
@property (nonatomic,copy  ) NSString       *startTime;
///定时勿扰结束时间 HH:mm Timed Do Not Disturb End Time HH: mm
@property (nonatomic,copy  ) NSString       *endTime;

@property (nonatomic,assign) BOOL           enableVibrate_WithoutTime;
@property (nonatomic,assign) BOOL           enableMsgRemind_WithoutTime;

@end


@interface UTEModeSportInfo: NSObject

@property (nonatomic,assign) BOOL           enableAllDay;
@property (nonatomic,assign) BOOL           enableTime;
//HH:mm
@property (nonatomic,copy  ) NSString       *startTime;
//HH:mm
@property (nonatomic,copy  ) NSString       *endTime;
@property (nonatomic,assign) BOOL           enableVibrate_WithoutTime;
@property (nonatomic,assign) BOOL           enableMsgRemind_WithoutTime;

@end

@interface UTEModelContactInfo : NSObject
///姓名 full name
@property (nonatomic,copy  ) NSString      *name;
///电话号码 phone number
@property (nonatomic,copy  ) NSString      *number;

@end


@interface UTEModelSportMangerInfo : NSObject
///最多支持当前运动数量 Supports up to the current number of sports
@property (nonatomic,assign) NSInteger     supportMax;
///最少支持当前运动数量 At least support the current number of movements
@property (nonatomic,assign) NSInteger     supportMin;

///请看EnumRYSDKSportType 序列号。对应支持的类型 Please refer to the serial number of EnumRYSDK SportType. Corresponding supported types
@property (nonatomic,strong) NSArray<NSNumber *>   *numSupportType;
///请看EnumRYSDKSportType 序列号。当前已添加类型 Please refer to the serial number of EnumRYSDK SportType. Currently added type
@property (nonatomic,strong) NSArray<NSNumber *>   *numCurrent;

@end

/*!
 *  UTEModelANCSInfo
 */
@interface UTEModelANCSInfo : NSObject

//appid 通过getBundleIDFromApp接口获取 Get the Bundle ID through the getBundleIDFromApp interface.
@property (nonatomic,copy) NSString                *appId;
//是否开启 0：关闭，1：开启 0：close ,1:open
@property (nonatomic,assign) NSInteger               enable;

@end

/*!
 *  UTEModelBaseInfo
 */
@interface UTEModelBaseInfo : NSObject

//Same as Android or Request an appkey from the project manager
@property (nonatomic,copy) NSString                *appKey;
//e.g. @"99aa00bbccdd"
@property (nonatomic,copy) NSString                *address;
//e.g. @"RB05V000088"
@property (nonatomic,copy) NSString                *version;

@property (nonatomic,assign)BOOL                    isDebug;
//See UTEDevicePlatformType
@property (nonatomic,assign) UTEDevicePlatformType  platform;

@end


/*!
 *  UTEModelOTAInfo
 */
@interface UTEModelOTAInfo : NSObject
/**
 *  If is YES,Indicates that the device must be upgraded.Because the device has a serious bug.
 */
@property (nonatomic,assign) BOOL          forceUpdate;
/**
 *  e.g. @"MH03BV000133"
 */
@property (nonatomic,copy  ) NSString      *version;
/**
 *  Description. Language follows mobile phone system language
 */
@property (nonatomic,copy  ) NSString      *des;
/**
 *  Firmware download path.
 *  1.Directly invoke beginUpdateFirmware: to upgrade.
 *
 *  2.OR you can download the firmware to the App.
 *  Then invoke updateLocalFirmwareUrl: to verify firmware.
 *  Finally, invoke beginUpdateFirmware: to upgrade.
 */
@property (nonatomic,copy  ) NSString      *firmwareURL;
/**
 *  Firmware patch download path.
 */
@property (nonatomic,copy  ) NSString      *firmwarePatchURL;

@end

/*!
 *  UTEModelWorldClock
 */
@interface UTEModelWorldClock : NSObject
///城市名 city name
@property (nonatomic,copy) NSString              *cityName;
///时区 time zone
@property (nonatomic,copy) NSString              *timeZone;
///夏令时(预留) Summer Time (reserved)
@property (nonatomic,assign) NSInteger              summerTime;

@end

/*!
 *  UTEModelServerLanguageFile
 */
@interface UTEModelServerLanguageFile : NSObject
//服务器语言
@property (nonatomic, copy ) NSString          *typeServer;
//iPhone语言
@property (nonatomic, copy ) NSString          *typeiOS;
//服务器语言列表号
@property (nonatomic,assign) NSInteger         num;
//文件下载地址
@property (nonatomic, copy ) NSString          *url;
//文件名称
@property (nonatomic, copy ) NSString          *name;
//文件时间 yyyy-MM-dd-HH-mm-ss
@property (nonatomic, copy ) NSString          *time;
//描述
@property (nonatomic, copy ) NSString          *des;
//设备支持最大容量
@property (nonatomic,assign) NSInteger         capacity;
//文件id序号
@property (nonatomic,assign) NSInteger         index;

@end

/*!
 *  UTEModelGameOperate
 */
@interface UTEModelGameOperate : NSObject
///
@property (nonatomic,assign) NSInteger                 x;
///
@property (nonatomic,assign) NSInteger                 y;

///
@property (nonatomic,assign) NSInteger                 Speed;

///
@property (nonatomic,assign) NSInteger                 X_Throw;

///
@property (nonatomic,assign) NSInteger                 Y_Throw;

/// 重力加速度Z
@property (nonatomic,assign) NSInteger                 Speed_Throw;
///
@property (nonatomic,assign) NSInteger                 Count_Throw;
/// 重力加速度X
@property (nonatomic,assign) NSInteger                 X_Move_Distance;
/// 重力加速度Y
@property (nonatomic,assign) NSInteger                 Y_Move_Distance;

@end

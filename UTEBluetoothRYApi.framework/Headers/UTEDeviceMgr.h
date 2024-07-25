//
//  UTEDeviceMgr.h
//  UTEBluetoothRYApi
//
//  Created by V V on 2023/3/15.
//  Copyright © 2023 vv. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UTEModelDevice.h"
#import "UTEMgrPhysiologicalCycle.h"
#import "UTEMgrDial.h"
#import "UTEAccountTool.h"
#import "UTEMgrAGPS.h"
#import "UTEMgrGame.h"

typedef NS_ENUM(NSInteger, UTEDeviceDateType) {
    UTEDeviceDateTypeYMD  = 1,
    UTEDeviceDateTypeMDY,
    UTEDeviceDateTypeDMY,
    UTEDeviceDateTypeMDE,
};

typedef NS_ENUM(NSInteger, UTEDeviceTimeType) {
    UTEDeviceTimeType12  = 1,
    UTEDeviceTimeType24,
};


@interface UTEDeviceMgr : NSObject

+ (instancetype) sharedInstance;
@property(nonatomic, strong, readonly) UTEMgrDial                *dial;
@property(nonatomic, strong, readonly) UTEMgrPhysiologicalCycle  *physiological;
@property(nonatomic, strong, readonly) UTEAccountTool            *accountTool;

@property(nonatomic, strong, readonly) UTEMgrAGPS                *agps;
@property(nonatomic, strong, readonly) UTEMgrGame                *game;
/**
 *  @discussion KEY
 *  If there is a key, you must set it every time you turn on the App.
 *
 *  uteKey e.g. @"aaaaaaaaaaaa11111"
 */
@property(nonatomic, copy) NSString                              *uteKey;

//1.2
- (void)querySupportService:(NSArray *)serviceIdList
                      block:(void(^)(NSDictionary *uteDict))block;
//1.3
- (void)querySupportCommand:(NSArray *)queryList
                      block:(void(^)(NSDictionary *uteDict))block;

/**1.4 设置手环日期格式
 Format the date of the bracelet
 
 @param dateType
 日期显示格式，1：年-月-日格式；2：月-日-年格式；3：日-月-年格式；4：月-日-星期格式
 Date display format, 1: year month day format; 2: Month day year format; 3: Day month year format; 4: Month Day Week Format
 
 @param timeType
 时间显示格式，1：显示 12 小时格式；2：显示 24 小时格式
 Time display format, 1: Display 12 hour format; 2: Display 24-hour format
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setTimeDisplay:(NSInteger)dateType timeType:(NSInteger)timeType block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

/**1.41 监听设备相机状态 通知事件ID 为固定的 297
 Monitor the status of the wristband camera
 
 @parma UTECameraStatus
 参考UTECameraStatus注释
 Refer to UTECameraStatus comments
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)notifyCamera:(void(^)(UTECameraStatus status,NSInteger errorCode ,NSDictionary *uteDict))block;

/**1.42 设置手机相机状态给设备
 Set the phone camera status to the bracelet
 
 @parma eventCode
 0:手机进入相机   1：手机打开相机   2：手机退出相机
 0: Phone enters camera 1: Phone opens camera 2: Phone exits camera
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setCameraStatus:(NSInteger)eventCode
                  block:(void(^)(NSInteger status ,NSInteger errorCode ,NSDictionary *uteDict))block;

//1.49 设备没有这个 默认返回都是0
- (void)querySupportAbilitySet:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

/**1.5 设置手环日期时间
 Set the date and time of the bracelet
 
 @parma timeSeconds
 时间戳(使用格林尼治时间)
 Timestamp (using Greenwich Mean Time)
 
 @parma timeZone
 时区
 time zone
 
 @parma minuteOffset
 分钟调整差值，部分地区为非整点时区
 Minute adjustment difference, some regions are in non hour time zones
 
 东8.15时区为timeZone:8 minuteOffset:15   东八区timeZone:8  minuteOffset:0 西八区timeZone:-8 minuteOffset:0
 East 8.15 is timeZone: 8 minuteOffset: 15; East Eighth District timeZone: 8 minuteOffset: 0; West Eighth District timeZone: -8 minuteOffset: 0;
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setTimeClock:(NSInteger)timeSeconds
            timeZone:(NSInteger)timeZone
        minuteOffset:(NSInteger)minuteOffset
               block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

//1.56 查询运动健康 APP 权限（上报及响应） 通知事件ID 为固定的 312 ,因为iOS不支持发短信、联系人，因此默认全部返回0
- (void)onNotifySportHealthPermision:(void(^)(NSArray<NSString *> *listPermision,NSInteger errorCode ,NSDictionary *uteDict))block;

///下发权限结果 array = @[@"0",@"0"]; 因为iOS不支持发短信、联系人，因此默认全部返回0
- (void)sendPermissionResultList:(NSArray *)array block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

/**1.6 获取手环日期时间
 Date and time of obtaining the bracelet
 
 @block timeSeconds 时间戳，单位：秒
 时间戳(使用格林尼治时间)
 Timestamp (using Greenwich Mean Time)
 
 @block timeZone
 时区
 time zone
 
 @block minuteOffset
 分钟调整差值，部分地区为非整点时区
 Minute adjustment difference, some regions are in non hour time zones
 
 东8.15时区为timeZone:8 minuteOffset:15   东八区timeZone:8  minuteOffset:0 西八区timeZone:-8 minuteOffset:0
 East 8.15 is timeZone: 8 minuteOffset: 15; East Eighth District timeZone: 8 minuteOffset: 0; West Eighth District timeZone: -8 minuteOffset: 0;
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)getTimeClock:(void(^)(NSInteger timeSeconds,NSInteger timeZone,NSInteger minuteOffset,NSInteger errorCode ,NSDictionary *uteDict))block;

/**1.67 获取抬腕亮屏开关状态
 Obtaining the status of the wrist lifting bright screen switch
 
 @parma switchType
 0：app查询；1：设备上报
 0: App query; 1: Equipment reporting
 
 @parma switchState
 0：关闭；1：开启
 0: Close; 1: Open
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)getScreenAutoLightState:(void(^)(NSInteger switchType,NSInteger switchState, NSInteger errorCode ,NSDictionary *uteDict))block;

/**1.67 监听抬腕亮屏开关状态 通知事件ID 为固定的 323
 Monitor the status of the wrist lifting and screen lighting switch
 
 @block switchType
 0：app查询；1：设备上报
 0: App query; 1: Equipment reporting
 
 @block switchState
 0：关闭；1：开启
 0: Close; 1: Open
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)onNofityScreenAutoLightState:(void(^)(NSInteger switchType,NSInteger switchState, NSInteger errorCode ,NSDictionary *uteDict))block;

/**1.69 app 查询与设备上报报警状态
 Query and device report alarm status
 
 @block findWearState
 0：关闭；1：开启；2：用户关闭
 0: Close; 1: Open; 2: User shutdown
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)getFindWearState:(void(^)(NSInteger findWearState,NSInteger errorCode ,NSDictionary *uteDict))block;

/**1.69 监听设备上报报警状态 通知事件ID 为固定的 325
 Monitor device reporting alarm status
 
 @block findWearState
 0：关闭；1：开启；2：用户关闭
 0: Close; 1: Open; 2: User shutdown
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)onNofityFindWearState:(void(^)(NSInteger findWearState,NSDictionary *uteDict))block;

/**1.7 获取设备版本相关信息
 Obtain device version related information
 
 @block model
 参考UTEModelDeviceElement注释
 Refer to UTEModelDeviceElement comments
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)getDeviceInfo:(void(^)(UTEModelDeviceElement *model,NSInteger errorCode ,NSDictionary *uteDict))block;

/**1.8 获取电池电量百分比
 Obtain battery level percentage
 
 @block percent
 电池电量百分比
 Battery level percentage
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)getBatteryInfo:(void(^)(NSInteger percent,NSInteger errorCode ,NSDictionary *uteDict))block;

/** 监听电池电量 通知事件ID 为固定的 264
 Monitor battery level
 
 @block battery
 电池电量百分比
 Battery level percentage
 */
- (void)onNofityBattery:(void(^)(NSInteger battery,NSDictionary *uteDict))block;

/**1.9 设置抬腕亮屏开关状态
 Set the status of the wrist lifting and screen lighting switch
 
 @parma enable
 true:开 false:关
 True: on false: off
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setScreenAutoLight:(BOOL)enable
                     block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

/**1.13 恢复出厂设置
 Restore factory settings
 
 @parma type
 0:恢复出厂后重启，1:恢复出厂以及关机
 0: Reboot after factory restoration, 1: Restore factory and shut down
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)resetFactory:(NSInteger)type block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

//1.33
- (void)getDefaultConfiguration:(void(^)(UTEModelDeviceInfoStatus1 *model,NSInteger errorCode ,NSDictionary *uteDict))block;

/**1.70 App控制设备震动或响铃（手机查找手环）
 App controls device vibration or ringing (phone searches for bracelets)
 
 @parma cmd
 0:关闭 1:开启
 0: Off 1: On
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setFindWearCmd:(NSInteger)cmd
                 block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

/**11.1 监听手机防丢报警(手环查找手机) 通知事件ID 为固定的 2817
 Monitor mobile phone loss prevention alarm (search for mobile phone with bracelet)
 
 @block status
 参考UTEFindWearStatus注释
 Refer to UTEFindWearStatus comments
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)notifyFindMyPhoneNotifyReal:(void(^)(UTEFindWearStatus status,NSInteger errorCode ,NSDictionary *uteDict))block;

/**11.2 设置手机防丢报警
 Set phone loss prevention alarm
 
 @parma action
 1:要求服务端报警 2:要求服务端停止报警
 1: Request server alarm 2: Request server to stop alarm
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setFindMyPhone:(NSInteger)action block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

/**11.3 设置蓝牙断开提醒开关
 Set Bluetooth disconnect reminder switch
 
 @parma enable
 true:开 false:关
 True: on false: off
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setDisconnectRemind:(BOOL)enable
                      block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

///12.1
- (void)setLanguage:(NSString *)language
               unit:(NSInteger)unit
              block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

/**12.1 设置手环语言&公英制单位设置
 Set bracelet language
 
 @parma language
 参考UTEDeviceLanguage
 Refer to UTEDeviceLanguage
 
 @parma unit
 0: 公制；1：英制
 0: metric system; 1: English system
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setLanguageEnum:(UTEDeviceLanguage)language
                   unit:(NSInteger)unit
                  block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

- (void)setLanguageOnly:(UTEDeviceLanguage)language
                  block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;
- (void)setUnitOnly:(NSInteger)unit
                  block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

/**2.4 设置消息提醒开关状态
 Set message reminder switch status
 
 @parma notificationEnable
 总消息提醒开关状态，NO：关，YES：开
 General message reminder switch status, NO: off, YES: on
 
 @parma incomingEnable
 来电通知开关状态，NO：关，YES：开
 Call notification switch status, NO: off, YES: on
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setNotificationConfig:(BOOL)notificationEnable
               incomingEnable:(BOOL)incomingEnable
                        block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

/**单独设置总通知提醒开关状态
 Set the overall notification reminder switch status separately
 
 @parma notificationEnable
 总消息提醒开关状态，NO：关，YES：开
 General message reminder switch status, NO: off, YES: on
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setNotificationConfig:(BOOL)notificationEnable block:(void(^)(NSInteger errorCode))block;

/**设置来电提醒开关状态
 Set the status of the incoming call reminder switch
 
 @parma incomingEnable
 来电通知开关状态，NO：关，YES：开
 Call notification switch status, NO: off, YES: on
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)incomingEnable:(BOOL)incomingEnable block:(void(^)(NSInteger errorCode))block;

//2.5 查询设备支持消息推送类型
- (void)getSupportMessageType:(void(^)(NSDictionary *dict,NSInteger errorCode ,NSDictionary *uteDict))block;

//2.10
- (void)getNotifyAppListCount:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

//2.11
- (void)setNotifyAppList:(NSArray<NSDictionary *> *)list block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

/**2.11 设置app消息单独控制名单(ANCS通知控制)
 Set up a separate control list for app messages (ANCS notification control)
 
 @parma list
 参考UTEModelANCSInfo
 Refer to UTEModelANCSInfo
 
 NSMutableArray *list = [NSMutableArray array];
 
 appId
 调用getBundleIDFromApp接口获取appId
 Call the getBundleIDFromApp interface to obtain appId
 
 enable
 @"1":开启, @"0":关闭
 @"1": On, @"0": Off

 例子
 example
 //常见app
 Common apps
 
 UTEModelANCSInfo *model = [UTEModelANCSInfo new];
 model.appId = [UTEDeviceMgr getBundleIDFromApp:UTEAppWechat];
 model.enable = 1;
 
 //没有的app统一用其他类型
 Unavailable apps are uniformly used with other types
 
 UTEModelANCSInfo *ohterModel = [UTEModelANCSInfo new];
 ohterModel.appId = [UTEDeviceMgr getBundleIDFromApp:UTEAppiOSOther];
 ohterModel.enable = 1;
 
 [list addObject:model];
 [list addObject:ohterModel];
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setNotifyAppListModel:(NSArray<UTEModelANCSInfo *> *)list block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

//listOpen/listOpen see UTEAppMsgType
- (void)setNotifyAppEnumOpen:(NSArray<NSNumber *> *)listOpen
                   listClose:(NSArray<NSNumber *> *)listClose
                       block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

/** 获取应用的appId
 Get appId
 
 @parma app
 参考UTEApp
 Refer to UTEApp
 
 @block NSString
 appId
 */
+ (NSString *)getBundleIDFromApp:(UTEApp)app;

///7.1
- (void)setMotionGoal:(NSArray<NSDictionary *> *)array
                block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

/**7.1 设置运动目标信息
 Set motion target information
 
 @parma arrayModel
 参考UTEModelSportGoal
 Refer to UTEModelSportGoal
 
 UTEModelSportGoal *Model = [UTEModelSportGoal new];
 arrayModel = @[Model]
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setMotionGoalModel:(NSArray<UTEModelSportGoal *> *)arrayModel
                block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

///7.2
- (void)setUserPhysicalInfo:(NSDictionary<NSString *, NSNumber *> *)userPhysicalInfo
                      block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

/**7.2 设置用户体征信息
 Set user sign information
 
 @parma model
 参考UTEModelPersonInfo
 Refer to UTEModelPersonInfo
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setUserPhysicalInfoModel:(UTEModelPersonInfo *)model
                      block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

/**7.3 获取当天总计运动数据
 Obtain total exercise data for the day
 
 @parma model
 参考UTEModelTodayStep
 Refer to UTEModelTodayStep

 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)getCurrentDayTotalWorkoutData:(void(^)(UTEModelTodayStep *model,NSInteger errorCode ,NSDictionary *uteDict))block;

/**7.6 获取活动提醒信息(久坐，喝水统称)
 Obtain activity reminder information (referred to as sedentary and drinking water)
 
 @parma model
 参考UTEModelActivity
 Refer to UTEModelActivity

 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)getActivityRemind:(void(^)(UTEModelActivity *model,NSInteger errorCode ,NSDictionary *uteDict))block;

/**7.7 设置活动提醒信息(久坐，喝水统称)
 Set activity reminder information (referred to as sedentary and drinking water)
 
 @parma enable
 true:开 false:关
 True: on false: off
 
 @parma interval
 间隔时长 单位: min
 Interval duration unit: min
 
 @parma startTime
 开始时间 HH-mm
 Start time HH-mm

 startTime = HH << 8 | mm;
 
 @parma endTime
 结束时间 HH-mm
 End time HH-mm
 
 endTime = HH << 8 | mm;
 
 @parma cycle
 目前固定值0b1111111
 Current fixed value 0b111111

 @block errorCode
 请求成功:100000 其他:错误码
 */
- (void)setActivityRemind:(BOOL)enable
                 interval:(UInt8)interval
                startTime:(UInt16)startTime
                  endTime:(UInt16)endTime
                    cycle:(UInt8)cycle
                    block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

/**7.10 获取采样点数据帧数(即同步步数/心率/血氧)
 Obtain the frame number of sampling point data (i.e. synchronization steps/heart rate/blood oxygen)
 
 @parma startTime
 开始时间戳
 Starting timestamp
 
 @parma endTime
 结束时间戳
 End timestamp

 @block frameCount
 总帧序
 Total frame order
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)getSampleFrameList:(NSInteger)startTime
                   endTime:(NSInteger)endTime
                     block:(void(^)(NSInteger frameCount ,NSInteger errorCode ,NSDictionary *uteDict))block;

/**新(根据健康拓展标识判断使用hasHealthExpansion) 获取采样点数据帧数(即同步步数/心率/血氧)
 New
 Obtain the frame number of sampling point data (i.e. synchronization steps/heart rate/blood oxygen)
 
 @parma startTime
 开始时间戳
 Starting timestamp
 
 @parma endTime
 结束时间戳
 End timestamp

 @block frameCount
 总帧序
 Total frame order
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)getSampleFrameListNew:(NSInteger)startTime
                   endTime:(NSInteger)endTime
                     block:(void(^)(NSInteger frameCount ,NSInteger errorCode ,NSDictionary *uteDict))block;

/**7.11  获取采样点数据(即同步步数/心率/血氧具体数据) 参数来源于7.10
 Obtain sampling point data (i.e. synchronous steps/heart rate/blood oxygen specific data) parameters from 7.10
 
 @parma startTime
 开始时间戳
 Starting timestamp
 
 @parma endTime
 结束时间戳
 End timestamp

 @parma index
 帧序号，通过7.10 frameCount，从0开始到index大于才同步数据完成
 Frame number, starting from 0 and synchronizing data until index is greater than 7.10 frameCount
 
 @block model
 参考UTEModelMotionFrame
 Refer to UTEModelMotionFrame
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)getSampleDetailData:(NSInteger)startTime
                    endTime:(NSInteger)endTime
                      index:(NSInteger)index
                      block:(void(^)(UTEModelMotionFrame *model ,NSInteger errorCode ,NSDictionary *uteDict))block;

//7.12
- (void)getStatusFrameCount:(NSInteger)startTime
                    endTime:(NSInteger)endTime
                      block:(void(^)(NSInteger count ,NSInteger errorCode ,NSDictionary *uteDict))block;
//7.13 参数来源于7.12
- (void)getStatusFrame:(NSInteger)startTime
               endTime:(NSInteger)endTime
                 index:(NSInteger)index
                 block:(void(^)(UTEModelStatusFrame *model ,NSInteger errorCode ,NSDictionary *uteDict))block;

/**7.15 监听手环数据通知主动上报 通知事件ID 为固定的 1807
 Monitor bracelet data notifications and proactively report
 
 通过监听此接口来主动触发调用同步今日活动数据或者运动历史记录、其他测量数据等接口
 Actively trigger calls to synchronize today's activity data, motion history, other measurement data, and other interfaces by listening to this interface
 */
- (void)onNotifySportData:(void(^)(NSInteger type,NSDictionary *uteDict))block;

/**7.22 设置科学睡眠检测开关
 Set scientific sleep detection switch
 
 @parma enable
 true:开 false:关
 True: on false: off
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setProfessionalSleep:(BOOL)enable
                       block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

/**7.30 获取心率升高/降低告警值
 Obtain alarm values for increased/decreased heart rate
 
 @parma startTime
 开始时间戳
 Start timestamp
 
 @parma endTime
 结束时间戳
 End timestamp
 
 @param alarmType
 0:心率升高 1:心率降低
 0: Increased heart rate 1: Reduced heart rate
 
 @block model
 参考UTEModelHRMRemind
 Refer to UTEModelHRMRemind
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)getHeartrateRaiseAlarm:(NSInteger)startTime
                       endTime:(NSInteger)endTime
                     alarmType:(NSInteger)alarmType
                         block:(void(^)(UTEModelHRMRemind *model,NSInteger errorCode ,NSDictionary *uteDict))block;

//7.31 获取指定类型的采样点数据帧数
- (void)getStateFrameIndex:(NSInteger)startTime
                   endTime:(NSInteger)endTime
                      type:(NSInteger)type
                     block:(void(^)(NSInteger frameCount ,NSInteger errorCode ,NSDictionary *uteDict))block;
//7.32 参数数来自于 7.31
- (void)getDesFrameData:(NSInteger)startTime
                endTime:(NSInteger)endTime
                  index:(NSInteger)index
                  block:(void(^)(UTEModelDesFrameData *model ,NSInteger errorCode ,NSDictionary *uteDict))block;

//7.33 设置储备心率区间参数
- (void)setHeartRateZone:(NSDictionary *)dict
                   block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

/**7.33 设置储备心率区间参数(运动中的心率报警设置)
 Set reserve heart rate interval parameters（Heart rate alarm settings during exercise）
 
 @parma model
 参考UTEModelHRMZone
 Refer to UTEModelHRMZone
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setHeartRateZoneModel:(UTEModelHRMZone *)model
                        block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

//7.35 0:静息心率1.0方案 1:静息心率2.0方案
- (void)setSilenceHeartrateMeasureType:(NSInteger)measureType block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;
- (void)readPeriodSpo2ConfigBlock:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

/**7.35 设置周期血氧开关
 Set cycle blood oxygen switch
 
 @parma enable
 true:开 false:关
 True: on false: off
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setPeriodSpo2Enable:(BOOL)enable block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

/** 设置周期血氧测量间隔
 Set cycle blood oxygen measurement interval
 
 @parma interval
 间隔时间 单位 分钟
 Interval time unit: minutes
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setPeriodSpo2EnableInterval:(NSInteger)interval block:(void(^)(NSInteger errorCode))block;

/** 获取周期血氧测量间隔
 Interval between obtaining periodic blood oxygen measurements
 
 @block interval
 间隔时间 单位 分钟
 Interval time unit: minutes
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)getPeriodSpo2EnableIntervalBlock:(void(^)(NSInteger errorCode,NSInteger interval))block;

/**7.36 设置血氧低于下限提醒开关 和最低值
 Set the reminder switch and minimum value for blood oxygen below the lower limit
 
 @parma enable
 true:开 false:关
 True: on false: off
 
 @parma remindLimit
 血氧低于下限提醒值
 Reminder value for blood oxygen below lower limit
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setPeriodSpo2Enable:(BOOL)enable
                remindLimit:(NSInteger)remindLimit
                      block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

//7.40
- (void)setPaceZoneConfig:(NSDictionary *)dict
                    block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;
//7.42 0:表示未锁屏 1:表示已锁屏
- (void)setPhoneState:(NSInteger)state
                block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

///7.1000 下载科学睡眠文件
- (void)getSciSleepFileWithStartTime:(NSInteger)startTime endTime:(NSInteger)endTime block:(void(^)(CGFloat process,BOOL isSuccess ,NSInteger errorCode ,NSString *filePath,NSDictionary *uteDict))block;

/**7.1000 下载科学睡眠文件（即睡眠数据）
 Download scientific sleep files (i.e. sleep data)

 */
- (void)getSciSleepModelWithStartTime:(NSInteger)startTime endTime:(NSInteger)endTime block:(void(^)(NSArray<UTEModelSciSleepFileData *> *array,CGFloat process,BOOL isSuccess ,NSInteger errorCode ,NSString *filePath,NSDictionary *uteDict))block;

///7.1000 bin文件解析
- (void)getSciSleepBinFilePath:(NSString *)filePath block:(void(^)(NSArray *uteArray))block;
-(void)testSleepData:(NSString *)str block:(void(^)(NSDictionary *uteDict,NSArray *uteArray))block;
//8.1
- (void)setAlarmArray:(NSArray<NSDictionary *> *)alarmArray
                block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

/**8.1 设置闹钟/删除闹钟(那么index 写对应的闹钟序号，其他值都填0）
 Set alarm clock to delete alarm clock (then write the corresponding alarm clock serial number in index, and fill in 0 for all other values)
 
 @parma alarmArray
 参考UTEModelClock注释
 Refer to UTEModelClock comments
 
 设置闹钟
 set alarm

 NSMutableArray *alarmArray = [NSMutableArray array];
 UTEModelClock *clock = [[UTEModelClock alloc] init];
 clock.timeHour = 12;
 clock.timeMin = 30;
 clock.name = @"";
 clock.index = 1;
 clock.cycle = 7f;
 clock.enable = NO;
 [alarmArray addObject:clock];
 
 删除闹钟
 根据获取到闹钟index,选择对应的index删除
 Delete alarm clock
 Based on the alarm clock index obtained, select the corresponding index to delete
 
 example
 NSMutableArray *alarmArray = [NSMutableArray array];
 UTEModelClock *clock = [[UTEModelClock alloc] init];
 clock.timeHour = 0;
 clock.timeMin = 0;
 clock.name = @"";
 clock.index = 1;
 clock.cycle = 0;
 clock.enable = NO;
 [alarmArray addObject:clock];
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setAlarmArrayModel:(NSArray<UTEModelClock *> *)alarmArray
                block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

//8.3
- (void)getAlarmArray:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

/**8.3 获取设备闹钟
 Get device alarm clock
 
 @parma modelArray
 参考UTEModelClock注释
 Refer to UTEModelClock comments
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)getAlarmArrayModel:(void(^)(NSInteger errorCode ,NSArray<UTEModelClock *> *modelArray))block;

/**7.23 设置自动测量心率开关
 Set automatic heart rate measurement switch
 
 @parma enable
 true:开 false:关
 True: on false: off
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setAutoHeartRate:(BOOL)enable
                   block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

/** 设置自动测量心率间隔
 Set automatic heart rate interval measurement
 
 @parma interval
 间隔时间 单位:分钟
 Interval time unit: minutes
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setAutoHeartRateInterval:(NSInteger)interval block:(void(^)(NSInteger errorCode))block;

/** 获取自动测量心率间隔
 Obtain automatic measurement of heart rate interval
 
 @block interval
 间隔时间 单位:分钟
 Interval time unit: minutes
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)getAutoHeartRateIntervalBlock:(void(^)(NSInteger errorCode,NSInteger interval))block;

/**7.28 设置连续测量心率开关
 Set continuous heart rate measurement switch
 
 @parma enable
 true:开 false:关
 True: on false: off
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setContinueMeasureHeartRateSwitch:(BOOL)enable
                                    block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;
/**7.29 设置心率升高提醒
 Set heart rate increase reminder
 
 @parma enable
 true:开 false:关
 True: on false: off
 
 @parma limit
 心率升高提醒值
 Reminder value for increased heart rate
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setHeartrateRaiseRemindSwitch:(BOOL)enable
                                limit:(NSInteger)limit
                                block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

/**7.34 设置心率降低提醒
 Set heart rate decrease reminder
 
 @parma enable
 true:开 false:关
 
 @parma limit
 心率降低提醒值
 Reminder value for heart rate decrease
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setLowestRemind:(BOOL)enable
                  limit:(NSInteger)limit
                  block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

//10.11 通知事件ID 为固定的 2571  type:1需要马上读取，0可以稍后读取   info:1代表手表所有日志；2代表重启日志；3代表死机日志；4代表抓取打点历史数据
- (void)onNofityDeviceBtn:(void(^)(NSDictionary *uteDict))block;

///15.1 设置当日气象提示信息
- (void)setTodayWeatherList:(NSDictionary *)dict
                      block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

/**15.1 设置当日气象提示信息
 Set daily meteorological prompt information
 
 @parma model
 参考UTEModelWeatherToday注释
 Refer to UTEModelWeatherToday comments
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setTodayWeatherModel:(UTEModelWeatherToday *)model
                      block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

//15.3 通知事件ID 为固定的 3843
- (void)onNotifyWeatherPressure:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;
- (void)setWeatherPressure:(NSInteger)pressure
                      unit:(NSInteger)unit
           pressureDecimal:(NSInteger)pressureDecimal
                     block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

/**15.4 监听设备主动获取天气数据 通知事件ID 为固定的 3844
 Active acquisition of weather data by monitoring devices
 
 监听到设备请求天气数据就调用15.1 15.8接口下发天气数据
 If the device requests weather data, call the 15.1 15.8 interface to send the weather data
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)onNotifyWeatherData:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

/**15.5 设置温度单位
 Set temperature units
 
 @parma unit
 1 摄氏度   2 华氏度
 1: Celsius 2: Fahrenheit
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setTemperatureUnit:(NSInteger)unit
                     block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

//15.7  weatherErrorType 0：网络错误；1：定位失败；2：关闭天气推送
- (void)setWeatherErrorInfoOld:(NSInteger)weatherErrorType
                         block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;
//15.8
- (void)setFutureWeather:(NSArray <NSDictionary *>*)hourForecastList
        weekForecastList:(NSArray <NSDictionary *>*)weekForecastList
                   block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

/**15.8 设置未来天气信息
 Set future weather information
 
 @parma hourForecastList
 未来小时天气，参考UTEModelWeatherHourForecast注释
 Future hourly weather, refer to UTEModelWeatherHourForecast notes
 
 @parma weekForecastList
 未来7天天气，参考UTEModelWeatherWeekForecast注释
 Weather for the next 7 days, refer to the UTEModelWeatherWeekForecast note
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setFutureWeatherModel:(NSArray <UTEModelWeatherHourForecast *>*)hourForecastList
        weekForecastListModel:(NSArray <UTEModelWeatherWeekForecast *>*)weekForecastList
                   block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;
//天气code转换对应UTEWeather
+ (UTEWeather)getSDKWeatherType:(NSInteger)code;

- (void)setFutureHourWeather:(NSArray <NSDictionary *>*)hourForecastDict
                       block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

//15.9  1：未来天气；2：日出日落，月相，潮汐；3：两者都支持 目前设备不支持能力设置，只有 1 功能
- (void)setFutureWeatherCapability:(NSInteger)item block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;
//15.10 item  0:都不支持 1：未来天气；2：日出日落，月相，潮汐；3：两者都支持
- (void)getFutureWeatherSupport:(void(^)(NSInteger item,NSInteger errorCode ,NSDictionary *uteDict))block;
//15.12  0：网络错误；1：定位失败；2：关闭天气推送
- (void)setWeatherErrorInfo:(NSInteger)errorInfoType block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

//23.1
- (void)setDeviceOperator:(NSDictionary *)dict
                    block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

/**23.1 通知设备开启运动
 Notify device to start movement
 
 @parma model
 参考UTEModelDeviceOperator注释
 Refer to UTEModelDeviceOperator comments
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setDeviceOperatorModel:(UTEModelDeviceOperator *)model
                    block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

/**23.2 监听设备主动上报执行状态 通知事件ID 为固定的 5890
 The monitoring device actively reports the execution status
 
 @parma model
 通过operatorType同步设备的开始、暂停、继续、结束
 Synchronize device start, pause, resume, and end through operatorType
 */
- (void)onNotifyDeviceOperator:(void(^)(UTEModelDeviceOperator *model,NSDictionary *uteDict))block;

/**23.3 查询设备执行状态
 Query device execution status
 
 @block model
 参考UTEModelDeviceOperator注释
 Refer to UTEModelDeviceOperator comments
 
 通过monitorState来判断
 Determine through monitorState
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)getDeviceOperatorState:(void(^)(UTEModelDeviceOperatorState *model,NSInteger errorCode ,NSDictionary *uteDict))block;

/**23.7 获取运动历史记录数据
 Obtain motion history data
 
 @parma startTime
 开始时间戳
 Start timestamp
 
 @parma endTime
 结束时间戳
 End timestamp
 
 @block model
 参考UTEModeSportRecord注释,获取到ID通过23.8查询获取单次运动记录统计值信息
 Refer to the UTEModSportRecord annotation to obtain the ID and obtain the statistical value information of a single exercise record through 23.8 query
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)getRecordList:(NSInteger)startTime endTime:(NSInteger)endTime block:(void(^)(UTEModeSportRecord *model,NSInteger errorCode ,NSDictionary *uteDict))block;

/**23.8 获取单次运动记录统计详细数据
 Obtain detailed statistical data for single exercise records
 
 @parma ID
 通过23.7获取到ID查询对应运动记录
 Retrieve ID through 23.7 to query corresponding motion records
 
 @block model
 参考UTEModeSportRecordSummary注释
 Refer to UTEModeSportRecordSummary comments
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)getRecordSummary:(NSInteger)ID block:(void(^)(UTEModeSportRecordSummary *model,NSInteger errorCode ,NSDictionary *uteDict))block;

/**23.9 监听上报单次运动结束记录统计值信息 通知事件ID 为固定的 5897
 Monitor and report the statistical value information of a single movement end record
 
 @block model
 参考UTEModelDeviceSportOneRecord注释
 Refer to UTEModelDeviceSportOneRecord comments
 
 运动记录，运动结束后上报，自行保存需要的字段
 Exercise records, report after exercise, and save the required fields on your own
 */
- (void)onNotifySportOneRecord:(void(^)(UTEModelDeviceSportOneRecord *model,NSDictionary *uteDict))block;

//23.10 
- (void)getRecordDetail:(NSDictionary *)dict
                  block:(void(^)(UTEModeSportRecordDetail *model,NSInteger errorCode ,NSDictionary *uteDict))block;

/** 23.10 获取单次运动记录详情值信息
 Obtain detailed value information for a single exercise record
 
 @parma detailModel
 参考UTEModeRecordDetailParam注释
 Refer to UTEModeRecordDetailParam annotation
 
 @block model
 参考UTEModeSportRecordDetail注释
 Refer to UTEModeSportRecordDetail comments
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)getRecordDetailModel:(UTEModeRecordDetailParam *)detailModel
                  block:(void(^)(UTEModeSportRecordDetail *model,NSInteger errorCode ,NSDictionary *uteDict))block;

//23.11
- (void)setWorkoutRealTimeData:(NSDictionary *)dict
                         block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

/**23.11 设置联动运动实时数据 运动中根据需要字段实时调用下发给手环
 Set up real-time data for linkage movement, and call and send the bracelet in real-time according to the required fields during movement
 
 @parma model
 参考UTEModeSportWorkoutRealTimeData注释
 Refer to UTEModeSportWorkoutRealTimeData annotation
 
 以下运动分类下发参考
 The following motion categories are distributed for reference
 1、户外跑步、户外走路、室内跑步：总时间、步数、距离、卡路里、步频、心率、平均配速、速度
 2、户外骑行：总时间、距离、速度 卡路里、心率
 3、爬楼梯：总时间、卡路里、心率
 4、登山、越野跑：总时间、步数、距离、配速、卡路里、海拔、累计上升、累计下降、心率 （登山需要有气压计，没有气压计，登山数据同步户外走跑)
 5、单板滑雪：总时间、距离、速度、趟数（steps）、海拔、累计上升、累计下降、卡路里、心率
 6、越野滑雪：总时间、距离、速度、海拔、累计上升、累计下降、卡路里、心率
 7、泳池游泳：总划水次数（steps）、卡路里、总游泳时间(workoutDuration)、平均配速、心率
 8、开放水域游泳：总划水次数、卡路里、总游泳时间、平均配速、心率
 9、椭圆机：总时间、步数、步频、卡路里、心率
 10、划船机：总时间、次数（steps）、频率、卡路里、心率
 11、跳绳：总时间、跳绳数（steps) 、卡路里、心率
 12、其它运动：总时间、 卡路里、心率
 1. Outdoor running, outdoor walking, indoor running: total time, steps, distance, calories, stride frequency, heart rate, average pace, speed
 2. Outdoor cycling: total time, distance, speed, calories, heart rate
 3. Climbing stairs: total time, calories, heart rate
 4. Mountaineering and off-road running: total time, steps, distance, pace, calories, altitude, cumulative increase, cumulative decrease, heart rate (mountaineering requires a barometer, no barometer, mountaineering data synchronized with outdoor running)
 5. Snowboarding: total time, distance, speed, steps, altitude, cumulative increase, cumulative decrease, calories, heart rate
 6. Cross country skiing: total time, distance, speed, altitude, cumulative increase, cumulative decrease, calories, heart rate
 7. Swimming in the pool: total number of strokes (steps), calories, total swimming time (workoutDuration), average pace, heart rate
 8. Open water swimming: total number of strokes, calories, total swimming time, average pace, heart rate
 9. Elliptical machine: total time, steps, step frequency, calories, heart rate
 10. Rowing machine: total time, steps, frequency, calories, heart rate
 11. Jumping rope: total time, steps, calories, heart rate
 12. Other sports: total time, calories, heart rate
 
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setWorkoutRealTimeDataModel:(UTEModeSportWorkoutRealTimeData *)model block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

//23.12
- (void)getWorkoutPace:(NSInteger)recordId
             paceIndex:(NSInteger)paceIndex
                 block:(void(^)(UTEModeWorkoutPace *model,NSInteger errorCode ,NSDictionary *uteDict))block;

//23.14 此固件不支持 不返回data key
- (void)getWorkoutSectionDetail:(NSInteger)workoutRecordId sectionIndex:(NSInteger)sectionIndex block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

/**23.17 运动中实时上报统计数据 通知事件ID 为固定的 5905
 Real time reporting of statistical data during exercise
 
 @block model
 参考UTEModelDeviceSportRealData注释
 Refer to UTEModelDeviceSportRealData annotation
 
 运动中实时上报数据，结合23.11选择需求数据下发给设备
 Real time reporting of data during exercise, combined with 23.11 selection of demand data for distribution to devices
 */
- (void)onNotifySportRealData:(void(^)(UTEModelDeviceSportRealData *model,NSDictionary *uteDict))block;

/**23.18 运动开始设置设备开启/关闭运动数据上报（直接发开启）
 Start of movement setting device on/off motion data reporting (direct activation)
 
 @parma enable
 true:开启 false:关闭
 True: enable false: disable
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setIsOpenWorkoutOperatorReport:(BOOL)enable block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

//23.21 目前只支持跑步机联动
- (void)getWorkoutAbility:(void(^)(UTEModelDeviceWorkoutAbility *model,NSInteger errorCode ,NSDictionary *uteDict))block;
//23.23
- (void)setWorkoutAbility:(NSInteger)capability enable:(BOOL)enable block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

//23.1000 文件路径注意要加上后缀
- (void)downloadRecordGpsFile:(NSInteger)recordId filePath:(NSString *)filePath block:(void(^)(CGFloat process,BOOL isSuccess ,NSInteger errorCode ,NSString *filePath))block;
- (void)downloadRecordGpsFileModel:(NSInteger)recordId filePath:(NSString *)filePath block:(void(^)(CGFloat process,BOOL isSuccess ,NSInteger errorCode,NSArray<UTEModeGpsParam *> *arrayModels))block;

/**23.1000-1 获取运动记录GPS数据
 Obtaining GPS data for sports records
 
 @parma recordId
 运动记录ID获取对应GPS数据
 Obtain corresponding GPS data for motion record ID
 
 @block isSuccess
 请求成功:YES 其他:错误码
 Request successful: YES Other: Error code
 
 @block uteArray
 数据格式返回经纬度数组[[纬度,经度]]
 Data format returns an array of latitude and longitude [[latitude, longitude]]
 */
- (void)downloadRecordGps:(NSInteger)recordId Block:(void(^)(CGFloat process,BOOL isSuccess ,NSInteger errorCode ,NSArray *uteArray))block;

/**24.2 监听手环请求GPS参数数据 通知事件ID 为固定的 6146
 Monitoring bracelet requests GPS parameter data
 
 监听到手环请求gps数据时，需要调用setGpsParamsModel下发gps数据给手环
 When listening to a bracelet requesting GPS data, you need to call setGpsParamsModel to send GPS data to the bracelet
 */
- (void)onNotifyGPS:(void(^)(NSDictionary *uteDict))block;

//24.3
- (void)setGpsParams:(NSArray <NSDictionary *>*)gpsList block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

/**24.3 运动中GPS实时下发
 Real time GPS distribution during movement
 
 @parma model
 参考UTEModeGpsParam注释
 Refer to UTEModeGpsParam comments
 
 下发gpsLatitude,gpsLongitude ，gcj02Latitude，gcj02Longitude，通过23.1000-1获取GPS记录数据
 Issue gpsLatitude, gpsLongitude, gcj02Latitude, gcj02Longitude, and obtain GPS record data through 23.1000-1
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setGpsParamsModel:(UTEModeGpsParam*)model block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

/**24.7 下发当前网络位置
 Distribute current network location
 
 @param model
 参考UTEModeCurrentGPS注释
 Refer to UTEModeCurrentGPS comments
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setCurrentGPSModel:(UTEModeCurrentGPS*)model block:(void(^)(NSInteger errorCode))block;

//25.3 通知事件ID 为固定的 6403
- (void)onNotifyHRMReal:(void(^)(UTEModelHRMReal *model,NSDictionary *uteDict))block;

/**25.1 运动开始设置设备开启/关闭实时心率（直接发开启）
 Set the device to turn on/off real-time heart rate at the beginning of exercise (directly activate)
 
 @param measureState
 1:实时心率开 2:实时心率关 3:实时RRI心率开 4:实时RRI心率关
 1: Real time heart rate on 2: Real time heart rate off 3: Real time RRI heart rate on 4: Real time RRI heart rate off
 
 @param speakerState
 1:静音 2:非静音
 1: Mute 2: Non mute
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setRestHeartRateMeasureType:(NSInteger)measureState
                       speakerState:(NSInteger)speakerState
                              block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

/**32.9 设置压力自动检测开关
 Set pressure automatic detection switch
 
 @param enable
 true:开启 false:关闭
 True: enable false: disable
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setAutoStress:(BOOL)enable
                block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

/** 设置压力自动检测间隔
 Set pressure automatic detection interval
 
 @param interval
 间隔时间 单位 分钟
 Interval time unit: minutes
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setAutoStressInterval:(NSInteger)interval block:(void(^)(NSInteger errorCode))block;

/** 获取压力自动检测间隔
 Obtain pressure automatic detection interval
 
 @block interval
 间隔时间 单位 分钟
 Interval time unit: minutes
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)getAutoStressIntervalBlock:(void(^)(NSInteger errorCode,NSInteger interval))block;

//32.1000 下载周期压力测量文件 endTime 结束时间无效，因为ble不支持。 process没有进度调，因为ble不支持
- (void)downloadStressDataFile:(NSInteger)startTime
                       endTime:(NSInteger)endTime
                      filePath:(NSString *)filePath
                         block:(void(^)(CGFloat process,BOOL isSuccess ,NSInteger errorCode ,NSString *filePath, NSString *uuid,NSDictionary *uteDict))block;

/**32.1000 下载周期压力测量文件 （即压力测量数据）
 Download periodic pressure measurement files (i.e. pressure measurement data)
 
 @param startTime
 开始时间戳
 Start timestamp
 
 @param endTime
 结束时间戳无效，因为ble不支持
 The end timestamp is invalid because ble does not support it
 
 NSTimeInterval endTime = [[NSDate date] timeIntervalSince1970];
 NSTimeInterval startTime = end - 7 * 86400;//默认7天数据
 
 @param filePath
 填写nil,根据返回的uteDict字典解析数据
 Fill in nil and parse the data based on the returned uteDict dictionary
 
 @block process
 没有进度，因为ble不支持
 No progress as ble does not support
 
 @block isSuccess
 请求成功:YES 其他:错误码
 Request successful: YES Other: Error code
 
 @block array
 压力测量数据
 Pressure measurement data
 
 NSMutableArray *mArray = [NSMutableArray array];
 for (UTEModeStressOneData *model in array) {
     NSDate *dateModel = [NSDate dateWithTimeIntervalSince1970:model.startTime];
     model.stressValue
 }
 */
- (void)downloadStressDataFileModel:(NSInteger)startTime endTime:(NSInteger)endTime filePath:(NSString *)filePath block:(void(^)(CGFloat process,BOOL isSuccess ,NSInteger errorCode ,NSString *filePath  ,NSString *uuid,NSArray<UTEModeStressOneData *> *array))block;

//1.150 timeSeconds:格林时间
//timeZone:时区(东区为正数，西区为负数)
//minuteOffset:分钟调整差值
- (void)activateElectronicCard:(NSInteger)timeSeconds
                      timeZone:(NSInteger)timeZone
                  minuteOffset:(NSInteger)minuteOffset;
//26.4 status:0：表示失败；1：表示成功
- (void)activateElectronicCard:(NSInteger)status block:(void(^)(NSString *uuid,NSInteger errorCode))block;

//26.3 通知事件ID 为固定的 6659
- (void)onNotifyElectronicRequest:(void(^)(NSString *uuid,NSDictionary *uteDict))block;

/** 监听设备ANCS配对状态
 Monitoring device ANCS pairing status
 
 @block isPair
 YES:点击了配对 NO:取消
 YES: Paired NO: Cancel
 */
- (void)onNotifyPair:(void(^)(BOOL isPair))block;

/** 读取通话蓝牙3.0状态
 Read Bluetooth 3.0 status for calls
 
 @block info
 参考UTEModeBT3Info注释
 Refer to UTEModeBT3Info comments
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)readBT3Info:(void(^)(UTEModeBT3Info *info,NSInteger errorCode))block;

/** 设置通话蓝牙配对ID
 Set call Bluetooth pairing ID
 
 @param appid
 根据phoneSendWatchAccountWith接口获取到0:帐号一致 1:帐号不一致 2:无帐号状态，当0或2 appid发相同的不用变，当1账号不一致发新的appid
 According to the phoneSendWatchAccountWith interface, 0: account consistency 1: account inconsistency 2: no account status. When 0 or 2 appids are the same, no change is needed. When 1 account is inconsistent, a new appid is sent
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setBT3Pair:(NSInteger)appid Block:(void(^)(NSInteger errorCode))block;

/** 控制BT的打开和关闭
 Control the opening and closing of BT
 
 @param type
 1:开启 固定发1
 1: Enable fixed transmission 1
 
 调用setBT3Pair接口后收到成功再调用此接口
 After successfully calling the setBT3Pair interface, call this interface again
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setBT3Info:(NSInteger)type Block:(void(^)(NSInteger errorCode))block;

/** 设置勿扰功能
 Set Do Not Disturb Function
 
 @param info
 参考UTEModeDNDInfo注释
 Refer to UTEModeDNDInfo comments
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setDNDInfo:(UTEModeDNDInfo *)info block:(void(^)(NSInteger errorCode))block;

/** 获取勿扰状态
 Obtain Do Not Disturb Status
 
 @block info
 参考UTEModeDNDInfo注释
 Refer to UTEModeDNDInfo comments
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)readDNDInfo:(void(^)(UTEModeDNDInfo *info,NSInteger errorCode))block;

/** 获取亮屏时长
 Obtain the duration of the bright screen
 
 @block lightTime
 亮屏时长 单位：秒
 Brightness duration，Unit: seconds
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)readLightTime:(void(^)(NSInteger lightTime,NSInteger errorCode))block;

/** 获取亮屏时长设置列表
 Get a list of bright screen duration settings
 
 @block lightTimeList
 亮屏时长列表 字符串 单位：秒
 List string of on-screen duration，Unit: seconds
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)readLightSetTimeList:(void(^)(NSArray *lightTimeList,NSInteger errorCode))block;

/** 设置亮屏时长
 Set the duration of the bright screen
 
 @block lightTime
 亮屏时长 单位：秒
 Brightness duration，Unit: seconds
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setLightTime:(NSInteger)lightTime Block:(void(^)(NSInteger errorCode))block;

/** 获取手环支持语言列表
 Obtain a list of supported languages for the bracelet
 
 @block array
 根据枚举UTEDeviceLanguage来解析
 Parse based on the enumeration of UTEDeviceLanguage
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)readSupportLanguage:(void(^)(NSArray<NSNumber *> *array,NSInteger errorCode))block;

//获取当前设备语言
- (void)readCurrentLanguage:(void(^)(NSInteger language,NSInteger errorCode))block;

//获取当前设备重量单位
- (void)readCurrentUnitWeight:(void(^)(BOOL isKG,NSInteger errorCode))block;

/** 设置当前设备重量单位
 Set the current device weight unit
 
 @param isKG
 YES:磅 NO:千克
 YES: pounds NO: kilograms
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setCurrentUnitWeight:(BOOL)isKG block:(void(^)(NSInteger errorCode))block;

/** 获取屏幕类型
 Get Screen Type
 
 @block ScreenType
 0:圆屏，1:方屏
 0: Round screen, 1: Square screen
 
 @block angle
 圆角值
 Fillet value
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)getDeviceScreenTypeBlock:(void(^)(NSInteger ScreenType,NSInteger angle,NSInteger errorCode))block;

//同步通讯录
- (void)setAddressBook:(NSArray *)array Block:(void(^)(NSInteger sendTime,NSInteger errorCode))block;

/** 同步通讯录
 Synchronize Address Book
 
 @param array
 参考UTEModelContactInfo注释
 Refer to UTEModelContactInfo comments
 
 @block sendTime
 已废弃
 obsolete
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setAddressBookModel:(NSArray <UTEModelContactInfo *>*)array Block:(void(^)(NSInteger sendTime,NSInteger errorCode))block;

///设置SOS号码
- (void)setSOSNumber:(NSArray *)array Block:(void(^)(NSInteger errorCode))block;

/** 设置SOS号码 （目前只支持一个，重复设置覆盖显示）
 Set SOS number (currently only one is supported, repeated settings overwrite display)
 
 @param array
 参考UTEModelContactInfo注释
 Refer to UTEModelContactInfo comments
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setSOSNumberModel:(NSArray <UTEModelContactInfo *>*)array Block:(void(^)(NSInteger errorCode))block;


/** 获取运动管理等信息
 Obtain sports management and other information
 
 @block model
 参考UTEModelSportMangerInfo注释
 Refer to UTEModelSportMangerInfo comments
 
 运动类型参考EnumRYSDKSportType
 Sports type reference EnumRYSDK SportType
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)readSportMangerInfo:(void(^)(UTEModelSportMangerInfo *model,NSInteger errorCode))block;

/** 设置当前手环显示的运动种类列表
 Set the list of motion types displayed on the current bracelet
 
 @param array
 运动类型参考EnumRYSDKSportType
 Sports type reference EnumRYSDK SportType
 
 array数量最多最少参考readSportMangerInfo接口返回的值来限制数量
 The maximum or minimum number of arrays can be limited by referring to the values returned by the readSportMangerInfo interface
 
 NSMutableArray *array = [NSMutableArray array];
 for (int i= 0,i < mArray.coun,i++) {
     NSNumber *number = [NSNumber numberWithInteger:EnumRYSDKSportType];
     [array addObject:number];
 }

 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setSportDisplay:(NSArray<NSNumber *> *)array block:(void(^)(NSInteger errorCode))block;

/**监听设备主动修改当前运动列表变化
 The monitoring device actively modifies the current movement list changes
 
 @block array
 手环当前运动列表
 Current movement list of the bracelet
 */
- (void)onNotifySportDisplay:(void(^)(NSArray<NSNumber *> *array))block;

/**app上查找手机开关
 Search for phone switches on the app
 
 @param status
 0表示关闭，1表示打开。
 0:close, 1:open

 */
- (void)setIphoneFindSwitch:(NSInteger)status block:(void(^)(NSInteger errorCode))block;

/**app上相机权限开关
 Camera permission switch on the app
 
 @param status
 0表示关闭，1表示打开。
 0:close, 1:open

 */
- (void)setCameraSwitch:(NSInteger)status block:(void(^)(NSInteger errorCode))block;

/**设置世界时钟
 Set World Clock
 
 @param arrayModels
 参考 UTEModeWorldClock 注释
 Refer to UTEModeWorldClock comments
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setWorldClock:(NSArray<UTEModelWorldClock *> *)arrayModels block:(void(^)(NSInteger errorCode))block;

/**获取世界时钟
 Get the world clock
 
 @block arrayModels
 数组 UTEModeWorldClock
 Array UTEModeWorldClock
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)getWorldClockBlock:(void(^)(NSInteger errorCode,NSArray<UTEModelWorldClock *> *arrayModels))block;

/**获取设备支持最大几个城市
 Obtain the maximum number of cities supported by the device
 
 @block max
 支持最大几个城市
 Support the largest cities
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)getSupportWorldClockBlock:(void(^)(NSInteger errorCode,NSInteger max))block;

/**监听同步app时间开关状态
 Monitor the synchronization app's time switch status
 
 @block status
 0表示关闭，1表示打开。
 0:close, 1:open
 */
- (void)onNotifySyncTimeSwitch:(void(^)(NSInteger status))block;

/**监听同步app语言开关状态
 Monitor and synchronize app language switch status
 
 @block status
 0表示关闭，1表示打开。
 0:close, 1:open
 */
- (void)onNotifySyncLanguageSwitch:(void(^)(NSInteger status))block;

/**
 *  获取设备支持语言文本的最大容量
 */
- (void)getDeviceLanguageCapacity:(void(^)(NSInteger errorCode,NSInteger maxCapacity))block;
/**
 *  从服务器获取语言文本
 *   language: 当为 UTEDeviceLanguageNone，表示从服务器获取支持的所有语言
 *  deviceCapacity: 请查看方法(getDeviceLanguageCapacity:)
 *  前提：hasLanguageFile = YES
 */
- (void)getServerLanguageFile:(UTEDeviceLanguage)language
               deviceCapacity:(NSInteger)deviceCapacity
                        block:(void(^)(NSArray<UTEModelServerLanguageFile *> *array ,NSError *error))block;
/**
 *  把语言文本发送给设备
 *  fileName: UTEModelServerLanguageFile.name
 *  data: 从UTEModelServerLanguageFile.url 路径下载得到的文件
 */
- (void)uploadLanguageFile:(NSString *)fileName data:(NSData *)data block:(void(^)(CGFloat process,BOOL isSuccess ,NSInteger errorCode))block;
/**
 *  删除设备当前某个语言
 *  index: 当前的语言序列号 请查看方法readCurrentLanguage：.  如得到的index 是设备支持的本地语言（readSupportLanguage：获取支持的本地语言），请不要调用此方法。
 */
- (void)deleteLanguageFileIndex:(NSInteger)indexCurrent block:(void(^)(BOOL isSuccess ,NSInteger errorCode))block;

#pragma mark - Tool
- (void)openSleepLog:(void(^)(BOOL ok))block;
- (void)closeSleepLog:(void(^)(BOOL ok))block;

///SN号不能都是空格，且只能是数字和字母
- (void)setDeviceSN:(NSString *)sn block:(void(^)(NSInteger errorCode,NSDictionary *uteDict))block;
- (void)getDeviceSN:(void(^)(NSInteger errorCode,NSString *sn,NSDictionary *uteDict))block;
///设置mac地址
- (void)setDeviceMAC:(NSString *)mac block:(void(^)(NSInteger errorCode,NSDictionary *uteDict))block;

- (void)debugReceiveData:(NSData *)data;

///字符串转换Unicode 再转nsdata
+(NSData*)stringToUnicodeData:(NSString *)dataStr;
///ble nsdata 转 Unicode 转utf8字符串
+(NSString *)replaceUnicode:(NSData *)strData;
///字符串转ASCII
+(NSData*)FromStringToASCII:(NSString *)sn;
///ASCII转字符串
+(NSString *)FromASCIIToString:(NSData *)data;
///十六进制字符串转nsdata
+ (NSData *)convertHexStrToData:(NSString *)str;
///nsdata 转十进制字符串
+ (NSString *)StringFromhexData:(NSData *)data;
///根据长度解析 index解析数据起始位置 length解析数据长度 data解析数据
+(NSInteger)getData:(NSInteger)index WithLength:(NSInteger)length WithData:(NSData *)data;
///十六进制转Double
+(double)HEXToDouble:(NSData *)data;
///十六进制转Float
+(double)HEXToFloat:(NSData *)data;
@end



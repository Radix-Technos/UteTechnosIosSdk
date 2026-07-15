//
//  UTEDevicePhysiologicalCycle.h
//  UTEBluetoothRYApi
//
//  Created by V V on 2023/3/28.
//  Copyright © 2023 vv. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, UTEAbilityType) {
    ///激活开关 action switch
    UTEAbilityTypeAllBtn                    = 0x01,
    ///经期开始提醒开关 Menstrual reminder switch
    UTEAbilityTypeMenstrualStartBtn         = 0x02,
    ///经期结束提醒开关 Menstrual end reminder switch
    UTEAbilityTypeMenstrualEndBtn           = 0x04,
    ///易孕期开始提醒开关 Start of easy pregnancy reminder switch
    UTEAbilityTypePregnancyStartBtn         = 0x08,
    ///易孕期结束提醒开关 End of pregnancy reminder switch
    UTEAbilityTypePregnancyEndBtn           = 0x10,
};

/*!
 *  @enum UTEMenstruationType
 *
 *  @discussion Menstruation Cycle Type
 *
 */
typedef NS_ENUM(NSInteger, UTEMenstruationType) {
    ///安全期 safe period
    UTEMenstruationTypeSafe,
    ///经期 Menstruation
    UTEMenstruationTypeMenstruation,
    ///排卵/易孕期 Ovulation
    UTEMenstruationTypeOvulation,
    
};

@interface UTEModelMenstrualNotifyAbility : NSObject
///开关类型 switch type
@property (nonatomic,assign) UTEAbilityType     abilityType;
///开关状态 switch status
@property (nonatomic,assign) BOOL               enable;

@end

@interface UTEModelMenstrualSwitch : NSObject
///所有开关 All switches
@property (nonatomic,assign) BOOL            allEnable;
///经期开始提醒开关 Menstrual reminder switch
@property (nonatomic,assign) BOOL            menstrualStartEnable;
///经期结束提醒开关 Menstrual end reminder switch
@property (nonatomic,assign) BOOL            menstrualEndEnable;
///易孕期开始提醒开关 Start of easy pregnancy reminder switch
@property (nonatomic,assign) BOOL            pregnancyStartEnable;
///易孕期结束提醒开关 End of pregnancy reminder switch
@property (nonatomic,assign) BOOL            pregnancyEndEnable;

@end

/*!
 *  UTEModelMenstruationInfo
 *  Female physiological cycle
 */
@interface UTEModelMenstruationInfo : NSObject
/**
 *  Date of the first day of the last menstrual period
 *  e.g. @"2018-08-22"
 */
@property (nonatomic,copy  ) NSString       *firstTime;
/**
 *  Duration of menstruation. Range:3 ~ 8 (day)
 */
@property (nonatomic,assign) NSInteger      duration;
/**
 *  Menstrual cycle. Range:24 ~ 40 (day)
 */
@property (nonatomic,assign) NSInteger      cycle;

@end


/*!
 *  UTEModelMenstruationCycle
 *  Female physiological cycle
 */
@interface UTEModelMenstruationCycle : NSObject
/**
 *  Current day
 *  e.g. @"2018-08-22"
 */
@property (nonatomic,copy  ) NSString               *time;
/**
 *  See UTEMenstruationType
 */
@property (nonatomic,assign) UTEMenstruationType     type;
/**
 *  The first day of the next menstruation
 *  e.g. @"2018-09-18"
 */
@property (nonatomic,copy) NSString               *nextMenstruationTime;


@end



@interface UTEModelMenstrualData : NSObject
///开始时间戳 Menstrual start timestamp
@property (nonatomic,assign) NSInteger     menstrualStartTime;
///结束时间戳（开始时间+长度） Menstrual end timestamp (Start time+length)
@property (nonatomic,assign) NSInteger     menstrualEndTime;
///易孕期开始时间戳 （比如经期后4天）Start timestamp of easy pregnancy period (e.g. 4 days after menstruation)
@property (nonatomic,assign) NSInteger     easyToPregnantStartTime;
///易孕期结束时间戳 （比如共10天） End timestamp of easy pregnancy period (e.g. 10 days in total)
@property (nonatomic,assign) NSInteger     easyToPregnantEndTime;
///生理期周期 Physiological cycle
@property (nonatomic,assign) NSInteger     cycleDays;
///固定值1 (APP设置时)(When setting up the app)Fixed value 1  （获取时）1：用户输入 0：不是(When retrieving) 1: User input 0: No
@property (nonatomic,assign) NSInteger     isManual;

@end
@interface UTEModelCycleData : NSObject
///固定值：生理期长度 Fixed value: length of physiological period
@property (nonatomic,assign) NSInteger     historyCycleSize;
///固定值：生理期周期 Fixed value: physiological cycle
@property (nonatomic,assign) NSInteger     futureCycleSize;
///设置生理周期数据的发送时间戳（当前时间戳） Set the sending timestamp for physiological cycle data (current timestamp)
@property (nonatomic,assign) NSInteger     modifyTime;
///生理期长度 Physiological period length
@property (nonatomic,assign) NSInteger     manualMenstrualDays;
///生理期周期 Physiological cycle
@property (nonatomic,assign) NSInteger     manualCycleDays;
///生理期具体信息数据 Physiological period specific information data
@property (nonatomic,strong) NSMutableArray<UTEModelMenstrualData *>       *menstrualDataList;


@end

@interface UTEModelCycleBloodVolume : NSObject

///时间戳 timestamp
@property (nonatomic,assign) NSInteger     timestamp;
///血量范围 0：无血量 1：少量 2：中等 3：大量 Blood volume range 0: no blood volume 1: small amount 2: moderate 3: large amount
@property (nonatomic,assign) NSInteger type;

@end


@interface UTEMgrPhysiologicalCycle : NSObject

/**50.1 设置女性生理周期开关
 Set female physiological cycle switch
 
 @parma status
 0：关闭 0x01|0x02|0x04|0x08|0x10：全开启（建议）
 0: Close, 0x01|0x02|0x04|0x08|0x10: Fully open(Suggestion)
 
 必须设置0x01 0x01 must be set
 
 比如NSInteger state = 0x01|0x02|0x04|0x08|0x10;全开启
 e.g. Fully open
 
 比如NSInteger state = 0x01|0x02;激活开关+经期开始提醒开启
 e.g. Activate switch+menstrual reminder on
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setMenstrualNotifyAbility:(NSInteger)status block:(void(^)(NSInteger errorCode,NSDictionary *uteDict))block;

/**50.2 监听手环生理周期修改时间请求 通知固定 ID 12802
 Request for monitoring the physiological cycle modification time of the bracelet
 
 监听到发送当前时间给手环，调用setPhysiologicalTime
 Listens to sending the current time to the bracelet and calls setPhysiologicalTime
 */
- (void)onNotifyPhysiological:(void(^)(NSDictionary *uteDict))block;

/** 设置生理周期修改时间
 Set physiological cycle modification time
 
 @parma time
 时间戳
 time stamp
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setPhysiologicalTime:(NSInteger)time block:(void(^)(NSInteger errorCode,NSDictionary *uteDict))block;

/**50.3 监听手环生理周期请求 通知固定 ID 12803
 Monitor bracelet physiological cycle requests
 
 监听到发送生理周期数据给手环，调用setCycle
 Listening for sending physiological cycle data to the bracelet, calling setCycle
 */
- (void)onNotifyCycle:(void(^)(UTEModelCycleData *model,NSDictionary *uteDict))block;

//设置女性生理周期数据
- (void)setCycle:(NSDictionary *)dict block:(void(^)(NSInteger errorCode,NSDictionary *uteDict))block;

/** 设置女性生理周期数据
 Setting Female Physiological Cycle Data
 
 @parma cycleModel
 参考UTEModelCycleData 注释
 Refer to UTEModelCycleData annotation
 
 //开始时间戳
 Start timestamp
 以下是例子时间，自行修改真实设置生理周期开始时间（按开始天的00:00开始转时间戳）
 The following is an example time, modify the actual setting of the physiological cycle start time (according to the timestamp from 00:00 on the start day)
 NSTimeInterval startTimeStamp = [[NSDate date] timeIntervalSince1970];
 NSInteger menstrualStartTime = startTimeStamp;
 
 //长度
 Menstrual length
 NSInteger menstrualDays = storageTool.profileModel.menstruationDuration;
 
 //周期
 Menstrual cycle
 NSInteger cycleDays = storageTool.profileModel.menstruationCycle;
 
 //结束时间戳
 End timestamp
 开始时间+长度
 Start time+length
 NSInteger menstrualEndTime = startTimeStamp + menstrualDays * 86400 - 86400;
 
//易孕期开始时间戳
 Easy pregnancy start timestamp
 经期后4天
 4 days after menstruation
 NSInteger easyToPregnantStartTime = menstrualEndTime + 4 * 86400 - 86400;
 
//易孕期结束时间戳
 End timestamp of easy pregnancy period
 共10天
 10 days in total
 NSInteger easyToPregnantEndTime = easyToPregnantStartTime + 10 * 86400 - 86400;
 
 发送数据时间戳（写当前时间戳）
 Send data timestamp (write current timestamp)
 NSInteger modifyTime = [[NSDate date] timeIntervalSince1970];
 
 UTEModelCycleData *cycleModel = [UTEModelCycleData new];
 cycleModel.historyCycleSize = menstrualDays;
 cycleModel.futureCycleSize = cycleDays;
 cycleModel.modifyTime = modifyTime;
 cycleModel.menstrualDays = menstrualDays;
 cycleModel.manualCycleDays = cycleDays;
 
 UTEModelMenstrualData *listModel = [UTEModelMenstrualData new];
 listModel.menstrualStartTime = menstrualStartTime;
 listModel.menstrualEndTime = menstrualEndTime;
 listModel.easyToPregnantStartTime = easyToPregnantStartTime;
 listModel.easyToPregnantEndTime = easyToPregnantEndTime;
 listModel.cycleDays = cycleDays;
 listModel.isManual = 1;
 
 cycleModel.menstrualDataList = @[listModel];
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setCycleModel:(UTEModelCycleData *)cycleModel block:(void(^)(NSInteger errorCode,NSDictionary *uteDict))block;


//50.4
- (void)notifyDeviceRefreshData:(void(^)(NSInteger errorCode,NSDictionary *uteDict))block;

//50.5
- (void)setMenstrualCapability:(NSInteger)capability block:(void(^)(NSInteger errorCode,NSDictionary *uteDict))block;
///主动让设备发通知
- (void)getnotify:(NSInteger)dd;

/** 获取生理周期开关状态
 get Physiological cycle switch status
 
 @parma UTEModelMenstrualSwitch
 参考UTEModelMenstrualSwitch 注释
 Refer to UTEModelMenstrualSwitch annotation
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)getPhysiologicalCycleSwitchBlock:(void(^)(NSInteger errorCode,UTEModelMenstrualSwitch* model))block;

/** 监听生理周期开关状态
 notify Physiological cycle switch status
 
 @parma UTEModelMenstrualSwitch
 参考UTEModelMenstrualSwitch 注释
 Refer to UTEModelMenstrualSwitch annotation
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)onNotifyPhysiologicalCycleSwitchBlock:(void(^)(NSInteger errorCode,UTEModelMenstrualSwitch *model))block;

/** 获取生理周期数据
 get Physiological cycle data
 
 @parma UTEModelCycleData
 参考UTEModelCycleData 注释
 Refer to UTEModelCycleData annotation
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)getPhysiologicalCycleDataBlock:(void(^)(NSInteger errorCode,UTEModelCycleData* model))block;

/** 监听生理周期数据
 notify Physiological cycle data
 
 @parma UTEModelCycleData
 参考UTEModelCycleData 注释
 Refer to UTEModelCycleData annotation
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)onNotifyPhysiologicalCycleDataBlock:(void(^)(NSInteger errorCode,UTEModelCycleData *model))block;

/** 设置生理周期血量
 get Physiological cycle Blood Volume
 
 @parma UTEModelCycleBloodVolume
 参考UTEModelCycleBloodVolume 注释
 Refer to UTEModelCycleBloodVolume annotation
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setPhysiologicalCycleBloodVolume:(UTEModelCycleBloodVolume *)model Block:(void(^)(NSInteger errorCode))block;

/** 获取生理周期血量
 get Physiological cycle Blood Volume
 
 @parma UTEModelCycleBloodVolume
 参考UTEModelCycleBloodVolume 注释
 Refer to UTEModelCycleBloodVolume annotation
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)getPhysiologicalCycleBloodVolumeBlock:(void(^)(NSInteger errorCode,NSArray <UTEModelCycleBloodVolume*>* array))block;

/** 监听生理周期血量
 notify Physiological cycle Blood Volume
 
 @parma UTEModelCycleBloodVolume
 参考UTEModelCycleBloodVolume 注释
 Refer to UTEModelCycleBloodVolume annotation
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)onNotifyPhysiologicalCycleBloodVolumeBlock:(void(^)(NSInteger errorCode,NSArray <UTEModelCycleBloodVolume*>* array))block;


#pragma mark - Tool
/**
 *  @discussion Physiological type of each day in a cycle
 *
 *  @param  model See UTEModelMenstruationInfo
 *
 *  e.g.
 *  model.firstTime = @"2022-10-01"
 *  model.duration = 7
 *  model.cycle = 28
 *  Array returns data from No. 1 to No. 28
 *
 *  If the parameter is incorrect, the returned data is nil
 */
- (NSArray<UTEModelMenstruationCycle *> *)getPhysiologicalFemaleCycle:(UTEModelMenstruationInfo *)model;

@end


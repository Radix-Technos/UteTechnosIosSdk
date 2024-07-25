//
//  UTEDevicePhysiologicalCycle.h
//  UTEBluetoothRYApi
//
//  Created by V V on 2023/3/28.
//  Copyright © 2023 vv. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, UTEAbilityType) {
    UTEAbilityTypeAllBtn                    = 0x01,
    UTEAbilityTypeMenstrualStartBtn         = 0x02,
    UTEAbilityTypeMenstrualEndBtn           = 0x04,
    UTEAbilityTypePregnancyStartBtn         = 0x08,
    UTEAbilityTypePregnancyEndBtn           = 0x10,
};

@interface UTEModelMenstrualNotifyAbility : NSObject

@property (nonatomic,assign) UTEAbilityType     abilityType;
@property (nonatomic,assign) BOOL               enable;

@end


@interface UTEModelMenstrualData : NSObject
///开始时间戳
@property (nonatomic,assign) NSInteger     menstrualStartTime;
///结束时间戳（开始时间+长度）
@property (nonatomic,assign) NSInteger     menstrualEndTime;
///易孕期开始时间戳 （经期后4天）
@property (nonatomic,assign) NSInteger     easyToPregnantStartTime;
///易孕期结束时间戳 （共10天）
@property (nonatomic,assign) NSInteger     easyToPregnantEndTime;
///生理期周期
@property (nonatomic,assign) NSInteger     cycleDays;
///固定值1
@property (nonatomic,assign) NSInteger     isManual;

@end
@interface UTEModelCycleData : NSObject
///固定值：生理期长度
@property (nonatomic,assign) NSInteger     historyCycleSize;
///固定值：生理期周期
@property (nonatomic,assign) NSInteger     futureCycleSize;
///设置生理周期数据的发送时间戳（当前时间戳）
@property (nonatomic,assign) NSInteger     modifyTime;
///生理期长度
@property (nonatomic,assign) NSInteger     manualMenstrualDays;
///生理期周期
@property (nonatomic,assign) NSInteger     manualCycleDays;
///生理期具体信息数据
@property (nonatomic,strong) NSMutableArray<UTEModelMenstrualData *>       *menstrualDataList;


@end


@interface UTEMgrPhysiologicalCycle : NSObject

/**50.1 设置女性生理周期开关
 Set female physiological cycle switch
 
 @parma status
 0：关闭 固定值31：全开启
 0: Close, fixed value 31: Fully open
 
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
 
 //长度
 Menstrual length
 NSInteger menstrualDays = storageTool.profileModel.menstruationDuration;
 
 //周期
 Menstrual cycle
 NSInteger cycleDays = storageTool.profileModel.menstruationCycle;
 
 NSInteger menstrualStartTime = startTimeStamp;
 
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
 cycleModel.cycleDays = cycleDays;
 
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
@end


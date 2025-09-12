//
//  UTEMgrPlanCourse.h
//  UTEBluetoothRYApi
//
//  Created by ute1205 on 2025/5/7.
//  Copyright © 2025 vv. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UTEModelDevice.h"

NS_ASSUME_NONNULL_BEGIN

@interface UTEMgrPlanCourse : NSObject

///查询训练计划数量，训练计划文件索引大小等参数
-(void)checkPlanInfoBlock:(void(^)(NSMutableArray <UTEModelPlanInfo*>*array,NSInteger errorCode))block;

///查询课程模版文件数量，课程模版文件索引大小等参数
-(void)checkCourseInfoBlock:(void(^)(NSMutableArray <UTEModelCourseInfo*>*array,NSInteger errorCode))block;

///通过索引查询文件内容，index索引(目前都写0)，type：0计划，1课程  返回array计划是UTEPlanListModel，课程是UTECourseListModel
-(void)checkInfoFromIndex:(NSInteger)index WithType:(NSInteger)type Block:(void(^)(NSMutableArray *array,NSInteger errorCode))block;

///查询训练计划设置的提醒状态，state:0关闭，1开启 time：秒值 （例如8点10分的秒值29400）
-(void)checkPlanReminderTimeBlock:(void(^)(NSInteger state,NSInteger time,NSInteger errorCode))block;

///设置训练计划设置的提醒状态，state:0关闭，1开启 time：秒值（例如8点10分的秒值29400）
-(void)setPlanReminderTime:(NSInteger)state WithTime:(NSInteger)time Block:(void(^)(NSInteger errorCode))block;

///删除一个训练计划文件或者课程，index索引(目前都写0)，type:0计划 1课程 注意删除课程文件会把所有课程模版都删除的
-(void)deleteInfoFromIndex:(NSInteger)index WithType:(NSInteger)type Block:(void(^)(NSInteger errorCode))block;

///设置计划文件参数  index索引(目前都写0) 收到成功后调用sendPlanDataToBleBlock接口，修改计划也是重新下发
-(void)setPlanInfo:(UTEPlanListModel *)model withIndex:(NSInteger)index Block:(void(^)(NSInteger errorCode))block;

///设置课程文件参数 index索引(目前都写0) 收到成功后调用sendPlanDataToBleBlock接口，设置/删除单个课程内容都是该接口，先从checkInfoFromIndex查询课程文件拿到每个课程，当修改和删除(删掉对应数据)需要重新下发，相当于覆盖
-(void)setCourseInfo:(NSMutableArray<UTECourseListModel*>*)modelArray withIndex:(NSInteger)index Block:(void(^)(NSInteger errorCode))block;

///发送计划数据/课程数据 收到设置计划文件成功/课程文件成功后调用该接口
-(void)sendPlanDataToBleBlock:(void(^)(CGFloat process,BOOL isSuccess ,NSInteger errorCode))block;

@end

NS_ASSUME_NONNULL_END

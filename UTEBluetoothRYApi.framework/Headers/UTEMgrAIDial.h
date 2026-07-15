//
//  UTEMgrAIDial.h
//  UTEBluetoothRYApi
//
//  Created by ute1205 on 2024/7/29.
//  Copyright © 2024 vv. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UTEBluetoothEnum.h"

NS_ASSUME_NONNULL_BEGIN

@interface UTEMgrAIDial : NSObject

///设置AI表盘语音内容
-(void)setAIVoiceContent:(NSString *)text Block:(void(^)(NSInteger errorCode))block;

///APP设置状态
-(void)setAPPAIStatus:(UTEAIDialStatus)status Block:(void(^)(NSInteger errorCode))block;

///设备上报状态
- (void)onNotifyAIStatus:(void(^)(UTEAIDialStatus status))block;

///设备上传录音数据，格式为opus
- (void)onNotifyAIVoiceData:(void(^)(NSInteger errorCode,NSData *opus))block;

///设备上传实时录音数据，格式为opus，isCompleted=YES 表示数据传输完成 支持实时上报时onNotifyChatGPTVoiceData不会再结束录音上报数据了
- (void)onNotifyAIDialUploadVoiceDataBlock:(void(^)(BOOL isCompleted,NSData *opus))block;

///设备上报开始生成 1:开始生成 （目前废弃了）
//- (void)onNotifyAIStartGenerating:(void(^)(NSInteger status))block;

///查询AI表盘功能开关 state 0：关， 1：开
-(void)getAIDialFuntionStateBlock:(void(^)(NSInteger errorCode, NSInteger state))block;

///设置AI表盘功能开关 state 0：关， 1：开
-(void)setAIDialFuntionState:(NSInteger)state Block:(void(^)(NSInteger errorCode))block;

@end

NS_ASSUME_NONNULL_END

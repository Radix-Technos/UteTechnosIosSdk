//
//  UTERYMgrChatGPT.h
//  UTEBluetoothRYApi
//
//  Created by ute1205 on 2024/7/29.
//  Copyright © 2024 vv. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UTEDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface UTERYModelChatGPTMemorandumInfo : NSObject
///时间戳
@property (nonatomic,assign) NSInteger              timeStamp;
///识别内容
@property (nonatomic,assign) NSString               *identifyContent;
///回答内容
@property (nonatomic,copy) NSString                 *answerContent;

@end


@interface UTERYMgrChatGPT : NSObject

+ (instancetype) sharedInstance;

///APP设置状态
-(void)setAPPChatGPTStatus:(UTEChatGPTType)status Block:(void(^)(NSInteger errorCode))block;

///设置ChatGPT识别语音内容
-(void)setChatGPTVoiceContent:(NSString *)text Block:(void(^)(NSInteger errorCode))block;

///设置ChatGPT回答内容
-(void)setChatGPTAnswerContent:(NSString *)text Block:(void(^)(NSInteger errorCode))block;

///同步备忘录内容
-(void)setChatGPTMemorandumContent:(NSArray <UTERYModelChatGPTMemorandumInfo *>*)array Block:(void(^)(NSInteger errorCode))block;

///设备上报状态
- (void)onNotifyChatGPTStatus:(void(^)(UTEChatGPTType status))block;

///设备上传录音数据，格式为opus
- (void)onNotifyChatGPTVoiceData:(void(^)(NSInteger errorCode,NSData *opus))block;

@end

NS_ASSUME_NONNULL_END

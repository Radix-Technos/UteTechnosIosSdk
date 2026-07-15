//
//  UTEMgrChatGPT.h
//  UTEBluetoothRYApi
//
//  Created by ute1205 on 2024/7/29.
//  Copyright © 2024 vv. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UTEBluetoothEnum.h"


NS_ASSUME_NONNULL_BEGIN

@interface UTEModelChatGPTMemorandumInfo : NSObject
///时间戳
@property (nonatomic,assign) NSInteger              timeStamp;
///识别内容
@property (nonatomic,assign) NSString               *identifyContent;
///回答内容
@property (nonatomic,copy) NSString                 *answerContent;

@end

@interface UTEModelIntelligentAgentType : NSObject
///类型
@property (nonatomic,assign) UTEIntelligentAgentType       type;

@end

@interface UTEModelAILargeModelType : NSObject
///类型
@property (nonatomic,assign) UTEAILargeModelType       type;

@end


@interface UTEMgrChatGPT : NSObject

///APP设置状态
-(void)setAPPChatGPTStatus:(UTEChatGPTStatus)status Block:(void(^)(NSInteger errorCode))block;

///设置ChatGPT识别语音内容
-(void)setChatGPTVoiceContent:(NSString *)text Block:(void(^)(NSInteger errorCode))block;

///设置ChatGPT回答内容 需要先获取getAIQAWordCountBlock，NSData *textData = [self.sendTotalText dataUsingEncoding:NSUTF16BigEndianStringEncoding]; 计算好text转Unicode NSData长度不能超过上报值的内容
-(void)setChatGPTAnswerContent:(NSString *)text Block:(void(^)(NSInteger errorCode))block;

///同步备忘录内容
-(void)setChatGPTMemorandumContent:(NSArray <UTEModelChatGPTMemorandumInfo *>*)array Block:(void(^)(NSInteger errorCode))block;

///设备上报状态
- (void)onNotifyChatGPTStatus:(void(^)(UTEChatGPTStatus status))block;

///设备上传录音数据，格式为opus
- (void)onNotifyChatGPTVoiceData:(void(^)(NSInteger errorCode,NSData *opus))block;

///设备实时上传录音数据，格式为opus,isCompleted=YES 表示数据传输完成 支持实时上报时onNotifyChatGPTVoiceData不会再结束录音上报数据了
-(void)onNotifyUploadVoiceDataBlock:(void(^)(BOOL isCompleted,NSData *opus))block;

///设置当前ai语言环境 0:中文 1:英文
-(void)setAICurrentLanguage:(NSInteger)language Block:(void(^)(NSInteger errorCode))block;

///设置当前智能体支持类型
-(void)setIntelligentAgentType:(NSArray <UTEModelIntelligentAgentType *>*)array Block:(void(^)(NSInteger errorCode))block;

///同步智能体内容 复用备忘录模型
-(void)setIntelligentAgentContent:(NSArray <UTEModelChatGPTMemorandumInfo *>*)array Block:(void(^)(NSInteger errorCode))block;

/*设备上报智能体类型
 dataType -1无模型不处理 0x00豆包 0x01DeepSeek 0x02智谱 0x03文心一言 0x04通义千问 0x05火星 0x06Kimi
 */
- (void)onNotifyIntelligentAgentType:(void(^)(NSInteger errorCode,NSArray <UTEModelIntelligentAgentType *>*array,UTEModelAILargeModelType *dataType))block;

///上报currentLanguage翻译前语言id，translateLanguage翻译后语言id（开始录音状态前上报，id参考手表支持多国语言）
- (void)onNotifyTranslateLanguage:(void(^)(UTERYDeviceLanguage currentLanguage,UTERYDeviceLanguage translateLanguage))block;

///上报APP开始播放翻译结果 1：播放
-(void)onNotifyPlayTranslateResults:(void(^)(NSInteger state))block;

///设置支持AI大模型类型 0x00豆包 0x01DeepSeek 0x02智谱 0x03文心一言 0x04通义千问 0x05火星 0x06Kimi
-(void)setAILargeModelType:(NSArray <UTEModelAILargeModelType *>*)array Block:(void(^)(NSInteger errorCode))block;

///查询ChatGPT功能开关 state 0：关， 1：开
-(void)getAIFuntionStateBlock:(void(^)(NSInteger errorCode, NSInteger state))block;

///设置ChatGPT功能开关 state 0：关， 1：开
-(void)setAIFuntionState:(NSInteger)state Block:(void(^)(NSInteger errorCode))block;

///查询支持问答字数长度 length：字节长度
-(void)getAIQAWordCountBlock:(void(^)(NSInteger errorCode, NSInteger length))block;

///查询支持备忘录条数和内容长度 number：条数 length：内容字节长度
-(void)getAIMemoWordCountBlock:(void(^)(NSInteger errorCode, NSInteger number,NSInteger length))block;


@end

NS_ASSUME_NONNULL_END

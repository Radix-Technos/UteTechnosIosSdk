//
//  UTEMgrAlipay.h
//  UTEBluetoothRYApi
//
//  Created by ute1205 on 2025/3/31.
//  Copyright © 2025 vv. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UTEBluetoothEnum.h"


NS_ASSUME_NONNULL_BEGIN

@interface UTEMgrAlipay : NSObject

///开始alipay 根据type来处理dic
-(void)alipayCodeStartBlock:(void(^)(NSInteger errorCode))block;
///监听操作处理
- (void)onNotifyAlipayCode:(void(^)(NSDictionary *dic,UTEALICMD Type))block;

- (void)getWebDataRes:(NSInteger)portId isSuccess:(BOOL)isSuccess;
- (void)sendSuccess:(NSInteger)portId msgLen:(NSInteger)msgLen;
- (void)getData:(NSInteger)portId;

- (void)beginSendDataToBT:(NSData *)data sendDataPortID:(NSInteger)sendDataPortID;
- (void)getData:(NSInteger)portId allDataSize:(NSInteger)allDataSize curNum:(NSInteger)curNum curData:(NSData *)curData dataLen:(NSInteger)dataLen;
- (void)close:(NSInteger)portId isSuccess:(BOOL)isSuccess;


@end

NS_ASSUME_NONNULL_END

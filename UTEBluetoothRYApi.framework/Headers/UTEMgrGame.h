//
//  UTEMgrGame.h
//  UTEBluetoothRYApi
//
//  Created by ute1205 on 2024/3/1.
//  Copyright © 2024 vv. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UTEModelDevice.h"

NS_ASSUME_NONNULL_BEGIN

@interface UTEMgrGame : NSObject

///开始/结束游戏 status:1开始 0结束
-(void)sendGameStatus:(NSInteger)status Block:(void(^)(NSInteger errorCode))block;

///监听ble 操作
-(void)onNotifyGameOperateBlock:(void(^)(NSInteger errorCode,NSArray<UTEModelGameOperate *> *arrayModels))block;

@end

NS_ASSUME_NONNULL_END

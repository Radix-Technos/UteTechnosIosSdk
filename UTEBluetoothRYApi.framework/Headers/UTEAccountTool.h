//
//  UTEAccountTool.h
//  UTEBluetoothRYApi
//
//  Created by V V on 2023/4/5.
//  Copyright © 2023 vv. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface UTEAccountTool : NSObject

/**60.3
 @parma account
 如果app有账号管理，以自己app登录后的账号id下发给手环
 If the app has account management, issue the bracelet with the account ID after logging in to the app
 如果没有，自己保存/读取UUID到钥匙串已此下发给手环
 If not, save/read the UUID on your own until the keychain has been distributed to the bracelet
 或者自行定义id下发给手环，这个账号id看开发者定义获取
 Alternatively, you can define your own ID and send it to the bracelet. This account ID can be obtained based on the developer's definition
 
 
 @block result
 0:帐号一致 1:帐号不一致 2:无帐号
 0: Account consistency 1: Account inconsistency 2: No account
 
 @账号一致或者无账号，则通过连接
 If the account is consistent or there is no account, connect
 
 判断连接成功过后等待6秒钟后必须调用通话蓝牙配对，否则通话蓝牙无法开启配对
 After determining the successful connection, call Bluetooth pairing must be called, otherwise call Bluetooth pairing cannot be enabled
 
 [[UTEDeviceMgr sharedInstance] setBT3Pair:[[StorageTool sharedInstance].bluePairModel.btPairID integerValue] Block:^(NSInteger errorCode) {
     if(errorCode == UTEDeviceErrorNil){
         VVLog(@"开启BT3.0配对成功");
        //然后再调用
        //Then call again
         [[UTEDeviceMgr sharedInstance] setBT3Info:1 Block:nil];
         
     }else{
         VVLog(@"开启BT3.0配对失败");

     }
 }];
 
 @帐号不一致调用断开手环蓝牙接口
 Account inconsistency calls disconnect the Bluetooth interface of the bracelet
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)phoneSendWatchAccountWith:(NSString *)account block:(void(^)(NSInteger result,NSInteger errorCode,NSDictionary *uteDict))block;

//60.4 通知ID 固定 15364   result 0:确认恢复出厂设置 1:取消配对
- (void)onNotifySelect:(void(^)(NSInteger result,NSDictionary *uteDict))block;

// App -> ble pair:YES 用户确认配对，NO 取消配对 最新逻辑调这个，绑定新设备连接上发1
- (void)notifyDevicePair:(BOOL)pair block:(void(^)(BOOL blePair,NSInteger errorCode))block;
// ble -> App pair:YES 用户确认配对或链接成功，NO 取消配对
- (void)onNotifyAppPair:(void(^)(BOOL pair))block;

/** APP解除绑定设备 注意不连接不能解绑 2023/06/21新增
 App unbinding device
 Note: Unbinding without connection is not possible

 @param type
 0断开，1解绑，2未知
 0 disconnected, 1 unbound, 2 unknown;

 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
*/
- (void)UnboundType:(NSInteger)type Block:(void(^)(NSInteger errorCode ,NSDictionary *uteDict))block;

@end



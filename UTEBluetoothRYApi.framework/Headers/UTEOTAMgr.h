//
//  UTEOTAMgr.h
//  UTEBluetoothRYApi
//
//  Created by V V on 2023/3/9.
//  Copyright © 2023 vv. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "UTEOTADelegate.h"
#import "UTEModelDevice.h"

@interface UTEOTAMgr : NSObject

@property(nonatomic, assign) BOOL           isUpdating;
@property (nonatomic,weak  ) id<UTEOTADelegate> delegate;
@property(nonatomic, assign) BOOL           isUpdateStatusAC7012x;

+ (instancetype) sharedInstance;

///1.1001 原厂通道BetaLog 暂停使用2023-06-02
//- (void)downloadBetaLogFiles:(void (^)(NSString *uuid,NSString *filePath,NSInteger errorCode,BOOL success))callback NS_DEPRECATED_IOS(2_0,9_0, "暂停使用,请用新的来获取日志getBetaLogFiles");

///1.1001 LOG 2023-06-02 type 0:全部文件下载 1:betaLog 2:beforeLog 3:afterLog
//- (void)downloadBetaLogFiles:(NSInteger)type callback:(void(^)(NSInteger logType,CGFloat process,BOOL isSuccess ,NSInteger errorCode ,NSString *filePath,NSDictionary *uteDict))block;

///1.1001 2023-06-10 LOG. filePathDic参数 type 1:betaLog 2:beforeLog 3:afterLog. filePath  完整路径的文件名（带后缀）保存格式为txt NSDictionary *dic = @{@"type":@1,@"filePath":filePath};
- (void)downloadBetaLogFiles:(NSDictionary *)filePathDic callback:(void(^)(NSInteger logType,CGFloat process,BOOL isSuccess ,NSInteger errorCode ,NSString *filePath,NSDictionary *uteDict))block;

/////1.1001 原厂死机前Log 2023-06-04
//- (void)downloadBeforeLogFiles:(void (^)(NSString *uuid,NSString *filePath,NSInteger errorCode,BOOL success))callback;
/////1.1001 原厂死机后Log 2023-06-04
//- (void)downloadAfterLogFiles:(void (^)(NSString *uuid,NSString *filePath,NSInteger errorCode,BOOL success))callback;



/**9.1 查询设备是否允许OTA升级
 Check whether the device allows OTA upgrades
 
 @parma version
 升级包软件版本号,比如手环固件AT338V000109，那么发送低版本AT338V000108或者高版本AT338V000110
 Upgrade package software version number, such as AT338V000109
 
 @parma componentSize
 目前写0
 Currently writing 0
 
 @parma mode
 目前写0
 Currently writing 0
 
 @parma abilityList
 目前写nil
 Currently writing nil
 
 @block errorCode
 -803,  //固件版本不一致 Inconsistent firmware version
 109002,//ota传输错误手表电量低 OTA transmission error, watch battery low
 -802,  //设备温度过高 Equipment temperature too high
 -1,    //其他未知不能升级 Other unknown cannot be upgraded
 100000, //允许升级 Allow upgrades
 */
- (void)prepareUpgrade:(NSString *)version
         componentSize:(NSInteger)componentSize
                  mode:(NSInteger)mode
           abilityList:(NSArray *)abilityList
              callback:(void (^)(NSInteger errorCode ,NSDictionary *uteDict))callback;

//9.8 暂停使用2023-06-01，升级过程中不允许暂停，如果收到升级取消的回调，一律视为 升级失败处理。
//- (void)cancelUpgrade:(void (^)(NSInteger errorCode,NSDictionary *uteDict))callback;
//9.1000
- (void)getPackageHeader:(NSData *)file callback:(void (^)(NSInteger errorCode,NSDictionary *uteDict))callback;

/**9.1001 发送OTA升级包数据
 Send OTA upgrade package data
 
 @parma filePath
 完整的沙盒路径，可以传路径 xxxx/xxxx/xxxx.bin 或者  xxxx/xxxx/xxxx.zip  或者 xxxx/xxxx/xxxx.ufw
 The complete sandbox path can be passed to either xxxx/xxxx/xxxx.bin or xxxx/xxxx/xxxx.zip or  xxxx/xxxx/xxxx.ufw
 /var/mobile/Containers/Data/Application/C889C112-FB9D-4D18-9318-D62524B198A0/Documents/Firmware/AT338V000109.bin
 
 @block errorCode,progress
 errorCode:100000,请求成功，其他：失败
 100000 Request succeeded, others: failed
 
 progress:>= 1 升级成功，其他：进度值
 >=1 Successfully upgraded, other: progress values
 
 if(errorCode == 100000){
     if(progress >= 1){
         升级成功
        Upgrade Successful
     }else{
        progress
        升级进度
        Upgrade Progress
     }
 }else{
     升级失败
     Upgrade failed
 }
 */
- (void)upgrade:(NSString *)filePath
       callback:(void (^)(NSString *uuid, CGFloat process,NSInteger errorCode,BOOL success))callback;

//9.14
- (void)notifyNewVersion:(NSString *)versionNumber
                    size:(NSInteger)size
               checkTime:(NSInteger)checkTime
             checkResult:(BOOL)isNew
                   block:(void (^)(NSString *uuid ,NSInteger errorCode))block;
//9.17 通知事件ID 为固定的 2321
- (void)onNotifyOTAConfirmDownload:(void (^)(NSInteger errorCode ,NSDictionary *uteDict))callback;

- (void)checkJLFirmwareFromServer:(UTEModelBaseInfo *)model block:(void(^)(UTEModelOTAInfo *result,BOOL hasNew,NSInteger errCode))block;
- (void)downloadOTAFirmware:(NSString *)url block:(void(^)(NSURL *binURL ,NSInteger errCode))block;


- (void)receiveData:(CBCharacteristic *)cb;
- (void)OTAperipheral:(CBPeripheral *)peripheral service:(CBService *)service array:(NSArray *)arrayChara error:(NSError *)error;
- (BOOL)compareCharacteristic:(CBCharacteristic *)cb;
- (void)clearParams;


@end



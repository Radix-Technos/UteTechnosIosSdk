//
//  UTEMgrAGPS.h
//  UTEBluetoothRYApi
//
//  Created by ute1205 on 2023/12/5.
//  Copyright © 2023 vv. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface UTERYModelAGPSInfo : NSObject
///文件状态下发间隔 单位：秒 File status issuance interval unit: seconds
@property (nonatomic,assign) NSInteger              interval;
///方案版本 0:VERSION_BROADCOM 博通。1:VERSION_SONY 索尼。2:VERSION_AIROHA 洛达。3:VERSION_ICOE 芯与物  Plan version 0:VERSION_BROADCOM。1:VERSION_SONY 。2:VERSION_AIROHA 。3:VERSION_ICOE
@property (nonatomic,assign) NSInteger               version;
///要ble需要的文件列表，使用";"隔开 List of files required for ble, separated by ";"
@property (nonatomic,copy) NSString               *fileList;

@end


@interface UTERYMgrAGPS : NSObject

+ (instancetype) sharedInstance;

/**31.1 监听ble星历操作
 Monitor the operation of the ble ephemeris
 
 AGPS ble交互流程：
 1.连接上手环同步数据先发送31.2获取ble所需下发文件名和后台下载文件参数。
 2.通过31.1监听ble星历操作。
 3.调用后台接口下载文件的状态，调用31.3告诉ble
 4.通过31.1监听ble星历操作,调用31.10000发送数据给ble
 
 AGPS ble interaction process:
 1. Connect the wristband to synchronize data. First, send 31.2 to obtain the file name and background download file parameters required for BLE.
 2. Listen to the ble ephemeris operation through 31.1.
 3. Call the backend interface to download the status of the file, and call 31.3 to inform ble
 4. Listen to the ble ephemeris operation through 31.1 and call 31.10000 to send data to ble
 
 @block status
 操作状态
 1:APP收到当前指令后，通过31.1000 下发星历文件
 2:查询星历文件准备状态,APP收到当前指令后，通过31.3下发星历文件状态
 Operation status
 1: After receiving the current command, the APP issues the ephemeris file through 31.1000
 2: Query the preparation status of the ephemeris file. After receiving the current command, the APP will issue the ephemeris file status through 31.3
 
 @block errorCode
 请求成功:0   其他:错误码
 Request successful: 0    Other: Error code
 */
-(void)onNotifyAGPS:(void(^)(NSInteger status))block;

/**31.2 星历协商参数
 Calendar negotiation parameters
 
 注意：连接上手环同步数据后，调用该接口提前获取到信息，再调用后台接口下载好文件到沙盒准备好
 Note: After connecting the bracelet synchronization data, call this interface to obtain information in advance, and then call the background interface to download the file to the sandbox
 
 @block model
 参考UTEModelAGPSInfo注释
 Refer to the UTEModelAGPSInfo annotation
 
 @block errorCode
 请求成功:0    其他:错误码
 Request successful: 0    Other: Error code
 */
-(void)sendAGPSInfoBlock:(void(^)(UTERYModelAGPSInfo *model,NSInteger errorCode))block;

/**31.3 下发星历文件准备状态
 Preparation status for issuing ephemeris files
 
 @parma status
 1：未开始下载 2：下载中 3：下载完成 4：下载失败  5：APP不支持
 1: Download not started 2: Download in progress 3: Download completed 4: Download failed 5: APP not supported
 
 @block errorCode
 请求成功:0   其他:错误码
 Request successful: 0    Other: Error code
 */
-(void)sendAGPSFileStatus:(NSInteger)status Block:(void(^)(NSInteger errorCode))block;

/**31.10000 APP下发星历文件给BLE
 APP distributes ephemeris files to BLE
 
 根据31.2 ble上报的文件数，调用后台接口下载好文件保存到沙盒后，重新获取沙盒路径和文件名发送给ble
 According to the number of files reported by 31.2 ble, after calling the backend interface to download and save the files to the sandbox, retrieve the sandbox path and file name again and send them to ble
 
 NSMutableArray *fileArray = [[NSMutableArray alloc] init];
 filePath：下载的AGPS文件的沙盒地址
 name:文件名
 NSDictionary *dic = @{@"filePath":filePath,
                       @"fileName":name
 };
 
 [fileArray addObject:dic];
 
 if (errorCode == UTEDeviceErrorNil) {
     if (isSuccess) {
        成功
        success
     } else {
        进度
        process
     }
 } else {
     失败
     fail
 }
 */
- (void)sendAGPSFileDataToBLE:(NSArray *)fileArray block:(void(^)(NSString *uuid, CGFloat process,BOOL isSuccess ,NSInteger errorCode))block;

@end

NS_ASSUME_NONNULL_END

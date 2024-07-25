//
//  UTEDeviceDial.h
//  UTEBluetoothRYApi
//
//  Created by V V on 2023/3/28.
//  Copyright © 2023 vv. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "UTEBluetoothEnum.h"
#import "UTEModelWatch.h"

@interface UTEMgrDial : NSObject

/**39.1 获取设备表盘参数
 Obtain device dial parameters
 
 @block model
 参考UTEModelWatchFaceParams注释
 Refer to UTEModelWatchFaceParams comments
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)getWatchFaceParams:(void(^)(UTEModelWatchFaceParams *model, NSInteger errorCode ,NSDictionary *uteDict))block;

/**39.2 获取设备表盘列表信息
 Obtain device dial list information
 
 @parma serverMode
 设备表盘列表 固定值1
 List of device dials，Fixed value 1
 
 @block model
 参考UTEModelWatchFace
 Refer to UTEModelWatchFace
 
 @block errorCode
 请求成功:100000 其他:错误码
 */
- (void)getWatchFaceInfo:(NSInteger)serverMode block:(void(^)(NSArray<UTEModelWatchFace *> *model, NSInteger errorCode,NSDictionary *uteDict))block;

/**39.3 应用表盘/删除表盘
 Apply dial/delete dial
 
 @parma ID
 表盘ID
 Dial ID
 
 @parma version
 表盘版本 如1.0.0
 The dial version is 1.0.0
 
 @parma operate
 操作码 1 应用表盘,2 删除表盘 ,3 应用google表盘（不支持）
 Operation code 1: Apply dial, 2: Delete dial, 3: Apply Google dial (not supported)
 */
- (void)applyWatchFace:(NSInteger)ID version:(NSString *)version operate:(NSInteger)operate block:(void(^)(UTEModelWatchFace *model, NSInteger errorCode,NSDictionary *uteDict))block;

/**39.4 表盘排序
 @parma array
 根据获取设备表盘列表信息getWatchFaceInfo的id，必须写完所有表盘的排序
 According to the ID of getWatchFaceInfo obtained from the device dial list information, it is necessary to complete the sorting of all dials
 比如
 for example
 @[@"8361001",@"8454001",@"8429001",@"8448001",@"8428001"]
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)sortWatchFace:(NSArray<NSString *> *)array block:(void(^)(NSInteger errorCode,NSDictionary *uteDict))block;
//39.5 通知固定ID 9989
- (void)onNotifyWatchFace:(void(^)(UTEModelWatchFaceNotify *model,NSDictionary *uteDict))block;

//39.8
- (void)getImageWatchFaceBlock:(void(^)(NSInteger errorCode,NSDictionary *uteDict))block;

/**39.8 获取相片表盘信息
 Obtain photo dial information
 
 @block model
 参考UTEModelWatchFaceImage
 Refer to UTEModelWatchFaceImage
 每次下发相册表盘时候都要获取一次，来查询表盘上限
 Every time the album dial is issued, it is necessary to obtain it once to check the upper limit of the dial
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)getImageWatchFaceModelBlock:(void(^)(UTEModelWatchFaceImage *model,NSInteger errorCode,NSDictionary *uteDict))block;
//39.9 
- (void)setImageWatchFace:(NSDictionary *)dict block:(void(^)(NSInteger errorCode,NSDictionary *uteDict))block;

/**39.9 设置相片表盘信息（推送相册表盘准备）
 Set photo dial information (push album dial preparation)
 
 @block model
 参考UTEModelWatchFaceImage
 Refer to UTEModelWatchFaceImage
 @图片名称长度必须小于或等于20的 英文或数字
 @图片名称必须唯一
 @图片必须是bmp或png
 @The length of the image name must be less than or equal to 20 in English or in numbers
 @The image name must be unique
 @The image must be a BMP or PNG
 
 @block errorCode
 请求成功:100000 其他:错误码
 Request successful: 100000 Other: Error code
 */
- (void)setImageWatchFaceModel:(UTEModelWatchFaceImage *)model block:(void(^)(UTEModelWatchFaceImage *model,NSInteger errorCode,NSDictionary *uteDict))block;

/**40.1 监听相册表盘推送准备 通知固定ID 10241
 Preparation for monitoring album dial push
 
 设置相册表盘时（调用39.9时），如果ble不存在这个图片index ，那么这个方法会回调，告诉App需要先发送图片给ble
 When setting the album dial (when calling 39.9), if the image index does not exist in ble, this method will call back and tell the app to send the image to ble first
 
 根据监听到信息保存name，在推送相册表盘数据需要
 Save the name based on the detected information, and when pushing the album dial data, it is necessary to
 
 if(uteDict){
     VVLog(@"uteDict = %@",uteDict);
     NSDictionary *data = uteDict[@"data"];
     NSString *imageName = data[@"name"];
     if (imageName.length > 0) {
         weakself.RYImageName = imageName;
     }
     
 }
 */
- (void)onNotifyImageWatchFace:(void(^)(NSInteger index,NSDictionary *uteDict))block;

/**39.1000 推送在线表盘文件数据
 Push online dial file data
 
 @parma dict
 字典 填写表盘地址
 Fill in the dial address in the dictionary
 
 filePath 完整路径包括格式XXX/XXX/XXX.bin
 The complete path of filePath includes the format XXX/XXX/XXX.bin
 
 NSDictionary *dict = @{@"filePath":path};
 
 @block errorCode,progress
 errorCode:100000,请求成功，其他：失败
 100000 Request succeeded, others: failed
 
 progress:>= 1 升级成功，其他：进度值
 >=1 Successfully upgraded, other: progress values
 
 if (errorCode == UTEDeviceErrorNil) {
     if (isSuccess) {
         成功
     } else {
        进度
        process
     }
 } else {
     失败
 }
 */
- (void)uploadWatchFace:(NSDictionary *)dict block:(void(^)(NSString *uuid, CGFloat process,BOOL isSuccess ,NSInteger errorCode))block;
- (void)uploadWatchFaceFilePath:(NSString *)filePath block:(void(^)(NSString *uuid, CGFloat process,BOOL isSuccess ,NSInteger errorCode))block;

//39.1001 从ble获取图片
- (void)downloadImageWatchFace:(NSString *)file imageName:(NSString *)imageName block:(void(^)(CGFloat process,BOOL isSuccess ,NSInteger errorCode ,NSString *filePath,NSString *imageName,NSString *uuid))block;

/**39.1002 推送相册表盘文件数据
 Push album and dial file data
 
 @parma list
 根据40.1监听相册表盘推送准备onNotifyImageWatchFace接口获取到的name,和对应name放的相册表盘地址
 40.1监听的name是根据39.9 设置相片表盘信息setImageWatchFaceModel来的
 According to 40.1, listen to the album dial push and prepare the name obtained from the onNotifyImageWatchFace interface, as well as the corresponding album dial address placed by the name
 The name for 40.1 monitoring is based on the setting of the photo dial information setImageWatchFaceModel in 39.9
 take care
 
 注意
 @图片名称长度必须小于或等于20的 英文或数字
 @图片名称必须唯一
 @图片必须是bmp或者png
 @地址是完整的地址包括格式 XXX/XXX/XXX.bmp
 take care
 @The length of the image name must be less than or equal to 20 in English or in numbers
 @The image name must be unique
 @The image must be a BMP or PNG
 @The address is complete, including the format XXX/XXX/XXX.bmp
 
 NSDictionary *dictPath = @{@"fileName":self.RYImageName,@"filePath":filePath};
 NSArray *arr = @[dictPath];
 
 @block errorCode,progress
 errorCode:100000,请求成功，其他：失败
 100000 Request succeeded, others: failed
 
 progress:>= 1 升级成功，其他：进度值
 >=1 Successfully upgraded, other: progress values
 
 if (errorCode == UTEDeviceErrorNil) {
     if (isSuccess) {
         成功
     } else {
        进度
        process
     }
 } else {
     失败
 }
 */
- (void)uploadImageWatchFace:(NSArray *)list block:(void(^)(NSString *uuid, CGFloat process,BOOL isSuccess ,NSInteger errorCode))block;


/**
 *  @discussion Watch Face Manage
 *  Required : connnectModel.platform is UTEDevicePlatformTypeAC7012x
 *
 *  @param model See UTEModelWatchFaceJL
 *
 *   Note1: Operating the Watch Face that what the device has (See readJLWatchFaces:)
 *   Note2: When operate=UTEWatchFaceTypeJLOperateAdd，Please ignore Note1. But the number of additions cannot exceed the maximum capacity of the device
 */
- (void)operateJLWatchFace:(UTEModelWatchFaceJL *)model
                     block:(void(^)( CGFloat process,BOOL isSuccess ,NSInteger errorCode))block;
/**
 *  @discussion Read information from the dial
 *  Required : connnectModel.platform is UTEDevicePlatformTypeAC7012x
 *
 *  arrayList : How many dials does the  device have
 */
- (void)readJLWatchFaces:(void(^)(NSArray<UTEModelWatchFaceJL *> *arrayList, NSInteger errorCode))block;

//- (NSArray<UTEModelDialInfo *> *)getUTECustomDialDefualtInfo:(UTEModelWatchFaceParams *)model;

/**查询息屏表盘支持最大个数
 Query the maximum number of supported breath screen dials
 
 @block max
 支持个数
 Number of supports
 
 @block errorCode,progress
 errorCode:100000,请求成功，其他：失败
 100000 Request succeeded, others: failed
 */
- (void)readRestingScreenSupports:(void(^)(NSInteger max, NSInteger errorCode))block;

/**
 *  @discussion Get Watch From Server
 *
 *  @param sdkkey    Unique Server KEY (Shared with Android)
 *  @param device    see UTEModelWatchServer
 
 *  @param success success
 *  @param failure error
 */
- (void)getWatchFromServer:(NSString *)sdkkey
                    device:(UTEModelWatchServer *)device
                    success:(void (^)(NSArray<UTEModelWatchServer *> *))success
                    failure:(void (^)(NSError *))failure;

/**
 *  @discussion Get  Custom Watch From Server (Replaceable background image)
 *
 *  @param sdkkey    Unique Server KEY (Shared with Android)
 *  @param device    see UTEModelWatchServer
 
 *  @param success success
 *  @param failure error
 */
- (void)getCustomWatchFromServer:(NSString *)sdkkey
                          device:(UTEModelWatchServer *)device
                         success:(void (^)(NSArray<UTEModelCustomWatchServer *> *))success
                         failure:(void (^)(NSError *))failure;

@end


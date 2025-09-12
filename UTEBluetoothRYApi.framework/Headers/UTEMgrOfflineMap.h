//
//  UTEMgrOfflineMap.h
//  UTEBluetoothRYApi
//
//  Created by ute1205 on 2025/3/10.
//  Copyright © 2025 vv. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UTEModelDevice.h"

NS_ASSUME_NONNULL_BEGIN


@interface UTEMgrOfflineMap : NSObject

///获取离线地图授权状态 0通过 1设备未授权
-(void)getOfflineMapAuthorizationStatusBlock:(void(^)(NSInteger status,NSInteger errorCode))block;

///设置离线地图授权码 status 0授权通过 1授权失败
-(void)setOfflineMapAuthorization:(NSString *)originalValue Block:(void(^)(NSInteger status,NSInteger errorCode))block;

///查询device id 用于离线地图授权
-(void)getOfflineMapDeviceIDBlock:(void(^)(NSString *deviceID,NSInteger errorCode))block;

///查询当前存在的所有的地图目录名(列表） array 包括目录名和大小
-(void)getOfflineMapDirectoryNameBlock:(void(^)(NSArray <UTEModelOfflineMapInfo *>*array,NSInteger errorCode))block;

/*查询目录的CRC32值，crc32值是目录下所有文件的路径名和文件内容（文件排列循序按照ansi码大小排序，文件路径名如：nanshan-cm\N22E113\N22E113.db）的crc32用来判断是否需要更新，crc不一致时需要更新，crc值使用通知返回。status=0为成功，正在计算crc
 
 fileName 目录名
 
 **/
-(void)getOfflineMapDirectoryNameCRC32:(NSString *)fileName Block:(void(^)(NSInteger status,NSInteger errorCode))block;

///查询可用剩余空间
-(void)getOfflineMapSizeBlock:(void(^)(NSInteger size,NSInteger errorCode))block;

///监听设备上报目录的CRC32值，大小，目录名
- (void)onNotifyOfflineMapDirectoryNameCRC32:(void(^)(NSInteger crc,NSInteger size,NSString *fileName))block;

///删除地图文件目录以及目录下的所有文件包括文件夹fileName根据查询目录名得到的 status:0成功 1失败
-(void)deleteDirectoryName:(NSString *)fileName Block:(void(^)(NSInteger status,NSInteger errorCode))block;

/** 设置准备要更新的地图文件路径，包括目录，文件名
 
 crc crc32值是目录下所有文件的路径名和文件内容（文件排列循序按照ansi码大小排序，文件路径名如：nanshan-cm\N22E113\N22E113.db）
 
 length 文件夹整个大小
 
 path 文件夹路径（/var/mobile/Containers/Data/Application/0D6062D5-E438-4C6E-8B41-3DE2CB1C4981/Documents/nanshan）
 
 status 0设置成功 1空间不足 2文件系统错误 3参数错误
 
 errorCode:701文件夹或文件为空
 */
-(void)setOfflineMapUpdateFilePath:(NSString *)path Block:(void(^)(NSInteger status,NSInteger errorCode))block;

//-(void)setOfflineMapUpdateFilePath1:(NSString *)path Block:(void(^)(NSInteger status,NSInteger errorCode))block;

/**发送文件内容
 
 filePath 沙盒文件夹地址（发送设置更新地图文件的一样路径）
 /var/mobile/Containers/Data/Application/0D6062D5-E438-4C6E-8B41-3DE2CB1C4981/Documents/nanshan

 errorCode 408是接收超时
 
 */
- (void)sendOfflineMapDataToBLE:(NSString *)filePath block:(void(^)(CGFloat process,BOOL isSuccess ,NSInteger errorCode))block;

//- (void)sendOfflineMapDataToBLE1:(NSString *)filePath block:(void(^)(CGFloat process,BOOL isSuccess ,NSInteger errorCode))block;

-(void)writeToFile:(NSString *)filePath;

@end

NS_ASSUME_NONNULL_END

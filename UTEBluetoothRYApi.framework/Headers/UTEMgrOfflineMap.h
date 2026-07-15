//
// UTEMgrOfflineMap.h
// UTEBluetoothRYApi
//
// Created by ute1205 on 2025/3/10.
// Copyright © 2025 vv. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UTEModelDevice.h"

NS_ASSUME_NONNULL_BEGIN

@interface UTEModelAMapSearchInfo : NSObject

///id
@property (nonatomic,assign) NSInteger    resultId;
///标题 255byte
@property (nonatomic,strong) NSString *title;
///地点名称 255byte
@property (nonatomic,strong) NSString *addressName;
///与当前位置距离 单位：米
@property (nonatomic,assign) NSInteger    distance;
///poi类型 255byte
@property (nonatomic,strong) NSString  *poiType;
///营业时间 开始小时开始分钟 HH:mm
@property (nonatomic,strong) NSString  *startTime;
///营业时间 结束小时结束分钟 HH:mm
@property (nonatomic,strong) NSString  *endTime;
/////步行所需时间 单位：分钟
//@property (nonatomic,assign) NSInteger    walkingTime;
/////骑行（自行车）所需时间 单位：分钟
//@property (nonatomic,assign) NSInteger    bicycleTime;
/////骑行（电动车）所需时间 单位：分钟
//@property (nonatomic,assign) NSInteger    eleTime;
/////驾车所需时间 单位：分钟 （预留）
//@property (nonatomic,assign) NSInteger    drivingTime;

///评分等级数值
@property (nonatomic,assign) NSInteger  rating;
///评论数
@property (nonatomic,assign) NSInteger  commentCount;
///扩展数据（详细地址、公交车、地铁路线等）
@property (nonatomic,assign) NSString  *expand;

@end

@interface UTEMgrOfflineMap : NSObject

/// Get offline map authorization status. 0: Authorized, 1: Device not authorized.
/// 获取离线地图授权状态 0通过 1设备未授权
-(void)getOfflineMapAuthorizationStatusBlock:(void(^)(NSInteger status, NSInteger errorCode))block;

/// Set offline map authorization code. originalValue.type: 0 Pi, 1 AMap. status: 0 Authorization passed, 1 Authorization failed.
/// 设置离线地图授权码originalValue.type:0圆周率 1高德，status 0授权通过 1授权失败
-(void)setOfflineMapAuthorization:(NSString *)originalValue mapType:(NSInteger)type Block:(void(^)(NSInteger status, NSInteger errorCode))block;

/// Query device ID for offline map authorization.
/// 查询device id 用于离线地图授权
-(void)getOfflineMapDeviceIDBlock:(void(^)(NSString *deviceID, NSInteger errorCode))block;

/// Query all existing map directory names (list). Array includes directory names and sizes.
/// 查询当前存在的所有的地图目录名(列表） array 包括目录名和大小
-(void)getOfflineMapDirectoryNameBlock:(void(^)(NSArray<UTEModelOfflineMapInfo *> *array, NSInteger errorCode))block;

/// Query map file storage path.
/// 查询地图文件存储路径
-(void)getOfflineMapFromBLEPathBlock:(void(^)(NSString *path, NSInteger errorCode))block;

/* Query CRC32 value of directory. The CRC32 is calculated based on all file path names and file contents in the directory (sorted by ANSI code, file path example: nanshan-cm\N22E113\N22E113.db), used to determine if an update is needed. If CRC does not match, an update is required. CRC value is returned via notification. status=0 means success, calculating CRC.

fileName Directory name

**/
/// 查询目录的CRC32值，crc32值是目录下所有文件的路径名和文件内容（文件排列循序按照ansi码大小排序，文件路径名如：nanshan-cm\N22E113\N22E113.db）的crc32用来判断是否需要更新，crc不一致时需要更新，crc值使用通知返回。status=0为成功，正在计算crc
-(void)getOfflineMapDirectoryNameCRC32:(NSString *)fileName Block:(void(^)(NSInteger status, NSInteger errorCode))block;

/// Query available free space.
/// 查询可用剩余空间
-(void)getOfflineMapSizeBlock:(void(^)(NSInteger size, NSInteger errorCode))block;

/// Monitor device-reported CRC32 value, size, and directory name.
/// 监听设备上报目录的CRC32值，大小，目录名
-(void)onNotifyOfflineMapDirectoryNameCRC32:(void(^)(NSInteger crc, NSInteger size, NSString *fileName))block;

/// Delete map file directory and all files/subfolders within. fileName is based on the queried directory name. status: 0 Success, 1 Failed.
/// 删除地图文件目录以及目录下的所有文件包括文件夹fileName根据查询目录名得到的 status:0成功 1失败
-(void)deleteDirectoryName:(NSString *)fileName Block:(void(^)(NSInteger status, NSInteger errorCode))block;

/** Set the map file path to be updated, including directory and file name.

crc CRC32 value is calculated based on all file path names and file contents in the directory (sorted by ANSI code, file path example: nanshan-cm\N22E113\N22E113.db).

length Total size of the folder.

path Folder path (/var/mobile/Containers/Data/Application/0D6062D5-E438-4C6E-8B41-3DE2CB1C4981/Documents/nanshan).

status 0 Setting successful, 1 Insufficient space, 2 File system error, 3 Parameter error.

errorCode: 701 Folder or file is empty.
*/
/// 设置准备要更新的地图文件路径，path：沙盒路径到文件目录文件夹。status：0设置成功，1：空间不足，2：文件系统错误，3：参数错误，13：手表打开地图中，设置失败，退出后设置
-(void)setOfflineMapUpdateFilePath:(NSString *)path Block:(void(^)(NSInteger status, NSInteger errorCode))block;

//-(void)setOfflineMapUpdateFilePath1:(NSString *)path Block:(void(^)(NSInteger status,NSInteger errorCode))block;

/** Send file content.

filePath Sandbox folder address (same path as set for map file update).
/var/mobile/Containers/Data/Application/0D6062D5-E438-4C6E-8B41-3DE2CB1C4981/Documents/nanshan

errorCode 408 indicates receive timeout.

*/
/// 发送文件内容
-(void)sendOfflineMapDataToBLE:(NSString *)filePath block:(void(^)(CGFloat process, BOOL isSuccess, NSInteger errorCode))block;
//- (void)sendOfflineMapDataToBLE1:(NSString *)filePath block:(void(^)(CGFloat process,BOOL isSuccess ,NSInteger errorCode))block;

-(void)writeToFile:(NSString *)filePath;

/// Query map service provider. type: 0 Pi, 1 AMap.
/// 查询地图服务商 type：0圆周率 1高德
-(void)checkMapServiceProvider:(void(^)(NSInteger type, NSInteger errorCode))block;

/// Set AMap license (reserved, may be called later together with sending authorization code).
/// 设置高德license （预留 后期需要用发送授权码同时调用该接口下发）
-(void)setAMapLicense:(NSString *)license Block:(void(^)(NSInteger errorCode))block;


/**请求服务器高德鉴权
 
 UTEServerAMAPLicenseModel *model = [UTEServerAMAPLicenseModel new];
 /// 参数参考 具体替换对应自己的
     model.appkey = @"填自己的appkey";
     model.btname = @"ATS328SF";
     model.bluetooth_name = @"UTE WATCH PRO";
     model.mac = @"7802b75bfc37";
     
     model.area = @"mainland";
     model.platform = @"rtos";
     model.type = @"raster";
     model.country = @"cn";
     model.reset = @"0";
 
 */
- (void)getUTEServerAMAPLicense:(UTEServerAMAPLicenseModel *)model
                          block:(void(^)(NSDictionary *dic, NSError *error))block;

///获取服务器高德地图信息
- (void)getUTEServerAMAPFile:(UTEServerAMAPPostModel *)model
                       block:(void(^)(NSDictionary *dic, NSError *error))block;


/// MARK: 高德地图在线导航相关接口

///设置同步常去地点 array：最多5个地点，地点长度100byte,sdk内部已做切割
-(void)setFrequentLocations:(NSArray <NSString*>*)array Block:(void(^)(NSInteger errorCode))block;

///设置同步搜索结果状态 state：0准备发送数据APP发送，1准备完成固件返回 2当前一组数据处理完成 3校验不通过
-(void)setSearchResultStatus:(NSInteger)state Block:(void(^)(NSInteger errorCode,NSInteger status))block;

///设置同步搜索结果
-(void)setSearchResult:(UTEModelAMapSearchInfo *)model Block:(void(^)(NSInteger errorCode))block;

///下发路径规划信息 距离和时长 （监听到通知选择导航的id以及出行方式调用）
-(void)setAMapPathData:(NSInteger)distance Duration:(NSInteger)duration Block:(void(^)(NSInteger errorCode))block;

///导航数据透传
-(void)setAMapNaviData:(NSData *)naviData Block:(void(^)(NSInteger errorCode))block;

///通知导航搜索类型 type:1语音搜索（content无数据，监听录音上报） 2POI搜索 3目的地搜索
- (void)onNotifySearchTypeBlock:(void(^)(NSInteger type,NSString *content))block;

///通知选择导航的id以及出行方式 naviId：与下发搜索id一致 type：1驾车（预留） 2骑行（自行车） 3步行 4骑行（电动车） 通过setAMapPathData下发数据
- (void)onNotifyNaviTypeBlock:(void(^)(NSInteger naviId,NSInteger type))block;

///通知导航状态 state：1开始导航 2结束导航
- (void)onNotifyNaviStatusBlock:(void(^)(NSInteger state))block;
@end

NS_ASSUME_NONNULL_END

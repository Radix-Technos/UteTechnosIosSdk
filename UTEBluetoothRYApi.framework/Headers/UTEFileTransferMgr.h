//
//  UTEFileTransferMgr.h
//  UTEBluetoothRYApi
//
//  Created by ute1205 on 2025/7/30.
//  Copyright © 2025 vv. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UTEModelDevice.h"

NS_ASSUME_NONNULL_BEGIN

@interface UTEFileTransferMgr : NSObject

/**
 目前只支持,其他后续补充
 disk填：@"D:" @"A:"
 
 @"D:/music/" 本地音乐保存目录
 @"A:/playlists/" 本地音乐保存自定义歌单目录

 发送音乐文件流程
 0、查询磁盘空间信息，判断是否可以传输
 1、先调用setTransferFileInfo
 2、然后setPrepareToWriteInfo准备音乐信息
 3、然后sendFileDataToBLEBlock
 4、如果有多个歌曲这里就循环2、3步骤
 5、然后sendFileCompleteBlock
  

 */

///查询磁盘空间 disk：@"D:" @"A:"
-(void)checkDiskSpace:(NSString *)disk Block:(void(^)(NSInteger freeSpace,NSInteger totalSpace,NSInteger errorCode))block;

///查询目录下的文件 path：查询音乐@"D:/music" 查询歌单@"A:/playlists"
-(void)checkFilesInDirectory:(NSString *)path Block:(void(^)(NSMutableArray <UTEModelFilesDirectoryInfo*>*array,NSInteger errorCode))block;

///查询单个文件信息 path：@"D:/music/三楠-晚风作酒.mp3"
-(void)checkFileInfo:(NSString *)path Block:(void(^)(UTEModelFileInfo *model,NSInteger errorCode))block;

///删除目录或文件 path：@"D:/music/三楠-晚风作酒.mp3"  state：0成功1失败
-(void)deleteFileInfo:(NSString *)path Block:(void(^)(NSInteger state,NSInteger errorCode))block;

///读取文件内容,监听文件接口上传数据 path：@"D:/music/三楠-晚风作酒.mp3"
-(void)getFileInfo:(NSString *)path Block:(void(^)(UTEModelFileInfo *model,NSInteger errorCode))block;

///文件内容数据监听上传 processData：每小包data，如果要计算进度需要在读取文件内容接口获取到文件大小自行计算 fileData：完成后总文件data
-(void)onNotifyFileContentBlock:(void(^)(NSData *processData,NSData *fileData,BOOL isSuccess,NSInteger errorCode))block;

///设置本次传输文件大小，个数，文件列表  state 0设置成功
-(void)setTransferFileInfo:(UTEModelFileItem *)model Block:(void(^)(NSInteger state,NSInteger errorCode))block;

///设置准备写入的信息 state 0设置成功 1空间不足 2文件系统错误 3参数错误 13手表打开地图中，设置失败，退出后设置
-(void)setPrepareToWriteInfo:(UTEModelFileTransferInfo *)model Block:(void(^)(NSInteger state,NSInteger errorCode))block;

///发送文件内容到设备
- (void)sendFileDataToBLEBlock:(void(^)(CGFloat process,BOOL isSuccess,NSInteger errorCode))block;

///本次传输完成
-(void)sendFileCompleteBlock:(void(^)(NSInteger errorCode))block;
///取消本次传输
-(void)cancelSendFileBlock:(void(^)(NSInteger errorCode))block;
#pragma mark 歌单
/**
    流程和设置音乐文件一样
    0、查询磁盘空间信息，判断是否可以传输
    1、先调用setTransferFileInfo，通过setMusicListContent来组装歌单内容
    2、然后setPrepareMusicList准备传输歌单
    3、然后sendFileDataToBLEBlock
    4、如果有多个歌单这里就循环2、3步骤
    5、然后sendFileCompleteBlock
 */
///歌单内容组装
-(NSData *)setMusicListContent:(UTEModelMusicList *)model;

///设置准备写入歌单信息 state 0设置成功 1空间不足 2文件系统错误 3参数错误
-(void)setPrepareMusicList:(UTEModelMusicList *)model Block:(void(^)(NSInteger state,NSInteger errorCode))block;

///监听设备删除歌曲   listName：歌单名   musicName：歌曲名，如果歌单名为0就是删除歌曲， 有歌单名就是删除歌单的歌曲名
-(void)onNotifyDeleteMusicBlock:(void (^)(NSString *listName,NSString *musicName))block;

///解析歌单内容
-(UTEModelMusicList*)analysisMusicList:(NSData *)data;

@end

NS_ASSUME_NONNULL_END

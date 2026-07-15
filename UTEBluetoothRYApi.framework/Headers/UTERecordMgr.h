//
//  UTERecordMgr.h
//  UTEBluetoothRYApi
//
//  Created by ute1205 on 2025/12/22.
//  Copyright © 2025 vv. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, UTERecordingScene) {
    ///    0：未知场景；
    UTERecordingSceneNone          = 0,
    ///    1：正常场景；
    UTERecordingSceneNormal        = 1,
    ///    2：电话场景；
    UTERecordingScenePhone         = 2,
    ///    3：采访场景；
    UTERecordingSceneInterview     = 3,
    ///    4：演讲场景；
    UTERecordingSceneSpeech        = 4,
    ///    5：备忘场景；
    UTERecordingSceneMemo          = 5,
    ///    6：音乐场景；
    UTERecordingSceneMusic         = 6,
    ///    7： HiRes场景；
    UTERecordingSceneHiRes         = 7,
};

typedef NS_ENUM(NSInteger, UTERecordingResult) {
    ///    0：开始录音成功；
    UTERecordingResultSuccess                = 0,
    ///    1 ：存储空间已满，录音失败；
    UTERecordingResultSpaceFull              = 1,
    ///    2： U盘模式已启动，录音失败；
    UTERecordingResultUSBMode                = 2,
    ///    3：硬件错误，录音失败；
    UTERecordingResultHardwareError          = 3,
    ///    4：已经在录音中；
    UTERecordingResultRecording              = 4,
    ///    5：WiFi模式中，录音失败；
    UTERecordingResultWiFiMode               = 5,
    ///    6：录音已停止；
    UTERecordingResultRecordingStopped       = 6,
    ///    10：未知错误；
    UTERecordingResultNone                   = 10,
};

typedef NS_ENUM(NSInteger, UTERecordingFileType) {
    ///    0代表AVO 也是opus格式 是双声道
    UTERecordingFileTypeAVO                = 0,
    ///    1代表opus 单声道
    UTERecordingFileTypeopus               = 1,
    ///    2代表MP3
    UTERecordingFileTypeMP3                = 2,
    ///    3代表SBC
    UTERecordingFileTypeSBC                = 3,
    ///    4代表PCM
    UTERecordingFileTypePCM                = 4,
    ///    5代表WAV
    UTERecordingFileTypeWAV                = 5,
};

typedef NS_ENUM(NSInteger, UTERecordStateType) {
    ///    未知
    UTERecordStateTypeNone                = 0,
    ///    空闲
    UTERecordStateTypeIdle                = 1,
    ///    正在录音
    UTERecordStateTypeRecording           = 2,
    ///    正在播放
    UTERecordStateTypePlaying             = 3,
    ///    USB已连接
    UTERecordStateTypeUSBConnected        = 4,
    ///    WiFi
    UTERecordStateTypeWiFi                = 5,
    ///    FOTA
    UTERecordStateTypeFOTA                = 6,
    ///    工厂测试
    UTERecordStateTypeFactoryTest         = 7,
};

typedef NS_ENUM(NSInteger, UTERecordWiFiType) {
    ///    0：未知；
    UTERecordWiFiTypeNone                     = 0,
    ///    1：握手成功；
    UTERecordWiFiTypeSuccess                  = 1,
    ///    2：上报握手请求；
    UTERecordWiFiTypeShandshakeRequest        = 2,
    ///    3：上报心跳；
    UTERecordWiFiTypePing                     = 3,
    ///    11：文件列表数据；
    UTERecordWiFiTypeFileList                 = 11,
    ///    12：文件同步数据状态回复；
    UTERecordWiFiTypeSyncFileStatus           = 12,
    ///    13：文件数据返回；
    UTERecordWiFiTypeFileData                 = 13,
    ///    14：删除文件状态；
    UTERecordWiFiTypeDelFileStatus            = 14,
    ///    15：停止传输；
    UTERecordWiFiTypeStopTrans                = 15,
    
};

@interface UTEModelRecordInfo : NSObject
///录音类型 1：设备发起 2：APP发起 （注意只有开始录音接口有值）
@property (nonatomic,assign) NSInteger type;
///录音id
@property (nonatomic,assign) NSInteger sessionID;
///录音场景
@property (nonatomic,assign) UTERecordingScene    scene;
///录音起始位置
@property (nonatomic,assign) NSInteger    startIndex;
///录音状态
@property (nonatomic,assign) UTERecordingResult    reslut;

@end

@interface UTEModelRecordPauseInfo : NSObject
///录音id
@property (nonatomic,assign) NSInteger sessionID;
///录音场景
@property (nonatomic,assign) UTERecordingScene    scene;
///录音起始位置
@property (nonatomic,assign) NSInteger    startIndex;
///录音状态 0:暂停录音成功 1:已经处于暂停状态 2:session_id与当前录音ID不匹配 3:未知错误
@property (nonatomic,assign) NSInteger    reslut;

@end

@interface UTEModelRecordStopInfo : NSObject
///录音id
@property (nonatomic,assign) NSInteger sessionID;
///录音类型 1：设备发起 2：APP发起
@property (nonatomic,assign) NSInteger type;
///录音文件是否保存：0：未保存；1：已保存；
@property (nonatomic,assign) NSInteger    file_exist;
///录音文件大小
@property (nonatomic,assign) NSInteger    file_size;

@end

@interface UTEModelRecordFileInfo : NSObject
///文件名(也是sessionID)
@property (nonatomic,assign) NSInteger fileName;
///文件大小
@property (nonatomic,assign) NSInteger fileSize;
///文件格式(当是标记该值忽略)
@property (nonatomic,assign) UTERecordingFileType    type;

@end

@interface UTEModelRecordFileListInfo : NSObject
///请求uid
@property (nonatomic,assign) NSInteger uid;
///文件数量
@property (nonatomic,assign) NSInteger count;
///录音文件列表
@property (nonatomic,assign) NSArray    <UTEModelRecordFileInfo *>*fileArray;

@end

@interface UTEModelRecordStorageInfo : NSObject
///总容量大小，单位KB
@property (nonatomic,assign) NSInteger total;
///剩余容量大小，单位KB
@property (nonatomic,assign) NSInteger free;
///每秒录音需要存储空间大小，单位Byte
@property (nonatomic,assign) NSInteger rec_size_ps;
///已经没有空闲存储容量：0：还有空闲容量；1：已无空闲容量；
@property (nonatomic,assign) NSInteger no_free_size;

@end

@interface UTEModelRecordBindInfo : NSObject

/*---app下发未验证时候返回以下数据---*/
///设备的SSN
@property (nonatomic,copy) NSString *ssn;
///固件版本标志：T：测试版本固件；V：正式版本固件；
@property (nonatomic,copy) NSString *version_flag;
///版本号值
@property (nonatomic,assign) NSInteger versionValue;
///绑定信息：0：未绑定；1：已绑定；
@property (nonatomic,assign) NSInteger binded;

/*---APP下发验证时候返回以下数据---*/
///握手请求结果：0：握手成功；1：token不匹配，握手失败；2：正在录音，无法确认握手；3：用户拒绝握手；4：需要App端校验相关信息；
@property (nonatomic,assign) NSInteger refuse_cause;
///传输协议版本
@property (nonatomic,assign) NSInteger transfersVersion;
///版本号值
@property (nonatomic,assign) NSInteger time_zone;
///麦克风模式：0：普通模式；1：混合模式
@property (nonatomic,assign) NSInteger mic_mode;
///数字麦克风增益：0：无增益 1：0dB 2：12dB 3：24dB 4：36dB
@property (nonatomic,assign) NSInteger mic_gain;
///模拟麦克风增益：  0x00 ：-17.625dB 0x2F：0dB 0x44 ：8dB 0x6B：24dB 0x7F：30dB
@property (nonatomic,assign) NSInteger adc_gain;
@end

@interface UTEModelRecordStatus : NSObject
/// 设备当前状态
@property (nonatomic,assign) UTERecordStateType state;
/// U盘模式 udisk:0：未开启；1：已开启；
@property (nonatomic,assign) NSInteger udisk;
/// 隐私模式 udisk:0：未开启；1：已开启；
@property (nonatomic,assign) NSInteger privacy;
/// 按键状态
@property (nonatomic,assign) NSInteger key_state;
/// 麦克风模式 mic_mode:0：普通模式；1：混个模式；
@property (nonatomic,assign) NSInteger mic_mode;
/// U盘功能控制状态 usbms_ctl:1 ：已经开启U盘功能；0：未开启U盘功能；
@property (nonatomic,assign) NSInteger usbms_ctl;

@end

@interface UTEModelRecordEncodingConfig : NSObject
///文件格式
@property (nonatomic,assign) UTERecordingFileType    type;
/// 通道
@property (nonatomic,assign) NSInteger channal;
/// 采样率
@property (nonatomic,assign) NSInteger sampleRate;
/// 位宽
@property (nonatomic,assign) NSInteger sampleBit;
/// 码率
@property (nonatomic,assign) NSInteger bitRate;
/// 复杂度（预留）
@property (nonatomic,assign) NSInteger complexity;

@end

@interface UTEModelRecordWiFiDatainfo : NSObject
///sessionID(也是文件名)
@property (nonatomic,assign) NSInteger session;
///数据偏移量
@property (nonatomic,assign) NSInteger offset;
///数据大小
@property (nonatomic,assign) NSInteger length;
///0:不是最后一包 1：最后一包 协议版本=1，暂不支持
@property (nonatomic,assign) NSInteger last;
///录音文件数据
@property (nonatomic,strong) NSData *data;

@end


@interface UTERecordMgr : NSObject

///获取存储容量信息
-(void)getStorageCapacityInfoBlock:(void(^)(NSInteger errorCode,UTEModelRecordStorageInfo *model))block;

///获取设备录音文件编码参数配置
-(void)getRecordEncodingConfigurationBlock:(void(^)(NSInteger errorCode,NSArray<UTEModelRecordEncodingConfig *> *configArray))block;

///获取当前录音设备状态
-(void)getRecordStatusBlock:(void(^)(NSInteger errorCode,UTEModelRecordStatus *model))block;

///监听设备开启录音
-(void)onNotifyStartRecordBlock:(void(^)(NSInteger errorCode,UTEModelRecordInfo *model))block;

///监听设备暂停录音
-(void)onNotifyPauseRecordBlock:(void(^)(NSInteger errorCode,UTEModelRecordPauseInfo *model))block;

///监听设备恢复录音
-(void)onNotifyResetRecordBlock:(void(^)(NSInteger errorCode,UTEModelRecordInfo *model))block;

///监听设备结束录音
-(void)onNotifyStopRecordBlock:(void(^)(NSInteger errorCode,UTEModelRecordStopInfo *model))block;

///开始录音 1：普通录音 2：同传录音 （目前填1即可）
-(void)startRecord:(NSInteger)type Block:(void(^)(NSInteger errorCode,UTEModelRecordInfo *model))block;

///暂停录音
-(void)pauseRecord:(NSInteger)sessionID Block:(void(^)(NSInteger errorCode,UTEModelRecordPauseInfo *model))block;

///恢复录音 sessionID:录音id Scene:场景（与开始录音场景一致）
-(void)resetRecord:(NSInteger)sessionID withScene:(UTERecordingScene)scene Block:(void(^)(NSInteger errorCode,UTEModelRecordInfo *model))block;

///结束录音
-(void)stopRecordBlock:(void(^)(NSInteger errorCode,UTEModelRecordStopInfo *model))block;

///获取文件列表，参数目前都填0 (如果当前正在录音，设备不响应此指令；如果当前U盘功能开启，设备不响应此指)
-(void)getRecordFileList:(NSInteger)uid StartSession:(NSInteger )session  OnlyOne:(NSInteger)count Block:(void(^)(NSInteger errorCode,UTEModelRecordFileListInfo *model))block;

///同步录音文件准备（步骤1） sessionID:请求同步录音文件ID start:文件数据位置开始index end:文件数据位置结束（完整文件大小，如果同传时候建议大小1600）index type:文件格式 reslut：0：文件没问题；1：文件系统错误；2：文件不存在；3：文件中断；
-(void)syncRecordData:(NSInteger)sessionId startIndex:(NSInteger)start endIndex:(NSInteger)end fileType:(UTERecordingFileType)type Block:(void(^)(NSInteger errorCode,NSInteger sessionID,NSInteger reslut))block;

///监听同步录音文件数据 sessionID:请求同步录音文件ID size:大小 completeData：完整数据 endIndex:数据最后位置 subData:每小包数据
-(void)onNotifySyncRecordDataBlock:(void (^)(BOOL isCompleted,NSInteger sessionID,NSInteger size,NSData *subData,NSData *completeData))block;

///监听同步录音文件数据完成 sessionID:请求同步录音文件ID
-(void)onNotifySyncRecordDataCompleteBlock:(void (^)(NSInteger sessionID))block;

///停止录音文件同步
-(void)stopSyncRecordDataBlock:(void(^)(NSInteger errorCode))block;

///删除录音文件 sessionID:请求同步录音文件ID type:文件格式 result:0：删除成功；1 ：正在录音，不允许删除；2：已收藏，不允许删除；3：正在播放，不允许删除；4： U盘模式，无法删除
-(void)deletelRecordFile:(NSInteger)sessionId fileType:(UTERecordingFileType)type Block:(void(^)(NSInteger errorCode,NSInteger sessionId,NSInteger result))block;

///清空文件(格式化 暂不支持，需与固件确认是否开放)
-(void)clearRecordFileBlock:(void(^)(NSInteger errorCode))block;

/**APP绑定录音设备
 osType：0：未知，1：IOS，2：Android；
 version：目前固定0；
 verify：0：未校验，或校验失败，1：校验成功；
 token：握手Token 长度16（未校验或校验识别不用填）
 */
-(void)appBindRecordDevice:(NSInteger)osType BleVersion:(NSInteger)version Verify:(NSInteger)verify Token:(NSString*)token Block:(void(^)(NSInteger errorCode,UTEModelRecordBindInfo *model))block;

///APP解绑录音设备type:是否擦除用户数据 0：不擦除；1：删除所有录音数据；不会回复block直接删除 token，并断开BLE连接
-(void)appUnBindRecordDeviceCMD:(NSInteger)type Block:(void(^)(NSInteger errorCode))block;

///恢复出厂设置 停止录音、传输等业务；断开蓝牙连接；清除个性化配置;格式化存储空间;
-(void)RecordFactoryResetBlock:(void(^)(NSInteger errorCode))block;

///设置WiFi模式传输 type：0:5G，1:2.4G; 设备收到指令后，会关闭BLE开启WiFi,不会通过BLE回复确认信息
-(void)setWiFiMode:(NSInteger)type;

///获取标记列表，参数目前都填0 (如果当前正在录音，设备不响应此指令；如果当前U盘功能开启，设备不响应此指)
-(void)getMarkFileList:(NSInteger)uid StartSession:(NSInteger )session  OnlyOne:(NSInteger)count Block:(void(^)(NSInteger errorCode,UTEModelRecordFileListInfo *model))block;

///同步标记文件准备（步骤1） sessionID:请求同步标记文件ID start:文件数据位置开始index end:文件数据位置结束（完整文件大小，如果同传时候建议大小1600）index reslut：0：文件没问题；1：文件系统错误；2：文件不存在；3：文件中断；
-(void)syncMarkData:(NSInteger)sessionId startIndex:(NSInteger)start endIndex:(NSInteger)end Block:(void(^)(NSInteger errorCode,NSInteger sessionID,NSInteger reslut))block;

///监听同步标记文件数据 sessionID:请求同步标记文件ID size:大小（可以判断是否完整） milliseconds(单位毫秒)
-(void)onNotifySyncMarkDataBlock:(void (^)(NSInteger sessionID,NSInteger size,NSArray *millisecondsArray))block;

///监听同步标记文件数据完成 sessionID:请求同步标记文件ID
-(void)onNotifySyncMarkDataCompleteBlock:(void (^)(NSInteger sessionID))block;

///停止标记文件同步
-(void)stopSyncMarkDataBlock:(void(^)(NSInteger errorCode))block;

///删除标记文件 sessionID:请求同步标记文件ID result:0：删除成功；1 ：正在录音，不允许删除；2：已收藏，不允许删除；3：正在播放，不允许删除；4： U盘模式，无法删除
-(void)deletelMarkFile:(NSInteger)sessionId Block:(void(^)(NSInteger errorCode,NSInteger sessionId,NSInteger result))block;


/// MARK: wifi模式下指令

/**解析接口和数据返回
 
  说明：
  | Type                          | parsedData 类型                          |
  |-------------------------------|------------------------------------------|
  | Success                       | nil                                      |
  | HandshakeRequest              | nil                                      |
  | FileList                      | NSArray<UTEModelRecordFileInfo *> *      |
  | SyncFileStatus                | NSDictionary *                           |
  | FileData                      | UTEModelRecordWiFiDatainfo *             |
  | DeleteFileStatus              | NSDictionary *                           |
  | StopTransmission              | NSDictionary *                           |
 
 返回UTERecordWiFiTypeSuccess，握手成功，anyData为nil；
 
 返回UTERecordWiFiTypeShandshakeRequest，握手请求，需要发送握手指令（wifi_handshake），anyData为nil；
 
 返回UTERecordWiFiTypeFileList，文件列表返回，anyData为NSMutableArray <UTEModelRecordFileInfo *>*array；
 
 返回UTERecordWiFiTypeSyncFileStatus，同步文件数据状态返回，anyData为NSDictionary *dict，key：@"session":sessionID, @"status"：status:0文件正常，1文件系统不可用，2文件不存在；
 
 返回UTERecordWiFiTypeFileData，同步文件数据，anyData为UTEModelRecordWiFiDatainfo *model，文件数据信息；
 
 返回UTERecordWiFiTypeDelFileStatus，删除文件状态，anyData为NSDictionary*dict, key：@"session":sessionID, @"status"：status; status：0删除成功，8文件不存在；
 
 返回UTERecordWiFiTypeStopTrans，停止传输，anyData为NSDictionary*dict, key：@"status"：status; status：0停止成功；
 
 */
-(void)wifi_parseData:(NSData *)data Block:(void(^)(UTERecordWiFiType type,id _Nullable anyData))block;

///wifi_握手指令
-(NSData*)wifi_handshake;

///wifi 心跳应答
-(NSData*)wifi_heartbeatPacket;

///wifi 获取文件列表
-(NSData *)wifi_getFileList;

/// 获取录音文件 sessionID:请求同步录音文件ID start:文件数据位置开始index end:文件数据位置结束index type:文件格式（类型与ble一致）
-(NSData *)wifi_getRecordData:(NSInteger)session withStart:(NSInteger)start withEnd:(NSInteger)end withType:(NSInteger)type;

///wifi 停止传输 sessionID：录音文件sessionID type:文件格式（类型与ble一致）
-(NSData *)wifi_stopTransmission:(NSInteger)session withType:(NSInteger)type;

///wifi 删除文件 sessionID：录音文件sessionID type:文件格式（类型与ble一致）
-(NSData *)wifi_delFile:(NSInteger)session withType:(NSInteger)type;

///wifi 关闭WiFi
-(NSData *)wifi_closeWiFi;


@end

NS_ASSUME_NONNULL_END

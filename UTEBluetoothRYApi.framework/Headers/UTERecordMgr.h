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
    ///    0：未知场景； (Unknown scene)
    UTERecordingSceneNone          = 0,
    ///    1：正常场景； (Normal scene)
    UTERecordingSceneNormal        = 1,
    ///    2：电话场景； (Phone scene)
    UTERecordingScenePhone         = 2,
    ///    3：采访场景； (Interview scene)
    UTERecordingSceneInterview     = 3,
    ///    4：演讲场景； (Speech scene)
    UTERecordingSceneSpeech        = 4,
    ///    5：备忘场景； (Memo scene)
    UTERecordingSceneMemo          = 5,
    ///    6：音乐场景； (Music scene)
    UTERecordingSceneMusic         = 6,
    ///    7： HiRes场景； (HiRes scene)
    UTERecordingSceneHiRes         = 7,
};

typedef NS_ENUM(NSInteger, UTERecordingResult) {
    ///    0：开始录音成功； (Recording started successfully)
    UTERecordingResultSuccess                = 0,
    ///    1 ：存储空间已满，录音失败； (Storage full, recording failed)
    UTERecordingResultSpaceFull              = 1,
    ///    2： U盘模式已启动，录音失败； (USB mode active, recording failed)
    UTERecordingResultUSBMode                = 2,
    ///    3：硬件错误，录音失败； (Hardware error, recording failed)
    UTERecordingResultHardwareError          = 3,
    ///    4：已经在录音中； (Already recording)
    UTERecordingResultRecording              = 4,
    ///    5：WiFi模式中，录音失败； (WiFi mode active, recording failed)
    UTERecordingResultWiFiMode               = 5,
    ///    6：录音已停止； (Recording stopped)
    UTERecordingResultRecordingStopped       = 6,
    ///    10：未知错误； (Unknown error)
    UTERecordingResultNone                   = 10,
};

typedef NS_ENUM(NSInteger, UTERecordingFileType) {
    ///    0代表AVO 也是opus格式 是双声道 (AVO/opus, stereo)
    UTERecordingFileTypeAVO                = 0,
    ///    1代表opus 单声道 (opus, mono)
    UTERecordingFileTypeopus               = 1,
    ///    2代表MP3 (MP3)
    UTERecordingFileTypeMP3                = 2,
    ///    3代表SBC (SBC)
    UTERecordingFileTypeSBC                = 3,
    ///    4代表PCM (PCM)
    UTERecordingFileTypePCM                = 4,
    ///    5代表WAV (WAV)
    UTERecordingFileTypeWAV                = 5,
};

typedef NS_ENUM(NSInteger, UTERecordStateType) {
    ///    未知 (Unknown)
    UTERecordStateTypeNone                = 0,
    ///    空闲 (Idle)
    UTERecordStateTypeIdle                = 1,
    ///    正在录音 (Recording)
    UTERecordStateTypeRecording           = 2,
    ///    正在播放 (Playing)
    UTERecordStateTypePlaying             = 3,
    ///    USB已连接 (USB connected)
    UTERecordStateTypeUSBConnected        = 4,
    ///    WiFi (WiFi)
    UTERecordStateTypeWiFi                = 5,
    ///    FOTA (FOTA)
    UTERecordStateTypeFOTA                = 6,
    ///    工厂测试 (Factory test)
    UTERecordStateTypeFactoryTest         = 7,
};

typedef NS_ENUM(NSInteger, UTERecordWiFiType) {
    ///    0：未知； (Unknown)
    UTERecordWiFiTypeNone                     = 0,
    ///    1：握手成功； (Handshake success)
    UTERecordWiFiTypeSuccess                  = 1,
    ///    2：上报握手请求； (Handshake request reported)
    UTERecordWiFiTypeShandshakeRequest        = 2,
    ///    3：上报心跳； (Heartbeat reported)
    UTERecordWiFiTypePing                     = 3,
    ///    11：文件列表数据； (File list data)
    UTERecordWiFiTypeFileList                 = 11,
    ///    12：文件同步数据状态回复； (File sync data status reply)
    UTERecordWiFiTypeSyncFileStatus           = 12,
    ///    13：文件数据返回； (File data returned)
    UTERecordWiFiTypeFileData                 = 13,
    ///    14：删除文件状态； (Delete file status)
    UTERecordWiFiTypeDelFileStatus            = 14,
    ///    15：停止传输； (Stop transmission)
    UTERecordWiFiTypeStopTrans                = 15,
    
};

@interface UTEModelRecordInfo : NSObject
///录音类型 1：设备发起 2：APP发起 （注意只有开始录音接口有值） (Recording type: 1=device initiated, 2=APP initiated)
@property (nonatomic,assign) NSInteger type;
///录音id (Recording session ID)
@property (nonatomic,assign) NSInteger sessionID;
///录音场景 (Recording scene)
@property (nonatomic,assign) UTERecordingScene    scene;
///录音起始位置 (Recording start index)
@property (nonatomic,assign) NSInteger    startIndex;
///录音状态 (Recording result)
@property (nonatomic,assign) UTERecordingResult    reslut;

@end

@interface UTEModelRecordPauseInfo : NSObject
///录音id (Recording session ID)
@property (nonatomic,assign) NSInteger sessionID;
///录音场景 (Recording scene)
@property (nonatomic,assign) UTERecordingScene    scene;
///录音起始位置 (Recording start index)
@property (nonatomic,assign) NSInteger    startIndex;
///录音状态 0:暂停录音成功 1:已经处于暂停状态 2:session_id与当前录音ID不匹配 3:未知错误 (Pause result: 0=success, 1=already paused, 2=session ID mismatch, 3=unknown error)
@property (nonatomic,assign) NSInteger    reslut;

@end

@interface UTEModelRecordStopInfo : NSObject
///录音id (Recording session ID)
@property (nonatomic,assign) NSInteger sessionID;
///录音类型 1：设备发起 2：APP发起 (Recording type: 1=device initiated, 2=APP initiated)
@property (nonatomic,assign) NSInteger type;
///录音文件是否保存：0：未保存；1：已保存； (File saved: 0=no, 1=yes)
@property (nonatomic,assign) NSInteger    file_exist;
///录音文件大小 (File size)
@property (nonatomic,assign) NSInteger    file_size;

@end

@interface UTEModelRecordFileInfo : NSObject
///文件名(也是sessionID) (File name, also session ID)
@property (nonatomic,assign) NSInteger fileName;
///文件大小 (File size)
@property (nonatomic,assign) NSInteger fileSize;
///文件格式(当是标记该值忽略) (File format, ignored for markers)
@property (nonatomic,assign) UTERecordingFileType    type;

@end

@interface UTEModelRecordFileListInfo : NSObject
///请求uid (Request UID)
@property (nonatomic,assign) NSInteger uid;
///文件数量 (File count)
@property (nonatomic,assign) NSInteger count;
///录音文件列表 (Recording file list)
@property (nonatomic,assign) NSArray    <UTEModelRecordFileInfo *>*fileArray;

@end

@interface UTEModelRecordStorageInfo : NSObject
///总容量大小，单位KB (Total capacity, in KB)
@property (nonatomic,assign) NSInteger total;
///剩余容量大小，单位KB (Free space, in KB)
@property (nonatomic,assign) NSInteger free;
///每秒录音需要存储空间大小，单位Byte (Storage needed per second, in Bytes)
@property (nonatomic,assign) NSInteger rec_size_ps;
///已经没有空闲存储容量：0：还有空闲容量；1：已无空闲容量； (No free space: 0=has free space, 1=no free space)
@property (nonatomic,assign) NSInteger no_free_size;

@end

@interface UTEModelRecordBindInfo : NSObject

/*---app下发未验证时候返回以下数据--- (Data returned when app sends unverified request)---*/
///设备的SSN (Device SSN)
@property (nonatomic,copy) NSString *ssn;
///固件版本标志：T：测试版本固件；V：正式版本固件； (Firmware version flag: T=test, V=release)
@property (nonatomic,copy) NSString *version_flag;
///版本号值 (Version value)
@property (nonatomic,assign) NSInteger versionValue;
///绑定信息：0：未绑定；1：已绑定； (Binding info: 0=unbound, 1=bound)
@property (nonatomic,assign) NSInteger binded;

/*---APP下发验证时候返回以下数据--- (Data returned when APP sends verification)---*/
///握手请求结果：0：握手成功；1：token不匹配，握手失败；2：正在录音，无法确认握手；3：用户拒绝握手；4：需要App端校验相关信息； (Handshake result: 0=success, 1=token mismatch, 2=recording, 3=user rejected, 4=app verification needed)
@property (nonatomic,assign) NSInteger refuse_cause;
///传输协议版本 (Transfer protocol version)
@property (nonatomic,assign) NSInteger transfersVersion;
///版本号值 (Time zone)
@property (nonatomic,assign) NSInteger time_zone;
///麦克风模式：0：普通模式；1：混合模式 (Mic mode: 0=normal, 1=mixed)
@property (nonatomic,assign) NSInteger mic_mode;
///数字麦克风增益：0：无增益 1：0dB 2：12dB 3：24dB 4：36dB (Digital mic gain: 0=none, 1=0dB, 2=12dB, 3=24dB, 4=36dB)
@property (nonatomic,assign) NSInteger mic_gain;
///模拟麦克风增益：  0x00 ：-17.625dB 0x2F：0dB 0x44 ：8dB 0x6B：24dB 0x7F：30dB (Analog mic gain: 0x00=-17.625dB, 0x2F=0dB, 0x44=8dB, 0x6B=24dB, 0x7F=30dB)
@property (nonatomic,assign) NSInteger adc_gain;
@end

@interface UTEModelRecordStatus : NSObject
/// 设备当前状态 (Device current state)
@property (nonatomic,assign) UTERecordStateType state;
/// U盘模式 udisk:0：未开启；1：已开启； (USB disk mode: 0=off, 1=on)
@property (nonatomic,assign) NSInteger udisk;
/// 隐私模式 udisk:0：未开启；1：已开启； (Privacy mode: 0=off, 1=on)
@property (nonatomic,assign) NSInteger privacy;
/// 按键状态 (Key state)
@property (nonatomic,assign) NSInteger key_state;
/// 麦克风模式 mic_mode:0：普通模式；1：混个模式； (Mic mode: 0=normal, 1=mixed)
@property (nonatomic,assign) NSInteger mic_mode;
/// U盘功能控制状态 usbms_ctl:1 ：已经开启U盘功能；0：未开启U盘功能； (USBMS control: 1=enabled, 0=disabled)
@property (nonatomic,assign) NSInteger usbms_ctl;

@end

@interface UTEModelRecordEncodingConfig : NSObject
///文件格式 (File format)
@property (nonatomic,assign) UTERecordingFileType    type;
/// 通道 (Channel)
@property (nonatomic,assign) NSInteger channal;
/// 采样率 (Sample rate)
@property (nonatomic,assign) NSInteger sampleRate;
/// 位宽 (Bit depth)
@property (nonatomic,assign) NSInteger sampleBit;
/// 码率 (Bit rate)
@property (nonatomic,assign) NSInteger bitRate;
/// 复杂度（预留） (Complexity, reserved)
@property (nonatomic,assign) NSInteger complexity;

@end

@interface UTEModelRecordWiFiDatainfo : NSObject
///sessionID(也是文件名) (Session ID, also the file name)
@property (nonatomic,assign) NSInteger session;
///数据偏移量 (Data offset)
@property (nonatomic,assign) NSInteger offset;
///数据大小 (Data size)
@property (nonatomic,assign) NSInteger length;
///0:不是最后一包 1：最后一包 协议版本=1，暂不支持 (0=not last packet, 1=last packet, protocol v1 not supported yet)
@property (nonatomic,assign) NSInteger last;
///录音文件数据 (Recording file data)
@property (nonatomic,strong) NSData *data;

@end


@interface UTERecordMgr : NSObject

///获取存储容量信息 (Get storage capacity info)
-(void)getStorageCapacityInfoBlock:(void(^)(NSInteger errorCode,UTEModelRecordStorageInfo *model))block;

///获取设备录音文件编码参数配置 (Get recording encoding configuration)
-(void)getRecordEncodingConfigurationBlock:(void(^)(NSInteger errorCode,NSArray<UTEModelRecordEncodingConfig *> *configArray))block;

///获取当前录音设备状态 (Get current recording device status)
-(void)getRecordStatusBlock:(void(^)(NSInteger errorCode,UTEModelRecordStatus *model))block;

///监听设备开启录音 (Monitor device start recording)
-(void)onNotifyStartRecordBlock:(void(^)(NSInteger errorCode,UTEModelRecordInfo *model))block;

///监听设备暂停录音 (Monitor device pause recording)
-(void)onNotifyPauseRecordBlock:(void(^)(NSInteger errorCode,UTEModelRecordPauseInfo *model))block;

///监听设备恢复录音 (Monitor device resume recording)
-(void)onNotifyResetRecordBlock:(void(^)(NSInteger errorCode,UTEModelRecordInfo *model))block;

///监听设备结束录音 (Monitor device stop recording)
-(void)onNotifyStopRecordBlock:(void(^)(NSInteger errorCode,UTEModelRecordStopInfo *model))block;

///开始录音 1：普通录音 2：同传录音 （目前填1即可） (Start recording: 1=normal, 2=simultaneous interpretation, use 1 for now)
-(void)startRecord:(NSInteger)type Block:(void(^)(NSInteger errorCode,UTEModelRecordInfo *model))block;

///设置实时转录功能，录音开始后发送开启指令，设备将录音数据主动上报 enble：0关闭; 1打开. type：目前先填1. status:0成功 1失败 2不支持该功能 (Set real-time upload: enable=0 off, 1 on; type=1 for now; status=0 success, 1 fail, 2 not supported)
-(void)setRealTimeUpload:(NSInteger)enble Extension:(NSInteger)type Block:(void(^)(NSInteger errorCode,NSInteger status))block;

///监听设备实时转录上报数据 data音频流数据 (Monitor real-time upload data, audio stream data)
-(void)onNotifyRealTimeUploadDataBlock:(void(^)(NSData *data))block;

///监听设备实时转录状态 status：0关闭 1开启 (Monitor real-time upload status: 0=off, 1=on)
-(void)onNotifyRealTimeUploadStateBlock:(void(^)(NSInteger status))block;

///回复设备实时转录状态 enble：0已处理，需调用设置实时转录功能接口开启 1操作失败 2拒绝 (Reply real-time upload status: 0=processed, call setRealTimeUpload to enable; 1=fail; 2=reject)
-(void)setNotifyRealTimeUploadState:(NSInteger)enble Extension:(NSInteger)type Block:(void(^)(NSInteger errorCode))block;


///暂停录音 (Pause recording) sessionID:录音id  （sessionID=recording ID）
-(void)pauseRecord:(NSInteger)sessionID Block:(void(^)(NSInteger errorCode,UTEModelRecordPauseInfo *model))block;

///恢复录音 sessionID:录音id Scene:场景（与开始录音场景一致） (Resume recording: sessionID=recording ID, scene=same as start recording)
-(void)resetRecord:(NSInteger)sessionID withScene:(UTERecordingScene)scene Block:(void(^)(NSInteger errorCode,UTEModelRecordInfo *model))block;

///结束录音 (Stop recording)
-(void)stopRecordBlock:(void(^)(NSInteger errorCode,UTEModelRecordStopInfo *model))block;

///获取文件列表，参数目前都填0 (如果当前正在录音，设备不响应此指令；如果当前U盘功能开启，设备不响应此指) (Get file list, all params fill 0 for now. Device won't respond if recording or USB mode is active)
-(void)getRecordFileList:(NSInteger)uid StartSession:(NSInteger )session  OnlyOne:(NSInteger)count Block:(void(^)(NSInteger errorCode,UTEModelRecordFileListInfo *model))block;

///同步录音文件准备（步骤1） sessionID:请求同步录音文件ID start:文件数据位置开始index end:文件数据位置结束（完整文件大小，如果同传时候建议大小1600）index type:文件格式 reslut：0：文件没问题；1：文件系统错误；2：文件不存在；3：文件中断； (Sync recording file prep (step 1): sessionID=file ID, start=start index, end=end index (full file size, 1600 recommended for simultaneous), type=file format, result=0 ok, 1 fs error, 2 file not found, 3 file interrupted)
-(void)syncRecordData:(NSInteger)sessionId startIndex:(NSInteger)start endIndex:(NSInteger)end fileType:(UTERecordingFileType)type Block:(void(^)(NSInteger errorCode,NSInteger sessionID,NSInteger reslut))block;

///监听同步录音文件数据 sessionID:请求同步录音文件ID size:大小 completeData：完整数据 endIndex:数据最后位置 subData:每小包数据 (Monitor sync recording file data: sessionID=file ID, size=size, completeData=full data, endIndex=last position, subData=each packet data)
-(void)onNotifySyncRecordDataBlock:(void (^)(BOOL isCompleted,NSInteger sessionID,NSInteger size,NSData *subData,NSData *completeData))block;

///监听同步录音文件数据完成 sessionID:请求同步录音文件ID (Monitor sync recording file data complete: sessionID=file ID)
-(void)onNotifySyncRecordDataCompleteBlock:(void (^)(NSInteger sessionID))block;

///停止录音文件同步 (Stop recording file sync)
-(void)stopSyncRecordDataBlock:(void(^)(NSInteger errorCode))block;

///删除录音文件 sessionID:请求同步录音文件ID type:文件格式 result:0：删除成功；1 ：正在录音，不允许删除；2：已收藏，不允许删除；3：正在播放，不允许删除；4： U盘模式，无法删除 (Delete recording file: sessionID=file ID, type=file format, result=0 success, 1 recording, 2 favorited, 3 playing, 4 USB mode)
-(void)deletelRecordFile:(NSInteger)sessionId fileType:(UTERecordingFileType)type Block:(void(^)(NSInteger errorCode,NSInteger sessionId,NSInteger result))block;

///清空文件(格式化 暂不支持，需与固件确认是否开放) (Clear files/format, not supported yet, needs firmware confirmation)
-(void)clearRecordFileBlock:(void(^)(NSInteger errorCode))block;

/**APP绑定录音设备 (APP bind recording device)
 osType：0：unknown，1：IOS，2：Android；
 version：目前固定0 (currently fixed to 0)；
 verify：0：未校验，或校验失败，1：校验成功 (0=unverified/failed, 1=verified)；
 token：握手Token 长度16（未校验或校验识别不用填） (handshake token, length 16, leave empty if not verifying)
 */
-(void)appBindRecordDevice:(NSInteger)osType BleVersion:(NSInteger)version Verify:(NSInteger)verify Token:(NSString*)token Block:(void(^)(NSInteger errorCode,UTEModelRecordBindInfo *model))block;

///APP解绑录音设备type:是否擦除用户数据 0：不擦除；1：删除所有录音数据；不会回复block直接删除 token，并断开BLE连接 (APP unbind device: type=0 keep data, 1 delete all data. No block reply, directly delete token and disconnect BLE)
-(void)appUnBindRecordDeviceCMD:(NSInteger)type Block:(void(^)(NSInteger errorCode))block;

///恢复出厂设置 停止录音、传输等业务；断开蓝牙连接；清除个性化配置;格式化存储空间; (Factory reset: stop recording/transfer, disconnect BLE, clear personal config, format storage)
-(void)RecordFactoryResetBlock:(void(^)(NSInteger errorCode))block;

///设置WiFi模式传输 type：0:5G，1:2.4G; 设备收到指令后，会关闭BLE开启WiFi,不会通过BLE回复确认信息 (Set WiFi mode: type=0 5G, 1 2.4G. Device will close BLE and open WiFi, no BLE confirmation)
-(void)setWiFiMode:(NSInteger)type;

///获取标记列表，参数目前都填0 (如果当前正在录音，设备不响应此指令；如果当前U盘功能开启，设备不响应此指) (Get marker file list, all params fill 0 for now. Device won't respond if recording or USB mode is active)
-(void)getMarkFileList:(NSInteger)uid StartSession:(NSInteger )session  OnlyOne:(NSInteger)count Block:(void(^)(NSInteger errorCode,UTEModelRecordFileListInfo *model))block;

///同步标记文件准备（步骤1） sessionID:请求同步标记文件ID start:文件数据位置开始index end:文件数据位置结束（完整文件大小，如果同传时候建议大小1600）index reslut：0：文件没问题；1：文件系统错误；2：文件不存在；3：文件中断； (Sync marker file prep (step 1): sessionID=file ID, start=start index, end=end index, result=0 ok, 1 fs error, 2 not found, 3 interrupted)
-(void)syncMarkData:(NSInteger)sessionId startIndex:(NSInteger)start endIndex:(NSInteger)end Block:(void(^)(NSInteger errorCode,NSInteger sessionID,NSInteger reslut))block;

///监听同步标记文件数据 sessionID:请求同步标记文件ID size:大小（可以判断是否完整） milliseconds(单位毫秒) (Monitor sync marker file data: sessionID=file ID, size=size, milliseconds array)
-(void)onNotifySyncMarkDataBlock:(void (^)(NSInteger sessionID,NSInteger size,NSArray *millisecondsArray))block;

///监听同步标记文件数据完成 sessionID:请求同步标记文件ID (Monitor sync marker file data complete: sessionID=file ID)
-(void)onNotifySyncMarkDataCompleteBlock:(void (^)(NSInteger sessionID))block;

///停止标记文件同步 (Stop marker file sync)
-(void)stopSyncMarkDataBlock:(void(^)(NSInteger errorCode))block;

///删除标记文件 sessionID:请求同步标记文件ID result:0：删除成功；1 ：正在录音，不允许删除；2：已收藏，不允许删除；3：正在播放，不允许删除；4： U盘模式，无法删除 (Delete marker file: sessionID=file ID, result=0 success, 1 recording, 2 favorited, 3 playing, 4 USB mode)
-(void)deletelMarkFile:(NSInteger)sessionId Block:(void(^)(NSInteger errorCode,NSInteger sessionId,NSInteger result))block;


/// MARK: wifi模式下指令 (Commands in WiFi mode)

/**解析接口和数据返回 (Parse interface and data return)
 
  说明 (Description):
  | Type                          | parsedData 类型                          |
  |-------------------------------|------------------------------------------|
  | Success                       | nil                                      |
  | HandshakeRequest              | nil                                      |
  | FileList                      | NSArray<UTEModelRecordFileInfo *> *      |
  | SyncFileStatus                | NSDictionary *                           |
  | FileData                      | UTEModelRecordWiFiDatainfo *             |
  | DeleteFileStatus              | NSDictionary *                           |
  | StopTransmission              | NSDictionary *                           |
 
 返回UTERecordWiFiTypeSuccess，握手成功，anyData为nil； (Handshake success, anyData is nil)
 
 返回UTERecordWiFiTypeShandshakeRequest，握手请求，需要发送握手指令（wifi_handshake），anyData为nil； (Handshake request, need to send wifi_handshake, anyData is nil)
 
 返回UTERecordWiFiTypeFileList，文件列表返回，anyData为NSMutableArray <UTEModelRecordFileInfo *>*array； (File list returned, anyData is file info array)
 
 返回UTERecordWiFiTypeSyncFileStatus，同步文件数据状态返回，anyData为NSDictionary *dict，key：@"session":sessionID, @"status"：status:0文件正常，1文件系统不可用，2文件不存在； (Sync file status returned, anyData is dict with session and status keys)
 
 返回UTERecordWiFiTypeFileData，同步文件数据，anyData为UTEModelRecordWiFiDatainfo *model，文件数据信息； (Sync file data returned, anyData is file data info model)
 
 返回UTERecordWiFiTypeDelFileStatus，删除文件状态，anyData为NSDictionary*dict, key：@"session":sessionID, @"status"：status; status：0删除成功，8文件不存在； (Delete file status returned, anyData is dict with session and status keys)
 
 返回UTERecordWiFiTypeStopTrans，停止传输，anyData为NSDictionary*dict, key：@"status"：status; status：0停止成功； (Stop transmission returned, anyData is dict with status key)
 
 */
-(void)wifi_parseData:(NSData *)data Block:(void(^)(UTERecordWiFiType type,id _Nullable anyData))block;

///wifi_握手指令 (WiFi handshake command)
-(NSData*)wifi_handshake;

///wifi 心跳应答 (WiFi heartbeat response)
-(NSData*)wifi_heartbeatPacket;

///wifi 获取文件列表 (WiFi get file list)
-(NSData *)wifi_getFileList;

/// 获取录音文件 sessionID:请求同步录音文件ID start:文件数据位置开始index end:文件数据位置结束index type:文件格式（类型与ble一致） (Get recording file: sessionID=file ID, start=start index, end=end index, type=file format, same as BLE)
-(NSData *)wifi_getRecordData:(NSInteger)session withStart:(NSInteger)start withEnd:(NSInteger)end withType:(NSInteger)type;

///wifi 停止传输 sessionID：录音文件sessionID type:文件格式（类型与ble一致） (WiFi stop transmission: sessionID=file ID, type=file format, same as BLE)
-(NSData *)wifi_stopTransmission:(NSInteger)session withType:(NSInteger)type;

///wifi 删除文件 sessionID：录音文件sessionID type:文件格式（类型与ble一致） (WiFi delete file: sessionID=file ID, type=file format, same as BLE)
-(NSData *)wifi_delFile:(NSInteger)session withType:(NSInteger)type;

///wifi 关闭WiFi (WiFi close WiFi)
-(NSData *)wifi_closeWiFi;


@end

NS_ASSUME_NONNULL_END

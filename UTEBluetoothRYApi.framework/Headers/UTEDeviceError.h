//
//  UTEDeviceError.h
//  UTEBluetoothRYApi
//
//  Created by V V on 2023/3/21.
//  Copyright © 2023 vv. All rights reserved.
//

#import <Foundation/Foundation.h>
/*!
 *  @enum UTEDeviceErrorType
 */
typedef NS_ENUM(NSInteger, UTEDeviceErrorType) {
    
    UTEDeviceErrorDisconnect            = -1000, //设备已断开
    UTEDeviceErrorCRC                   = -999,  //数据校验失败
    UTEDeviceErrorAppParamEmpty         = -998,  //App参数为空
    
    UTEDeviceErrorCharacteristicNil     = -996,  //SDK的特征值为空
    UTEDeviceErrorNetworkTimeout        = -995,
    UTEDeviceErrorDownload              = -994,
    UTEDeviceErrorFolderOperation       = -993,
    
    UTEDeviceErrorDialSending           = -853,  //表盘数据指令在交互中
    UTEDeviceErrorBetaFile              = -852,  //Beta文件有错误
    UTEDeviceErrorDialCancel            = -851,  //设备主动取消表盘
    UTEDeviceErrorDialFail              = -850,  //表盘操作失败
    UTEDeviceErrorDialOpen              = -849,  //打开文件失败
    UTEDeviceErrorDialRest              = -848,  //重置失败
    UTEDeviceErrorDialCmd               = -847,  //指令失败
    UTEDeviceErrorDialSize              = -846,  //表盘的大小与传入的图片大小不一致
    
    UTEDeviceErrorOTABinNil             = -807,  //文件bin 不存在
    UTEDeviceErrorOTAConfigNil          = -806,  //文件config 不存在
    UTEDeviceErrorOTAUnzipFail          = -805,  //固件解压文件
    UTEDeviceErrorOTADeleteFail         = -804,  //固件删除文件
    UTEDeviceErrorOTADiffVersion        = -803,  //固件版本不一致
    UTEDeviceErrorOTAHighTemperature    = -802,  //设备温度过高
    UTEDeviceErrorOTACancelFail         = -801,  //设备升级取消失败
    UTEDeviceErrorOTAFirmwarePath       = -800,  //固件路径为空
    
    UTEDeviceErrorOTA_JLFail                = -724, //OTA升级失败
    UTEDeviceErrorOTA_JLDataIsNull          = -723, //OTA升级数据为空
    UTEDeviceErrorOTA_JLCommandFail         = -722, //OTA指令失败
    UTEDeviceErrorOTA_JLSeekFail            = -721, //OTA标示偏移查找失败
    UTEDeviceErrorOTA_JLInfoFail            = -720, //OTA升级固件信息错误
    UTEDeviceErrorOTA_JLLowPower            = -719, //OTA升级设备电压低
    UTEDeviceErrorOTA_JLEnterFail           = -718, //未能进入OTA升级模式
    UTEDeviceErrorOTA_JLUpgrading           = -717, //OTA升级中
    UTEDeviceErrorOTA_JLReconnect           = -716, //OTA需重连设备(uuid方式)
    UTEDeviceErrorOTA_JLReboot              = -715, //OTA需设备重启
    UTEDeviceErrorOTA_JLPreparing           = -714, //OTA准备中
    UTEDeviceErrorOTA_JLPrepared            = -713, //OTA准备完成
    UTEDeviceErrorOTA_JLFailVerification    = -712, //升级数据校验失败
    UTEDeviceErrorOTA_JLFailCompletely      = -711, //升级失败
    UTEDeviceErrorOTA_JLFailKey             = -710, //升级数据校验失败
    UTEDeviceErrorOTA_JLFailErrorFile       = -709, //升级文件出错
    UTEDeviceErrorOTA_JLFailUboot           = -708, //uboot不匹配
    UTEDeviceErrorOTA_JLFailLenght          = -707, //升级过程长度出错
    UTEDeviceErrorOTA_JLFailFlash           = -706, //升级过程flash读写失败
    UTEDeviceErrorOTA_JLFailCmdTimeout      = -705, //升级过程指令超时
    UTEDeviceErrorOTA_JLFailSameVersion     = -704, //相同版本
    UTEDeviceErrorOTA_JLFailTWSDisconnect   = -703, //TWS耳机未连接
    UTEDeviceErrorOTA_JLFailNotInBin        = -702, //耳机未在充电仓
    UTEDeviceErrorOTA_JLReconnectWithMacAddr= -701, //OTA需重连设备(mac方式)
    
    
    UTEDeviceErrorOTAFail               = -700,  //升级失败了，原因要看Log
    
    UTEDeviceErrorCommonFail            = -2,    //操作失败
    UTEDeviceErrorOTAUnknow             = -1,    //其他未知不能升级
    
    UTEDeviceErrorNone                  = 0,        //正常（无错误）
    UTEDeviceErrorCmdTimeout            = 408,      //指令超时
    UTEDeviceErrorFileEmpty             = 701,      //文件为空
    UTEDeviceErrorParamEmpty            = 40003,    //参数为空
    UTEDeviceErrorNil                   = 100000,   //正常（无错误）
    
    UTEDeviceErrorOTALowPower           = 109002,//ota传输错误手表电量低
    UTEDeviceErrorOTAProgress           = 109019,//设备ota升级中
    UTEDeviceErrorDialSizeTooBig        = 140009,//设备内存不足
    UTEDeviceErrorDialUpperLimit        = 140004,//表盘数量达上限
};

@interface UTEDeviceError : NSObject

@end



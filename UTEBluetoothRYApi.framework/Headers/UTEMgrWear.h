//
//  UTEMgrGlassesEarphone.h
//  UTEBluetoothRYApi
//
//  Created by V V on 2025/5/26.
//  Copyright © 2025 vv. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "UTEModelDevice.h"

@interface UTEMgrWear : NSObject

//See method(onNotifyUploadImg:)
@property (nonatomic,assign)BOOL isUploadingImg;

#pragma mark - Time
- (void)setTime:(NSInteger)time1970 block:(void(^)(UTEDeviceError errorCode))block;
- (void)setTimeFormat:(UTEDisplayTimeType)type block:(void(^)(UTEDeviceError errorCode))block;
/*
 东8.15时区为timeZone:8 offset:15
 东八区timeZone:8  offset:0
 西八区timeZone:-8 offset:0
 
 timeZone: -12 ~ 12
 minuteOffset
 
 East 8.15 is timeZone: 8 offset: 15;
 East Eighth District timeZone: 8 offset: 0;
 West Eighth District timeZone: -8 offset: 0;
 */
- (void)setTimeZone:(NSInteger)timeZone
              offset:(NSInteger)offset
               block:(void(^)(UTEDeviceError errorCode))block;

- (void)setDateFormat:(UTEDisplayDateType)type block:(void(^)(UTEDeviceError errorCode))block;
- (void)readTimeInfo:(void(^)(UTEModelTimeInfo *model,UTEDeviceError errorCode))block;

#pragma mark - Device Info Set
/**
 *  @discussion Device Password
 *  @param password The password requires 8 digits
 *
 *  Return:  Whether the data has already been sent
 */
- (BOOL)setPassword:(NSInteger)password block:(void(^)(UTEPasswordStatus status))block;
/**
 *  @discussion SN (It can only be numbers or letters.)
 */
- (void)setSN:(NSString *)sn block:(void(^)(UTEDeviceError errorCode))block;


/**
 *  @discussion Device language (Currently, only Chinese and English settings are supported.)
 */
- (void)setLanguage:(UTERYDeviceLanguage)language block:(void(^)(UTEDeviceError errorCode))block;

/**
 *  @discussion MAC (It can only be numbers or letters.)
 *  e.g. aabbcc112233
 */
- (void)setMac:(NSString *)mac block:(void(^)(UTEDeviceError errorCode))block;
/**
 *  @discussion Device Name (It can only be numbers or letters.)
 */
- (void)setDeviceName:(NSString *)name block:(void(^)(UTEDeviceError errorCode))block;
- (void)setDeviceSettingsType:(UTESystemSettingsType)type block:(void(^)(UTEDeviceError errorCode))block;
#pragma mark - Device Info Read
- (void)readDeviceInfo:(void(^)(UTEModelDeviceExtraInfo *info,UTEDeviceError errorCode))block;
/**
 *  @discussion Read mac
 *  e.g.  aabbcc112233
 */
- (void)readMac:(void(^)(NSString *macStr,UTEDeviceError errorCode))block;
- (void)readCertifiedModel:(void(^)(NSString *modelStr,UTEDeviceError errorCode))block;

- (void)readGlassesSN:(void(^)(NSString *sn,UTEDeviceError errorCode))block;
- (void)readGlassesID:(void(^)(NSString *ID,UTEDeviceError errorCode))block;
- (void)readISPVerBlock:(void(^)(NSString *version,UTEDeviceError errorCode))block;

- (void)readDeviceModel:(void(^)(NSString *version,UTEDeviceError errorCode))block;
- (void)readEarphoneSN:(void(^)(NSString *sn,UTEDeviceError errorCode))block;

- (void)readHardwareVer:(void(^)(NSString *version,UTEDeviceError errorCode))block;
- (void)readDeviceVer:(void(^)(NSString *version,UTEDeviceError errorCode))block;
- (void)readOTARegion:(void(^)(UTERegionType region,UTEDeviceError errorCode))block;
- (void)readBattery:(void(^)(NSInteger battery,UTEBatteryStatus status,UTEDeviceError errorCode))block;
#pragma mark - notify
/**
 *  @discussion Notify device battery
 */
- (void)onNotifyBattery:(void(^)(NSInteger battery,UTEBatteryStatus status))block;
- (void)onNotifyDeviceStatus:(void(^)(UTEWearStatus status))block;

#pragma mark - Glasses Read
- (void)readDeviceStatus:(void(^)(UTEWearStatus status))block;
- (void)readDeviceVideoDirection:(void(^)(UTEDirectionType type))block;
- (void)readAudioStyle:(void(^)(UTEAudioStyle type))block;
- (void)readLedLevel:(void(^)(UTELedLevel level))block;
- (void)readEarphoneInfo:(void(^)(UTEModelEarphoneInfo *info,UTEDeviceError err))block;
/**
 *  @discussion The maximum length of time to record a video (Unit: seconds )
 */
- (void)readVideoDuration:(void(^)(NSInteger duration))block;
- (void)readStorageInfo:(void(^)(NSArray<UTEModelStorageInfo *> *array))block;
- (void)readGlassesInfo:(void(^)(UTEModelGlassesInfo *model,UTEDeviceError err))block;
- (void)readDeviceFiles:(void(^)(NSArray<NSString *> *array,UTEDeviceError err))block;
- (void)readAiAwakeEnable:(void(^)(BOOL enable))block;

#pragma mark - Device Set
- (void)setAiAwakeEnable:(BOOL)enable block:(void(^)(BOOL success))block;
- (void)setVideoDirection:(UTEDirectionType)type block:(void(^)(UTEDeviceError err))block;
/**
 *  @discussion Set Video duration (Unit: seconds , The maximum video recording duration is 600 seconds)
 */
- (void)setVideoDuration:(NSInteger)duration block:(void(^)(UTEDeviceError err))block;
//camera setting
- (void)setCameraSystemSettingsType:(UTESystemSettingsType)type block:(void(^)(UTEDeviceError errorCode))block;
- (void)deleteDeviceFile:(NSString *)file block:(void(^)(UTEDeviceError err))block;

#pragma mark - Earphone Set

- (void)setAudioStyle:(UTEAudioStyle)type block:(void(^)(UTEDeviceError errorCode))block;
- (void)setLedLevel:(UTELedLevel)level block:(void(^)(UTEDeviceError errorCode))block;
//Device bluetooth setting
- (void)setDeviceSystemSettingsType:(UTESystemSettingsType)type block:(void(^)(UTEDeviceError errorCode))block;

#pragma mark - Control
/**
 *  @discussion If isUploadingImg = yes, then the method cannot be invoke
 */
- (void)controlType:(UTEControlType)type result:(void(^)(BOOL success))block;

- (void)onNotifyControlStatus:(void(^)(UTEControlStatus status))block;
/**
 *  @discussion Music Control
 */
- (void)controlMedia:(UTEControlMedia)type result:(void(^)(BOOL success))block;

/**
 *  @discussion GPS coordinates are all multiplied by 1,000,000
 */
- (void)controlPicture:(int32_t)longitude latitude:(int32_t)latitude result:(void(^)(BOOL success))block;

/**
 *  @discussion Notify the device to update the media file list
 */
- (void)updateFilesAmount:(void(^)(BOOL success))block;

#pragma mark - stabilization calibration

- (void)cameraStabilizationCalibration:(void(^)(UTEStabilizationCalibrationStatus status))block;


#pragma mark - Device AI

/**
 *  @discussion Send Data to Starburst AI
 *  @data the data of third party mode
 */
- (void)sendDataToDeviceAi:(NSData *)data;
- (void)checkAuthStarburstAI:(void(^)(UTEModelOfflineVoiceAuth *model ,UTEDeviceError errorCode))block;
/**
 *  @discussion Start Auth Starburst AI
 *  @data Please return the data to the third party ai mode.
 *  @success Authorization completed successfully
 *  @errorCode Error Codel
 *
 */
- (void)startAuthStarburstAI:(void(^)(NSData *data,BOOL success ,UTEDeviceError errorCode))block;
- (void)controlUploadAiVoiceStatus:(UTEVoiceAiStatus)status result:(void(^)(BOOL success))block;
- (void)onNotifyAiVoiceAwake:(void (^)(void))block;

#pragma mark - AI Image Analysis
/**
 *  @discussion The device automatically uploads images
 */
- (void)onNotifyUploadImg:(void(^)(UIImage *img, CGFloat process,BOOL finish, UTEDeviceError errorCode))block;
/**
 *  @discussion The device automatically uploads audio
 */
- (void)onNotifyUploadAudio:(void(^)(NSData *data, UTEAudioType style, UTEDeviceError errorCode,BOOL finish))block;
#pragma mark - OTA
/**
 * Check the status of the device upgrade
 * Note:Please see UTEBluetoothMgr.sharedInstance().mgrOTA.onNotifyWearOTAStatus
 */
- (void)checkStatusOTA;

#pragma mark - SD Card
/**
 *  @discussion SDCard Status
 *  Note:If UTEWearSDCardStatusAbnormal is received, invoke setGlassesSystemSettingsType:UTESystemSettingsTypeReset to format the SD card and restore its normal functions.
 */
- (void)onNotifySDCardStatus:(void(^)(UTEWearSDCardStatus status))block;


#pragma mark - Factory Test
- (void)debugVideo:(NSInteger)height
                     width:(NSInteger)width
                       fps:(NSInteger)fps
                heightJPG:(NSInteger)heightJPG
                 widthJPG:(NSInteger)widthJPG
             block:(void(^)(UTEDeviceError errorCode))block;

- (void)factoryReadFunction:(void(^)(NSArray<UTEWearFunctionModel *> *array,UTEDeviceError errorCode))block;
- (void)factorySpeaker:(BOOL)enable type:(UTESpeakerType)type block:(void(^)(BOOL success,UTEDeviceError errorCode))block;
- (void)factoryLED:(BOOL)enable type:(UTELEDType)type block:(void(^)(BOOL success,UTEDeviceError errorCode))block;
- (void)factoryMic:(BOOL)enable type:(UTEMicType)type block:(void(^)(BOOL success,UTEDeviceError errorCode))block;
- (void)factoryButton:(UTEButtonKey)type block:(void(^)(BOOL success,UTEDeviceError errorCode))block;
- (void)factoryTP:(UTEButtonTP)type block:(void(^)(BOOL success,UTEDeviceError errorCode))block;
- (void)factoryHall:(BOOL)enable block:(void(^)(BOOL success,UTEDeviceError errorCode))block;
- (void)factoryGsensor3:(BOOL)enable block:(void(^)(BOOL success,UTEDeviceError errorCode))block;
- (void)factorySenorLight:(BOOL)enable block:(void(^)(BOOL success,UTEDeviceError errorCode))block;
- (void)factoryGsensor6:(BOOL)enable block:(void(^)(BOOL success,UTEDeviceError errorCode))block;

- (void)factoryStopAll;

- (void)onNotifyFactoryHall:(void(^)(BOOL open))block;
- (void)onNotifyFactoryGsensor3:(void(^)(NSInteger x,NSInteger y, NSInteger z))block;
- (void)onNotifyFactoryGsensor6:(void(^)(NSInteger angle,NSInteger x,NSInteger y, NSInteger z))block;
- (void)onNotifyFactorySensorLight:(void(^)(BOOL value))block;
- (void)onNotifyFactoryTP:(void(^)(NSInteger value))block;
- (void)onNotifyFactoryKey:(void(^)(NSInteger value))block;

@end



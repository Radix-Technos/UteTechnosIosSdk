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
#import "UTEDeviceError.h"

@interface UTEMgrGlassesEarphone : NSObject

#pragma mark - Time
- (void)setTime:(NSInteger)time1970 block:(void(^)(UTEDeviceErrorType errorCode))block;
- (void)setTimeFormat:(UTEDisplayTimeType)type block:(void(^)(UTEDeviceErrorType errorCode))block;
- (void)setDateFormat:(UTEDisplayDateType)type block:(void(^)(UTEDeviceErrorType errorCode))block;
- (void)readTimeInfo:(void(^)(UTEModelTimeInfo *model,UTEDeviceErrorType errorCode))block;

#pragma mark - Device Info Set
/**
 *  @discussion SN (It can only be numbers or letters.)
 */
- (void)setSN:(NSString *)sn block:(void(^)(UTEDeviceErrorType errorCode))block;
/**
 *  @discussion MAC (It can only be numbers or letters.)
 *  e.g. aabbcc112233
 */
- (void)setMac:(NSString *)mac block:(void(^)(UTEDeviceErrorType errorCode))block;
/**
 *  @discussion Device Name (It can only be numbers or letters.)
 */
- (void)setDeviceName:(NSString *)name block:(void(^)(UTEDeviceErrorType errorCode))block;
- (void)setDeviceSettingsType:(UTESystemSettingsType)type block:(void(^)(UTEDeviceErrorType errorCode))block;
#pragma mark - Device Info Read
- (void)readDeviceInfo:(void(^)(UTEModelDeviceExtraInfo *info,UTEDeviceErrorType errorCode))block;
/**
 *  @discussion Read mac
 *  e.g.  aabbcc112233
 */
- (void)readMac:(void(^)(NSString *macStr,UTEDeviceErrorType errorCode))block;
- (void)readCertifiedModel:(void(^)(NSString *modelStr,UTEDeviceErrorType errorCode))block;

- (void)readGlassesSN:(void(^)(NSString *sn,UTEDeviceErrorType errorCode))block;
- (void)readGlassesID:(void(^)(NSString *ID,UTEDeviceErrorType errorCode))block;
- (void)readGlassesSoftwareVer:(void(^)(NSString *version,UTEDeviceErrorType errorCode))block;

- (void)readEarphoneVer:(void(^)(NSString *version,UTEDeviceErrorType errorCode))block;
- (void)readEarphoneSoftwareVer:(void(^)(NSString *version,UTEDeviceErrorType errorCode))block;
- (void)readEarphoneSN:(void(^)(NSString *sn,UTEDeviceErrorType errorCode))block;

- (void)readHardwareVer:(void(^)(NSString *version,UTEDeviceErrorType errorCode))block;
- (void)readDeviceVer:(void(^)(NSString *version,UTEDeviceErrorType errorCode))block;
- (void)readOTARegion:(void(^)(UTERegionType region,UTEDeviceErrorType errorCode))block;
- (void)readBattery:(void(^)(NSInteger battery,UTEDeviceErrorType errorCode))block;
#pragma mark - notify
/**
 *  @discussion Notify device battery
 */
- (void)onNotifyBattery:(void(^)(NSInteger battery))block;

- (void)onNotifyGlassesStatus:(void(^)(UTEGlassesStatus status))block;

#pragma mark - Glasses Read
- (void)readGlassesStatus:(void(^)(UTEGlassesStatus status))block;
- (void)readGlassesVideoDirection:(void(^)(UTEDirectionType type))block;
/**
 *  @discussion The maximum length of time to record a video (Unit: seconds )
 */
- (void)readGlassesVideoDuration:(void(^)(NSInteger duration))block;
- (void)readGlassesStorageInfo:(void(^)(NSArray<UTEModelStorageInfo *> *array))block;
- (void)readGlassesInfo:(void(^)(UTEModelGlassesInfo *model,UTEDeviceErrorType err))block;
- (void)readGlassesFiles:(void(^)(NSArray<NSString *> *array,UTEDeviceErrorType err))block;

#pragma mark - Glasses Set
- (void)setGlassesVideoDirection:(UTEDirectionType)type block:(void(^)(UTEDeviceErrorType err))block;
/**
 *  @discussion Set Glasses Video duration (Unit: seconds , The maximum video recording duration is 600 seconds)
 */
- (void)setGlassesVideoDuration:(NSInteger)duration block:(void(^)(UTEDeviceErrorType err))block;
- (void)setGlassesSystemSettingsType:(UTESystemSettingsType)type block:(void(^)(UTEDeviceErrorType errorCode))block;
- (void)deleteGlassesFile:(NSString *)file block:(void(^)(UTEDeviceErrorType err))block;

#pragma mark - Earphone Read
- (void)readEarphoneAudioType:(void(^)(UTEAudioType type))block;
- (void)readEarphoneLedLevel:(void(^)(UTELedLevel level))block;
- (void)readEarphoneInfo:(void(^)(UTEModelEarphoneInfo *info,UTEDeviceErrorType err))block;

#pragma mark - Earphone Set
/**
 *  @discussion Device Password
 *  @param password The password requires 8 digits
 *
 *  Return:  Whether the data has already been sent
 */
- (BOOL)setEarphonePassword:(NSInteger)password block:(void(^)(UTEPasswordStatus status))block;
- (void)setEarphoneAudioType:(UTEAudioType)type block:(void(^)(UTEDeviceErrorType errorCode))block;
- (void)setEarphoneLedLevel:(UTELedLevel)level block:(void(^)(UTEDeviceErrorType errorCode))block;
- (void)setEarphoneSystemSettingsType:(UTESystemSettingsType)type block:(void(^)(UTEDeviceErrorType errorCode))block;
@end



//
//  UTESmartBandClient.h
//  UTESmartBandClient
//
//  Created by VV on 14/11/28.
//  Copyright © 2014年 vv. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <UIKit/UIKit.h>
#import "UTEManagerDelegate.h"
#import "UTEModel.h"

#pragma mark - UTESmartBandClient

typedef void(^cardApduResponseBlock)(NSData * _Nullable data,BOOL success);

/*!
 *  UTESmartBandClient
 */
@interface UTESmartBandClient : NSObject

/**
 *   Default false 
 */
@property (nonatomic,assign ) BOOL  debugUTELog;
/**
 *   Default UTELogTypePrint
 *   When debugUTELog=yes, it is valid.
 */
@property (nonatomic,assign ) UTELogType  logType;
/**
 *  Delegate
 */
@property (nonatomic,weak   ) id<UTEManagerDelegate> _Nullable delegate;
/**
 *  Bluetooth status
 */
@property (nonatomic,assign,readonly) UTEBluetoothState     bluetoothState;
/**
 *  Whether the device is in sync data
 */
@property (nonatomic,assign,readonly) BOOL  isSyncDevices;
/**
 *  When the device is synchronizing data, the app can also send other commands
 */
@property (nonatomic,assign,readonly) BOOL  isHandleSync;
/**
 *  Whether the device is being upgraded
 */
@property (nonatomic,assign,readonly) BOOL  isUpdateDevices;
/**
 *  Whether the device is testing heart rate
 */
@property (nonatomic,assign,readonly) BOOL  isHeartDetecting;
/**
 *  Whether the device is testing blood pressure
 */
@property (nonatomic,assign,readonly) BOOL  isBloodDetecting;
/**
 *  Whether the device is testing blood oxygen
 */
@property (nonatomic,assign,readonly) BOOL  isBloodOxygenDetecting;
/**
 *  Whether the device is testing blood glucose
 */
@property (nonatomic,assign,readonly) BOOL  isBloodGlucoseDetecting;
/**
 *  Whether the device is testing HRV
 */
@property (nonatomic,assign,readonly) BOOL  isHRVDetecting;
/**
 *  Whether the device is testing respiration
 */
@property (nonatomic,assign,readonly) BOOL  isRespirationDetecting;
/**
 *  Whether the device is testing Body fat
 */
@property (nonatomic,assign,readonly) BOOL  isBodyFatDetecting;
/**
 *  Whether the device is testing ECG
 */
@property (nonatomic,assign,readonly) BOOL  isECGDetecting;
/**
 *  Device is monitoring Mood, Pressure and Fatigue
 */
@property (nonatomic,assign,readonly) BOOL  isMPFDetecting;
/**
 *  Custom data is still being sent
 */
@property (nonatomic,assign,readonly) BOOL  isCustomDataSending;
/**
 *  Device sport mode status
 */
@property (nonatomic,assign,readonly) UTEDeviceSportModeStatus  sportModeStatus;
/**
 *  Device's sharing system notification permission on the mobile phone's Bluetooth interface
 */
@property (nonatomic,assign,readonly) BOOL  ancsAuthorized NS_AVAILABLE_IOS(13_0);
/**
 *  See UTEDeviceSportMode
 */
@property (nonatomic,assign,readonly) UTEDeviceSportMode  sportMode;
/**
 *  Whether the device is changing device feature.
 *  Note:When isRKDevices=YES, don't need to consider this value.
 */
@property (nonatomic,assign,readonly) BOOL  isChangeFeature;
/**
 *  Whether the heart rate is being calibrated.
 *  Note:Any value sent by the App to the device during the calibration process is invalid.
 */
@property (nonatomic,assign,readonly) BOOL  isHRMCalibrating;
/**
 *  Blood pressure is being calibrated
 */
@property (nonatomic,assign,readonly) BOOL  isBloodCalibrating;
/**
 *  Blood PPG is being calibrated
 */
@property (nonatomic,assign,readonly) BOOL  isBloodPPGCalibrating;
/**
 *  Blood PPG Mode
 */
@property (nonatomic,assign,readonly) BOOL  isBloodPrecisionMode;
/**
 *  Whether the 'Raise wrist' is being calibrated.
 *  Note:Any value sent by the App to the device during the calibration process is invalid.
 */
@property (nonatomic,assign,readonly) BOOL  isRaiseHandCalibrating;
/**
 *  Connected Device
 *  Note:
 *  When connected, SDK will automatically assign each attribute.When disconnected, value is nil.
 *  Do not change the value inside this attribute.
 */
@property (nonatomic,strong) UTEModelDevices  * _Nullable connectedDevicesModel;
/**
 *  Sets the name of the specified device to be scanned. It is case sensitive. The default is nil.
 */
@property (nonatomic,copy  ) NSString    * _Nullable filterName;
/**
 *  Set the signal strength of the device to be scanned.
 *  Range(0 > filerRSSI > -100, default -70)
 */
@property (nonatomic,assign) NSInteger    filerRSSI;
/**
 *  Specify a device to scan, which services are included. e.g. [@"55dd",@"66ff"], default nil.
 *  The UUID of the same product device is the same.
 *  Note:You can use third-party software (Lightblue) to connect the device to view the broadcast UUID.
 *  (Lightblue has key value Service UUIDs in Adverisement Data)
 */
@property (nonatomic,strong) NSArray      * _Nullable filerServers;
/**
 *  The UUID of different products is different. e.g. @[ @[@"55dd",@"66ff"], @[@"22dd",@"33ff"] ]
 *  Note:You can use third-party software (Lightblue) to connect the device to view the broadcast UUID.
 *  (Lightblue has key value Service UUIDs in Adverisement Data)
 */
@property (nonatomic,strong) NSArray      * _Nullable filerServersArray;
/**
 *  Scan devices repeatedly, default NO.
 *  Note:If yes,the signal value of the device is updated in real time during the scanning process.
 */
@property (nonatomic,assign) BOOL         isScanRepeat;
/**
 *  Delay connecting devices. In order to prevent some devices from connecting too fast, the app has not yet read the data of the device.
 *  Units: seconds
 */
@property (nonatomic,assign) CGFloat      delayTimeConnect;
/**
 *  Scan devices without filtering, default NO.
 *  Note:
 *  1.If yes,filterName/filerServers/filerServersArray is invalid.
 *  2.Delegate uteManagerDiscoverDevices: will show all surrounding devices
 *  3.If an unsupported device is connected using method connectUTEModelDevices: , the SDK will not have any callback, please invoke method disConnectUTEModelDevices: to disconnect.
 */
@property (nonatomic,assign) BOOL         isScanAllDevice;
/**
 *  Connect device, skip pair (The watch interface will not pop up a pair button)
 */
@property (nonatomic,assign) BOOL         isConnectSkipPair;
/**
 *  Set this value in advance, and then call the connected device. When the connection status between the device and the app changes,
 *  when the app is in the background, the phone will pop up a system dialog prompt. Default UTEDeviceAlertTypeRequiresANCS.
 *  Note:DeviceAlertType only works if Bluetooth background permissions are not enabled in "Background Mode" in xcode.
 */
@property (nonatomic,assign) UTEDeviceAlertType   deviceAlertType;
@property (nonatomic,assign) UTEDeviceAlertType   deviceAlertTypeExcluding;
/**
 *   Whether the device is RK platform
 */
@property (nonatomic,assign,readonly) BOOL isRKDevices;
/**
 *   Whether the device is NR platform
 */
@property (nonatomic,assign,readonly) BOOL isNRDevices;
/**
 *   Whether the device is SYD platform
 */
@property (nonatomic,assign,readonly) BOOL isSYDDevices;
/**
 *   Whether the device is ATS platform (3085L)
 */
@property (nonatomic,assign,readonly) BOOL isATSDevices;
/**
 *   Whether the device is FRQ platform
 */
@property (nonatomic,assign,readonly) BOOL isFRQDevices;
/**
 *   Whether the device is ACX platform
 */
@property (nonatomic,assign) BOOL isACXDevices;
/**
 *   Whether the device is RY platform
 */
@property (nonatomic,assign) BOOL isRYDevices;
/**
 *   Whether the device is 3085s platform
 */
@property (nonatomic,assign) BOOL is3085sDevices;
/**
 *   Whether the device is 8773ewe platform
 */
@property (nonatomic,assign) BOOL is8773eweDevices;
/**
 *   Does the device's connection require a password
 */
@property (nonatomic,assign,readonly) BOOL isHasPassword;
/**
 *   Whether the connection of the device needs to set a user ID
 *   See setUTEUserID:
 *
 *   Note:If YES, App must set the ID (the device will verify that it is connected to the same App).
 *   If the ID is not set or the ID is inconsistent, the device will not process any instructions
 *   and will actively disconnect after 30 seconds.
 */
@property (nonatomic,assign,readonly) BOOL isHasUserID;
/**
 *   Supports sending userids on the device's QR code interface
 */
@property (nonatomic,assign,readonly) BOOL isHasUserIDQRCode;
/**
 *   Raw data log
 */
@property (nonatomic,assign) BOOL isOpenRawDataLog;
/**
 *   Device is transportation card
 */
@property (nonatomic,assign) BOOL         isCardDevices;
/** 
 *   Whether the Apdu channel is open
 */
@property (nonatomic,assign,readonly) BOOL isOpenApdu;
/**
 *  Data returned by Apdu channel
 */
@property (nonatomic,copy) cardApduResponseBlock _Nullable  cardApduResponseBlock;
@property (nonatomic,assign) BOOL           dialTest;
@property (nonatomic,assign) BOOL           firmwareTest;

#pragma mark - UTESmartBandClient

/**
 *  @return UTESmartBandClient
 */
+ (UTESmartBandClient *_Nonnull)sharedInstance;

/**
 *  @discussion Initialize UTESmartBandClient to allow SDK to obtain Bluetooth management and proxy permissions
 */
- (void)initUTESmartBandClient;

/**
 *  @discussion Scan for surrounding devices
 */
- (void)startScanDevices;

/**
 *  @discussion Stop scanning devices
 */
- (void)stopScanDevices;

/**
 *  @discussion Connect the device
 *
 *  @param model identifier cannot be nil
 *  Note:If you can’t connect to the device for a long time, please call disConnectUTEModelDevices first, and then call connectUTEModelDevices after 0.3 seconds. This may improve the chance of connection.
 */
- (void)connectUTEModelDevices:(UTEModelDevices *_Nonnull)model;

/**
 *  @discussion Check which known devices are connected to the system.
 *
 *  Note:Currently Apple does not provide a method to query which devices and systems are paired
 *
 *  @param  UUID What services does the device have, can fill in one or more services. e.g. @[@"EFF5"]. or @[@"EFF5",@"12B5"].
 *  See mServicesConnectedUUID in UTEModelDevices.
 *  For the same series of devices, the mServicesConnectedUUID is fixed.
 *
 *  @return If there are no connected devices, 0 will be returned. If yes, then only attributes 'identifier' and 'name' in UTEModelDevices have values.
 */
- (NSArray<UTEModelDevices *> *_Nullable)retrieveConnectedDeviceWithServers:(NSArray<NSString *> *_Nonnull)UUID;

/**
*  @discussion Check if the QR code is valid
*
*  @param qrCode identifier cannot be nil
*
*  @return If valid(e.g @"78:55:55:65:33:88"), returns the Bluetooth advertisement address by the device. As well see UTEModelDevices.advertisementAddress .
*/
- (NSString *_Nullable)checkUTEDeviceQRCode:(NSString *_Nonnull)qrCode;

/**
 *  @discussion Disconnect the device
 *
 *  @param model identifier cannot be nil
 *
 *  @return Whether this method is actually executed
 */
- (BOOL)disConnectUTEModelDevices:(UTEModelDevices *_Nonnull)model;

/**
 *  @discussion Set some device information
 *
 *  @param option See UTEOption
 *
 *  @return Whether this method is actually executed. You can invoke checkUTEDevicesStateIsEnable: method to check if it can be set.
 */
- (BOOL)setUTEOption:(UTEOption)option;

/**
 *   @discussion Set up additional information
 *   Please invoke 'setUTEOption:' to set the device unit( meters or feet) before calling this method.
 *   If it is not invoke 'setUTEOption:', or invoke fails, the distance and calories may all be 0.
 *
 *   @param model See UTEModelDeviceInfo
 *
 */
- (BOOL)setUTEInfoModel:(UTEModelDeviceInfo *_Nonnull)model;

/**
 *  @discussion Send password
 *
 *  @param password Must be a 4-digit number. e.g. @"1234"
 *
 *  @param type See UTEPasswordType
 */
- (void)sendUTEPassword:(NSString *_Nonnull)password type:(UTEPasswordType)type;

/**
 *  @discussion KEY
 *  If there is a key, you must set it every time you turn on the App.
 *
 *  @param key e.g. @"aaaaaaaaaaaa11111"
 */
- (void)setUTESDKKey:(NSString *_Nonnull)key;

/**
 *  @discussion Region
 *  Set the region where the SDK is located.
 *
 *  @param region  e.g. @"zh-Hans"  @"zh"
 *  The SDK will compare it to the system language.
 */
- (void)setUTESDKRegion:(NSString *_Nonnull)region;

#pragma mark - SN
/**
 *  @discussion Read Device serial number
 *
 *  sn: Serial number
 *  maxLenght: Maximum length of serial number
 *
 *  Not every product has SN, please ask your product manager for details.
 */
- (BOOL)readUTEDeviceSN:(void(^_Nullable)(NSString * _Nullable sn ,NSInteger maxLenght))result;
/**
 *  @discussion Set Device serial number
 *  @param sn  Only numbers and letters,
 *  Cannot exceed the maximum length of the serial number. See readUTEDeviceSN (get maxLenght)
 *
 *    Note:
 *    1. Please clear the SN first, and then write the SN.
 *    2. Not every product has SN, please ask your product manager for details.
 */
- (BOOL)setUTEDeviceSN:(NSString *_Nonnull)sn result:(void(^_Nullable)(BOOL success))result;
/**
 *  @discussion Clear Device serial number
 *  Not every product has SN, please ask your product manager for details.
 */
- (BOOL)clearUTEDeviceSN:(void(^_Nullable)(BOOL success))result;
#pragma mark - Alarm Clock
/**
 *  @discussion Set alarm
 *
 *  @param array See UTEModelAlarm (Up to 3 , If isHasClockTitle = YES, up to 5 . If isHasClockType = YES ,up to 10)
 *  @param count Number of alarm vibrations (0-9); if the UTEModelAlarm attribute 'countVibrate' is not equal to 0, then 'countVibrate' will prevail.
 *
 *  Note: If isHasClockTitle = YES, To delete all alarms, please fill in the parameter array as nil .
 *  Note: If isHasLocalAlarmClock = YES, this method is invalid.
 */
- (BOOL)setUTEAlarmArray:(NSArray<UTEModelAlarm *> *_Nullable)array vibrate:(NSInteger)count;

/**
 *  @discussion Set alarm
 *
 *  @param array See UTEModelAlarm (Up to 3 , If isHasClockTitle = YES up to 5)
 *  @param count Number of alarm vibrations (0-9); if the UTEModelAlarm attribute 'countVibrate' is not equal to 0, then 'countVibrate' will prevail.
 *
 *  @param result If isHasClockTitle = NO, result is invalid.
 *  
 *  Note: If isHasClockTitle = YES, To delete all alarms, please fill in the parameter array as nil .
 *  Note: If isHasLocalAlarmClock = YES, this method is invalid.
 */
- (BOOL)setUTEAlarmArray:(NSArray<UTEModelAlarm *> *_Nullable)array vibrate:(NSInteger)count result:(void(^_Nullable)(BOOL success))result;

/**
 *  @discussion Read device alarm information
 *  Required isHasClockTitle=Yes.
 *  @param result also callback  delegate uteManagerReceiveAlarmChange:success
 */
- (BOOL)readUTEAlarm:(void(^_Nullable)(NSArray<UTEModelAlarm *> * _Nullable array, BOOL success))result;

#pragma mark - Sit Remind
/**
 *  @discussion Sedentary reminder (12 to 14 noon and night sleep time, no reminder)
 *  Note:When isHasSitRemindDuration = Yes，please invoke sendUTESitRemindModel:(But, If isHasSleepSporadic=YES, method is not valid)
 *
 *  Note:If isHasSleepSporadic=YES, This method is valid, and remindTime Fixed to 1 hour.
 *
 *  @param remindTime How long to sit for long, then remind. Unit minute,range<10,180>.
 */
- (void)setUTESitRemindOpenTime:(NSInteger)remindTime;

/**
 *  @discussion Turn off sedentary reminder
 */
- (void)setUTESitRemindClose;

/**
 *  @discussion   Set sedentary reminder
 *  Required:isHasSitRemindDuration = Yes
 *  Note:If isHasSleepSporadic=YES, UTEModelDeviceSitRemind.duration is not valid. (Fixed for 60)
 *
 *  @param model  See UTEModelDeviceSitRemind
 */
- (void)sendUTESitRemindModel:(UTEModelDeviceSitRemind *_Nonnull)model;

#pragma mark - User ID
/**
 *  @discussion Set User ID
 *  Required isHasUserID=Yes
 *  See delegate uteManagerUserIDStatus:
 *
 *  ID range 1 ~  9999 9999
 *
 *  Note:If the ID is incorrect, the device will be disconnected directly.
 */
- (void)setUTEUserID:(NSUInteger)ID;

/**
 *  @discussion Read User ID
 *  Required isHasUserID=Yes
 *
 *  Note:If ID = 0,indicates that the device has no ID.
 *
 *  @return It sends successfully or fails
 */
- (BOOL)readUTEUserID:(void(^_Nullable)(NSUInteger ID))result;

/**
 *  @discussion Set User ID
 *  Required isHasUserIDQRCode=Yes
 *  See delegate uteManagerUserIDStatus:
 *
 *  ID range 1 ~  9999 9999
 *  qrCode range 1 ~  9999 9999
 *  connectID range 1 ~  255
 *
 *  Note:
 *  1. If not on the QR code interface, please fill in 0 for qrCode
 *  2. If connectID is 0, indicate that Connecting the device for the first time; if connectID is 1, indicate that Each reconnection of device.
 */
- (void)setUTEUserID:(NSUInteger)ID qrCode:(NSUInteger)qrCode connectID:(UInt8)connectID;

#pragma mark - Bluetooth3.0
/**
 *  @discussion Read UTEBluetooth3.0 Status
 *  Required isHasBluetooth3=Yes
 *
 *  See delegate  uteManagerReceiveBluetooth3Info:
 */
- (BOOL)readUTEBluetooth3Status;

/**
 *  @discussion Set Bluetooth3.0 key
 *  Required isHasBluetooth3=Yes
 *
 *  See  delegate uteManageUTEOptionCallBack:UTECallBluetooth3_0Key
 *
 *  @param key  Range: 1~99999999
 *  @param allow  Allow Bluetooth 3.0 to connect to apps when pairing phones
 */
- (BOOL)setUTEBluetooth3_0Key:(NSInteger)key allowConnect:(BOOL)allow;

/**
 *  @discussion Device BT3.0 switch control
 *
 *  @return It sends successfully or fails
 */
- (BOOL)setUTEBluetooth3_0Open:(BOOL)on result:(void(^_Nullable)(BOOL success))result;

#pragma mark - Weather
/**
 *  @discussion Read UV
 *
 *  @param result UV index. Range:0~15
 *
 *  Note:Corresponding 5 levels.
 *  Weakest:0~2
 *  Weak:3~5
 *  Medium:6~8
 *  Strong:9~11
 *  Very strong:12 or more
 *
 *  @return It sends successfully or fails
 */
- (BOOL)readUTEDeviceUV:(void(^_Nullable)(NSInteger value))result;
/**
 *  @discussion Set the 7-day weather of the device
 *  Required:isHasWeatherSeven = YES
 *
 *  @param weatherArray It contains 7 days of weather information, and each day is a UTEModelWeather
 *  Please place them in order, index 0 is the first day (today) ... index 6 is the seventh day, and you need to write 7 models.
 *  if isHasWeather24Hours = Yes, Only 6 models need to be filled in.
 *
 *  @return It sends successfully or fails
 */
- (BOOL)sendUTESevenWeather:(NSArray<UTEModelWeather*> *_Nonnull)weatherArray;

/**
 *  @discussion Set the 2-day weather of the device
 *  Required:isHasWeather = YES
 *
 *  @param todayType    See UTEWeatherType
 *  @param currentTemp  Current Temperature
 *  @param maxTemp      Highest temperature today
 *  @param minTemp      Lowest temperature today
 *  @param pm25         Today PM2.5
 *  @param aqi          Air quality today
 *
 *  @param tomorrowType See UTEWeatherType
 *  @param tmrMax       Highest temperature tomorrow
 *  @param tmrMin       Lowest temperature tomorrow
 *
 *  @return It sends successfully or fails
 */
- (BOOL)sendUTETodayWeather:(UTEWeatherType)todayType
                currentTemp:(NSInteger)currentTemp
                    maxTemp:(NSInteger)maxTemp
                    minTemp:(NSInteger)minTemp
                       pm25:(NSInteger)pm25
                        aqi:(NSInteger)aqi
               tomorrowType:(UTEWeatherType)tomorrowType
                     tmrMax:(NSInteger)tmrMax
                     tmrMin:(NSInteger)tmrMin;
/**
 *  @discussion Get the weather type supported by the device according to the weather code
 *
 *  @param weatherCode e.g. 101 , Weather icons and weather codes See https://dev.qweather.com/docs/start/icons
 *
 *  @return See UTEWeatherType
 *
 *  Note:You can freely organize all weather into the types(UTEWeatherType) supported by the device.So, this method does not necessarily invoke.
 */
- (UTEWeatherType)getUTEWeatherType:(NSInteger)weatherCode;

/**
 *  @discussion Get weather information (Paid API, Server authorization required)
 *
 *  @param sdkkey  KEY
 *  @param cityID  e.g. @"CN101010100"   See https://github.com/qwd/LocationList
 *
 *  @param latitude         If cityID is filled in, this parameter is not required.
 *  @param longitude       If cityID is filled in, this parameter is not required.
 *
 *  Note:
 *  1.It is recommended to use parameter cityID, because it will get more accurate weather.
 *  2.Must fill in one of them (cityID or latitude and longitude)
 *  3.This method requires server authorization to have data, please let us know.
 */
- (void)getUTEWeatherDataFormServer:(NSString *_Nullable)sdkkey
                             cityID:(NSString *_Nullable)cityID
                           latitude:(double)latitude
                          longitude:(double)longitude
                            success:(void (^_Nullable)(UTEModelWeatherInfo * _Nullable data))success
                            failure:(void (^_Nullable)(NSError * _Nullable error))failure;
- (void)getUTEWeatherDataFormServer:(NSString *_Nullable)sdkkey
                           latitude:(double)latitude
                          longitude:(double)longitude
                           cityZone:(NSString *_Nullable)cityZone
                         cityParent:(NSString *_Nullable)cityParent
                          provinces:(NSString *_Nullable)provinces
                            success:(void (^_Nullable)(UTEModelWeatherInfo * _Nullable data))success
                            failure:(void (^_Nullable)(NSError * _Nullable error))failure;

#pragma mark - Version OTA/Update

/**
 *  @discussion OTA KEY type
 *  Compatible with different types of firmware, default is NO
 *
 *  Note: If necessary, Please invoke this method before upgrading firmware.
 */
- (void)setOTAKeyNormal:(BOOL)isNormal;
- (void)setOTAKeyCustom:(NSData *_Nullable)customKey;
/**
 *  @discussion Check if the server has the latest firmware
 *  Callback uteManagerDevicesSate:error:
 *  Note:Run the App once during debugging, you can access the server 5 times in a row, and then please run the App again to continue access.
 *  If SDKKey has never been set, please invoke setUTESDKKey: first.
 *
 *  @return It sends successfully or fails
 */
- (BOOL)checkUTEFirmwareVersion;

//Always get a new firmware, even if it's exactly the same as the current one
- (BOOL)checkUTEFirmwareVersionAlwaysNew;

/**
 *  @discussion Check if the server has the latest firmware UI.
 *  Callback uteManagerDevicesSate:error:
 *
 *  Required:isHasFirmwareUI = YES
 *
 *  @return It sends successfully or fails
 *
 *  Note:First invoke 'checkUTEFirmwareVersion' to check the firmware, if there is a new version, invoke 'beginUpdateFirmware' to upgrade. If there is no new version, invoke this method again to check the firmware UI.
 *  If SDKKey has never been set, please invoke setUTESDKKey: first.
 */
- (BOOL)checkUTEFirmwareUIVersion;
/**
 *  @discussion notify Firmware status
 *   dict:
 *   kUTEUpdateFirmwareInfo : UTEModelFirmwareInfo
 *   kUTEForceUpdateFirmware: BOOL
 */
- (void)notifyUTEFirmwareNew:(void(^_Nullable)(NSDictionary * _Nullable dict,BOOL hasNew))block;
/**
 *  @discussion Check if method UTEOption can be called OR Is it possible to set up or perform other operations on the device.
 *  For example, when isSyncDevices=YES, isHeartDetecting=YES, isBloodDetecting=YES, isECGDetecting=YES, isUpdateDevices=YES, sendingDailFlag=YES  other values cannot be sent.
 *
 *  Exceptions: 1. When the device is in the process of testing heart rate, you can send UTEOptionHeartDetectingStop / UTEOptionCloseCameraMode, regardless of the return value.
 *  Exception: 2. When the device is in the process of testing blood pressure, UTEOptionBloodDetectingStop / UTEOptionCloseCameraMode can be sent, regardless of the return value.
 *  Exception: 3. When the device sportModeStatus !=UTEDeviceSportModeStatusClose, you can call the method setUTESportModel: to stop the current motion state.
 *
 *  When isOpenApdu=YES,UTEOption instructions are invalid, this method returns false.
 *
 *  @return value
 */
- (BOOL)checkUTEDevicesStateIsEnable;

/**
 *  @discussion Start firmware upgrade
 *  Callback during upgrade: uteManagerUpdateProcess:
 *  Callback when the upgrade fails or succeeds: uteManagerDevicesSate:error:
 *
 *  Note:
 *  1.Before upgrading, it is recommended to determine the battery level of the device. When the power is greater than 50, please call the method to upgrade, otherwise the province will easily fail.
 *  2. When upgrading, please keep the app in the foreground. This will help increase the data sending speed.
 *  If the app is in the background, the sending speed will become very slow.
 */
- (void)beginUpdateFirmware;

/**
 *  @discussion local firmware update
 *
 *  @url firmware path
 *  e.g. @"/var/mobile/Containers/Data/Application/xxxxx/SH0AV000564.bin"
 *  e.g. @"/var/mobile/Containers/Data/Application/xxxxx/SH0AV000564.img"
 *
 *  Firmware Name Format: versionName + V + versionNum
 *  versionName: See UTEModelDevices.versionName (e.g. SH0A)
 *  versionNum:   See UTEModelDevices.versionNum   (e.g. 000564     6 digits, if not enough, fill in 0 in front.  )
 *
 *  @return Is the firmware valid. If Yes , You can invoke method beginUpdateFirmware to upgrade the firmware.
 *  if NO,Please do not upgrade the firmware, otherwise the device will freeze and become unusable.
 */
- (BOOL)updateLocalFirmwareUrl:(NSString *_Nonnull)url;

/**
 *  @discussion local firmware update
 *  *  Required: isFRQDevices = YES
 *
 *  @url firmware path
 *  e.g. @"/var/mobile/Containers/Data/Application/xxxxx/SH0AV000564.bin"
 *  e.g. @"/var/mobile/Containers/Data/Application/xxxxx/SH0AV000564.img"
 *
 *  @return Is the firmware valid. If Yes , You can invoke method beginUpdateFirmware to upgrade the firmware.
 *  if NO,Please do not upgrade the firmware, otherwise the device will freeze and become unusable.
 */
- (BOOL)updateLocalFirmwareCMUrl:(NSString *_Nullable)urlCM dspUrl:(NSString *_Nullable)dspUrl;

/**
 *  @discussion local firmware update(Straight to the start of the upgrade)
 *  *  Required: isATSDevices = YES
 *
 *  @param filePath firmware local path
 *  e.g. @"/var/mobile/Containers/Data/Application/xxxxx/xxxx/xxxx/xxxx.bin"
 *  e.g. @"/var/mobile/Containers/Data/Application/xxxxx/xxxx/xxxx/xxxx.zip"
 *
 */
- (void)updateLocalFirmwareATSFilePath:(NSString *_Nonnull)filePath;

/**
 *  @discussion Change device feature. See UTEDeviceFeature
 *
 *  @param isSuccess result
 *
 *  Note: 'isMustUpdate=YES': Must force to upgrade (if not upgrade, some of the original functions may not be available).
 *
 */
- (void)changeDeviveFeature:(void(^_Nullable)(BOOL isSuccess,BOOL isMustUpdate))isSuccess;

#pragma mark - Do not disturb
/**
 *  @discussion Do not disturb
 *
 *  @param type See UTESilenceType
 *
 *  @param start time e.g. @"08:30"
 *
 *  @param end   time e.g. @"23:00"
 *
 *  @param except as follows
 *  Note:
 *  1.When except is Yes, it means "Do not disturb" in the range of (e.g 08: 30 ~ 23: 00), which is not related to the parameter type. But outside of this time, it is related to type and is controlled by the type attribute UTESilenceType.
 *  2.When except is No, it means that “Do Not Disturb” in one day is controlled by the type attribute UTESilenceType, which is not related to startTime and endTime.
 *  3.If you want to turn off 'Do Not Disturb', set except=NO and type to UTESilenceTypeNone.
 *
 *  4."Do not disturb" can not set separate functions at multiple different times, such as setting [UTESilenceTypeVibration] at a certain time A, and then setting B [UTESilenceTypeMessage] at a certain time.
 *  5."Do Not Disturb" can only be set uniformly within a certain time [Do Not Disturb], and then set UTESilenceType outside of this time A.
 */
- (void)sendUTEAllTimeSilence:(UTESilenceType)type exceptStartTime:(NSString *_Nonnull)start endTime:(NSString *_Nonnull)end except:(BOOL)except;

#pragma mark - Dial & Display
/**
 *  @discussion Get the Dial that exists on the server
 *
 *  @param sdkkey    KEY
 *  @param device    see UTEModelDeviceDisplayModel. Invoke readUTEDisplayInfoFormDevice:
 
 *  @param success success
 *  @param failure error
 */
- (void)getUTEDisplayInfoFormServer:(NSString *_Nonnull)sdkkey
                             device:(UTEModelDeviceDisplayModel *_Nonnull)device
                            success:(void (^_Nullable)(NSArray<UTEModelDeviceDisplayModel *> *_Nullable))success
                            failure:(void (^_Nullable)(NSError *_Nullable))failure;

/**
 *  @discussion Sort by group to get the Dial where the server exists
 *
 *  Temporarily support specific projects, ask your project manager
 *
 *  @param sdkkey    KEY
 *  @param device    see UTEModelDeviceDisplayModel. Invoke readUTEDisplayInfoFormDevice:
 
 *  @param success success
 *  @param failure error
 *
 *  Note:
 *  1.Returns data in groups, with a maximum of 3 in each group by default.
 */
- (void)getUTEDisplayInfoFormServerByGroup:(NSString *_Nonnull)sdkkey
                                    device:(UTEModelDeviceDisplayModel *_Nonnull)device
                                   success:(void (^_Nullable)(NSArray<UTEModelDeviceDisplayGroupModel *> *_Nullable))success
                                   failure:(void (^_Nullable)(NSError *_Nullable))failure;

/**
 *  @discussion Check if the server has these dials
 *
 *  @param sdkkey    KEY
 *  @param model      see UTEModelDeviceDisplayModel. Invoke readUTEDisplayInfoFormDevice:
 *  @param arrayIDs    see UTEModelDeviceDisplayModel.ID   e.g.  @[@"10002", @"10008"]
 
 *  @param success Return ID that does not exist on the server
 *  @param failure error
 */
- (void)checkUTEDisplayExistFormServer:(NSString *_Nonnull)sdkkey
                                device:(UTEModelDeviceDisplayModel *_Nonnull)model
                              arrayIDs:(NSArray<NSString *> *_Nonnull)arrayIDs
                               success:(void (^_Nullable)(NSArray<NSString *> *_Nullable))success
                               failure:(void (^_Nullable)(NSError *_Nullable))failure;

/**
 *  @discussion View 'Dial' information supported by the device
 *  Required:isHasSwitchDialOnline = YES
 *
 *  @return It sends successfully or fails
 */
- (BOOL)readUTEDisplayInfoFormDevice:(void (^_Nullable)(UTEModelDeviceDisplayModel *_Nullable model))result;

/**
 *  @discussion Read the dial information of the specified location
 *  Required:isHasReadDialLocation = YES
 *
 *  @param location See method readUTEDisplayInfoFormDevice: (UTEModelDeviceDisplayModel.locationCount)
 *  Range: From 1 to UTEModelDeviceDisplayModel.locationCount .
 *
 *  @param result
 *  currentLocation: Current Dial position
 *  ID: Current Dial ID, same as UTEModelDeviceDisplayModel.bleID
 *
 *  @return It sends successfully or fails
 */
- (BOOL)readUTEDisplayInfoFormDeviceLocation:(NSInteger)location result:(void (^_Nullable)(NSInteger currentLocation, NSInteger bleID))result;

/**
 *  @discussion View local 'Dial' information supported by the device
 *  Required:isHasModifyLocalDial = YES
 *
 *  @return It sends successfully or fails
 */
- (BOOL)readUTEDisplayLocalDial:(void (^_Nullable)(UTEModelDeviceDisplayLocalModel *_Nullable model))result;

/**
 *  @discussion Change the dial  currently displayed on the device
 *  Required:isHasModifyLocalDial = YES
 *
 *  @param index See (readUTEDisplayLocalDial) 
 *  @return It sends successfully or fails
 */
- (BOOL)setUTEDisplayCurrent:(NSInteger)index result:(void(^_Nullable)(BOOL success))result;

/**
 *  @discussion Send a new 'Dial' (to replace the device's screen display).
 *  Required: isHasSwitchDialOnline=YES.
 *
 *  Note:Invoke getUTEDisplayModelFormServer:success:failure to get the dial data
 *  If the app enters the background, the SDK sending data may be suspended by the system,
 *  and the app will continue to send automatically when it returns to the foreground.
 *
 *  @param binData  firmware (bin file) data. Or see getUTEDisplayModelFormServer:success:failure
 *  @param process  Data sending progress(0 ~ 1.0)
 *
 *  @param success  success
 *  @param failure  error.code See UTEErrorCode
 *
 *  @return It sends successfully or fails
 */
- (BOOL)sendUTEDisplayDataToDevice:(NSData *_Nonnull)binData
                           process:(void (^_Nullable)(CGFloat process))process
                           success:(void (^_Nullable)(void))success
                           failure:(void (^_Nullable)(NSError *_Nullable error))failure;
/**
 *  @discussion Send a new 'Dial' (to replace the device's screen display , specified location).
 *  Required: isHasReadDialLocation=YES.
 *
 *  Note:Invoke getUTEDisplayModelFormServer:success:failure to get the dial data
 *  If the app enters the background, the SDK sending data may be suspended by the system,
 *  and the app will continue to send automatically when it returns to the foreground.
 *
 *  @param binData  firmware (bin file) data. Or see getUTEDisplayModelFormServer:success:failure
 *
 *  @param location  Where should the position of the dial be replaced?
 *  Range:  From 1 to UTEModelDeviceDisplayModel.locationCount
 *  See readUTEDisplayInfoFormDevice (UTEModelDeviceDisplayModel.locationCount)
 *
 *  @param process  Data sending progress(0 ~ 1.0)
 *
 *  @param success  success
 *  @param failure  error.code See UTEErrorCode
 *
 *  @return It sends successfully or fails
 */
- (BOOL)sendUTEDisplayDataToDevice:(NSData *_Nonnull)binData
                          location:(NSInteger)location
                           process:(void (^_Nullable)(CGFloat process))process
                           success:(void (^_Nullable)(void))success
                           failure:(void (^_Nullable)(NSError *_Nullable error))failure;

/**
 *  @discussion Stop sending Dial Data
 *
 *  Note:There will be error callback, error.code = UTEErrorCodeDialCRC
 */
- (void)stopUTEDisplayDataToDevice;

/**
 *  @discussion Change device background image or font color, and get a new bin file.
 *  Required:isHasSwitchDialOnline=YES.
 *
 *  @param backgroundImage  It is recommended that the size of the picture is the same as the size of the device screen,
 *                          otherwise it will be distorted.(UTEModelDeviceDisplayModel have device size).
 *
 *  @param fontColor  Font color. Colors cannot have transparency.
 *  @param dialIndex  See UTEModelDialInfo.index
 *
 *  @param success  UTEModelDialInfo:Get a new Dial.
 *  Then you can call sendUTEDisplayDataToDevice:process:success:failure, and the device interface will change display.
 */

- (void)changeUTEDialBackgroundImage:(UIImage *_Nullable)backgroundImage
                             fontColor:(UIColor *_Nullable)fontColor
                           dialIndex:(NSInteger)dialIndex
                               success:(void (^_Nullable)(UTEModelDialInfo *_Nullable dialInfo))success
                               failure:(void (^_Nullable)(void))failure;

/**
 *  @discussion Get customizable dial in the SDK built-in
 *  Required:isHasSwitchDialOnline=YES.
 *
 *  @param model see UTEModelDeviceDisplayModel. Invoke readUTEDisplayInfoFormDevice.
 *
 *  @return All dials. If it nil, there is no customizable dial.Your UI designer can make the dial resource pack by himself,
 *  and then the developer can invoke method getUTECustomDialInfoFromUnzippedPath: to get the resource pack information.
 *  Please use the reference documents provided by us to make the resource pack.
 */
- (NSArray<UTEModelDialInfo *> *_Nullable)getUTECustomDialDefualtInfo:(UTEModelDeviceDisplayModel *_Nonnull)model;

/**
*  @discussion Get customizable dial(zip url) from server.
*  Required:isHasSwitchDialOnline=YES.
*
*  @param model see UTEModelDeviceDisplayModel. Invoke readUTEDisplayInfoFormDevice.
*
*  @param success . If there is data on the server, zipDials is not empty, otherwise is null.
*
*/
- (void)getUTECustomDialInfoFromServer:(NSString *_Nonnull)sdkkey
                                device:(UTEModelDeviceDisplayModel *_Nonnull)model
                               success:(void (^_Nullable)(NSArray<UTEModelDialServer *> *_Nullable zipDials))success
                               failure:(void (^_Nullable)(void))failure;
/**
 *  @discussion Get customizable dial from unzipped Path.
 *  Required:isHasSwitchDialOnline=YES.
 *
 *  @param unzippedPath unzip the file to get the destination path of the unzipped file.
 *  e.g. /var/mobile/Containers/Data/Application/xxxx-xxx-xxx-xxxx/Documents/DeviceDial
 *
 *  @param model see UTEModelDeviceDisplayModel. Invoke readUTEDisplayInfoFormDevice.
 *
 *  Note: Invoke getUTEDisplayInfoFormServer:device:success:failure to get customDial.zip download link.
 *  Download customDial.zip from UTEModelDialServer.zipUrl, then unzip the file to get the destination path of the unzipped file.
 *  Or Make a custom resource package according to file 《App自定义表盘制作规范》.
 *  
 *  @return All dials. If it nil, there is no customizable dial OR There is a problem with the unzippedPath, please see the SDK log.
 */
- (NSArray<UTEModelDialInfo *> *_Nullable)getUTECustomDialInfoFromUnzippedPath:(NSString *_Nonnull)unzippedPath defaultInfo:(UTEModelDeviceDisplayModel *_Nonnull)model;

/**
 *  @discussion Modify the coordinates, show, and hide of dial elements
 *
 *  @param model  Invoke getUTECustomDialDefualtInfo:  OR getUTECustomDialInfoFromServer:device:success:failure
 *
 *  @param success  See UTEModelDialInfo
 *
 *  @param failure failure
 *
 *  Note: Only the coordinates (x,y) and BOOL properties in UTEModelDialInfo.status can be modified.
 *
 */
- (void)changeUTEModelDialInfo:(UTEModelDialInfo *_Nonnull)model
                       success:(void (^_Nullable)(UTEModelDialInfo * _Nullable dialInfo))success
                       failure:(void (^_Nullable)(void))failure;
- (void)changeUTEModelDialInfo:(UTEModelDialInfo *_Nonnull)model
                    screenType:(UTEDeviceScreenType)screenType
                    compatible:(NSInteger)compatible
                       success:(void (^_Nullable)(UTEModelDialInfo * _Nullable dialInfo))success
                       failure:(void (^_Nullable)(void))failure;

/**
 *  @discussion Get preview only
 *
 *  @param model  See  getUTECustomDialDefualtInfo  OR getUTECustomDialInfoFromServer:device:success:failure OR getUTECustomDialInfoFromUnzippedPath:defaultInfo
 */
- (UIImage *_Nullable)getDialPreviewImageFrom:(UTEModelDialInfo *_Nonnull)model;
- (UIImage *_Nullable)getDialPreviewImageFrom:(UTEModelDialInfo *_Nonnull)model 
                                   screenType:(UTEDeviceScreenType)screenType
                                   compatible:(NSInteger)compatible;


#pragma mark - iBeacon
/**
 *  @discussion ibeacon
 *
 *  @param option     See UTEIbeaconOption
 *  @param dataString as follows:
 *
 *   UTEIbeaconOptionUUID:  Range(0~9 and not case sensitive a~f) Data length must be equal to 32
 *                          e.g. @"a2b9c738cc9d846aef90639e0e4c9562"
 *
 *   UTEIbeaconOptionMajor: Range(0~65535) Numbers e.g. @"55365"
 *
 *   UTEIbeaconOptionMinor:  Range(0~65535) Numbers e.g. @"65"
 *
 *   UTEIbeaconOptionName:   Range(0~9 and case sensitive a~Z and English symbols on keyboard) Data length is up to 14
 *                           e.g. @"UTE_001"
 *   UTEIbeaconOptionTXPower: Range(1~254) Numbers e.g.@"55"
 *
 *   UTEIbeaconOptionAdvertisingInterval: Range(1~20) Numbers e.g. @"5" (Unit is 100 ms),mean 5*100 = 500ms
 *
 *  @return It sends successfully or fails
 */
- (BOOL)sendUTEIbeacon:(UTEIbeaconOption)option dataString:(NSString *_Nonnull)dataString;

/**
 *  @discussion    Read ibeacon data
 *
 *  @param option  See UTEIbeaconOption
 */
- (void)readUTEIbeacon:(UTEIbeaconOption)option;

#pragma mark - Menstruation
/**
 *  @discussion Setting the menstrual
 *
 *  @param  model See UTEModelDeviceMenstruation
 *
 *  @return It sends successfully or fails
 */
- (BOOL)sendMenstruationRemind:(UTEModelDeviceMenstruation *_Nonnull)model;
/**
 *  @discussion Physiological type of each day in a cycle
 *
 *  @param  model See UTEModelDeviceMenstruation
 *
 *  e.g.
 *  model.firstTime = @"2022-10-01"
 *  model.duration = 28
 *  model.cycle = 28
 *  Array returns data from No. 1 to No. 28
 *
 */
- (NSArray<UTEModelDeviceFemaleCycle *> *_Nullable)getPhysiologicalFemaleCycle:(UTEModelDeviceMenstruation *_Nonnull)model;
/**
 *  @discussion Control menstrual to show or hide
 *
 *  Required: isHasMenstruationCtr=Yes
 *
 *  @return It sends successfully or fails
 */
- (BOOL)sendMenstruationShow:(BOOL)show block:(void(^_Nullable)(BOOL show))block;
/**
 *  @discussion read menstrual status (show or hide)
 *
 *  Required: isHasMenstruationCtr=Yes
 *
 *  @return It sends successfully or fails
 */
- (BOOL)readMenstruationShow:(void(^_Nullable)(BOOL show))block;

#pragma mark - Send Custom Data
/**
 *  @discussion  Send custom data to the device
 *  Callback uteManagerSendCustomDataResult:
 *  See uteManagerReceiveCustomData:result:
 *
 *  see isCustomDataSending
 *
 *  @param flagSync
 *  YES:App wants to get the device data (e.g. App get historical data)
 *  NO:App only sends data to BLE
 *
 *  @return It sends successfully or fails
 */
- (BOOL)sendUTECustomData:(NSData *_Nonnull)data flagSync:(BOOL)flagSync;

/**
 *  Delete all instructions that the APP will send
 */
- (void)removeUTECustomSendData;

/**
 *  @discussion  Send a custom string to the device
 *
 *  @param model See UTEModelDeviceCustomMsg
 */
- (void)sendUTECustomMsg:(UTEModelDeviceCustomMsg *_Nonnull)model;

#pragma mark - Contacts
/**
 *  @discussion  Send contacts(normal) to the device
 *  Required:isHasContact=Yes
 *  The maximum name length is 10, and the maximum number of contacts is 100
 *
 *  When isHasContactMax20=Yes
 *  The maximum name length is 20, and the maximum number of contacts is 70
 *
 *  @param array @[UTEModelContactInfo...] 
 *  Note:
 *  1.Array should fill in at least one
 *  2.See UTEOptionDeleteAllContacts.
 */
- (BOOL)sendUTEContactInfo:(NSArray<UTEModelContactInfo *> *_Nonnull)array callback:(void (^_Nullable)(void))callback;
/**
 *  @discussion  Send contacts(emergency) to the device
 *  Required:isHasSOSContacts=Yes
 *
 *  @param array @[UTEModelContactInfo...]  See readUTEContactSOSAmount
 *
 *  Note:
 *  1. The number cannot exceed the maximum number. Otherwise the function will not take effect.
 *  2. To delete all sos contacts, array please fill in nil
 */
- (BOOL)sendUTEContactSOSInfo:(NSArray<UTEModelContactInfo *> *_Nullable)array callback:(void (^_Nullable)(void))callback;
/**
 *  @discussion  Read the maximum number of contacts supported
 *  Required:isHasSOSContacts=Yes
 *
 *  @param callback Maximum number supported
 */
- (BOOL)readUTEContactSOSAmount:(void (^_Nullable)(NSInteger max))callback;
/**
 *  @discussion  App wake up Device SOS
 *  Required:isHasSOSCtl=Yes
 *
 *  @return It sends successfully or fails
 */
- (BOOL)wakeupDeviceSOS:(void (^_Nullable)(UTEContactWakeupType type))callback;
/**
 *  @discussion  Device actively changes the SOS status
 *
 */
- (void)notifyDeviceSOS:(void (^_Nullable)(UTEContactWakeupType type))callback;

#pragma mark - Language
/**
 *  @discussion Customize the language of the device display interface
 *  During the language sending process (approximately 8 seconds, the longer the text, the longer the time), please do not send other command, otherwise the device displays incomplete text.
 *  Required:isHasMultiLanguage=YES
 *
 *  Note:When isHasLanguageSwitchDirectly=YES,please invoke setUTELanguageSwitchDirectly
 */
- (void)setUTELanguageInterface:(UTEModelDeviceInterface *_Nonnull)model;
/**
 *  @discussion Switch device language
 *  Required:isHasLanguageSwitchDirectly=YES
 *
 */
- (void)setUTELanguageSwitchDirectly:(UTEDeviceLanguage)language;

/**
 *  @discussion Read the language of the current device
 *  Required: isHasReadLanguage=YES
 *
 *  @return It sends successfully or fails
 */
- (BOOL)readDeviceLanguage:(void(^_Nullable)(UTEDeviceLanguage language))result;

/**
 *  @discussion Read which languages the current device supports
 *  Required: isHasReadSupportLanguage=YES
 *
 *  supports:NSArray e.g. @[@UTEDeviceLanguageChinese, @UTEDeviceLanguageEnglish...]
 *
 *  @return It sends successfully or fails
 */
- (BOOL)readDeviceLanguageSupport:(void(^_Nullable)(UTEDeviceLanguage currentLanguage,NSArray<NSNumber *> * _Nullable supports))result;

#pragma mark - Remind App
/**
 *  @discussion Information push for the specified app
 *  Required:isHasSocialNotification=Yes OR isHasSocialNotification2=Yes OR isHasIconANCS=Yes
 *
 *  @return It sends successfully or fails
 */
- (BOOL)setUTERemindApp:(UTEModelDeviceRemindApp *_Nonnull)model;

/**
 *  @discussion Which app icons are built into the device
 *  Required:isHasIconANCS=YES
 *
 *  @param result arrayApp See UTEDeviceApp(please convert NSNumber to UTEDeviceApp).
 *
 *  @return It sends successfully or fails
 */
- (BOOL)readDeviceSupportAppListANCS:(void(^_Nullable)(NSArray<NSNumber *> * _Nullable arrayApp))result;

#pragma mark - Shortcut
/**
 *  @discussion Read which shortcut buttons are supported by the device
 *  Required:isHasShortcutButton=YES
 *
 *  Please see delegate uteManagerShortcutBtnSupportModel:
 *
 *  @return It sends successfully or fails
 */
- (BOOL)readDeviceShortcutBtnSupport;

/**
 *  @discussion Read the status of device shortcut buttons
 *  Required:isHasShortcutButton=YES
 *  Callback uteManagerShortcutBtnStatusModel:
 *
 *  The value of the status button is only valid if the function is supported.  See method readDeviceShortcutBtnSupport
 *
 *  @return It sends successfully or fails
 */
- (BOOL)readDeviceShortcutBtnStatus;

#pragma mark - HRM
/**
 *  @discussion   How often is the heart rate detected.
 *  Required isSwitchHeart=Yes.
 *
 *  @param isAuto automatic detection
 *
 *  @param time  Range 1 ~ 23 (Unit hour)
 */
- (void)setUTEHeartAuto:(BOOL)isAuto time:(NSInteger)time;
/**
 *  @discussion   How often is the heart rate detected.
 *  Required isHas24HourHRMCtl=Yes.
 *
 *  @param isAuto automatic detection
 *
 *  @param timeMins  only value(2/5/10/15/20) mins
 */
- (void)setHRM24Auto:(BOOL)isAuto time:(NSInteger)timeMins result:(void(^_Nullable)(BOOL success))result;

/**
 *  @discussion   Modify the maximum heart rate value
 *  Required isHasModifyMaxHRM=Yes.
 *
 *  @max Range 40 ~ 220
 */
- (BOOL)setUTEMaxHeart:(NSInteger)max result:(void(^_Nullable)(BOOL success))result;

/**
 *  @discussion Read heart rate status
 *  Whether the device is detecting heart rate
 *
 *  @return It sends successfully or fails
 */
- (BOOL)readHRMStatus:(void(^_Nullable)(BOOL isHeartDetecting))result;

/**
 *  @discussion   How often is the heart rate detected.
 *  Required isHasCustomTimeSaveData=Yes.
 *
 *  @param time  Range 1 ~ 255 (minute)
 *
 *   @return It sends successfully or fails
 */
- (BOOL)setUTEHeartCustomTimeSaveData:(NSInteger)time;

#pragma mark - Blood
/**
 *  @discussion   Automatically measure blood pressure within a time range
 *  Required isHasBloodTestRangeTime=Yes.
 *
 *  @param isAuto automatic detection
 *
 *  @param startTime   Format HH:mm
 *  @param endTime    Format HH:mm
 *
 *  Note: The time range can only be set between 18:00 and 06:00, and cannot exceed this range.
 *  Alse See setUTEBloodPressureAuto:time (Set time intervals)
 *
 *  See Callback: UTECallBackBloodPressureTimeRange
 *  @return It sends successfully or fails
 */
- (BOOL)setUTEBloodPressureAuto:(BOOL)isAuto startTime:(NSString *_Nonnull)startTime endTime:(NSString *_Nonnull)endTime;
/**
 *  @discussion   Automatically measure blood pressure  time
 *  Required isHasBloodTestRangeTime=Yes.
 *
 *  @param time   Format HH:mm
 *  @param index  The index number of time  ,Starting from 0, only 3 can be set
 *  @param enable  enable
 *
 *  Alse See setUTEBloodPressureAuto:time (Set time intervals)
 *
 *  See Callback: UTECallBackBloodPressureSpecifyTime
 *  @return It sends successfully or fails
 */
- (BOOL)setUTEBloodPressureTestTime:(NSString *_Nonnull)time index:(NSInteger)index enable:(BOOL)enable;
/**
 *  @discussion   Reminder for automatic morning blood pressure testing
 *  Required isHasBloodTestMorningRemind=Yes.
 *
 *  See Callback: UTECallBackBloodPressureMorningTestOpen/UTECallBackBloodPressureMorningTestClose
 *  @return It sends successfully or fails
 */
- (BOOL)setUTEBloodTestMorningRemind:(BOOL)remind;
/**
 *  @discussion   How often is the blood pressure detected.
 *  Required isHasBloodAutoTest=Yes.
 *
 *  @param isAuto automatic detection
 *  @param time   Detect every few hours, range 1 ~ 23
 *
 *  See Callback: UTECallBackBloodPressureAutoTime
 */
- (void)setUTEBloodPressureAuto:(BOOL)isAuto time:(NSInteger)time;

/**
 *  @discussion Set blood pressure calibration parameters
 *  Required:isHasBloodCalibrate=YES
 *
 *  @param callback Device setting parameters succeeded or failed.
 *
 *  @return It sends successfully or fails
 */
- (BOOL)setBloodCalibrateData:(NSData *_Nonnull)data callback:(void(^_Nullable)(BOOL success))callback;

/**
 *  @discussion Set blood pressure  parameters
 *  Required:isHasBloodCalibrate=YES
 *
 *  @param isHypertension Is it high blood pressure.
 *  @param isDrug Taking medicines related to lowering high blood pressure.
 *  @param callback Device setting parameters succeeded or failed.
 *
 *  @return It sends successfully or fails
 */
- (BOOL)setBloodParamHypertension:(BOOL)isHypertension drug:(BOOL)isDrug callback:(void(^_Nullable)(BOOL success))callback;

/**
 *  @discussion Does the device need to be calibrated
 *  Required:isHasBloodCalibrate=YES
 *
 *  @return It sends successfully or fails
 */
- (BOOL)readBloodCalibrateStatus:(void(^_Nullable)(BOOL needCalibrate))callback;

/**
 *  @discussion Read blood chip type
 *  Required:isHasBloodMoreFeatures=YES
 *
 *  @return It sends successfully or fails
 */
- (BOOL)readBloodChipType:(void(^_Nullable)(NSInteger chipType, NSInteger chipNum, NSString * _Nullable chipVersion))callback;

/**
 *  @discussion Read blood chip history (blood,hrm,blood oxygn)
 *  Required:isHasBloodMoreFeatures=YES
 *
 *  Callback See delegate uteManagerDevicesSate:UTEDevicesSateSyncSuccess  error: userInfo:
 *  @return It sends successfully or fails
 */
- (BOOL)readBloodChipHistory;
/**
 *  @discussion Whether the blood pressure function of the device is activated
 *  Required:isHasBloodMoreFeatures=YES
 *
 *  @return It sends successfully or fails
 */
- (BOOL)checkDeviceActivateBlood:(void(^_Nullable)(BOOL activated ,NSString * _Nullable sn))callback;

/**
 *  @discussion Activate the Blood of the device
 *  Required:isHasBloodMoreFeatures=YES
 *
 *  @return It sends successfully or fails
 */
- (BOOL)activateDeviceBlood:(NSData *_Nonnull)activateData callback:(void(^_Nullable)(BOOL success))callback;



/**
 *  @discussion Regular blood pressure test
 *  Required:isHasBloodPressureCustom=YES
 *
 *  @param array See UTEModelCustomBloodClock
 *  Note:12 Clocks must be filled
 *
 *  @return It sends successfully or fails
 */
- (BOOL)setCustomBloodAlarmClock:(NSArray<UTEModelCustomBloodClock *> *_Nonnull)array;
- (BOOL)setCustomBloodHandle;

/**
 *  @discussion How many blood pressure records are there.
 *
 *  Required:isHasBloodPressureCustom=YES
 *  @return It sends successfully or fails
 */
- (BOOL)readCustomBloodHistoryCount:(void(^_Nullable)(NSInteger count))callback;

/**
 *  @discussion Blood History
 *
 *  @param fromIndex Data start position
 *  @param toIndex  Data end position
 *
 *  Required:isHasBloodPressureCustom=YES
 *
 *  The data(fromIndex,toIndex) cannot exceed the number returned by method readCustomBloodHistoryCount.
 *
 *  Callback See delegate uteManagerDevicesSate:UTEDevicesSateSyncSuccess  error: userInfo:
 *  @return It sends successfully or fails
 */
- (BOOL)readCustomBloodHistoryFrom:(NSInteger)fromIndex ToIndex:(NSInteger)toIndex;

/**
 *  @discussion Blood  PPG Start
 *  Required:isHasBloodHengAi=YES
 *  @param isPrecisionMode
 *   If Yes, The use of precision mode is provided that calibration data is required to improve the accuracy of the results.
 *   If No, Simple mode, the results of the data will be skewed greatly.
 *
 *  Callback See delegate uteManagerDevicesSate:UTEDevicesSateBloodPPGStartFromApp  error: userInfo:
 *  @return It sends successfully or fails
 */
- (BOOL)startBloodPPG:(BOOL)isPrecisionMode;

/**
 *  @discussion Blood  PPG Stop
 *  Required:isHasBloodHengAi=YES
 *
 *  Callback See delegate uteManagerDevicesSate:UTEDevicesSateBloodPPGStop  error: userInfo:
 *  @return It sends successfully or fails
 */
- (BOOL)stopBloodPPG;

/**
 *  @discussion Blood Test Status
 *  Required:isHasBloodHengAi=YES
 *
 *  @return It sends successfully or fails
 */
- (BOOL)readBloodPPGStatus:(void(^_Nullable)(BOOL isDetecting))result;

/**
 *  @discussion Set Blood
 *  Required:isHasBloodHengAi=YES
 *
 *  @param  type 1: ppg test   2: middle test
 *  @param  switchEnable Whether to regularly detect
 *  @param  interval unit:  minute. Test once at excessive intervals
 *  @param  duration unit:  minute. How long does it take to test once
 *
 *  Callback See UTECallBloodHengAiInfo
 *  @return It sends successfully or fails
 */
- (BOOL)setBloodPPG:(UTEBloodTestType)type
             switchEnable:(BOOL)switchEnable
                 interval:(NSInteger)interval
                 duration:(NSInteger)duration;

/**
 *  @discussion Set Blood Test
 *  Required:isHasBloodHengAi=YES
 *
 *  @param  isTest  If yes ,when invoke method(startBloodPPGHengAi),  device will return data in real time (UTEDevicesSateBloodPPGSProcess have data)
 *
 *  Callback See UTECallBackBloodHengAiTestModel
 *  @return It sends successfully or fails
 */
- (BOOL)setBloodPPGTestModel:(BOOL)isTest;

/**
 *  @discussion Read Blood Algorithm version
 *  Required:isHasBloodHengAi=YES
 *
 *  @return It sends successfully or fails
 */
- (BOOL)readBloodPPGAlgorithmVersion:(void(^_Nullable)(NSString * _Nullable version))block;
//debug for ppg
- (void)debugbloodPPGSourceForJson:(NSString *_Nonnull)key block:(void(^_Nullable)(NSString * _Nullable strJson))block;

/**
 *  @discussion Calibrate Blood
 *  Required:isHasBloodHengAi=YES
 *
 *  Note:
 *  1. Calibration required twice
 *  2. If not calibrated, the measurement results of blood pressure will be inaccurate.
 *
 *  @return It sends successfully or fails
 */
- (BOOL)calibrateBloodPPG;

/**
 *  @discussion Upload Calibrate Blood Data to server
 *  Required:isHasBloodHengAi=YES
 *
 *  Note: Systolic and Diastolic (Data measured with medical Sphygmomanometer)
 *
 */
- (void)uploadBloodPPGCalibrationData:(NSInteger)systolic diastolic:(NSInteger)diastolic block:(void(^_Nullable)(BOOL ok ,UTEErrorCode errorCode))block;
/**
 *  @discussion The activation status of the device
 *  Required:isHasBloodHengAi=YES
 *
 *  @return It sends successfully or fails
 */
- (BOOL)checkBloodPPGActivationStatus:(void(^_Nullable)(BOOL activate))block;

/**
 *  @discussion Activate  device blood
 *  Required:isHasBloodHengAi=YES
 *
 *  @return It sends successfully or fails
 */
- (BOOL)activateBloodPPGHengAi:(void(^_Nullable)(BOOL success ,UTEErrorCode errorCode))callback;

/**
 *  @discussion Login Account 
 *  Required:isHasBloodHengAi=YES
 *
 *  @param userID The account ID must be unique and longer than 6
 *
 *  @return It sends successfully or fails
 */
- (BOOL)loginAccountPPG:(NSInteger)userID callback:(void(^_Nullable)(BOOL success ,UTEErrorCode errorCode))callback;

/**
 *  @discussion send Account
 *
 *  @return It sends successfully or fails
 */
- (BOOL)sendHengAiAccount:(UTEModelHengAiAccount *_Nonnull)model callback:(void(^_Nullable)(BOOL success ,UTEErrorCode errorCode))callback;

/**
 *  @discussion Read BloodPPG Calibration
 *  Required:isHasBloodHengAi=YES
 *
 *  @return It sends successfully or fails
 */
- (BOOL)readBloodPPGCalibrationData:(void(^_Nullable)(BOOL success,NSArray<UTEModelBloodData *> * _Nullable array, UTEErrorCode errorCode))callback;
/**
 *  @discussion build BloodPPG Calibration
 *  Required:isHasBloodHengAi=YES
 *
 *  @return It sends successfully or fails
 */
- (BOOL)buildBloodPPGCalibrationData:(void(^_Nullable)(BOOL success ,UTEErrorCode errorCode))callback;

/**
 *  @discussion Send BloodPPG Calibration To Device
 *  Required:isHasBloodHengAi=YES
 *
 *  Note: when method buildBloodPPGCalibrationData: return success, this method is valid.
 */
- (void)sendBloodPPGCalibrationData:(void(^_Nullable)(BOOL success ,UTEErrorCode errorCode))callback;
/**
 *  @discussion Does Device have BloodPPG Calibration
 *  Required:isHasBloodHengAi=YES
 */
- (BOOL)readBloodPPGCalibrationStatus:(void(^_Nullable)(BOOL isExisted))callback;

/**
 *  @discussion delete BloodPPG Calibration
 *  Required:isHasBloodHengAi=YES
 *
 *  @return It sends successfully or fails
 */
- (BOOL)deleteBloodPPGCalibrationData:(void(^_Nullable)(BOOL success ,UTEErrorCode errorCode))callback;

/**
 *  @discussion Get BloodPPG Result From Server
 *  Required:isHasBloodHengAi=YES
 *
 *  @param startTime Format: yyyy-MM-dd-HH-mm
 */
- (void)getBloodPPGResultFromServer:(NSString *_Nonnull)startTime arrayPPG:(NSArray *_Nonnull)arrayPPG callback:(void(^_Nullable)(UTEModelBloodData * _Nullable model ,BOOL success, UTEErrorCode errCode))callback;
/**
 *  @discussion App set custom blood value
 *  Required:isHasBloodHengAi=YES
 *
 *  @time yyyy-MM-dd-HH-mm
 *
 *  Tips: If diastolic or systolic is 0 ,  this method will notify device that the test has failed.
 *
 *  @return It sends successfully or fails
 */
- (BOOL)setBloodPPGHengAi:(NSInteger)diastolic systolic:(NSInteger)systolic time:(NSString *_Nonnull)time;
/**
 *  @discussion History debug
 *   Defualt is no ,delete local data automatically. If yes, every time the history is synchronized, local data on the device will not be deleted.
 */
- (void)setBloodPPGHistoryDebug:(BOOL)isDebug;

/**
 *  @discussion App delete history of device local ppg data
 */
- (void)deleteBloodPPGHistory;

#pragma mark - BloodGlucose
/**
 *  @discussion Blood Glucose Start
 *  Required:ishasBloodGlucose=YES
 *
 *  Callback
 *  See delegate uteManagerDevicesSate:UTEDevicesSateBloodGlucoseStart  error: userInfo:
 *  If isHasBloodHengAi = YES , Also see delegate uteManagerDevicesSate:UTEDevicesSateBloodGlucoseProcess  error: userInfo:
 *  
 *  @return It sends successfully or fails
 */
- (BOOL)startBloodGlucose;
/**
 *  @discussion Blood Glucose Stop
 *  Required:ishasBloodGlucose=YES
 *
 *  Callback See delegate uteManagerDevicesSate:UTEDevicesSateBloodGlucoseStop  error: userInfo:
 *  @return It sends successfully or fails
 *
 *  Note: If it has UTEErrorCodeHRVTestAbnormal , Invalid test result.
 */
- (BOOL)stopBloodGlucose;

/**
 *  @discussion Blood Glucose Status
 *  Required:ishasBloodGlucose=YES
 *
 *  @return It sends successfully or fails
 */
- (BOOL)readBloodGlucoseStatus:(void(^_Nullable)(BOOL isDetecting))callback;

/**
*  @discussion Sync Blood Glucose history
*  Required:ishasBloodGlucose = YES
 
*  @param time  yyyy-MM-dd
*
*   Callback See delegate  uteManagerDevicesSate:UTEDevicesSateSync error: userInfo:
*
*  @return It sends successfully or fails
*/
- (BOOL)syncHistoryBloodGlucoseFrom:(NSString *_Nonnull)time;

#pragma mark - Blood Glucose Algorithm 1

- (void)getBloodGlucoseAlgorithm1ServerID:(UTEModelBloodGlucoseAccount1 *_Nonnull)model callback:(void(^_Nullable)(UTEModelBloodGlucoseAccount1 *_Nullable accountServer,NSError * _Nullable err))callback;

/**
 *  @discussion Enable Blood Glucose Algorithm 1
 *
 *  Callback See delegate  uteManageUTEOptionCallBack:UTECallBackBloodGlucoseAlgorithm1Open/UTECallBackBloodGlucoseAlgorithm1Close
 *
 *  Note: When  Blood Glucose Algorithm 1 is enable, the 24-hour heart rate is also enable
 *  @return It sends successfully or fails
 */
- (BOOL)setBloodGlucoseAlgorithm1Enable:(BOOL)enable;

/**
 *  @discussion Blood Glucose Algorithm 1 Status
 *  Required: isHasBloodGlucoseAlgorithm1=YES
 *
 *  @return It sends successfully or fails
 */
- (BOOL)readBloodGlucoseAlgorithm1Status:(void(^_Nullable)(BOOL enable))callback;

/**
*  @discussion Sync Blood Glucose Algorithm1 history
*  Required: isHasBloodGlucoseAlgorithm1 = YES
*
*   Callback See delegate  uteManagerDevicesSate:UTEDevicesSateSync error: userInfo:
*
*  @return It sends successfully or fails
*/
- (BOOL)syncHistoryBloodGlucoseAlgorithm1;

/**
*  @discussion Upload Blood Glucose Algorithm1 To Server
*
*  @param array See method (syncHistoryBloodGlucoseAlgorithm1)
* Note:If Upload success, please invoke method(deleteHistoryBloodGlucoseAlgorithm1)  delete histyory.
 Otherwise, the device data storage is too much, and the synchronization speed of the APP is very slow.
*
* @param sn  See method readUTEDeviceSN
* @param serverID See method getBloodGlucoseAlgorithm1ServerID
* @param mac See UTEModelDevices.addressStr
*
*/
- (void)uploadHistoryBloodGlucoseAlgorithm1:(NSArray<UTEModelBloodGlucoseAlgorithm1 *> *_Nullable)array
                                         sn:(NSString *_Nonnull)sn
                                   serverID:(NSString *_Nonnull)serverID
                                        mac:(NSString *_Nonnull)mac
                                   callback:(void(^_Nullable)(BOOL success,NSError * _Nullable error))callback;
/**
*  @discussion analyze server data
*  Required: isHasBloodGlucoseAlgorithm1 = YES
*
* Note:When method(uploadHistoryBloodGlucoseAlgorithm1:sn:serverID:mac:callback)  succeeds, you can invoke this method  to analyze
*/
- (void)analyzeBloodGlucoseAlgorithm1:(UTEModelBloodGlucoseAlgorithm1ServerData *_Nonnull)model
                             callback:(void(^_Nullable)(BOOL isSuccess,NSError * _Nullable error))callback;
/**
*  @discussion The result of getting the data from the server
*  Required: isHasBloodGlucoseAlgorithm1 = YES
*
* Note:
* 1. Param startTime and endTime can not be nil.
* 2. When method(analyzeBloodGlucoseAlgorithm1:callback)  succeeds, you can invoke this method  to obtain the data result.
*/
- (void)getBloodGlucoseAlgorithm1ServerData:(UTEModelBloodGlucoseAlgorithm1ServerData *_Nonnull)model
                               callback:(void(^_Nullable)(UTEModelBloodGlucoseAlgorithm1ServerHistory * _Nullable history,NSError * _Nullable error))callback;

/**
*  @discussion The result of getting the status from the server
*/
- (void)getBloodGlucoseAlgorithm1ServerStatus:(UTEModelBloodGlucoseAlgorithm1ServerData *_Nonnull)model
                               callback:(void(^_Nullable)(UTEModelBloodGlucoseAlgorithm1Status * _Nullable status,NSError * _Nullable error))callback;

/**
*  @discussion Calibrate Blood Glucose Algorithm1 To Server
*
* Note:Calibrate status at least 4 times (Status see UTEDietaryStatus)
*/
- (void)calibrateBloodGlucoseAlgorithm1:(UTEModelBloodGlucoseAlgorithm1Calibrate *_Nonnull)model
                               callback:(void(^_Nullable)(BOOL success,NSError * _Nullable error))callback;

/**
*  @discussion Build Blood Glucose Algorithm1 Server Model
*
* Note:In general, the return to NO is caused by the fact that the wearing time is less than 18 hours, and the amount of data is too small.
*/
- (void)buildBloodGlucoseAlgorithm1ServerModel:(UTEModelBloodGlucoseAlgorithm1ServerData *_Nonnull)model
                                      callback:(void(^_Nullable)(BOOL success,NSError * _Nullable error))callback;

/**
*  @discussion delete Blood Glucose History
*  Required: isHasBloodGlucoseAlgorithm1 = YES
*
* Callback See delegate  uteManageUTEOptionCallBack:UTECallBackBloodGlucoseAlgorithm1HistoryDelete
*
*  @return It sends successfully or fails
*/
- (BOOL)deleteHistoryBloodGlucoseAlgorithm1;

/**
*  @discussion Blood Glucose Level throughout the day
*  Required: isHasBloodGlucoseAlgorithm1 = YES
*
*   @param interval The interval between each Blood Glucose in a day
*   @param values The level of each Blood Glucose in a day. Each value is a UTEBloodGlucoseLevel
*
*   If interval is UTEBloodGlucoseIntervalMin1, values needs to fill in 1440 data
*   If interval is UTEBloodGlucoseIntervalMin5, values needs to fill in 288 data
*   If interval is UTEBloodGlucoseIntervalMin10, values needs to fill in 144 data
*
*  @return It sends successfully or fails
*/
- (BOOL)setBloodGlucoseAlgorithm1:(UTEBloodGlucoseInterval)interval values:(NSArray<NSNumber *> *_Nonnull)values callback:(void(^_Nullable)(BOOL success))callback;

/**
*  @discussion Set Today Blood Glucose TIR to device
*  Required: isHasBloodGlucoseAlgorithm1 = YES
*
*  @return It sends successfully or fails
*/
- (BOOL)setBloodGlucoseAlgorithm1TIR:(UTEModelBloodGlucoseTIR *_Nonnull)TIR;


#pragma mark - HRV Test
/**
 *  @discussion HRV TestStart
 *  Required:ishasHRVTest=YES
 *
 *  Callback
 *  See delegate uteManagerDevicesSate:UTEDevicesSateHRVTestStart  error: userInfo:
 *  If isHasBloodHengAi = YES , Also see delegate uteManagerDevicesSate:UTEDevicesSateHRVTestProcess  error: userInfo:
 *
 *  @return It sends successfully or fails
 */
- (BOOL)startHRVTest;
/**
 *  @discussion HRV Test Stop
 *  Required:ishasHRVTest=YES
 *
 *  Callback
 *  See delegate uteManagerDevicesSate:UTEDevicesSateHRVTestStop  error: userInfo:
 *  
 *  @return It sends successfully or fails
 *
 *  Note: If it has UTEErrorCodeHRVTestAbnormal , Invalid test result.
 */
- (BOOL)stopHRVTest;
/**
 *  @discussion HRV Status
 *  Required:ishasHRVTest=YES
 *
 *  @return It sends successfully or fails
 */
- (BOOL)readHRVStatus:(void(^_Nullable)(BOOL isDetecting))callback;

/**
*  @discussion Sync HRV history
*  Required:ishasHRVTest = YES
 
*  @param time  yyyy-MM-dd
*
*   Callback See delegate  uteManagerDevicesSate:UTEDevicesSateSync error: userInfo:
*
*  @return It sends successfully or fails
*/
- (BOOL)syncHistoryHRVFrom:(NSString *_Nonnull)time;

#pragma mark - BodyFat
/**
 *  @discussion Read device body fat status
 *  Whether the device is detecting body fat
 *
 *  @return It sends successfully or fails
 */
- (BOOL)readDeviceBodyFatStatus:(void(^_Nullable)(BOOL isDetecting))result;

/**
 *  @discussion Test body fat
 *
 *  @param  on  Start or stop
 *  @param  model If you are testing body fat, you must set UTEModelDeviceBodyFatConfig
 *
 *  @return It sends successfully or fails
 */
- (BOOL)monitorBodyFat:(BOOL)on config:(UTEModelDeviceBodyFatConfig *_Nonnull)model;

/**
 *  @discussion   Set Body Fat Information
 *  @param  model See UTEModelDeviceBodyFatConfig
 */
- (BOOL)setUTEBodyFatInfo:(UTEModelDeviceBodyFatConfig *_Nonnull)model;

#pragma mark - MPF
/**
 *  @discussion Read MPF sensor name
 *  Required: isHasMPF=YES
 *
 *  @param result Sensor Name AND Whether the device displays Mood/Pressure/Fatigue interface.
 *
 *  @return It sends successfully or fails
 */
- (BOOL)readDeviceSensorMPF:(void(^_Nullable)(NSString *_Nullable sensorName,BOOL haveMood,BOOL havePressure,BOOL haveFatigue))result;

/**
 *  @discussion Whether the device has been activated MPF(Mood,Pressure and Fatigue)
 *  Required:isHasMPF=YES
 *  If activated, the device can test MPF offline. If NO, Please invoke activateDeviceMPF:   to activate .
 *
 *  Note:When isHasLocalMP = YES,This method is invalid.
 *
 *  @return It sends successfully or fails
 */
- (BOOL)checkDeviceActivateMPF:(void(^_Nullable)(BOOL activated))callback;

/**
 *  @discussion Activate the MPF of the device
 *  Required:isHasMPF=YES
 *  If success, the device can test MPF offline.
 *  @param callback errorCode See UTEErrorCode
 *
 *  Note:When isHasLocalMP = YES,This method is invalid.
 *
 *  @return It sends successfully or fails
 */
- (BOOL)activateDeviceMPF:(void(^_Nullable)(BOOL success ,UTEErrorCode errorCode))callback;

/**
 *  @discussion Whether the device is detecting Mood,Pressure and Fatigue
 *  Required:isHasMPF = YES
 *
 *  @return It sends successfully or fails
 */
- (BOOL)readUTE_MPF_Status:(void(^_Nullable)(BOOL detecting))callback;

/**
 *  @discussion Monitoring interval
 *  Required:isHasMPF = YES
 *
 *  @return It sends successfully or fails
 *
 */
- (BOOL)setMPFAutoTest:(BOOL)on time:(UTECommonTestTime)testTime;

/**
 *  @discussion Time period for automatic monitoring
 *  Required:isHasMPF = YES
 *  When method (setMPFAutoTest:time:) parameter on is YES, this method is valid.
 *
 *  @param on  If YES,  The detection period is from startTime to endTime.
 *               If NO, All day.
 *
 *  @param startTime  e.g. @"08:30"
 *  @param endTime    e.g. @"18:00"
 *
 *  @return It sends successfully or fails
 *
 */
- (BOOL)setMPFAutoTestDuration:(BOOL)on startTime:(NSString *_Nonnull)startTime endTime:(NSString *_Nonnull)endTime;

#pragma mark - ECG
/**
 *  @discussion Read if the device has data to save offline ECG history
 *  if isChangsang_ECG = YES, This method is invalid.
 *
 *  @param  result (Format:yyyy-MM-dd-HH-mm) If there is ECG data, the date of the historical data is returned, otherwise nil.
 *
 *  Note:It is recommended to call this method before synchronizing the ECG data of the device, so that the progress percentage of the synchronization will be displayed truthfully.
 *
 *  @return It sends successfully or fails
 */
- (BOOL)readDeviceECGHistoryDate:(void(^_Nullable)(NSString *_Nullable strDate))result;

/**
*  @discussion Sampling frequency of device's ECG
*
*  @param result
*   frequency: This parameter may be needed when drawing an ECG.How many points are there per second.
*   ignore: The result of the test needs to delete the initial number of points.
*
*
*  @return It sends successfully or fails
*/
- (BOOL)readDeviceECGSamplingfrequency:(void(^_Nullable)(NSInteger frequency ,NSInteger ignore))result;

/**
*  @discussion Synchronize sampling data of device's ECG (Specify time)
*  Required:isChangsang_ECG = YES
 
*  @param time   Specific time point. See UTEOptionSyncECG returned data (UTEModelDeviceECG.time)
*   if time=nil, Indicates that the App synchronizes all the ECG sampling data in the device. (It will take a long time)
*
*   Callback See delegate  uteManagerDevicesSate:UTEDevicesSate error: userInfo:
*
*  @return It sends successfully or fails
*/
- (BOOL)syncDeivceECGSamplingDataFrom:(NSString *_Nullable)time;

/**
 *  @discussion ECG test
 *
 *  @param  on  Start or stop
 *
 *  @return It sends successfully or fails
 */
- (BOOL)monitorECG:(BOOL)on;

/**
 *  @discussion ECG Test Fail (App send to device)
 *
 *  If isECG_BLE = YES, method is invalid
 *
 *  @return It sends successfully or fails
 */
- (BOOL)sendECGFail;

/**
 *  @discussion ECG Test result (App send to device)
 *
 *  @param  aveHRM  Average heart rate
 *
 *  @param  arrays ECG result (Up to 5)
 *
 *  If isECG_BLE = YES, method is invalid
 *
 *  @return It sends successfully or fails
 */
- (BOOL)sendECGResult:(NSInteger)aveHRM arrays:(NSArray<UTEModelECGApp *> *_Nonnull)arrays complete:(void(^_Nullable)(BOOL success))complete;

#pragma mark - Body Temperature
/**
 *  @discussion Calibrate body temperature
 *  Required:isHasCalibrateBodyTemperature = YES
 *  @param  temp      Calibration temperature. Unit Celsius. Exact two decimal places
 *  e.g. @"16.55" @"16" ,range 0.01~255 .
 *
 *  @param  complete  Calibration succeeded or failed
 *
 *  @return It sends successfully or fails
 */
- (BOOL)calibrateBodyTemp:(NSString *_Nonnull)temp complete:(void(^_Nullable)(BOOL success))complete;

/**
 *  @discussion Read the compensation value of the current calibration temperature
 *
 *  @return It sends successfully or fails
 */
- (BOOL)readDeviceCalibrateBodyTemp:(void(^_Nullable)(NSString *_Nullable temp))result;

/**
 *  @discussion Sync data (from a certain date to today)
 *  Required:isHasBodyTemperature = YES
 *
 *  @param  time From that day. Format:yyyy-MM-dd-HH-mm e.g. @"2018-08-30-09-30"
 *
 *  @return It sends successfully or fails
 *
 */
- (BOOL)syncBodyTemperature:(NSString *_Nonnull)time;

/**
 *  @discussion Time for automatic body temperature test
 *  Required:isHasBodyTemperature = YES
 *
 *  @param on  If YES,turn on automatic temperature test.
 *               If NO,turn off automatic temperature test.
 *
 *  @param testTime See UTEBodyTempTestTime (Test frequency)
 *
 *  @return It sends successfully or fails
 *
 */
- (BOOL)setBodyTemperatureAutoTest:(BOOL)on time:(UTECommonTestTime)testTime;

/**
 *  @discussion Duration of automatic test body temperature
 *  Required:isHasBodyTemperature = YES
 *  When method (setBodyTemperatureAutoTest:time:) parameter on is YES, this method is valid.
 *
 *  @param on  If YES,  body temperature is automatically test between startTime and endTime.
 *               If NO,  body temperature testing throughout the day.
 *
 *  @param startTime  e.g. @"08:30"
 *  @param endTime    e.g. @"18:00"
 *
 *  @return It sends successfully or fails
 *
 */
- (BOOL)setBodyTemperatureAutoTestDuration:(BOOL)on startTime:(NSString *_Nonnull)startTime endTime:(NSString *_Nonnull)endTime;

/**
 *  @discussion Set body temperature device alarm value
 *  If the body temperature(UTEModelBodyTemperature.bodyTemperature) exceeds the maximum or minimum value,lasts longer than one minute,
 *  the device will alert. See UTEDevicesSateBodyTempAlarm.
 *  Required:isHasBodyTemperature = YES
 *
 *  Max OR Min Temperature range 35 ~ 42.
 *
 *  @param  on  Enable alarm
 *  @param  max   Maximum temperature.
 *  @param  min   Minimum temperature.
 *
 *  @return It sends successfully or fails
 *
 */
- (BOOL)setBodyTemperatureAlarmOpen:(BOOL)on max:(CGFloat)max alarmMin:(CGFloat)min;

/**
 *  @discussion Turn on body temperature Funtion2(original data collection)
 *
 *  Required:isHasBodyTemperatureFunction2 = YES
 *
 *  @param  on If YES, During the test, UTEModelBodyTemperature.ambientTemperature/shellTemperature have value .
 *                 If NO, During the test, UTEModelBodyTemperature.bodyTemperature/shellTemperature have value .
 *
 *  @return It sends successfully or fails
 *
 */
- (BOOL)setBodyTemperatureEnableFuntion2:(BOOL)on;

/**
 *  @discussion Read Body Temperature Funtion2 Status
 *
 *  Required:isHasBodyTemperatureFunction2 = YES
 *
 *  @return It sends successfully or fails
 *
 */
- (BOOL)readBodyTemperatureFuntion2Status:(void(^_Nullable)(BOOL on))result;

/**
 *  @discussion Read Current Body Temperature Current
 *
 *  Required:isHasBodyTemperature = YES
 *
 *  CallBack: See delegate uteManagerDevicesSate:UTEDevicesSateBodyTempCurrent
 *  Note:It may take 10 to 30 seconds before the body temperature data is CallBack.
 *
 *  @return It sends successfully or fails
 *
 */
- (BOOL)readBodyTemperatureCurrent;

#pragma mark - Respiration
/**
 *  @discussion Read respiration status
 *  Whether the device is detecting
 *
 *  @return It sends successfully or fails
 */
- (BOOL)readRespirationStatus:(void(^_Nullable)(BOOL isDetecting))result;

/**
 *  @discussion Time for automatic Respiration test
 *
 *  @return It sends successfully or fails
 *
 */
- (BOOL)setRespirationAutoTest:(BOOL)on time:(UTECommonTestTime)testTime;

/**
 *  @discussion Duration of automatic test Respiration
 *  When method (setRespirationAutoTest:time:) parameter on is YES, this method is valid.
 *
 *  @param on  If YES,  Respiration is automatically test between startTime and endTime.
 *               If NO,  Respiration testing throughout the day.(For different series of devices, it will be different. Please consult the developer)
 *
 *  @param startTime  e.g. @"08:30"
 *  @param endTime    e.g. @"18:00"
 *
 *  @return It sends successfully or fails
 *
 */
- (BOOL)setRespirationAutoTestDuration:(BOOL)on startTime:(NSString *_Nonnull)startTime endTime:(NSString *_Nonnull)endTime;

#pragma mark - BloodOxygen
/**
 *  @discussion Read Blood Oxygen status
 *  Whether the device is detecting
 *
 *  @return It sends successfully or fails
 */
- (BOOL)readBloodOxygenStatus:(void(^_Nullable)(BOOL isDetecting))result;

/**
 *  @discussion Time for automatic Blood Oxygen test
 *
 *  @return It sends successfully or fails
 *
 */
- (BOOL)setBloodOxygenAutoTest:(BOOL)on time:(UTECommonTestTime)testTime;

/**
 *  @discussion Duration of automatic test BloodOxygen
 *  When method (setBloodOxygenAutoTest:time:) parameter on is YES, this method is valid.
 *
 *  @param on  If YES,  BloodOxygen is automatically test between startTime and endTime.
 *               If NO,  BloodOxygen testing throughout the day.
 *
 *  @param startTime  e.g. @"08:30"
 *  @param endTime    e.g. @"18:00"
 *
 *  @return It sends successfully or fails
 *
 */
- (BOOL)setBloodOxygenAutoTestDuration:(BOOL)on startTime:(NSString *_Nonnull)startTime endTime:(NSString *_Nonnull)endTime;

#pragma mark - Sport
/**
 *  @discussion How many sports does the device support
 *  Required:isHasMoreSportType = YES
 *
 *  @param callback
 *  minDisplay : The minimum number of sports  displayed on the device interface
 *  maxDisplay : The maximum number of sports  displayed on the device interface
 *  array : Which sports are supported by the device. See UTEDeviceSportMode (Convert to NSNumber)
 *  Tips: The number of sport cannot exceed maxDisplay and less than minDisplay (When invoke setUTESportModelCurrentDisplay:)
 *
 *  @return It sends successfully or fails
 */
- (BOOL)readUTESportModelSupport:(void(^_Nullable)(NSInteger minDisplay,NSInteger maxDisplay, NSArray<NSNumber *> * _Nullable array))callback;

/**
 *  @discussion Which sports are displayed by the device
 *  Required:isHasMoreSportType = YES
 *
 *  @param callback  array  See UTEDeviceSportMode (Convert to NSNumber)
 *  The order of array is the order of Sport Type in the device.
 *
 *
 *  @return It sends successfully or fails
 */
- (BOOL)readUTESportModelCurrentDisplay:(void(^_Nullable)(NSArray<NSNumber *> * _Nullable array))callback;

/**
 *  @discussion Read the status of the device's sport mode
 *  Required:isHasSportHRM = YES
 *
 *  Note:When isHasHeadsetHRM=YES, please invoke readUTESportHeadsetModelStatus
 *  Each time the device is successfully connected, the SDK will automatically read it once.
 *
 *  @return It sends successfully or fails
 */
- (BOOL)readUTESportModelStatus:(void(^_Nullable)(UTEDeviceSportMode mode,UTEDeviceSportModeStatus status))callback;
/**
 *  @discussion Read the status of the Headset's sport mode.
 *  Each time the device is successfully connected, the SDK will automatically read it once.
 *
 *  Required:isHasHeadsetHRM=YES
 *  Callback: uteManagerHeadsetSport
 *
 *  @return It sends successfully or fails
 */
- (BOOL)readUTESportHeadsetModelStatus;

/**
 *  @discussion Set sport mode on or off
 *  Required:isHasSportHRM=YES
 *
 *  Note:When isHasHeadsetHRM=YES please invoke setUTESportHeadsetModel.
 *  Method uteManagerReceiveSportHRM to monitor heart rate and other data.
 *
 *  @param  on Turn on or off
 *  @param  hrmTime How often does the device save the heart rate value.
 *  @param  mode See UTEDeviceSportMode
 *  @param  callback When the device receives command, there is a callback.OR see delegate uteManagerReceiveSportMode:status
 *
 *  Note:If the device has turned on a sport mode A, and then turn it on or off a sport mode(Not Sport Mode A), then there is no callback.
 *
 *  @return It sends successfully or fails
 */
- (BOOL)setUTESportModel:(UTEDeviceSportMode)mode
                    open:(BOOL)on
                 hrmTime:(UTEDeviceIntervalTime)hrmTime
                callback:(void(^_Nullable)(UTEDeviceSportMode mode,BOOL on))callback;

/**
 *  @discussion Set sport mode pause
 *  Required:isHasSportPause=YES
 *
 *  @param info See UTEDeviceSportModeInfo
 *  Note:Set the parameters(UTEDeviceSportModeInfo) ensure that the activity duration of the App is consistent with the activity duration of the device.
 *  See delegate uteManagerReceiveSportMode:
 *
 *  @return It sends successfully or fails
 */
- (BOOL)setUTESportModelPause:(UTEDeviceSportModeInfo *_Nonnull)info;

/**
 *  @discussion Set sport mode continue
 *  Required:isHasSportPause=YES
 *
 *  @param info See UTEDeviceSportModeInfo
 *  Note:Set the parameters(UTEDeviceSportModeInfo) ensure that the activity duration of the App is consistent with the activity duration of the device.
 *  See delegate uteManagerReceiveSportMode:
 *
 *  @return It sends successfully or fails
 */
- (BOOL)setUTESportModelContinue:(UTEDeviceSportModeInfo *_Nonnull)info;

/**
 *  @discussion Set sport mode Info
 *  Required:isHasSportPause=YES
 *
 *  @param info See UTEDeviceSportModeInfo
 *  Note:You should set the parameters(UTEDeviceSportModeInfo) every second by invoke this method.
 *  In order to keep the device time consistent with the app time during exercise.
 *  There is no need to invoke this method after the exercise is over.
 *
 *  No need to fill in UTEDeviceSportModeInfo.status
 *
 *  When Sport model is
 *  1.UTEDeviceSportModeWalking/UTEDeviceSportModeRunning/UTEDeviceSportModeCycling ,
 *  UTEDeviceSportModeMountaineering
 *  2.OR UTEDeviceSportModeIndoorWalking/UTEDeviceSportModeIndoorRunning/UTEDeviceSportModeStepping
 *  UTEDeviceSportModeOutdoorWalking/UTEDeviceSportModeHiking/UTEDeviceSportModeParkour
 *  UTEDeviceSportModeMarathon
 *  3.ORset UTEDeviceSportModeInfo.isCustomSport=YES (This parameter cannot be set freely. Please ask the developer or refer to the SDK online documentation)
 *  parameters(UTEDeviceSportModeInfo.calories , UTEDeviceSportModeInfo.distance ,UTEDeviceSportModeInfo.speed) need to be filled.
 *  Otherwise, the calorie, distance and speed of the device's sport interface are always 0.
 *
 *  @return It sends successfully or fails
 */
- (BOOL)setUTESportModelInfo:(UTEDeviceSportModeInfo *_Nonnull)info;

/**
 *  @discussion Set Headset sport mode on or off
 *  Required:isHasHeadsetHRM=YES
 *
 *  Note:If the app and device are disconnected for 10 minutes, the heart rate headset will automatically end the exercise.
 *  Status can be monitored through method uteManagerHeadsetSport
 *
 *  @param  on Turn on or off
 *  @param  hrmTime Unit second, Range(1~200). How often have a heart rate.
 *   Method uteManagerReceiveSportHRM to monitor heart rate and other data.
 *
 *  @param  mode See UTEDeviceSportMode
 *
 *  @return It sends successfully or fails
 */
- (BOOL)setUTESportHeadsetModel:(UTEDeviceSportMode)mode
                           open:(BOOL)on
                        hrmTime:(NSInteger)hrmTime;
                        
/**
 *  @discussion Set which sport types are currently displayed on the device
 *  Required:isHasMoreSportType = YES
 *
 *  @param  array  See UTEDeviceSportMode (Convert to NSNumber)
 *  The order of array is the order of Sport Type in the device.
 *
 *  @param  callback if YES  (errorCode = 0), device successfully received the data.
 *  OR errorCode = 1, The number of devices displayed exceeds the limit.
 *
 *  Note: See method readUTESportModelSupport:
 *  Do not fill in the sports that the device does not support, otherwise the device interface will display a blank line.
 *
 *  @return It sends successfully or fails
 */
- (BOOL)setUTESportModelCurrentDisplay:(NSArray<NSNumber *> * _Nonnull)array callback:(void(^_Nullable)(BOOL success, NSInteger errorCode))callback;

/**
 *  @discussion Sport  heart rate alert
 *  Required: isHasSportTargetHRM=YES
 *
 *  @param minHRMAlert Range 50~180
 *  @param maxHRMAlert Range 70~200
 *
 *  @return It sends successfully or fails
 */
- (BOOL)setUTESportHRMAlert:(NSInteger)minHRMAlert alertMax:(NSInteger)maxHRMAlert open:(BOOL)on;

/**
 *  @discussion Sport target distance
 *  Required: isHasSportTargetHRM=YES
 *
 *  @param distance Unit meter. Range 100~1000000
 *
 *  @return It sends successfully or fails
 */
- (BOOL)setUTESportTargetDistance:(NSInteger)distance open:(BOOL)on;

/**
 *  @discussion Sport target duration
 *  Required: isHasSportTargetHRM=YES
 *
 *  @param duration Unit seconds. Range 120~86400
 *
 *  @return It sends successfully or fails
 */
- (BOOL)setUTESportTargetDuration:(NSInteger)duration open:(BOOL)on;

/**
 *  @discussion Sport target calories
 *  Required: isHasSportTargetHRM=YES
 *
 *  @param calories Unit kcal. Range 50~10000
 *
 *  @return It sends successfully or fails
 */
- (BOOL)setUTESportTargetCalories:(NSInteger)calories open:(BOOL)on;

/**
 *  @discussion Sync data(All sport data from a certain day to today)
 *  Required:isHasSportHRM=YES
 *  See UTEDevicesSateSyncSuccess,key:kUTEQuerySportHRMData.
 *
 *  @param  time From that day. Format:yyyy-MM-dd-HH-mm  e.g. @"2018-08-30-09-30"
 *
 *  @return It sends successfully or fails
 */
- (BOOL)syncUTESportModelCustomTime:(NSString *_Nonnull)time;

/**
 *  @discussion Set which sports icons are displayed
 *  Required:isHasCustomSportIconList = YES
 *  @param array See Enum UTEDeviceSportMode
 *  e.g. @[[NSNumber numberWithInteger:UTEDeviceSportModeRunning], [NSNumber numberWithInteger:UTEDeviceSportModeCycling]]
 *
 *  @return It sends successfully or fails
 *
 *  Note:The order in array is the order in which it is displayed.
 */
- (BOOL)setSportIcons:(NSArray *_Nonnull)array callback:(void(^_Nullable)(BOOL success))callback;

/**
 *  @discussion Get which sports icons are showing
 *  Required:isHasCustomSportIconList = YES
 *  @param callback See Enum UTEDeviceSportMode
 *
 *  e.g. @[[NSNumber numberWithInteger:UTEDeviceSportModeRunning], [NSNumber numberWithInteger:UTEDeviceSportModeCycling]]
 *
 *  @return It sends successfully or fails
 *
 *  Note:
 *  1.The order in array is the order in which it is displayed.
 *  2.arrayShow : How many icons are currently displayed on the device
 *  3.arrayHide : How many icons are hidden on the current device
 *  4.minShow : Indicates how many icons need to be displayed at least. If it is 0, it means that the device does not support this attribute.
 *  5.maxShow : Indicates how many icons can be displayed at most. If it is 0, it means that the device does not support this attribute.
 *
 */
- (BOOL)readSportIconShow:(void(^_Nullable)(NSArray * _Nullable arrayShow ,NSArray * _Nullable arrayHide, BOOL success, NSInteger minShow, NSInteger maxShow))callback;

/**
 *  @discussion Tell the device whether the app location succeeds or fails
 *  Required:isHasSportGPS = YES
 *
 *  @return It sends successfully or fails
 */
- (BOOL)setAppLocationEnable:(BOOL)success;

/**
 *  @discussion Send GPS data to device
 *  Required:isHasSportGPS = YES
 *
 *  @return It sends successfully or fails
 */
- (BOOL)setAppLocationData:(UTEModelDeviceGPS *_Nonnull)model;

/**
 *  @discussion (Listen to user clicks)On the device interface, the user clicks to start/stop sport
 *
 *   return Yes Or No,  decide whether to allow the device to start sport
 */
- (void)onNotifySportStart:(BOOL(^_Nullable)(UTEDeviceSportMode startMode,BOOL start))callback;

#pragma mark - Ali pay
/**
 *  @discussion Check if Ali  has been activated
 *  Required:isHasAliPay = YES
 *
 *  Note: if isAutoMode = Yes, The app needs to be actively activated.
 *      if isAutoMode = NO,The app needs to wait for the request from ble to activate.(See  uteManagerReceiveAliRequestActivation)
 */
- (void)checkAliPayActivate:(void (^_Nullable)(BOOL isActivate,BOOL isAutoMode))callback;

/**
 *  @discussion Read  Ali  status
 *  Required:isHasAliPay = YES
 */
- (void)readAliPayActivateStatus:(void (^_Nullable)(BOOL processing))callback;

/**
 *  @discussion Received Device AliPay Request Activation
 */
- (void)receiveAliRequestActivation:(void (^_Nullable)(void))callback;
/**
 *  @discussion App sends Ali data to the device
 */
- (void)sendAliData:(NSData *_Nonnull)data;
/**
 *  @discussion Received Device AliPay Data
 */
- (void)notifyAliData:(void (^_Nullable)(NSData * _Nullable data))callback;
/**
 *  @discussion App notification of device Ali activation failure
 */
- (void)sendAliActivationFail;

/**
 *  @discussion Notify AliPay result
 *  isSuccess: Activate Success or Fail
 *  isFunctionInvalid: The AliPay of this device can no longer be used.
 */
- (void)notifyAliActivationResult:(void (^_Nullable)(BOOL isSuccess,BOOL isFunctionInvalid))callback;

#pragma mark - Off Screen

/**
 *  @discussion Off Screen Display
 *  Required isHasOffScreenDisplay=Yes.
 *  See UTECallBackOffScreenDisplayType, when device received value.
 */
- (void)setOffScreenDisplayType:(UTEOffScreenDisplayType)displayType;
/**
 *  @discussion Off Screen Index
 *  Required isHasOffScreenDisplay=Yes.
 *
 *  See UTECallBackOffScreenIndex, when device received value.
 */
- (void)setOffScreenIndex:(NSInteger)index;

/**
 *  @discussion Off Screen Time range
 *  Required isHasOffScreenDisplay=Yes.
 *
 *  @param  startTime HH-mm
 *  @param  endTime HH-mm
 *
 *  See UTECallBackOffScreenTimeRange, when device received value.
 */
- (void)setOffScreenTimeRange:(NSString *_Nonnull)startTime endTime:(NSString *_Nonnull)endTime;

/**
 *  @discussion Read Off Screen Param
 *  Required isHasOffScreenDisplay=Yes.
 */
- (void)readOffScreenParam:(void(^_Nullable)(UTEModelOffScreenDisplay * _Nullable model))callback;

/**
 *  @discussion Device actively returns to displayType
 */
- (void)onNotifyOffScreenActiveDisplayType:(void(^_Nullable)(UTEOffScreenDisplayType displayType))callback;

/**
 *  @discussion Device actively returns to off screen index
 */
- (void)onNotifyOffScreenActiveIndex:(void(^_Nullable)(NSInteger index))callback;

/**
 *  @discussion Device actively returns to time range
 *   startTime : HH-mm
 *   endTime : HH-mm
 */
- (void)onNotifyOffScreenActiveTimeRange:(void(^_Nullable)(NSString * _Nullable startTime,NSString * _Nullable endTime))callback;

#pragma mark - 4G
/**
 *  @discussion Read device imei
 */
- (BOOL)readDevice4Gimei:(void(^_Nullable)(NSString * _Nullable imei))block;

/**
 *  @discussion Set the upload interval for 4G data
 *  @param interval minute
 *   See delegate uteManageUTEOptionCallBack:UTECallBack4GInterval
 */
- (BOOL)sendDeviceUpload4GDataInterval:(NSInteger)interval;

#pragma mark - Prayer
/**
 *  @discussion Set Prayer Time
 *  Delete all, please fill in nil
 */
- (BOOL)sendPrayInfo:(NSArray<UTEModelPrayInfo *> *_Nullable)info callback:(void(^_Nullable)(BOOL success))callback;

/**
 *  @discussion Read Prayer Time
 */
- (BOOL)readPrayInfo:(void(^_Nullable)(NSArray<UTEModelPrayInfo *> *_Nullable info,NSError * _Nullable error))callback;
/**
 *  @discussion Read Prayer Status
 */
- (BOOL)readPrayStatus:(void(^_Nullable)(BOOL show,NSError * _Nullable error))callback;
/**
 *  @discussion Device actively returns to  prayer information
 */
- (void)onNotifyPrayInfo:(void(^_Nullable)(NSArray<UTEModelPrayInfo *> *_Nullable))callback;

/**
 *  @discussion Show or hide the device's prayer interface
 */
- (BOOL)showPrayInfo:(BOOL)show callback:(void(^_Nullable)(BOOL success))callback;


#pragma mark - Other
/**
 *  @discussion Listen custom characteristics
 *
 *  See  delegate uteManagerUpdateValueForCharacteristic:error
 */
- (void)listenCutomCharacteristic:(NSArray<NSString *> *_Nullable)cbs callback:(void (^_Nullable)(NSArray<CBCharacteristic *> * _Nullable arrayCbs))callback;
- (void)notifyValue:(BOOL)notify cb:(CBCharacteristic *_Nonnull)cb;
- (void)sendCustomData:(NSData *_Nonnull)data characteristic:(CBCharacteristic *_Nonnull)cb response:(BOOL)resp;
/**
 *  @discussion Read History Of Swim Category
 *  Required:isHasSwimCategory = YES
 *  @param  time yyyy-MM-dd-HH-mm-ss
 *
 *  See uteManagerDevicesSate:error:userInfo
 */
- (BOOL)syncSwimCategoryHistory:(NSString *_Nonnull)time;
/**
 *  @discussion Power saving mode
 *  Required:isHasPowerSave = YES
 *
 *  @param  startTime HH-mm
 *  @param  endTime HH-mm
 */
- (BOOL)setUTEPowerSavingMode:(BOOL)enable startTime:(NSString *_Nonnull)startTime endTime:(NSString *_Nonnull)endTime callback:(void (^_Nullable)(BOOL success))callback;
/**
 *  @discussion Read Power saving mode info
 *  Required:isHasPowerSave = YES
 */
- (BOOL)readUTEPowerSavingModeInfo:(void (^_Nullable)(BOOL enable,NSString *_Nonnull startTime,NSString *_Nonnull endTime))callback;
/**
 *  @discussion set device screen light time
 *  Required:isHasHandLightCtl = YES
 *  
 *  @param  open enable
 *  @param  time  Unit sec
 */
- (BOOL)setUTEDeviceLighTimeOpen:(BOOL)open time:(NSInteger)time callback:(void (^_Nullable)(BOOL success))callback;
/**
 *  @discussion read device screen light time info
 *  Required:isHasHandLightCtl = YES
 */
- (BOOL)readUTEDeviceLighTimeInfo:(void (^_Nullable)(BOOL on,NSInteger time))callback;
/**
 *  @discussion set  title and content of the QR code
 *  Required:isHasModifyQRCode = YES
 *
 *  @param title If it is in English and numbers, the maximum length is 100, otherwise it is 50. The excess will be cut off.
 *  @param content If it is in English and numbers, the maximum length is 300, otherwise it is 150. The excess will be cut off.
 */
- (BOOL)setQRCodeTitle:(NSString *_Nonnull)title content:(NSString *_Nonnull)content callback:(void (^_Nullable)(BOOL success))callback;

/**
 *  @discussion Tell the device the status of the phone
 *
 *  @param  background  Is the phone in the background status
 *  @param  backgroundUpdate  Is the device updatable in the background
 */
- (BOOL)setUTESystemStatus:(BOOL)background backgroundUpdate:(BOOL)backgroundUpdate;
/**
 *  @discussion Correction device to monitor sleep
 *  Required:isHasCustomSleep=Yes
 *
 *  Note:
 *  1. Minimum 3 hours of sleep range at night
 *  2. Minimum 1 hour of siesta range
 *  3. Sleep correction is only for night sleep monitoring and will take effect from tonight.
 *
 *  @return It sends successfully or fails
 */
- (BOOL)setUTESleepAdjustParam:(UTEModelDeviceSleepAdjust *_Nonnull)model;

/**
 *  @discussion Show and hide custom UI interface
 *  Required:isHasCustomDeviceUI=Yes
 *
 *  @param  array See UTEModelDeviceCustomUI or readUTEDeviceCustomUIStatus:
 */
- (void)setUTEDeviceCustomUIStatus:(NSArray<UTEModelDeviceCustomUI *> *_Nonnull)array;

/**
 *  @discussion Check if the device is properly worn on the hand.
 *  Required:isHasControl_WearCheck=Yes
 *
 *  @param  on YES:Check  NO:Don't check
 *  Users who have tattoos on their wrists are advised to turn off this function,
 *  which can improve the accuracy of the heart rate test.
 *
 *  CallBack UTECallBackCheckWearFunctionOpen/UTECallBackCheckWearFunctionClose
 *  
 *  @return It sends successfully or fails
 */
- (BOOL)setUTEDeviceCheckWearOpen:(BOOL)on;

/**
 *  @discussion Display and wearing style
 *  Required: isHasSwitchHand=YES
 *
 *  @param wearType  See UTEWearType
 *  @param sreenType See UTEDeviceSreenDisplayType
 */
- (void)sendUTEWearType:(UTEWearType)wearType sreenType:(UTEDeviceSreenDisplayType)sreenType;

/**
 *  @discussion Drink water reminder
 *  Required:isHasDrinkWaterReminder=Yes
 *
 *  @param  on reminder switch
 *  @param  interval How long is the interval between each time (unit minutes,Range 10~240)
 *  @param  startTime Time range: start time (Format HH:mm e.g. 08:56)
 *  @param  endTime Time range: end time (Format HH:mm e.g. 21:05)
 *
 *  @param  count How many times the device vibrates. Range (1~20) It is recommended 5 times, too much vibration will reduce the battery power.
 *  @param  isSiesta If Yes, it means that there will be no reminder to drink water during the time period 12:00~14:00
 *
 *
 *  @return It sends successfully or fails
 */
- (BOOL)setUTEDeviceReminderDrinkWaterOpen:(BOOL)on
                              intervalTime:(NSInteger)interval
                                 startTime:(NSString *_Nonnull)startTime
                                   endTime:(NSString *_Nonnull)endTime 
                                   vibrate:(NSInteger)count
                                    siesta:(BOOL)isSiesta;
/**
 *  @discussion Drink water reminder
 *  Required:isHasDrinkWaterReminder=Yes
 *
 *  @param  on reminder switch
 *  @param  interval How long is the interval between each time (unit minutes,Range 10~240)
 *  @param  startTime Time range: start time (Format HH:mm e.g. 08:56)
 *  @param  endTime Time range: end time (Format HH:mm e.g. 21:05)
 *
 *  @param  count How many times the device vibrates. Range (1~20) It is recommended 5 times, too much vibration will reduce the battery power.
 *  @param  isSiesta If Yes, it means that there will be no reminder to drink water during the time period 12:00~14:00 (fixed time)
 *
 *  @param  siestaStartTime     Required:isHasCustomSiestaTimeNoDisturb=Yes
 *  @param  siestaEndTime           Required:isHasCustomSiestaTimeNoDisturb=Yes
 *
 *  @return It sends successfully or fails
 */
- (BOOL)setUTEDeviceReminderDrinkWaterOpen:(BOOL)on
                              intervalTime:(NSInteger)interval
                                 startTime:(NSString *_Nonnull)startTime
                                   endTime:(NSString *_Nonnull)endTime
                                   vibrate:(NSInteger)count
                                    siesta:(BOOL)isSiesta
                           siestaStartTime:(NSString *_Nonnull)siestaStartTime
                             siestaEndTime:(NSString *_Nonnull)siestaEndTime;
/**
 *  @discussion Handwashing reminder
 *  Required:isHasHandWashing=Yes
 *
 *  @param  on reminder switch
 *  @param  interval How long is the interval between each time (unit minutes,Range 10~240)
 *  @param  startTime Time range: start time (Format HH:mm e.g. 08:56)
 *  @param  endTime Time range: end time (Format HH:mm e.g. 21:05)
 *
 *  @param  count How many times the device vibrates. Range (1~20) It is recommended 5 times, too much vibration will reduce the battery power.
 *  @param  isSiesta If Yes, it means that there will be no reminder to drink water during the time period 12:00~14:00
 *
 *
 *  @return It sends successfully or fails
 */
- (BOOL)setUTEDeviceReminderHandwashingOpen:(BOOL)on
                              intervalTime:(NSInteger)interval
                                 startTime:(NSString *_Nonnull)startTime
                                   endTime:(NSString *_Nonnull)endTime
                                   vibrate:(NSInteger)count
                                    siesta:(BOOL)isSiesta;

- (BOOL)setUTEDeviceReminderHandwashingOpen:(BOOL)on
                              intervalTime:(NSInteger)interval
                                 startTime:(NSString *_Nonnull)startTime
                                   endTime:(NSString *_Nonnull)endTime
                                   vibrate:(NSInteger)count
                                    siesta:(BOOL)isSiesta
                            siestaStartTime:(NSString *_Nonnull)siestaStartTime
                              siestaEndTime:(NSString *_Nonnull)siestaEndTime;

/**
 *  @discussion Meeting Reminder
 *  Required:isHasMeetingReminder=Yes
 *
 *  @param  array See UTEModelMeeting
 *
 *  Note:
 *  1.Up to 5 meetings.
 *  2.Fill in nil if deleting all meetings.
 *
 *
 *  @return It sends successfully or fails
 */
- (BOOL)setUTEDeviceMeeting:(NSArray<UTEModelMeeting *> *_Nullable)array callback:(void (^_Nullable)(BOOL success))callback;

/**
 *  @discussion World Clock
 *  Required:isHasTimeZone=Yes
 *
 *  @param array See UTEModelRegion.
 *  1.When filling in nil, delete all world clocks.
 *  2.Support up to 5. if isHasTimeZone10=YES,  up to 10
 *  3.The order of the world clock follows the order in the array.
 *
 *  @param callback Whether the device has received valid data.
 *
 *  @return It sends successfully or fails
 */
- (BOOL)setUTEWorldClockTimeZone:(NSArray<UTEModelRegion *> *_Nullable)array callback:(void (^_Nullable)(BOOL success))callback;

/**
 *  @discussion Turn on or off the emergency phone of the device interface
 *  Required:isHasControlEmergencyPhone =Yes
 *
 *  @return It sends successfully or fails
 */
- (BOOL)setUTEEmergencyPhoneOpen:(BOOL)on callback:(void (^_Nullable)(BOOL success))callback;

/**
 *  @discussion Bluetooth status reminder on device interface
 *  Required:isHasDeviceBluetoothReminder =Yes
 *
 *  @return It sends successfully or fails
 */
- (BOOL)setUTEDeviceBluetoothReminderOpen:(BOOL)on callback:(void (^_Nullable)(BOOL success))callback;

/**
 *  @discussion Read Bluetooth status reminder on device interface
 *  Required:isHasDeviceBluetoothReminder =Yes
 *
 *  @return It sends successfully or fails
 */
- (BOOL)readUTEDeviceBluetoothReminderStatus:(void (^_Nullable)(BOOL on))callback;

/**
 *  @discussion Read device version
 *  The device will automatically read it once it is connected.
 *
 *  Also see UTECallBackDevicesVersion
 *
 *  @return It sends successfully or fails
 */
- (BOOL)readUTEDeviceVersion;

/**
 *  @discussion Read device address
 *  The device will automatically read it once it is connected.
 *  Also see UTECallBackDevicesAddress
 *
 *  @return It sends successfully or fails
 */
- (BOOL)readUTEDeviceAddress;
/**
 *  @discussion Read device address
 *  The device will automatically read it once it is connected.
 *
 *  Also see UTECallBackDevicesAddress
 *
 *  address The same as  UTEModelDevices.addressStr
 *
 *  @return It sends successfully or fails
 */
- (BOOL)readUTEDeviceAddressBlock:(void(^_Nullable)(NSString * _Nullable address))block;

/**
 *  @discussion Read the current riding status of the device
 *
 *  @param  result YES or NO
 *
 *  @return It sends successfully or fails
 */
- (BOOL)readUTEDeviceBicycleStatus:(void(^_Nullable)(BOOL isRiding))result;

/**
 *  @discussion Read the current device ball status
 *
 *  @param  result Only one ball can be opened or all closed (allClose = Yes)
 *
 *  @return It sends successfully or fails
 */
- (BOOL)readUTEDeviceBallStatus:(void(^_Nullable)(UTEDeviceBallType type, BOOL on, BOOL allClose))result;

/**
 *  @discussion Read the current device interface (show and hide) status
 *
 *  @param  result the status of the support interface
 *
 *  @return It sends successfully or fails
 */
- (BOOL)readUTEDeviceCustomUIStatus:(void(^_Nullable)(NSArray<UTEModelDeviceCustomUI *> *_Nullable array))result;

/**
 *  @discussion Read device GPS status
 *
 *  @param  result See UTEDeviceGPSStatus
 *  Note:Because there is a lot of GPS data and the storage capacity of the device is limited, it is recommended to send the command UTEOptionDeleteGPSData to delete the GPS data on the device after synchronizing the GPS data.
 *
 *  @return It sends successfully or fails
 */
- (BOOL)readUTEDeviceGPSStatus:(void(^_Nullable)(UTEDeviceGPSStatus status))result;

/**
 *  @discussion Read the connected device signal value
 *
 *  @return It sends successfully or fails
 */
- (BOOL)readDeviceRSSI:(void(^_Nullable)(NSInteger rssi))result;

/**
 *  @discussion What other types of data are not yet synchronized (or what new data)
 *  Required:isHasDataStatus=YES
 *
 *  @param  result UTEModelDeviceDataStatus Not yet synchronized (or new) data attribute is YES
 *
 *  @return It sends successfully or fails
 */
- (BOOL)readDeviceDataStatus:(void(^_Nullable)(UTEModelDeviceDataStatus *_Nullable status))result;

/**
 *  @discussion Sync data (from a certain date to the present)
 *  Required:isHasDataStatus = YES
 *
 *  @param  time From that day. Format:yyyy-MM-dd-HH-mm e.g. @"2018-08-30-09-30"
 *  @param  type See UTEDeviceDataType
 *
 *  @return It sends successfully or fails
 *
 */
- (BOOL)syncDataCustomTime:(NSString *_Nonnull)time type:(UTEDeviceDataType)type;

/**
 *  @discussion Sync data (Get GPS data for specific start time)
 *  Required:isHasGPS = YES
 *
 *  @param  time From that day. Format:yyyy-MM-dd-HH-mm e.g. @"2018-08-30-09-30"
 *
 *  Note:
 *  First invoke method syncDataCustomTime:type to synchronize UTEDeviceDataTypeSportHRM,
 *  if there is UTEModelSportHRMData(sportModel is UTEDeviceSportModeRunning/UTEDeviceSportModeCycling/UTEDeviceSportModeMountaineering/UTEDeviceSportModeWalking) data, then use their UTEModelSportHRMData.timeStart to use method syncDataGPS:UTEModelSportHRMData.timeStart .
 *
 *  Each synchronization returns a piece of data corresponding to the time. If there is no data, it means that there is no GPS data at the corresponding time.
 *
 *  @return It sends successfully or fails
 *
 */
- (BOOL)syncDataGPS:(NSString *_Nonnull)time;

/**
 *  @discussion Daily goal. When the goal is reached, the device will vibrate to remind
 *  Required:isHasActivityGoal=YES
 *  
 *  @param type  See UTEGoalType
 *  @param on  Enable
 *
 *  @param goal
 *  When type is UTEGoalTypeStanding ,unit is minutes, range is 10 ~ 1200
 *  When type is UTEGoalTypeActivity ,unit is minutes, range is 10 ~ 1200
 *  When type is UTEGoalTypeCalorie  ,unit is kcal,    range is 10 ~ 10000
 *  When type is UTEGoalTypeStep     ,unit is number , range is 100 ~ 100000
 *  When type is UTEGoalTypeDistance ,unit is meters , range is 100 ~ 100000
 *  When type is UTEGoalTypeSportTime ,unit is minutes, range is 10 ~ 1200
 *
 *  @return It sends successfully or fails
 */
- (BOOL)setUTEGoalReminder:(UTEGoalType)type open:(BOOL)on goal:(NSInteger)goal callback:(void(^_Nullable)(UTEGoalType callbackType, BOOL callbackOpen))callback;

/**
 *  @discussion Daily history of UTEGoalType
 *  Required:isHasActivityGoal=YES
 *
 *  Tips:
 *  1.Currently only UTEGoalTypeStanding is supported, other enumerations depend on the specific firmware.
 *  2.If Type is UTEGoalType and isHasDataStatus = YES, please invoke syncDataCustomTime:type
 *
 *  @param type  See UTEGoalType
 *
 *  @return It sends successfully or fails
 */
- (BOOL)syncUTEGoalHistory:(UTEGoalType)type;

/**
 *  @discussion When receiving the instruction of the device to find the iPhone, the ringing state of the app.
 *  Required:isHasFindiPhone = YES
 *
 *  @return It sends successfully or fails
 */
- (BOOL)setRingtoneStatus:(BOOL)on;

/**
 *  @discussion Set which Menu icons are displayed
 *  Required:isHasCustomMenuIconList = YES
 *  @param array See Enum UTEMenuIcon
 *  e.g. @[[NSNumber numberWithInteger:UTEMenuIconStatus], [NSNumber numberWithInteger:UTEMenuIconSport]]
 *
 *  @return It sends successfully or fails
 *
 *  Note:The order in array is the order in which it is displayed.
 */
- (BOOL)setMenuIcons:(NSArray *_Nonnull)array callback:(void(^_Nullable)(BOOL success))callback;

/**
 *  @discussion Get which menu icons are showing
 *  Required:isHasCustomMenuIconList = YES
 *  @param callback See Enum UTEMenuIcon
 *  e.g. @[[NSNumber numberWithInteger:UTEMenuIconStatus], [NSNumber numberWithInteger:UTEMenuIconSport]]
 *
 *  @return It sends successfully or fails
 *
 *  Note:The order in array is the order in which it is displayed.
 */
- (BOOL)readMenuIconShow:(void(^_Nullable)(NSArray * _Nullable arrayShow,NSArray * _Nullable arrayHide, BOOL success))callback;

/**
 *  @discussion Modify Bluetooth name
 *  Required:isHasModifyBluetoothName=YES
 *
 *  @param  name The maximum length is 10. Only numbers, English letters, and symbols such as - _ space are supported.
 *
 *  @return It sends successfully or fails
 *
 *  Note:After the modification is completed, you need to restart the Bluetooth device or send UTEOptionDeleteDevicesAllData to factory settings after a delay of more than 0.2 seconds) before the device name takes effect.
 *  1. Because the system has a cache, the system will update the cache after connecting to the device again, and you will see the new name in the next scan.
 *   2. Because the system has a cache, you can also view the broadcast attribute advertisementData in the UTEModelDevices. The key value kCBAdvDataLocalName will change according to the device name in real time.
 *
 *   3.No special circumstances, please do not invoke this method !!!
 */
- (BOOL)modifyUTEBluetoothName:(NSString *_Nonnull)name success:(void(^_Nullable)(BOOL ok))success;

/**
 *  @discussion Current SDK version
 *
 *  @return e.g. @"2.18.9"
 *
 *  Note:If it is a four digit such as @"2.18.9.8", then the last 8 is the 8th debug version.
 */
- (NSString *_Nonnull)sdkVersion;

#pragma mark - Factory Test
/**
 *  @discussion Test for light leakage
 *  Required:isHasFactoryLightLeakage = YES
 *
 *  reesult Temporarily invalid, it can only mean that the device has received the value of the App.
 *  @return It sends successfully or fails.
 */
- (BOOL)factoryReadLightLeakage:(void(^_Nullable)(BOOL success,NSInteger value))result;
- (void)factoryCloseTestLightLeakage;
/**
 *  @discussion Screen auxiliary display
 */
- (void)factoryPostDisplayOpen:(BOOL)on;
/**
 *  @discussion Turn on device stress test
 */
- (void)factoryTestTypeOpenType:(UTEDeviceFactoryType)type result:(void(^_Nullable)(UTEDeviceFactoryType type))result;
- (void)factoryModel:(BOOL)on;
- (void)factoryVibration:(NSInteger)count;
- (void)factoryOriginalSource:(NSString *_Nonnull)cmd;
- (void)factoryOriginalData:(NSData *_Nonnull)data;//Also see uteManagerFactoryTestOriginalDataCallback:

- (void)factoryOpenTestRGB:(BOOL)on;
- (void)factoryOpenTestTP:(BOOL)on callback:(void(^_Nullable)(NSInteger tpCount))callback;
- (void)factoryOpenTestGsensor:(BOOL)on;
- (void)factoryOpenTestGPS:(BOOL)on satelliteID:(NSInteger)satelliteID range:(NSInteger)range reference:(NSInteger)reference result:(void(^_Nullable)(BOOL success,NSInteger cn))result;
- (void)factoryOpenTestNFC:(void(^_Nullable)(BOOL success))result;
- (void)factoryOpenTestMike_Speaker;
- (void)factorySetting:(NSString *_Nonnull)cmd;
- (void)factoryReadGyroData:(void(^_Nullable)(NSInteger range,NSInteger x,NSInteger y,NSInteger z))result;
- (void)factoryReadGeomagnetism:(void(^_Nullable)(BOOL success, CGFloat x,CGFloat y,CGFloat z))result;
- (void)factoryReadAliIC:(void(^_Nullable)(BOOL success))result;
- (void)factoryModifyMac:(NSString *_Nonnull)mac result:(void(^_Nullable)(BOOL success))result;

- (void)setUpdateRKLogOpen:(BOOL)on key:(NSString *_Nonnull)key;
- (void)setUpdateRKSilent:(BOOL)silent key:(NSString *_Nonnull)key;

#pragma mark - UTESmartBandClient Tool
/**
 *  @discussion Calculate calories by distance
 *
 *  @param distance   unit km
 *  @param dataType   Only fill in UTEDeviceSportModeWalking/UTEDeviceSportModeRunning/UTEDeviceSportModeCycling
 *  @param infoWeight unit kg
 *  @param infoSex    See  UTEDeviceInfoSex
 *
 *  @return unit kcal
 */
+ (CGFloat)calculateCaloriesFromDistance:(CGFloat)distance
                                dataType:(UTEDeviceSportMode)dataType
                              infoWeight:(CGFloat)infoWeight
                                 infoSex:(UTEDeviceInfoSex)infoSex;
/**
 *  @discussion Calculate distance by steps
 *
 *  @param dataType   Only fill in UTEDeviceSportModeWalking/UTEDeviceSportModeRunning
 *  @param infoHeight unit cm
 *  @param infoSex    See  UTEDeviceInfoSex
 *
 *  @return unit km
 */
+ (CGFloat)calculateDistanceFromStep:(NSInteger)step
                            dataType:(UTEDeviceSportMode)dataType
                          infoHeight:(CGFloat)infoHeight
                             infoSex:(UTEDeviceInfoSex)infoSex;

/**
 *  @discussion Convert string to hexadecimal data
 *
 *  @param str e.g. @"a0b8"  return NSData <a0b8>
 */
+ (NSData *_Nullable)getData16FromString:(NSString *_Nonnull)str;

/**
 *  @discussion Convert hexadecimal data  to string
 *
 *  @param data e.g. NSData <a0b8>  return @"a0b8"
 */
+ (NSString *_Nullable)getStringFromData16:(NSData *_Nonnull)data;

/**
 *  @discussion Convert image to device data
 *
 *  @param image png OR jpg
 *  @param model see UTEModelDeviceDisplayModel. Invoke readUTEDisplayInfoFormDevice.
 *
 *  Note:If the height and width of image are not equal to model(UTEModelDeviceDisplayModel.width / UTEModelDeviceDisplayModel.height),  image will be automatically cut.
 */
+ (NSData *_Nullable)getBinDataFromImage:(UIImage *_Nonnull)image model:(UTEModelDeviceDisplayModel *_Nonnull)model;

#pragma mark - UTESmartBandClient Traffic card method
/**
 *  @discussion Close channel
 */
- (void)cardCloseApduChannel;
/**
 *  @discussion Send data to the device
 *
 *  @param data Traffic card data
 */
- (void)cardApduSendData:(NSData *_Nonnull)data;

#pragma mark - Used to test firmware local upgrade
- (BOOL)localUpdate:(NSString *_Nonnull)name type:(NSString *_Nonnull)type updateVer:(void(^_Nullable)(NSString *_Nullable updateVer))callback;

#pragma mark - This is an outdated API, compatible with previous versions
/******************************* Do not use *******************************/

- (void)allocateUTEData:(NSData *_Nonnull)data userInfo:(id _Nullable)userInfo response:(BOOL)response;

/******************************* Do not use  ******************************/

@end

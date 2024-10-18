//
//  UTEManagerDelegate.h
//  UTESmartBandApi
//
//  Created by VV on 2017/4/24.
//  Copyright © 2017年 vv. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "UTEDefine.h"

@class UTEModelDevices;
@class UTEModelRunData;
@class UTEModelHourStep;
@class UTEDeviceSportModeInfo;
@class UTEModelBluetooth3_0;
@class UTEModelAlarm;
@class UTEModelShortcutBtn;

#pragma mark - UTEManagerDelegate

/*!
 *  UTEManagerDelegate
 */
@protocol UTEManagerDelegate;

@protocol UTEManagerDelegate <NSObject>

@optional

/**
 *  @discussion It is called once for each device found
 *
 *  @param modelDevices See UTEModelDevices
 */
- (void)uteManagerDiscoverDevices:(UTEModelDevices *)modelDevices;

/**
 *  @discussion Monitor the status of connected devices in real time
 *
 *  @param devicesState See UTEDevicesSate
 *  @param error        See error.code(UTEErrorCode)
 *
 *  Note:In the following cases, enum UTEDevicesSateDisconnected will not be called when the device is disconnected.Because they have their own enumeration.
 *  1.When isSyncDevices = yes ,        device is disconnected, enum UTEDevicesSateSyncError will be called,                  error.code = UTEErrorCodeSyncDisconnect
 *  2.When isUpdateDevices = yes ,     device is disconnected, enum UTEDevicesSateUpdateError will be called,              error.code = UTEErrorCodeUpdateDisconnect
 *  3.When isHeartDetecting = yes ,     device is disconnected, enum UTEDevicesSateHeartDetectingError will be called,  error.code = UTEErrorCodeHeartingDisconnect
 *  4.When isBloodDetecting = yes ,     device is disconnected, enum UTEDevicesSateBloodDetectingError will be called, error.code = UTEErrorCodeBloodDisconnect
 *  5.When isBloodOxygenDetecting = yes , device is disconnected, enum UTEDevicesSateBloodOxygenDetectingError will be called, error.code = UTEErrorCodeBloodOxygenDisconnect
 *  6.When isBodyFatDetecting = yes , device is disconnected, enum UTEDevicesSateBodyFatFail will be called,                error.code = UTEErrorCodeDisconnect
 *  7.When isECGDetecting = yes ,       device is disconnected, enum UTEDevicesSateECGDetectingFail will be called,       error.code = UTEErrorCodeDisconnect
 *  8.When isMPFDetecting = yes ,       device is disconnected, enum UTEDevicesSateMPFDetectingFail will be called,        error.code = UTEErrorCodeDisconnect
 *  9.When isHRMCalibrating = yes ,     device is disconnected, enum UTEDevicesSateHRMCalibrateFail will be called,         error.code = UTEErrorCodeDisconnect
 */
- (void)uteManagerDevicesSate:(UTEDevicesSate)devicesState error:(NSError *)error userInfo:(NSDictionary *)info;

/**
 *  @discussion Bluetooth status
 *
 *  @param bluetoothState See UTEBluetoothSate
 */
- (void)uteManagerBluetoothState:(UTEBluetoothState)bluetoothState;

/**
 *  @discussion
 *   The system will pop up a dialog box asking for pair (the dialog box has not popped up before)
 *
 *   Note:
 *   1.If the device is paired, the system will not pop up a dialog box, no return value
 *   2.If the device has not been paired, the user clicks the pair button (then the device is pair to the system) and returns YES, indicating that the push message reminder is valid. If NO is returned, it indicates that the information push is invalid, and the device will be actively disconnected, please reconnect,but RK platform device will not be disconnected.
 *   3.If the device is paired, there will be an information symbol ⓘ on the right side of the device in the system Bluetooth.
 *   4.If you want to unpair the device, it is recommended to remind the user to manually go to the system Bluetooth and click the 'Ignore Device' button, otherwise the device may not be found during the next scan (Because the device may have already been connected by the system Bluetooth)
 *
 *  @param isAble Information push function works
 *
 */
- (void)uteManagerExtraIsAble:(BOOL)isAble;

/**
 *  @discussion Monitor the device (steps) change in real time, it will be called frequently
 *  Note:When isHasWalkRun=YES,this method is not called, please use uteManagerReceiveTodaySport.
 *
 *  @param runData See UTEModelRunData
 */
- (void)uteManagerReceiveTodaySteps:(UTEModelRunData *)runData;

/**
 *  @discussion Monitor the device (steps) change in real time, it will be called frequently
 *  Required: isHasSleepSporadic=YES.
 *  Note:The total steps, distance and calories in a day need to be calculated by the App itself.
 *
 *  @param model See UTEModelHourStep
 */
- (void)uteManagerReceiveHourSteps:(UTEModelHourStep *)model;

/**
 *  @discussion Monitor the device (steps) of the device in real time. It will be called frequently
 *  Required: isHasWalkRun=YES.
 *  Note:The total steps, distance and calories in a day need to be calculated by the App itself.
 *
 *  @param dict key:kUTEQuerySportWalkRunData value:UTEModelSportWalkRun
 */
- (void)uteManagerReceiveTodaySport:(NSDictionary *)dict;

/**
 *  @discussion Monitor Device UTEDeviceSportMode status
 *  Required:isHasSportHRM=YES OR isHasSportPause=YES.
 *
 */
- (void)uteManagerReceiveSportMode:(UTEDeviceSportModeInfo *)info;

/**
 *  @discussion It monitors the change of the device's sport data in real time, and it will be called frequently.
 *  Required:isHasSportHRM=Yes OR isHasHeadsetHRM=Yes .
 *
 *  @param dict key:kUTEQuerySportHRMData        value:UTEModelSportHRMData
 *         dict key:kUTEQuerySportHeadsetData    value:UTEModelSportHeadsetData
 */
- (void)uteManagerReceiveSportHRM:(NSDictionary *)dict;

/**
 *  @discussion Device automatically return Sport Status
 *  Required:isHasSportGPS=Yes .
 *  @param status See UTEDeviceSportModeStatus
 *  @param sport See UTEDeviceSportMode
 */
- (void)uteManagerReceiveSportStatus:(UTEDeviceSportModeStatus)status sport:(UTEDeviceSportMode)sport;

/**
 *  @discussion Device requests app to send GPS coordinates
 *  Required:isHasSportGPS=Yes .
 *  @param needGPS  Does the device need App GPS
 *  @param interval Interval between app sending GPS,  app should stop sending data.
 *
 *  Note:
 *  1. When needGPS=YES , App needs to turn on the GPS of the phone. If the location succeeds or fails, App should invoke method (setAppLocationEnable: ) to tell the device.
 *  Then every second (reference parameter interval), invoke the method (setAppLocationData: ) to send GPS coordinates to the device.
 *  2. When needGPS=NO, Indicates that the device does not need the app's GPS positioning.
 */
- (void)uteManagerReceiveNeedGPS:(BOOL)needGPS interval:(NSInteger)interval;

/**
 *  @discussion Device automatically returns heart rate data
 *  Required:isHasHRMValueMaxMin=Yes .
 *
 */
- (void)uteManagerReceiveHRMMaxValue:(NSInteger)max minValue:(NSInteger)min averageValue:(NSInteger)average;

/**
 *  @discussion Device automatically returns Heart Rate (Current hour )
 *  Required:isHasRHRM=Yes .
 *
 *  @param max Value may be 0
 *  @param min Value may be 0
 *  @param rhr  Resting Heart Rate . Value may be 0
 *  @param time  Time format yyyy-MM-dd-HH
 */
- (void)uteManagerReceiveHRMMaxValue:(NSInteger)max minValue:(NSInteger)min rhr:(NSInteger)rhr time:(NSString *)time;

/**
 *  @discussion Progress of syncing data.
 *  @param process 0 to 100
 */
- (void)uteManagerSyncProcess:(NSInteger)process;

/**
 *  @discussion Progress of firmware upgrade.
 *
 *  @param process 0 to 100
 */
- (void)uteManagerUpdateProcess:(NSInteger)process;
/**
 *  @discussion Progress of downloading firmware from the server
 *
 *  @param process 0 to 100
 */
- (void)uteManagerDownloadFWProcess:(NSInteger)process;

/**
 *  @discussion When the device UTEOptionOpenCameraMode enters the camera mode, it will be called back every 3 shakes.
 *   Note:You must call UTEOptionCloseCameraMode to exit the camera mode, otherwise the device may not record the number of steps.(If the device is disconnected, it will automatically exit the camera mode.)
 */
- (void)uteManagerTakePicture;

/**
 *  @discussion The device entered camera mode
 *  Note:Only some devices support this method.
 */
- (void)uteManagerEnterCameraMode;

/**
 *  @discussion The device has exited camera mode
 *  Note:Only some devices support this method.
 */
- (void)uteManagerExitCameraMode;

/**
 *  @discussion After querying by calling UTEOptionReadDisplaySize(setUTEOption:), this method callback.
 *
 *  @param width   Device screen resolution.
 *  @param height  Device screen resolution.
 *  @param count   Replaceable quantity.
 */
- (void)uteManagerDisplaySizeWidth:(NSInteger)width height:(NSInteger)height count:(NSInteger)count;

/**
 *  @discussion Read ibeacon information through method readUTEIbeacon, this method callback.
 */
- (void)uteManagerUTEIbeaconOption:(UTEIbeaconOption)option value:(NSString *)value;

/**
 *  @discussion The SDK sends a command to the device. If the device receives value, this method will have callback.
 */
- (void)uteManageUTEOptionCallBack:(UTECallBack)callback;

/**
 *  @discussion Device key events (or touch feedback)
 *
 *  @param data Received device return value
 *  e.g. 'data' is <D10A> ,2 bytes, Indicates that the device has been clicked (or touched) (find iPhone)
 *  e.g. 'data' is <D10A0100> ,4 bytes, Indicates that the device has been clicked again (or touched again) (stop find iPhone)
 */
- (void)uteManageTouchDeviceReceiveData:(NSData *)data;

/**
 *  @discussion See sendUTECustomData
 *
 *  @param result  Data transmitted successfully (no lost data)
 */
- (void)uteManagerSendCustomDataResult:(BOOL)result;

/**
 *  @discussion Continue to send the remaining data
 *
 *  Note:When invoke sendUTECustomData:  to send data, if the data is too large,SDK will split the data and send it multiple times.
 *  Before each send, this proxy will be called to ask whether to continue sending.
 *
 *  Default yes if this proxy is not used.
 *
 */
- (BOOL)uteManagerSendCustomDataContinue;

/**
 *  @discussion Device returns custom data
 *
 *  @param data    Data returned by the device
 *  @param result  Data transmitted successfully (no lost data)
 */
- (void)uteManagerReceiveCustomData:(NSData *)data result:(BOOL)result;

/**
 *  @discussion     Sport status of Headset.
 *
 *  @param mode     See UTEDeviceSportMode
 *  @param open     Whether it is in sport model.
 *
 *  Note:If the state is open=NO, it means that the sport is stopped, and the mode is UTEDeviceSportModeNone.
 *
 *  @param support  Device support this sport type
 */
- (void)uteManagerHeadsetSport:(UTEDeviceSportMode)mode open:(BOOL)open suppport:(BOOL)support;

/**
 *  @discussion What shortcut buttons the device supports.
 *  See method readDeviceShortcutBtnSupport
 *
 *  Note:Please use "bitwise AND" for value
 *  It is recommended to use uteManagerShortcutBtnSupportModel:
 */
- (void)uteManagerShortcutBtnSupport:(UTEDeviceShortcutBtnType)type;

/**
 *  @discussion Status of device shortcut buttons.
 *  See method readDeviceShortcutBtnStatus
 *
 *  @param openType     Which button states are on.
 *  @param closeType    Which button states are off.
 *
 *  Note:
 *  1.Support bitwise AND operation
 *  2.The value of the status button is only valid if the function is supported.  See method readDeviceShortcutBtnSupport
 *  3.It is recommended to use uteManagerShortcutBtnStatusModel:
 */
- (void)uteManagerShortcutBtnStatus:(UTEDeviceShortcutBtnType)openType closeType:(UTEDeviceShortcutBtnType)closeType;

/**
 *  @discussion What shortcut buttons the device supports.
 *  See method readDeviceShortcutBtnSupport
 */
- (void)uteManagerShortcutBtnSupportModel:(UTEModelShortcutBtn *)model;

/**
 *  @discussion Status of device shortcut buttons.
 *  The value of the status button is only valid if the function is supported.  See method readDeviceShortcutBtnSupport
 */
- (void)uteManagerShortcutBtnStatusModel:(UTEModelShortcutBtn *)model;

/**
 *  @discussion Heart rate data returned every ten minutes
 *
 *  @param dict key:kUTEQuery24HRMData value:UTEModelHRMData
 */
- (void)uteManagerReceiveTenMinLaterHRM:(NSDictionary *)dict;

/**
 *  @discussion Device debugging information.
 */
- (void)uteManagerReceiveDebugInfo:(NSDictionary *)dict;

/**
 *  @discussion System Bluetooth notification permissions (share system notification permission status, not pairing status bound by the device).
 */
- (void)uteManagerANCSAuthorization:(BOOL)ancsAuthorized NS_AVAILABLE_IOS(13_0);

/**
 *  @discussion Device user id status
 */
- (void)uteManagerUserIDStatus:(UTEUserIDStatus)status;

/**
 *  @discussion Received firmware UI version
 *  @param ver    version of the firmware e.g. @"U0008"
 */
- (void)uteManagerReceiveFirmwareUI:(NSString *)ver;

/**
 *  @discussion Received Device Bluetooth3.0 info
 *  @param model  See UTEModelBluetooth3_0
 *
 *  Required: isHasBluetooth3=YES.
 */
- (void)uteManagerReceiveBluetooth3Info:(UTEModelBluetooth3_0 *)model;

/**
 *  @discussion Device changed alarm clock(Add or delete on the device interface)
 *  @param array If is nil, Indicates that the device does not have alarm clock.
 *  @param success The data is complete and there is no loss.
 *
 *  Required: isHasClockTitle=YES.
 */
- (void)uteManagerReceiveAlarmChange:(NSArray<UTEModelAlarm *> *)array success:(BOOL)success;

/**
 *  @discussion custom characteristics value call back
 */
- (void)uteManagerUpdateValueForCharacteristic:(CBCharacteristic *)cb error:(NSError *)error;

/**
 *  @discussion Continuous monitoring of MPF
 *  @param isAppCtl start from app, or start from device
 *  @param isStop The test starts or stops
 *  @param type The type of stop
 *  @param dict {kUTEQueryMPF_PPG:NSData}
 *
 */
- (void)uteManagerMPFContinuousTesting:(BOOL)isAppCtl isStop:(BOOL)isStop stopType:(UTETestingStopType)type dict:(NSDictionary *)dict;

- (void)uteManagerReceivePrepareInfo:(NSString *)uuid version:(NSString *)version address:(NSString *)address error:(NSError *)error;

#pragma mark - FactoryTest
- (void)uteManagerFactoryTestOriginalDataCallback:(NSData *)data;
- (void)uteManagerFactoryTestButtonCallback:(NSInteger)totalButton currentBtnIndex:(NSInteger)index;
- (void)uteManagerFactoryTestTpCallback:(NSInteger)position;
- (void)uteManagerFactoryTestRGBCallback:(BOOL)open;
- (void)uteManagerFactoryTestLogData:(NSData *)data strData:(NSString *)strData tag:(NSInteger)tag;

#pragma mark - debug info
- (void)uteManagerDebugLogData:(NSData *)data;

@end

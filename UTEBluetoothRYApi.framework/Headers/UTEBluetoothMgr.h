//
//  UTEBluetoothRYMgr.h
//  UTEBluetoothRYApi
//
//  Created by VV on 23/03/07.
//  Copyright © 2023年 vv. All rights reserved.
// 

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <UIKit/UIKit.h>
#import "UTEBluetoothDelegate.h"
#import "UTEModelDevice.h"
#import "UTEOTAMgr.h"
#import "UTEDeviceMgr.h"
#import "RYUTELogTool.h"
#import "UTEDeviceError.h"


typedef void (^uteDevicesStatusBlock)(UTEDevicesStatus status,NSError *error, NSDictionary *info);
typedef void (^uteBluetoothStatusBlock)(UTEBluetoothStatus status);

typedef void (^syncOrderBlock)(BOOL ok);

@interface UTEBluetoothMgr : NSObject

@property (nonatomic,strong,readonly) RYUTELogTool           *mgrLog;
@property (nonatomic,strong,readonly) UTEOTAMgr              *mgrOTA;
@property (nonatomic,strong,readonly) UTEDeviceMgr           *mgrDevice;

/**
 *  Scan devices repeatedly, default NO.
 *  Note:If yes,the signal value of the device is updated in real time during the scanning process.
 */
@property (nonatomic,assign) BOOL         isScanRepeat;
/**
 *  Set the signal strength of the device to be scanned.
 *  Range(0 > filerRSSI > -100, default None)
 */
@property (nonatomic,assign) NSInteger    filerRSSI;
/**
 *  Sets the name of the specified device to be scanned. It is case sensitive. The default is nil.
 */
@property (nonatomic,copy  ) NSString      *filterName;
/**
 *  The UUID of different products is different. e.g. @[ @[@"55dd",@"66ff"], @[@"22dd",@"33ff"] ]
 *  Note:You can use third-party software (Lightblue) to connect the device to view the broadcast UUID.
 *  (Lightblue has key value Service UUIDs in Adverisement Data)
 */
@property (nonatomic,strong) NSArray       *filerServersArray;

@property (nonatomic,assign) BOOL                   isOpenBluetooth;
@property (nonatomic,assign) UTEBluetoothStatus     bluetoothStatus;
@property (nonatomic,assign) BOOL                   ancsAuthorized;

/**
 *  Delegate
 */
@property (nonatomic,weak  ) id<UTEBluetoothDelegate> delegate;


/**
 *  Set this value in advance, and then call the connected device. When the connection status between the device and the app changes,
 *  when the app is in the background, the phone will pop up a system dialog prompt. Default UTEDeviceAlertTypeRequiresANCS.
 *  Note:DeviceAlertType only works if Bluetooth background permissions are not enabled in "Background Mode" in xcode.
 */
@property (nonatomic,assign) UTEBluetoothAlertType   deviceAlertType;
@property (nonatomic,assign) UTEBluetoothAlertType   deviceAlertTypeExcluding;

@property (nonatomic,strong) UTEModelDevice          *connnectModel;

@property (nonatomic,copy  ) uteDevicesStatusBlock   uteDevicesStatusBlock;
@property (nonatomic,copy  ) uteBluetoothStatusBlock uteBluetoothStatusBlock;

@property(nonatomic, copy  ) syncOrderBlock syncOrderBlock;

@property (nonatomic,assign) BOOL                    isFactoryMode;

/**
 *  @return UTEBluetoothMgr
 */
+ (UTEBluetoothMgr *)sharedInstance;

/**
 *  @discussion Initialize UTEBluetoothMgr to allow SDK to obtain Bluetooth management and proxy permissions
 *  Note: After about 1 ~ 2 seconds, the SDK will obtain Bluetooth permissions
 */
- (void)initUTEMgr;

/**
 *  @discussion Scan for surrounding devices
 *  See delegate uteDiscoverDevices:
 */
- (void)startScanDevices;

/**
 *  @discussion Scan for surrounding devices(To upgrade firmware)
 *   See UTEOTADelegate(uteForceUpdate:)
 *
 *  @param macStr Same as UTEModelDevice.addressStr
 */
- (void)startScanDeviceForUpdate:(NSString *)macStr;

/**
 *  @discussion Stop scanning devices
 */
- (void)stopScanDevices;
/**
 *  @discussion Connect the device
 *
 *  @param model identifier cannot be nil
 *  Note:If you can’t connect to the device for a long time, please call disconnectDevices first, and then call connectDevice after 0.3 seconds. This may improve the chance of connection.
 */
- (void)connectDevice:(UTEModelDevice *)model;

/**
 *  @discussion Disconnect the device
 *
 *  @param model identifier cannot be nil
 *
 *  @return Whether this method is actually executed
 */
- (BOOL)disconnectDevices:(UTEModelDevice *)model;

/**
 *  @discussion Check which known devices are connected to the system.
 *
 *  Note:Currently Apple does not provide a method to query which devices and systems are paired
 *
 *  @param  UUID What services does the device have, can fill in one or more services. e.g. @[@"EFF5"]. or @[@"EFF5",@"12B5"].
 *  See mServicesConnectedUUID in UTEModelDevice.
 *  For the same series of devices, the mServicesConnectedUUID is fixed.
 *
 *  @return If there are no connected devices, 0 will be returned. If yes, then only attributes 'identifier' and 'name' in UTEModelDevice have values.
 */
- (NSArray<UTEModelDevice *> *)retrieveConnectedDeviceWithServers:(NSArray<NSString *> *)UUID;

/**
 *  @discussion Read the connected device signal value
 */
- (void)readDeviceRSSI:(void(^)(NSInteger rssi))result;
/**
 *  @discussion return e.g. @" 1.0.27"
 */
- (NSString *)sdkVersion;

#pragma mark - 触发bt连接
-(void)readBT;

///当账号不一致要断开连接
-(void)disconnectDevicesFromAccount;

- (void)onNotifySend:(void(^)(NSString *str))result;
- (void)onNotifyRecive:(void(^)(NSString *str))result;

///同步机制
- (void)syncOrder:(void(^)(BOOL ok))block;

#pragma mark - Tool
+ (NSData *)strToData:(NSString *)hexString;
+ (NSString *)dataToStr:(NSData *)data;

@end

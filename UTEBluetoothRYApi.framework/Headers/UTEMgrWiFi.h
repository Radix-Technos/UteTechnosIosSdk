//
//  UTEWiFiMgr.h
//  UTEBluetoothRYApi
//
//  Created by V V on 2025/6/6.
//  Copyright © 2025 vv. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UTEDeviceError.h"

/*!
 *  @enum UTEWiFiStatus
 */
typedef NS_ENUM(NSInteger, UTEWiFiStatus) {
    UTEWiFiStatusClose,
    UTEWiFiStatusOpen,
    UTEWiFiStatusErr,
};

@interface UTEModelWiFi : NSObject
@property(nonatomic, strong) NSData             *address;
@property(nonatomic, copy  ) NSString           *addressStr;
@property(nonatomic, copy  ) NSString           *ssid;
@property(nonatomic, assign) UTEWiFiStatus      status;
@end

@interface UTEMgrWiFi : NSObject

- (void)setWifiEnable:(BOOL)on block:(void(^)(UTEDeviceErrorType errorCode))block;
//ssid:The maximum length must not exceed 50.
- (void)setWifiSSID:(NSString *)ssid block:(void(^)(UTEDeviceErrorType errorCode))block;
//pw:There must be no spaces. The characters are in the range of ASCII(0x21~0x7e)
- (void)setWifiPassword:(NSString *)pw block:(void(^)(UTEDeviceErrorType errorCode))block;

- (void)readWiFiStatus:(void(^)(UTEWiFiStatus status))block;
- (void)readWiFiMac:(void(^)(NSString *mac))block;
- (void)readWiFiSSID:(void(^)(NSString *ssid))block;
- (void)readWiFiInfo:(void(^)(UTEModelWiFi *info,UTEDeviceErrorType errorCode))block;

@end



//
//  UTEWiFiMgr.h
//  UTEBluetoothRYApi
//
//  Created by V V on 2025/6/6.
//  Copyright © 2025 vv. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UTEBluetoothEnum.h"

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

- (void)setWifiEnable:(BOOL)on
                block:(void(^)(BOOL enable, UTEDeviceError errorCode))block;

//ssid:The maximum length must not exceed 50.
- (void)setWifiSSID:(NSString *)ssid
              block:(void(^)(UTEDeviceError errorCode))block;

//pw:There must be no spaces. The characters are in the range of ASCII(0x21~0x7e)
- (void)setWifiPassword:(NSString *)pw
                  block:(void(^)(UTEDeviceError errorCode))block;

//The device acts as a hotspot.
- (void)setWifiSSID:(NSString *)ssid
                pwd:(NSString *)pwd
             enable:(BOOL)on
              block:(void(^)(UTEDeviceError errorCode))block;

//see onNotifyControlStatus:
//It is recommended not to modify parameters x,y,w,h, please enter 0.
- (void)enableVideoStreaming:(BOOL)enable
                      videoX:(NSInteger)x
                      videoY:(NSInteger)y
                      videoW:(NSInteger)w
                      videoH:(NSInteger)h
                       block:(void(^)(UTEDeviceError errorCode))block;
/*!
 *  The device connects to an external Wi‑Fi.
 *  ssid.length + pwd.lenght must be less than 60
 *  deviceIP4: Device Wi-Fi IP address e.g. 192.168.1.55
 */
- (void)connectWiFiSSID:(NSString *)ssid
                    pwd:(NSString *)pwd
                  block:(void(^)(UTEDeviceError errorCode,NSString *deviceIP4))block;

- (void)readWiFiStatus:(void(^)(UTEWiFiStatus status))block;
- (void)readWiFiMac:(void(^)(NSString *mac))block;
- (void)readWiFiSSID:(void(^)(NSString *ssid))block;
- (void)readWiFiInfo:(void(^)(UTEModelWiFi *info,UTEDeviceError errorCode))block;

@end



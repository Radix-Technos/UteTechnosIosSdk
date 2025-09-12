//
//  UTEBluetoothRYDelegate.h
//  UTEBluetoothRYApi
//
//  Created by VV on 23/03/07.
//  Copyright © 2023年 vv. All rights reserved.
//  

#import <UIKit/UIKit.h>
#import <UTEBluetoothRYApi/UTEModelDevice.h>


#pragma mark - UTEBluetoothDelegate

/*!
 *  UTEBluetoothDelegate
 */
@protocol UTEBluetoothDelegate;

@protocol UTEBluetoothDelegate <NSObject>

@optional

/**
 *  @discussion Bluetooth status
 *
 *  @param status See UTEBluetoothStatus
 */
- (void)uteBluetoothStatus:(UTEBluetoothStatus)status;

/**
 *  @discussion It is called once for each device found
 *
 *  @param model See UTEModelDevice
 */
- (void)uteDiscoverDevices:(UTEModelDevice *)model;

/**
 *  @discussion Status of  devices in real time
 *
 *  @param status See UTEDevicesStatus
 */
- (void)uteDevicesStatus:(UTEDevicesStatus)status error:(NSError *)error userInfo:(NSDictionary *)info;

/**
 *  @discussion System Bluetooth notification permissions (share system notification permission status, not pairing status bound by the device).
 */
- (void)uteANCSAuthorization:(BOOL)ancsAuthorized NS_AVAILABLE_IOS(13_0);

@end

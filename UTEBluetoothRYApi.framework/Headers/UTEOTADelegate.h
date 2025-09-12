//
//  UTEOTADelegate.h
//  UTEBluetoothRYApi
//
//  Created by V V on 2023/12/6.
//  Copyright © 2023 vv. All rights reserved.
//

#ifndef UTEOTADelegate_h
#define UTEOTADelegate_h

@class UTEModelBaseInfo;

@protocol UTEOTADelegate;

@protocol UTEOTADelegate <NSObject>

@required
/**
 *  @discussion Bluetooth status
 *   Device was not successfully upgraded before and must now be upgraded again
 *   Note: If force = YES, please invoke method ([UTEOTAMgr upgrade:callback:])
 */
- (void)uteForceUpdate:(BOOL)force model:(UTEModelBaseInfo *)model;

@end

#endif /* UTEOTADelegate_h */

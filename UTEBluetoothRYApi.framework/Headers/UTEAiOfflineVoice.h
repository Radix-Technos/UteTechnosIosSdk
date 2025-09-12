//
//  UTEAiOfflineVoice.h
//  UTEBluetoothRYApi
//
//  Created by V V on 2024/8/27.
//  Copyright © 2024 vv. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol UTEAiOfflineVoiceDelegate <NSObject>

- (void)uteOVReceiveData:(NSData *)data;

@end


@interface UTEAiOfflineVoice : NSObject

@property (nonatomic, weak) id<UTEAiOfflineVoiceDelegate> delegate;

+ (instancetype) sharedInstance;

- (void)initWithDict:(NSDictionary *)dict;
- (void)sendValue:(NSData *)data;

@end


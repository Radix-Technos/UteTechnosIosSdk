//
//  EncryptTool.h
//  DayDayBand
//
//  Created by VV on 2017/6/21.
//  Copyright © 2017年 vv. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RYUTEEncryptTool : NSObject

/** 转化成服务器规定的sig */
+ (NSString *)getSig:(NSMutableDictionary *)dict;
/** 公钥加密 */
+ (NSString *)encryptStr:(NSString *)json lenght:(NSInteger)signLenght rsa:(NSInteger)rsaFlag;
/** 公钥解密 */
+ (NSData *)dencryptStr:(NSString *)str rsa:(NSInteger)rsaFlag;

/** Log加密 */
+ (NSString *)EncryptString:(NSString *)sourceStr data:(NSData *)sourceData;
/** Log解密 */
+ (NSString *)DecryptStringToStr:(NSString *)secretStr;
/** Log解密 */
+ (NSData *)DecryptStringToData:(NSString *)secretStr;

@end

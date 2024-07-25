//
//  UTELogTool.h
//  UTESmartBandApi
//
//  Created by V V on 2021/4/19.
//  Copyright © 2021 vv. All rights reserved.
//

#import <Foundation/Foundation.h>

#define UTESDKLog(...) [[RYUTELogTool sharedInstance] logInfoStr:[NSString stringWithFormat:__VA_ARGS__]]
#define UTESDKLogErr(...) [[RYUTELogTool sharedInstance] logInfoStrErr:[NSString stringWithFormat:__VA_ARGS__]]

typedef NS_ENUM(NSInteger, UTELogType) {
    UTELogTypeNone,
    UTELogTypePrint,         //Print log
    UTELogTypeSave,          //Log will be saved in the path "Documents/UTELog" folder.
    UTELogTypePrintAndSave,  //Log will be printed and saved in the path "Documents/UTELog" folder.
                             //The format of the file name is yyyy-MM-dd, only the log of the last 7 days is saved, and one file per day.
};

@interface RYUTELogTool : NSObject

//Defualt is UTELogTypePrintAndSave
@property (nonatomic,assign) UTELogType            logType;

+ (instancetype) sharedInstance;
- (void)logInfoStr:(NSString*)logStr;
- (void)logInfoStrErr:(NSString*)logStr;
- (void)logInfoStr:(NSString*)logStr data:(NSData *)data flag:(NSString *)flag path:(NSString *)path;

@end


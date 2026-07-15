//
//  UTEServerDataTool.h
//  UTESmartBandApi
//
//  Created by V V on 2019/3/6.
//  Copyright © 2019 vv. All rights reserved.
//

#import <Foundation/Foundation.h>

@class RYUTEReceiveMPFCommon;
@class UTEModelWatchServer;
@class RYServerOTAModel;
@class UTEServerLanguagePostModel;
@class UTEModelServerLanguageFile;
@class UTEUploadStatusModel;
@class UTEServiceAGPSPostModel;
@class RYUTEOneBleDisplayInfoModel;
@class UTEServerAMAPPostModel;
@class UTEServerAMAPLicenseModel;


typedef enum : NSUInteger {
    VVDataTypeActivation            = 1 << 0,
//    VVDataTypeStep                = 1 << 0,
//    VVDataTypeSleep               = 1 << 1,
//    VVDataTypeHRM                 = 1 << 2,
//    VVDataTypeBlood               = 1 << 3,
//    VVDataTypeSportModelWalk      = 1 << 4,
//    VVDataTypeSportModelRun       = 1 << 5,
//    VVDataTypeSportModelBicycle   = 1 << 6,
//    VVDataTypeSportModelSwim      = 1 << 7,
//    VVDataTypeSportModelSkip      = 1 << 8,
//    VVDataTypeMapGPS              = 1 << 9,
//    VVDataTypeTableTennis         = 1 << 10,
//    VVDataTypeTennis              = 1 << 11,
//    VVDataTypeBadminton           = 1 << 12,
//    VVDataTypeHRMContinue         = 1 << 13,
//    VVDataTypeHRM24               = 1 << 14,
//    VVDataTypeBodyFat             = 1 << 15,
//    VVDataTypeECG                 = 1 << 16,
} VVDataType;


typedef enum : NSUInteger {
    VVMeanTypeGetLastUpdate,
    VVMeanTypeGetHistory,
    VVMeanTypeUploadData,
} VVMeanType;


@interface RYUTEServerDataTool : NSObject

@property (nonatomic,assign) BOOL                  debugDail;
@property (nonatomic,assign) BOOL                  sourceDebug;
@property (nonatomic,  copy) NSString              *region;

/** 对应的下载包 */
@property (nonatomic,strong) NSMutableArray<RYUTEOneBleDisplayInfoModel*>    *mArrayResource;

+ (RYUTEServerDataTool *)sharedInstance;
///统计接口
- (void)checkActivationDataSuccess:(void (^)(id))success failure:(void (^)(NSError *))failure;

- (void)getDeviceDisplayInfoAppkey:(NSString *)appkey
                       deviceModel:(UTEModelWatchServer *)deviceModel
                           address:(NSData *)address
                        screenType:(NSInteger)screenType
                          language:(NSString *)lang
                           byGroup:(BOOL)byGroup
                           groupID:(NSInteger)groupID
                          platform:(NSInteger)platform
                           success:(void (^)(id data,NSInteger count))success
                           failure:(void (^)(NSError *))failure;
- (void)getDeviceDisplayInfoAppkey:(NSString *)appkey
                       deviceModel:(UTEModelWatchServer *)deviceModel
                          arrayIDs:(NSArray *)IDs
                           success:(void (^)(NSArray<NSString *> *))success
                           failure:(void (^)(NSError *))failure;

- (void)getDeviceDialZipUrlAppkey:(NSString *)appkey
                        deviceVer:(NSString *)ver
                             type:(NSInteger)type
                           height:(NSInteger)height
                            width:(NSInteger)width
                         platform:(NSInteger)platform
                          success:(void (^)(id))success
                          failure:(void (^)(NSError *))failure;

- (void)getUTEDisplayModelFormServer:(NSString *)url
                             success:(void (^)(NSData *))success
                             failure:(void (^)(NSError *))failure;

- (void)getUTEWeatherDataFormServer:(NSString *)sdkkey
                             cityID:(NSString *)cityID
                           latitude:(double)latitude
                          longitude:(double)longitude
                            success:(void (^)(id data))success
                            failure:(void (^)(NSError *  error))failure;

- (void)getMDFDataFormServer:(NSData *)data
                         mac:(NSString *)mac
                   startTime:(NSDate *)startTime
                     endTime:(NSDate *)endTime
                     sensorType:(NSString *)sensorType
                     success:(void (^)(RYUTEReceiveMPFCommon *data))success
                     failure:(void (^)(NSError * error))failure;

- (void)activateMPF:(NSData *)dataMPF success:(void (^)(id data))success failure:(void (^)(NSError *  error))failure;
- (void)getServerFirmware:(NSString *)url data:(NSData *)data success:(void (^)(RYServerOTAModel *updateModel))success failure:(void (^)(NSError *  error))failure;

- (void)getServerLanguageFile:(UTEServerLanguagePostModel *)model
                        block:(void(^)(NSArray<UTEModelServerLanguageFile *> *array ,NSError *error))block;

- (void)uploadbtupdatestatus:(UTEUploadStatusModel *)model;

///获取服务器APGS文件信息
- (void)getServerAGPSFile:(UTEServiceAGPSPostModel *)model success:(void (^)(id data))success failure:(void (^)(NSError *  error))failure;

///高德授权
- (void)getServerAMAPLicense:(UTEServerAMAPLicenseModel *)model success:(void (^)(id data))success failure:(void (^)(NSError *  error))failure;

///获取服务器高德地图文件信息
- (void)getServerAMAP:(UTEServerAMAPPostModel *)model success:(void (^)(id data))success failure:(void (^)(NSError *  error))failure;

@end

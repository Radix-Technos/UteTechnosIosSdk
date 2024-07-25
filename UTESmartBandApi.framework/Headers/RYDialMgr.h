//
//  RYDialMgr.h
//  UTESmartBandApi
//
//  Created by V V on 2023/11/4.
//  Copyright © 2023 vv. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UTEModel.h"

@interface RYDialMgr : NSObject

+ (instancetype) sharedInstance;

/**
 *  @discussion Read device dial parameters
 */
- (void)getWatchFaceParams:(void(^)(UTEModelRYDialParams *model,
                                    UTEErrorCode errorCode ,
                                    NSDictionary *uteDict))block;
/**
 *  @discussion Read the dial list in the device
 *  @param serverMode Temporarily invalid
 */
- (void)getWatchFaceInfo:(NSInteger)serverMode block:(void(^)(NSArray<UTEModelRYDial *> *model,
                                                              UTEErrorCode errorCode,
                                                              NSDictionary *uteDict))block;
/**
 *  @discussion Operation dial
 *  @param ID Dial ID from UTEModelRYDial.ID  See (getWatchFaceInfo:block)
 *  @param version Dial ID from UTEModelRYDial.version  See (getWatchFaceInfo:block)
 *  @param operate See UTERYDialOperate
 */
- (void)applyWatchFace:(NSInteger)ID
               version:(NSString *)version
               operate:(UTERYDialOperate)operate
                 block:(void(^)(UTEModelRYDial *model,
                                UTEErrorCode errorCode,
                                NSDictionary *uteDict))block;

/**
 *  @discussion Read  dial image information
 *  Callback Dict
 */
- (void)getImageWatchFaceBlock:(void(^)(UTEErrorCode errorCode,
                                        NSDictionary *uteDict))block;
/**
 *  @discussion Read  dial image information
 *  Callback Model
 */
- (void)getImageWatchFaceModelBlock:(void(^)(UTEModelRYDialImage *model,
                                             UTEErrorCode errorCode,
                                             NSDictionary *uteDict))block;
/**
 *  @discussion Set  dial image information
 *  Parameter Dict
 */
- (void)setImageWatchFace:(NSDictionary *)dict
                    block:(void(^)(UTEErrorCode errorCode,
                                   NSDictionary *uteDict))block;
/**
 *  @discussion Set  dial image information
 *  Parameter Model
 *  Note:
 *  1.The length of the image name must be less than or equal to 20 in English or in numbers
 *  2.The image name must be unique
 */
- (void)setImageWatchFaceModel:(UTEModelRYDialImage *)model
                         block:(void(^)(UTEModelRYDialImage *model,
                                        UTEErrorCode errorCode,
                                        NSDictionary *uteDict))block;
/**
 *  @discussion Notify status of (Set  dial image)
 *  When invoke method(setImageWatchFace/setImageWatchFaceModel), if the device does not have UTEModelRYDialImage.index for this image, the method will call back the index, indicating that the App needs to send the image to the device first
 *
 *  See uploadImageWatchFace:block (Send the image to the device)
 *
 * param uteDict e.g.
 * NSDictionary *uteDict = @{
    @"msgId":@10241,
    @"data":@{
     @"index":@1,
     @"name":@"imageImage"
     @"type":@(3)
     
 },
}
 */
- (void)onNotifyImageWatchFace:(void(^)(NSInteger index,
                                        NSDictionary *uteDict))block;

/**
 *  @discussion Send online dial to device
 *  Parameter dict =  @{@"XXX/XXX/XXX.bin" : path};
 */
- (void)uploadWatchFace:(NSDictionary *)dict
                  block:(void(^)(CGFloat process,
                                 BOOL isSuccess,
                                 UTEErrorCode errorCode))block;
/**
 *  @discussion Reading dial images from the device
 *  @param file Path for saving images
 *  @param imageName The name of the image
 */
- (void)downloadImageWatchFace:(NSString *)file
                     imageName:(NSString *)imageName
                         block:(void(^)(CGFloat process,
                                        BOOL isSuccess,
                                        UTEErrorCode errorCode,
                                        NSString *filePath,
                                        NSString *imageName))block;
/**
 *  @discussion Send image to device
 *  fileName comes from  method (setImageWatchFaceModel:block)
 *
 *  NSDictionary *dictPath = @{@"fileName": name ,@"filePath":filePath};
 *  NSArray *list = @[dictPath];
 */
- (void)uploadImageWatchFace:(NSArray *)list
                       block:(void(^)(CGFloat process,
                                      BOOL isSuccess,
                                      UTEErrorCode errorCode))block;

@end



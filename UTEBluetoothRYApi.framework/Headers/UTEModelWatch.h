//
//  UTEModelWatch.h
//  UTEBluetoothRYApi
//
//  Created by V V on 2024/1/23.
//  Copyright © 2024 vv. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UTEBluetoothEnum.h"


typedef NS_ENUM(NSInteger, UTEWatchFaceTimePosition) {
    UTEWatchFaceTimePositionUp           = 0x01,
    UTEWatchFaceTimePositionDown         = 0x02,
    UTEWatchFaceTimePositionLeft         = 0x03,
    UTEWatchFaceTimePositionRight        = 0x04,
};

typedef NS_ENUM(NSInteger, UTEWatchFaceType) {
    ///当前表盘 Current dial
    UTEWatchFaceTypeCurrent         = 0x01,
    ///预置表盘 Pre set dial
    UTEWatchFaceTypePreset          = 0x02,
    ///支持删除 Support deletion
    UTEWatchFaceTypeDelete          = 0x04,
    ///支持自定义 Support customization
    UTEWatchFaceTypeCustom          = 0x08,
    ///Google预置 Google presets
    UTEWatchFaceTypeGooglePre       = 0x10,
    ///相片表盘 Photo dial
    UTEWatchFaceTypePhoto           = 0x20,
    ///息屏表盘
    UTEWatchFaceTypeAOD             = 0x40,
};

typedef NS_ENUM(NSInteger, UTEWatchFaceType1) {
    
    UTEWatchFaceType1Current           = 1 << 0,
    UTEWatchFaceType1Preset            = 1 << 1,
    UTEWatchFaceType1Delete            = 1 << 2,
    UTEWatchFaceType1Custom            = 1 << 3,
    UTEWatchFaceType1GooglePre         = 1 << 4,
    UTEWatchFaceType1Photo             = 1 << 5,
    UTEWatchFaceType1AOD               = 1 << 6,

};

typedef NS_ENUM(NSInteger, UTEWatchFaceTypeJLOperate) {
    ///无操作 no-operation
    UTEWatchFaceTypeJLOperateNone,
    ///增加新的表盘 Add a new dial
    UTEWatchFaceTypeJLOperateAdd,
    ///删除表盘 Delete dial
    UTEWatchFaceTypeJLOperateDelete,
    ///设置当前表盘(手表已经存在的表盘) Set the current dial (a dial that already exists on the watch)
    UTEWatchFaceTypeJLOperateSet,
};

typedef NS_ENUM(NSInteger, UTEWatchFaceTypeJLCategory) {
    ///在线表盘 Online dial
    UTEWatchFaceTypeJLCategoryOnline,
    ///自定义表盘（更换背景图片） Custom dial (replace background image)
    UTEWatchFaceTypeJLCategoryCustom,
};

@interface UTEModelWatch : NSObject
@end


@interface UTEModelWatchFaceParams : NSObject
///设备支持的最大表盘版本 The maximum dial version supported by the device
@property (nonatomic,copy  ) NSString               *maxWatchFaceVersion;
///屏幕宽度—横向长度 Screen width - horizontal length
@property (nonatomic,assign) NSInteger              width;
///屏幕高度—纵向长度 Screen height - vertical length
@property (nonatomic,assign) NSInteger              height;
///设备支持的主题包文件类型 0为bin文件 The theme pack file type 0 supported by the device is a bin file
@property (nonatomic,assign) NSInteger              supportFileType;
///设备是否支持表盘排序 YES：支持，NO:不支持 Does the device support dial sorting? Yes: Yes, NO: No
@property (nonatomic,assign) BOOL                   isSupportSort;
///设备支持的向下兼容的表盘版本，若支持多个则以逗号隔开 The downward compatible dial versions supported by the device, if multiple are supported, separated by commas
@property (nonatomic,copy  ) NSString               *earlyWatchFaceVersion;
///获取屏幕类型 0:圆屏，1:方屏 Get screen types 0: round screen, 1: square screen
@property (nonatomic,assign) UTEDeviceDialType      shape;
///方屏圆角值 Square screen corner value
@property (nonatomic,assign) NSInteger              cornerRadius;
///支持表盘文件最大大小 Support maximum size of dial file
@property (nonatomic,assign) NSInteger              maxCapacity;
///设备支持最大的在线表盘个数 Support the number of online dials supported by the device
@property (nonatomic,assign) NSInteger              maxCountOnline;
///设备支持最大的息屏表盘个数 Support the number of offline dials supported by the device
@property (nonatomic,assign) NSInteger              maxCountOffline;
@end

@interface UTEModelWatchFace : NSObject
///表盘文件ID Dial file ID
@property (nonatomic,copy  ) NSString               *ID;
///表盘文件版本号，三段式（1.0.0） Version number of dial file, three segment 1.0.0
@property (nonatomic,copy  ) NSString               *version;
///表盘类型 Dial type
@property (nonatomic,assign) UTEWatchFaceType       type;
/**表盘类型也可以用以下判断*/
///当前表盘 Current dial
@property(nonatomic,assign) BOOL                hasCurrent;
///预置表盘 Pre set dial
@property(nonatomic,assign) BOOL                hasPreset;
///支持删除 Support deletion
@property(nonatomic,assign) BOOL                hasDelete;
///支持自定义 Support customization
@property(nonatomic,assign) BOOL                hasCustom;
///Google预置 Google presets
@property(nonatomic,assign) BOOL                hasGooglePre;
///相片表盘 Photo dial
@property(nonatomic,assign) BOOL                hasPhoto;
///息屏表盘 Breath screen dial
@property(nonatomic,assign) BOOL                hasAOD;

///1：应用表盘，2：删除表盘，3: 应用 Google 预置表盘 1: Application dial, 2: Delete dial, 3: Apply Google preset dial
@property (nonatomic,assign) NSInteger              operate;
///是否需要传输表盘，0：不需要，1：需要（默认） Do you need to transfer the dial? 0: Not required, 1: Required (default)
@property (nonatomic,assign) NSInteger              needReceiveFile;
//Required: UTEModelDevice.platform = UTEDevicePlatformTypeAC7012x
@property (nonatomic,copy  ) NSString               *uuid;
@end

@interface UTEModelWatchFaceNotify : NSObject

@property (nonatomic,copy  ) NSString               *watchFaceId;
@property (nonatomic,copy  ) NSString               *watchFaceVersion;
///1:表盘已变更为当前表盘 2:表盘文件已传输成功 3:在设备上删除表盘 4:相片表盘资源包已接受 1: The dial has been changed to the current dial. 2. The dial file has been successfully transferred. 3. The dial was deleted on the device. 4. The photo dial resource package has been accepted
@property (nonatomic,assign) NSInteger              operate;
@end

@interface UTEModelWatchFaceImageInfo : NSObject
///相片背景的图片索引 Image index for photo background
@property (nonatomic,assign) NSInteger              index;
///相片背景的图片名称 The image name of the photo background
@property (nonatomic,copy  ) NSString               *name;
@end

@interface UTEModelWatchFaceImage : NSObject
///相片表盘支持显示的最大背景图片个数 The maximum number of background images supported by the photo dial
@property (nonatomic,assign) NSInteger              maxCount;
///设备是否支持智能取色 Does the device support intelligent color selection
@property (nonatomic,assign) BOOL                   isSupportIntellectColor;
///设备支持的相片背景的格式，1：png，2：压缩后的 bitmap The format of the photo background supported by the device, 1: png, 2: compressed bitmap
@property (nonatomic,assign) NSInteger              imageType;
///位置可选项当前索引 1上居中 2下居中 3中居中 Location options: Currently, index 1 is centered on top, 2 is centered on bottom, and 3 is centered on center
@property (nonatomic,assign) NSInteger              positionIndex;
///样式可选项当前索引 样式1 样式2 样式3 。。。。 Style options: Current index style 1, style 2, style 3....
@property (nonatomic,assign) NSInteger              styleIndex;
///相片表盘背景列表 Photo dial background list
@property (nonatomic,strong) NSMutableArray<UTEModelWatchFaceImageInfo *>         *imageInfoList;
///设备需要获取的图片个数 The number of images that the device needs to obtain
@property (nonatomic,assign) NSInteger              imageCount;
///暂定，获取到下发时候在发回给手环 Temporarily, when receiving the distribution, send it back to the bracelet
@property (nonatomic,assign) NSInteger              transferNum;

//相片表盘 时间 颜色RGB,如为NO, 则表示此参数无效 或 不设置
@property (nonatomic,assign) NSInteger              timeRGB_enable;
///相片表盘 时间 颜色RGB : red,
@property (nonatomic,assign) NSInteger              timeRGB_R;
///相片表盘 时间 颜色RGB : green
@property (nonatomic,assign) NSInteger              timeRGB_G;
///相片表盘 时间 颜色RGB : blue,
@property (nonatomic,assign) NSInteger              timeRGB_B;

//相片表盘 日期 颜色RGB,如为NO, 则表示此参数无效 或 不设置
@property (nonatomic,assign) NSInteger              dateRGB_enable;
///相片表盘 日期 颜色RGB : red
@property (nonatomic,assign) NSInteger              dateRGB_R;
///相片表盘 日期 颜色RGB : green
@property (nonatomic,assign) NSInteger              dateRGB_G;
///相片表盘 日期 颜色RGB : blue,
@property (nonatomic,assign) NSInteger              dateRGB_B;

@end

@interface UTEModelWatchFaceJL : NSObject
//在线表盘的文件,当 操作 为 UTEWatchFaceTypeJLOperateAdd 的时候才需要赋值
@property(nonatomic, copy  ) NSString                               *filePathOnline;
//自定义的背景图片,当 操作 为 UTEWatchFaceTypeJLOperateAdd 的时候才需要赋值
@property(nonatomic, strong) UIImage                                *backgroundImg;
//表盘的索引，从1开始，最大不能超过 UTEModelWatchFaceImage.maxCount(可从 getImageWatchFaceModelBlock：方法读取到最大值)
//相同的索引会替换掉原来的内容（在线表盘或自定义背景表盘）
@property (nonatomic,assign) NSInteger                              index;
//操作的方式
@property (nonatomic,assign) UTEWatchFaceTypeJLOperate              operate;
//类型
@property (nonatomic,assign) UTEWatchFaceTypeJLCategory             category;
@end



@interface UTEModelWatchServer : NSObject

//See UTEModelDevice.versionName ([UTEBluetoothMgr sharedInstance].connnectModel.versionName)
@property (nonatomic,copy  ) NSString               *versionName;
//See UTEModelDevice.address
@property (nonatomic,strong) NSData                 *address;

//See method getWatchFaceParams:
//See UTEModelWatchFaceParams.height
@property (nonatomic,assign) NSInteger              height;
//See UTEModelWatchFaceParams.width
@property (nonatomic,assign) NSInteger              width;
//See UTEModelWatchFaceParams.maxCapacity
@property (nonatomic,assign) NSInteger              maxCapacity;
//See UTEModelWatchFaceParams.shape
@property (nonatomic,assign) UTEDeviceDialType      shape;
//See UTEModelWatchFaceParams.cornerRadius
@property (nonatomic,assign) NSInteger              cornerRadius;

//Optional Download from that watch index. Default is 0.
@property (nonatomic,assign) NSInteger              startIndex;
//Optional Download To that watch index. Default is 29(startIndex+29).
@property (nonatomic,assign) NSInteger              endIndex;
//Optional From which group
@property (nonatomic,assign) NSInteger              groupID;
//Optional From group
@property (nonatomic,assign) BOOL                   isGroup;
//Optional Normal or Off Screen Display
@property (nonatomic,assign) BOOL                   isOffScreen;


/**
 * The following parameters are the data returned by the server
 */
//Server Watch ID. When ID = -1, it means there is no watch in the device to replace
//Unique Number
@property (nonatomic,assign) NSInteger               ID;
//Watch title
@property (nonatomic,copy  ) NSString                *title;
//Brief description
@property (nonatomic,copy  ) NSString                *des;
//Preview image link
@property (nonatomic,strong) NSArray                 *previewURLs;
//Firmware(such as 'bin file') download link
@property (nonatomic,copy  ) NSString                *firmwareURL;
//Firmware size
@property (nonatomic,assign) NSInteger               firmwareSize;
//How many times has it been downloaded
@property (nonatomic,assign) NSInteger               dowloadCount;
//See UTEDeviceDialType
@property (nonatomic,assign) UTEDeviceDialType       type;
//How many Dials are there on the server. If 'startIndex' is greater than 'amount', then it is 0.
@property (nonatomic,assign) NSUInteger              amount;
//See UTEDeviceDisplayMode
@property (nonatomic,assign) UTEDisplayMode          displayMode;


@end


@interface UTEModelCustomWatchServer : NSObject

//Server Watch ID
@property (nonatomic,assign) NSInteger               ID;
//zip link e.g @"https://aaaaa.zip" or @"https://aaaaa.bin" or @"https://aaaaa.ufw"
@property (nonatomic,copy  ) NSString                *firmwareURL;
//Preview Picture Url (It may be nil)
@property (nonatomic,assign) NSString                *previewBgUrl;
/**
    Time display position
    If the value is 0, the position change is not supported
*/
@property (nonatomic,assign) UTEWatchFaceTimePosition  timePosition;

//Preview Time Postion Url (It may be nil)
@property (nonatomic,copy  ) NSString                *previewTimeUp;
@property (nonatomic,copy  ) NSString                *previewTimeDown;
@property (nonatomic,copy  ) NSString                *previewTimeLeft;
@property (nonatomic,copy  ) NSString                *previewTimeRight;


@end


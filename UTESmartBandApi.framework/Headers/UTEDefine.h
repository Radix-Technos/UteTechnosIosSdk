//
//  UTEDefine.h
//  UTESmartBandApi
//
//  Created by VV on 2017/4/22.
//  Copyright © 2017年 vv. All rights reserved.
//
//  Enumerations and key values

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface UTEDefine : NSObject
/*!
 *  Step
 *
 *  @discussion NSDictionary value:NSArray.
 *              Data synchronization completed.
 */
extern NSString *const kUTEQueryRunData;
/*!
 *  Step
 *
 *  @discussion NSDictionary value:NSArray
 *              Data synchronization completed.
 *              Required parameter isHasSleepSporadic = YES.
 */
extern NSString *const kUTEQueryHourStepData;
/*!
 *  Sleep
 *
 *  @discussion NSDictionary value:NSArray.
 *              Data synchronization completed. All sleep is collected in an array.
 */
extern NSString *const kUTEQuerySleepData;
/*!
 *  Sleep
 *
 *  @discussion NSDictionary value:NSArray.
 *              Data synchronization completed. Sorted out separate sleep data day by day.
 */
extern NSString *const kUTEQuerySleepDataDayByDay;
/*!
 *  Nap
 *
 *  @discussion NSDictionary value:NSArray.
 *              Data synchronization completed.
 */
extern NSString *const kUTEQuerySiestaData;
/*!
 *  Sleep Sporadic
 *
 *  @discussion NSDictionary value:NSArray.
 *              Data synchronization completed.
 *              Required parameter isHasSleepSporadic = YES.
 */
extern NSString *const kUTEQuerySleepSporadicData;
/*!
 *  Heart Rate
 *
 *  @discussion NSDictionary value:NSArray or UTEModelHRMData
 *              Data synchronization completed OR Test heart rate completed.
 */
extern NSString *const kUTEQueryHRMData;
/*!
 *  Heart Rate Source Data
 *
 *  @discussion NSDictionary value:NSArray (NSData,NSData...)
 *              Data synchronization completed OR Test heart rate completed.
 */
extern NSString *const kUTEQueryHRMDataSource;
/*!
 *  24-Hour Heart Rate
 *
 *  @discussion NSDictionary value:NSArray.
 *              Synchronized 24-hour heart rate data completed.
 *              Required isHas24HourHRM = YES.
 */
extern NSString *const kUTEQuery24HRMData;
/*!
 *  Blood Pressure
 *
 *  @discussion NSDictionary value:NSArray. or UTEModelBloodData
 *              Data synchronization completed OR Test blood pressure completed.
 */
extern NSString *const kUTEQueryBloodData;
/*!
 *  Blood Pressure Chip History Data
 *
 *  @discussion NSArray value: UTEModelBloodChipHistory
 *              Data synchronization completed.
 */
extern NSString *const kUTEQueryBloodChipHistoryData;
/*!
 *  Blood Oxygen
 *
 *  @discussion NSDictionary value:NSArray. or UTEModelBloodOxygenData
 *              Data synchronization completed OR Test blood oxygen.
 */
extern NSString *const kUTEQueryBloodOxygenData;
/*!
 *  Device password status
 *
 *  @discussion NSDictionary value:NSString (Converted to NSInteger, corresponding to UTEPasswordState).
 */
extern NSString *const kUTEPasswordState;
/*!
 *  Walking and running
 *
 *  @discussion NSDictionary value:UTEModelSportWalkRun. or NSArray
 *              Required parameter isHasWalkRun = YES.
 */
extern NSString *const kUTEQuerySportWalkRunData;
/*!
 *  Bicycle
 *
 *  @discussion NSDictionary value:UTEModelDeviceBicycle.
 *              Required parameter isHasBicycle = YES.
 */
extern NSString *const kUTEQuerySportBicycleData;
/*!
 *  Swim
 *
 *  @discussion NSDictionary value:UTEModelSportSwim.
 *              Required parameter isHasSwim = YES.
 */
extern NSString *const kUTEQuerySportSwimData;
/*!
 *  Rope Skipping
 *
 *  @discussion NSDictionary value:UTEModelSportSkip.
 *              Required parameter isHasSkip = YES.
 */
extern NSString *const kUTEQuerySportSkipData;
/*!
 *  TableTennis
 *
 *  @discussion NSDictionary value:UTEModelDeviceTableTennis.
 *              Required parameter isHasTableTennis = YES.
 */
extern NSString *const kUTEQuerySportTableTennisData;
/*!
 *  Badminton
 *
 *  @discussion NSDictionary value:UTEModelDeviceBadminton.
 *              Required parameter isHasBadminton = YES.
 */
extern NSString *const kUTEQuerySportBadmindonData;
/*!
 *  Tennis
 *
 *  @discussion NSDictionary value:UTEModelDeviceTableTennis.
 *              Required parameter isHasTennis = YES.
 */
extern NSString *const kUTEQuerySportTennisData;
/*!
 *  UV
 *
 *  @discussion NSDictionary value:NSNumber.
 */
extern NSString *const kUTEQueryUVData;
/*!
 *  GPS
 *
 *  @discussion NSDictionary value:NSArray.
 *              Data synchronization completed.
 */
extern NSString *const kUTEQueryGPSData;
/*!
 *  New firmware version available
 *
 *  @discussion NSDictionary value:NSNumber(numberWithBool).
 *              if NSNumber is YES,Indicates that the device must be upgraded.Because the device has a serious bug.
 */
extern NSString *const kUTEForceUpdateFirmware;
/*!
 *  New firmware information
 *
 *  @discussion NSDictionary value:UTEModelFirmwareInfo.
 */
extern NSString *const kUTEUpdateFirmwareInfo;
/*!
 *  New firmware information
 *
 *  @discussion value:@[UTEModelFirmwareInfo,UTEModelFirmwareInfo, ...]
 *  Required isFRQDevices = YES,
 */
extern NSString *const kUTEUpdateFirmwareFRQ;

/*!
 *  Barometric pressure
 *
 *  @discussion NSDictionary value:NSArray.
 */
extern NSString *const kUTEQueryBarometricData;
/*!
 *  BodyFat
 *
 *  @discussion NSDictionary value:NSArray. or UTEModelDeviceBodyFat
 */
extern NSString *const kUTEQueryBodyFatData;
/*!
 *  ECG
 *
 *  @discussion value:NSArray During the test.
 *              value:UTEModelDeviceECG  During the test have Heart rate value.
 *              value:UTEModelDeviceECG  Test completed.
 *
 *              value:@[model,model,model...]  synchronization completed.
 *              And the last model is the analysis result, if last model.valid=NO, Please don't save data.
 *
 */
extern NSString *const kUTEQueryECGData;
/*!
 *  ECG sampling data
 *
 *  @discussion value: @[  @[model,model...] , @[model,model...]  .... ] synchronization completed.
 *
 */
extern NSString *const kUTEQueryECGSamplingData;
/*!
 *  Exercise with heart rate recording
 *
 *  @discussion NSDictionary value:UTEModelSportHRMData. or NSArray
 *              Required parameter isHasSportHRM = YES.
 */
extern NSString *const kUTEQuerySportHRMData;
/*!
 *  Headset
 *
 *  @discussion NSDictionary value:UTEModelSportHeadsetData.
 *              Required parameter isHasHeadsetHRM = YES.
 */
extern NSString *const kUTEQuerySportHeadsetData;
/*!
 *  Headset click event
 *
 *  @discussion NSDictionary value:UTEModelSportHeadsetData.
 *              Required parameter isHasHeadsetHRM = YES.
 */
extern NSString *const kUTEQuerySportHeadsetDataOnClick;
/*!
 *  Body Temperature
 *
 *  @discussion NSDictionary value:NSArray or UTEModelBodyTemperature
 *              Required parameter isHasBodyTemperature = YES.
 */
extern NSString *const kUTEQueryBodyTemperature;
/*!
 *  Respiration Rate
 *
 *  @discussion NSDictionary value:NSArray. or UTEModelRespirationData
 *              Data synchronization completed OR Test respiration.
 */
extern NSString *const kUTEQueryRespirationData;
/*!
 *  Daily history of UTEGoalType
 *
 *  @discussion NSDictionary value:NSArray
 */
extern NSString *const kUTEQueryGoalHistory;
/*!
 *  Mood, Pressure and Fatigue
 *
 *  @discussion NSDictionary value:NSArray or UTEModelMPFInfo
 *              Required parameter isHasMPF = YES.
 */
extern NSString *const kUTEQueryMPF;
/*!
 *  Get the error provided by the mobile phone system, not the error defined by the SDK.
 *  @discussion NSDictionary value:NSError.
 */
extern NSString *const kSystemError;
/*!
 *  A common key
 *  NSDictionary value:id
 */
extern NSString *const kUTECommonData;
/*!
 *  History of Sport Activity
 *
 *  @discussion NSDictionary value:NSArray
 */
extern NSString *const kUTEQuerySportTimeHistory;
/*!
 *  Resting Heart Rate
 *
 *  @discussion NSDictionary value:NSArray
 */
extern NSString *const kUTEQueryRHR;
/*!
 *  Blood PPG
 *
 *  @discussion value:NSArray During the test.
 *
 */
extern NSString *const kUTEQueryBloodPPGProcessData;
/*!
 *  Blood PPG
 *
 *  @discussion value:NSArray During the test.
 *
 */
extern NSString *const kUTEQueryBloodPPGMiddleData;
/*!
 *  Blood PPG
 *
 *  @discussion value:NSArray During the test.
 *
 */
extern NSString *const kUTEQueryBloodPPGHistory;
/*!
 *  Blood Glucose PPG
 *
 *  @discussion value:Data During the test.
 *  Required parameter isHasBloodHengAi = YES.
 *
 */
extern NSString *const kUTEQueryBloodGlucosePPGProcess;
/*!
 *  HRV PPG
 *
 *  @discussion value:Data During the test.
 *  Required parameter isHasBloodHengAi = YES.
 *
 */
extern NSString *const kUTEQueryHRVPPGProcess;
/*!
 *  Blood Glucose
 *
 *  @discussion NSDictionary value:NSArray or UTEModelBloodGlucose
 */
extern NSString *const kUTEQueryBloodGlucose;
/*!
 *  HRV
 */
extern NSString *const kUTEQueryHRV;


/*!
 *  @enum UTEOption
 *
 *  @discussion Set device information
 *
 */
typedef NS_ENUM(NSInteger, UTEOption) {
    
    UTEOptionSyncAllStepsData       = 0, //If isHasDataStatus=YES ,please invoke syncDataCustomTime:type:
    UTEOptionSyncAllSleepData       = 1, //If isHasDataStatus=YES ,please invoke syncDataCustomTime:type:
    UTEOptionSyncAllHRMData         = 2, //If isHasDataStatus=YES ,please invoke syncDataCustomTime:type:
    UTEOptionSyncAllBloodData       = 3, //If isHasDataStatus=YES ,please invoke syncDataCustomTime:type:
    UTEOptionSyncAllBloodOxygenData = 4,
    UTEOptionSyncAllRespirationData = 5, // Unspport syncDataCustomTime:type:
    
    UTEOptionSyncBicycleData        = 6, //If isHasDataStatus=YES ,please invoke syncDataCustomTime:type:
    //If isHasSportHRM=YES ,please invoke syncUTESportModelCustomTime:
    
    UTEOptionSyncBarometricData     = 7,
    UTEOptionSyncBodyFat            = 8, //If isHasDataStatus=YES ,please invoke syncDataCustomTime:type:
    UTEOptionSyncECG                = 9, //The device saves offline test data
    
    UTEOptionIncall                 = 10, //Incoming call command: When the mobile phone calls, when this value is called,the device will vibrate 10 times, once every 1 second.If isHasSocialNotification = Yes OR isHasSocialNotification2 = Yes , please invoke setUTERemindApp: ,do not use setUTEOption:
    
    UTEOptionHangup                 = 11, //Hang up the phone OR Connect the call: invoke this value, the device will immediately stop shaking
    UTEOptionFindBand               = 12,
    UTEOptionSyncTime               = 13, //Keep the phone time the same as device time
    UTEOptionReadDevicesBattery     = 14,
    UTEOptionDeleteGPSData          = 15, //Delete GPS data saved by the device.
    //It is recommended to invoke this value after the GPS data is synchronized.Otherwise, too much GPS data will cause the device's GPS data to synchronize slowly.
    
    UTEOptionHeartDetectingStart    = 16,
    UTEOptionHeartDetectingStop     = 17,
    
    //See UTEModelDevices.isSwitchHeart and UTEModelDevices.isHasHRMautoSwitch, Decide whether these two enumerations are valid.
    UTEOptionHeartSwitchDynamic     = 18, //Heart rate dynamic mode.When testing heart rate, the device does not stop testing automatically
    UTEOptionHeartSwitchStatic      = 19, //Heart rate static mode.When testing heart rate,the device automatically stops when it detects a heart rate value
    
    UTEOptionOpen24HourHRM          = 20, //Required isHas24HourHRM = YES.Turn on device heart rate test(Heart rate monitoring throughout the day, one data every 10 minutes).
    UTEOptionClose24HourHRM         = 21, //Required isHas24HourHRM = YES.
    
    UTEOptionUnitInch               = 22, //Units are imperial and pound(lbs)  (Compatible with older devices,no longer used)
    UTEOptionUnitMeter              = 23, //Units are metric and kilogram      (Compatible with older devices,no longer used)
    
    UTEOptionUnitInch_12            = 24, //Units are imperial and pound(lbs)、12-hour time(AM,PM)
    UTEOptionUnitInch_24            = 25, //Units are imperial and pound(lbs)、24-hour time
    UTEOptionUnitMeter_12           = 26, //Units are metric and kilogram 、12-hour time(AM,PM)
    UTEOptionUnitMeter_24           = 27, //Units are metric and kilogram 、24-hour time
    
    
    //If isHasSocialNotification = Yes OR isHasSocialNotification2 = Yes OR isHasIconANCS = Yes
    //please invoke setUTERemindApp:  Do not use setUTEOption: (This method is invalid)
    UTEOptionOpenRemindIncall       = 28,
    UTEOptionOpenRemindQQ           = 29,
    UTEOptionOpenRemindWeixin       = 30,
    UTEOptionOpenRemindSms          = 31,
    UTEOptionOpenRemindMore         = 32,
    UTEOptionCloseRemindIncall      = 33,
    UTEOptionCloseRemindQQ          = 34,
    UTEOptionCloseRemindWeixin      = 35,
    UTEOptionCloseRemindSms         = 36,
    UTEOptionCloseRemindMore        = 37,
    
    
    UTEOptionOpenCameraMode         = 38,
    UTEOptionCloseCameraMode        = 39,
    
    UTEOptionDeleteDevicesAllData   = 40, //Delete all data from the device(Reset everything on the device)
    
    UTEOptionDeviceHorizontal       = 41, //Set the device display orientation to landscape
    UTEOptionDeviceVertical         = 42, //Set device display orientation to portrait
    
    UTEOptionBloodDetectingStart    = 43,
    UTEOptionBloodDetectingStop     = 44,
    
    UTEOptionBloodOxygenDetectingStart  = 45,
    UTEOptionBloodOxygenDetectingStop   = 46,
    
    UTEOptionRespirationDetectingStart  = 47,
    UTEOptionRespirationDetectingStop   = 48,
    
    UTEOptionReadDisplaySize            = 49,
    
    UTEOptionSyncSkipData               = 50, //If isHasSportHRM=YES ,please invoke syncUTESportModelCustomTime:
    UTEOptionSyncSwimData               = 51, //If isHasSportHRM=YES ,please invoke syncUTESportModelCustomTime:
    
    UTEOptionReadBaseStatus             = 52,
    
    UTEOptionDetectUV                   = 53,
    UTEOptionFindPhoneFunctionOpen      = 54, //Device 'find phone' function open
    UTEOptionFindPhoneFunctionClose     = 55, //Device 'find phone' function close
    
    //If isHasSportHRM=YES, please invoke method setUTESportModel: to OPEN or CLOSE ,do not use setUTEOption:(This method is invalid)
    UTEOptionOpenBicycle                = 56,
    UTEOptionCloseBicycle               = 57,
    UTEOptionOpenSwim                   = 58,
    UTEOptionCloseSwim                  = 59,
    UTEOptionOpenSkip                   = 60,
    UTEOptionCloseSkip                  = 61,
    UTEOptionOpenTableTennis            = 62,
    UTEOptionCloseTableTennis           = 63,
    UTEOptionOpenBadminton              = 64,
    UTEOptionCloseBadminton             = 65,
    UTEOptionOpenTennis                 = 67,
    UTEOptionCloseTennis                = 68,
    
    
    UTEOptionSyncBallData               = 69,//Sync Ball Data(TableTennis、Badminton、Tennis)
    //If isHasDataStatus=YES ,please invoke syncDataCustomTime:type:
    //If isHasSportHRM=YES ,please invoke syncUTESportModelCustomTime:
    
    
    UTEOptionHRMCalibrateStart          = 70,
    UTEOptionHRMCalibrateDefault        = 71, //Restore Defaults
    UTEOptionRaiseHandCalibrateStart    = 72,
    UTEOptionRaiseHandCalibrateDefault  = 73, //Restore Defaults
    
    UTEOptionBloodCalibrateStart        = 74, //see Enum:UTEDevicesSate UTEDevicesSateBloodCalibrate..
    UTEOptionBloodCalibrateStop         = 75, //see Enum:UTEDevicesSate UTEDevicesSateBloodCalibrate..
    UTEOptionBloodCalibrateReset        = 76, //see Enum:UTEDevicesSate UTEDevicesSateBloodCalibrate..
    
    UTEOptionShutdown                   = 77,
    
    UTEOptionResetBodyTemperature       = 78, //Reset temperature calibration value
    UTEOptionClearBodyTemperature       = 79, //Delete all temperature records
    
    //Mood、Pressure and Fatigue, (Which UI to display on the interface of the device)
    UTEOptionMPFDetectingStartInMoodUI      = 80, //This Option requires access to the server, please ensure that the network is working.
    UTEOptionMPFDetectingStartInPressureUI  = 81, //please ensure that the network is working.
    UTEOptionMPFDetectingStartInFatigueUI   = 82, //please ensure that the network is working.
    UTEOptionMPFDetectingStop               = 83, //please ensure that the network is working.
    
    UTEOptionReboot                         = 84, //Required isHasReboot=Yes
    UTEOptionDeleteAllContacts              = 85, //Delete All Contacts.For some firmware support(See isHasContactDel)
    
    UTEOptionSyncRestingHR                  = 86, //Required isHasRHRM=Yes Synchronize historical data (resting heart rate)
    UTEOptionSyncBloodPPG                   = 87, //Required isHasBloodHengAi = YES.
    UTEOptionSyncBloodPPGMiddle             = 88, //Required isHasBloodHengAi = YES.
};


/*!
 *  @enum UTECallBack
 *
 *  @discussion After calling method setUTEOption, if the device receives value, it will feedback to the App.
 */
typedef NS_ENUM(NSInteger, UTECallBack) {
    
    UTECallBackUnit,
    UTECallBackInfoHeightWeight,
    UTECallBackSyncTime,
    UTECallBackAlarm,
    
    UTECallBackOpenRemindIncall,
    UTECallBackOpenRemindQQ,
    UTECallBackOpenRemindWeixin,
    UTECallBackOpenRemindSms,
    UTECallBackOpenRemindMore,
    
    UTECallBackCloseRemindIncall,
    UTECallBackCloseRemindQQ,
    UTECallBackCloseRemindWeixin,
    UTECallBackCloseRemindSms,
    UTECallBackCloseRemindMore,
    
    UTECallBackOpenRemindFacebook,
    UTECallBackOpenRemindFacebookMessenger,
    UTECallBackOpenRemindTwitter,
    UTECallBackOpenRemindWhatsApp,
    UTECallBackOpenRemindLine,
    UTECallBackOpenRemindSkype,
    UTECallBackOpenRemindHangouts,
    
    UTECallBackOpenRemindInstagram,
    UTECallBackOpenRemindYouTube,
    UTECallBackOpenRemindGmail,
    UTECallBackOpenRemindSnapchat,
    UTECallBackOpenRemindPinterest,
    UTECallBackOpenRemindLinkedIn,
    UTECallBackOpenRemindTumblr,
    UTECallBackOpenRemindViber,
    UTECallBackOpenRemindGooglePlus,
    UTECallBackOpenRemindFlickr,
    UTECallBackOpenRemindVK,
    UTECallBackOpenRemindKaKao,
    UTECallBackOpenRemindTelegram,
    UTECallBackOpenRemindTruecaller,
    UTECallBackOpenRemindPaytm,
    UTECallBackOpenRemindZalo,
    UTECallBackOpenRemindImo,
    UTECallBackOpenRemindMicrosoftTeams,
    UTECallBackOpenRemindMicrosoftOutlook,
    UTECallBackOpenRemindSwiggy,
    
    UTECallBackOpenRemindZomato,
    UTECallBackOpenRemindGpay,
    UTECallBackOpenRemindPhonePe,
    UTECallBackOpenRemindHotstar,
    UTECallBackOpenRemindPrimeVideo,
    UTECallBackOpenRemindFlipkart,
    UTECallBackOpenRemindAmazon,
    UTECallBackOpenRemindMyntra,
    
    UTECallBackOpenRemindNoiseFit,
    UTECallBackOpenRemindDailyHunt,
    UTECallBackOpenRemindInshorts,
    UTECallBackOpenRemindBookMyShow,
    
    UTECallBackOpenRemindAppleCalendar,
    UTECallBackOpenRemindJioTV,
    UTECallBackOpenRemindMakeMyTrip,
    UTECallBackOpenRemindNetflix,
    
    UTECallBackOpenRemindOla,
    UTECallBackOpenRemindFastrackReflex,
    UTECallBackOpenRemindUber,
    UTECallBackOpenRemindYTMusic,
    
    UTECallBackOpenRemindWhatsAppBusiness,
    UTECallBackOpenRemindDunzo,
    UTECallBackOpenRemindGaana,
    UTECallBackOpenRemindGoogleDrive,
    
    UTECallBackOpenRemindGoogleChat,
    UTECallBackOpenRemindWynkMusic,
    UTECallBackOpenRemindYahoo,
    UTECallBackOpenRemindTitanSmartWorld,
    
    UTECallBackOpenRemindSlack,
    UTECallBackOpenRemindSpotify,
    UTECallBackOpenRemindiOSMail,
    
    UTECallBackCloseRemindFacebook,
    UTECallBackCloseRemindFacebookMessenger,
    UTECallBackCloseRemindTwitter,
    UTECallBackCloseRemindWhatsApp,
    UTECallBackCloseRemindLine,
    UTECallBackCloseRemindSkype,
    UTECallBackCloseRemindHangouts,
    
    UTECallBackCloseRemindInstagram,
    UTECallBackCloseRemindYouTube,
    UTECallBackCloseRemindGmail,
    UTECallBackCloseRemindSnapchat,
    UTECallBackCloseRemindPinterest,
    UTECallBackCloseRemindLinkedIn,
    UTECallBackCloseRemindTumblr,
    UTECallBackCloseRemindViber,
    UTECallBackCloseRemindGooglePlus,
    UTECallBackCloseRemindFlickr,
    UTECallBackCloseRemindVK,
    UTECallBackCloseRemindKaKao,
    UTECallBackCloseRemindTelegram,
    UTECallBackCloseRemindTruecaller,
    UTECallBackCloseRemindPaytm,
    UTECallBackCloseRemindZalo,
    UTECallBackCloseRemindImo,
    UTECallBackCloseRemindMicrosoftTeams,
    UTECallBackCloseRemindMicrosoftOutlook,
    UTECallBackCloseRemindSwiggy,
    
    UTECallBackCloseRemindZomato,
    UTECallBackCloseRemindGpay,
    UTECallBackCloseRemindPhonePe,
    UTECallBackCloseRemindHotstar,
    UTECallBackCloseRemindPrimeVideo,
    UTECallBackCloseRemindFlipkart,
    UTECallBackCloseRemindAmazon,
    UTECallBackCloseRemindMyntra,
    
    UTECallBackCloseRemindNoiseFit,
    UTECallBackCloseRemindDailyHunt,
    UTECallBackCloseRemindInshorts,
    UTECallBackCloseRemindBookMyShow,
    
    UTECallBackCloseRemindAppleCalendar,
    UTECallBackCloseRemindJioTV,
    UTECallBackCloseRemindMakeMyTrip,
    UTECallBackCloseRemindNetflix,
    
    UTECallBackCloseRemindOla,
    UTECallBackCloseRemindFastrackReflex,
    UTECallBackCloseRemindUber,
    UTECallBackCloseRemindYTMusic,
    
    UTECallBackCloseRemindWhatsAppBusiness,
    UTECallBackCloseRemindDunzo,
    UTECallBackCloseRemindGaana,
    UTECallBackCloseRemindGoogleDrive,
    
    UTECallBackCloseRemindGoogleChat,
    UTECallBackCloseRemindWynkMusic,
    UTECallBackCloseRemindYahoo,
    UTECallBackCloseRemindTitanSmartWorld,
    
    UTECallBackCloseRemindSlack,
    UTECallBackCloseRemindSpotify,
    UTECallBackCloseRemindiOSMail,
    
    UTECallBackOpenUnitSitRemind,
    UTECallBackCloseSitRemind,
    
    UTECallBackHeartSwitchDynamic,
    UTECallBackHeartSwitchStatic,
    
    UTECallBackDevicesVersion,
    UTECallBackDevicesAddress,
    
    UTECallBackDeviceHorizontal,
    UTECallBackDeviceVertical,
    
    UTECallBackDeviceSilence,
    
    UTECallBackDeviceWeather,
    UTECallBackDeviceBattery,
    UTECallBackSwitchHandAndDisplay,
    UTECallBackWeatherSevenDay,
    UTECallBackIbeaconOption,
    UTECallBackMultiLanguage,
    
    UTECallBackSiestaSet,
    UTECallBackSleepNightSet,
    UTECallBackSleepAdjust,
    
    UTECallBackFindPhoneFunctionOpen,
    UTECallBackFindPhoneFunctionClose,
    
    UTECallBackOpenBicycle,
    UTECallBackCloseBicycle,
    UTECallBackOpenSwim,
    UTECallBackCloseSwim,
    UTECallBackOpenSkip,
    UTECallBackCloseSkip,
    
    UTECallBackOpenTableTennis,
    UTECallBackCloseTableTennis,
    UTECallBackOpenBadminton,
    UTECallBackCloseBadminton,
    UTECallBackOpenTennis,
    UTECallBackCloseTennis,
    
    UTECallBackOpenCommonHRMAuto,
    UTECallBackCloseCommonHRMAuto,
    UTECallBackOpen24HourHRM,
    UTECallBackClose24HourHRM,
    
    UTECallBackCustomUIshow,
    UTECallBackCustomUIhide,
    UTECallBackDeleteGPSData,
    UTECallBackDeviceCustomMsg,
    
    UTECallBackResetCalibrateBodyTemp,
    UTECallBackClearBodyTempData,
    
    UTECallBackMenstruationOpen,
    UTECallBackMenstruationClose,
    
    UTECallBackBloodPressureAutoTest,
    
    UTECallBackBodyTemperatureAutoTestOpen,
    UTECallBackBodyTemperatureAutoTestClose,
    UTECallBackBodyTemperatureSetTestDuration,
    UTECallBackBodyTemperatureSetAlarm,
    UTECallBackBodyTemperatureFunction2Open,
    UTECallBackBodyTemperatureFunction2Close,
    
    UTECallBloodOxygenAutoTestOpen,
    UTECallBloodOxygenAutoTestClose,
    UTECallBloodOxygenSetTestDuration,
    
    UTECallRespirationAutoTestOpen,
    UTECallRespirationAutoTestClose,
    UTECallRespirationSetTestDuration,
    
    UTECallBackCheckWearFunctionOpen,
    UTECallBackCheckWearFunctionClose,
    
    UTECallMPFAutoTestOpen,
    UTECallMPFAutoTestClose,
    UTECallMPFSetTestDuration,
    
    UTECallBackDrinkWaterReminderOpen,
    UTECallBackDrinkWaterReminderClose,
    UTECallBackHandwashingReminderOpen,
    UTECallBackHandwashingReminderClose,
    
    UTECallSportAlertHRM,
    UTECallSportTargetDistance,
    UTECallSportTargetDuration,
    UTECallSportTargetCalories,
    
    UTECallBluetooth3_0Key,
    
    UTECallBackDeleteAllContacts,
    
    UTECallBackBloodHengAiInfo,
    UTECallBackBloodHengAiTestModel,
    
    UTECallBackOffScreenDisplayType,
    UTECallBackOffScreenIndex,
    UTECallBackOffScreenTimeRange,
    
    UTECallBackCustomTimeSaveData,
    UTECallBackBloodPressureAutoTime,
    UTECallBackBloodPressureSpecifyTime,
    UTECallBackBloodPressureTimeRange,
    UTECallBackBloodPressureMorningTestOpen,
    UTECallBackBloodPressureMorningTestClose,
    
    UTECallBackECGAppTestFail,
};

/*!
 *  @enum UTEDevicesSate
 */
typedef NS_ENUM(NSInteger, UTEDevicesSate) {
    UTEDevicesSateConnected = 0,
    UTEDevicesSateSystemConnected,
    UTEDevicesSateDisconnected,           //If there is an error, please see error.code(UTEErrorCode)
    UTEDevicesSateConnectingError,        //There may be too many devices connected to the Bluetooth system of the mobile phone, making it impossible to connect. if error=14 or 15,Please ignore the device in the system Bluetooth interface.
    
    UTEDevicesSateSyncBegin,
    UTEDevicesSateSyncSuccess,
    UTEDevicesSateSyncError,              //There are errors, please see error.code(UTEErrorCode)
    
    UTEDevicesSateHeartDetectingStart,
    UTEDevicesSateHeartDetectingProcess,  //There will be data during device heart rate detection
    UTEDevicesSateHeartDetectingStop,     //No data will be returned
    UTEDevicesSateHeartDetectingError,    //There are errors, please see error.code(UTEErrorCode)
    UTEDevicesSateHeartCurrentValue,      //Device heart rate returns in real time
    
    UTEDevicesSateBloodDetectingStart,
    UTEDevicesSateBloodDetectingProcess,  //There will be data during device Blood pressure detection
    UTEDevicesSateBloodDetectingStop,     //There will be data if device test successful
    UTEDevicesSateBloodDetectingError,    //There are errors, please see error.code(UTEErrorCode)
    
    UTEDevicesSateBloodOxygenDetectingStart,
    UTEDevicesSateBloodOxygenDetectingProcess,  //There will be data during device Blood Oxygen detection
    UTEDevicesSateBloodOxygenDetectingStop,     //There will be data if device Blood Oxygen test successful
    UTEDevicesSateBloodOxygenDetectingError,    //There are errors, please see error.code(UTEErrorCode)
    
    UTEDevicesSateRespirationDetectingStart,
    UTEDevicesSateRespirationDetectingProcess,
    UTEDevicesSateRespirationDetectingStop,
    UTEDevicesSateRespirationDetectingError,
    
    UTEDevicesSateCheckFirmwareError,      //Error in firmware check, please see error.code(UTEErrorCode)
    
    UTEDevicesSateUpdateHaveNewVersion,
    UTEDevicesSateUpdateNoNewVersion,
    UTEDevicesSateUpdateBegin,
    UTEDevicesSateUpdateSuccess,           //Firmware upgrade successful(Device will automatically disconnect, please reconnect)
    UTEDevicesSateUpdateError,             //Firmware upgrade failed, please see error.code(UTEErrorCode)
    
    UTEDevicesSateCardApduError,           //Device Apdu data interaction failed, please see error.code(UTEErrorCode)
    
    UTEDevicesSatePasswordState,           //Device password verification status. Please see UTEPasswordState
    
    UTEDevicesSateStep,                     //The device is in the monitoring step
    UTEDevicesSateSleep,                    //The device is in the monitoring sleep
    UTEDevicesSateOther,
    
    UTEDevicesSateUV,                       //Acquired UV data after device testing is completed
    
    UTEDevicesSateHRMCalibrateStart,
    UTEDevicesSateHRMCalibrateFail,
    UTEDevicesSateHRMCalibrateComplete,
    UTEDevicesSateHRMCalibrateDefault,      //Heart rate calibration value restored to default
    
    UTEDevicesSateRaiseHandCalibrateStart,  // (Raise your hand, the screen lights up) Calibration starts
    UTEDevicesSateRaiseHandCalibrateFail,
    UTEDevicesSateRaiseHandCalibrateComplete,
    UTEDevicesSateRaiseHandCalibrateDefault, //Calibration value restored to default
    
    UTEDevicesSateBodyFatStart,
    UTEDevicesSateBodyFatStop,
    UTEDevicesSateBodyFatStateIn,           //Device test status. 'Not Wearing' To 'Wearing'
    UTEDevicesSateBodyFatStateOut,          //Device test status. 'Wearing' To 'Not Wearing'
    UTEDevicesSateBodyFatFail,              //There are errors. Please see error.code(UTEErrorCode)
    UTEDevicesSateBodyFatComplete,          //There will be data if device test successful
    
    UTEDevicesSateECGDetectingStart,
    UTEDevicesSateECGDetectingProcess,          //There will be data during ECG detection
    UTEDevicesSateECGDetectingFail,             //There are errors. Please see error.code(UTEErrorCode)
    UTEDevicesSateECGDetectingComplete,         //There will be data if device test successful
    UTEDevicesSateECGDetectingStatusBothHand,   //ECG status: Both hands have been placed on the electrodes.
    UTEDevicesSateECGDetectingStatusOneHand,    //ECG status: one of the hands is not placed on the electrode.
    
    UTEDevicesSateBodyTempNormal,               //The device automatically return data. Required isHasBodyTemperature = YES
    UTEDevicesSateBodyTempCurrent,              //Current body temperature. Required isHasBodyTemperature = YES
    UTEDevicesSateBodyTempAlarm,                //The device issues an alarm for body temperature.
    
    UTEDevicesSateDrop,                         //The device has been dropped.
    
    UTEDevicesSateBloodCalibrateStart,
    UTEDevicesSateBloodCalibrateStop,
    UTEDevicesSateBloodCalibrateComplete,   //have value :dict = @{kUTECommonData:NSData}
    UTEDevicesSateBloodCalibrateFail,       //See UTEErrorCode
    UTEDevicesSateBloodCalibrateReset,
    
    UTEDevicesSateMPFDetectingStart,
    UTEDevicesSateMPFDetectingStop,
    UTEDevicesSateMPFDetectingComplete,     // have value :dict = @{kUTEQueryMPF:UTEModelMPFInfo};
    UTEDevicesSateMPFDetectingFail,         //See UTEErrorCode
    
    UTEDevicesSateBloodPPGStartFromApp,     //App actively starts starting blood pressure testing
    UTEDevicesSateBloodPPGStartFromDevice,  //Device actively initiates a blood pressure test
    UTEDevicesSateBloodPPGSProcess,         //There will be data during Blood detection
    UTEDevicesSateBloodPPGStopFromApp,
    UTEDevicesSateBloodPPGStopFromDevice,
    UTEDevicesSateBloodPPGSComplete,
    UTEDevicesSateBloodPPGSFail,
    
    UTEDevicesSateBloodGlucoseStart,
    UTEDevicesSateBloodGlucoseStop,         //Required:isHasBloodHengAi=NO,have value :dict = @{kUTEQueryBloodGlucose:UTEModelBloodGlucose}
    UTEDevicesSateBloodGlucoseProcess,      //Required:isHasBloodHengAi=Yes
    UTEDevicesSateBloodGlucoseDetectingError,    //There are errors, please see error.code(UTEErrorCode)
    
    UTEDevicesSateHRVTestStart,
    UTEDevicesSateHRVTestStop,              //Required:isHasBloodHengAi=NO,have value :dict = @{kUTEQueryHRV:UTEModelHRV}
    UTEDevicesSateHRVTestProcess,           //Required:isHasBloodHengAi=Yes
    UTEDevicesSateHRVTestDetectingError,    //There are errors, please see error.code(UTEErrorCode)
};

/*!
 *  @enum UTEPasswordState
 *
 *  @discussion Some firmware requires a password to connect.
 *
 *  @constant UTEPasswordStateNew               Device needs to set a new password (Not used yet)
 *  @constant UTEPasswordStateNeed              Device needs to set a password (Not used yet)
 *  @constant UTEPasswordStateCorrect           Password input, verified, or modify successfully
 *  @constant UTEPasswordStateError             Password input, verified, or modify failed
 */
typedef NS_ENUM(NSInteger, UTEPasswordState) {
    
    UTEPasswordStateNew    = 1,
    UTEPasswordStateNeed,
    UTEPasswordStateCorrect,
    UTEPasswordStateError,
};

/*!
 *  @enum UTEPasswordType
 *
 *  @discussion The type of password used for what.
 *
 *  @constant UTEPasswordTypeConnect           When the device is connected
 *  @constant UTEPasswordTypeConfirm           Must verify when changing password (Not used yet)
 *  @constant UTEPasswordTypeReset             Reset password (Not used yet)
 */
typedef NS_ENUM(NSInteger, UTEPasswordType) {
    
    UTEPasswordTypeConnect    = 1,
    UTEPasswordTypeConfirm,
    UTEPasswordTypeReset,
};

/*!
 *  @enum UTEErrorCode
 */
typedef NS_ENUM(NSInteger, UTEErrorCode) {
    UTEErrorCodeCRC                     = -1,
    
    UTEErrorCodeNULL                    = 0,
    
    UTEErrorCodeDisconnect              = 1,  //Device disconnected from App
    
    UTEErrorCodeSyncDisconnect          = 2,  //Device disconnected while syncing data
    UTEErrorCodeHeartingDisconnect      = 3,  //Device disconnected during heart rate test
    UTEErrorCodeBloodDisconnect         = 4,  //Device disconnected during blood pressure test
    UTEErrorCodeBloodOxygenDisconnect   = 5,  //Device disconnected during blood oxygen pressure test
    UTEErrorCodeSyncVerify              = 6,  //After syncing data, data verification failed (some data was lost)
    
    UTEErrorCodeSyncStep                = 7,  //Sync data of steps. The data reception is abnormal. Sync finish.
    UTEErrorCodeSyncSleep               = 8,
    UTEErrorCodeSyncHRM                 = 9,
    UTEErrorCodeSyncBlood               = 10,
    UTEErrorCodeSyncBloodOxygen         = 11,
    UTEErrorCodeSyncSwim                = 12,
    UTEErrorCodeSyncSkip                = 13,
    UTEErrorCodeSyncBicycle             = 14,
    UTEErrorCodeSyncBall                = 15,
    UTEErrorCodeSyncGPS                 = 16,
    UTEErrorCodeSyncBarometric          = 17,
    UTEErrorCodeSyncECG                 = 18,
    UTEErrorCodeSyncBodyFat             = 19,
    UTEErrorCodeSyncBodyTemp            = 20,
    
    UTEErrorCodeSyncTimeout             = 21,  //Synchronized data timed out
    
    UTEErrorCodeCheckTimeout            = 22,  //Check device's online firmware timeout, network timeout (about 10 seconds)
    UTEErrorCodeCheckChara              = 23,  //Check device, the firmware is incomplete and characteristic values are missing
    UTEErrorCodeCheckAddress            = 24,  //Check device, the firmware is incomplete and address missing
    
    UTEErrorCodeUpdateDownload          = 25,
    UTEErrorCodeUpdateDisconnect        = 26,
    UTEErrorCodeUpdateLoadFirmwareFail  = 27,
    
    UTEErrorCodeApduDisconnect          = 28,  //Device disconnected during Apdu data interaction
    UTEErrorCodeDeviceTimeout           = 29,
    UTEErrorCodeBodyFatTimeout          = 30,
    
    UTEErrorCodeDialTimeout             = 31,
    UTEErrorCodeDialCRC                 = 32,
    UTEErrorCodeDialTooBig              = 33,
    UTEErrorCodeDialDisconnect          = 34,
    UTEErrorCodeDialLowBattery          = 35,  //Device battery is low, please charge
    
    UTEErrorCodePairingInformation      = 36,//There may be too many devices connected to the Bluetooth system of the mobile phone, making it impossible to connect. Please prompt the user to ignore the device or restart the device.
    
    UTEErrorCodeBloodPressureCheckTimeout       = 37,
    UTEErrorCodeBloodPressureCheckFingerAway    = 38,
    UTEErrorCodeBloodPressureCheckAbnormal      = 39,
    
    UTEErrorCodeMPFInvalidData          = 40,
    UTEErrorCodeMPFNetworkTimeout       = 41,
    UTEErrorCodeMPFTestTimeout          = 42,
    UTEErrorCodeMPFIncorrectlyWorn      = 43,
    UTEErrorCodeMPFInMotion             = 44,
    
    UTEErrorCodeBloodPPGTimeout         = 45,
    UTEErrorCodeBloodPPGUnstableWear    = 46, //Please wear the device correctly
    
    
    UTEErrorCodeBloodGlucoseAbnormal    = 47,
    UTEErrorCodeHRVTestAbnormal         = 48,
    
    UTEErrorCodeBloodPPGCRC             = 49,
    UTEErrorCodeBloodPPGInvalidData     = 50,
    UTEErrorCodeBloodPPGNetworkTimeout  = 51,
    
    UTEErrorCodeNoFunction              = 52,
    UTEErrorCodeMissingParameter        = 53,
    UTEErrorCodePath                    = 54,
    UTEErrorCodeOTACancel               = 55,
    UTEErrorCodeDelete                  = 56,
    UTEErrorCodeUnzip                   = 57,
    UTEErrorCodeBinNil                  = 58,
    UTEErrorCodeDialCancel              = 59,
    UTEErrorCodeDialUpperLimit          = 60,
};

/*!
 *  @enum UTEBluetoothState
 *
 *  @discussion Bluetooth status
 */
typedef NS_ENUM(NSInteger, UTEBluetoothState) {
    UTEBluetoothStateOpen = 0,
    UTEBluetoothStateClose,
    UTEBluetoothStateResetting,
    UTEBluetoothStateUnsupported,
    UTEBluetoothStateUnauthorized,
    UTEBluetoothStateUnknown,
};

/*!
 *  @enum UTEQueryType
 */
typedef NS_ENUM(NSInteger, UTEQueryType) {
    UTEQueryTypeRun = 0,
    UTEQueryTypeSleep,
    UTEQueryTypeHRM,
    UTEQueryTypeAll,
}NS_DEPRECATED_IOS(2_0,7_0);

/*!
 *  @enum UTESleepType
 */
typedef NS_ENUM(NSInteger, UTESleepType) {
    UTESleepTypeAwake = 0,
    UTESleepTypeDeepSleep,
    UTESleepTypeLightSleep,
    
    //Some devices support the following
    UTESleepTypeSleepREM, //See isHasSleepREM : rapid eye movement sleep
    UTESleepTypeSleepSporadic,//See isHasSleepSporadic
    UTESleepTypeSleepSnoring, //Undefined
    
    UTESleepTypeOther = 999,
};

/*!
 *  @enum UTETimeType
 */
typedef NS_ENUM(NSInteger, UTETimeType) {
    UTETimeTypeUndefined = 0,
    UTETimeTypeNight,
    UTETimeTypeDay,
};

/*!
 *  @enum UTEHRMType
 *
 *  @constant UTEHRMTypeNormal      Data is normal
 *  @constant UTEHRMTypeSuccess     Heart rate test successful
 *  @constant UTEHRMTypeFail        Heart rate test failed
 *  @constant UTEHRMTypeTimeout     Heart rate test timeout
 */
typedef NS_ENUM(NSInteger, UTEHRMType) {
    UTEHRMTypeNormal = 0,
    UTEHRMTypeSuccess,
    UTEHRMTypeFail,
    UTEHRMTypeTimeout,
};

/*!
 *  @enum UTEBloodType
 *
 *  @constant UTEBloodTypeNormal      Data is normal
 *  @constant UTEBloodTypeSuccess     Blood pressure test successful
 *  @constant UTEBloodTypeFail        Blood pressure test failed
 *  @constant UTEBloodTypeTimeout     Blood pressure test timeout
 */
typedef NS_ENUM(NSInteger, UTEBloodType) {
    UTEBloodTypeNormal = 0,
    UTEBloodTypeSuccess,
    UTEBloodTypeFail,
    UTEBloodTypeTimeout,
};

/*!
 *  @enum UTEBloodOxygenType
 *
 *  @constant UTEBloodOxygenTypeNormal      Data is normal
 *  @constant UTEBloodOxygenTypeSuccess     Blood Oxygen test successful
 *  @constant UTEBloodOxygenTypeFail        Blood Oxygen test failed
 *  @constant UTEBloodOxygenTypeTimeout     Blood Oxygen test timeout
 */
typedef NS_ENUM(NSInteger, UTEBloodOxygenType) {
    UTEBloodOxygenTypeNormal = 0,
    UTEBloodOxygenTypeSuccess,
    UTEBloodOxygenTypeFail,
    UTEBloodOxygenTypeTimeout,
};

/*!
 *  @enum UTERespirationType
 *
 *  @constant UTERespirationTypeNormal      Data is normal
 *  @constant UTERespirationTypeSuccess     Respiration test successful
 *  @constant UTERespirationTypeFail        Respiration test failed
 *  @constant UTERespirationTypeTimeout     Respiration test timeout
 */
typedef NS_ENUM(NSInteger, UTERespirationType) {
    UTERespirationTypeNormal = 0,
    UTERespirationTypeSuccess,
    UTERespirationTypeFail,
    UTERespirationTypeTimeout,
};

/*!
 *  @enum UTEAlarmWeek
 */
typedef NS_ENUM(NSInteger, UTEAlarmWeek) {
    UTEAlarmWeekSunday    = 1 << 0,
    UTEAlarmWeekMonday    = 1 << 1,
    UTEAlarmWeekTuesday   = 1 << 2,
    UTEAlarmWeekWednesday = 1 << 3,
    UTEAlarmWeekThursday  = 1 << 4,
    UTEAlarmWeekFriday    = 1 << 5,
    UTEAlarmWeekSaturday  = 1 << 6,
};

/*!
 *  @enum UTEAlarmNum
 *
 *  @discussion Alarm clock number
 */
typedef NS_ENUM(NSInteger, UTEAlarmNum) {
    UTEAlarmNum1 = 1,
    UTEAlarmNum2,
    UTEAlarmNum3,
    
    //The following content requires UTEModelDevices.isHasClockTitle = YES
    UTEAlarmNum4,
    UTEAlarmNum5,
    
    //The following content requires UTEModelDevices.isHasClockType = YES
    UTEAlarmNum6,
    UTEAlarmNum7,
    UTEAlarmNum8,
    UTEAlarmNum9,
    UTEAlarmNum10,
};

/*!
 *  @enum UTEClockType
 *
 *  @discussion Alarm Clock Type
 *  Requires UTEModelDevices.isHasClockType = YES
 */
typedef NS_ENUM(NSInteger, UTEClockType) {
    UTEClockTypeNormal,
    UTEClockTypeGetUp,
    UTEClockTypeMeeting,
    UTEClockTypeAppointment,
    UTEClockTypeEat,
    
};

/*!
 *  @enum UTEDeviceFeature
 *
 *  @discussion Device Feature.
 *  When isRKDevices=YES, don't need to consider this enumeration.
 *
 *  @constant UTEDeviceFeatureNone             Default mode
 *  @constant UTEDeviceFeatureWechat           WeChat mode (WeChat ranking)
 *  @constant UTEDeviceFeatureMessage          Message push mode
 *  @constant UTEDeviceFeatureWechatMessage    Message push mode and WeChat mode
 *  @constant UTEDeviceFeatureUpdate           Upgrade mode
 *  @constant UTEDeviceFeatureUpdateWechat     Upgrade mode and WeChat mode
 */
typedef NS_ENUM(NSInteger, UTEDeviceFeature) {
    UTEDeviceFeatureNone,
    UTEDeviceFeatureWechat,
    UTEDeviceFeatureMessage,
    UTEDeviceFeatureWechatMessage,
    UTEDeviceFeatureUpdate,
    UTEDeviceFeatureUpdateWechat,
};

/*!
 *  @enum UTESilenceType
 *
 *  @discussion Turn off some functions of the device
 *
 *  @constant UTESilenceTypeNone             Turn off all functions
 *  @constant UTESilenceTypeScreen           Turn on the device screen and the screen will never light up (This feature is invalid)
 *  @constant UTESilenceTypeVibration        Turn on the device's motor vibration, the device will never shake
 *  @constant UTESilenceTypeMessage          Turn on the device any message alerts
 *  @constant UTESilenceTypePhone            Turn on the 'hang up call' function of the device
 */
typedef NS_ENUM(NSInteger, UTESilenceType) {
    UTESilenceTypeNone              = 0,
    UTESilenceTypeScreen            = 1 << 0, //(This enumerate is invalid)
    UTESilenceTypeVibration         = 1 << 1,
    UTESilenceTypeMessage           = 1 << 2,
    UTESilenceTypePhone             = 1 << 3,
};

/*!
 *  @enum UTEWeatherType
 *
 *  @discussion Weather types supported by firmware.
 */
typedef NS_ENUM(NSInteger, UTEWeatherType) {
    UTEWeatherTypeSunny         = 1,
    UTEWeatherTypeCloudy,
    UTEWeatherTypeOvercast,
    UTEWeatherTypeShower,
    UTEWeatherTypeThunderStorm,
    UTEWeatherTypeRainSnow,
    UTEWeatherTypeLightRain,
    UTEWeatherTypePouring,
    UTEWeatherTypeSnow,
    UTEWeatherTypeSandstorm,
    UTEWeatherTypeMistHaze,
    UTEWeatherTypeWind,
    
    
    //The following parameters, Required isHasWeatherTypeMore=YES
    //Different device supports different types. Please consult the project manager
    
    UTEWeatherTypeSnowHeavy,
    UTEWeatherTypeSnowLight,
    
    UTEWeatherTypeCloudyPartly,
    UTEWeatherTypeCloudyOccasional,
    
    UTEWeatherTypeShowerHeavy,
    UTEWeatherTypeThunderStormHeavy,
    UTEWeatherTypeThunderStormHeavyAndHail,
    UTEWeatherTypeModerateRain,
    UTEWeatherTypeExtremeRain,
    UTEWeatherTypeDrizzle,
    UTEWeatherTypeRainstorm,
    UTEWeatherTypeRainstormHeavy,
    UTEWeatherTypeRainstormExtreme,
    UTEWeatherTypeFreezingRain,
    UTEWeatherTypeLightToModerateRain,
    UTEWeatherTypeModerateToHeavyRain,
    UTEWeatherTypeHeavyRainToRainstorm,
    UTEWeatherTypeRainstormToHeavy,
    UTEWeatherTypeHeavyToRainstormExtreme,
    
    UTEWeatherTypeModerateSnow,
    UTEWeatherTypeSnowStorm,
    UTEWeatherTypeSleet,
    UTEWeatherTypeShowerAndRain,
    UTEWeatherTypeSnowShower,
    UTEWeatherTypeLightToModerateSnow,
    UTEWeatherTypeModerateToHeavySnow,
    UTEWeatherTypeHeavyToSnowStorm,
    
    UTEWeatherTypeMist,
    UTEWeatherTypeFog,
    
    UTEWeatherTypeHaze,
    UTEWeatherTypeDust,
    UTEWeatherTypeSand,
    UTEWeatherTypeSandstormHeavy,
    
    UTEWeatherTypeFogHeavy,
    UTEWeatherTypeFogExtreme,
    
    UTEWeatherTypeHazeModerate,
    UTEWeatherTypeHazeHeavy,
    UTEWeatherTypeHazeExtreme,
    
    UTEWeatherTypeFogDense,
    UTEWeatherTypeFogDensest,
    
    UTEWeatherTypeHot,
    UTEWeatherTypeCold,
    
    //For the above parameters, Required isHasWeatherTypeMore=YES
};

/*!
 *  @enum UTEDeviceSreenDisplayType
 *
 *  @discussion Device screen display orientation
 *
 *  @constant UTEDeviceSreenDisplayTypeHorizontal
 *  @constant UTEDeviceSreenDisplayTypeVerticalEN        //Vertical display(English and other languages)
 *  @constant UTEDeviceSreenDisplayTypeVerticalCH        //Vertical display(Chinese)
 */
typedef NS_ENUM(NSInteger, UTEDeviceSreenDisplayType) {
    UTEDeviceSreenDisplayTypeHorizontal,
    UTEDeviceSreenDisplayTypeVerticalEN,
    UTEDeviceSreenDisplayTypeVerticalCH,
};

/*!
 *  @enum UTEWearType
 *
 *  @discussion Which hand wears the device
 *
 *  @constant UTEWearTypeLeft         //Left hand
 *  @constant UTEWearTypeRight        //Right hand
 */
typedef NS_ENUM(NSInteger, UTEWearType) {
    UTEWearTypeLeft,
    UTEWearTypeRight,
};

/*!
 *  @enum UTEIbeaconOption
 *
 *  @discussion ibeacon
 *
 *  @constant UTEIbeaconOptionUUID                 //uuid
 *  @constant UTEIbeaconOptionMajor                //major
 *  @constant UTEIbeaconOptionMinor                //minor
 *  @constant UTEIbeaconOptionName                 //device name
 *  @constant UTEIbeaconOptionTXPower              //TX Power
 *  @constant UTEIbeaconOptionAdvertisingInterval  //Advertising Interval
 */
typedef NS_ENUM(NSInteger, UTEIbeaconOption) {
    UTEIbeaconOptionUUID,
    UTEIbeaconOptionMajor,
    UTEIbeaconOptionMinor,
    UTEIbeaconOptionName,
    UTEIbeaconOptionTXPower,
    UTEIbeaconOptionAdvertisingInterval,
};

/*!
 *  @enum UTEDeviceInfoSex
 *
 *  @discussion Wearer's gender
 *
 *  @constant UTEDeviceInfoSexDefault
 *  @constant UTEDeviceInfoSexMale
 *  @constant UTEDeviceInfoSexFemale
 */
typedef NS_ENUM(NSInteger, UTEDeviceInfoSex) {
    UTEDeviceInfoSexDefault,
    UTEDeviceInfoSexMale,
    UTEDeviceInfoSexFemale,
};

/*!
 *  @enum UTEDeviceLanguage
 */
typedef NS_ENUM(NSInteger, UTEDeviceLanguage) {
    
    UTEDeviceLanguageChinese    = 1,        //中文
    UTEDeviceLanguageEnglish    = 2,        //英语
    UTEDeviceLanguageKorean     = 3,        //韩语
    UTEDeviceLanguageJapanese   = 4,        //日语
    UTEDeviceLanguageGerman     = 5,        //德语
    UTEDeviceLanguageSpanish    = 6,        //西班牙语
    UTEDeviceLanguageFrench     = 7,        //法语
    UTEDeviceLanguageItalian    = 8,        //意大利语
    UTEDeviceLanguagePortuguese  = 9,       //葡萄牙语
    UTEDeviceLanguageArabic     = 10,       //阿拉伯语
    UTEDeviceLanguageIndia      = 11,       //印度语
    UTEDeviceLanguageHindi      = 12,       //印地语
    UTEDeviceLanguagePolish     = 13,       //波兰语
    UTEDeviceLanguageRussian    = 14,       //俄语
    UTEDeviceLanguageDutch      = 15,       //荷兰语
    UTEDeviceLanguageTurkey     = 16,       //土耳其
    UTEDeviceLanguageBengal     = 17,       //孟加拉语
    UTEDeviceLanguageUrdu       = 18,       //乌尔都语
    UTEDeviceLanguageIndonesia  = 19,       //印度尼西亚语
    UTEDeviceLanguagePunjabi    = 20,       //旁遮普语
    UTEDeviceLanguageThai       = 21,       //泰语
    UTEDeviceLanguageCzech      = 22,       //捷克语
    UTEDeviceLanguageChinese_t  = 23,       //中文繁体
    UTEDeviceLanguageHebrew     = 24,       //希伯来语
    UTEDeviceLanguageSlovakia   = 25,       //斯洛伐克
    UTEDeviceLanguageHungary    = 26,       //匈牙利
    UTEDeviceLanguageRomania    = 27,       //罗马尼亚
    UTEDeviceLanguageBelarus    = 28,       //白俄罗斯
    UTEDeviceLanguageEesti      = 29,       //爱沙尼亚
    UTEDeviceLanguageAlgeria    = 30,       //阿尔及利亚
    UTEDeviceLanguageAmharic    = 31,       //阿姆哈拉
    UTEDeviceLanguageAzerbaijan = 32,       //阿塞拜疆
    UTEDeviceLanguageIreland    = 33,       //爱尔兰
    UTEDeviceLanguageOccitan    = 34,       //欧西坦语(奥克语)
    UTEDeviceLanguageOriya      = 35,       //奥里亚语
    UTEDeviceLanguageOromoo     = 36,       //奥罗莫语
    UTEDeviceLanguageEuskera    = 37,       //巴斯克语
    UTEDeviceLanguageBulgaria   = 38,       //保加利亚
    UTEDeviceLanguageBosnia     = 39,       //波斯尼亚
    UTEDeviceLanguagePersian    = 40,       //波斯语
    UTEDeviceLanguagePhilippines   = 41,    //菲律宾
    UTEDeviceLanguageKhmer      = 42,       //高棉语
    UTEDeviceLanguageGujarat    = 43,       //古吉拉特语
    UTEDeviceLanguageKazakhstan = 44,       //哈萨克斯坦
    UTEDeviceLanguageAyisyen    = 45,       //海地克里奥语(海地语/克里奥耳语)
    UTEDeviceLanguageHausa      = 46,       //豪萨语
    UTEDeviceLanguageMontenegrin = 47,      //黑山语
    UTEDeviceLanguageCatalunya  = 48,       //加泰罗尼亚语
    UTEDeviceLanguageKannada    = 49,       //卡纳达语
    UTEDeviceLanguageXhosa      = 50,       //科萨语
    UTEDeviceLanguageHrvatska   = 51,       //克罗地亚语
    UTEDeviceLanguageQuechua    = 52,       //克丘亚语
    UTEDeviceLanguageKurdish    = 53,       //库尔德语
    UTEDeviceLanguageLatin      = 54,       //拉丁语
    UTEDeviceLanguageTzebuergesch = 55,     //卢森堡语
    UTEDeviceLanguageKinyarwanda  = 56,     //卢旺达语
    UTEDeviceLanguageDenmark    = 57,       //丹麦语
    UTEDeviceLanguageRome       = 58,       //罗马语
    UTEDeviceLanguageRomansh    = 59,       //罗曼什语
    UTEDeviceLanguageMalagasy   = 60,       //马达加斯加
    UTEDeviceLanguageMarathi    = 61,       //马拉地语(मराठी)
    UTEDeviceLanguageMarathi_1  = 62,       //马拉提语
    UTEDeviceLanguageMalayalam  = 63,       //马拉雅拉姆语
    UTEDeviceLanguageMalaysia   = 64,       //马来西亚
    UTEDeviceLanguageMacedonia  = 65,       //马其顿语
    UTEDeviceLanguageMaithili   = 66,       //迈蒂利语
    UTEDeviceLanguageGaelg      = 67,       //曼克斯(曼岛语)
    UTEDeviceLanguageMyanmar    = 68,       //缅甸语
    UTEDeviceLanguageNaples     = 69,       //那不勒斯语
    UTEDeviceLanguageNepal      = 70,       //尼泊尔语
    UTEDeviceLanguageNorge      = 71,       //挪威语
    UTEDeviceLanguagePashto     = 72,       //普什图语
    UTEDeviceLanguageChichewa   = 73,       //齐切瓦语
    UTEDeviceLanguageSverige    = 74,       //瑞典
    UTEDeviceLanguageSerbia     = 75,       //赛尔维亚语
    UTEDeviceLanguageSinhalese  = 76,       //僧伽罗语
    UTEDeviceLanguageSlovenski  = 77,       //斯洛文尼亚语
    UTEDeviceLanguageKiswahili  = 78,       //斯瓦希里语
    UTEDeviceLanguageCebu       = 79,       //宿务语
    UTEDeviceLanguageSomali     = 80,       //索马里语
    UTEDeviceLanguageSamoan     = 81,       //萨摩亚语
    UTEDeviceLanguageTagalog    = 82,       //他加禄语
    UTEDeviceLanguageTajik      = 83,       //塔吉克语
    UTEDeviceLanguageTelangana  = 84,       //泰卢固语
    UTEDeviceLanguageTamil      = 85,       //泰米尔语
    UTEDeviceLanguageTigray     = 86,       //提格利尼亚语
    UTEDeviceLanguageTurkmen    = 87,       //土库曼语
    UTEDeviceLanguageUkraine    = 88,       //乌克兰语
    UTEDeviceLanguageUzbekistan = 89,       //乌兹别克语
    UTEDeviceLanguageGreek      = 90,       //希腊语
    UTEDeviceLanguageSindhi     = 91,       //信德语
    UTEDeviceLanguageShona      = 92,       //修纳语
    UTEDeviceLanguageSyriac     = 93,       //叙利亚语
    UTEDeviceLanguageIgbo       = 94,       //伊博语
    UTEDeviceLanguageIlokano    = 95,       //伊洛卡诺语
    UTEDeviceLanguagePending2   = 96,       //预留、待定
    UTEDeviceLanguageYoruba     = 97,       //约鲁巴语
    UTEDeviceLanguageFinnish    = 98,       //芬兰语
    UTEDeviceLanguageVietnam    = 99,       //越南语
    UTEDeviceLanguageIsiZulu    = 100,      //祖鲁语
    UTEDeviceLanguageMongolia   = 101,      //蒙古语
    
    UTEDeviceLanguageOther      = UTEDeviceLanguageEnglish, //other
};


/*!
 *  @enum UTEDeviceSleepAuxType
 *
 *  @discussion Sleep assist function
 *
 */
typedef NS_ENUM(NSInteger, UTEDeviceSleepAuxType) {
    UTEDeviceSleepAuxTypeDefault  = 0,
    UTEDeviceSleepAuxTypeOpen     = 1,
    UTEDeviceSleepAuxTypeClose    = -1,
};

/*!
 *  @enum UTEDeviceRemindEnableType
 */
typedef NS_ENUM(NSInteger, UTEDeviceRemindEnableType) {
    UTEDeviceRemindDefault  = 0,
    UTEDeviceRemindOpen     = 1,
    UTEDeviceRemindClose    = -1,
};

/*!
 *  @enum UTEDeviceSleepStatus
 */
typedef NS_ENUM(NSInteger, UTEDeviceSleepStatus) {
    UTEDeviceSleepStatusOpen ,
    UTEDeviceSleepStatusClose,
};

/*!
 *  @enum UTEDeviceSleepTimeType
 *
 *  @discussion Type of sleep
 *
 */
typedef NS_ENUM(NSInteger, UTEDeviceSleepTimeType) {
    UTEDeviceSleepTimeTypeSiesta,      //Daytime nap
    UTEDeviceSleepTimeTypeNight,       //Sleep at night
};

/*!
 *  @enum UTEDeviceBallType
 */
typedef NS_ENUM(NSInteger, UTEDeviceBallType) {
    UTEDeviceBallTypeTableTennis  = 1,
    UTEDeviceBallTypeBadminton,
    UTEDeviceBallTypeTennis,
};

/*!
 *  @enum UTEDeviceCustomUIType
 *
 *  @discussion Which interface is set to show or hide
 *
 */
typedef NS_ENUM(NSInteger, UTEDeviceCustomUIType) {
    UTEDeviceCustomUITypeBloodPressure   = 0,
    UTEDeviceCustomUITypeHRM                ,
    UTEDeviceCustomUITypeBloodOxygen        ,
    UTEDeviceCustomUITypeCalorie            ,
    UTEDeviceCustomUITypeDistance           ,
    UTEDeviceCustomUITypeWeather            ,
    UTEDeviceCustomUITypeSMS                ,
    UTEDeviceCustomUITypeFunction           ,
    
    UTEDeviceCustomUITypeSteps              ,
    UTEDeviceCustomUITypeRopeSkipping       ,
    UTEDeviceCustomUITypeSwimming           ,
    UTEDeviceCustomUITypeCycling            ,
    UTEDeviceCustomUITypeTableTennis        ,
    UTEDeviceCustomUITypeBadminton          ,
    UTEDeviceCustomUITypeTennis             ,
    UTEDeviceCustomUITypeRunning            ,
    
    UTEDeviceCustomUITypeGPS                ,
    UTEDeviceCustomUITypeInfo               ,
    UTEDeviceCustomUITypeFindPhone          ,
    UTEDeviceCustomUITypeNoDisturbing       ,
    UTEDeviceCustomUITypePowerOff           ,
    UTEDeviceCustomUITypeReset              ,
    UTEDeviceCustomUITypeECG                ,
    UTEDeviceCustomUITypeBloodGlucose       ,
    
    UTEDeviceCustomUITypeTramp              ,
    UTEDeviceCustomUITypeBasketball         ,
    UTEDeviceCustomUITypeSoccer_USA         ,
    UTEDeviceCustomUITypeBaseball           ,
    UTEDeviceCustomUITypeVolleyball         ,
    UTEDeviceCustomUITypeCricket            ,
    UTEDeviceCustomUITypeFootball_USA       , //American football
    UTEDeviceCustomUITypeDance              ,
    
    UTEDeviceCustomUITypeMountaineering     ,
    UTEDeviceCustomUITypeSpinningCycling    ,
    UTEDeviceCustomUITypeYoga               ,
    UTEDeviceCustomUITypeSit_Ups            ,
    UTEDeviceCustomUITypeTreadmill          ,
    UTEDeviceCustomUITypeGymnastics         ,
    UTEDeviceCustomUITypeBoating            ,
    UTEDeviceCustomUITypeJumping_Jacks      ,
    
    UTEDeviceCustomUITypeStopwatch          ,
    UTEDeviceCustomUITypeBodyFat            ,
    UTEDeviceCustomUITypeHockey             ,
    
};

/*!
 *  @enum UTEDeviceGPSStatus
 */
typedef NS_ENUM(NSInteger, UTEDeviceGPSStatus) {
    UTEDeviceGPSStatusClose,
    UTEDeviceGPSStatusCloseAndFull,     //GPS is off and The device's GPS data storage data is full. It is recommended to synchronize the GPS data,send the command UTEOptionDeleteGPSData to delete the GPS data of the device.
    UTEDeviceGPSStatusSearch,           //Searching for satellites
    UTEDeviceGPSStatusLocate,           //Positioning success
    
};

/*!
 *  @enum UTEDeviceMsgType
 */
typedef NS_ENUM(NSInteger, UTEDeviceMsgType) {
    UTEDeviceMsgTypeOther,
};

/*!
 *  @enum UTEDeviceAlertType
 *
 *  @discussion When the application is in the background and interacts with the device, the system prompts the system dialog
 *  Note:This is useful for applications that have not specified background mode and cannot display their own alert. If more than one application has requested notification for a given device, the one that was most recently in the foreground will receive the alert.
 *
 */
typedef NS_ENUM(NSInteger, UTEDeviceAlertType) {
    UTEDeviceAlertTypeNone            = 0,      //Default, no system prompt box will pop up
    UTEDeviceAlertTypeConnect         = 1 << 0, //indicating that the system should display a connection alert for a given device, if the application is suspended when a successful connection is made.
    UTEDeviceAlertTypeDisconnect      = 1 << 1, //indicating that the system should display a disconnection alert for a given device, if the application is suspended at the time of the disconnection.
    UTEDeviceAlertTypeCommunicate     = 1 << 2, //indicating that the system should display an alert for all notifications received from a device peripheral, if the application is suspended at the time.
    UTEDeviceAlertTypeRequiresANCS    = 1 << 3, //indicating that the ANCS (Apple Notification Center Service) is required for the device is connected.  If there is a response, method uteManagerANCSAuthorization: will be called.
};

/*!
 *  @enum UTEDeviceDataType
 */
typedef NS_ENUM(NSInteger, UTEDeviceDataType) {
    UTEDeviceDataTypeSteps             , //Number of steps
    UTEDeviceDataTypeSleep             , //Sleep at night
    UTEDeviceDataTypeHRM               , //Includes static and dynamic heart rate
    UTEDeviceDataTypeHRM24             , //Heart rate measured 24 hours a day
    UTEDeviceDataTypeBlood             ,
    UTEDeviceDataTypeBloodOxygen       , //If you want to sync historical data, please invoke method setUTEOption:
    UTEDeviceDataTypeRespiration       ,
    UTEDeviceDataTypeSkipping          ,
    UTEDeviceDataTypeSwiming           ,
    UTEDeviceDataTypeBicycle           ,
    UTEDeviceDataTypeBall              , //Includes badminton、table tennis、tennis
    UTEDeviceDataTypeSportHRM          , //Required: isHasSportHRM=YES
    UTEDeviceDataTypeGPS               , //If you want to sync historical data, please invoke method syncDataGPS:
    UTEDeviceDataTypeBodyFat           ,
    UTEDeviceDataTypeECG               , //If you want to sync historical data, please invoke method setUTEOption:
    UTEDeviceDataTypeMPF               , //Mood and Pressure、Fatigue
    UTEDeviceDataTypeSportTime         , //Required: isHasSportTimeGoal=YES . Activity time for more sports
};

/*!
 *  @enum UTEDeviceScreenType
 */
typedef NS_ENUM(NSInteger, UTEDeviceScreenType) {
    UTEDeviceScreenTypeCircle           ,
    UTEDeviceScreenTypeSquare           ,
    
};

/*!
 *  @enum UTEDeviceDisplayMode
 */
typedef NS_ENUM(NSInteger, UTEDeviceDisplayMode) {
    UTEDeviceDisplayModeDigital     = 1,
    UTEDeviceDisplayModePointer        ,
    
};

/*!
 *  @enum UTEDeviceSportMode
 *
 *  @discussion Required isHasSportHRM = YES
 *
 */
typedef NS_ENUM(NSInteger, UTEDeviceSportMode) {
    UTEDeviceSportModeNone               ,
    
    UTEDeviceSportModeRunning            ,
    UTEDeviceSportModeCycling            ,
    UTEDeviceSportModeRopeSkipping       ,
    UTEDeviceSportModeSwimming           ,
    UTEDeviceSportModeBadminton          ,
    UTEDeviceSportModeTableTennis        ,
    UTEDeviceSportModeTennis             ,
    UTEDeviceSportModeMountaineering     ,
    UTEDeviceSportModeWalking            ,
    UTEDeviceSportModeBasketball         ,
    
    UTEDeviceSportModeSoccer_USA         ,
    UTEDeviceSportModeBaseball           ,
    UTEDeviceSportModeVolleyball         ,
    UTEDeviceSportModeCricket            ,
    UTEDeviceSportModeFootball_USA       , //American football
    UTEDeviceSportModeHockey             ,
    UTEDeviceSportModeDance              ,
    UTEDeviceSportModeSpinningCycling    ,
    UTEDeviceSportModeYoga               ,
    UTEDeviceSportModeSit_Ups            ,
    
    UTEDeviceSportModeTreadmill          ,
    UTEDeviceSportModeGymnastics         ,
    UTEDeviceSportModeBoating            ,
    UTEDeviceSportModeJumping_Jacks      ,
    UTEDeviceSportModeFree               , //Custom training
    
    //When UTEModelDevices.isHasMoreSportType = YES, the device additionally supports all the following sports.
    UTEDeviceSportModeIndoorWalking         = 26,
    UTEDeviceSportModeIndoorRunning         = 27,
    UTEDeviceSportModeStrengthTraining      = 28,
    UTEDeviceSportModeStepping              = 29,
    UTEDeviceSportModeHorseRiding           = 30,
    
    UTEDeviceSportModeEllipticalTrainer     = 31,
    UTEDeviceSportModeTaiChi                = 32,
    UTEDeviceSportModeShuttlecock           = 33,
    UTEDeviceSportModeBoxing                = 34,
    UTEDeviceSportModeOutdoorWalking        = 35,
    UTEDeviceSportModeTrailRunning          = 36,
    UTEDeviceSportModeSkiing                = 37,
    UTEDeviceSportModeIceHockey             = 38,
    UTEDeviceSportModeTaekwondo             = 39,
    
    UTEDeviceSportModeVO2maxTest            = 40,
    UTEDeviceSportModeRowingMachine         = 41,
    UTEDeviceSportModeWalkingMachine        = 42,
    UTEDeviceSportModeHiking                = 43,
    UTEDeviceSportModeAthletics             = 44,
    UTEDeviceSportModeWaistTraining         = 45,
    UTEDeviceSportModeKarate                = 46,
    UTEDeviceSportModeCoolDown              = 47,
    UTEDeviceSportModeCrossTraining         = 48,
    UTEDeviceSportModePilates               = 49,
    
    UTEDeviceSportModeCrossFit              = 50,
    UTEDeviceSportModeFunctionalTraining    = 51,
    UTEDeviceSportModePhysicalTraining      = 52,
    UTEDeviceSportModeArchery               = 53,
    UTEDeviceSportModeFlexibility           = 54,
    UTEDeviceSportModeMixedCardio           = 55,
    UTEDeviceSportModeLatinDance            = 56,
    UTEDeviceSportModeStreetDance           = 57,
    UTEDeviceSportModeKickboxing            = 58,
    UTEDeviceSportModeBarre                 = 59,
    
    UTEDeviceSportModeAustralianFootball    = 60,
    UTEDeviceSportModeMartialArts           = 61,
    UTEDeviceSportModeClimbStairs           = 62,
    UTEDeviceSportModeHandball              = 63,
    UTEDeviceSportModeBowling               = 64,
    UTEDeviceSportModeSquash                = 65,
    UTEDeviceSportModeCurling               = 66,
    UTEDeviceSportModeHunting               = 67,
    UTEDeviceSportModeSnowboarding          = 68,
    UTEDeviceSportModeLeisure               = 69,
    
    UTEDeviceSportModeAmericanFootball      = 70,
    UTEDeviceSportModeHandcycling           = 71,
    UTEDeviceSportModeFishing               = 72,
    UTEDeviceSportModeFrisbee               = 73,
    UTEDeviceSportModeRugby                 = 74,
    UTEDeviceSportModeGolf                  = 75,
    UTEDeviceSportModeFolkDance             = 76,
    UTEDeviceSportModeDownhillSkiing        = 77,
    UTEDeviceSportModeSnow_Sports           = 78,
    UTEDeviceSportModeMeditation            = 79,
    
    UTEDeviceSportModeCoreTraining          = 80,
    UTEDeviceSportModeSkating               = 81,
    UTEDeviceSportModeFitnessGame           = 82,
    UTEDeviceSportModeAerobics              = 83,
    UTEDeviceSportModeGroupGymnastics       = 84,
    UTEDeviceSportModeKickboxingGymnastics  = 85,
    UTEDeviceSportModeLacrosse              = 86,
    UTEDeviceSportModeFoamRoller            = 87,
    UTEDeviceSportModeWrestling             = 88,
    UTEDeviceSportModeFencing               = 89,
    
    UTEDeviceSportModeSoftball              = 90,
    UTEDeviceSportModeHorizontalBar         = 91,
    UTEDeviceSportModeParallelBars          = 92,
    UTEDeviceSportModeRollerSkating         = 93,
    UTEDeviceSportModeHulaHoop              = 94,
    UTEDeviceSportModeDarts                 = 95,
    UTEDeviceSportModePickleball            = 96,
    UTEDeviceSportModeHIIT                  = 97,
    UTEDeviceSportModeShoot                 = 98,
    UTEDeviceSportModeJudo                  = 99,
    
    UTEDeviceSportModeTrampoline            = 100,
    UTEDeviceSportModeSkateboard            = 101,
    UTEDeviceSportModeHoverboard            = 102,
    UTEDeviceSportModeBlading               = 103,
    UTEDeviceSportModeParkour               = 104,
    UTEDeviceSportModeDiving                = 105,
    UTEDeviceSportModeSurfing               = 106,
    UTEDeviceSportModeSnorkeling            = 107,
    UTEDeviceSportModePull_ups              = 108,
    UTEDeviceSportModePush_ups              = 109,
    
    UTEDeviceSportModePlank                 = 110,
    UTEDeviceSportModeRockClimbing          = 111,
    UTEDeviceSportModeHighJump              = 112,
    UTEDeviceSportModeBungeeJumping         = 113,
    UTEDeviceSportModeLongJump              = 114,
    UTEDeviceSportModeMarathon              = 115,
    UTEDeviceSportModeFlexibilityTraining   = 116,
    UTEDeviceSportModeSideplank             = 117,
    UTEDeviceSportModeBeachFootball         = 118,
    UTEDeviceSportModeBeachVolleyball       = 119,
    
    UTEDeviceSportModeBellyDance            = 120,
    UTEDeviceSportModeBiathlon              = 121,
    UTEDeviceSportModeBilliards             = 122,
    UTEDeviceSportModeBMXBike               = 123,
    UTEDeviceSportModeCrossCountrySkiing    = 124,
    UTEDeviceSportModeTugOfWar              = 125,
    UTEDeviceSportModeDodgeBall             = 126,
    UTEDeviceSportModeDragonBoat            = 127,
    UTEDeviceSportModeDrifing               = 128,
    UTEDeviceSportModeEnduranceRun          = 139,
    
    UTEDeviceSportModeFatBurnRun            = 130,
    UTEDeviceSportModeFlyKite               = 131,
    UTEDeviceSportModeGateBall              = 132,
    UTEDeviceSportModeGolfDrivingRangeMode  = 133,
    UTEDeviceSportModeIndoorBike            = 134,
    UTEDeviceSportModeJazz                  = 135,
    UTEDeviceSportModeJetFootball           = 136,
    UTEDeviceSportModeKayaking              = 137,
    UTEDeviceSportModeKickBoxing            = 138,
    UTEDeviceSportModeMotorBoat             = 139,
    
    UTEDeviceSportModeObstacle              = 140,
    UTEDeviceSportModeOpenWaterSwimming     = 141,
    UTEDeviceSportModeOrienteering          = 142,
    UTEDeviceSportModePaddleBoardSufing     = 143,
    UTEDeviceSportModeParachute             = 144,
    UTEDeviceSportModeRacingBoat            = 145,
    UTEDeviceSportModeRacingCar             = 146,
    UTEDeviceSportModeSailboat              = 147,
    UTEDeviceSportModeSnowCar               = 148,
    UTEDeviceSportModeSquareDance           = 149,
    
    UTEDeviceSportModeSwing                 = 150,
    UTEDeviceSportModeTriathlon             = 151,
    UTEDeviceSportModeFitness               = 152,
    UTEDeviceSportModeKettlebellTraining    = 153,
    UTEDeviceSportModeMixedMartialArts      = 154,
    UTEDeviceSportModeWeightlifting         = 155,
    UTEDeviceSportModeTrackAndField         = 156,
    UTEDeviceSportModeSocialDance           = 157,
    UTEDeviceSportModeTapDancing            = 158,
    UTEDeviceSportModeEquestringSport       = 159,
    
    UTEDeviceSportModeWaterBalloon          = 160,
    UTEDeviceSportModePOLO                  = 161,
    UTEDeviceSportModePocketStickBall       = 162,
    UTEDeviceSportModeScooter               = 163,
    UTEDeviceSportModeParaglder             = 164,
    UTEDeviceSportModeBattleGame            = 165,
    UTEDeviceSportModeIndoorRunningOther    = 166,
    UTEDeviceSportModeGeneralExercise       = 167,
    UTEDeviceSportModeYogaCatStyle          = 168,
    UTEDeviceSportModeYogaCowStyle          = 169,
    
    UTEDeviceSportModeYogaCobarPose         = 170,
    UTEDeviceSportModeYogaHero1             = 171,
    UTEDeviceSportModeYogaHero2             = 172,
    UTEDeviceSportModeYogaHero3             = 173,
    UTEDeviceSportModeYogaRoller            = 174,
    UTEDeviceSportModeMixedFitness          = 175,
    UTEDeviceSportModeBoxingAerobics        = 176,
    UTEDeviceSportModeCyclicTraining        = 177,
    UTEDeviceSportModeAerbicTraining        = 178,
    UTEDeviceSportModeCallisthenice         = 179,
    
    UTEDeviceSportModeP90X                  = 180,
    UTEDeviceSportModeStairClimbingMachine  = 181,
    UTEDeviceSportModeBallet                = 182,
    UTEDeviceSportModeHandwheel             = 183,
    UTEDeviceSportModeMindBodyExercise      = 184,
    UTEDeviceSportModeSoftnessExercises     = 185,
    UTEDeviceSportModeMixedAerobic          = 186,
    UTEDeviceSportModeTraditionStrenghtTraining = 187,
    UTEDeviceSportModeLadderTraining        = 188,
    UTEDeviceSportModeGeneralDance          = 189,
    
    UTEDeviceSportModeZumbaDance            = 190,
    UTEDeviceSportModeGeneralLeisureSports  = 191,
    UTEDeviceSportModeTeamSport             = 192,
    UTEDeviceSportModeFitnessVideoGames     = 193,
    UTEDeviceSportModeGeneralBallGames      = 194,
    UTEDeviceSportModeGolfBall              = 195,
    UTEDeviceSportModeAmericanSquash        = 196,
    UTEDeviceSportModeEnglishRugby          = 197,
    UTEDeviceSportModeGeneralWaterActivities= 198,
    UTEDeviceSportModeCanoe                 = 199,
    
    UTEDeviceSportModeJetSki                = 200,
    UTEDeviceSportModeGroundWater           = 201,
    UTEDeviceSportModeParagliderSurfing     = 202,
    UTEDeviceSportModeSurfingAndWaterSkiing = 203,
    UTEDeviceSportModeWindsurfing           = 204,
    UTEDeviceSportModeUnderWaterFitness     = 205,
    UTEDeviceSportModeWaterSports           = 206,
    UTEDeviceSportModeFreestyleSwimming     = 207,
    UTEDeviceSportModeBreastStroke          = 208,
    UTEDeviceSportModeBackstroke            = 209,
    
    UTEDeviceSportModeButterflyStroke       = 210,
    UTEDeviceSportModeGeneralIceSport       = 211,
    UTEDeviceSportModeSled                  = 212,
    UTEDeviceSportModeSnowShoeHiking        = 213,
    UTEDeviceSportModeGeneralExtremeSport   = 214,
    UTEDeviceSportModeTakeElevator          = 215,
    UTEDeviceSportModeTakeEscalator         = 216,
    UTEDeviceSportModeGardening             = 217,
    UTEDeviceSportModeDoingHousehold        = 218,
    UTEDeviceSportModeInTheCar              = 219,
    
    UTEDeviceSportModeMeditationType        = 220,
    UTEDeviceSportModeStatic                = 221,
    UTEDeviceSportModeTilt                  = 222,
    UTEDeviceSportModeWheelChairMobility    = 223,
    
    
};

/*!
 *  @enum UTEDeviceIntervalTime
 */
typedef NS_ENUM(NSInteger, UTEDeviceIntervalTime) {
    UTEDeviceIntervalTime10s            = 10,  //10 seconds
    UTEDeviceIntervalTime20s            = 20,  //20 seconds
    UTEDeviceIntervalTime30s            = 30,  //30 seconds
    UTEDeviceIntervalTime1min           = 60,  //1 minute
    UTEDeviceIntervalTime2min           = 120, //2 minute
    UTEDeviceIntervalTime3min           = 180, //3 minute
    UTEDeviceIntervalTime4min           = 240, //4 minute
    UTEDeviceIntervalTime5min           = 300, //5 minute
};

/*!
 *  @enum UTEDeviceFactoryType
 */
typedef NS_ENUM(NSInteger, UTEDeviceFactoryType) {
    UTEDeviceFactoryTypePressure,
    UTEDeviceFactoryTypePower,
};

/*!
 *  @enum UTEDeviceShortcutBtnType
 *
 *  @discussion Device shortcut button type
 *  It is recommended to use UTEModelShortcutBtn ( Support more than 8 types ), See uteManagerShortcutBtnSupportModel:
 *
 */
typedef NS_ENUM(NSInteger, UTEDeviceShortcutBtnType) {
    UTEDeviceShortcutBtnTypeFindBand        = 1 << 0,    //Button:‘Find device’
    UTEDeviceShortcutBtnTypeHandlight       = 1 << 1,    //Button:Lift your wrist and the device screen lights up
    UTEDeviceShortcutBtnTypeSitRemind       = 1 << 2,    //Button:After sitting for a long time, the device will vibrate to remind.
    UTEDeviceShortcutBtnTypeSilence         = 1 << 3,    //Button:Device Do Not Disturb Mode
    UTEDeviceShortcutBtnTypeSmartLost       = 1 << 4,    //Button:Device anti-lost function
    UTEDeviceShortcutBtnTypeSMSRemind       = 1 << 5,    //Button:SMS reminder
    UTEDeviceShortcutBtnTypeHRM24h          = 1 << 6,    //Button:Heart rate measured 24 hours a day
    UTEDeviceShortcutBtnTypeLightTime       = 1 << 7,    //Button:Control the duration of screen brightness
    UTEDeviceShortcutBtnTypeVibration       = 1 << 8,    //Button:Vibration intensity of equipment motor
};

/*!
 *  @enum UTEDeviceSportModeStatus
 */
typedef NS_ENUM(NSInteger, UTEDeviceSportModeStatus) {
    UTEDeviceSportModeStatusClose,
    UTEDeviceSportModeStatusOpen,
    UTEDeviceSportModeStatusPause,                 //Required:isHasSportPause=YES
    UTEDeviceSportModeStatusContinue,              //Required:isHasSportPause=YES
};

/*!
 *  @enum UTEUserIDStatus
 *
 *  @discussion User id status
 *
 *  @constant UTEUserIDStatusRequired           Device needs a user id, please invoke setUTEUserID:
 *
 *  @constant UTEUserIDStatusOld                Indicates that the device has stored an User ID,
 *                                              When setting a different user id , device will pop up a dialog box requesting pairing,
 *                                              then user click the pairing button,some devices will reboot,
 *                                              please invoke connectUTEModelDevices: again.
 *
 *  @constant UTEUserIDStatusNew                Indicates that the device has not stored User ID , device will pop up a dialog box requesting pairing.
 *
 *  @constant UTEUserIDStatusVerifySuccess      Indicates that User ID is valid, device starts to connect.
 *
 *  @constant UTEUserIDStatusPaird              In the device interface, user click the pairing button,and the device starts to connect.
 *
 *  @constant UTEUserIDStatusPairdCancel        In the device interface, user click the cancel pairing button,
 *                                              the device will be disconnected directly.
 */
typedef NS_ENUM(NSInteger, UTEUserIDStatus) {
    UTEUserIDStatusRequired,
    UTEUserIDStatusOld,
    UTEUserIDStatusNew,
    UTEUserIDStatusVerifySuccess,
    UTEUserIDStatusPaird,
    UTEUserIDStatusPairdCancel,
};

typedef NS_ENUM(NSInteger, UTECommonTestTime) {
    UTECommonTestTime1Min = 1,              //The test interval is 1 minute .Only effective for body temperature
    
    UTECommonTestTime5Mins,                 //The test interval is 5 minutes.Only effective for body temperature
    //OR isHasHRM5mins = YES
    
    UTECommonTestTime10Mins,                //The test interval is 10 minutes
    UTECommonTestTime30Mins,                //The test interval is 30 minutes
    UTECommonTestTime1Hour,                 //The test interval is 1 hour
    UTECommonTestTime2Hours,                //The test interval is 2 hours
    UTECommonTestTime3Hours,                //The test interval is 3 hours
    UTECommonTestTime4Hours,                //The test interval is 4 hours
    UTECommonTestTime6Hours,                //The test interval is 6 hours
    
    UTECommonTestTimeAt_8,                  //Automatic test at 08:00 every day
    UTECommonTestTimeAt_8_20,               //Automatic test at 08:00/20:00 every day
    UTECommonTestTimeAt_8_14_20,            //Automatic test at 08:00/14:00/20:00 every day
};

typedef NS_ENUM(NSInteger, UTEDeviceApp) {
    UTEDeviceAppOther = 0, //Other apps not listed below
    UTEDeviceAppSMS,
    UTEDeviceAppQQ,
    UTEDeviceAppWechat,
    UTEDeviceAppPhone,
    UTEDeviceAppFacebook,
    UTEDeviceAppTwitter,
    UTEDeviceAppWhatsApp,
    UTEDeviceAppFacebookMessenger,
    UTEDeviceAppLine,
    UTEDeviceAppSkype,
    UTEDeviceAppHangouts,
    
    UTEDeviceAppLinkedin,
    UTEDeviceAppInstagram,
    UTEDeviceAppViber,
    UTEDeviceAppKakaoTalk,
    UTEDeviceAppVKontakte,
    UTEDeviceAppSnapchat,
    UTEDeviceAppGooglePlus,
    UTEDeviceAppGmail,
    UTEDeviceAppFlickr,
    UTEDeviceAppTumblr,
    UTEDeviceAppPinterest,
    UTEDeviceAppYouTube,
    UTEDeviceAppTelegram,
    UTEDeviceAppTruecaller,
    UTEDeviceAppPaytm,
    UTEDeviceAppZalo,
    UTEDeviceAppImo,
    UTEDeviceAppMicrosoftTeams,
    
    UTEDeviceAppMicrosoftOutlook,
    UTEDeviceAppSwiggy,
    UTEDeviceAppZomato,
    UTEDeviceAppGpay,
    UTEDeviceAppPhonePe,
    UTEDeviceAppHotstar,
    UTEDeviceAppPrimeVideo,
    UTEDeviceAppFlipkart,
    UTEDeviceAppAmazon,
    UTEDeviceAppMyntra,
    UTEDeviceAppNoiseFit,
    UTEDeviceAppDailyHunt,
    UTEDeviceAppInshorts,
    UTEDeviceAppBookMyShow,
    UTEDeviceAppAppleCalendar,
    UTEDeviceAppJioTV,
    UTEDeviceAppMakeMyTrip,
    UTEDeviceAppNetflix,
    UTEDeviceAppOla,
    UTEDeviceAppFastrackReflex,
    UTEDeviceAppUber,
    UTEDeviceAppYTMusic,
    
    UTEDeviceAppWhatsAppBusiness,
    UTEDeviceAppDunzo,
    UTEDeviceAppGaana,
    UTEDeviceAppGoogleDrive,
    UTEDeviceAppGoogleChat,
    UTEDeviceAppWynkMusic,
    UTEDeviceAppYahoo,
    UTEDeviceAppTitanSmartWorld,
    UTEDeviceAppSlack,
    UTEDeviceAppSpotify,
    UTEDeviceAppiOSMail,
};


typedef NS_ENUM(NSInteger, UTELogType) {
    UTELogTypePrint,         //Print log
    UTELogTypeSave,          //Log will be saved in the path "Documents/UTELog" folder.
    UTELogTypePrintAndSave,  //Log will be printed and saved in the path "Documents/UTELog" folder.
    //The format of the file name is yyyy-MM-dd, only the log of the last 7 days is saved, and one file per day.
};

typedef NS_ENUM(NSInteger, UTEGoalType) {
    UTEGoalTypeStanding   = 1,
    UTEGoalTypeActivity,
    UTEGoalTypeCalorie,
    UTEGoalTypeStep,
    UTEGoalTypeDistance,
    UTEGoalTypeSportTime, //Required:isHasSportTimeGoal=YES
};

typedef NS_ENUM(NSInteger, UTEMenuIcon) {
    UTEMenuIconStatus            = 1,
    UTEMenuIconSport,
    UTEMenuIconSportHistory,
    UTEMenuIconCall,
    UTEMenuIconHRM,
    UTEMenuIconBlood,
    UTEMenuIconBloodOxygen,
    UTEMenuIconMusic,
    UTEMenuIconBodyTemperature,
    UTEMenuIconMessage,
    UTEMenuIconPressure,
    UTEMenuIconSleep,
    UTEMenuIconWeather,
    UTEMenuIconBreathingTraining,
    UTEMenuIconBreathingRate,
    UTEMenuIconStopwatch,
    UTEMenuIconCountdown,
    UTEMenuIconFindiPhone,
    UTEMenuIconClock,
    UTEMenuIconCamera,
    UTEMenuIconFlashlight,
    UTEMenuIconSetting,
    UTEMenuIconMore,
    UTEMenuIconDialSelect,
    UTEMenuIconMenstrual,
    UTEMenuIconTheme,
    UTEMenuIconShutdown,
    UTEMenuIconReboot,
    UTEMenuIconRestore,
    UTEMenuIconAbout,
    UTEMenuIconAlipay,
    UTEMenuIconWorldClock,
};

/*!
 *  @enum UTEDeviceBloodFeature
 *
 *  @discussion Blood pressure supports more functions
 *
 */
typedef NS_ENUM(NSInteger, UTEDeviceBloodFeature) {
    UTEDeviceBloodFeatureHRV                = 1 << 0,
    UTEDeviceBloodFeatureCardiovascular     = 1 << 1,
    UTEDeviceBloodFeatureLiquor             = 1 << 2,
    UTEDeviceBloodFeatureOverallRating      = 1 << 3,
    
};

/*!
 *  @enum UTEDeviceFemaleCycleType
 *
 *  @discussion Female Cycle Type
 *
 */
typedef NS_ENUM(NSInteger, UTEDeviceFemaleCycleType) {
    UTEDeviceFemaleCycleTypeSafe,
    UTEDeviceFemaleCycleTypeMenstruation,
    UTEDeviceFemaleCycleTypeOvulation,
    
};

/*!
 *  @enum UTEDeviceSportTimeCategory
 *
 *  @discussion Sports are divided into several categories
 *
 */
typedef NS_ENUM(NSInteger, UTEDeviceSportTimeCategory) {
    UTEDeviceSportTimeCategoryDaily,
    UTEDeviceSportTimeCategoryRunning,
    UTEDeviceSportTimeCategoryWalking,
    UTEDeviceSportTimeCategorySwimming,
    UTEDeviceSportTimeCategoryCycling,
    UTEDeviceSportTimeCategoryOutdoor,
    UTEDeviceSportTimeCategoryFitness,
    UTEDeviceSportTimeCategoryBall,
    UTEDeviceSportTimeCategoryYoga,
    UTEDeviceSportTimeCategoryAquatic,
    UTEDeviceSportTimeCategorySnow,
    UTEDeviceSportTimeCategoryLeisure,
    UTEDeviceSportTimeCategoryOther,
    
};

/*!
 *  @enum UTEDeviceCRType
 *
 *  @discussion Sports are divided into several categories
 *
 */
typedef NS_ENUM(NSInteger, UTEDeviceCRType) {
    UTEDeviceCRTypeNone,
    UTEDeviceCRTypeSinusRhythm,
    UTEDeviceCRTypeSychnosphygmia,
    UTEDeviceCRTypeBradycardia,
    UTEDeviceCRTypeArrhythmiaIntermittent,
    UTEDeviceCRTypeArrhythmiaContinuous,
    UTEDeviceCRTypeArrhythmiaSerious,
};

/*!
 *  @enum UTEDeviceFRQFirmwareType
 *
 *  @discussion Firmware Type
 *
 */
typedef NS_ENUM(NSInteger, UTEDeviceFRQFirmwareType) {
    UTEDeviceFRQFirmwareTypeM3,
    UTEDeviceFRQFirmwareTypeDsp,
};

/*!
 *  @enum UTEDeviceSwimType
 *
 *  @discussion Swim Type
 */
typedef NS_ENUM(NSInteger, UTEDeviceSwimType) {
    UTEDeviceSwimTypeUnknown,
    UTEDeviceSwimTypeFreeStyle,
    UTEDeviceSwimTypeBreastStroke,
    UTEDeviceSwimTypeBackStroke,
    UTEDeviceSwimTypeButterflyStroke,
    UTEDeviceSwimTypeMedley,
};

/*!
 *  @enum UTEContactWakeupType
 */
typedef NS_ENUM(NSInteger, UTEContactWakeupType) {
    UTEContactWakeupTypeNoContacts,
    UTEContactWakeupTypeFail,
    UTEContactWakeupTypeSuccess,
};

/*!
 *  @enum UTEBloodTestType
 */
typedef NS_ENUM(NSInteger, UTEBloodTestType) {
    UTEBloodTestTypePPG = 1,
    UTEBloodTestTypeMiddle,
    
};

/*!
 *  @enum UTEOffScreenDisplayType
 */
typedef NS_ENUM(NSInteger, UTEOffScreenDisplayType) {
    UTEOffScreenDisplayTypeOff,
    UTEOffScreenDisplayTypeOn,
    UTEOffScreenDisplayTypeTimeRange,
};

typedef NS_ENUM(NSInteger, UTERYDialType) {
    UTERYDialTypeCurrent         = 0x01,
    UTERYDialTypePreset          = 0x02,
    UTERYDialTypeDelete          = 0x04,
    UTERYDialTypeCustom          = 0x08,
    UTERYDialTypeGooglePre       = 0x10,
    UTERYDialTypePhoto           = 0x20,
    
};

typedef NS_ENUM(NSInteger, UTERYDialOperate) {
    UTERYDialOperateApply   = 1,
    UTERYDialOperateDelete  = 2,
    UTERYDialOperateGoogle  = 3, //Temporarily invalid
};

typedef NS_ENUM(NSInteger, UTEPrayType) {
    UTEPrayTypeFajr,        //observed at dawn
    UTEPrayTypeZuhr,        //observed at noon
    UTEPrayTypeAsr,         //observed late in the afternoon
    UTEPrayTypeMaghrib,     //observed after sunset
    UTEPrayTypeIsha,        //observed at dusk
};

typedef NS_ENUM(NSInteger, UTETimePosition) {
    UTETimePositionUp           = 0x01,
    UTETimePositionDown         = 0x02,
    UTETimePositionLeft         = 0x03,
    UTETimePositionRight        = 0x04,
};

typedef NS_ENUM(NSInteger, UTEECGResultType) {
    UTEECGResultTypeNormal,                 //CN:正常
    UTEECGResultTypePVCSingle,              //CN:单发室性早搏
    UTEECGResultTypePVCDouble,              //CN:成对室性早搏
    UTEECGResultTypePVCTwoCoupletLaw,       //CN:室性早搏二联律
    UTEECGResultTypePVCThreeCoupletLaw,     //CN:室性早搏三联律
    UTEECGResultTypePVCSingleUp,            //CN:单发室上性早搏
    UTEECGResultTypePVCDoubleUp,            //CN:成对室上性早搏
    UTEECGResultTypePVCTwoCoupletLawUp,     //CN:室上性早搏二联律
    UTEECGResultTypePVCThreeCoupletLawUp,   //CN:室上性早搏三联律
    UTEECGResultTypeCardiacArrest,          //CardiacArrest CN:停博
    UTEECGResultTypeHeartArrhythmia,        //HeartArrhythmia CN:心率不齐
    UTEECGResultTypeTachycardia,            //Tachycardia CN:心动过速
    UTEECGResultTypeBradycardia,            //Bradycardia CN:心动过缓
    UTEECGResultTypePSVT,                   //Paroxysmal Supraventricular Tachycardia CN:阵发性室上性心动过速
    UTEECGResultTypePT,                     //Paroxysmal Tachycardia CN:阵发性室性心动过速
    UTEECGResultTypePES,                    //Pre-excitation Syndromes CN:预激综合症
    UTEECGResultTypeSET,                    //Suspected Extreme Tachycardia CN:疑似极度心动过速
    UTEECGResultTypeSEB,                    //Suspected Extreme Bradycardia CN:疑似极度心动过缓
};

typedef NS_ENUM(NSInteger, UTECurrencyType) {
    UTECurrencyTypeCNY,
    UTECurrencyTypeUSD,
    
};

typedef NS_ENUM(NSInteger, UTEPayStatus) {
    UTEPayStatusUndefined,
    UTEPayStatusPaid,
    UTEPayStatusRefunded,
    UTEPayStatusProcessing,
};


@end

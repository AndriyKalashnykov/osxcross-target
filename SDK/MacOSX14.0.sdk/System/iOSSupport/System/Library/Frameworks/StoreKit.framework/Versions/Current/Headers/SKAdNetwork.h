//
//  SKAdNetwork.h
//  StoreKit
//
//  Copyright © 2017 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKitDefines.h>
#import <StoreKit/SKAdImpression.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString * SKAdNetworkCoarseConversionValue NS_TYPED_ENUM NS_SWIFT_NAME(SKAdNetwork.CoarseConversionValue) API_AVAILABLE(ios(16.1)) API_UNAVAILABLE(macos,watchos,visionos) __TVOS_PROHIBITED;

SK_EXTERN SKAdNetworkCoarseConversionValue const SKAdNetworkCoarseConversionValueHigh  API_AVAILABLE(ios(16.1)) API_UNAVAILABLE(macos,watchos,visionos) __TVOS_PROHIBITED;
SK_EXTERN SKAdNetworkCoarseConversionValue const SKAdNetworkCoarseConversionValueMedium  API_AVAILABLE(ios(16.1)) API_UNAVAILABLE(macos,watchos,visionos) __TVOS_PROHIBITED;
SK_EXTERN SKAdNetworkCoarseConversionValue const SKAdNetworkCoarseConversionValueLow  API_AVAILABLE(ios(16.1)) API_UNAVAILABLE(macos,watchos,visionos) __TVOS_PROHIBITED;

SK_EXTERN_CLASS API_AVAILABLE(ios(11.3)) API_UNAVAILABLE(macos, watchos, visionos) __TVOS_PROHIBITED @interface SKAdNetwork : NSObject

// Source apps should call these methods for performing a non-mediated attribution
+ (void)startImpression:(SKAdImpression *)impression completionHandler:(nullable void (^)(NSError *__nullable error))completion NS_SWIFT_NAME(startImpression(_:completionHandler:)) API_AVAILABLE(ios(14.5)) API_UNAVAILABLE(macos, watchos, visionos) __TVOS_PROHIBITED;

+ (void)endImpression:(SKAdImpression *)impression completionHandler:(nullable void (^)(NSError *__nullable error))completion NS_SWIFT_NAME(endImpression(_:completionHandler:)) API_AVAILABLE(ios(14.5)) API_UNAVAILABLE(macos, watchos, visionos) __TVOS_PROHIBITED;

// Participating apps should call this on launch to complete the install+open action associated with a product view
+ (void)registerAppForAdNetworkAttribution API_DEPRECATED("Use updatePostbackConversionValue:completionHandler: instead", ios(11.3, 15.4))  API_UNAVAILABLE(macos, watchos, visionos) __TVOS_PROHIBITED;

+ (void)updateConversionValue:(NSInteger)conversionValue API_DEPRECATED("Use updatePostbackConversionValue:completionHandler: instead", ios(14.0, 15.4))  API_UNAVAILABLE(macos, watchos, visionos) __TVOS_PROHIBITED;

+ (void)updatePostbackConversionValue:(NSInteger)conversionValue completionHandler:(nullable void (^)(NSError *__nullable error))completion API_AVAILABLE(ios(15.4))  API_UNAVAILABLE(macos, watchos, visionos) __TVOS_PROHIBITED;

+ (void)updatePostbackConversionValue:(NSInteger)fineValue coarseValue:(SKAdNetworkCoarseConversionValue)coarseValue completionHandler:(nullable void (^)(NSError *__nullable error))completion API_AVAILABLE(ios(16.1)) API_UNAVAILABLE(macos,watchos,visionos) __TVOS_PROHIBITED;

+ (void)updatePostbackConversionValue:(NSInteger)fineValue coarseValue:(SKAdNetworkCoarseConversionValue)coarseValue lockWindow:(BOOL)lockWindow completionHandler:(nullable void (^)(NSError *__nullable error))completion API_AVAILABLE(ios(16.1)) API_UNAVAILABLE(macos,watchos,visionos) __TVOS_PROHIBITED;

@end

// Constants for use with SKStoreProductViewController to associate a product view with an install+open

// Advertising network's cryptographic signature for the atribution params (NSString)
SK_EXTERN NSString * const SKStoreProductParameterAdNetworkAttributionSignature API_AVAILABLE(ios(11.3)) API_UNAVAILABLE(macos, watchos, visionos);

// Advertising network campaign identifier (NSNumber)
SK_EXTERN NSString * const SKStoreProductParameterAdNetworkCampaignIdentifier API_AVAILABLE(ios(11.3)) API_UNAVAILABLE(macos, watchos, visionos);

SK_EXTERN NSString * const SKStoreProductParameterAdNetworkSourceIdentifier API_AVAILABLE(ios(16.1)) API_UNAVAILABLE(macos, watchos, visionos);

// Advertising network identifier (NSString)
SK_EXTERN NSString * const SKStoreProductParameterAdNetworkIdentifier API_AVAILABLE(ios(11.3)) API_UNAVAILABLE(macos, watchos, visionos);

// Random entropy value for security (NSUUID)
SK_EXTERN NSString * const SKStoreProductParameterAdNetworkNonce API_AVAILABLE(ios(11.3)) API_UNAVAILABLE(macos, watchos, visionos);

// Timestamp for this ad impression (NSNumber)
SK_EXTERN NSString * const SKStoreProductParameterAdNetworkTimestamp API_AVAILABLE(ios(11.3)) API_UNAVAILABLE(macos, watchos, visionos);

// App Store item identifier of the source app (NSNumber)
SK_EXTERN NSString * const SKStoreProductParameterAdNetworkSourceAppStoreIdentifier API_AVAILABLE(ios(14.0)) API_UNAVAILABLE(macos, watchos, visionos);

SK_EXTERN NSString * const SKStoreProductParameterAdNetworkVersion API_AVAILABLE(ios(14.0)) API_UNAVAILABLE(macos, watchos, visionos);

NS_ASSUME_NONNULL_END

//
//  MKPinAnnotationView.h
//  MapKit
//
//  Copyright (c) 2009-2014, Apple Inc. All rights reserved.
//

#import <MapKit/MKFoundation.h>

#if MK_SUPPORTS_VIEW_CLASSES

#import <MapKit/MKAnnotationView.h>

typedef NS_ENUM(NSUInteger, MKPinAnnotationColor) {
    MKPinAnnotationColorRed = 0,
    MKPinAnnotationColorGreen,
    MKPinAnnotationColorPurple
} NS_ENUM_DEPRECATED(10_9, 10_11, 3_0, 9_0, "Use MKPinAnnotationView's pinTintColor instead")
#if defined(TARGET_OS_VISION) && TARGET_OS_VISION
API_UNAVAILABLE(visionos);
#else
API_UNAVAILABLE(tvos) API_UNAVAILABLE(watchos);
#endif

NS_ASSUME_NONNULL_BEGIN

API_DEPRECATED_WITH_REPLACEMENT("MKMarkerAnnotationView", macos(10.9, 13.0), ios(3.0, 16.0), tvos(9.2, 16.0))
API_UNAVAILABLE(watchos)
@interface MKPinAnnotationView : MKAnnotationView

#if TARGET_OS_IPHONE
+ (UIColor *)redPinColor NS_AVAILABLE(10_11, 9_0);
+ (UIColor *)greenPinColor NS_AVAILABLE(10_11, 9_0);
+ (UIColor *)purplePinColor NS_AVAILABLE(10_11, 9_0);
#else
+ (NSColor *)redPinColor NS_AVAILABLE(10_11, 9_0);
+ (NSColor *)greenPinColor NS_AVAILABLE(10_11, 9_0);
+ (NSColor *)purplePinColor NS_AVAILABLE(10_11, 9_0);
#endif

#if TARGET_OS_IPHONE
@property (NS_NONATOMIC_IOSONLY, strong, null_resettable) UIColor *pinTintColor NS_AVAILABLE(10_11, 9_0) UI_APPEARANCE_SELECTOR;
#else
@property (NS_NONATOMIC_IOSONLY, strong, null_resettable) NSColor *pinTintColor NS_AVAILABLE(10_11, 9_0);
#endif

@property (nonatomic) BOOL animatesDrop;

@property (nonatomic) MKPinAnnotationColor pinColor
#if defined(TARGET_OS_VISION) && TARGET_OS_VISION
API_UNAVAILABLE(visionos);
#else
NS_DEPRECATED(10_9, 10_11, 3_0, 9_0, "Use pinTintColor instead") API_UNAVAILABLE(tvos);
#endif

@end

NS_ASSUME_NONNULL_END

#endif // MK_SUPPORTS_VIEW_CLASSES

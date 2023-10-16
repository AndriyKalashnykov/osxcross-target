//
//  MPSGraphDevice.h
//  MetalPerformanceShadersGraph
//
//  Created on 11/12/19.
//  Copyright © 2019 Apple Inc. All rights reserved.
//

#ifndef MPSGraphDevice_h
#define MPSGraphDevice_h

#import <MetalPerformanceShadersGraph/MPSGraphCore.h>

NS_ASSUME_NONNULL_BEGIN

/// Device type
typedef NS_ENUM(uint32_t, MPSGraphDeviceType)
{
    /// Device of type Metal
    MPSGraphDeviceTypeMetal                            MPS_ENUM_AVAILABLE_STARTING(macos(11.0), ios(14.0), tvos(14.0)) MPS_SWIFT_NAME(metal)  =   0L,
};

MPS_CLASS_AVAILABLE_STARTING(macos(11.0), ios(14.0), tvos(14.0))
@interface MPSGraphDevice : MPSGraphObject

/// Device of the MPSGraphDevice.
@property (readonly, nonatomic) MPSGraphDeviceType type;

/// If device type is Metal then returns the corresponding MTLDevice else nil.
@property (readonly, nonatomic, nullable) id<MTLDevice> metalDevice;

/// Creates a device from given metal device.
///
/// - Parameters:
///   - metalDevice: `MTLDevice` to create an MPSGraphDevice from.
/// - Returns: A valid device.
///
+(instancetype) deviceWithMTLDevice:(id<MTLDevice>) metalDevice;

@end

NS_ASSUME_NONNULL_END

#endif /* MPSGraphDevice_h */

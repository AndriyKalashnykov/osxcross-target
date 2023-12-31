//
//  SKRequest.h
//  StoreKit
//
//  Copyright 2009 Apple, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

@protocol SKRequestDelegate;

// Base class used to fetch data from the store.  Should not be used directly.
SK_EXTERN_CLASS API_AVAILABLE(ios(3.0), macos(10.7), watchos(6.2), visionos(1.0)) NS_SWIFT_NONSENDABLE @interface SKRequest : NSObject {
@private
    id _requestInternal;
}

@property(nonatomic, weak, nullable) id <SKRequestDelegate> delegate API_AVAILABLE(ios(3.0), macos(10.7), watchos(6.2), visionos(1.0));

// Cancel the request if it has started.
- (void)cancel API_AVAILABLE(ios(3.0), macos(10.7), watchos(6.2), visionos(1.0));

// Start the request if it has not already been started.
- (void)start API_AVAILABLE(ios(3.0), macos(10.7), watchos(6.2), visionos(1.0));

@end


@protocol SKRequestDelegate <NSObject>

@optional
- (void)requestDidFinish:(SKRequest *)request API_AVAILABLE(ios(3.0), macos(10.7), watchos(6.2), visionos(1.0));
- (void)request:(SKRequest *)request didFailWithError:(NSError *)error API_AVAILABLE(ios(3.0), macos(10.7), watchos(6.2), visionos(1.0));

@end

NS_ASSUME_NONNULL_END

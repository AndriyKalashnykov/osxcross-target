// Copyright © 2023 Apple Inc. All rights reserved.

#import <AuthenticationServices/ASFoundation.h>

@class ASAuthorizationPlatformPublicKeyCredentialDescriptor;
@class ASPublicKeyCredentialClientData;

AS_HEADER_AUDIT_BEGIN(nullability, sendability)

API_AVAILABLE(macos(13.5), macCatalyst(16.6)) API_UNAVAILABLE(ios, tvos, watchos)
@protocol ASAuthorizationWebBrowserPlatformPublicKeyCredentialRegistrationRequest

@property (nonatomic, readonly, nullable) ASPublicKeyCredentialClientData *clientData NS_REFINED_FOR_SWIFT;

@property (nonatomic, nullable, copy) NSArray<ASAuthorizationPlatformPublicKeyCredentialDescriptor *> *excludedCredentials;

@property (nonatomic) BOOL shouldShowHybridTransport;

@end

AS_HEADER_AUDIT_END(nullability, sendability)

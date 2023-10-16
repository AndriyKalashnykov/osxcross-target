//
//  AuthenticationServices.h
//  AuthenticationServices Framework
//
//  Copyright © 2018 Apple Inc. All rights reserved.
//

#import <AuthenticationServices/ASFoundation.h>
#import <AuthenticationServices/ASWebAuthenticationSession.h>
#import <AuthenticationServices/ASWebAuthenticationSessionRequest.h>
#import <AuthenticationServices/ASWebAuthenticationSessionWebBrowserSessionHandling.h>
#import <AuthenticationServices/ASWebAuthenticationSessionWebBrowserSessionManager.h>

#import <AuthenticationServices/ASCredentialIdentityStore.h>
#import <AuthenticationServices/ASCredentialIdentityStoreState.h>
#import <AuthenticationServices/ASCredentialProviderExtensionContext.h>
#import <AuthenticationServices/ASCredentialServiceIdentifier.h>
#import <AuthenticationServices/ASPasswordCredential.h>
#import <AuthenticationServices/ASPasswordCredentialIdentity.h>

#import <AuthenticationServices/ASAuthorization.h>
#import <AuthenticationServices/ASAuthorizationAppleIDCredential.h>
#import <AuthenticationServices/ASAuthorizationAppleIDProvider.h>
#import <AuthenticationServices/ASAuthorizationAppleIDRequest.h>
#import <AuthenticationServices/ASAuthorizationController.h>
#import <AuthenticationServices/ASAuthorizationCredential.h>
#import <AuthenticationServices/ASAuthorizationError.h>
#import <AuthenticationServices/ASAuthorizationOpenIDRequest.h>
#import <AuthenticationServices/ASAuthorizationPasswordProvider.h>
#import <AuthenticationServices/ASAuthorizationProvider.h>
#import <AuthenticationServices/ASAuthorizationRequest.h>
#import <AuthenticationServices/ASAuthorizationSingleSignOnCredential.h>
#import <AuthenticationServices/ASAuthorizationSingleSignOnProvider.h>
#import <AuthenticationServices/ASAuthorizationSingleSignOnRequest.h>
#import <AuthenticationServices/ASAuthorizationProviderExtensionAuthorizationRequest.h>
#import <AuthenticationServices/ASAuthorizationProviderExtensionAuthorizationResult.h>

#import <AuthenticationServices/ASExtensionErrors.h>

#if !TARGET_OS_WATCH
#import <AuthenticationServices/ASCredentialProviderViewController.h>

#import <AuthenticationServices/ASAccountAuthenticationModificationController.h>
#import <AuthenticationServices/ASAccountAuthenticationModificationExtensionContext.h>
#import <AuthenticationServices/ASAccountAuthenticationModificationReplacePasswordWithSignInWithAppleRequest.h>
#import <AuthenticationServices/ASAccountAuthenticationModificationUpgradePasswordToStrongPasswordRequest.h>
#import <AuthenticationServices/ASAccountAuthenticationModificationViewController.h>

#import <AuthenticationServices/ASAuthorizationAppleIDButton.h>
#endif // !TARGET_OS_WATCH

#import <AuthenticationServices/ASAuthorizationPlatformPublicKeyCredentialAssertion.h>
#import <AuthenticationServices/ASAuthorizationPlatformPublicKeyCredentialAssertionRequest.h>
#import <AuthenticationServices/ASAuthorizationPlatformPublicKeyCredentialDescriptor.h>
#import <AuthenticationServices/ASAuthorizationPlatformPublicKeyCredentialProvider.h>
#import <AuthenticationServices/ASAuthorizationPlatformPublicKeyCredentialRegistration.h>
#import <AuthenticationServices/ASAuthorizationPlatformPublicKeyCredentialRegistrationRequest.h>
#import <AuthenticationServices/ASAuthorizationPublicKeyCredentialAssertion.h>
#import <AuthenticationServices/ASAuthorizationPublicKeyCredentialAssertionRequest.h>
#import <AuthenticationServices/ASAuthorizationPublicKeyCredentialConstants.h>
#import <AuthenticationServices/ASAuthorizationPublicKeyCredentialDescriptor.h>
#import <AuthenticationServices/ASAuthorizationPublicKeyCredentialLargeBlobAssertionInput.h>
#import <AuthenticationServices/ASAuthorizationPublicKeyCredentialLargeBlobAssertionOutput.h>
#import <AuthenticationServices/ASAuthorizationPublicKeyCredentialLargeBlobRegistrationInput.h>
#import <AuthenticationServices/ASAuthorizationPublicKeyCredentialLargeBlobRegistrationOutput.h>
#import <AuthenticationServices/ASAuthorizationPublicKeyCredentialParameters.h>
#import <AuthenticationServices/ASAuthorizationPublicKeyCredentialRegistration.h>
#import <AuthenticationServices/ASAuthorizationPublicKeyCredentialRegistrationRequest.h>
#import <AuthenticationServices/ASAuthorizationSecurityKeyPublicKeyCredentialAssertion.h>
#import <AuthenticationServices/ASAuthorizationSecurityKeyPublicKeyCredentialAssertionRequest.h>
#import <AuthenticationServices/ASAuthorizationSecurityKeyPublicKeyCredentialDescriptor.h>
#import <AuthenticationServices/ASAuthorizationSecurityKeyPublicKeyCredentialProvider.h>
#import <AuthenticationServices/ASAuthorizationSecurityKeyPublicKeyCredentialRegistration.h>
#import <AuthenticationServices/ASAuthorizationSecurityKeyPublicKeyCredentialRegistrationRequest.h>
#import <AuthenticationServices/ASCOSEConstants.h>
#import <AuthenticationServices/ASPublicKeyCredential.h>



#import <AuthenticationServices/ASAuthorizationProviderExtensionLoginConfiguration.h>
#import <AuthenticationServices/ASAuthorizationProviderExtensionLoginManager.h>
#import <AuthenticationServices/ASAuthorizationProviderExtensionRegistrationHandler.h>

#import <AuthenticationServices/ASAuthorizationProviderExtensionUserLoginConfiguration.h>

#import <AuthenticationServices/ASAuthorizationWebBrowserExternallyAuthenticatableRequest.h>
#import <AuthenticationServices/ASAuthorizationWebBrowserPlatformPublicKeyCredential.h>
#import <AuthenticationServices/ASAuthorizationWebBrowserPublicKeyCredentialManager.h>

#import <AuthenticationServices/ASCredentialIdentity.h>
#import <AuthenticationServices/ASCredentialRequest.h>
#import <AuthenticationServices/ASPasskeyAssertionCredential.h>
#import <AuthenticationServices/ASPasskeyCredentialIdentity.h>
#import <AuthenticationServices/ASPasskeyCredentialRequest.h>
#import <AuthenticationServices/ASPasskeyCredentialRequestParameters.h>
#import <AuthenticationServices/ASPasskeyRegistrationCredential.h>
#import <AuthenticationServices/ASPasswordCredentialRequest.h>

#import <AuthenticationServices/ASAuthorizationWebBrowserPlatformPublicKeyCredentialAssertionRequest.h>
#import <AuthenticationServices/ASAuthorizationWebBrowserPlatformPublicKeyCredentialProvider.h>
#import <AuthenticationServices/ASAuthorizationWebBrowserPlatformPublicKeyCredentialRegistrationRequest.h>
#import <AuthenticationServices/ASPublicKeyCredentialClientData.h>

#import <AuthenticationServices/ASSettingsHelper.h>

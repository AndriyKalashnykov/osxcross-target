// Copyright © Apple Inc. All rights reserved.

#import <GameKit/GKGameSession.h>

NS_ASSUME_NONNULL_BEGIN

API_DEPRECATED_WITH_REPLACEMENT("GKLocalPlayerListener", ios(10.0, 12.0), tvos(10.0, 12.0), macosx(10.12, 10.14)) API_UNAVAILABLE(watchos)
@protocol GKGameSessionEventListener <NSObject>
@optional
- (void)session:(GKGameSession *)session didAddPlayer:(GKCloudPlayer *)player;
- (void)session:(GKGameSession *)session didRemovePlayer:(GKCloudPlayer *)player;
- (void)session:(GKGameSession *)session player:(GKCloudPlayer *)player didChangeConnectionState:(GKConnectionState)newState;
- (void)session:(GKGameSession *)session player:(GKCloudPlayer *)player didSaveData:(NSData *)data;
- (void)session:(GKGameSession *)session didReceiveData:(NSData *)data fromPlayer:(GKCloudPlayer *)player;
- (void)session:(GKGameSession *)session didReceiveMessage:(NSString *)message withData:(NSData *)data fromPlayer:(GKCloudPlayer *)player;

@end

@interface GKGameSession (GKGameSessionEventListener)
+ (void)addEventListener:(NSObject<GKGameSessionEventListener> *)listener NS_SWIFT_NAME(add(listener:)) API_DEPRECATED_WITH_REPLACEMENT("-[GKLocalPlayer registerListener:]", ios(10.0, 12.0), tvos(10.0, 12.0), macosx(10.12, 10.14)) API_UNAVAILABLE(watchos);
+ (void)removeEventListener:(NSObject<GKGameSessionEventListener> *)listener NS_SWIFT_NAME(remove(listener:)) API_DEPRECATED("-[GKLocalPlayer unregisterListener:] or -[GKLocalPlayer unregisterAllListeners:]", ios(10.0, 12.0), tvos(10.0, 12.0), macosx(10.12, 10.14)) API_UNAVAILABLE(watchos);
@end

NS_ASSUME_NONNULL_END


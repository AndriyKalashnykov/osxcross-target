// Copyright © Apple Inc. All rights reserved.

#import <Foundation/Foundation.h>
#import <GameKit/GKDefines.h>

@class GKPlayer;

NS_ASSUME_NONNULL_BEGIN
// GKAchievement represents a game achievement that the player has started or completely achieved.
NS_CLASS_AVAILABLE(10_8, 4_1) __WATCHOS_AVAILABLE(3_0)
@interface GKAchievement : NSObject <NSCoding, NSSecureCoding>

/// Asynchronously load all achievements for the local player
+ (void)loadAchievementsWithCompletionHandler:(void (^ __nullable)(NSArray<GKAchievement *> * __nullable achievements, NSError * __nullable error))completionHandler;

/// Reset the achievements progress for the local player. All the entries for the local player are removed from the server. Error will be nil on success.
///Possible reasons for error:
/// 1. Local player not authenticated
/// 2. Communications failure
+ (void)resetAchievementsWithCompletionHandler:(void(^ __nullable)(NSError * __nullable error))completionHandler;

/// Designated initializer
- (instancetype)initWithIdentifier:(nullable NSString *)identifier;

/// Initialize the achievement for a specific player. Use to submit participant achievements when ending a turn-based match.
- (instancetype)initWithIdentifier:(nullable NSString *)identifier player:(GKPlayer *)player NS_AVAILABLE(10_10, 8_0);


/// Report an array of achievements to the server. Percent complete is required. Points, completed state are set based on percentComplete. isHidden is set to NO anytime this method is invoked. Date is optional. Error will be nil on success.
/// Possible reasons for error:
/// 1. Local player not authenticated
/// 2. Communications failure
/// 3. Reported Achievement does not exist
+ (void)reportAchievements:(NSArray<GKAchievement *> *)achievements withCompletionHandler:(void(^ __nullable)(NSError * __nullable error))completionHandler NS_AVAILABLE(10_8, 6_0);

/// Achievement identifier
@property(copy, nullable, NS_NONATOMIC_IOSONLY) NSString *identifier;
/// Required, Percentage of achievement complete.
@property(assign, NS_NONATOMIC_IOSONLY) double percentComplete;
/// Set to NO until percentComplete = 100.
@property(readonly, getter=isCompleted, NS_NONATOMIC_IOSONLY) BOOL completed;
/// Date the achievement was last reported. Read-only. Created at initialization
@property(copy, readonly, NS_NONATOMIC_IOSONLY) NSDate *lastReportedDate;

/// A banner will be momentarily displayed after reporting a completed achievement
@property(assign, NS_NONATOMIC_IOSONLY) BOOL showsCompletionBanner NS_AVAILABLE(10_8, 5_0);

/// The identifier of the player that earned the achievement.
@property(readonly, strong, nullable, NS_NONATOMIC_IOSONLY) GKPlayer *player NS_AVAILABLE(10_10, 8_0);

@end

@interface GKAchievement (Deprecated)
- (void)reportAchievementWithCompletionHandler:(void(^ __nullable)(NSError * __nullable error))completionHandler API_DEPRECATED_WITH_REPLACEMENT("+reportAchievements:withCompletionHandler:", ios(4.1,7.0), macos(10.8,10.10)) __TVOS_UNAVAILABLE;
@property(assign, getter=isHidden, readonly, NS_NONATOMIC_IOSONLY) BOOL hidden API_DEPRECATED_WITH_REPLACEMENT("-[GKAchievementDescription isHidden:]", ios(4.1,6.0), macos(10.8,10.10)) __TVOS_UNAVAILABLE;
@end

@interface GKAchievement (Obsoleted)
/*** This method is obsolete. Calling this initialiser does nothing and will return nil ***/
- (nullable instancetype)initWithIdentifier:(nullable NSString *)identifier forPlayer:(NSString *)playerID API_DEPRECATED_WITH_REPLACEMENT("-initWithIdentifier:player:", ios(7.0,8.0), macos(10.9,10.10)) API_UNAVAILABLE(tvos);
/*** This property is obsolete. ***/
@property(readonly, copy, nullable, NS_NONATOMIC_IOSONLY)  NSString * playerID API_DEPRECATED_WITH_REPLACEMENT("-player:", ios(7.0,8.0), macos(10.9,10.10)) API_UNAVAILABLE(tvos);
@end
NS_ASSUME_NONNULL_END

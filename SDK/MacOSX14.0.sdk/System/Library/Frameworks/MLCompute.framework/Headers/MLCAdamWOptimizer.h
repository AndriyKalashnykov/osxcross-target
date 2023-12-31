//
//  MLCAdamWOptimizer.h
//  MLCompute
//
//  Copyright © 2021 Apple. All rights reserved.
//

#import <MLCompute/MLCompute.h>

@class MLCDevice;
@class MLCOptimizerDescriptor;

NS_ASSUME_NONNULL_BEGIN

/*! @class      MLCAdamWOptimizer
    @discussion The MLCAdamWOptimizer specifies the AdamW optimizer.
 */
MLCOMPUTE_AVAILABLE_STARTING_BUT_DEPRECATED_MACOS14(12.0, 15.0, 15.0)
@interface  MLCAdamWOptimizer : MLCOptimizer<NSCopying>

/*! @property   beta1
    @abstract   Coefficent used for computing running averages of gradient.
    @discussion The default is 0.9.
 */
@property (readonly, nonatomic) float beta1;

/*! @property   beta2
    @abstract   Coefficent used for computing running averages of square of gradient.
    @discussion The default is 0.999.
 */
@property (readonly, nonatomic) float beta2;

/*! @property   epsilon
    @abstract   A term added to improve numerical stability.
    @discussion The default is 1e-8.
 */
@property (readonly, nonatomic) float epsilon;

/*! @property   usesAMSGrad
    @abstract   Whether to use the AMSGrad variant of this algorithm
    @discussion The default is false
 */
@property (readonly, nonatomic) BOOL usesAMSGrad;

/*! @property   timeStep
    @abstract   The current timestep used for the update.
    @discussion The default is 1.
 */
@property (readonly, nonatomic) NSUInteger timeStep;


/*! @abstract   Create an MLCAdamWOptimizer object with defaults
    @return     A new MLCAdamWOptimizer object.
 */
+ (instancetype)optimizerWithDescriptor:(MLCOptimizerDescriptor *)optimizerDescriptor;

/*! @abstract   Create an MLCAdamWOptimizer object
    @param      optimizerDescriptor    The optimizer descriptor object
    @param      beta1                  The beta1 value
    @param      beta2                  The beta2 value
    @param      epsilon              The epsilon value to use to improve numerical stability
    @param      usesAMSGrad     Whether to use the AMSGrad variant of this algorithm from the paper (https://arxiv.org/abs/1904.09237)
    @param      timeStep            The initial timestep to use for the update
    @return     A new MLCAdamWOptimizer object.
 */
+ (instancetype)optimizerWithDescriptor:(MLCOptimizerDescriptor *)optimizerDescriptor
                                  beta1:(float)beta1
                                  beta2:(float)beta2
                                epsilon:(float)epsilon
                            usesAMSGrad:(BOOL)usesAMSGrad
                               timeStep:(NSUInteger)timeStep;

@end

NS_ASSUME_NONNULL_END

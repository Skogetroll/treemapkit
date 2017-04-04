#import <UIKit/UIKit.h>

@protocol TreemapViewCellDelegate;

NS_ASSUME_NONNULL_BEGIN

@interface TreemapViewCell : UIControl {
    UILabel *valueLabel;
    UILabel *textLabel;

    NSInteger index;

    id <TreemapViewCellDelegate> _Nullable delegate;
}

@property (nonatomic, strong) UILabel *valueLabel;
@property (nonatomic, strong) UILabel *textLabel;

@property NSInteger index;

@property (nonatomic, retain) id <TreemapViewCellDelegate> _Nullable delegate;

- (instancetype)initWithFrame:(CGRect)frame;

@end

@protocol TreemapViewCellDelegate <NSObject>

@optional

- (void)treemapViewCell:(TreemapViewCell *)treemapViewCell tapped:(NSInteger)index;

@end

NS_ASSUME_NONNULL_END

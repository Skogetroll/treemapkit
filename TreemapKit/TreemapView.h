#import <UIKit/UIKit.h>
#import "TreemapViewCell.h"

@protocol TreemapViewDataSource;
@protocol TreemapViewDelegate;

NS_ASSUME_NONNULL_BEGIN

@interface TreemapView : UIView <TreemapViewCellDelegate> {
    id <TreemapViewDataSource> _Nullable dataSource;
    id <TreemapViewDelegate> _Nullable delegate;

    BOOL initialized;
}

@property (nonatomic, retain) IBOutlet id <TreemapViewDataSource> _Nullable dataSource;
@property (nonatomic, retain) IBOutlet id <TreemapViewDelegate> _Nullable delegate;

- (void)reloadData;

@end

@protocol TreemapViewDelegate <NSObject>

@optional

- (void)treemapView:(TreemapView *)treemapView touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event;
- (void)treemapView:(TreemapView *)treemapView touchesCancelled:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event;
- (void)treemapView:(TreemapView *)treemapView touchesEnded:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event;
- (void)treemapView:(TreemapView *)treemapView touchesMoved:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event;
- (void)treemapView:(TreemapView *)treemapView tapped:(NSInteger)index;
- (void)treemapView:(TreemapView *)treemapView updateCell:(TreemapViewCell *)cell forIndex:(NSInteger)index forRect:(CGRect)rect;

@end

@protocol TreemapViewDataSource <NSObject>

- (NSArray<NSNumber *> *)valuesForTreemapView:(TreemapView *)treemapView;
- (TreemapViewCell * _Nullable)treemapView:(TreemapView *)treemapView cellForIndex:(NSInteger)index forRect:(CGRect)rect;

@optional

- (CGFloat)treemapView:(TreemapView *)treemapView separatorWidthForDepth:(NSInteger)depth;
- (NSInteger)treemapView:(TreemapView *)treemapView separationPositionForDepth:(NSInteger)depth;

@end

NS_ASSUME_NONNULL_END

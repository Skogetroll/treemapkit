#import <UIKit/UIKit.h>

@class IPhoneSimpleDemoViewController;

@interface IPhoneSimpleDemoAppDelegate : NSObject <UIApplicationDelegate> {
    UIWindow *window;
    IPhoneSimpleDemoViewController *viewController;
}

@property (nonatomic, strong) IBOutlet UIWindow *window;
@property (nonatomic, strong) IBOutlet IPhoneSimpleDemoViewController *viewController;

@end


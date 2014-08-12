//
//  xlMain.h
//  pashmak-gui
//
//  Created by Sayed Hadi Hashemi on 7/15/14.
//  Copyright (c) 2014 Sayed Hadi Hashemi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ELCImagePickerController.h"

@interface xlMain : UIViewController <UINavigationControllerDelegate, UIImagePickerControllerDelegate, ELCImagePickerControllerDelegate>

@property (weak, nonatomic) IBOutlet UIImageView *preview;


@end

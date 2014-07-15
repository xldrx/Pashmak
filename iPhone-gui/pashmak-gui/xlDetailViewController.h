//
//  xlDetailViewController.h
//  pashmak-gui
//
//  Created by Sayed Hadi Hashemi on 7/14/14.
//  Copyright (c) 2014 Sayed Hadi Hashemi. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface xlDetailViewController : UIViewController

@property (strong, nonatomic) id detailItem;

@property (weak, nonatomic) IBOutlet UILabel *detailDescriptionLabel;
@end

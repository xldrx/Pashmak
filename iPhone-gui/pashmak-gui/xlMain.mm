//
//  xlMain.m
//  pashmak-gui
//
//  Created by Sayed Hadi Hashemi on 7/15/14.
//  Copyright (c) 2014 Sayed Hadi Hashemi. All rights reserved.
//

#import "xlMain.h"

#include "Constants.h"
#include "Engine.h"
#include "FileManager.h"
#include <iostream>
#include <string>


//#import "../../core/Pashmak/main.cpp"

@interface xlMain ()

@end

@implementation xlMain

- (IBAction)click:(id)sender {
    [self imaging:UIImagePickerControllerSourceTypePhotoLibrary];
}
- (IBAction)take_image:(id)sender {
    [self imaging:UIImagePickerControllerSourceTypeCamera];
}

- (void) imaging: (UIImagePickerControllerSourceType) source {
    if (![UIImagePickerController isSourceTypeAvailable:source]){
        
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"You don't have any pictures (or camera)"
                                                        message:@"Save some pictures."
                                                       delegate:nil
                                              cancelButtonTitle:@"OK"
                                              otherButtonTitles:nil];
        [alert show];
        return;
    }
    
    UIImagePickerController *pickerLibrary = [[UIImagePickerController alloc] init];
    pickerLibrary.sourceType = source;
    pickerLibrary.delegate = self;
    
    [self presentViewController:pickerLibrary animated:YES completion:nil];

}

- (void) imagePickerController:(UIImagePickerController *)picker didFinishPickingImage:(UIImage *)image editingInfo:(NSDictionary *)editingInfo
{

    [picker dismissViewControllerAnimated:YES completion:nil];
    NSString *path = [NSTemporaryDirectory() stringByAppendingPathComponent:@"image.jpg"];
    NSData *imageData = UIImageJPEGRepresentation(image, 1);
    [imageData writeToFile:path atomically:YES];

    path = [NSString stringWithFormat:@"%@/%@", [[NSBundle mainBundle] resourcePath], @"Lenna.jpg"];;
    
    FileManager myFileManager;
	Engine myEngine;
    
    auto cpath = {(std::string)[path UTF8String]};
    
	auto media = myFileManager.LoadFiles(cpath);
    NSString* savePath = [NSString stringWithFormat:@"%@/%@", [[NSBundle mainBundle] resourcePath], @"output2.mp4"];
	myEngine.CreateZoe(media, Themes::Oldie, [savePath UTF8String]);

//	myFileManager.SaveFile(output, [savePath UTF8String]);
    
    UIImage* imageToBeSaved = [UIImage imageWithContentsOfFile:savePath];
    UIImageWriteToSavedPhotosAlbum(imageToBeSaved, nil, nil, nil);
    
    [self.preview setImage:imageToBeSaved];
    [self.preview setContentMode:UIViewContentModeScaleAspectFill];

    
    
}


- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end

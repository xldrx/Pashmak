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
#import <MobileCoreServices/UTCoreTypes.h>

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
//    if (![UIImagePickerController isSourceTypeAvailable:source]){
//        
//        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"You don't have any pictures (or camera)"
//                                                        message:@"Save some pictures."
//                                                       delegate:nil
//                                              cancelButtonTitle:@"OK"
//                                              otherButtonTitles:nil];
//        [alert show];
//        return;
//    }
//    
//    UIImagePickerController *pickerLibrary = [[UIImagePickerController alloc] init];
//    pickerLibrary.sourceType = source;
//    pickerLibrary.mediaTypes = [NSArray arrayWithObjects:(NSString*)kUTTypeImage, (NSString*)kUTTypeMovie, nil];
//    pickerLibrary.delegate = self;
//    pickerLibrary.videoQuality = UIImagePickerControllerQualityTypeHigh;
//    
//    [self presentViewController:pickerLibrary animated:YES completion:nil];

    ELCImagePickerController *imagePicker = [[ELCImagePickerController alloc] init];
    imagePicker.maximumImagesCount = 10; //Set the maximum number of images to select, defaults to 4
    imagePicker.imagePickerDelegate = self;
    [self presentViewController:imagePicker animated:YES completion:nil];

    
    
}

//- (void) imagePickerController:(UIImagePickerController *)picker didFinishPickingImage:(UIImage *)image editingInfo:(NSDictionary *)editingInfo

- (void)imagePickerController:(UIImagePickerController *)picker didFinishPickingMediaWithInfo:(NSDictionary *)info
{
    [picker dismissViewControllerAnimated:NO completion:nil];

//    NSString *path = [NSTemporaryDirectory() stringByAppendingPathComponent:@"image.m4v"];
//    NSData *imageData = UIImageJPEGRepresentation(image, 1);
//    [imageData writeToFile:path atomically:YES];
//
    NSURL *videoPath = [info objectForKey:UIImagePickerControllerMediaURL];
    FileManager myFileManager;
	Engine myEngine;
    NSLog(@"URL is %@", videoPath);
    
    auto cpath = {(std::string)[[videoPath absoluteString] UTF8String]};


	auto media = myFileManager.LoadFiles(cpath);
    NSString* savePath = [NSString stringWithFormat:@"%@/%@", [[NSBundle mainBundle] resourcePath], @"output2.m4v"];
	myEngine.CreateZoe(media, Themes::Oldie, [savePath UTF8String]);
    
    UISaveVideoAtPathToSavedPhotosAlbum(savePath,nil,nil,nil);
    
//    UIImage* imageToBeSaved = [UIImage imageWithContentsOfFile:savePath];
//        UIImageWriteToSavedPhotosAlbum
//    (imageToBeSaved, nil, nil, nil);
    
//    [self.preview setImage:imageToBeSaved];
//    [self.preview setContentMode:UIViewContentModeScaleAspectFill];
}

- (void)elcImagePickerController:(ELCImagePickerController *)picker didFinishPickingMediaWithInfo:(NSArray *)info;
{
    NSLog(@"%@", [info count]);
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
- (IBAction)new_method:(id)sender {

    NSString* savePath =  [NSTemporaryDirectory() stringByAppendingPathComponent:@"image.m4v"];

    [[NSFileManager defaultManager] removeItemAtPath:savePath error:nil];

    
    
    auto inputPath = [NSString stringWithFormat:@"%@/%@", [[NSBundle mainBundle] resourcePath], @"b.m4v"];
    
    auto addr = [NSString stringWithFormat:@"%@/%@", [[NSBundle mainBundle] resourcePath], @"filmscratches.m4v"];
    
    Engine myEngine;
    FileManager myFileManager;

    auto media = myFileManager.LoadFiles({[inputPath UTF8String]});
    
	myEngine.CreateZoe(media, Themes::Oldie, [savePath UTF8String], [addr UTF8String]);
    NSLog(inputPath);
    NSLog(addr);
    NSLog(savePath);
}

@end

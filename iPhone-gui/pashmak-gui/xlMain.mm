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
    FileManager myFileManager;
	Engine myEngine;
    
    NSString *path = [[NSBundle mainBundle] pathForResource:@"Lenna" ofType:@"png"];
    auto cpath = {(std::string)[path UTF8String]};
    
	auto media = myFileManager.LoadFiles(cpath);
	auto output = myEngine.CreateZoe(media, Themes::Oldie);
	myFileManager.SaveFile(output, "./test.png");

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

//
//  JGPhotoManager.m
//  MyImagePicker
//
//  Created by jinguang peng on 2020/3/18.
//  Copyright © 2020 jinguang peng. All rights reserved.
//

#import "JGPhotoManager.h"
#import "JJImagePicker.h"
#import "UIImage+Extension.h"

@interface JGPhotoManager ()

@property (nonatomic, strong) JGPhotoManagerDidChoseImg imgBlock;

@end

@implementation JGPhotoManager

- (void)categoryViewChangeImgBtnClick {
    JJImagePicker *picker = [JJImagePicker sharedInstance];
    //自定义裁剪图片的ViewController
    picker.customCropViewController = ^TOCropViewController *(UIImage *image) {
        if (picker.type == JJImagePickerTypePhoto) {
            //使用默认
            return nil;
        }
        TOCropViewController  *cropController = [[TOCropViewController alloc] initWithImage:image];
        //选择框可以按比例来手动调节
        cropController.aspectRatioLockEnabled = NO;
        //        cropController.resetAspectRatioEnabled = NO;
        //设置选择宽比例
        cropController.aspectRatioPreset = TOCropViewControllerAspectRatioPresetSquare;
        //显示选择框比例的按钮
        cropController.aspectRatioPickerButtonHidden = NO;
        //显示选择按钮
        cropController.rotateButtonsHidden = NO;
        //设置选择框可以手动移动
        cropController.cropView.cropBoxResizeEnabled = NO;
        return cropController;
    };
    picker.albumText = @"照片";
    picker.cancelText = @"取消";
    picker.doneText = @"完成";
    picker.retakeText = @"重拍";
    picker.choosePhotoText = @"选择照片";
    picker.automaticText = @"Automatic";
    picker.closeText = @"关闭";
    picker.openText = @"打开";
    typeof(self) wkSelf = self;
    [picker actionSheetWithTakePhotoTitle:@"拍照" albumTitle:@"从相册选择一张图片" cancelTitle:@"取消" InViewController:[UIApplication sharedApplication].keyWindow.rootViewController didFinished:^(JJImagePicker *picker, UIImage *image) {
        // 由于用户选图比较大,这边做压缩处理
        image = [wkSelf imageResize:image andResizeTo:CGSizeMake(414, 414)];
         NSLog(@"压缩前：%lu",(unsigned long)UIImagePNGRepresentation(image).length);
         NSData *data = [UIImage compressImageQuality:image toByte:80000];
        UIImage *img = [UIImage imageWithData:data scale:1.0];
        if (wkSelf.imgBlock) {
            wkSelf.imgBlock(img);
        }
    }];
}

// 图片缩放的方式 将图片由原始尺寸调整
-(UIImage *)imageResize :(UIImage*)img andResizeTo:(CGSize)newSize {
    CGFloat scale = [[UIScreen mainScreen]scale];
    UIGraphicsBeginImageContextWithOptions(newSize, NO, scale);
    [img drawInRect:CGRectMake(0,0,newSize.width,newSize.height)];
    UIImage* newImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    return newImage;
}

// 将图片以16 : 9 的方式进行缩放
- (UIImage *)resizeSnapshot:(UIImage *)snapshot InRect:(CGRect)rect {
    CGFloat scale = [UIScreen mainScreen].scale;
    CGRect rect1 = CGRectMake(rect.origin.x*scale, rect.origin.y*scale, rect.size.width*scale, rect.size.height*scale);
    UIImage *image = [UIImage imageWithCGImage:CGImageCreateWithImageInRect([snapshot CGImage], rect1)];
    return image;
}



@end

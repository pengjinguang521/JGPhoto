//
//  JGPhotoManager.h
//  MyImagePicker
//
//  Created by jinguang peng on 2020/3/18.
//  Copyright © 2020 jinguang peng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^JGPhotoManagerDidChoseImg)(UIImage *img);

@interface JGPhotoManager : NSObject

// 选择图片的方法
// maxKb eg: 80000
// imgBlock: 最后回掉的图片信息
+ (void)ChangeImgBtnClickWithImageMAXSize:(NSInteger)maxKb
                               choseBlock:(JGPhotoManagerDidChoseImg)imgBlock;

@end

NS_ASSUME_NONNULL_END

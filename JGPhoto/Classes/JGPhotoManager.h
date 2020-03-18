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

- (void)categoryViewChangeImgBtnClick;

@end

NS_ASSUME_NONNULL_END

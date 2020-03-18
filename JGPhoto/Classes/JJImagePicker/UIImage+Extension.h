//
//  UIImage+Extension.h
//  elf
//
//  Created by maimob on 2019/4/16.
//  Copyright © 2019 Maiba. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (Extension)
+ (void)fetchAlbumAuthorization;

// 图片压缩
+ (NSData *)compressImageQuality:(UIImage *)image toByte:(NSInteger)maxLength;

- (nullable UIImage *)imageByResizeToSize:(CGSize)size;
@end

NS_ASSUME_NONNULL_END

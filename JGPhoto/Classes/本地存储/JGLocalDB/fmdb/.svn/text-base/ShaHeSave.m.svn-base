//
//  ShaHeSave.m
//  沙盒存储
//
//  Created by aaa on 16/1/13.
//  Copyright © 2016年 aaa. All rights reserved.
//

#import "ShaHeSave.h"

@implementation ShaHeSave

//获取沙盒路径
+ (NSString *)getDocPath{

    NSString * string = [[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES)lastObject]stringByAppendingString:@"/SavePath"];
    return string;
}
//存储我已经回答过的问题 ARRAY是你要存储的问题数组  name是方便找到数组的标识
+ (BOOL)saveQuestionArray:(NSArray *)questionArray withName:(NSString *)name{

     NSString * path = [NSString stringWithFormat:@"%@%@.txt",[ShaHeSave getDocPath],name];
    
    BOOL isSuccess = [questionArray writeToFile:path atomically:YES];
    
    if (isSuccess) {
        return YES;
    }else{
        return NO;
    }
}
+ (NSArray *)getArrayFromDBWithName:(NSString *)name{

      NSString * path = [NSString stringWithFormat:@"%@%@.txt",[ShaHeSave getDocPath],name];
    NSArray * array = [NSArray arrayWithContentsOfFile:path];
    return array;
}

//做到第几题存下第几题的编号，方便下次再用
//这边可以考虑再传个字典过来  用来标识谁的答题 （只是考虑）
+ (BOOL)saveQuestionNumber:(int)number{
    NSString * path = [NSString stringWithFormat:@"%@QuestionNumber.txt",[ShaHeSave getDocPath]];
    NSString * string = [NSString stringWithFormat:@"%d",number];
    BOOL isSuccess = [string writeToFile:path atomically:YES encoding:NSUTF8StringEncoding error:nil];
    if (isSuccess) {
        return YES;
    }else{
        return NO;
    }
}

//获取存入的 数字 （标识为第几题）
+ (int)getQuestionNumber{

    NSString * path = [NSString stringWithFormat:@"%@QuestionNumber.txt",[ShaHeSave getDocPath]];
    NSString * string = [NSString stringWithContentsOfFile:path usedEncoding:nil error:nil];
    int number = [string intValue];
    return number;
}
//清空沙盒
+ (void)clearnShaHe{
    
    NSString * string = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES)lastObject];
    NSFileManager * manger = [NSFileManager defaultManager];
    [manger removeItemAtPath:string error:nil];
    

}


@end

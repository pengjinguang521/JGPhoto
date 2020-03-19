//
//  ShaHeSave.h
//  沙盒存储
//
//  Created by aaa on 16/1/13.
//  Copyright © 2016年 aaa. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ShaHeSave : NSObject

+ (NSString *)getDocPath;
//存入数组对象
//name 为标识对象  可以覆盖存入
+ (BOOL)saveQuestionArray:(NSArray *)questionArray withName:(NSString *)name;
//拿到数组对象
+ (NSArray *)getArrayFromDBWithName:(NSString *)name;


//存入的题目标号
+ (BOOL)saveQuestionNumber:(int)number;
//拿到的题目标号
+ (int)getQuestionNumber;
//清空沙盒
+ (void)clearnShaHe;

@end

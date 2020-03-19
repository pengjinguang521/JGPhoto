//
//  DBSaveHelper.h
//  简单封装FMDB做本地化存储
//
//  Created by aaa on 16/1/22.
//  Copyright © 2016年 pengPL. All rights reserved.
//
/**
 *  该类 是对 FMDB 的封装
 *      主要是 封装一些基本的 调用办法
 *
 *      封装 fmdb 以及mjextension
 */
#import <Foundation/Foundation.h>
#import "FMDatabase.h"
#import "MJExtension.h"

@interface DBSaveHelper : NSObject


@property (nonatomic,strong) FMDatabase *  db;

//单类化
+ (instancetype)sharedHelper;

//表字段内容的拼接方法，就是字段名加空格然后是字段类型（int、text）
+ (NSString *)contentStrWith:(NSString *)dbStr And:(NSString *)type;

//打开sqlite 文件  打开db 如果不存在则创建  --
- (void)openDB:(NSString *)pathName;

//在sqlite下面创建表，tableName为表名 array 为所要创建的表字段
- (void)createTableWithName:(NSString *)tableName AndArray:(NSArray *)array;

//写入数据库方法，name为tablename model为你传过来的数据模型
- (void)insertIntoDBWithTableName:(NSString *)name AndModel:(NSObject *)model;

//查询某个表的全部信息
- (NSArray *)searchDBAllContentWithTableName:(NSString *)tableName;

//删除某个表（name）字段ID ＝ ID 的记录
- (void)DeleteTableWithTableName:(NSString *)name ID:(NSString *)ID;

//删除某个表中的全部字段
- (void)DeleteAllFromTableWithName:(NSString *)name;

//修改数据库中的某个属性
- (void)UpdataDBWithTableName:(NSString *)name AndID:(NSString *)ID AndModel:(NSObject *)model;

//查询数据库中的某记录  入参 你自己写的sql语句，和要查询的表名称  这里我返回array  请在解析的时候注意 返回是array
- (NSArray *)searchDBWithSql:(NSString *)sql AndArray:(NSArray *)array AndTableName:(NSString *)name;


#pragma mark - 检查 表名 是否存在数据库中 --
-(BOOL)checkTableIsHasWithTableName:(NSString *)tableName;

#pragma mark - 删除 表名 --
-(void)DropTableWithTableName:(NSString *)tableName;

#pragma mark - 升级 数据库 表里添加传入的属性 --
-(void)UpgradeTableWithTableName:(NSString *)tableName andAttribute:(NSString *)attribute andType:(NSString *)type;

#pragma mark - 执行 获取 数组 查找表中所有数据  的 sql 语句 --
-(NSArray *)getArrayAllObjectWithSql:(NSString *)sql andTableName:(NSString *)tableName;

//关闭数据库
- (void)CloseDB;


@end

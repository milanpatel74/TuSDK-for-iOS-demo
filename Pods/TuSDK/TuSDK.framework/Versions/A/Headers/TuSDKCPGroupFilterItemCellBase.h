//
//  TuSDKCPGroupFilterItemCell.h
//  TuSDK
//
//  Created by Clear Hu on 15/2/18.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import "TuSDKCPGroupFilterItemCellBase.h"
#import "TuSDKFilterOption.h"
#import "TuSDKFilterGroup.h"
#import "TuSDKICTableViewCell.h"

/**
 *  滤镜分组元素类型
 */
typedef NS_ENUM(NSInteger, lsqGroupFilterItemType)
{
    /**
     * 占位视图
     */
    lsqGroupFilterItemHolder,
    /**
     * 滤镜
     */
    lsqGroupFilterItemFilter,
    /**
     * 滤镜分组
     */
    lsqGroupFilterItemGroup,
    /**
     * 历史
     */
    lsqGroupFilterItemHistory,
    /**
     * 在线滤镜
     */
    lsqGroupFilterItemOnline,
};

/**
 *  滤镜分组元素类型
 */
typedef NS_ENUM(NSInteger, lsqGroupFilterAction)
{
    /**
     * 默认
     */
    lsqGroupFilterActionNormal,
    /**
     * 编辑
     */
    lsqGroupFilterActionEdit,
    /**
     * 相机
     */
    lsqGroupFilterActionCamera
};

#pragma mark - TuSDKCPGroupFilterItemCellInterface
@class TuSDKCPGroupFilterItem;

/**
 *  滤镜分组元素视图接口
 */
@protocol TuSDKCPGroupFilterItemCellInterface <NSObject>
/**
 *  滤镜分组元素类型
 */
@property (nonatomic)lsqGroupFilterAction action;

/**
 *  是否激活
 */
@property (nonatomic, readonly)BOOL activating;

/**
 *  滤镜分组元素
 */
@property (nonatomic, retain)TuSDKCPGroupFilterItem *mode;

/**
 *  是否为相机动作
 *
 *  @return 是否为相机动作
 */
- (BOOL)isCameraAction;

/**
 *  启动激活状态
 *
 *  @param wait 等待秒
 */
- (void)waitInActivate:(CGFloat)wait;

/**
 *  停止激活
 */
- (void)stopActivating;
@end

#pragma mark - TuSDKCPGroupFilterItemColor
/**
 *  滤镜分组元素颜色
 */
@interface TuSDKCPGroupFilterItemColor : NSObject
/**
 *  历史记录背景色
 */
@property (nonatomic, retain) UIColor *history;
/**
 *  在线滤镜背景色
 */
@property (nonatomic, retain) UIColor *online;
/**
 *  原始效果背景色
 */
@property (nonatomic, retain) UIColor *orgin;
/**
 *  滤镜分组元素颜色
 *
 *  @return 滤镜分组元素颜色
 */
+ (instancetype)shared;
@end
#pragma mark - TuSDKCPGroupFilterItem
/**
 *  滤镜分组元素
 */
@interface TuSDKCPGroupFilterItem : NSObject
/**
 *  滤镜分组元素类型
 */
@property (nonatomic)lsqGroupFilterItemType type;
/**
 *  滤镜配置选项
 */
@property (nonatomic, retain) TuSDKFilterOption *option;
/**
 *  滤镜分组
 */
@property (nonatomic, retain) TuSDKFilterGroup *group;

/**
 *  是否为动作状态
 */
@property (nonatomic) BOOL isInActingType;

/**
 *  初始化
 *
 *  @param type 滤镜分组元素类型
 *
 *  @return 滤镜分组元素
 */
+ (instancetype)initWithType:(lsqGroupFilterItemType)type;

/**
 *  初始化
 *
 *  @param option 滤镜配置选项
 *
 *  @return 滤镜分组元素
 */
+ (instancetype)initWithOption:(TuSDKFilterOption *)option;

/**
 *  初始化
 *
 *  @param group 滤镜分组
 *
 *  @return 滤镜分组元素
 */
+ (instancetype)initWithGroup:(TuSDKFilterGroup *)group;

/**
 *  获取滤镜代号
 *
 *  @return 滤镜代号
 */
- (NSString *)filterCode;
@end
#pragma mark - TuSDKCPGroupFilterItemCellBase
/**
 *  滤镜分组元素视图基础类
 */
@interface TuSDKCPGroupFilterItemCellBase : TuSDKICTableViewCell<TuSDKCPGroupFilterItemCellInterface>
/**
 *  滤镜分组元素类型
 */
@property (nonatomic)lsqGroupFilterAction action;

/**
 *  是否激活
 */
@property (nonatomic, readonly)BOOL activating;
/**
 *  滤镜分组元素
 */
@property (nonatomic, retain)TuSDKCPGroupFilterItem *mode;

/**
 *  图片视图
 */
@property (nonatomic, readonly) UIImageView *thumbView;

/**
 *  初始化视图 (空方法, 默认当使用+(id)initWithFrame:(CGRect)frame;初始化视图时调用)
 */
- (void)initView;

/**
 *  设置选中图标
 *
 *  @param mode     滤镜分组元素
 *  @param needIcon 是否需要Icon
 */
- (void)setSelectedIcon:(TuSDKCPGroupFilterItem *)mode needIcon:(BOOL)needIcon;

/**
 *  原始效果
 *
 *  @param mode 滤镜分组元素
 */
- (void)handleTypeOrgin:(TuSDKCPGroupFilterItem *)mode;

/**
 *  滤镜分组
 *
 *  @param mode 滤镜分组元素
 */
- (void)handleTypeGroup:(TuSDKCPGroupFilterItem *)mode;

/**
 *  滤镜
 *
 *  @param mode 滤镜分组元素
 */
- (void)handleTypeFilter:(TuSDKCPGroupFilterItem *)mode;

/**
 *  历史记录
 *
 *  @param mode 滤镜分组元素
 */
- (void)handleTypeHistory:(TuSDKCPGroupFilterItem *)mode;

/**
 *  在线滤镜
 *
 *  @param mode 滤镜分组元素
 */
- (void)handleTypeOnlie:(TuSDKCPGroupFilterItem *)mode;

/**
 *  设置功能块视图
 *
 *  @param color 颜色
 *  @param icon  图标
 */
- (void)handleBlockView:(UIColor *)color icon:(NSString *)icon;
@end

#pragma mark - TuSDKCPGroupFilterGroupCellBase

@class TuSDKCPGroupFilterGroupCellBase;

/**
 *  滤镜分组视图基础类委托
 */
@protocol TuSDKCPGroupFilterGroupCellDelegate <NSObject>

/**
 *  长按视图
 *
 *  @param cell 滤镜分组视图
 */
- (void)onFilterGroupCellLongClick:(TuSDKCPGroupFilterGroupCellBase *)cell;

/**
 *  删除滤镜组
 *
 *  @param cell 滤镜分组视图
 */
- (void)onFilterGroupCellRemove:(TuSDKCPGroupFilterGroupCellBase *)cell;
@end

/**
 *  滤镜分组视图基础类
 */
@interface TuSDKCPGroupFilterGroupCellBase : TuSDKCPGroupFilterItemCellBase
/**
 *  滤镜分组视图委托
 */
@property (nonatomic, assign) id<TuSDKCPGroupFilterGroupCellDelegate> delegate;

/**
 *  是否隐藏删除标识
 *
 *  @return 是否隐藏删除标识
 */
- (BOOL)canHiddenRemoveFlag;

/**
 *  是否为动作状态
 *
 *  @return 是否为动作状态
 */
- (BOOL)isInActingType;
@end
//
//  TuSDKLiveStickerManager.h
//  TuSDKVideo
//
//  Created by Yanlin Qiu on 24/11/2016.
//  Copyright © 2016 TuSDK. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TuSDKFilterAdapter.h"

#pragma mark - TuSDKLiveStickerManager

/**
 * 动态贴纸数据管理
 */
@interface TuSDKLiveStickerManager : NSObject

/**
 获取 TuSDKLiveStickerManager 实例

 @return TuSDKLiveStickerManager 对象
 */
+ (TuSDKLiveStickerManager *)shared;

/**
 *  显示贴纸
 *
 *  @param sticker    贴纸对象
 */
- (BOOL)addSticker:(TuSDKPFSticker *)sticker;

/**
 *  贴纸是否正在使用
 *
 *  @param sticker    贴纸对象
 *
 *  @return 是否使用
 */
- (BOOL)isStickerExists:(TuSDKPFSticker *)sticker;

/**
 *  删除一张贴纸
 *
 *  @param sticker    贴纸对象
 */
- (void)removeSticker:(TuSDKPFSticker *)sticker;

/**
 *  显示一组贴纸
 *
 *  @param stickerGroup    贴纸组对象
 */
- (BOOL)showStickerGroup:(TuSDKPFStickerGroup *)stickerGroup;

/**
 *  贴纸组是否正在使用
 *
 *  @param stickerGroup    贴纸组对象
 *
 *  @return 是否使用
 */
- (BOOL)isStickerGroupExists:(TuSDKPFStickerGroup *)stickerGroup;

/**
 *  移除所有的贴纸
 */
- (void)removeAllStickers;


/**
 获取当前使用的贴纸数据

 @return 数组
 */
- (NSArray *)getStickers;

/**
 *  显示的贴纸数量
 */
- (NSUInteger)stickerCount;

@end

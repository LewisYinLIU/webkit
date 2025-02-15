/*
 * Copyright (C) 2015 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <WebKit/WKFoundation.h>

#if WK_API_ENABLED

#import <Foundation/Foundation.h>

WK_ASSUME_NONNULL_BEGIN

/*! @constant WKWebsiteDataTypeDiskCache On-disk caches. */
WK_EXTERN NSString * const WKWebsiteDataTypeDiskCache WK_AVAILABLE(WK_MAC_TBA, WK_IOS_TBA);

/*! @constant WKWebsiteDataTypeMemoryCache In-memory caches. */
WK_EXTERN NSString * const WKWebsiteDataTypeMemoryCache WK_AVAILABLE(WK_MAC_TBA, WK_IOS_TBA);

/*! @constant WKWebsiteDataTypeOfflineWebApplicationCache HTML offline web application caches. */
WK_EXTERN NSString * const WKWebsiteDataTypeOfflineWebApplicationCache WK_AVAILABLE(WK_MAC_TBA, WK_IOS_TBA);

/*! @constant WKWebsiteDataTypeCookies Cookies. */
WK_EXTERN NSString * const WKWebsiteDataTypeCookies WK_AVAILABLE(WK_MAC_TBA, WK_IOS_TBA);

/*! @constant WKWebsiteDataTypeLocalStorage HTML local storage. */
WK_EXTERN NSString * const WKWebsiteDataTypeLocalStorage WK_AVAILABLE(WK_MAC_TBA, WK_IOS_TBA);

/*! @constant WKWebsiteDataTypeWebSQLDatabases WebSQL databases. */
WK_EXTERN NSString * const WKWebsiteDataTypeWebSQLDatabases WK_AVAILABLE(WK_MAC_TBA, WK_IOS_TBA);

/*! @constant WKWebsiteDataTypeIndexedDBDatabases IndexedDB databases. */
WK_EXTERN NSString * const WKWebsiteDataTypeIndexedDBDatabases WK_AVAILABLE(WK_MAC_TBA, WK_IOS_TBA);

/*! A WKWebsiteDataRecord represents website data, grouped by domain name using the public suffix list. */
WK_CLASS_AVAILABLE(WK_MAC_TBA, WK_IOS_TBA)
@interface WKWebsiteDataRecord : NSObject

/*! @abstract The display name for the data record. This is usually the domain name. */
@property (nonatomic, readonly, copy) NSString *displayName;

/*! @abstract The various types of website data that exist for this data record. */
@property (nonatomic, readonly, copy) WK_SET(NSString *) *dataTypes;

@end

WK_ASSUME_NONNULL_END

#endif

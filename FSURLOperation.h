//
//  FSURLOperation.h
//
//  Created by Christopher Miller on 10/31/11.
//  Copyright (c) 2011 Christopher Miller. All rights reserved.
//
// Pilfers liberally from Gowalla's AFNetworking. I hope they don't mind.

#import <Foundation/Foundation.h>

typedef void(^FSURLRequestStartedCallback)(NSURLRequest *, NSThread *);
typedef void(^FSURLRequestFinishedCallback)(NSURLRequest *, NSThread *, NSHTTPURLResponse *, NSData *, NSError *);

@interface FSURLOperation : NSOperation

@property (strong) NSURLRequest* request; // changing this after the request has started produces undefined behavior.
@property (strong) NSHTTPURLResponse* response;
@property (strong) NSMutableData* payload;
@property (strong) NSError * error;
@property (strong) NSThread* targetThread; // changing this after the request has started produces undefined behavior.
@property (copy) void(^onFinish)(NSHTTPURLResponse* resp, NSData* payload, NSError* error);
@property (weak) id delegate;
@property (assign) SEL callback;

+ (NSMutableSet *)globalBlockCallbacks_requestStarted;
+ (NSMutableSet *)globalBlockCallbacks_requestFinished;

+ (FSURLOperation*)URLOperationWithRequest:(NSURLRequest*)req
                           completionBlock:(void(^)(NSHTTPURLResponse* resp, NSData* payload, NSError* error))completion;
+ (FSURLOperation*)URLOperationWithRequest:(NSURLRequest*)req
                           completionBlock:(void(^)(NSHTTPURLResponse* resp, NSData* payload, NSError* error))completion
                                  onThread:(NSThread*)thread;

- (id)initWithRequest:(NSURLRequest*)_request;

@end

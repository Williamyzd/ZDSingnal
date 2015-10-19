//
//  Singleton.h
//  recover
//
//  Created by admin on 15/7/28.
//  Copyright (c) 2015年 admin. All rights reserved.
////不加参数更为简单
#define SingletonH(MethodName)  +(instancetype) shared##MethodName;
#if __has_feature(objc_arc)//编译环境是ARC
#define SingletonM(MethodName)  \
static id _instance;\
+(id) allocWithZone:(struct _NSZone *)zone{\
if (_instance ==nil) {\
static   dispatch_once_t onceToken;\
dispatch_once(&onceToken, ^{\
_instance =  [super allocWithZone:zone];\
});\
}\
return _instance;\
}\
-(id)init{\
static  dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{\
_instance = [super init];\
});\
return _instance;\
}\
+(instancetype) shared##MethodName{\
return  _instance = [[super alloc] init];\
}

#else  //变异环境是非ARC
#define SingletonM(MethodName)  \
static id _instance;\
+(id) allocWithZone:(struct _NSZone *)zone{\
if (_instance ==nil) {\
static   dispatch_once_t onceToken;\
dispatch_once(&onceToken, ^{\
_instance =  [super allocWithZone:zone];\
});\
}\
return _instance;\
}\
-(id)init{\
static  dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{\
_instance = [super init];\
});\
return _instance;\
}\
+(instancetype) shared##MethodName{\
return  _instance = [[super alloc] init];\
}\
-(oneway void)release{\
}\
-(id)autorelease{\
    return self;\
}\
-(id)retain{\
    return self;\
}\
-(NSUInteger)retainCount{\
    return 1;\
}
#endif






//
// Created by AS on 2017/3/7.
//

#ifndef JNITEST_LOGUTILS_H
#define JNITEST_LOGUTILS_H

#endif //JNITEST_LOGUTILS_H

#include "android/log.h"
#ifndef LOG_TAG
#define LOG_TAG "CLog"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#endif

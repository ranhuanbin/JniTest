#include "FilePerform.h"
#include "LogUtils.h"
#include <stdio.h>
#include <string.h>

int writeFile(const char *path, const char *msg) {
    FILE *file = fopen(path, "wb");
    int length = sizeof(msg);
    if (file != NULL) {
        int len = fwrite(msg, sizeof(msg), 1, file);
        LOGI("[%s],len=%d", __FUNCTION__, len);
        fclose(file);
        if (len <= 0) {
            LOGI("[%s],写数据失败", __FUNCTION__);
            return 0;
        } else {
            LOGI("[%s],写数据成功", __FUNCTION__);
            return 1;
        }
    }
    return 0;
}


char *readFile(const char *path) {
    FILE *file = fopen(path, "rb");
    if (file != NULL) {
        fseek(file, 0L, SEEK_END);
        long size = ftell(file);
        char *chs = malloc((size_t) size + 1);
        if (chs != NULL) {
            memset(chs, 0, (size_t) size + 1);
            int result = fread(chs, (size_t) size, 1, file);
            for (int i = 0; i < size; ++i) {
                LOGI("[%s],chs[%d] = %d\n", __FUNCTION__, i, chs[i]);
            }
            if (result > 0) {
                fclose(file);
                free(chs);
                return chs;
            } else {
                return NULL;
            }
        }
    }
}

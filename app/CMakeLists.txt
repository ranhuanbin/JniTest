cmake_minimum_required(VERSION 3.4.1)
add_library( # Sets the name of the library.
             # 生成的库名
             sample
             # Sets the library as a shared library.
             # 库类型
             SHARED
             # Provides a relative path to your source file(s).
             # Associated headers in the same location as their source
             # file are automatically included.
             # .c文件路径
             src/main/cpp/sample.c src/main/cpp/FilePerform.c)
find_library( # Sets the name of the path variable.
              log-lib
              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )
target_link_libraries( # Specifies the target library.
                       sample
                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib})

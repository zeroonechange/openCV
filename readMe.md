

此项目主要是学习 openCV     现在市面上  安卓opencv没啥好的学习资料   只能自己慢慢啃







```cpp
android studio 导入 openCV
1.下载 https://opencv.org/releases/
2.AS 创建一个 Native C++ Project
3.导入 opencv的 sdk目录  
4.修改 setting.gradle  
    include "opencv"
    project(":opencv").projectDir = file("sdk")
5.在 app 下 修改  build.grald 在android.defaultConfig.externalNativeBuild.cmake 添加 argue参数
    arguments "-DOpenCV_DIR=" + file('../sdk').absolutePath + "/native/jni",
            "-DANDROID_TOOLCHAIN=clang",
            "-DANDROID_STL=c++_shared"
6.导入module   implementation project(':opencv')
7.在 CMakeLists.txt 添加代码 link
    cmake_minimum_required(VERSION 3.10.2)
    project("demo")
    set(ANDROID_OPENCV_COMPONENTS "opencv_java" CACHE STRING "")
    message(STATUS "ANDROID_ABI=${ANDROID_ABI}")
    find_package(OpenCV REQUIRED COMPONENTS ${ANDROID_OPENCV_COMPONENTS})
    add_library( # Sets the name of the library.
            demo
            SHARED
            native-lib.cpp)
    find_library(
            log-lib
            log)
    target_link_libraries( # Specifies the target library.
            demo
            ${ANDROID_OPENCV_COMPONENTS}
            ${log-lib})
8.sync  在native-lib.cpp  添加 头文件  #include <opencv2/core.hpp>
9.在 MainActivity 中 尝试引用 org.opencv.core.Mat    onResume() 加载 OpenCVLoader.initDebug()

You should link the OpenCV in your JNI CMake rather than copying compiled libraries to jniLibs Folder.
Just follows this tutorial:  https://kcwong-joe.medium.com/how-to-import-opencv-4-5-2-in-android-studio-d9114179628f
```


# OpenCV

## Resources
OpenCV: https://opencv.org/releases.html

Video: https://www.youtube.com/watch?v=7SM5OD2pZKY, https://stackoverflow.com/questions/21079758/opencv-c-drawing-on-image

Github Resources: https://github.com/MicrocontrollersAndMore/OpenCV_3_Windows_10_Installation_Tutorial

## Installation Guide
1. Download OpenCV
2. Create a Folder with the Directory: C:\OpenCV-3.4.3
3. Open OpenCV.exe, and Extract to the: C:\OpenCV-3.4.3 directory
4. Open Environment Variables on Windows, click on Path > Edit > New > C:\OpenCV-3.4.3\opencv\build\x64\vc15\lib (maybe it's \bin not \lib)
NOTE: VC14 = VS2015, VC15 = VS2017
5. Start Visual Studio > New > Empty Project
6. Under sources, right click and add new cpp file (ie Source.cpp/Main.cpp)
7. Verify Visual Studio toolbar has Solution Configurations set to "Debug", and Solution Platforms to "x64"
NOTE: New versions of OpenCV only supports x64 binaries
8. Project > Properties (Active(Debug)) > Configuration Properties > VC++ Directories > Include Directories > Add > C:\OpenCV-3.4.3\opencv\build\include
9. Project > Properties (Active(Debug)) > Configuration Properties > VC++ Directories > Library Directories > Add > C:\OpenCV-3.4.3\opencv\build\x64\vc15\lib
10. Open Windows File Explorer > C:\OpenCV-3.4.3\opencv\build\x64\vc15\lib > Copy the filename "opencv_world343d.lib"
11. Visual Studio > Project > Properties > Configuration Properties > Linker > Input > Additional Dependencies > Edit > opencv_world343d.lib
NOTE: Should Debug build be too slow, change Solution Configuration to Release

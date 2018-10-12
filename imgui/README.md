# imgui

IMPORTANT: 32bit binaries is being tested and seems to work, 64bit does not compile at all (LINKER ERROR).

IMPORTANT: imgui does not work as a standalone library, it requires either OpenGL, Metal, DirectX, Vulkan etc

## Integrating into Project
NOTE: COPY IMGUI FILES AND GLFW + OPENGL FILES INTO PROJECT FILE EXPLORER
1. Add [imgui_impl_glfw.cpp, imgui_impl_glfw.h, imgui_impl_opengl2.cpp, imgui_impl_opengl2.h] into Source Files
2. Create new filer "imgui" and add [imconfig.h, imgui.cpp, imgui.h, imgui_demo.cpp, imgui_draw.cpp, imgui_internal.h, imgui_widgets.cpp, imstb_rectpack.h, imstb_textedit.h, imstb_truetype.h] into it.
3. Add #include "imgui.h", #include "imgui_impl_glfw.h", #include "imgui_impl_opengl2.h", #include <GLFW\glfw3.h> into main.cpp
4. Properties > VC++ > Include Directories: C:\Users\efoo1\Desktop\glfw-3.2.1.bin.WIN32\include
5. Properties > VC++ > Library Directories: C:\Users\efoo1\Desktop\glfw-3.2.1.bin.WIN32\lib-vc2015
6. Linker > Input > Additional Dependencies > glfw3.lib & opengl32.lib

### TO READ
- http://www.glfw.org/docs/latest/quick.html#quick_include

#### Source
- https://stackoverflow.com/questions/20223198/visual-studio-11-glfw-external-symbol-error
- https://www.youtube.com/watch?v=XiWNi5Gk0zc&t=8s

## Installing Example
- Clone GitHub project: https://github.com/ocornut/imgui
- Open examples > imgui_examples.sln
- Use example_glfw_opengl2
- Properties > General > Windows SDK Version > 10.0.x
- Properties > Linker > Input > Additional Dependencies > add ;legacy_stdio_definitions.lib

### Changing Default Font
- https://github.com/ocornut/imgui/issues/1102

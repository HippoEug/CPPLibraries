# SFML-Realsense

Video Link: https://www.youtube.com/watch?v=-mcnW_6QpYA&t=4s

## Installation Guide
1. Download Link: https://www.sfml-dev.org/download.php
2. Download 32-bit version (Recommended)
Note: 3 Important Files: lib, include & bin
4. Open Visual Studio & create new Empty Project
5. Open Project on File Explorer
6. Create new folder "smfl" and copy lib, include & bin into it
![image](https://user-images.githubusercontent.com/21957042/46274061-9887de80-c58a-11e8-8dd9-eb9a8e97b94f.png)
![image](https://user-images.githubusercontent.com/21957042/46274190-2a8fe700-c58b-11e8-8edd-adf90671da1c.png)
7. Open Visual Studio > Properties > Configuration (TOP) > All Configurations
8. Linker > General > Additional Library Directories > File Explorer > Select "lib" folder > Apply
9. Linker > Input > Additional Dependencies > add: smfl-system.lib, smfl-graphics.lib, smfl-audio.lib,

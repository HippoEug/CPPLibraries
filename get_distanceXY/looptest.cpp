#include <iostream>
#include <fstream>
#include <chrono>

#include <librealsense2\rs.hpp>

int main() {
	char i;
	int x = 0;
	int y = 0;
	int percent = 10;

	std::ofstream myfile;
	myfile.open("test.csv");

	std::cout << "Start operation? (y/n):";
	std::cin >> i;

	if (i == 'y') {
		rs2::pipeline pipe;
		pipe.start();

		std::cout << "Calculating..." << std::endl;

		std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

		for (int x = 0; x < 40000; x++) {
			rs2::frameset frames = pipe.wait_for_frames();
			rs2::depth_frame depth = frames.get_depth_frame();
			myfile << x << "," << depth.get_distance(x, 0) << std::endl;
		}

		std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
		std::cout << "\nDONE" << std::endl;
		std::cout << "The operation took: " << duration << "ms" << std::endl;
	}

	myfile.close();

	std::cin.get();
	std::cin.ignore();
}

#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;


int main() {
	char y;
	volatile int i;

	std::ofstream myfile;
	myfile.open("test.csv");

	std::cout << "Start operation? (y/n):";
	std::cin >> y;

	if (y == 'y') {
		std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
		for (i = 0; i < 921600; i++) {
			myfile << "a,b,c\n";
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

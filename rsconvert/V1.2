#include <iostream>
#include <vector>
#include <string>

#include <librealsense2\rs.hpp>
#include "converter.hpp"
#include "converter-csv.hpp"

int main() {
	std::string fileName, bagName;

	auto pipe = std::make_shared<rs2::pipeline>();
	rs2::config cfg;
	std::vector<std::shared_ptr<rs2::tools::converter::converter_base>> converters;

	std::cout << "INITIALIZATION COMPLETE" << std::endl;
	std::cout << "Enter File Name: ";
	std::cin >> fileName;
	std::cout << "Enter Bag Name: ";
	std::cin >> bagName;

	converters.push_back(std::make_shared<rs2::tools::converter::converter_csv>(fileName));
	cfg.enable_device_from_file(bagName);
	pipe->start(cfg);

	auto device = pipe->get_active_profile().get_device();
	rs2::playback playback = device.as<rs2::playback>();
	playback.set_real_time(false);

	auto duration = playback.get_duration();
	int progress = 0;
	auto frameNumber = 0ULL;

	while (true) {
		auto frameset = pipe->wait_for_frames();
		
		int posP = static_cast<int>(playback.get_position() * 100. / duration.count()); // Current position probably

		if (posP > progress) { // If current position > previous progress, update to new progress %
			progress = posP;
		}

		if (frameset[0].get_frame_number() == 5 || frameset[0].get_frame_number() == 6 || frameset[0].get_frame_number() == 7) { // If end of frame, bag loops again, hence get_frame_number resets to 1 and is smaller
			std::for_each(converters.begin(), converters.end(), [&frameset](std::shared_ptr<rs2::tools::converter::converter_base>& converter) {
				converter->convert(frameset);
			});

			std::for_each(converters.begin(), converters.end(), [](std::shared_ptr<rs2::tools::converter::converter_base>& converter) {
				converter->wait();
			});

			break;
		}

		frameNumber = frameset[0].get_frame_number();
	}

	std::cout << std::endl;
	std::for_each(converters.begin(), converters.end(), [](std::shared_ptr<rs2::tools::converter::converter_base>& converter) {
		std::cout << converter->get_statistics() << std::endl;
	});

	std::cin.get();
	std::cin.ignore();
}

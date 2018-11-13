#include <iostream>
#include <vector>

#include <librealsense2\rs.hpp>
#include "converter.hpp"
#include "converter-csv.hpp"

int main() {
	std::cout << "Program Started Successfully" << std::endl;

	std::vector<std::shared_ptr<rs2::tools::converter::converter_base>> converters;
	converters.push_back(std::make_shared<rs2::tools::converter::converter_csv>("testtest"));

	auto pipe = std::make_shared<rs2::pipeline>();
	rs2::config cfg;
	cfg.enable_device_from_file("a.bag");
	pipe->start(cfg);

	auto device = pipe->get_active_profile().get_device();
	rs2::playback playback = device.as<rs2::playback>();
	playback.set_real_time(false);

	auto duration = playback.get_duration();
	int progress = 0;
	auto frameNumber = 0ULL;

	while (true) {
		auto frameset = pipe->wait_for_frames();
		
		int posP = static_cast<int>(playback.get_position() * 100. / duration.count());

		if (posP > progress) {
			progress = posP;
			std::cout << posP << "%" << "\r" << std::flush;
		}

		if (frameset[0].get_frame_number() < frameNumber) {
			break;
		}

		frameNumber = frameset[0].get_frame_number();

		std::for_each(converters.begin(), converters.end(), [&frameset](std::shared_ptr<rs2::tools::converter::converter_base>& converter) {
			converter->convert(frameset);
		});

		std::for_each(converters.begin(), converters.end(), [](std::shared_ptr<rs2::tools::converter::converter_base>& converter) {
			converter->wait();
		});
	}

	std::cout << std::endl;
	std::for_each(converters.begin(), converters.end(), [](std::shared_ptr<rs2::tools::converter::converter_base>& converter) {
		std::cout << converter->get_statistics() << std::endl;
	});

	std::cin.get();
	std::cin.ignore();
}

#include <iostream>
#include <string>
#include <getopt.h>

int main(int argc, char *argv[]) {
    std::string value;
    int opt;
    struct option long_options[] = {
        {"string", required_argument, 0, 's'},
        {0, 0, 0, 0}
    };

    while ((opt = getopt_long(argc, argv, "s:", long_options, NULL)) != -1) {
        switch (opt) {
            case 's':
                value = optarg;
                break;
            default:
                std::cerr << "Usage: " << argv[0] << " --string value" << std::endl;
                return 1;
        }
    }

    if (value.empty()) {
        std::cerr << "The string value must be specified." << std::endl;
        return 1;
    }

    std::string line;
    bool found = false;
    while (std::getline(std::cin, line)) {
        if (line.substr(0, value.size()) == value) {
            std::cout << line << std::endl;
            found = true;
        }
    }

    return found ? 0 : 1;
}
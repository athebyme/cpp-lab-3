#include "ConsoleDisplayService.h"
#include <iostream>

namespace Service {
    void ConsoleDisplayService::displayError() {
        std::cerr << "error\n";
    }
}

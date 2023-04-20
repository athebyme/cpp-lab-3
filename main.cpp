#include "src/App.h"
#include "src/Service/ConsoleDisplayService.h"
#include "src/Service/FileService.h"

int main(int argc, char* argv[]) {
    return App::create(
            new Service::ConsoleDisplayService()
    )->start(argc, argv);
}
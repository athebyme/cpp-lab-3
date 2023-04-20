#include "App.h"
#include <iostream>
#include "Service/FileService.h"

int App::start(int argc, char* argv[]) {
    auto filename = argv[1];

    try {
        this->fileService->open(filename);
        this->fileService->writeString(argv[2]);
        this->fileService->close();
    } catch (std::exception const &e) {
        this->displayService->displayError();
        return -1;
    }

    return 0;
}

App::App(
        Service::FileService *fileService,
        Service::DisplayServiceInterface* displayService
) {
    this->fileService    = fileService;
    this->displayService = displayService;
}

App *App::create(Service::FileService* fileService, Service::DisplayServiceInterface* displayService) {
    return new App(fileService, displayService);
}
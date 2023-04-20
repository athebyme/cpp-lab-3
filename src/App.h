//
// Created by Anton on 04.04.2023.
//

#ifndef PATTERN_APP_H
#define PATTERN_APP_H
#include "Service/FileService.h"
#include "Service/DisplayServiceInterface.h"

class App {
private:
    Service::FileService* fileService;
    Service::DisplayServiceInterface* displayService;
public:
    explicit App(
            Service::FileService* fileService,
            Service::DisplayServiceInterface* displayService
    );
    int start(int argc, char* argv[]);
    static App* create(Service::FileService* fileService, Service::DisplayServiceInterface* displayService);
};

#endif //PATTERN_APP_H

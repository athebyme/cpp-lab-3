#ifndef PATTERN_APP_H
#define PATTERN_APP_H
#include "Service/DisplayServiceInterface.h"

class App {
private:
    Service::DisplayServiceInterface* displayService;
public:
    explicit App(
            Service::DisplayServiceInterface* displayService
    );
    int start(int argc, char* argv[]);
    static App* create(Service::DisplayServiceInterface* displayService);
};

#endif

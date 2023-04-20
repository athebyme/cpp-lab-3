//
// Created by Anton on 04.04.2023.
//

#ifndef PATTERN_CONSOLEDISPLAYSERVICE_H
#define PATTERN_CONSOLEDISPLAYSERVICE_H
#include "DisplayServiceInterface.h"

namespace Service {
    class ConsoleDisplayService: public Service::DisplayServiceInterface {
        void displayError() override;
    };
}
#endif //PATTERN_CONSOLEDISPLAYSERVICE_H

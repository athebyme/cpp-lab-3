#include "App.h"
#include <iostream>
#include "Geometry/Square.h"
#include "Service/ExceptionService.h"

using namespace std;
int App::start(int argc, char* argv[]) {
    Geometry::Square* square = nullptr;
    try {
        square = Geometry::Square::create(argc, argv);
        Geometry::Square comparableSquare = Geometry::Square(0, 0, 5, 0);
        if((*square == comparableSquare)) this->displayService->displayInformation("Same");
        else{
            this->displayService->displayInformation("Not same\n");
            this->displayService->displayInformation("Your Square | side: %.2f  x: %.2f y: %.2f angle: %.2f \n", square->getSide(), square->getX(), square->getY(), square->getAngle());
            this->displayService->displayInformation("Comparable Square | side: %.2f  x: %.2f y: %.2f angle: %.2f \n",comparableSquare.getSide(),comparableSquare.getX(), comparableSquare.getY(), comparableSquare.getAngle());
        }
    }catch (const CustomExceptions::NotEnoughArgumentsException& e) {
        this->displayService->displayError(e);
        return -1;
    }
    catch (std::exception const &e) {
        this->displayService->displayError(e);
        return -1;
    }
    return 0;
}

App::App(
        Service::DisplayServiceInterface* displayService
) {
    this->displayService = displayService;
}

App *App::create(Service::DisplayServiceInterface* displayService) {
    return new App(displayService);
}
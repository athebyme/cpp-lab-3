#include "App.h"
#include <iostream>
#include "Geometry/Square.h"
int App::start(int argc, char* argv[]) {
    Geometry::Square* square = nullptr;
    try {
        square = Geometry::Square::create(argc, argv);
        Geometry::Square comparableSquare = Geometry::Square(0, 0, 5, 0);
        std::cout << square->getAngle() << std::endl;
        std::cout << square->getSide()<< std::endl;
        if((*square == comparableSquare)) std::cout << "Same"<< std::endl;
        else{
            std::cout << "Not Same"<< std::endl;
            std::cout <<"Your Square | side: " << square->getSide() << " x: "<<square->getX()  << " y: " << square->getY()<< " angle: " << square->getAngle() <<std::endl;
            std::cout << "Comparable Square | side: " << comparableSquare.getSide() << " x: "<<comparableSquare.getX()  << " y: " << comparableSquare.getY()<<  " angle: " << comparableSquare.getAngle() << std::endl;
        }
    }catch (std::exception const &e) {
        this->displayService->displayError();
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
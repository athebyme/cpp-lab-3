#include "FileService.h"
#include <string>

namespace Service {
    void FileService::open(const std::string& filename) {
        this->out.open(filename);

        if (!this->out.is_open()) {
            throw std::exception();
        }
    }

    void FileService::close() {
        if (!this->out.is_open()) {
            throw std::exception();
        }
        this->out.close();
    }

    void FileService::writeString(const std::string& str) {
        this->out << str;
    }
}
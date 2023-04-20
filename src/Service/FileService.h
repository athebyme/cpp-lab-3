//
// Created by Anton on 04.04.2023.
//

#ifndef PATTERN_FILESERVICE_H
#define PATTERN_FILESERVICE_H
#include "fstream"

namespace Service {
    class FileService {
    private:
        std::ofstream out;

    public:
        void open(const std::string& filename);
        void close();
        void writeString(const std::string &str);
    };
}
#endif //PATTERN_FILESERVICE_H

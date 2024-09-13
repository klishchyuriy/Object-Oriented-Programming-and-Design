#ifndef ASSIGNMENTONE_FILEREADER_H
#define ASSIGNMENTONE_FILEREADER_H

#include <string>
#include <vector>
#include "Airplane.h"

class FileReader {
public:
    static std::vector<Airplane> readConfigFile(const std::string &filePath);
};

#endif

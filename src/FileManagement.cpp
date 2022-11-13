// Austin Swanlaw
#ifndef FILEMANAGEMENT
#define FILEMANAGEMENT 
#include "../include/FileManagement.hpp"
#include <stdexcept>

// constructor
FileManagement::FileManagement(const std::string str) {
    this->file.open(str);
}

// destructor
FileManagement::~FileManagement() {
    this->file.close();
}

// check if we have reached the end of the file yet
bool FileManagement::isEmpty() const {
    return this->file.eof();
}

// get the next line and input it into
// the line value for the object.
void FileManagement::getNextLine() {
    if (this->isEmpty()) {
        throw std::runtime_error("No more lines to get, the file is empty.");
    }
    else{
        std::getline(this->file, this->line);
    }
}

#endif /* ifndef FILEMANAGEMENT */


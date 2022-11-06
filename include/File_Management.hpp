// Austin Swanlaw
#define FILEMANAGEMENT
#include <fstream>
#include <string>

class FileManagement {
public:
    FileManagement(std::string);
    virtual ~FileManagement();

    // if we reached the end of the file or if the
    // file is empty, then this returns true
    bool isEmpty();

    // returns the next line in the file
    std::string returnLine();

private:
    std::fstream file;
    std::string line;
};

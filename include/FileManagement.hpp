// Austin Swanlaw
#define FILEMANAGEMENT
#include <fstream>
#include <string>

class FileManagement {
public:
    FileManagement(const std::string);
    virtual ~FileManagement();

    // if we reached the end of the file or if the
    // file is empty, then this returns true
    bool isEmpty() const;

    // get the next line in the file
    void getNextLine();

private:
    // the file we are working with
    std::fstream file;
    // the line we are getting from the file
    std::string line;
};


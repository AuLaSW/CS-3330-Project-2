// Austin Swanlaw
#define FILEMANAGEMENT
#include <fstream>
#include <string>

class FileManagement {
public:
    // constructor
    FileManagement(const std::string);
    // destructor
    virtual ~FileManagement();

    // if we reached the end of the file or if the
    // file is empty, then this returns true
    bool isEmpty() const;

    // get the next line in the file
    std::string getNextLine();

private:
    // the file we are working with
    std::fstream file;
    // the line we are getting from the file
    std::string line;
};


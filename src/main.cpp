#include "../include/FileManagement.hpp"
#include "../include/CLQueue.hpp"

int main(int argc, char *argv[])
{
    // the file that we are reading the shooters from
    const std::string SHOOTER_FILE;
    
    // open the file
    FileManagement *file = new FileManagement(SHOOTER_FILE);

    // Create queue
    CLQueue *queue = new CLQueue();

    // read the file contents into a queue
    while (!file->isEmpty()) {
        queue->enqueue(*(new Shooter(file->getNextLine())));
    }

    // shooting sequence
    while (!queue->isEmpty()) {
        Shooter temp = queue->front();
        queue->dequeue();

        temp.shooting();
        temp.display();

        if (temp.getQuantity() != 0) {
            queue->enqueue(temp);
        }
    }

    return 0;
}

#include "../include/FileManagement.hpp"
#include "../include/CLQueue.hpp"

int main(int argc, char *argv[])
{
    // the file that we are reading the shooters from
    const std::string SHOOTER_FILE = "../src/Week3-bulletCount.txt";
    
    // open the file
    FileManagement *file = new FileManagement(SHOOTER_FILE);

    // Create queue
    CLQueue *queue = new CLQueue();

    // read the file contents into a queue
    // loop through the file until the end of the file is reached.
    while (!file->isEmpty()) {
        queue->enqueue(*(new Shooter(file->getNextLine())));
    }

    // shooting sequence
    while (!queue->isEmpty()) {
        // create a temporary holder for
        // the shooter
        Shooter temp = queue->front();
        // remove the shooter from the queue
        queue->dequeue();

        // let the shooter shoot
        temp.shooting();

        // if the shooter has bullets left, then
        // put them back into the queue
        if (temp.getQuantity() != 0) {
            queue->enqueue(temp);
        }
    }

    return 0;
}

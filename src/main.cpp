#include "../include/FileManagement.hpp"
#include "../include/CLQueue.hpp"
#include <fstream>
#include <string>
#include <iostream>

int main(int argc, char *argv[])
{
    // the file that we are reading the shooters from
    const std::string SHOOTER_FILE = "../src/Week3-bulletCount.txt";
    
    // open the file
    std::fstream file (SHOOTER_FILE);
    std::string line;
    int bullets;

    // Create queue
    CLQueue *queue = new CLQueue();


    // read the file contents into a queue
    while (file >> line >> bullets) {
        std::cout << line << bullets << std::endl;
        Shooter *shooter = new Shooter(line, bullets);
        queue->enqueue(*shooter);
    }

    // shooting sequence
    while (!queue->isEmpty()) {
        Shooter temp = queue->front();
        queue->dequeue();

        temp.shooting();

        if (temp.getQuantity() != 0) {
            queue->enqueue(temp);
        }
    }

    return 0;
}

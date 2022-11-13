// Austin Swanlaw
#define CATACH_CONFIG_MAIN
#include "../../lib/Catch2/extras/catch_amalgamated.hpp"
#include "../../../include/CLQueue.hpp"

typedef CLQueue Queue;
SCENARIO("Creating and Deleting a queue", "[queue]") {
    GIVEN("An empty queue") {
        Queue *queue = new CLQueue();

        THEN("the queue should be empty") {
            REQUIRE(queue->isEmpty());

            AND_THEN("the queue should have size 0") {
                REQUIRE(queue->size() == 0);
            }
        }

        WHEN("a new node is added to the queue") {
            const Shooter *temp = new Shooter();
            queue->enqueue(*temp);

            THEN("that node should be the first node") {
                REQUIRE(queue->front() == *temp);
            }

            AND_WHEN("the node is removed") {
                queue->dequeue();

                THEN("the queue should be empty") {
                    REQUIRE(queue->isEmpty());
                }
            }
        }

        WHEN("the node is deleted") {
            delete queue;
            THEN("this assertion should pass") {
                REQUIRE(true);
            }
        }
    }
}


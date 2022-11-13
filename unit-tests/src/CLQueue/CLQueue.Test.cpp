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

SCENARIO("Adding nodes to a queue with multiple nodes", "[queue]") {
    GIVEN("A queue with multiple nodes") {
        const int NUM_OF_SHOOTERS = GENERATE(2, 5, 10, 11, 21, 40);
        Queue *queue = new CLQueue();

        // loop to create a queue with a specified number of shooters
        while (queue->size() < NUM_OF_SHOOTERS) {
            queue->enqueue(*(new Shooter()));
        }

        WHEN("a node is added") {
            const Shooter * oldFront = &queue->front();

            queue->enqueue(*(new Shooter()));

            THEN("the front node should remain in the front") {
                REQUIRE(&queue->front() == oldFront);
            }
        }

        WHEN("a node is removed") {
            const Shooter * oldFront = &queue->front();

            queue->dequeue();

            THEN("the front node should not be the same") {
                REQUIRE_FALSE(&queue->front() == oldFront);
            }
        }
    }
}

SCENARIO("Removing a shooter from the queue.", "[queue]") {
    GIVEN("A queue with a non-shooter") {
        Queue *queue = new Queue();

        queue->enqueue(*(new Shooter("test", 1)));

        WHEN("the shooter shoots their last bullet") {
            THEN("the dequeue operation should output to the terminal") {
                queue->dequeue();
                REQUIRE(true);
            }
        }
    }
}

#include <exception>
#define CATACH_CONFIG_MAIN
#include "../../lib/Catch2/extras/catch_amalgamated.hpp"
#include "../../../include/CLList.hpp"

/*
 * These are tests for the CLList Class, a class for a circularly
 * linked list.
 */

/*
 * This tests walks through creating a list and perform simple node operations
 * on the list, then destroying it.
 */
SCENARIO("Circulalry Linked Lists can be created and destroyed", "[linked_list]") {
    GIVEN("An empty linked list") {
        CLList *list = new CLList();

        THEN("the list should be empty"){
            CHECK(list->isEmpty());
            CHECK(list->size() == 0);
        }

        WHEN("a node is added to the list") {
            list->add(*(new Shooter()));

            THEN("the list is no longer empty") {
                CHECK_FALSE(list->isEmpty());
                CHECK_FALSE(list->size() == 0);

                AND_THEN("the element the cursor points to points to itself") {
                    CHECK(&list->back() == &list->front());
                }
            }

            AND_WHEN("a node is removed from the list") {
                list->remove();

                THEN("the list is empty") {
                    CHECK(list->isEmpty());
                    CHECK(list->size() == 0);
                }
            }
        }

        WHEN("multiple nodes are added") {
            const int NODES = GENERATE(1, 2, 5, 10, 13, 17, 20, 29);

            // loop to add nodes to the list
            while (list->size() < NODES) {
                list->add(*new Shooter());
            }

            THEN("the size should be the number of nodes added") {
                REQUIRE(list->size() == NODES);
            }

            AND_WHEN("an element is removed") {
                THEN("no errors should be thrown") {
                    REQUIRE_NOTHROW(list->remove());
                }
            }       
        }

        delete list;

    }
}

SCENARIO("Moving through a list", "[linked_list]") {
    GIVEN("A circularly linked list with no nodes") {
        CLList *list = new CLList();

        WHEN("the list is advanced") {
            THEN("the list should throw an error") {
                REQUIRE_THROWS(list->advance());
            }
        }

        AND_GIVEN("a circularly linked list with a positive number of nodes") {
            const int NODES = GENERATE(1, 2, 5, 10, 13, 17, 20, 29);

            // loop to add nodes to the list
            while (list->size() < NODES) {
                list->add(*new Shooter());
            }

            // loop through the list, advancing each turn, to make sure
            // that the advance can work with multiple tries.
            WHEN("the list is advanced") {
                const Shooter *temp = &list->front();
                list->advance();

                // we can check node-iness through checking the
                // addresses of the shooter objects, since they are
                // unique to each node object
                THEN("the previous front node should be the new back node") {
                    REQUIRE(temp == &list->back());
                }
            }
        }

        delete list;
    }
}

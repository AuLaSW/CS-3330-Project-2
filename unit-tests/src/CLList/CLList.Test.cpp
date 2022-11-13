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

        delete list;

    }
}

SCENARIO("Moving through a list", "[linked_list]") {
    GIVEN("A circularly linked list") {
        const int NODES = GENERATE(2, 5, 10, 13, 17, 20, 29);
        CLList *list = new CLList();

        // loop to add nodes to the list
        while (list->size() < NODES) {
            list->add(*new Shooter());
        }

        WHEN("the list is advanced") {
            CLList *temp = list;
            list->advance();

            // the two objects should be the same since we are pointing 
            // to the same node
            THEN("the previous front node should be the new back node") {
                REQUIRE(&temp->front() == &list->back());
            }
        }

        delete list;
    }
    
    GIVEN("A circularly linked list with one node") {
        const int NODES = 1;
        CLList *list = new CLList();

        // loop to add nodes to the list
        while (list->size() < NODES) {
            list->add(*new Shooter());
        }

        WHEN("the list is advanced") {
            CLList *temp = list;
            list->advance();

            THEN("nothing should change") {
                REQUIRE(&temp->front() == &list->back());
            }
        }

        delete list;
    }

    GIVEN("A circularly linked list with no nodes") {
        CLList *list = new CLList();

        WHEN("the list is advanced") {
            THEN("the list should throw an error") {
                REQUIRE_THROWS(list->advance());
            }
        }

        delete list;
    }
}

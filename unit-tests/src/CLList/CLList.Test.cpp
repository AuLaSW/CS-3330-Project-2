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

                AND_THEN("the list can be deleted"){
                    delete list;
                    REQUIRE(true);
                }
            }

            AND_WHEN("the node is removed from the list") {
                list->remove();

                THEN("the list is empty") {
                    CHECK(list->isEmpty());
                    CHECK(list->size() == 0);
                }
            }
        }
    }

    GIVEN("A list with multiple nodes are added") {
        const int NODES = GENERATE(1, 2, 5, 10, 13, 17, 20, 29);
        CLList *list = new CLList();

        // loop to add nodes to the list
        while (list->size() < NODES) {
            list->add(*new Shooter());
        }

        THEN("the size should be the number of nodes added") {
            REQUIRE(list->size() == NODES);
        }

        WHEN("an element is removed") {
            THEN("no errors should be thrown") {
                REQUIRE_NOTHROW(list->remove());

                AND_THEN("the size should decrease by one") {
                    REQUIRE(list->size() == NODES - 1);
                }
            }
        }       

        WHEN("All of the elements but the last are removed") {
            while(list->size() > 0){
                list->remove();
            }

            THEN("the size of the list is 0") {
                REQUIRE(list->size() == 0);
            }
        }

        WHEN("an element is added") {
            const Shooter * const oldBack = &list->back();
            const Shooter * const oldFront = &list->front();
            Shooter * tempShooter = new Shooter();
            list->add(*tempShooter);

            THEN("the back node should remain the same") {
                REQUIRE(&list->back() == oldBack);

                // this isn't a fool-proof test, since it is just checking
                // that the two shooters equal each other on a member-object
                // level. Two nodes can have the exact same shooter, so the
                // test shouldn't be a requirement, just a check that they
                // are the same to validate they are very likely the same node.
                AND_THEN("the front node should be the new node") {
                    CHECK(list->front() == *tempShooter);

                    AND_THEN("the next node should be the old front node") {
                        list->advance();
                        REQUIRE(&list->front() == oldFront);
                    }
                }
            }
        }
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
                    REQUIRE(&list->back() == temp);
                }
            }

            WHEN("the list is adanced all the way through") {
                int count = 0;
                const Shooter *tempBack = &list->back();
                const Shooter *tempFront = &list->front();

                while (count < list->size()) {
                    list->advance();
                    count++;
                }

                // here we are comparing the two shooter objects' positions
                // to make sure they are the same objects being pointed to.
                THEN("the list should be back where it started") {
                    REQUIRE(&list->back() == tempBack);
                    REQUIRE(&list->front() == tempFront);
                }
            }
        }

    }
}

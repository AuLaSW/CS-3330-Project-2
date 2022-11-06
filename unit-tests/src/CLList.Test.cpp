#include "../lib/Catch2/extras/catch_amalgamated.hpp"
#include "../../include/CLList.hpp"

/*
 * These are tests for the CLList Class, a class for a circularly
 * linked list.
 */

/*
 * This tests walks through creating a list and perform simple node operations
 * on the list, then destroying it.
 */
SCENARIO("Circulalry Linked Lists can be created and destroyed", "[linked list]") {
    GIVEN("An empty linked list") {
        CLList<int> *list = new CLList<int>;

        CHECK(list->isEmpty());
        CHECK(list->size() == 0);

        WHEN("a node is added to the list") {
            list->add(5);

            THEN("the list is no longer empty") {
                CHECK_FALSE(list->isEmpty());
                CHECK_FALSE(list->size() == 0);
            }
        }
    }
}

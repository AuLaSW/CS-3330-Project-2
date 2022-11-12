#include <exception>
#define CATACH_CONFIG_MAIN
#include "../../lib/Catch2/extras/catch_amalgamated.hpp"
#include "../../../include/Shooter.hpp"

/*
 * These are tests for the CLList Class, a class for a circularly
 * linked list.
 */

/*
 * This tests walks through creating a list and perform simple node operations
 * on the list, then destroying it.
 */
SCENARIO("Creating and deleting a shooter", "[shooter]") {
    GIVEN("An empty shooter") {
        Shooter *shooter = new Shooter();

        THEN("the values should be defaults") {
            REQUIRE(shooter->getName() == "");
            REQUIRE(shooter->getQuantity() == 0);
        }
    }
}

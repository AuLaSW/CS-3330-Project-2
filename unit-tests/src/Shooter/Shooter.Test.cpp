#include <exception>
#include <string>
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

    GIVEN("A shooter with some positive quantity of bullets"){
        const std::string NAME = "testShooter";
        const int BULLETS = 10;
        Shooter *shooter = new Shooter(NAME, BULLETS);

        THEN("the bullet count should be zero"){
            REQUIRE(shooter->getQuantity() == BULLETS);
        }

        THEN("the name should be the same as what was inputted"){
            REQUIRE(shooter->getName() == NAME);
        }

        WHEN("a bullet is fired"){
            // fires a bullet
            shooter->shooting();

            THEN("the bullet count should increase"){
                REQUIRE(shooter->getQuantity() == 1);
            }
        }
    }
}

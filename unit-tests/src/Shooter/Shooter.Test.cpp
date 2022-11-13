#include <exception>
#include <string>
#define CATACH_CONFIG_MAIN
#include "../../lib/Catch2/extras/catch_amalgamated.hpp"
#include "../../../include/Shooter.hpp"

/*
 * These are tests for the Shooter Class, a class for a circularly
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

        THEN("the shooter can be deleted") {
            delete shooter;
            REQUIRE(true);
        }

        WHEN("a bullet is fired"){
            THEN("an error should be thrown"){
                REQUIRE_THROWS(shooter->shooting());
            }
        }       
    }

    GIVEN("A shooter with some positive quantity of bullets"){
        const std::string NAME = "testShooter";
        const int BULLETS = GENERATE(1, 2, 3);
        Shooter *shooter = new Shooter(NAME, BULLETS);

        THEN("the bullet count should be the number of bullets inputted"){
            REQUIRE(shooter->getQuantity() == BULLETS);
        }

        THEN("the name should be the same as what was inputted"){
            REQUIRE(shooter->getName() == NAME);
        }

        WHEN("a bullet is fired"){
            // fires a bullet
            shooter->shooting();

            THEN("the bullet count should decrease"){
                REQUIRE(shooter->getQuantity() == BULLETS - 1);
            }
        }

        WHEN("the bullet count has reached zero") {
            while(shooter->getQuantity() > 0) {
                shooter->shooting();
            }

            THEN("getQuantity() should return 0") {
                REQUIRE(shooter->getQuantity() == 0);
            }

            THEN("if you try to shoot again, it will throw an error") {
                REQUIRE_THROWS(shooter->shooting());
            }
        }
    }

    GIVEN("A shooter with a negative quantity of bullets") {
        const std::string NAME = "testShooter";
        const int BULLETS = GENERATE(-1, -2, -3, -10, -15, -100);

        THEN("the constructor should throw an error") {
            REQUIRE_THROWS(new Shooter(NAME, BULLETS));
        }
    }
}

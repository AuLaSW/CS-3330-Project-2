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
 * This test scenario creates and destroys different shooter objects
 * to make sure that all of the different methods work.
 */
SCENARIO("Creating, deleting, and using a shooter", "[shooter]") {
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

    GIVEN("An existing shooter") {
        const int BULLETS = GENERATE(0, 1, 2, 5, 10, 11, 20, 23);
        const std::string NAMES = GENERATE("A", "shooter", "test");
        Shooter *existShooter = new Shooter(NAMES, BULLETS);

        WHEN("the shooter is copied"){
            Shooter *copyShooter = existShooter;

            THEN("the existing shooter should be deep-copied"){
                REQUIRE(copyShooter->operator==(*existShooter));
            }
        }
    }
}

SCENARIO("Creating a shooter object from a file", "[shooter]") {
    GIVEN("A string from a file representing a shooter") {
        const std::string INPUT = "Amanda 13";
        const std::string NAME = "Amanda";
        const int BULLETS = 13;
        
        WHEN("a new shooter is generated") {
            Shooter *shooter = new Shooter(INPUT);

            THEN("the name should match") {
                REQUIRE(shooter->getName() == NAME);
            }

            THEN("the number of bullets should match") {
                REQUIRE(shooter->getQuantity() == BULLETS);
            }
        }
    }
}

#define CATACH_CONFIG_MAIN
#include "../../lib/Catch2/extras/catch_amalgamated.hpp"
#include "../../../include/CLNode.hpp"

SCENARIO("Circularly Linked Nodes can be created and destroyed") {
    GIVEN("A node") {
        CLNode *node = new CLNode();

        THEN("the node can be deleted") {
            delete node;
            REQUIRE(true);
        }
    }

    GIVEN("A node with an empty shooter") {
        CLNode *node = new CLNode(*(new Shooter()));

        THEN("the node can be deleted") {
            delete node;
            REQUIRE(true);
        }
    }
}

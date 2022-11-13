#define CATACH_CONFIG_MAIN
#include "../../lib/Catch2/extras/catch_amalgamated.hpp"
#include "../../../include/CLNode.hpp"

SCENARIO("Circularly Linked Nodes can be created and destroyed", "[node]") {
    GIVEN("An empty node") {
        CLNode *node = new CLNode();

        THEN("the node should have default values") {
            REQUIRE(&node->getNext() == nullptr);
            REQUIRE((node->getElement()).operator==(*new Shooter()));
        }

        THEN("the node can be deleted") {
            delete node;
            REQUIRE(true);
        }
    }

    GIVEN("A node with a non-empty shooter") {
        const std::string NAMES = GENERATE("A", "test", "shooter");
        const int BULLETS = GENERATE(0, 1, 2, 5, 10, 21, 23);
        Shooter *shooter = new Shooter(NAMES, BULLETS);
        CLNode *node = new CLNode();
        node->add(*shooter);

        THEN("the node can be deleted") {
            delete node;
            REQUIRE(true);
        }

        WHEN("copied into an empty node") {
            CLNode *emptyNode = new CLNode(*node);

            THEN("they should have matching values") {
                REQUIRE(emptyNode->getElement() == node->getElement());
                REQUIRE(&emptyNode->getNext() == &node->getNext());
            }
        }
    }
}

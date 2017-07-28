#include <iostream>

#include "game2048/version.h"
#include "game2048/GameState.h"

using namespace solve2048::game2048;

int main(int argc, char* argv[])
{
    std::cout << "version " << Version::getString() << std::endl;
    std::cout << "revision " << Version::getRevision() << std::endl;
}

#include "Hexagon.hpp"
#include <iostream>
#include <cstdlib>

Hexagon::Hexagon (Color c, Unit u)
{
    color = c;
    unit = u;
    isSea = false;
}

Hexagon::Hexagon (bool sea)
{
    if (!sea)
    {
        std::cout << "Parameter of sea passed as false";
        exit (EXIT_FAILURE);
    }

    isSea = sea;
    color = Color_None;
    unit = Unit_None;
}

Hexagon::Hexagon ()
{
    color = Color_None;
    unit = Unit_None;
    isSea = false;
}

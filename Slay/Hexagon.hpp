#ifndef HEXAGON_HPP_INCLUDED
#define HEXAGON_HPP_INCLUDED

#include <cstdint>

class Hexagon
{
public:

    enum Color
    {
        Color_None = 0,
        Red,
        Blue,
        Green,
        Yellow,
        Orange,
        Purple
    };

    enum Unit
    {
        Unit_None = 0,
        Soldier,
        Castle,
        Tree,
        House,
        Grave
    };

    enum SoldierType
    {
        Soldier_None = 0,
        Peasant,
        Spearman,
        Knight,
        Baron
    };

    Hexagon (Color, Unit);
    Hexagon (bool sea);
    Hexagon ();

private:
    bool  isSea;
    Color color;
    Unit  unit;

    /* If it's a soldier: */
    SoldierType soldierType;
    bool        canMove;

    /* If it's a house */
    int32_t money;

    friend class HexGrid;
};

#endif // HEXAGON_HPP_INCLUDED

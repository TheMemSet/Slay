#ifndef HEXGRID_HPP_INCLUDED
#define HEXGRID_HPP_INCLUDED

#include "Hexagon.hpp"
#include <cstdint>
#include <string>

#define MAX_GRID_WIDTH 40
#define MAX_GRID_HEIGHT 40
#define MAX_PLAYERS 6

class HexGrid
{
    Hexagon **grid;

    void KillUnitsAt       (int y, int x);
    bool IsLegalHexagon    (int y, int x);

    bool TopLeftBorder     (int &y, int &x); // Returns false if it's not legal,
    bool BottomLeftBorder  (int &y, int &x); // otherwise puts coordinates into y and x
    bool TopRightBorder    (int &y, int &x); //
    bool BottomRightBorder (int &y, int &x); //
    bool TopBorder         (int &y, int &x); //
    bool BottomBorder      (int &y, int &x); //

    void PositionError     (std::string);
    void GenericBFS        (std::string arg); // Utility function

    uint16_t       AreaSizeAt    (int y, int x);
    uint16_t       RevenueAt     (int y, int x);
    uint16_t       UpkeepAt      (int y, int x);
    int16_t        ProfitAt      (int y, int x);

    void           UpdateMoneyAt (int y, int x); // Calls KillUnitsAt if money ends up being negative

    bool           ConquerAt     (int y, int x, Hexagon::Color conqueror, Hexagon::Unit unit); // Return true if successful, false otherwise
    bool           GrowTreeAt    (int y, int x);                                               //
    bool           PutCastleAt   (int y, int x, Hexagon::Color user);                          //
    bool           PutHouseAt    (int y, int x); // Returns false if area is size 1, or if it already has a house, determines the exact position by itself

public:
    HexGrid  ();
    ~HexGrid ();

    Hexagon::Color ColorAt       (int y, int x);
    Hexagon::Unit  UnitAt        (int y, int x);
};

#endif // HEXGRID_HPP_INCLUDED

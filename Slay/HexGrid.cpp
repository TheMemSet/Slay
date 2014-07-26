#include "HexGrid.hpp"
#include <iostream>
#include <cstdlib>

HexGrid::HexGrid ()
{
    grid = new Hexagon* [MAX_GRID_HEIGHT];

    for (int i = 0;i < MAX_GRID_HEIGHT;i++)
    {
        grid [i] = new Hexagon [MAX_GRID_WIDTH];
    }
}

HexGrid::~HexGrid ()
{
    for (int i = 0;i < MAX_GRID_HEIGHT;i++)
    {
        delete [] grid [i];
    }

    delete [] grid;
}

void HexGrid::PositionError (std::string msg)
{
    std::cout << msg;
    exit (EXIT_FAILURE);
}

bool HexGrid::IsLegalHexagon (int y, int x)
{
    return !((y < 0) || (y >= MAX_GRID_HEIGHT) || (x < 0) || (x >= MAX_GRID_WIDTH));
}

Hexagon::Color HexGrid::ColorAt (int y, int x)
{
    if (!IsLegalHexagon (y, x))
    {
        PositionError ("ColorAt attempted to access an illegal field");
    }

    return grid [y] [x].color;
}

Hexagon::Unit HexGrid::UnitAt (int y, int x)
{
    if (!IsLegalHexagon (y, x))
    {
        PositionError ("UnitAt attempted to access an illegal field");
    }

    return grid [y] [x].unit;
}

bool HexGrid::PutCastleAt (int y, int x, Hexagon::Color user)
{
    if (!IsLegalHexagon (y, x))
    {
        PositionError ("PutCastleAt attempted to access an illegal field");
    }

    if ((ColorAt (y, x) == user) && (UnitAt (y, x) == Hexagon::Unit_None))
    {
        grid [y] [x].unit = Hexagon::Castle;
        return true;
    }
    else return false;
}

bool HexGrid::TopLeftBorder (int &y, int &x)
{
    if (!(x % 2))
    {
        if (IsLegalHexagon (y - 1, x - 1))
        {
            x--;
            y--;
            return true;
        }
        else return false;
    }
    else
    {
        if (IsLegalHexagon (y, x - 1))
        {
            x--;
            return true;
        }
        else return false;
    }
}

bool HexGrid::BottomLeftBorder (int &y, int &x)
{
    if (!(x % 2))
    {
        if (IsLegalHexagon (y, x - 1))
        {
            x--;
            return true;
        }
        else return false;
    }
    else
    {
        if (IsLegalHexagon (y + 1, x - 1))
        {
            y++;
            x--;
            return true;
        }
        else return false;
    }
}

bool HexGrid::TopRightBorder (int &y, int &x)
{
    if (!(x % 2))
    {
        if (IsLegalHexagon (y - 1, x + 1))
        {
            y--;
            x++;
            return true;
        }
        else return false;
    }
    else
    {
        if (IsLegalHexagon (y, x + 1))
        {
            x++;
            return true;
        }
        else return false;
    }
}

bool HexGrid::BottomRightBorder (int &y, int &x)
{
    if (!(x % 2))
    {
        if (IsLegalHexagon (y, x + 1))
        {
            x++;
            return true;
        }
        else return false;
    }
    else
    {
        if (IsLegalHexagon (y + 1, x + 1))
        {
            y++;
            x++;
            return true;
        }
        else return false;
    }
}

bool HexGrid::TopBorder (int &y, int &x)
{
    if (IsLegalHexagon (y - 1, x))
    {
        y--;
        return true;
    }
    else return false;
}

bool HexGrid::BottomBorder (int &y, int &x)
{
    if (IsLegalHexagon (y + 1, x))
    {
        y++;
        return true;
    }
    else return false;
}

bool HexGrid::GrowTreeAt (int y, int x)
{
    if (!IsLegalHexagon (y, x))
    {
        PositionError ("GrowTreeAt attempted to access an illegal field");
    }

    if (grid [y] [x].isSea)
    {
        PositionError ("Attempted to put a tree into the sea");
    }

    if (grid [y] [x].unit == Hexagon::Unit_None)
    {
        grid [y] [x].unit = Hexagon::Tree;
        return true;
    }
    else return false;
}



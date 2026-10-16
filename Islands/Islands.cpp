#include <vector>
#include <assert.h>
#include <iostream>

/*
 * To analyze satellite images, a geospatial company studies maps of remote ocean regions.
 * Each map is represented as a grid where land and water are identified.
 *
 * Your task is to determine how many separate islands are present on a given map.
 * The map is represented as a 2D grid of characters :
 *    - '1' represents land
 *    - '0' represents water
 *
 * An island is defined as a group of connected land cells.
 * Cells are considered connected if they are adjacent horizontally or vertically(not diagonally).
 * The grid is surrounded by water.
 * 
 * Implement the function count_islands which returns the total number of islands present in the map.
 */

const int dirs[4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} }; 


void Flood(std::vector<std::vector<char>>& grid, int x, int y, int size)
{
    if (x < 0 || x >= size || y < 0 || y >= size) return;  
    if (grid[y][x] != '1') return;                            

    grid[y][x] = '0'; 

    for (const auto& d : dirs)
        Flood(grid, x + d[0], y + d[1], size);
}

int count_islands(std::vector<std::vector<char>>& grid)
{
    int size =(int)grid.size();
    
    int count = 0;
    for (int y = 0; y < size; ++y)
        for (int x = 0; x < size; ++x)
            if (grid[y][x] == '1')
            {
                ++count;      
                Flood(grid,x, y, size); 
            }

    return count;
}

int main()
{
    {
        std::vector<std::vector<char>> grid = {
            {'1','1','0','0'},
            {'1','1','0','0'},
            {'0','0','1','0'},
            {'0','0','0','1'}
        };
        assert(count_islands(grid) == 3);
        std::cout << count_islands(grid);
    }
    

    return 0;
}
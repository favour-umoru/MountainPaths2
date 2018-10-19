#include<vector>
#include "functions.h"
#include<cmath>

using namespace std;

int colorPath(const vector<vector<int>>& heightMap, vector<vector<int>>& r, vector<vector<int>>& g, vector<vector<int>>& b, int color_r, int color_g,
	int color_b, int start_row)
{
	int elevChange1 = 99999;
	int elevChange2 = 99999;
	int elevChange3 = 99999;
	int totalElevChange = 0;
	
	// go through the elevation data
	for(int i = 0; i < heightMap.size(); i++)
	{
        for (int j = 0; j < heightMap.at(1).size(); j++)
		{
			r.at(start_row).at(j) = 252;
			g.at(start_row).at(j) = 25;
			b.at(start_row).at(j) = 63;
	
			// go through the heightMap and calculates the path for the row.
			// Check to see if the value of the column above the row after the start row is inbounds
			if((j - 1)>=0)
			{
				elevChange1 = abs((heightMap.at(start_row + i).at(j)) - (heightMap.at(start_row  + i + 1).at(j - 1)));
			}
			
			elevChange3 = abs((heightMap.at(start_row + i).at(j)) - (heightMap.at(start_row  + i + 1).at(j)));
			
			// Check to see if the value of the column below the row after the start row is inbounds
			if((j + 1) >= 0)
			{
				elevChange3 = abs((heightMap.at(start_row + i).at(j)) - (heightMap.at(start_row  + i + 1).at(j + 1)));
			}

			// Find the Minimum change in elevation by comparing the elevation changes 
			int minElevationChange = heightMap.at(start_row).at(j);
			
			if(elevChange1 < elevChange2 && elevChange1 < elevChange3)
			{
				minElevationChange = elevChange1;
				totalElevChange += elevChange1;
				r.at(start_row + i + 1).at(j - 1) = 252;
				g.at(start_row + i + 1).at(j - 1) = 25;
				b.at(start_row + i + 1).at(j - 1) = 63;
				
			}
			else if(elevChange2 < elevChange1 && elevChange2 < elevChange3)
			{
				minElevationChange = elevChange2;
				totalElevChange += elevChange2;
				r.at(start_row + i + 1).at(j) = 252;
				g.at(start_row + i + 1).at(j) = 25;
				b.at(start_row + i + 1).at(j) = 63;
				
			}
			else if(elevChange3 < elevChange1 && elevChange3 < elevChange2)
			{
				minElevationChange = elevChange3;
					
				totalElevChange += elevChange3;
				r.at(start_row + i + 1).at(j + 1) = 252;
				g.at(start_row + i + 1).at(j + 1) = 25;
				b.at(start_row + i + 1).at(j + 1) = 63;
				
			}
				
		  
		  
		}
	}
	
	return totalElevChange;
}

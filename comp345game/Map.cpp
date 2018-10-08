#include <iostream>
#include <ostream>
#include <algorithm>
#include <vector>
#include <string>
#include "Map.h"

using namespace std;

Map::Map() {

}

Map::Map(vector<Region> regions) {
	this->regions = regions;
}

void Map::addRegion(Region region) {
	regions.push_back(region);
}

Map::~Map() {
	while (regions.size() > 0) {
		//delete regions.back();		if the regions vector is a pointer
		regions.pop_back();
	}
}

bool Map::checkConnection() {
	vector<Region> regions = this->regions;

	for (int i = 0; i < regions.size(); i++) {
		Region currentRegion = regions[i];
		vector<Region> neighbours = currentRegion.getNearbyRegions();

		cout << "Region: " + currentRegion.getName() << endl;

		for (int i = 0; i < neighbours.size(); i++) {
			Region neighbour = neighbours[i];
			vector<Region> innerNeighbours = neighbour.getNearbyRegions();

			cout << "	neighbour: " + neighbour.getName() << endl;

			for (int i = 0; i < innerNeighbours.size(); i++) {
				Region innerNeighbour = innerNeighbours[i];

				cout << "		innerNeighbour: " + innerNeighbour.getName() << endl;

			}
			cout << "Entering find statement" << endl;
			if (find(innerNeighbours.begin(), innerNeighbours.end(), currentRegion) == innerNeighbours.end()) {
				cout << "Region: " + currentRegion.getName() + " is not properly connected. Please load a proper map." << endl;
				return false;
			}

		}

	}

	cout << "map is good" << endl;

	return true;
};

/*
Static verification for one directional maps
	*I'm leaving this here in case it becomes useful

vector<int> a1 = { 2, 3, 4, 5 };
vector<int> a2 = { 1, 3, 4, 5 };
vector<int> a3 = { 1, 2, 4, 5 };
vector<int> a4 = { 1, 2, 3, 5 };
vector<int> a5 = { 1, 2, 3, 4, 6 };
vector<int> a6 = { 1, 2, 3, 4, 7 };
vector<int> a7 = { 1, 2, 3, 4 };
vector<int> a7 = { 1, 2, 3, 4, 5 };

bool Map::checkConnection() {
	vector<Region> regions = this->regions;

	for (int i = 0; i < regions.size(); i++) {
		Region currentRegion = regions[i];
		int id = currentRegion.getId();


		switch (id) {
		case 1:
			if (currentRegion.getNearbyRegionIds() != a1)
				return false;
			break;

		case 2:
			if (currentRegion.getNearbyRegionIds() != a2)
				return false;
			break;

		case 3:
			if (currentRegion.getNearbyRegionIds() != a3)
				return false;
			break;

		case 4:
			if (currentRegion.getNearbyRegionIds() != a4)
				return false;

			break;

		case 5:
			if (currentRegion.getNearbyRegionIds() != a5)
				return false;
			break;

		case 6:
			if (currentRegion.getNearbyRegionIds() != a6)
				return false;
			break;

		case 7:
			if (currentRegion.getNearbyRegionIds() != a7)
				return false;
			break;
		}

	}

	cout << "we made it " << endl;

	return true;
}
*/
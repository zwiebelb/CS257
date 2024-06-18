#ifndef COORDINATES_H

#include <utility>  // For pair
#include <vector>

typedef std::pair<double, double>  Coordinate;

double Haversine(Coordinate a, Coordinate b);
void SortByDistanceTo(Coordinate target, std::vector<Coordinate> &coords);

#endif
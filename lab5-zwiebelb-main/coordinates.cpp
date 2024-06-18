#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <cmath>

#include "coordinates.h"

using namespace std;

double Haversine(Coordinate a, Coordinate b) {
  double lat1 = a.first;
  double lon1 = a.second;
  double lat2 = b.first;
  double lon2 = b.second;

  const double R = 6371e3;
  const double phi1 = lat1 * M_PI / 180;
  const double phi2 = lat2 * M_PI / 180;
  const double deltaphi = (lat2 - lat1) * M_PI / 180;
  const double deltalamda = (lon2 - lon1) * M_PI / 180;

  // a = sin²(Δφ/2) + cos φ1 ⋅ cos φ2 ⋅ sin²(Δλ/2)
  const double aH = pow(sin(deltaphi / 2.0), 2.0) +
                    cos(phi1) * cos(phi2) * pow(sin(deltalamda / 2), 2);
  // c = 2 ⋅ atan2( √a, √(1−a) )
  const double c = 2 * atan2(sqrt(aH), sqrt(1.0 - aH));
  const double d = (R * c) / 1000;

  return d;
}

// target is 42.1858587, -122.6970897
void SortByDistanceTo(Coordinate target, vector<Coordinate> &coords) {
  for (unsigned int i = 0; i < coords.size() - 1; ++i) {
    double lh = 100000000; 
    int min = i;
    for (unsigned int j = i + 1; j < coords.size(); ++j) {
      double haversine = Haversine(target, coords[j]);
      if (haversine < lh) {
        lh = haversine;
        min = j;
      }
    }
    swap(coords[i], coords[min]);
  }
}
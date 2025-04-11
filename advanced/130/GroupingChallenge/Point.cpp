#include "Point.h"
using namespace NGroupingChallenge;

void CPoint::vAddCoordinate(double dCoordinate) {
	coordinates.push_back(dCoordinate);
}
double CPoint::dCalculateDistance(const CPoint& cOther) const {
	if (coordinates.empty() || coordinates.size() != cOther.coordinates.size()) return WrongDistance;
	double squaredDistance = 0.0;
	for (size_t i = 0; i < coordinates.size(); i++) squaredDistance += (coordinates[i] - cOther.coordinates[i]) * (coordinates[i] - cOther.coordinates[i]);
	return sqrt(squaredDistance);
}
void CPoint::viewPoint() {
	for(int i=0; i<coordinates.size(); i++) cout << " " << coordinates[i];
	cout << endl;
}
string CPoint::textPoint() {
	string output = "";
	for(double item : coordinates) output += "\t" + to_string(item);
	output += "\n";
	return output;
}
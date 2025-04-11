/*
CGroupingEvaluator: evaluate the fitness with the given information (points, number of groups, solution)
*/
#include "GroupingEvaluator.h"
using namespace NGroupingChallenge;

CGroupingEvaluator::CGroupingEvaluator(int iNumberOfGroups, const vector<CPoint>& vPoints)
	: nGroups(iNumberOfGroups), points(vPoints) {}
double CGroupingEvaluator::dEvaluate(const int* piSolution) const {
	bool isError = !piSolution || points.empty();

	double distance;
	double sumDistance = 0;

	for (size_t i = 0; i + 1 < points.size() && !isError; i++) {
		if (piSolution[i] >= iGetLowerBound() && piSolution[i] <= iGetUpperBound()) {
			for (size_t j = i + 1; j < points.size(); j++) {
				if (piSolution[i] == piSolution[j]) {
					distance = points[i].dCalculateDistance(points[j]);

					if (distance >= 0) sumDistance += 2.0 * points[i].dCalculateDistance(points[j]);
					else isError = true;
				}
			}
		}
		else isError = true;
	}

	if (isError) return WrongDouble;
	return sumDistance;
}
double CGroupingEvaluator::dEvaluate(const vector<int>* pvSolution) const {
	if (!pvSolution) return WrongDouble;
	return dEvaluate(*pvSolution);
}
double CGroupingEvaluator::dEvaluate(const vector<int>& vSolution) const {
	if (vSolution.size() != points.size()) return WrongDouble;
	return dEvaluate(vSolution.data());
}
void CGroupingEvaluator::viewPoints() {
	cout << "\npoint details\n";
	for(CPoint item : points) item.viewPoint();
}
string CGroupingEvaluator::textPoints() {
	string output = "points\n";
	for(CPoint item : points) output += item.textPoint();
	return output;
}

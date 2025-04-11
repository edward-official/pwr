/*
CGroupingEvaluator: evaluate the fitness with the given information (points, number of groups, solution)
*/
#ifndef GROUPING_EVALUATOR_H
#define GROUPING_EVALUATOR_H

#include <vector>
#include "Point.h"
using namespace std;

namespace NGroupingChallenge {
	class CGroupingEvaluator {
	public:
		CGroupingEvaluator(int iNumberOfGroups, const vector<CPoint>& vPoints);
		double dEvaluate(const int* piSolution) const;
		double dEvaluate(const vector<int>* pvSolution) const;
		double dEvaluate(const vector<int>& vSolution) const;
		const vector<CPoint>& vGetPoints() const { return points; }
		int iGetNumberOfPoints() const { return (int)points.size(); };
		int getGroupSize() const {return nGroups;}
		int iGetLowerBound() const { return 1; };
		int iGetUpperBound() const { return nGroups; }
		void viewPoints();
		string textPoints();

	private:
		const double WrongDouble = -1;
		int nGroups;
		vector<CPoint> points;
	};
}

#endif
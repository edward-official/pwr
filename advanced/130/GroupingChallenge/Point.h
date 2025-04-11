#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

namespace NGroupingChallenge
{
	class CPoint
	{
	public:
		void vAddCoordinate(double dCoordinate);
		double dCalculateDistance(const CPoint& cOther) const;
		void viewPoint();
		string textPoint();

	private:
		const double WrongDistance = -1;
		vector<double> coordinates;
	};
}

#endif
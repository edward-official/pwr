/*
CDimension: generates random mean/deviation within the given scope
CUnivariateGaussianDistribution: generates random coordinate according to the given mean and deviation
CMultivariateGaussianDistribution: generates random coordinates of a point with the given cluster(n-dimensional)
CGaussianGroupingEvaluatorFactory: generates random points with the given clusters and then evaluator with those points
*/
#ifndef GAUSSIAN_GROUPING_EVALUATOR_FACTORY_H
#define GAUSSIAN_GROUPING_EVALUATOR_FACTORY_H

#include <random>
#include <vector>
#include "GroupingEvaluator.h"
#include "Point.h"
using namespace std;

namespace NGroupingChallenge {
	class CDimension {
	public:
		CDimension(double dMeanMin, double dMeanMax, double dStandardDeviationMin, double dStandardDeviationMax, mt19937& cRandomEngine);
		double dGenerateRandomMean();
		double dGenerateRandomStandardDeviation();

	private:
		const double DefaultDeviationValue = 1.0;
		uniform_real_distribution<double> meanDistribution;
		uniform_real_distribution<double> deviationDistribution;
		mt19937& randomEngine;
	};
	class CUnivariateGaussianDistribution {
	public:
		CUnivariateGaussianDistribution(double dMean, double dStandardDeviation, mt19937& cRandomEngine);
		double dGenerateRandomNumber();
	private:
		normal_distribution<double> normalRandomDouble;
		mt19937& randomEngine;
	};
	class CMultivariateGaussianDistribution {
	public:
		CMultivariateGaussianDistribution(vector<CDimension>& vDimensions, mt19937& cRandomEngine);
		CPoint cGenerateRandomPoint();
	private:
		vector<CUnivariateGaussianDistribution> univariateDistributions;
	};
	class CGaussianGroupingEvaluatorFactory {
	public:
		CGaussianGroupingEvaluatorFactory(int iNumberOfGroups, int iNumberOfPoints, int iNumberOfMultivariateGaussianDistributions);
		CGaussianGroupingEvaluatorFactory& cAddDimension(double dMeanMin, double dMeanMax, double dStandardDeviationMin, double dStandardDeviationMax);
		CGroupingEvaluator* pcCreateEvaluator();
		CGroupingEvaluator* pcCreateEvaluator(unsigned int iSeed);


	private:
		const int NGroupsMinimum = 1;
		const int NPointsMinimum = 1;
		const int NMultivariateMinimum = 1;

		vector<CMultivariateGaussianDistribution>* createMultivariate();
		vector<CPoint>* createPoints(vector<CMultivariateGaussianDistribution>& vMultivariateGaussianDistributions);

		int nGroups;
		int nPoints;
		int nMultivariate;

		vector<CDimension> dimensions;
		mt19937 randomEngine;
	};
}

#endif
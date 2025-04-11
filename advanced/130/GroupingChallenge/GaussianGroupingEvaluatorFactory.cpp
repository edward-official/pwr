/*
CDimension: generates random mean/deviation within the given scope
CUnivariateGaussianDistribution: generates random coordinate according to the given mean and deviation
CMultivariateGaussianDistribution: generates random coordinates of a point with the given cluster(n-dimensional)
CGaussianGroupingEvaluatorFactory: generates random points with the given clusters and then evaluator with those points
*/
#include "GaussianGroupingEvaluatorFactory.h"
using namespace NGroupingChallenge;


CDimension::CDimension(double dMeanMin, double dMeanMax, double dStandardDeviationMin, double dStandardDeviationMax, mt19937 &cRandomEngine)
	: meanDistribution(min(dMeanMin, dMeanMax), max(dMeanMin, dMeanMax)), 
	deviationDistribution(min(dStandardDeviationMin, dStandardDeviationMax), max(dStandardDeviationMin, dStandardDeviationMax)),
	randomEngine(cRandomEngine)
{

}
double CDimension::dGenerateRandomMean() {return meanDistribution(randomEngine);}
double CDimension::dGenerateRandomStandardDeviation() {
	double d_standard_deviation = deviationDistribution(randomEngine);
	if (d_standard_deviation <= 0) d_standard_deviation = DefaultDeviationValue;
	return d_standard_deviation;
}


CUnivariateGaussianDistribution::CUnivariateGaussianDistribution(double dMean, double dStandardDeviation, mt19937& cRandomEngine)
	: normalRandomDouble(dMean, dStandardDeviation), randomEngine(cRandomEngine)
{

}
double CUnivariateGaussianDistribution::dGenerateRandomNumber() {return normalRandomDouble(randomEngine);}


CMultivariateGaussianDistribution::CMultivariateGaussianDistribution(vector<CDimension>& vDimensions, mt19937& cRandomEngine) {
	// [document] in 3D spaces for example one multivariate should own three different univariate
	// [document] when making random (x, y, z) point every different coordinates follow different mean and deviation.
	univariateDistributions.reserve(vDimensions.size());
	for (size_t i = 0; i < vDimensions.size(); i++) univariateDistributions.push_back(CUnivariateGaussianDistribution(vDimensions[i].dGenerateRandomMean(), vDimensions[i].dGenerateRandomStandardDeviation(), cRandomEngine));
}
CPoint CMultivariateGaussianDistribution::cGenerateRandomPoint() {
	CPoint c_point;
	for (size_t i = 0; i < univariateDistributions.size(); i++) c_point.vAddCoordinate(univariateDistributions[i].dGenerateRandomNumber());
	return c_point;
}


CGaussianGroupingEvaluatorFactory::CGaussianGroupingEvaluatorFactory(int iNumberOfGroups, int iNumberOfPoints, int iNumberOfMultivariateGaussianDistributions)
	: nGroups(max(iNumberOfGroups, NGroupsMinimum)), 
	nPoints(max(iNumberOfPoints, NGroupsMinimum)), 
	nMultivariate(max(iNumberOfMultivariateGaussianDistributions, NMultivariateMinimum))
{

}
CGaussianGroupingEvaluatorFactory& CGaussianGroupingEvaluatorFactory::cAddDimension(double dMeanMin, double dMeanMax, double dStandardDeviationMin, double dStandardDeviationMax) {
	dimensions.push_back(CDimension(dMeanMin, dMeanMax, dStandardDeviationMin, dStandardDeviationMax, randomEngine));
	return *this;
}
CGroupingEvaluator* CGaussianGroupingEvaluatorFactory::pcCreateEvaluator() {
	random_device c_seed_generator;
	return pcCreateEvaluator(c_seed_generator());
}
CGroupingEvaluator* CGaussianGroupingEvaluatorFactory::pcCreateEvaluator(unsigned int iSeed) {
	randomEngine.seed(iSeed);
	vector<CMultivariateGaussianDistribution>* multivariateDistributions = createMultivariate();
	vector<CPoint>* points = createPoints(*multivariateDistributions);
	CGroupingEvaluator* evaluator = new CGroupingEvaluator(nGroups, *points);
	delete multivariateDistributions;
	delete points;
	return evaluator;
}
vector<CMultivariateGaussianDistribution>* CGaussianGroupingEvaluatorFactory::createMultivariate() {
	vector<CMultivariateGaussianDistribution>* multivariateDistributions = new vector<CMultivariateGaussianDistribution>();
	multivariateDistributions->reserve(nMultivariate);
	for (int i = 0; i < nMultivariate; i++) multivariateDistributions->push_back(CMultivariateGaussianDistribution(dimensions, randomEngine));
	return multivariateDistributions;
}
vector<CPoint>* CGaussianGroupingEvaluatorFactory::createPoints(vector<CMultivariateGaussianDistribution>& vMultivariateGaussianDistributions) {
	vector<CPoint>* points = new vector<CPoint>();
	points->reserve(nPoints);

	// select random cluster and then generate points
	uniform_int_distribution<size_t> randomMultivariateIndex(0, vMultivariateGaussianDistributions.size() - 1);
	cout << "cluster:";
	for (int i = 0; i < nPoints; i++) {
		size_t multivariateIndex = randomMultivariateIndex(randomEngine);
		cout << " " << multivariateIndex + 1;
		points->push_back(vMultivariateGaussianDistributions[multivariateIndex].cGenerateRandomPoint());
	}
	cout << endl;
	return points;
}
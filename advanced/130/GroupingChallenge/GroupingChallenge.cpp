/*
g++ -std=c++11 GaussianGroupingEvaluatorFactory.cpp GroupingEvaluator.cpp Optimizer.cpp GroupingChallenge.cpp Point.cpp -o GroupingChallenge && ./GroupingChallenge
CGeneticAlgorithm: takes care of one specific case + designate seed value
*/
#include <fstream>
#include "GaussianGroupingEvaluatorFactory.h"
#include "GroupingEvaluator.h"
#include "Optimizer.h"
using namespace NGroupingChallenge;


class CGeneticAlgorithm {
private:
	int nGroups, nPoints, nMultivalueDistribution, nDimension, nPopulation;
	double pMutate, pCrossover;
	CGroupingEvaluator* evaluator;
	COptimizer *optimizer;
public:
	CGeneticAlgorithm(double _pMutate, double _pCrossover, int _nGroups, int _nPoints, int _nMultivalueDistribution, int _nDimension, int _nPopulation) 
	: pMutate(_pMutate), pCrossover(_pCrossover), nGroups(_nGroups), nPoints(_nPoints), nMultivalueDistribution(_nMultivalueDistribution), nDimension(_nDimension), nPopulation(_nPopulation)
	{
		CGaussianGroupingEvaluatorFactory evaluatorFactory(nGroups, nPoints, nMultivalueDistribution);
		for(int i=0; i<nDimension; i++) evaluatorFactory.cAddDimension(-100, 100, 1.0, 1.0);
		// int seed = time(0);
		int seed = 0;
		evaluator = evaluatorFactory.pcCreateEvaluator(seed); // create points
		optimizer = new COptimizer(*evaluator, nPopulation, pMutate, pCrossover);
	}
	~CGeneticAlgorithm() {
		delete evaluator;
		delete optimizer;
	}

	void initialize() {optimizer->vInitialize();}
	void viewPoints() {optimizer->viewPoints();}
	void runGeneration(int terminateCriterion) {
		int gap = terminateCriterion/10;
		cout << endl;
		for(int i=0; i<terminateCriterion; i++) {
			if(i % gap==0) cout << "generation [" << i+1 << "] to [" << i+gap << "]\n";
			optimizer->vRunGeneration();
		}
	}
	void viewOutput() {optimizer->viewCuurentBest();}
	void downloadOutput() {
		string outputFileName = "result.txt";
		ofstream outFile(outputFileName);
		if (!outFile) {
			cerr << "failed to open file!" << endl;
			return;
		}
		outFile << optimizer->textPoints() << endl;
		outFile << optimizer->textCurrentBest() << endl;
		outFile.close();
		
		cout << "\nfile writer closed 💻\n";
		cout << "output saved on the text file " << "(" << outputFileName << ")" << endl << endl;
	}
};


int main() {
	int nGroups = 5, nPoints = 10, nMultivalueDistribution = 5, nDimension = 3;
	int nPopulation = 1000, terminateCriterion = 100;
	double pMutate = 0.1, pCrossover = 0.6;

	CGeneticAlgorithm algorithm(pMutate, pCrossover, nGroups, nPoints, nMultivalueDistribution, nDimension, nPopulation);
	algorithm.initialize();
	// algorithm.viewPoints();
	algorithm.runGeneration(terminateCriterion);
	algorithm.viewOutput();
	algorithm.downloadOutput();

	return 0;
}
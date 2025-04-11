/*
CIndividual: includes genotype and calculate fitness
COptimizer: run generations to find the best solution possible
*/
#include "Optimizer.h"
#include "Point.h"
#include "GroupingEvaluator.h"
using namespace NGroupingChallenge;


COptimizer::COptimizer(CGroupingEvaluator& _evaluator, int _sizeGeneration, double _pMutate, double _pCrossover)
	: evaluator(_evaluator), sizeGeneration(_sizeGeneration), pMutate(_pMutate), pCrossover(_pCrossover) {
	random_device c_seed_generator;
	randomEngine.seed(c_seed_generator());
}
void COptimizer::vInitialize() {
	cout << "\ninitialize: generation [0]\n";
	
	numeric_limits<double> doubleLimits;
	currentBestFitness = doubleLimits.max();

	currentBest.clear();
	currentBest.resize(evaluator.iGetNumberOfPoints());

	// 🔥🔥🔥🔥 setting up the 0st generation
	generation.clear();
	for(int i=0; i<sizeGeneration; i++) {
		// [candidate/solution/genotype]
		// size==n_point, range_of_element==(n_group)
		vector<int> v_candidate(evaluator.iGetNumberOfPoints());
		uniform_int_distribution<int> c_candidate_distribution(evaluator.iGetLowerBound(), evaluator.iGetUpperBound());
		for (size_t i = 0; i < v_candidate.size(); i++) v_candidate[i] = c_candidate_distribution(randomEngine);

		CIndividual t(v_candidate);
		generation.push_back(t);
	}

	for(int i=0; i<sizeGeneration; i++) {
		if(generation[i].getFitness(evaluator) < currentBestFitness) {
			currentBest = generation[i].getGenotype();
			currentBestFitness = generation[i].getFitness(evaluator);
			cout << currentBestFitness << " 🎉" << endl;
		}
	}
}
void COptimizer::vRunIteration() {
	// 🔎 Make random individual and test it
	vector<int> v_candidate(evaluator.iGetNumberOfPoints());
	uniform_int_distribution<int> c_candidate_distribution(evaluator.iGetLowerBound(), evaluator.iGetUpperBound());
	for (size_t i = 0; i < v_candidate.size(); i++) v_candidate[i] = c_candidate_distribution(randomEngine);

	double d_candidate_fitness = evaluator.dEvaluate(v_candidate);
	if (d_candidate_fitness < currentBestFitness) {
		currentBest = v_candidate;
		currentBestFitness = d_candidate_fitness;
		cout << currentBestFitness << endl;
	}
}
void COptimizer::vRunGeneration() {
	// cout << "💻 running next generation\n";
	vector<CIndividual> nextGeneration;

	// to track partial best
	// vector<int> partialBestGenotype;
	// partialBestGenotype.clear();
	// numeric_limits<double> doubleLimits;
	// double partialBestFitness = doubleLimits.max();

	nextGeneration.clear();
	nextGeneration.push_back(CIndividual(currentBest)); // one place is going to the current best genotype

	// mutation
	for(int i=0; i<sizeGeneration; i++) generation[i].mutate(pMutate, evaluator.getGroupSize(), evaluator);
	
	// crossover
	while(true) {
		// 🔥 artificial intervention
		double pArtificial = 0.1;
  	uniform_real_distribution<double> random_probability(0.0, 1.0);
		if(random_probability(randomEngine) < 0.1) {
			nextGeneration.push_back(CIndividual(currentBest));
			if(nextGeneration.size()==sizeGeneration) break;
		}

		vector<CIndividual> childs;
		int parentIndex1=-1, parentIndex2=-1; // pick two parents for one child > repeated two times
		childs.clear();

		// setting up random numbers for individual selection
		uniform_int_distribution<int> random_index(0, sizeGeneration-1);
		
		// pick parent 1
		int targetIndex1 = random_index(randomEngine), targetIndex2 = random_index(randomEngine);
		if(generation[targetIndex1].getFitness(evaluator) < generation[targetIndex2].getFitness(evaluator)) parentIndex1 = targetIndex1;
		else parentIndex1 = targetIndex2;

		// pick parent 2
		targetIndex1 = random_index(randomEngine), targetIndex2 = random_index(randomEngine);
		if(generation[targetIndex1].getFitness(evaluator) < generation[targetIndex2].getFitness(evaluator)) parentIndex2 = targetIndex1;
		else parentIndex2 = targetIndex2;

		// cout << "parent " << parentIndex1 << " and " << parentIndex2 << " selected\n";

		// crossover
		childs = generation[parentIndex1].crossover(pCrossover, generation[parentIndex2], evaluator);

		// push back to next generation
		nextGeneration.push_back(childs[0]);
		if(nextGeneration.size()==sizeGeneration) break;
		nextGeneration.push_back(childs[1]);
		if(nextGeneration.size()==sizeGeneration) break;
	}
	
	// update the best solution
	generation = nextGeneration;
	for(int i=0; i<sizeGeneration; i++) {
		if(generation[i].getFitness(evaluator) < currentBestFitness) {
			currentBest = generation[i].getGenotype();
			currentBestFitness = generation[i].getFitness(evaluator);
			cout << "found better: " << currentBestFitness << " 🎉" << endl;
		}
		// if(generation[i].getFitness(evaluator) < partialBestFitness) {
		// 	partialBestGenotype = generation[i].getGenotype();
		// 	partialBestFitness = generation[i].getFitness(evaluator);
		// }
	}
	// cout << "partial best: " << partialBestFitness << endl;
}
void COptimizer::viewCuurentBest() {
	cout << "\ncurrent best fitness: " << currentBestFitness << endl;
	cout << "details:";
	for(double item: currentBest) cout << " " << item;
	cout << endl;
}
void COptimizer::viewPoints() {evaluator.viewPoints();}
string COptimizer::textCurrentBest() {
	string output = "best fitness: " + to_string(currentBestFitness) + "\n";
	output += "details:";
	for(int item : currentBest) output += " " + to_string(item);
	output += "\n";
	return output;
}
string COptimizer::textPoints() {return evaluator.textPoints();}


CIndividual::CIndividual(vector<int> &_genotype) : genotype(_genotype) {}
CIndividual::CIndividual(const CIndividual &other) 
: genotype(other.genotype), fitness(other.fitness), randomEngine(other.randomEngine) {}
double CIndividual::getFitness(CGroupingEvaluator &evaluator) {
  if(fitness<0.0) fitness = evaluator.dEvaluate(genotype);
  return fitness;
}
vector<int> CIndividual::getGenotype() {return genotype;}
void CIndividual::fixGenotype(int index, int newValue) {genotype[index] = newValue;}
void CIndividual::mutate(double probability, int nGroup, CGroupingEvaluator &evaluator) {
  uniform_real_distribution<double> random_probability(0.0, 1.0);
	uniform_int_distribution<int> random_gene(evaluator.iGetLowerBound(), evaluator.iGetUpperBound());
  int sizegenotype = genotype.size();
  for(int i=0; i<sizegenotype; i++) {
    double t = random_probability(randomEngine);
    if(t<probability) genotype[i] = random_gene(randomEngine);
  }
}
void CIndividual::viewDetails() {
  for(int i=0; i<genotype.size(); i++) cout << " " << genotype[i];
  cout << endl;
}
vector<CIndividual> CIndividual::crossover(double probability, CIndividual& other, CGroupingEvaluator &evaluator) {
  uniform_real_distribution<double> random_probability(0.0, 1.0);
  vector<CIndividual> childs;
  if(random_probability(randomEngine) > probability) {
    childs.push_back(*this);
    childs.push_back(other);
    return childs;
  }
  int sizegenotype = genotype.size();
	uniform_int_distribution<int> random_index(1, sizegenotype-1);
  CIndividual child1(this->genotype);
  CIndividual child2(other.genotype);

  int index = random_index(randomEngine);
  for(int i=index; i<sizegenotype; i++) {
    int t = child1.genotype[i];
    child1.fixGenotype(i, other.genotype[i]);
    child2.fixGenotype(i, t);
  }

  childs.push_back(child1);
  childs.push_back(child2);
  return childs;
}


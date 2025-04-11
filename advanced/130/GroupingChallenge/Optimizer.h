/*
CIndividual: includes genotype and calculate fitness
COptimizer: run generations to find the best solution possible
*/
#ifndef OPTIMIZER_H
#define OPTIMIZER_H

#include <iostream>
#include <numeric>
#include <random>
#include <vector>
#include "GroupingEvaluator.h"
using namespace std;

namespace NGroupingChallenge {
	class CIndividual {
	private:
		vector<int> genotype;
		double fitness = -1.0;
		mt19937 randomEngine;

	public:
    CIndividual(vector<int> &genotype);
		CIndividual(const CIndividual &other);
		vector<int> getGenotype();
		double getFitness(CGroupingEvaluator &evaluator);
		void fixGenotype(int index, int newValue);
		void mutate(double probability, int nGroup, CGroupingEvaluator &evaluator);
		vector<CIndividual> crossover(double probability, CIndividual& other, CGroupingEvaluator &evaluator);
		void viewDetails();
	};

	class COptimizer {
	public:
		COptimizer(CGroupingEvaluator& cEvaluator, int sizeGeneration, double pMutate, double pCrossover);
		void vInitialize();
		void vRunGeneration();
		void vRunIteration();
		void viewCuurentBest();
		vector<int>* pvGetCurrentBest() { return &currentBest; }
		double getCurrentBestFitness() {return currentBestFitness;}
		void viewPoints();
		string textPoints();
		string textCurrentBest();

	private:
		// 🔥🔥🔥🔥
		int sizeGeneration;
		vector<CIndividual> generation;
		double pMutate, pCrossover;

		CGroupingEvaluator& evaluator;
		double currentBestFitness;
		vector<int> currentBest;
		mt19937 randomEngine;
	};
}

#endif
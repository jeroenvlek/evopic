/*
 * PairGenerator.cpp
 *
 *  Created on: Aug 5, 2012
 *      Author: jvlek
 */

#include "PairGenerator.h"

#include <ctime>

PairGenerator::PairGenerator(unsigned int maxSingles)
	: m_maxSingles(maxSingles)
{
	m_generator.seed(static_cast<unsigned int>(std::time(0)));

	// for each number of singles left, there is a random generator that generates
	// an index within the bounds of the singles left set
	for(unsigned int i = 2; i < m_maxSingles; ++i) {
		boost::uniform_int<> dist(0, i);
		RandomIndexGenerator* randomIndexGenerator = new RandomIndexGenerator(m_generator, dist);
		m_randomIndexGenerators.push_back(randomIndexGenerator);
	}
}

PairGenerator::~PairGenerator()
{
	std::vector<RandomIndexGenerator*>::iterator it;
	for(it = m_randomIndexGenerators.begin(); it != m_randomIndexGenerators.end(); ++it) {
		delete *it;
	}
}

Couples PairGenerator::createRandomPairs() {

	std::vector<unsigned int> singles;
	for(unsigned int i = 0; i < m_maxSingles; ++i) {
		singles.push_back(i);
	}

	Couples couples;
	RandomIndexGenerator* randomIndexGenerator;
	while(singles.size() > 2) {
		Couple couple;

		boost::mutex::scoped_lock(m_lock);

		// generate first pick and delete it from possible singles
		randomIndexGenerator = m_randomIndexGenerators[singles.size() - 3];
		unsigned int pick = (*randomIndexGenerator)();
		couple.first = singles[pick];
		singles.erase(singles.begin() + pick);

		// generate second pick and delete it from possible singles
		randomIndexGenerator = m_randomIndexGenerators[singles.size() - 3];
		pick = (*randomIndexGenerator)();
		couple.second = singles[pick];
		singles.erase(singles.begin() + pick);

		couples.push_back(couple);
	}

	// last two singles left are automatically a couple, given that
	// the initial count was even
	if(singles.size() == 2) {
		Couple lastCouple(singles[0], singles[1]);
		couples.push_back(lastCouple);
	}

	return couples;
}



/*
 * PairGenerator.h
 *
 *  Created on: Aug 5, 2012
 *      Author: jvlek
 */

#ifndef PAIRGENERATOR_H_
#define PAIRGENERATOR_H_

#include <utility>
#include <vector>

#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int.hpp>
#include <boost/random/variate_generator.hpp>
#include <boost/thread/mutex.hpp>

typedef std::pair<unsigned int, unsigned int> Couple;
typedef std::vector<Couple > Couples;
typedef boost::variate_generator<boost::mt19937&, boost::uniform_int<> > RandomIndexGenerator;

class PairGenerator
{
public:
	PairGenerator(unsigned int maxSingles);
	virtual ~PairGenerator();

	Couples createRandomPairs();

private:
	unsigned int m_maxSingles;
	boost::mt19937 m_generator;
	std::vector<RandomIndexGenerator*> m_randomIndexGenerators;
	boost::mutex m_lock;
};

#endif /* PAIRGENERATOR_H_ */



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
#include <boost/random/uniform_01.hpp>
#include <boost/random/variate_generator.hpp>
#include <boost/thread/mutex.hpp>

typedef boost::variate_generator<boost::mt19937&, boost::uniform_01<> > RandomGenerator;

class PairGenerator
{
public:
	PairGenerator();
	virtual ~PairGenerator();

	template <typename T>
	std::pair<T, T> removeRandomPair(std::vector<T>& singles);

private:
	boost::mt19937 m_rawGenerator;
	RandomGenerator* m_generator;

	template<typename T>
	T removeRandomSingle(std::vector<T>& singles);
};

template<typename T>
std::pair<T, T> PairGenerator::removeRandomPair(std::vector<T>& singles)
{
	T first = removeRandomSingle(singles);
	T second = removeRandomSingle(singles);

	return std::pair<T, T>(first, second);
}

template<typename T>
T PairGenerator::removeRandomSingle(std::vector<T>& singles)
{
	unsigned int index = (unsigned int) singles.size() * (*m_generator)();
	typename std::vector<T>::iterator iter = singles.begin() + index;
	T single = *(iter);
	singles.erase(iter);

	return single;
}

#endif /* PAIRGENERATOR_H_ */



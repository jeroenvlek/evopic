/*
 * PairGenerator.cpp
 *
 *  Created on: Aug 5, 2012
 *      Author: jvlek
 */

#include "PairGenerator.h"

#include <ctime>

PairGenerator::PairGenerator()
{
	m_rawGenerator.seed(static_cast<unsigned int>(std::time(0)));

	boost::uniform_01<> dist;
	m_generator = new RandomGenerator(m_rawGenerator, dist);
}

PairGenerator::~PairGenerator()
{
	delete m_generator;
}

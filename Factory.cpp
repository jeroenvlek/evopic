/**
 * Factory.cpp
 *
 *  Created on: Aug 2, 2011
 *      Author: Jeroen Vlek
 *	     Email: jeroenvlek@gmail.com
 *     Website: www.perceptivebits.com
 *     License: Free Beer (Feel free to use it in every 
 *              way possible and if you like it, make 
 *				sure to give me credit and buy me a drink 
 *              if we ever meet ;) )
 */

#include "Factory.h"
#include "QtFactory.h"

#include <ctime>
#include <iostream>

Factory::Factory()
		: m_gen(boost::rand48(std::time(0))),
		  m_randPrimary(
				  new boost::variate_generator<boost::rand48&, boost::uniform_int<unsigned char> >(
						  m_gen,
						  boost::uniform_int<unsigned char>(0, 255)
				  )
		  ),
		  m_randX(
				  new boost::variate_generator<boost::rand48&, boost::uniform_int<unsigned int> >(
						  m_gen,
						  boost::uniform_int<unsigned int>(0, 0))
				  ),
		  m_randY(
				  new boost::variate_generator<boost::rand48&, boost::uniform_int<unsigned int> >(
						  m_gen,
						  boost::uniform_int<unsigned int>(0, 0))
				  ),
		  m_randGeneSize(
				  new boost::variate_generator<boost::rand48&, boost::uniform_int<unsigned int> >(
						  m_gen,
						  boost::uniform_int<unsigned int>(
								  Config::GetMinGeneSize(),
								  Config::GetMaxGeneSize()
						  )
				  )
		  ),
		  m_randGenomeIndex(
				  new boost::variate_generator<boost::rand48&, boost::uniform_int<unsigned int> >(
						  m_gen,
						  boost::uniform_int<unsigned int>(
								  0,
								  Config::GetGenomeSize() - 1
						  )
				  )
		  ) {
}

Factory::~Factory() {
	delete m_randPrimary;
	delete m_randX;
	delete m_randY;
	delete m_randGeneSize;
	delete m_randGenomeIndex;
}

Factory& Factory::Instance() {
#ifdef QT_YES
		static QtFactory factory;
		return factory;
#endif
}

void Factory::update() {
	// changing random number generators

	if(Config::GetWidth() > 0) {
		delete m_randX;
		m_randX = new boost::variate_generator<boost::rand48&, boost::uniform_int<unsigned int> >(
				m_gen, boost::uniform_int<unsigned int>(0, Config::GetWidth() - 1));
	}

	if(Config::GetHeight() > 0) {
		delete m_randY;
		m_randY = new boost::variate_generator<boost::rand48&, boost::uniform_int<unsigned int> >(
				m_gen, boost::uniform_int<unsigned int>(0, Config::GetHeight() - 1));
	}

	delete m_randGeneSize;
	m_randGeneSize = new boost::variate_generator<boost::rand48&, boost::uniform_int<unsigned int> >(
							  m_gen,
							  boost::uniform_int<unsigned int>(
									  Config::GetMinGeneSize(),
									  Config::GetMaxGeneSize()
							  )
					  );
	delete m_randGenomeIndex;
	m_randGenomeIndex = new boost::variate_generator<boost::rand48&, boost::uniform_int<unsigned int> >(
							  m_gen,
							  boost::uniform_int<unsigned int>(
									  0,
									  Config::GetGenomeSize() - 1
							  )
					  );

	std::cout << "[ Factory::update() ] Updated factory" << std::endl;
}

unsigned int Factory::randX() {
	return (*m_randX)();
}

unsigned int Factory::randGeneSize() {
	return (*m_randGeneSize)();
}

unsigned int Factory::randY() {
	return (*m_randY)();
}

unsigned char Factory::randPrimary() {
	return (*m_randPrimary)();
}

unsigned int Factory::randGenomeIndex() {
	return (*m_randGenomeIndex)();
}

Gene Factory::makeRandomGene() {
	PIXEL color;
	color.r = randPrimary();
	color.g = randPrimary();
	color.b = randPrimary();
	color.a = randPrimary();

	unsigned int numPoints = randGeneSize();
	std::vector<std::pair<int, int> > points(numPoints);
	for(unsigned int i = 0; i < numPoints; ++i) {
		points.push_back(std::pair<int, int>(randX(), randY()));
	}

	return Gene(color, points);
}

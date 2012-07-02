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

FactoryPtr Factory::_Instance;

Factory::~Factory()
{
}

Factory::Factory()
		: _gen(boost::rand48(std::time(0))),
		  _randPrimary(
				  new boost::variate_generator<boost::rand48&, boost::uniform_int<unsigned char> >(
						  _gen,
						  boost::uniform_int<unsigned char>(0, 255)
				  )
		  ),
		  _randX(
				  new boost::variate_generator<boost::rand48&, boost::uniform_int<unsigned int> >(
						  _gen,
						  boost::uniform_int<unsigned int>(0, 0))
				  ),
		  _randY(
				  new boost::variate_generator<boost::rand48&, boost::uniform_int<unsigned int> >(
						  _gen,
						  boost::uniform_int<unsigned int>(0, 0))
				  ),
		  _randGeneSize(
				  new boost::variate_generator<boost::rand48&, boost::uniform_int<unsigned int> >(
						  _gen,
						  boost::uniform_int<unsigned int>(
								  Config::GetMinGeneSize(),
								  Config::GetMaxGeneSize()
						  )
				  )
		  )
{
}

FactoryPtr Factory::Instance()
{
	if(Factory::_Instance.get() == NULL) {
#ifdef QT_YES
		std::cout << "[ Factory::Instance() ] Using QtFactory" << std::endl;
		Factory::_Instance.reset(new QtFactory());
#endif
	}

	return Factory::_Instance;
}

void Factory::update()
{
	// changing random number generators

	if(Config::GetWidth() > 0) {
		delete _randX;
		_randX = new boost::variate_generator<boost::rand48&, boost::uniform_int<unsigned int> >(
				_gen, boost::uniform_int<unsigned int>(0, Config::GetWidth() - 1));
	}

	if(Config::GetHeight() > 0) {
		delete _randY;
		_randY = new boost::variate_generator<boost::rand48&, boost::uniform_int<unsigned int> >(
				_gen, boost::uniform_int<unsigned int>(0, Config::GetHeight() - 1));
	}

	delete _randGeneSize;
	_randGeneSize = new boost::variate_generator<boost::rand48&, boost::uniform_int<unsigned int> >(
							  _gen,
							  boost::uniform_int<unsigned int>(
									  Config::GetMinGeneSize(),
									  Config::GetMaxGeneSize()
							  )
					  );

	std::cout << "[ Factory::update() ] Updated factory" << std::endl;
}

unsigned int Factory::randX()
{
	return (*_randX)();
}



unsigned int Factory::randGeneSize()
{
	return (*_randGeneSize)();
}



unsigned int Factory::randY()
{
	return (*_randY)();
}



unsigned char Factory::randPrimary()
{
	return (*_randPrimary)();
}



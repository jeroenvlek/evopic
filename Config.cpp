/**
 * Config.cpp
 *
 *  Created on: Aug 9, 2011
 *      Author: Jeroen Vlek
 *	     Email: jeroenvlek@gmail.com
 *     Website: www.perceptivebits.com
 *     License: Free Beer (Feel free to use it in every 
 *              way possible and if you like it, make 
 *				sure to give me credit and buy me a drink 
 *              if we ever meet ;) )
 */

#include "Config.h"
#include "Factory.h"

unsigned int Config::_Width = 0;
unsigned int Config::_Height = 0;
unsigned int Config::_MinGeneSize = 3;
unsigned int Config::_MaxGeneSize = 10;
unsigned int Config::_GenomeSize = 30;
unsigned int Config::_PopulationSize = 8;

Config::Config()
{
}


Config::~Config()
{
}

unsigned int Config::GetGenomeSize()
{
    return _GenomeSize;
}

unsigned int Config::GetPopulationSize()
{
    return _PopulationSize;
}

unsigned int Config::GetHeight()
{
    return _Height;
}

unsigned int Config::GetMaxGeneSize()
{
    return _MaxGeneSize;
}

unsigned int Config::GetMinGeneSize()
{
    return _MinGeneSize;
}

unsigned int Config::GetWidth()
{
    return _Width;
}

void Config::SetGenomeSize(const unsigned int genomeSize)
{
    _GenomeSize = genomeSize;
}

void Config::SetPopulationSize(const unsigned int populationSize)
{
    _PopulationSize = populationSize;
}

void Config::SetHeight(const unsigned int Height)
{
    _Height = Height;
    Factory::Instance()->update();
}

void Config::SetMaxGeneSize(const unsigned int MaxGeneSize)
{
    _MaxGeneSize = MaxGeneSize;
    Factory::Instance()->update();
}

void Config::SetMinGeneSize(const unsigned int MinGeneSize)
{
    _MinGeneSize = MinGeneSize;
    Factory::Instance()->update();
}

void Config::SetWidth(const unsigned int Width)
{
    _Width = Width;
    Factory::Instance()->update();
}

std::string Config::GetTestImageName()
{
	return std::string("data/farnsworth.jpg");
}




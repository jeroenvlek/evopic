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

unsigned int Config::m_Width = 0;
unsigned int Config::m_Height = 0;
unsigned int Config::m_MinGeneSize = 3;
unsigned int Config::m_MaxGeneSize = 7;
unsigned int Config::m_GenomeSize = 10;
unsigned int Config::m_PopulationSize = 18;
unsigned int Config::m_MutationInterval = 2;
unsigned int Config::m_ReportingInterval = 10;

Config::Config()
{
}



Config::~Config()
{
}

unsigned int Config::GetGenomeSize()
{
    return m_GenomeSize;
}

unsigned int Config::GetPopulationSize()
{
    return m_PopulationSize;
}

unsigned int Config::GetHeight()
{
    return m_Height;
}

unsigned int Config::GetMaxGeneSize()
{
    return m_MaxGeneSize;
}

unsigned int Config::GetMinGeneSize()
{
    return m_MinGeneSize;
}

unsigned int Config::GetWidth()
{
    return m_Width;
}

unsigned int Config::GetMutationInterval() {
	return m_MutationInterval;
}

unsigned int Config::GetReportingInterval() {
	return m_ReportingInterval;
}


void Config::SetGenomeSize(const unsigned int genomeSize)
{
    m_GenomeSize = genomeSize;
}

void Config::SetPopulationSize(const unsigned int populationSize)
{
    m_PopulationSize = populationSize;
}

void Config::SetHeight(const unsigned int Height)
{
    m_Height = Height;
    Factory::Instance()->update();
}

void Config::SetMaxGeneSize(const unsigned int MaxGeneSize)
{
    m_MaxGeneSize = MaxGeneSize;
    Factory::Instance()->update();
}

void Config::SetMinGeneSize(const unsigned int MinGeneSize)
{
    m_MinGeneSize = MinGeneSize;
    Factory::Instance()->update();
}

void Config::SetWidth(const unsigned int Width)
{
    m_Width = Width;
    Factory::Instance()->update();
}

std::string Config::GetTestImageName()
{
	return std::string("data/simple_red_star.jpg");
}

void Config::SetMutationInterval(const unsigned int mutationInterval) {
	m_MutationInterval = mutationInterval;
}

void Config::SetReportingInterval(const unsigned int reportingInterval) {
	m_ReportingInterval = reportingInterval;
}



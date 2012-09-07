/**
 * DNA.cpp
 *
 *  Created on: Jul 31, 2011
 *      Author: Jeroen Vlek
 *	     Email: jeroenvlek@gmail.com
 *     Website: www.perceptivebits.com
 *     License: Free Beer (Feel free to use it in every 
 *              way possible and if you like it, make 
 *				sure to give me credit and buy me a drink 
 *              if we ever meet ;) )
 */

#include "Config.h"
#include "Organism.h"
#include "TargetImage.h"

#include <iostream>


Organism::Organism(const unsigned int genomeLength)
{
	init();

	for(unsigned int i = 0; i < genomeLength; ++i) {
		m_genome.push_back(m_factory->makeRandomGene());
	}

	createPhenotype();
}

Organism::Organism(const Organism& parentA, const Organism& parentB)
{
	init();

	unsigned int parentAContribution = Config::GetGenomeSize() / 2;
	unsigned int parentBContribution = Config::GetGenomeSize() - parentAContribution;

	std::vector<Gene*>::const_iterator it;
	for(it = parentA.m_genome.begin(); it != (parentA.m_genome.begin() + parentAContribution); ++it) {
		m_genome.push_back((*it)->clone());
	}
	for(it = parentB.m_genome.begin(); it != (parentB.m_genome.begin() + parentBContribution); ++it) {
		m_genome.push_back((*it)->clone());
	}

	createPhenotype();
}

Organism::~Organism()
{
	std::vector<Gene*>::iterator iter;
	for(iter = m_genome.begin(); iter != m_genome.end(); ++iter) {
		delete (*iter);
	}
}

void Organism::mutate(unsigned int numMutations)
{
	//TODO mutilate genes

	createPhenotype();
}

void Organism::createPhenotype()
{
	m_phenotype->clear();
	std::vector<Gene*>::iterator iter;
	for (iter = m_genome.begin(); iter != m_genome.end(); ++iter) {
		m_phenotype->drawGene(*(*iter));
	}
}

PhenotypeImage& Organism::getPhenotype()
{
	return *m_phenotype;
}



void Organism::init() throw(TargetImageNotLoadedEx)
{
	m_factory = Factory::Instance();

	// The phenotype has the same dimensions as the target image, therefore
	// it cannot be created before the target image is loaded.
	if(Config::GetWidth() == 0 || Config::GetHeight() == 0) {
		throw TargetImageNotLoadedEx(__FILE__, __LINE__);
	}
	else {
		m_phenotype = new PhenotypeImage();
	}

}



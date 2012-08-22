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
}

Organism::Organism(const Organism& parentA, const Organism& parentB)
{
	init();

	const std::vector<Gene*>& genesParentA = parentA.m_genome;
	const std::vector<Gene*>& genesParentB = parentB.m_genome;

	unsigned int parentAContribution = Config::GetGenomeSize() / 2;
	unsigned int parentBContribution = Config::GetGenomeSize() - parentAContribution;

	m_genome.insert(m_genome.end(), genesParentA.begin(), genesParentA.begin() + parentAContribution);
	m_genome.insert(m_genome.end(), genesParentB.begin(), genesParentB.begin() + parentBContribution);
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
}

PhenotypeImage& Organism::getPhenotype()
{
	m_phenotype->clear();

	std::vector<Gene*>::iterator iter;
	for(iter = m_genome.begin(); iter != m_genome.end(); ++iter) {
		m_phenotype->drawGene(*(*iter));
	}

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



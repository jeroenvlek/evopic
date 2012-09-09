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

#include <cassert>
#include <iostream>


Organism::Organism(const unsigned int genomeLength)
{
	init();

	for(unsigned int i = 0; i < genomeLength; ++i) {
		m_genome.push_back(m_factory->makeRandomGene());
	}

	createPhenotype();
}

Organism::Organism(const Organism& parentA, const Organism& parentB, const bool doMutation)
{
	assert(parentA.m_genome.size() == parentB.m_genome.size());
	init();

	for(unsigned int i = 0; i < parentA.m_genome.size(); ++i) {
		Gene* gene;
		if(i % 2) {
			gene = parentA.m_genome[i];
		}
		else {
			gene = parentB.m_genome[i];
		}

		m_genome.push_back(gene->clone());
	}

	if(doMutation) {
		// it doesn't really matter which gene is mutated, might as well take
		// the first one
		delete m_genome[0];
		m_genome[0] = m_factory->makeRandomGene();
	}

	createPhenotype();
}

Organism::~Organism()
{
	std::vector<Gene*>::iterator iter;
	for(iter = m_genome.begin(); iter != m_genome.end(); ++iter) {
		delete (*iter);
	}
	delete m_phenotype;
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



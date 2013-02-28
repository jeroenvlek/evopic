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
	for(unsigned int i = 0; i < genomeLength; ++i) {
		Gene* randomGene = Factory::Instance()->makeRandomGene();
		m_genome.push_back(randomGene);
	}
	createPhenotype();
}

Organism::Organism(const Organism& parentA, const Organism& parentB, const bool doMutation)
{
	assert(parentA.m_genome.size() == parentB.m_genome.size());

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
		unsigned int index = Factory::Instance()->randGenomeIndex();
		delete m_genome[index];
		Gene* randomGene = Factory::Instance()->makeRandomGene();
		m_genome[index] = randomGene;
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

void Organism::createPhenotype()
{
	m_phenotype.clear();
	std::vector<Gene*>::iterator iter;
	for (iter = m_genome.begin(); iter != m_genome.end(); ++iter) {
		m_phenotype.drawGene(*(*iter));
	}
}

PhenotypeImage& Organism::getPhenotype()
{
	return m_phenotype;
}



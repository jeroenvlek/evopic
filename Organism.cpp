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
		_genome.push_back(_factory->makeRandomGene());
	}
}

Organism::Organism(
		const std::vector<Gene*>& genesParentA,
		const std::vector<Gene*>& genesParentB)
{
	init();

	_genome.insert(_genome.end(), genesParentA.begin(), genesParentA.end());
	_genome.insert(_genome.end(), genesParentB.begin(), genesParentB.end());
}

Organism::~Organism()
{
	std::vector<Gene*>::iterator iter;
	for(iter = _genome.begin(); iter != _genome.end(); ++iter) {
		delete (*iter);
	}
}

void Organism::mutate(unsigned int numMutations)
{
}

PhenotypeImage& Organism::getPhenotype()
{
	_phenotype->clear();

	std::vector<Gene*>::iterator iter;
	for(iter = _genome.begin(); iter != _genome.end(); ++iter) {
		_phenotype->drawGene(*(*iter));
	}

	return *_phenotype;
}



void Organism::init() throw(TargetImageNotLoadedEx)
{
	_factory = Factory::Instance();

	// The phenotype has the same dimensions as the target image, therefore
	// it cannot be created before the target image is loaded.
	if(Config::GetWidth() == 0 || Config::GetHeight() == 0) {
		throw TargetImageNotLoadedEx(__FILE__, __LINE__);
	}
	else {
		_phenotype = new PhenotypeImage();
	}

}



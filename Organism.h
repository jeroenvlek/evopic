/**
 * Organism.h
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

#ifndef ORGANISM_H_
#define ORGANISM_H_

#include <vector>

#include "Exceptions.h"
#include "Factory.h"
#include "Gene.h"
#include "PhenotypeImage.h"
#include "memory/PoolableObject.h"

/**
 * The class that represents the organism. It contains both the genotype and
 * phenotype.
 */
class Organism : public memory::PoolableObject<Organism>
{
public:

	/**
	 * Constructs a DNA with length genomeLength.
	 *
	 * @param genomeLength The length of the gene sequence.
	 * @return DNA
	 */
	Organism(const unsigned int genomeLength = 0);

	/**
	 * Constructs a DNA object by concatenating the genes from parent A with the
	 * genes from parent B.
	 *
	 * @param genesParentA Half of the genes of parent A
	 * @param genesParentB Half of the genes of parent B
	 * @return DNA
	 */
	Organism(const Organism& parentA, const Organism& parentB, const bool doMutation = false);

	/**
	 * Destructor
	 *
	 * @return void
	 */
	virtual ~Organism();

	/**
	 * Draws the phenotype image, bases on the genome and returns a reference to it.
	 *
	 * @return PhenotypeImage of this Organism
	 */
	PhenotypeImage& getPhenotype();


private:
	/**
	 * The sequence of genes.
	 */
	std::vector<Gene*> m_genome;

	/**
	 * The phenotype image that is derived from the genes. This derivation is done
	 * in the getPhenotype function.
	 */
	PhenotypeImage m_phenotype;

	/**
	 * Creates the phenotype image from the genome
	 */
	void createPhenotype();
};

#endif /* ORGANISM_H_ */

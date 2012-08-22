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

/**
 * The class that represents the organism. It contains both the genotype and
 * phenotype.
 */
class Organism
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
	Organism(const Organism& parentA, const Organism& parentB);

	/**
	 * Destructor
	 *
	 * @return void
	 */
	virtual ~Organism();

	/**
	 * Mutates a given number of genes by randomly picking out genes from the genome
	 * and calling their mutate() function.
	 *
	 * @param numMutations The number of genes that are to be mutated.
	 */
	void mutate(unsigned int numMutations);

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
	 * The class responsible for making the genes.
	 */
	boost::shared_ptr<Factory> m_factory;

	/**
	 * The phenotype image that is derived from the genes. This derivation is done
	 * in the getPhenotype function.
	 */
	PhenotypeImage* m_phenotype;

	/**
	 * Common initalizer function for all constructor types
	 */
	void init() throw (TargetImageNotLoadedEx);
};

#endif /* ORGANISM_H_ */

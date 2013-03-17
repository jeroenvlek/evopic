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

#include <algorithm>
#include <cassert>
#include <iostream>
#include <boost/bind.hpp>

#include "Config.h"
#include "Organism.h"
#include "TargetImage.h"

Organism::Organism(const unsigned int genomeLength) : m_score(-1.0) {
	m_genome.reserve(genomeLength);
	for (unsigned int i = 0; i < genomeLength; ++i) {
		Gene randomGene = Factory::Instance().makeRandomGene();
		m_genome.push_back(randomGene);
	}
	createPhenotype();
}

Organism::Organism(const Organism& parentA, const Organism& parentB,
		const bool doMutation) : m_score(-1.0) {
	m_genome.reserve(parentA.m_genome.size());
	for (unsigned int i = 0; i < parentA.m_genome.size(); ++i) {
		if (i % 2) {
			const Gene& gene = parentA.m_genome[i];
			m_genome.push_back(gene);
		} else {
			const Gene& gene = parentB.m_genome[i];
			m_genome.push_back(gene);
		}
	}

	if (doMutation) {
		unsigned int index = Factory::Instance().randGenomeIndex();
		Gene randomGene = Factory::Instance().makeRandomGene();
		m_genome[index] = randomGene;
	}

	createPhenotype();
}

Organism::~Organism() {
}


void Organism::createPhenotype() {
	m_phenotype.clear();
	for_each(m_genome.begin(), m_genome.end(), boost::bind(&PhenotypeImage::drawGene, &m_phenotype, _1));
}

PhenotypeImage& Organism::getPhenotype() {
	return m_phenotype;
}

bool Organism::operator <(const Organism& other) {
	return m_score < other.m_score;
}

bool Organism::operator <=(const Organism& other) {
	return m_score <= other.m_score;
}

bool Organism::operator >(const Organism& other) {
	return m_score > other.m_score;
}

bool Organism::operator >=(const Organism& other) {
	return m_score >= other.m_score;
}

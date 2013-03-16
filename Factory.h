/**
 * Factory.h
 *
 *  Created on: Aug 2, 2011
 *      Author: Jeroen Vlek
 *	     Email: jeroenvlek@gmail.com
 *     Website: www.perceptivebits.com
 *     License: Free Beer (Feel free to use it in every 
 *              way possible and if you like it, make 
 *				sure to give me credit and buy me a drink 
 *              if we ever meet ;) )
 */

#ifndef FACTORY_H_
#define FACTORY_H_

#include "Config.h"
#include "Gene.h"
#include "ImageImp.h"

#include <boost/shared_ptr.hpp>
#include <boost/random/linear_congruential.hpp>
#include <boost/random/uniform_int.hpp>
#include <boost/random/variate_generator.hpp>


/**
 * Abstract factory for producing Genes and ImageImps. This is a singleton class.
 */
class Factory
{
public:
	virtual ~Factory();

	static Factory& Instance();

	Gene makeRandomGene();

	virtual ImageImp* makeImageImp() =0;

	/**
	 * Updates the factory according to the settings in Config. Should be called
	 * after any config changes.
	 */
	void update();

	/**
	 * @return Random gene size [0, Config::GetGenomeSize() ]
	 */
	unsigned int randGenomeIndex();

protected:
	Factory();

	/**
	 * @return Random primary color [0, 255]
	 */
	unsigned char randPrimary();

	/**
	 * @return Random x-coordinate [0, Config::GetWidth() )
	 */
	unsigned int randX();

	/**
	 * @return Random y-coordinate [0, Config::GetHeight() )
	 */
	unsigned int randY();

	/**
	 * @return Random gene size [Config::GetMinGeneSize(), Config::GetMaxGeneSize() ]
	 */
	unsigned int randGeneSize();

private:
	/**
	 * Fastest random number generator in the boost library.
	 */
	boost::rand48 m_gen;


	/**
	 * Function object that generates primary colors.
	 * Distribution for color values: [0, 255]
	 */
	boost::variate_generator<boost::rand48&, boost::uniform_int<unsigned char> >* m_randPrimary;

	/**
	 * Function object that generates x-coordinates. Distribution for
	 * x-coordinates: [0, Config::Width() ).
	 * On initialization Config::Width() is 0, meaning that the TargetImage should
	 * be loaded and subsequently the update function should be called first.
	 */
	boost::variate_generator<boost::rand48&, boost::uniform_int<unsigned int> >* m_randX;

	/**
	 * Function object that generates y-coordinates. Distribution for
	 * x-coordinates: [0, Config::Height() ).
	 * On initialization Config::Height() is 0, meaning that the TargetImage should
	 * be loaded and subsequently the update function should be called first.
	 */
	boost::variate_generator<boost::rand48&, boost::uniform_int<unsigned int> >* m_randY;

	/**
	 * Function object that generates gene sizes. Distribution for
	 * gene sizes: [Config::MinGeneSize, Config::MaxGeneSize].
	 */
	boost::variate_generator<boost::rand48&, boost::uniform_int<unsigned int> >* m_randGeneSize;

	/**
	 * Function object that generates gene indices (used for mutation)
	 */
	boost::variate_generator<boost::rand48&, boost::uniform_int<unsigned int> >* m_randGenomeIndex;

};

#endif /* FACTORY_H_ */

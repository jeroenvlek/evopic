/**
 * QtFactory.h
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

#ifndef QTFACTORY_H_
#define QTFACTORY_H_

#include "Factory.h"
#include "ImageImp.h"

class QtFactory: public Factory
{
public:
	QtFactory();
	virtual ~QtFactory();

	Gene* makeGene();
	Gene* makeRandomGene();

	ImageImp* makeImageImp();
};

#endif /* QTFACTORY_H_ */

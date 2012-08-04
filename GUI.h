/**
 * GUI.h
 *
 *  Created on: Aug 9, 2011
 *      Author: Jeroen Vlek
 *	     Email: jeroenvlek@gmail.com
 *     Website: www.perceptivebits.com
 *     License: Free Beer (Feel free to use it in every 
 *              way possible and if you like it, make 
 *				sure to give me credit and buy me a drink 
 *              if we ever meet ;) )
 */

#ifndef GUI_H_
#define GUI_H_

#include <string>

#include "PhenotypeImage.h"


class GUI
{
public:
	virtual ~GUI();

	/**
	 * Loads and displays the TargetImage.
	 *
	 * @return True on success, false on failure
	 */
	virtual bool loadTargetImage() =0;

	/**
	 * Displays the given PhenotypeImage at index.
	 * @param index
	 * @param phenotypeImage
	 */
	virtual void displayPhenotypeImage(unsigned int index, PhenotypeImage& phenotypeImage) =0;

protected:
	GUI();
};

#endif /* GUI_H_ */

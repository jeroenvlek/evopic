/**
 * TargetImage.h
 *
 *  Created on: Aug 3, 2011
 *      Author: Jeroen Vlek
 *	     Email: jeroenvlek@gmail.com
 *     Website: www.perceptivebits.com
 *     License: Free Beer (Feel free to use it in every 
 *              way possible and if you like it, make 
 *				sure to give me credit and buy me a drink 
 *              if we ever meet ;) )
 */

#ifndef TARGETIMAGE_H_
#define TARGETIMAGE_H_

#include "Image.h"

#include <boost/shared_ptr.hpp>
#include <string>


class TargetImage;
typedef boost::shared_ptr<TargetImage> TargetImagePtr;

/**
 * The target image that specifies the environment (i.e. the basis for natural
 * selection).
 */
class TargetImage: public Image
{
public:
	virtual ~TargetImage();

	static TargetImagePtr Instance();
	static bool IsLoaded();

	void loadFromFile(const std::string& filename);

private:
	static TargetImagePtr _Instance;
	static bool _Loaded;

	TargetImage();
};


#endif /* TARGETIMAGE_H_ */

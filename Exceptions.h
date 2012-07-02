/**
 * Exceptions.h
 *
 *  Created on: Aug 5, 2011
 *      Author: Jeroen Vlek
 *	     Email: jeroenvlek@gmail.com
 *     Website: www.perceptivebits.com
 *     License: Free Beer (Feel free to use it in every 
 *              way possible and if you like it, make 
 *				sure to give me credit and buy me a drink 
 *              if we ever meet ;) )
 */

#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <exception>
#include <sstream>

class EvoPicException: public std::exception
{
public:
	EvoPicException(const char* filename = NULL, const unsigned int line = 0)
			: _filename(filename), _line(line) { }

protected:
	const char* _filename;
	const unsigned int _line;
};

class TargetImageNotLoadedEx: public EvoPicException
{
public:
	TargetImageNotLoadedEx(const char* filename = NULL, const unsigned int line = 0)
			: EvoPicException(filename, line) { }
	virtual const char* what() const throw()
	{
		std::stringstream msg;
		msg << "Exception: TargetImage not loaded at " <<
				_filename << ", line " << _line;
		return msg.str().c_str();
	}
};

#endif /* EXCEPTIONS_H_ */

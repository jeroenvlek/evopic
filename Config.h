/**
 * Config.h
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

#ifndef CONFIG_H_
#define CONFIG_H_

#include <string>

/**
 * A class with only static members that contains all the config values.
 */
class Config
{
public:
    static unsigned int GetGenomeSize();
    static unsigned int GetHeight();
    static unsigned int GetMaxGeneSize();
    static unsigned int GetMinGeneSize();
    static unsigned int GetWidth();

    static void SetGenomeSize(const unsigned int GenomeSize);
    static void SetHeight(const unsigned int Height);
    static void SetMaxGeneSize(const unsigned int MaxGeneSize);
    static void SetMinGeneSize(const unsigned int MinGeneSize);
    static void SetWidth(const unsigned int Width);

    static std::string GetTestImageName();

private:
	Config();
	virtual ~Config();

	/**
	 * Width of the target image.
	 */
	static unsigned int _Width;

	/**
	 * Height of the target image.
	 */
	static unsigned int _Height;

	/**
	 * Minimum size of the genes, e.g. minimum number of points in a polygon
	 * gene or minimum radius of a circular gene.
	 */
	static unsigned int _MinGeneSize;

	/**
	 * Maximum size of the genes, e.g. maximum number of points in a polygon
	 * gene or maximum radius of a circular gene.
	 */
	static unsigned int _MaxGeneSize;

	/**
	 * Number of genes per organism
	 */
	static unsigned int _GenomeSize;

};

#endif /* CONFIG_H_ */

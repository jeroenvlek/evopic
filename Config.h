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
    static unsigned int GetPopulationSize();
    static unsigned int GetHeight();
    static unsigned int GetMaxGeneSize();
    static unsigned int GetMinGeneSize();
    static unsigned int GetWidth();
    static unsigned int GetMutationInterval();
    static unsigned int GetReportingInterval();

    static void SetGenomeSize(const unsigned int genomeSize);
    static void SetPopulationSize(const unsigned int populationSize);
    static void SetHeight(const unsigned int height);
    static void SetMaxGeneSize(const unsigned int maxGeneSize);
    static void SetMinGeneSize(const unsigned int minGeneSize);
    static void SetWidth(const unsigned int width);
    static void SetMutationInterval(const unsigned int mutationInterval);
    static void SetReportingInterval(const unsigned int reportingInterval);

    static std::string GetTestImageName();

private:
	Config();
	virtual ~Config();

	/**
	 * Width of the target image.
	 */
	static unsigned int m_Width;

	/**
	 * Height of the target image.
	 */
	static unsigned int m_Height;

	/**
	 * Minimum size of the genes, e.g. minimum number of points in a polygon
	 * gene or minimum radius of a circular gene.
	 */
	static unsigned int m_MinGeneSize;

	/**
	 * Maximum size of the genes, e.g. maximum number of points in a polygon
	 * gene or maximum radius of a circular gene.
	 */
	static unsigned int m_MaxGeneSize;

	/**
	 * Number of genes per organism
	 */
	static unsigned int m_GenomeSize;

	/**
	 * Population size
	 */
	static unsigned int m_PopulationSize;

	/**
	 * Number of iterations that need to pass between mutations.
	 */
	static unsigned int m_MutationInterval;

	/**
	 * Number of iterations that need to pass between logs.
	 */
	static unsigned int m_ReportingInterval;

};

#endif /* CONFIG_H_ */

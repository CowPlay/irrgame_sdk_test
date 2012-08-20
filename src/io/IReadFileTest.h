/*
 * IReadFileTest.h
 *
 *  Created on: Aug 9, 2012
 *      Author: litirvi
 */

#ifndef IREADFILETEST_H_
#define IREADFILETEST_H_

#include "io/IReadFile.h"
namespace irrgame
{
	namespace io
	{
		namespace tests
		{
			class IReadFileTest
			{
				public:

					// Must define void operator() with no arguments
					void operator()();

					void read();
					void seek();
					void getSize();
					void getPos();
					void getFileName();

				private:
					core::stringc mes;
			};
		} //end tests namespace
	} //end io namespace
} //end irrgame namespace



#endif /* IREADFILETEST_H_ */

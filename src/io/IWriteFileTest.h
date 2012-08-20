/*
 * IWriteFileTest.h
 *
 *  Created on: Aug 9, 2012
 *      Author: litirvi
 */

#ifndef IWRITEFILETEST_H_
#define IWRITEFILETEST_H_

#include "io/IWriteFile.h"
namespace irrgame
{
	namespace io
	{
		namespace tests
		{
			class IWriteFileTest
			{
				public:

					// Must define void operator() with no arguments
					void operator()();

					void write();
					void seek();
					void getPos();
					void getFileName();

				private:
					core::stringc mes;
			};
		} //end tests namespace
	} //end io namespace
} //end irrgame namespace

#endif /* IWRITEFILETEST_H_ */

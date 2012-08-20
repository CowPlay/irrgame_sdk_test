/*
 * IFileListTest.h
 *
 *  Created on: Aug 13, 2012
 *      Author: litirvi
 */

#ifndef IFILELISTTEST_H_
#define IFILELISTTEST_H_
#include "io/IFileList.h"
namespace irrgame
{
	namespace io
	{
		namespace tests
		{
			class IFileListTest
			{
				public:

					// Must define void operator() with no arguments
					void operator()();

					void getFileCount();
					void getFileName();
					void getFullFileName();
					void getFileSize();
					void getID();
					void isDirectory();
					void findFile();
					void getPath();
					void addItem();
					void sort();

				private:
					core::stringc mes;

			};
		} //end tests namespace
	} //end io namespace
} //end irrgame namespace



#endif /* IFILELISTTEST_H_ */

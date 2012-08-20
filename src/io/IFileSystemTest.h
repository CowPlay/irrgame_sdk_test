/*
 * IFileSystemTest.h
 *
 *  Created on: Aug 8, 2012
 *      Author: litirvi
 */

#ifndef IFILESYSTEMTEST_H_
#define IFILESYSTEMTEST_H_
#include "io/IFileSystem.h"
namespace irrgame
{
	namespace io
	{
		namespace tests
		{
			class IFileSystemTest
			{
				public:

					// Must define void operator() with no arguments
					void operator()();

					void createXMLReader();
					void getAbsolutePath();
					void flattenFilename();
					void createReadFile();
					void createMemoryReadFile();
					void createLimitReadFile();
					void createMemoryWriteFile();
					void createWriteFile();
					void getWorkingDirectory();
					void changeWorkingDirectoryTo();
					void existFile();
					void createFileList();
					void createEmptyAttributes();
				private:
					core::stringc mes;

			};
		} //end tests namespace
	} //end io namespace
} //end irrgame namespace

#endif /* IFILESYSTEMTEST_H_ */

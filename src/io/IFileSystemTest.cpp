/*
 * IFileSystemTest.cpp
 *
 *  Created on: Aug 8, 2012
 *      Author: litirvi
 */
#include "IFileSystemTest.h"
#include "cute.h"
#include "io/IFileSystem.h"

namespace irrgame
{
	namespace io
	{
		namespace tests
		{
			// Must define void operator() with no arguments
			void IFileSystemTest::operator()()
			{
				createXMLReader();
				getAbsolutePath();
				flattenFilename();
				createReadFile();
				createMemoryReadFile();
				createLimitReadFile();
				createMemoryWriteFile();
				createWriteFile();
				getWorkingDirectory();
				changeWorkingDirectoryTo();
				existFile();
				createFileList();
				createEmptyAttributes();

				ASSERTM(mes.c_str(), mes.size() == 0);
			}
			void IFileSystemTest::createXMLReader()
			{
				//TODO could not create XMLReader without a file name
				//TODO does not create XMLReader if the specified file does not exist

				IXMLReader* mfile = IFileSystem::createXMLReader("assets/io/fileXML1.xml");
				if (0 == mfile)
					mes.append(
							"\n createXMLReader: You can not read a file with no name");
				if (mfile)
				{
					mfile->drop();
					mfile = 0;
				}
			}

			void IFileSystemTest::getAbsolutePath()
			{
				//TODO can not return an absolute path without the file name

				core::stringc mpath;
				mpath = IFileSystem::getAbsolutePath("assets/io/fileEmpty.txt");
				if (mpath == 0)
					mes.append(
							"\n getAbsolutePath: return 0 when passed the name of an existing file");

			}

			void IFileSystemTest::flattenFilename()
			{
				core::stringc directory = "/assets/me/./././.././me/./.././";

				core::stringc& path = IFileSystem::flattenFilename(directory);

				if (path != "/assets/")
					mes.append("\n flattenFilename: incorrect flattenFilename");
			}

			void IFileSystemTest::createReadFile()
			{

				//TODO You can not create a file with an empty name

				//TODO  If this file name exists, overwrite the existing file


				IReadFile* mfile2 = IFileSystem::createReadFile("assets/io/fileEmpty.txt");
				if (mfile2 == 0)
					mes.append(
							"\n createAndOpenFile: return 0 when the file is create");
				if (mfile2)
				{
					mfile2->drop();
					mfile2 = 0;
				}

			}

			void IFileSystemTest::createMemoryReadFile()
			{
				// TODO You can not create the file if you are not allocated memory for him


				IReadFile* mfile1 = IFileSystem::createMemoryReadFile(
						(void*) "thisismemorystring", 30, "a", false);
				if (30 != mfile1->getSize())
					mes.append(
							"\n createMemoryReadFile: creates a file incorrectly indicating the size of the");
				if (mfile1)
				{
					mfile1->drop();
					mfile1 = 0;
				}

				IReadFile* mfile2 = IFileSystem::createMemoryReadFile(
						(void*) "thisismemorystring", 10, "fff", false);
				if (mfile2->getFileName() != "fff")
					mes.append(
							"\n createMemoryReadFile: creates a file incorrectly indicating the name of the");
				if (mfile2)
				{
					mfile2->drop();
					mfile2 = 0;
				}
				//TODO You can not create a file with an empty name

			}

			void IFileSystemTest::createLimitReadFile()
			{
				IReadFile* mfileOpen = IFileSystem::createMemoryReadFile(
						(void*) "thisismemorystring",
						sizeof("thisismemorystring"), "mfileOpen", false);

				//TODO You can not create a file with an empty name

				IReadFile* mfile1 = IFileSystem::createLimitReadFile("a",
						mfileOpen, 5, 7);
				if (mfile1 == 0)
					mes.append(
							"\n createLimitReadFile: return 0 when the LimitReadFile is create");
				if (mfile1)
				{
					mfile1->drop();
					mfile1 = 0;
				}

				//TODO pos+areaSize is not greater than the size of the alreadyOpenedFile

			}

			void IFileSystemTest::createMemoryWriteFile()
			{
				c8* buffer = new c8[20];
				// TODO You can not create the file if you are not allocated memory for him

				// TODO length of the file must be greater than 0
				// TODO You can not create a file with an empty name

				IWriteFile* mfile2 = IFileSystem::createMemoryWriteFile(buffer,
						70, "memoryfile", false);
				if (mfile2 == 0)
					mes.append(
							"\n createMemoryWriteFile: return 0 when the MemoryWriteFile is create");
				if (mfile2)
				{
					mfile2->drop();
					mfile2 = 0;
				}

			}

			void IFileSystemTest::createWriteFile()
			{
				IWriteFile* mfile = IFileSystem::createWriteFile("aaa");
				if (mfile == 0)
					mes.append(
							"\n createAndWriteFile: does not write file ");
				if (mfile)
				{
					mfile->drop();
					mfile = 0;
				}
				IWriteFile* mfile1 = IFileSystem::createWriteFile(
						"assets/io/fileWithContent.txt", true);
				if (mfile1 == 0)
					mes.append(
							"\n createAndWriteFile: does not write file ");
				if (mfile1)
				{
					mfile1->drop();
					mfile1 = 0;
				}
			}
			void IFileSystemTest::getWorkingDirectory()
			{
				core::stringc workDir = IFileSystem::getWorkingDirectory();
				if(workDir != "/Users/litirvi/workspace/irrgame_sdk_test")
								mes.append("\n getWorkingDirectory: returns the wrong Working Directory ");

			}
			void IFileSystemTest::changeWorkingDirectoryTo()
			{
				bool workDir = IFileSystem::changeWorkingDirectoryTo("");
				if (workDir)
					mes.append("\n changeWorkingDirectoryTo: changes the working directory to an empty string");
				workDir = IFileSystem::changeWorkingDirectoryTo("assets/");
				if (!workDir)
					mes.append("\n changeWorkingDirectoryTo: zaaaaaaa ");
				workDir = IFileSystem::changeWorkingDirectoryTo("mejgfhgfhgf");
				if (workDir)
					mes.append("\n changeWorkingDirectoryTo: changes the working directory to a non-existent");
			}
			void IFileSystemTest::existFile()
			{
				bool exFile = IFileSystem::existFile("aaaa");
				if (exFile)
					mes.append("\n existFile: non-existent file ");

				exFile = IFileSystem::existFile("");
				if (exFile)
					mes.append("\n existFile: non-existent file with no name");

				exFile = IFileSystem::existFile("../assets/io/fileEmpty.txt");
				if (!exFile)
					mes.append("\n existFile: can not find an existing file ");

			}
			void IFileSystemTest::createFileList()
			{
				IFileList* mfile = IFileSystem::createFileList();
				if(mfile == 0)
					mes.append("\n createFileList: does not create FileList");

			}
			void IFileSystemTest::createEmptyAttributes()
			{
				IAttributes* mattr = IFileSystem::createEmptyAttributes();
				if(mattr == 0)
					mes.append("\n createEmptyAttributes: does not create EmptyAttributes");
			}



		} //end tests namespace
	} //end io namespace
} //end irrgame namespace

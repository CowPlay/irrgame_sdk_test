/*
 * IFileListTest.cpp
 *
 *  Created on: Aug 13, 2012
 *      Author: litirvi
 */
#include "IFileListTest.h"
#include "cute.h"
#include "io/IFileSystem.h"

namespace irrgame
{
	namespace io
	{
		namespace tests
		{
			// Must define void operator() with no arguments
			void IFileListTest::operator()()
			{
				getFileCount();
				getFileName();
				getFullFileName();
				getFileSize();
				getID();
				isDirectory();
				findFile();
				getPath();
				addItem();
				sort();

				ASSERTM(mes.c_str(), mes.size() == 0);
			}
			void IFileListTest::getFileCount()
			{
				IFileList* flist = IFileSystem::createFileList();
				if(flist->getFileCount() == 0)
					mes.append("\n getFileCount: does not create FileList");
				if (flist)
					flist->drop();

			}
			void IFileListTest::getFileName()
			{
				IFileList* flist = IFileSystem::createFileList();

				if(flist->getFileName(0) == 0)
					mes.append("\n getFileName: return 0 when the index is less than FileCount");
				if(flist->getFileName(0) != "..")
					mes.append("\n getFileName: correctly returns the file name");
				if(flist->getFileName(170) != 0)
					mes.append("\n getFileName: does not return 0 when the index more FileCount");

				if (flist)
				{
					flist->drop();
					flist = 0;
				}

			}
			void IFileListTest::getFullFileName()
			{
				IFileList* flist = IFileSystem::createFileList();
				if (flist->getFullFileName(2) == 0)
					mes.append(
							"\n getFullFileName: return 0 when the index is less than FileCount");
				if (flist->getFullFileName(850) != 0)
					mes.append(
							"\n getFullFileName: does not return 0 when the index more FileCount");
				if (flist)
				{
					flist->drop();
					flist = 0;
				}
			}
			void IFileListTest::getFileSize()
			{
				IFileList* flist = IFileSystem::createFileList();
				if (flist->getFileSize(2) == 0)
					mes.append(
							"\n getFileSize: return 0 when the index is less than FileCount");
				if (flist->getFileSize(270) != 0)
					mes.append(
							"\n getFileSize: does not return 0 when the index more FileCount");
				if (flist)
				{
					flist->drop();
					flist = 0;
				}
			}
			void IFileListTest::getID()
			{
				IFileList* flist = IFileSystem::createFileList();
				if (flist->getID(2) == 0)
					mes.append(
							"\n getID: return 0 when the index is less than FileCount");
				if (flist->getID(270) != 0)
					mes.append(
							"\n getID: does not return 0 when the index more FileCount");
				if (flist)
				{
					flist->drop();
					flist = 0;
				}
			}
			void IFileListTest::isDirectory()
			{
				IFileList* flist = IFileSystem::createFileList();
				if (!flist->isDirectory(2))
					mes.append(
							"\n isDirectory: return 0 when the index is Directory");
				if (flist->isDirectory(270))
					mes.append(
							"\n isDirectory: does not return 0 when the index more FileCount");
				if (flist)
				{
					flist->drop();
					flist = 0;
				}
			}
			void IFileListTest::findFile()
			{
				IFileList* flist = IFileSystem::createFileList();

				if (flist->findFile("assassassasaasasas", false) != -1)
					mes.append(
							"\n findFile: does not return -1 when looking for a nonexistent file");
				if (flist->findFile("aaa", true) != -1)
					mes.append(
							"\n findFile: does not return -1 when looking for a file with no name");
				if (flist)
				{
					flist->drop();
					flist = 0;
				}

			}
			void IFileListTest::getPath()
			{
				IFileList* flist = IFileSystem::createFileList();
				if (flist->getPath() == 0)
					mes.append("\n getPath: does not return path");
				if (flist)
				{
					flist->drop();
					flist = 0;
				}
			}
			void IFileListTest::addItem()
			{
				IFileList* flist = IFileSystem::createFileList();
				if (flist->addItem("", 10, true,45))
					mes.append("\n addItem: You can not add to the list of file without a name");
				if (flist->addItem("aaa", 0, false))
					mes.append("\n addItem: You can not add to the list of file size of 0");
				if (flist)
				{
					flist->drop();
					flist = 0;
				}
			}
			void IFileListTest::sort()
			{

			}
		} //end tests namespace
	} //end io namespace
} //end irrgame namespace


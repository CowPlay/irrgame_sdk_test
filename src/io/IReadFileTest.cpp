/*
 * IReadFileTest.cpp
 *
 *  Created on: Aug 9, 2012
 *      Author: litirvi
 */
#include "IReadFileTest.h"
#include "cute.h"
#include "io/IReadFile.h"
#include "io/IFileSystem.h"
//#include <stdio.h>
namespace irrgame
{
	namespace io
	{
		namespace tests
		{

			// Must define void operator() with no arguments
			void IReadFileTest::operator()()
			{
				read();
				seek();
				getSize();
				getPos();
				getFileName();
				ASSERTM(mes.c_str(), mes.size() == 0);
			}
			void IReadFileTest::read()
			{
				IReadFile* mfile = IFileSystem::createMemoryReadFile(
						(void*) "thisismemorystring",
						sizeof("thisismemorystring"), "a", false);

				c8* buffer = new c8[18];
				s32 readBytesSize = mfile->read(buffer, 0);
				if (0 != readBytesSize)
					mes.append("\n sizeToRead should not be equal 0");
				if (buffer)
					delete buffer;

			}
			void IReadFileTest::seek()
			{

				IReadFile* mfile = IFileSystem::createMemoryReadFile(
						(void*) "thisismemorystring",
						sizeof("thisismemorystring"), "a", false);
				if (mfile->seek(40, false))
					mes.append(
							"\n finalPos should not be greater than the length of the file");
				if (mfile)
				{
					mfile->drop();
					mfile = 0;
				}

			}
			void IReadFileTest::getSize()
			{

				IReadFile* mfile = IFileSystem::createMemoryReadFile(
						(void*) "thisismemorystring",
						sizeof("thisismemorystring"), "a", false);
				if (sizeof("thisismemorystring") != mfile->getSize())
					mes.append("\n correctly reads the file size");
				if (mfile)
				{
					mfile->drop();
					mfile = 0;
				}
			}
			void IReadFileTest::getPos()
			{

				IReadFile* mfile = IFileSystem::createMemoryReadFile(
						(void*) "thisismemorystring",
						sizeof("thisismemorystring"), "a", false);
				if (0 != mfile->getPos())
					mes.append("\n ccorrectly reads the file size position");
				if (mfile)
				{
					mfile->drop();
					mfile = 0;
				}
			}
			void IReadFileTest::getFileName()
			{

				IReadFile* mfile = IFileSystem::createMemoryReadFile(
						(void*) "thisismemorystring",
						sizeof("thisismemorystring"), "qwerty", false);
				core::stringc mFileName = mfile->getFileName();
				core::stringc fileName = "qwerty";
				if (fileName != mFileName)
					mes.append("\n correctly reads the file name");
				if (mfile)
				{
					mfile->drop();
					mfile = 0;
				}
			}
		} //end tests namespace
	} //end io namespace
} //end irrgame namespace


/*
 * IWriteFileTest.cpp
 *
 *  Created on: Aug 9, 2012
 *      Author: litirvi
 */
#include "IWriteFileTest.h"
#include "cute.h"
#include "io/IWriteFile.h"
#include "io/IFileSystem.h"
#include "core/irrString.h"
namespace irrgame
{
	namespace io
	{
		namespace tests
		{
			// Must define void operator() with no arguments
			void IWriteFileTest::operator()()
			{
				write();
				seek();
				getPos();
				getFileName();
				ASSERTM(mes.c_str(), mes.size() == 0);
			}

			void IWriteFileTest::write()
			{

				c8* bufferRW = new c8[20];
				IWriteFile* mfile = IFileSystem::createMemoryWriteFile(
						(void*) bufferRW, 20, "memoryfile", false);

				c8* in = "memorystr";
				c8* out = new c8[20];

				IReadFile* mfileR = IFileSystem::createMemoryReadFile(
						(void*) bufferRW, 20, "readfile", false);

				//!------------ TESTs
				s32 writeBytesSize = mfile->write(in, 0);
				if (0 != writeBytesSize)
					mes.append("\n sizeToWrite should not be equal 0");

				mfile->write(in, 5);
				mfileR->read(out, 20);
				core::stringc strIn = in;
				core::stringc strOut = out;
				if (!strIn.equalsn(strOut.c_str(), 5))
					mes.append("\n writes the file incorrect");

				if (out)
					delete out;

				if (bufferRW)
					delete bufferRW;
				if (mfile)
				{
					mfile->drop();
					mfile = 0;
				}
				if (mfileR)
				{
					mfileR->drop();
					mfileR = 0;
				}

			}
			void IWriteFileTest::seek()
			{

				c8* bufferRW = new c8[20];
				IWriteFile* mfile = IFileSystem::createMemoryWriteFile(
						(void*) bufferRW, 20, "memoryfile", false);
				if (mfile->seek(40, false))
					mes.append(
							"\n finalPos should not be greater than the length of the file ");
				if (mfile)
				{
					mfile->drop();
					mfile = 0;
				}

			}

			void IWriteFileTest::getPos()
			{

				c8* bufferRW = new c8[20];
				IWriteFile* mfile = IFileSystem::createMemoryWriteFile(
						(void*) bufferRW, 20, "memoryfile", false);
				if (0 != mfile->getPos())
					mes.append("\n position in the new file should be 0");
				if (mfile)
				{
					mfile->drop();
					mfile = 0;
				}
			}
			void IWriteFileTest::getFileName()
			{

				c8* bufferRW = new c8[20];
				IWriteFile* mfile = IFileSystem::createMemoryWriteFile(
						(void*) bufferRW, 20, "memoryfile", false);
				core::stringc mFileName = mfile->getFileName();
				core::stringc fileName = "memoryfile";
				if (fileName != mFileName)
					mes.append("\n not correctly read the file name");
				if (mfile)
				{
					mfile->drop();
					mfile = 0;
				}
			}
		} //end tests namespace
	} //end io namespace
} //end irrgame namespace


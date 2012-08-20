/*
 * CMemoryFileTest.cpp
 *
 *  Created on: Aug 7, 2012
 *      Author: litirvi
 */
#include "CMemoryFileTest.h"
#include "cute.h"
#include "io/IReadFile.h"

void testCMemoryFileSeek()
{
	irrgame::io::IReadFile* mFile = irrgame::io::createMemoryReadFile((void*) "thisismemorystring",
			sizeof("thisismemorystring"), "", false);

	ASSERTM("seek", mFile->seek(0,false) != false);

}



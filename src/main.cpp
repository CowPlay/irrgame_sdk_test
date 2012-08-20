#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"

#include "io/IFileSystemTest.h"
#include "io/IReadFileTest.h"
#include "io/IWriteFileTest.h"
#include "io/IXMLReaderTest.h"
#include "io/IXMLWriterTest.h"
#include "io/IFileListTest.h"

using namespace irrgame;
using namespace io;
using namespace tests;

void runSuiteIFileSystem()
{
	cute::suite suiteIFileSystem;

	suiteIFileSystem.push_back(IFileSystemTest());

	cute::ide_listener lis;
	cute::makeRunner(lis)(suiteIFileSystem, "The SuiteIFileSystem");
}
void runSuiteIReadFile()
{
	cute::suite suiteIReadFile;
	suiteIReadFile.push_back(IReadFileTest());
	cute::ide_listener lis;
	cute::makeRunner(lis)(suiteIReadFile, "The SuiteIReadFile");
}

void runSuiteIWriteFile()
{
	cute::suite suiteIWriteFile;
	suiteIWriteFile.push_back(IWriteFileTest());
	cute::ide_listener lis;
	cute::makeRunner(lis)(suiteIWriteFile, "The SuiteIWriteFile");
}
void runSuiteIXMLReader()
{
	cute::suite suiteIXMLReader;
	suiteIXMLReader.push_back(IXMLReaderTest());
	cute::ide_listener lis;
	cute::makeRunner(lis)(suiteIXMLReader, "The SuiteIXMLReader");
}
void runSuiteIXMLWriter()
{
	cute::suite suiteIXMLWriter;
	suiteIXMLWriter.push_back(IXMLWriterTest());
	cute::ide_listener lis;
	cute::makeRunner(lis)(suiteIXMLWriter, "The SuiteIXMLWriter");
}
void runSuiteIFileList()
{
	cute::suite suiteIFileList;
	suiteIFileList.push_back(IFileListTest());
	cute::ide_listener lis;
	cute::makeRunner(lis)(suiteIFileList, "The SuiteIFileList");
}
int main()
{
//	runSuiteIFileSystem();
//	runSuiteIReadFile();
//	runSuiteIWriteFile();
//	runSuiteIXMLReader();
//	runSuiteIXMLWriter();
	runSuiteIFileList();
	return 0;
}


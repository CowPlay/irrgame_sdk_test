/*
 * IXMLWriterTest.cpp
 *
 *  Created on: Aug 15, 2012
 *      Author: litirvi
 */
#include "IXMLWriterTest.h"
#include "cute.h"
#include "io/xml/IXMLWriter.h"
#include "io/IFileSystem.h"
namespace irrgame
{
	namespace io
	{
		namespace tests
		{
			// Must define void operator() with no arguments
			void IXMLWriterTest::operator()()
			{
				writeXMLHeader();
				writeElement();
				writeComment();
				writeClosingTag();
				writeText();
				writeLineBreak();

				ASSERTM(mes.c_str(), mes.size() == 0);
			}

			void IXMLWriterTest::writeXMLHeader()
			{
				IWriteFile* fWrite = IFileSystem::createWriteFile(
						"assets/io/fileXMLEmpty.xml");
				IXMLWriter* fxml = IFileSystem::createXMLWriter(fWrite);

				if (fWrite)
					fWrite->drop();

				fxml->writeXMLHeader();

				if (fxml)
					fxml->drop();

				IReadFile* fRead = IFileSystem::createReadFile(
						"assets/io/fileXMLEmpty.xml");
				IXMLReader* fxmlR = IFileSystem::createXMLReader(fRead);
				fxmlR->read();
				if (fxmlR->getNodeType() != EXNT_UNKNOWN)
					mes.append(
							"\n writeXMLHeader: does not write the XMLHeader");

				if (fxmlR)
					fxmlR->drop();
				if (fRead)
					fRead->drop();
			}

			void IXMLWriterTest::writeElement()
			{

				IWriteFile* fWrite = IFileSystem::createWriteFile(
						"assets/io/fileXMLEmpty.xml");
				IXMLWriter* fxml = IFileSystem::createXMLWriter(fWrite);

				if (fWrite)
					fWrite->drop();

				fxml->writeElement("fff", true, "attr1", "attrValue1");

				if (fxml)
					fxml->drop();

				IReadFile* fRead = IFileSystem::createReadFile(
						"assets/io/fileXMLEmpty.xml");
				IXMLReader* fxmlR = IFileSystem::createXMLReader(fRead);

				fxmlR->read();

				if (fxmlR->getNodeType() != EXNT_ELEMENT)
					mes.append(
							"\n writeElement: incorrectly indicates the type of node");

				if (fxmlR->getAttributeCount() != 1)
					mes.append(
							"\n writeElement: correctly returns the number of attributes");

				core::stringc strA = core::stringc("attr1");
				if (!strA.equalsn(fxmlR->getAttributeName(0), 4))
					mes.append(
							"\n writeElement: correctly returns the name of attributes");

				core::stringc strV = core::stringc("attrValue1");
				if (!strV.equalsn(fxmlR->getAttributeValue(0), 10))
					mes.append(
							"\n writeElement: correctly returns the value of attributes");
				if (fxmlR)
					fxmlR->drop();
				if (fRead)
					fRead->drop();

//TODO should not create an element with no name

				IWriteFile* fWrite1 = IFileSystem::createWriteFile(
						"assets/io/fileXMLEmpty.xml");
				IXMLWriter* fxml1 = IFileSystem::createXMLWriter(fWrite1);

				if (fWrite1)
					fWrite1->drop();
				fxml1->writeElement("", true);
				if (fxml1)
					fxml1->drop();

				IReadFile* fRead1 = IFileSystem::createReadFile(
						"assets/io/fileXMLEmpty.xml");
				IXMLReader* fxmlR1 = IFileSystem::createXMLReader(fRead1);

				fxmlR1->read();
				core::stringc strN = core::stringc("");
				if (strN.equalsn(fxmlR1->getNodeName(), 1))
					mes.append("\n writeElement: node name can not be empty");

				if (fxmlR1->getAttributeCount() != 0)
					mes.append("\n writeElement: sees non-existent attributes");

				if (fxmlR1)
					fxmlR1->drop();

				if (fRead1)
					fRead1->drop();

				core::array<core::stringc> atr;
				atr.insert(core::stringc("atr1"));
				atr.insert(core::stringc("atr2"));
				atr.insert(core::stringc("7"));
				atr.insert(core::stringc(0));
				atr.insert(core::stringc("art5"));
				atr.insert(core::stringc("</>"));
				atr.insert(core::stringc("art7"));

				core::array<core::stringc> atrValue;
				atrValue.insert(core::stringc("atrValue1"));
				atrValue.insert(core::stringc("atrValue2"));
				atrValue.insert(core::stringc("atrValue3"));
				atrValue.insert(core::stringc("atrValue4"));
				atrValue.insert(core::stringc("atrValue5"));
				atrValue.insert(core::stringc("6"));
				atrValue.insert(core::stringc(""));

				IWriteFile* fWrite3 = IFileSystem::createWriteFile(
						"assets/io/fileXMLEmpty.xml");
				IXMLWriter* fxml3 = IFileSystem::createXMLWriter(fWrite3);
				if (fWrite3)
					fWrite3->drop();

				fxml3->writeElement("fff", true, atr, atrValue);

				if (fxml3)
					fxml3->drop();

				IReadFile* fRead3 = IFileSystem::createReadFile(
						"assets/io/fileXMLEmpty.xml");
				IXMLReader* fxmlR3 = IFileSystem::createXMLReader(fRead3);

				fxmlR3->read();

				if (fxmlR3->getAttributeCount() != 7)
					mes.append(
							"\n writeElement: correctly returns the number of attributes");

				//TODO attribute name can not be a 0
				if (fxmlR3->getAttributeName(3) == 0)
					mes.append(
							"\n writeElement: attribute name can not be a 0");

				//TODO attribute value can not be empty
				core::stringc strAV = core::stringc("");
				if (strAV.equalsn(fxmlR3->getAttributeValue(6), 1))
					mes.append(
							"\n writeElement: attribute value can not be empty");

				if (fxmlR3)
				{
					fxmlR3->drop();
				}

			}
			void IXMLWriterTest::writeComment()
			{

				IWriteFile* fWrite = IFileSystem::createWriteFile(
						"assets/io/fileXMLEmpty.xml");
				IXMLWriter* fxml = IFileSystem::createXMLWriter(fWrite);

				if (fWrite)
					fWrite->drop();

				fxml->writeComment(static_cast<const c8*>("bla bla bla"));

				if (fxml)
					fxml->drop();

				IReadFile* fRead = IFileSystem::createReadFile(
						"assets/io/fileXMLEmpty.xml");
				IXMLReader* fxmlR = IFileSystem::createXMLReader(fRead);

				fxmlR->read();

				if (fxmlR->getNodeType() != EXNT_COMMENT)
					mes.append("\n writeComment: comment is not created");

				if (fxmlR)
					fxmlR->drop();

//TODO creates an empty comment

				IWriteFile* fWrite1 = IFileSystem::createWriteFile(
						"assets/io/fileXMLEmpty.xml");
				IXMLWriter* fxml1 = IFileSystem::createXMLWriter(fWrite1);

				if (fWrite1)
					fWrite1->drop();

				fxml1->writeComment(static_cast<const c8*>(""));

				if (fxml1)
					fxml1->drop();

				IReadFile* fRead1 = IFileSystem::createReadFile(
						"assets/io/fileXMLEmpty.xml");
				IXMLReader* fxmlR1 = IFileSystem::createXMLReader(fRead1);

				fxmlR1->read();

				if (fxmlR1->getNodeType() != EXNT_COMMENT)
					mes.append("\n writeComment: empty comment is not created");

				if (fxmlR1)
					fxmlR1->drop();
			}
			void IXMLWriterTest::writeClosingTag()
			{

				IWriteFile* fWrite = IFileSystem::createWriteFile(
						"assets/io/fileXMLEmpty.xml");
				IXMLWriter* fxml = IFileSystem::createXMLWriter(fWrite);

				if (fWrite)
					fWrite->drop();

				fxml->writeClosingTag("fff");

				if (fxml)
					fxml->drop();

				IReadFile* fRead = IFileSystem::createReadFile(
						"assets/io/fileXMLEmpty.xml");
				IXMLReader* fxmlR = IFileSystem::createXMLReader(fRead);

				fxmlR->read();

				if (fxmlR->getNodeType() != EXNT_ELEMENT_END)
					mes.append(
							"\n writeClosingTag: Closing tag is not created");

				if (fxmlR)
					fxmlR->drop();

// TODO create empty closing teg

				IWriteFile* fWrite1 = IFileSystem::createWriteFile(
						"assets/io/fileXMLEmpty.xml");
				IXMLWriter* fxml1 = IFileSystem::createXMLWriter(fWrite1);

				if (fWrite1)
					fWrite1->drop();

				fxml1->writeClosingTag("");

				if (fxml1)
					fxml1->drop();

				IReadFile* fRead1 = IFileSystem::createReadFile(
						"assets/io/fileXMLEmpty.xml");
				IXMLReader* fxmlR1 = IFileSystem::createXMLReader(fRead1);

				fxmlR1->read();

				if (fxmlR1->getNodeType() != EXNT_ELEMENT_END)
					mes.append(
							"\n writeClosingTag: emty closing tag is not created");

				if (fxmlR1)
					fxmlR1->drop();

			}
			void IXMLWriterTest::writeText()
			{

				IWriteFile* fWrite = IFileSystem::createWriteFile(
						"assets/io/fileXMLEmpty.xml");
				IXMLWriter* fxml = IFileSystem::createXMLWriter(fWrite);

				if (fWrite)
					fWrite->drop();
				fxml->writeElement("fff", false);
				fxml->writeText("text text text");
				fxml->writeClosingTag("fff");
				if (fxml)
					fxml->drop();

				IReadFile* fRead = IFileSystem::createReadFile(
						"assets/io/fileXMLEmpty.xml");
				IXMLReader* fxmlR = IFileSystem::createXMLReader(fRead);

				fxmlR->read();
				fxmlR->read();

				if (fxmlR->getNodeType() != EXNT_TEXT)
					mes.append("\n writeText: element text is not created");

				core::stringc strND = core::stringc("text text text");
				if (!strND.equalsn(fxmlR->getNodeData(), 14))
					mes.append(
							"\n writeText: correctly writes text content of the");

				if (fxmlR)
					fxmlR->drop();

			}

			void IXMLWriterTest::writeLineBreak()
			{
				IWriteFile* fWrite = IFileSystem::createWriteFile(
						"assets/io/fileXMLEmpty.xml");
				IXMLWriter* fxml = IFileSystem::createXMLWriter(fWrite);

				if (fWrite)
					fWrite->drop();
				fxml->writeElement("fff", false);
				fxml->writeText("text text text");
				fxml->writeLineBreak();
				fxml->writeText(" text1 text1 text1");
				fxml->writeClosingTag("fff");
				if (fxml)
					fxml->drop();

				IReadFile* fRead = IFileSystem::createReadFile(
						"assets/io/fileXMLEmpty.xml");
				IXMLReader* fxmlR = IFileSystem::createXMLReader(fRead);

				fxmlR->read();
				fxmlR->read();

				if (fxmlR->getNodeType() != EXNT_TEXT)
					mes.append(
							"\n writeLineBreak: element text is not created");

				core::stringc strND = core::stringc(
						"text text text /r text1 text1 text1");
				if (!strND.equalsn(fxmlR->getNodeData(), 17))
					mes.append(
							"\n writeLineBreak: correctly writes text content of the");

				if (fxmlR)
					fxmlR->drop();
			}
		} //end tests namespace
	} //end io namespace
} //end irrgame namespace


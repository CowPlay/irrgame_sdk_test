/*
 * IXMLReaderTest.cpp
 *
 *  Created on: Aug 13, 2012
 *      Author: litirvi
 */

#include "IXMLReaderTest.h"
#include "cute.h"
#include "io/xml/IXMLReader.h"
#include "io/IFileSystem.h"
namespace irrgame
{
	namespace io
	{
		namespace tests
		{
			// Must define void operator() with no arguments
			void IXMLReaderTest::operator()()
			{
				read();
				getNodeType();
				getAttributeCount();
				getAttributeName();
				getAttributeValue();
				getAttributeValueSafe();
				getAttributeValueAsInt();
				getAttributeValueAsFloat();
				getNodeName();
				getNodeData();
				isEmptyElement();

				ASSERTM(mes.c_str(), mes.size() == 0);
			}
			void IXMLReaderTest::read()
			{
				IXMLReader* mfile = IFileSystem::createXMLReader(
						"assets/io/fileXML.xml");
				if (!mfile->read())
					mes.append(
							"\n read: do not read ahead to the next node XML.");
				if (mfile)
				{
					mfile->drop();
					mfile = 0;
				}

				IXMLReader* mfile1 = IFileSystem::createXMLReader(
						"assets/io/fileXMLEmpty1.xml");
				if (mfile1->read())
					mes.append(
							"\n read: Read ahead to the next node XML file, an empty");
				if (mfile1)
				{
					mfile1->drop();
					mfile1 = 0;
				}

				// TODO should not be read without a file name
				IXMLReader* mfile2 = IFileSystem::createXMLReader("");
				if (mfile2->read())
					mes.append(
							"\n read: Read ahead to the next node XML without a file name");
				if (mfile2)
				{
					mfile2->drop();
					mfile2 = 0;
				}
			}
			void IXMLReaderTest::getNodeType()
			{
				IXMLReader* mfile = IFileSystem::createXMLReader(
						"assets/io/fileXML.xml");
				mfile->read();
				if (mfile->getNodeType() != EXNT_UNKNOWN)
					mes.append(
							"\n getNodeType: correctly identifies the type of tag");
				if (mfile)
				{
					mfile->drop();
					mfile = 0;
				}
//TODO not refer to a nonexistent node
				IXMLReader* mfile1 = IFileSystem::createXMLReader(
						"assets/io/fileXMLEmpty1.xml");
				mfile1->read();
				if (mfile1->getNodeType() != 0)
					mes.append(
							"\n getNodeType: does not return 0 when the tag does not exist");
				if (mfile1)
				{
					mfile1->drop();
					mfile1 = 0;
				}
				// TODO should not be read without a file name
				IXMLReader* mfile2 = IFileSystem::createXMLReader("");
				mfile2->read();
				if (mfile2->getNodeType() != 0)
					mes.append(
							"\n getNodeType: does not return 0 when without a file name");
				if (mfile2)
				{
					mfile2->drop();
					mfile2 = 0;
				}

//				IXMLReader* xml = IFileSystem::createXMLReader(
//						"assets/io/fileXML.xml");
//				while (xml->read())
//				{
//					switch (xml->getNodeType())
//					{
//						case EXNT_NONE:
//						{
//							mes.append("\n EXNT_NONE");
//
//							break;
//						}
//						case EXNT_ELEMENT:
//						{
//							mes.append("\n EXNT_ELEMENT");
//							break;
//						}
//						case EXNT_ELEMENT_END:
//						{
//							mes.append("\n EXNT_ELEMENT_END");
//							break;
//						}
//						case EXNT_TEXT:
//						{
//							mes.append("\n EXNT_TEXT");
//							break;
//						}
//						case EXNT_COMMENT:
//						{
//							mes.append("\n EXNT_COMMENT");
//							break;
//						}
//						case EXNT_CDATA:
//						{
//							mes.append("\n EXNT_CDATA");
//							break;
//						}
//						case EXNT_UNKNOWN:
//						{
//							mes.append("\n EXNT_UNKNOWN");
//							break;
//						}
//
//					}
//
//				}
			}
			void IXMLReaderTest::getAttributeCount()
			{

				IXMLReader* mfile = IFileSystem::createXMLReader(
						"assets/io/fileXML.xml");
				mfile->read();
				mfile->read();
				if (mfile->getAttributeCount() == 0)
					mes.append(
							"\n getAttributeCount: correctly identifies the type of tag");

				if (mfile)
				{
					mfile->drop();
					mfile = 0;
				}
				//TODO not refer to a nonexistent Attribute
				IXMLReader* mfile1 = IFileSystem::createXMLReader(
						"assets/io/fileXMLEmpty1.xml");
				mfile1->read();
				if (mfile1->getAttributeCount() != 0)
					mes.append(
							"\n getAttributeCount: does not return 0 when the tag does not exist");
				if (mfile1)
				{
					mfile1->drop();
					mfile1 = 0;
				}
				// TODO should not be read without a file name
				IXMLReader* mfile2 = IFileSystem::createXMLReader("");
				mfile2->read();
				if (mfile2->getAttributeCount() != 0)
					mes.append(
							"\n getAttributeCount: does not return 0 when without a file name");
				if (mfile2)
				{
					mfile2->drop();
					mfile2 = 0;
				}
			}
			void IXMLReaderTest::getAttributeName()
			{
				IXMLReader* mfile = IFileSystem::createXMLReader(
						"assets/io/fileXML.xml");
				mfile->read();
				mfile->read();

				if (mfile->getAttributeName(0) == 0)
					mes.append(
							"\n getAttributeName: return 0 when the tag exist");
				core::stringc str = core::stringc("name");
				if (!str.equalsn(mfile->getAttributeName(0), 4))
					mes.append(
							"\n getAttributeName: correctly returns the name of attribute");

				//TODO you can not pass the index of a nonexistent
				mfile->getAttributeName(6);

				if (mfile)
				{
					mfile->drop();
					mfile = 0;
				}
				//TODO not refer to a nonexistent Attribute name
				IXMLReader* mfile1 = IFileSystem::createXMLReader(
						"assets/io/fileXMLEmpty1.xml");
				mfile1->read();
				if (mfile1->getAttributeName(0) != 0)
					mes.append(
							"\n getAttributeName: does not return 0 when the tag does not exist");
				if (mfile1)
				{
					mfile1->drop();
					mfile1 = 0;
				}
				// TODO should not be read without a file name
				IXMLReader* mfile2 = IFileSystem::createXMLReader("");
				mfile2->read();
				if (mfile2->getAttributeName(0) != 0)
					mes.append(
							"\n getAttributeName: does not return 0 when without a file name");
				if (mfile2)
				{
					mfile2->drop();
					mfile2 = 0;
				}
			}
			void IXMLReaderTest::getAttributeValue()
			{
				IXMLReader* mfile = IFileSystem::createXMLReader(
						"assets/io/fileXML.xml");
				mfile->read();
				mfile->read();
				if (mfile->getAttributeValue("preptime") == 0)
					mes.append(
							"\n getAttributeValue: return 0 when the Attribute exist");
				//TODO not refer to a nonexistent Attribute
				mfile->getAttributeValue(25);
				if (mfile)
				{
					mfile->drop();
					mfile = 0;
				}

				//TODO not refer to a nonexistent Attribute
				IXMLReader* mfile1 = IFileSystem::createXMLReader(
						"assets/io/fileXMLEmpty1.xml");
				mfile1->read();
				if (mfile1->getAttributeValue(0) != 0)
					mes.append(
							"\n getAttributeValue: does not return 0 when the tag does not exist");
				if (mfile1)
				{
					mfile1->drop();
					mfile1 = 0;
				}
				// TODO should not be read without a file name
				IXMLReader* mfile2 = IFileSystem::createXMLReader("");
				mfile2->read();
				if (mfile2->getAttributeValue(0) != 0)
					mes.append(
							"\n getAttributeValue: does not return 0 when without a file name");
				if (mfile2)
				{
					mfile2->drop();
					mfile2 = 0;
				}
			}

			void IXMLReaderTest::getAttributeValueSafe()
			{
				IXMLReader* mfile = IFileSystem::createXMLReader(
						"assets/io/fileXML.xml");
				mfile->read();
				mfile->read();
				if (mfile->getAttributeValueSafe("preptime") == 0)
					mes.append(
							"\n getAttributeValueSafe: return 0 when the Attribute exist");
				//TODO not refer to a nonexistent Attribute
				mfile->getAttributeValueSafe("preptssssime");
				if (mfile)
				{
					mfile->drop();
					mfile = 0;
				}

				IXMLReader* mfile1 = IFileSystem::createXMLReader(
						"assets/io/fileXMLEmpty1.xml");
				mfile1->read();
				if (mfile1->getAttributeValueSafe(0) == 0)
					mes.append(
							"\n getAttributeValueSafe: does not return 0 when the tag does not exist");
				if (mfile1)
				{
					mfile1->drop();
					mfile1 = 0;
				}
				// TODO should not be read without a file name
				IXMLReader* mfile2 = IFileSystem::createXMLReader("");
				mfile2->read();
				if (mfile2->getAttributeValueSafe(0) == 0)
					mes.append(
							"\n getAttributeValueSafe: does not return 0 when without a file name");
				if (mfile2)
				{
					mfile2->drop();
					mfile2 = 0;
				}
			}
			void IXMLReaderTest::getAttributeValueAsInt()
			{
				IXMLReader* mfile = IFileSystem::createXMLReader(
						"assets/io/fileXML.xml");
				mfile->read();
				mfile->read();
				if (mfile->getAttributeValueAsInt(1) == 0)
					mes.append(
							"\n getAttributeValueAsInt: return 0 when the tag exist");

				//TODO not refer to a nonexistent Attribute
				mfile->getAttributeValueAsInt(25);
				{
					mfile->drop();
					mfile = 0;
				}

				IXMLReader* mfile1 = IFileSystem::createXMLReader(
						"assets/io/fileXMLEmpty1.xml");
				mfile1->read();
				if (mfile1->getAttributeValueAsInt(0) != 0)
					mes.append(
							"\n getAttributeValueAsInt: does not return 0 when the tag does not exist");
				if (mfile1)
				{
					mfile1->drop();
					mfile1 = 0;
				}
				// TODO should not be read without a file name
				IXMLReader* mfile2 = IFileSystem::createXMLReader("");
				mfile2->read();
				if (mfile2->getAttributeValueAsInt(0) != 0)
					mes.append(
							"\n getAttributeValueAsInt: does not return 0 when without a file name");
				if (mfile2)
				{
					mfile2->drop();
					mfile2 = 0;
				}
			}

			void IXMLReaderTest::getAttributeValueAsFloat()
			{
				IXMLReader* mfile = IFileSystem::createXMLReader(
						"assets/io/fileXML.xml");
				mfile->read();
				mfile->read();
				if (mfile->getAttributeValueAsFloat(2) == 0)
					mes.append(
							"\n getAttributeValueAsFloat: return 0 when the tag exist");
				//TODO not refer to a nonexistent Attribute
				mfile->getAttributeValueAsFloat(72);
				if (mfile)
				{
					mfile->drop();
					mfile = 0;
				}

				IXMLReader* mfile1 = IFileSystem::createXMLReader(
						"assets/io/fileXMLEmpty1.xml");
				mfile1->read();
				if (mfile1->getAttributeValueAsFloat(0) != 0)
					mes.append(
							"\n getAttributeValueAsFloat: does not return 0 when the tag does not exist");
				if (mfile1)
				{
					mfile1->drop();
					mfile1 = 0;
				}
				// TODO should not be read without a file name
				IXMLReader* mfile2 = IFileSystem::createXMLReader("");
				mfile2->read();
				if (mfile2->getAttributeValueAsFloat(0) != 0)
					mes.append(
							"\n getAttributeValueAsFloat: does not return 0 when without a file name");
				if (mfile2)
				{
					mfile2->drop();
					mfile2 = 0;
				}
			}

			void IXMLReaderTest::getNodeName()
			{
				IXMLReader* mfile = IFileSystem::createXMLReader(
						"assets/io/fileXML.xml");
				mfile->read();
				mfile->read();
				core::stringc str = core::stringc("recipe");
				if (!str.equalsn(mfile->getNodeName(), 6))
					mes.append("\n getNodeName: correctly returns the name of node");
				if (mfile->getNodeName() == 0)
					mes.append("\n getNodeName: return 0 when the tag exist");
				if (mfile)
				{
					mfile->drop();
					mfile = 0;
				}

				IXMLReader* mfile1 = IFileSystem::createXMLReader(
						"assets/io/fileXMLEmpty1.xml");
				mfile1->read();
				//TODO not refer to a nonexistent node
				mfile1->getNodeName();
				if (mfile1)
				{
					mfile1->drop();
					mfile1 = 0;
				}
				// TODO should not be read without a file name
				IXMLReader* mfile2 = IFileSystem::createXMLReader("");
				mfile2->read();
				if (mfile2->getNodeName() == 0)
					mes.append(
							"\n getNodeName: does not return 0 when without a file name");
				if (mfile2)
				{
					mfile2->drop();
					mfile2 = 0;
				}
			}
			void IXMLReaderTest::getNodeData()
			{
				IXMLReader* mfile = IFileSystem::createXMLReader(
						"assets/io/fileXML.xml");
				mfile->read();
				mfile->read();
				if (mfile->getNodeData() == 0)
					mes.append("\n getNodeData: return 0 when the tag exist");
				if (mfile)
				{
					mfile->drop();
					mfile = 0;
				}

				IXMLReader* mfile1 = IFileSystem::createXMLReader(
						"assets/io/fileXMLEmpty1.xml");

				mfile1->read();
				//TODO not refer to a nonexistent node
				if (mfile1->getNodeData() == 0)
					mes.append(
							"\n getNodeData: does not return 0 when the tag does not exist");
				if (mfile1)
				{
					mfile1->drop();
					mfile1 = 0;
				}
				// TODO should not be read without a file name
				IXMLReader* mfile2 = IFileSystem::createXMLReader("");
				mfile2->read();
				if (mfile2->getNodeData() == 0)
					mes.append(
							"\n getNodeData: does not return 0 when without a file name");
				if (mfile2)
				{
					mfile2->drop();
					mfile2 = 0;
				}
			}
			void IXMLReaderTest::isEmptyElement()
			{
				IXMLReader* mfile = IFileSystem::createXMLReader(
						"assets/io/fileXML.xml");
				mfile->read();
				mfile->read();
				if (mfile->isEmptyElement())
					mes.append(
							"\n isEmptyElement: returns true if the element is not like <foo />");
				mfile->read();
				mfile->read();
				mfile->read();
				if (mfile->isEmptyElement())
					mes.append(
							"\n isEmptyElement: returns false if the element is not like <foo />");
				if (mfile)
				{
					mfile->drop();
					mfile = 0;
				}
			}

		} //end tests namespace
	} //end io namespace
} //end irrgame namespace

/*
 * IXMLReaderTest.h
 *
 *  Created on: Aug 13, 2012
 *      Author: litirvi
 */

#ifndef IXMLREADERTEST_H_
#define IXMLREADERTEST_H_
#include "io/xml/IXMLReader.h"

#include "core/irrString.h"
namespace irrgame
{
	namespace io
	{
		namespace tests
		{
			class IXMLReaderTest
			{
				public:

					// Must define void operator() with no arguments
					void operator()();

					void read();
					void getNodeType();
					void getAttributeCount();
					void getAttributeName();
					void getAttributeValue();
					void getAttributeValueSafe();
					void getAttributeValueAsInt();
					void getAttributeValueAsFloat();
					void getNodeName();
					void getNodeData();
					void isEmptyElement();

				private:
					core::stringc mes;

			};
		} //end tests namespace
	} //end io namespace
} //end irrgame namespace



#endif /* IXMLREADERTEST_H_ */

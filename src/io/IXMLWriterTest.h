/*
 * IXMLWriterTest.h
 *
 *  Created on: Aug 15, 2012
 *      Author: litirvi
 */

#ifndef IXMLWRITERTEST_H_
#define IXMLWRITERTEST_H_
#include "io/xml/IXMLWriter.h"
#include "core/irrString.h"

namespace irrgame
{
	namespace io
	{
		namespace tests
		{
			class IXMLWriterTest
			{
				public:

					// Must define void operator() with no arguments
					void operator()();

					void writeXMLHeader();
					void writeElement();
					void writeComment();
					void writeClosingTag();
					void writeText();
					void writeLineBreak();

				private:
					core::stringc mes;

			};
		} //end tests namespace
	} //end io namespace
} //end irrgame namespace


#endif /* IXMLWRITERTEST_H_ */

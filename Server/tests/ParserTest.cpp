/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ParserTest.cpp
 * Author: Flavien Maillot <fmaillot@webcomputing.fr>
 *
 * Created on 26 nov. 2015, 12:33:31
 */

#include "ParserTest.hh"
#include "../Parser/Parser.hh"


CPPUNIT_TEST_SUITE_REGISTRATION(ParserTest);

ParserTest::ParserTest()
{
}

ParserTest::~ParserTest()
{
}

void ParserTest::setUp()
{
}

void ParserTest::tearDown()
{
}
/*
void ParserTest::testParser()
{
	Parser parser();
	if (true )
	{
		CPPUNIT_ASSERT(false);
	}
}

void ParserTest::testParser2()
{
	const Parser& orig;
	Parser parser(orig);
	if (true )
	{
		CPPUNIT_ASSERT(false);
	}
}*/

void ParserTest::testLoad()
{
	std::string _levelName;
	Parser parser;
	parser.load(_levelName);
	if (true /*check result*/)
	{
		CPPUNIT_ASSERT(false);
	}
}

void ParserTest::testGetLevelName()
{
	Parser parser;
	std::string result = parser.getLevelName();
	if (true /*check result*/)
	{
		CPPUNIT_ASSERT(true);
	}
}


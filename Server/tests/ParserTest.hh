/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ParserTest.hh
 * Author: Flavien Maillot <fmaillot@webcomputing.fr>
 *
 * Created on 26 nov. 2015, 12:33:31
 */

#ifndef PARSERTEST_HH
#define PARSERTEST_HH

#include <cppunit/extensions/HelperMacros.h>

class ParserTest : public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE(ParserTest);

	/*CPPUNIT_TEST(testParser);
	CPPUNIT_TEST(testParser2);*/
	CPPUNIT_TEST(testLoad);
	CPPUNIT_TEST(testGetLevelName);

	CPPUNIT_TEST_SUITE_END();

public:
	ParserTest();
	virtual ~ParserTest();
	void setUp();
	void tearDown();

private:
	/*void testParser();
	void testParser2();*/
	void testLoad();
	void testGetLevelName();

};

#endif /* PARSERTEST_HH */


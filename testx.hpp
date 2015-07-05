#pragma once
#ifndef _TESTX_TESTX_HPP
#define _TESTX_TESTX_HPP



#include <boost/test/unit_test.hpp>
#include <boost/utility.hpp>

#define TESTX_PARAM_TEST_CASE(_name, ...)	\
			void _name (__VA_ARGS__)

#define TESTX_AUTO_TEST_CASE(_name) \
			BOOST_AUTO_TEST_CASE(_name)

#define TESTX_PARAM_TEST(_func, ...)	\
			TESTX_PARAM_TEST_NAMED(_func, BOOST_JOIN(_func, BOOST_JOIN(_in_, __LINE__)), __VA_ARGS__)
#define TESTX_PARAM_TEST_NAMED(_func, _name, ...)	\
			BOOST_AUTO_TEST_CASE(_name)	{ _func(__VA_ARGS__); }

#define TESTX_START_FIXTURE_TEST(_test, ...)	\
			TESTX_START_FIXTURE_TEST_NAMED(BOOST_JOIN(_test, BOOST_JOIN(_in_, __LINE__)), _test, __VA_ARGS__)
#define TESTX_START_FIXTURE_TEST_NAMED(_name, _fixture, ...)								\
			struct BOOST_JOIN(_name, _help_fixture)										\
			{																			\
				typedef _fixture fixture;												\
				BOOST_JOIN(_name, _help_fixture)()										\
				{																		\
					m_fix = new fixture(__VA_ARGS__);									\
				}																		\
																						\
				~BOOST_JOIN(_name, _help_fixture)()										\
				{																		\
					delete m_fix;														\
				}																		\
																						\
				fixture* m_fix;															\
			};																			\
			BOOST_FIXTURE_TEST_SUITE(_name, BOOST_JOIN(_name, _help_fixture))			

#define TESTX_END_FIXTURE_TEST()		\
			BOOST_AUTO_TEST_SUITE_END()

#define TESTX_FIXTURE_TEST(_func, ...)	\
			TESTX_FIXTURE_TEST_NAMED(_func, BOOST_JOIN(_func, BOOST_JOIN(_in_, __LINE__)), __VA_ARGS__);
#define TESTX_FIXTURE_TEST_NAMED(_func, _name, ...)	\
			BOOST_AUTO_TEST_CASE(_name) { m_fix->_func(__VA_ARGS__); }

			


#endif
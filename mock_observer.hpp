#pragma once
#ifndef _TESTX_MOCK_OBSERVER_HPP
#define _TESTX_MOCK_OBSERVER_HPP

#include <boost/lockfree/queue.hpp>
#include <list>
#include <memory>
#include <mutex>

namespace testx {

	template<typename Events>
	class MockObserver
	{
	public:
		struct Inserter
		{
			Inserter(std::shared_ptr<boost::lockfree::queue<Events> > events)
				: events(events)
			{
			}

			Inserter& operator << (const Events& v)
			{
				events->push(v);
				return *this;
			}

		private:
			std::shared_ptr<boost::lockfree::queue<Events> > events;
		};

		MockObserver()
		{
			events = std::make_shared<boost::lockfree::queue<Events> >(0);
		}

		~MockObserver()
		{
			if(events.unique())
			{
				BOOST_CHECK(events->empty());
			}
		}

		MockObserver(const MockObserver& other)
		{
			events = other.events;
		}

		void expect(const Events& v)
		{
			Events q;
			BOOST_REQUIRE(events->pop(q));
			BOOST_CHECK_EQUAL(v, q);
		}

		Inserter set()
		{
			return Inserter(events);
		}
		

	private:
		std::shared_ptr<boost::lockfree::queue<Events> > events;
	};

}

#endif
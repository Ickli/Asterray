#include <vector>
#include <memory>
#include <unordered_set>

#include <EventHandler.hpp>
#include <Event.hpp>

#include <iostream>
void testfunc() {std::cout << "test func has printed this message\n";}

template<typename R, typename ...Args> Event<R, Args...>::Event() {}

template<typename R, typename ...Args> Event<R, Args...>::~Event() {}

template<typename R, typename ...Args> R Event<R, Args...>::invoke(Args... args) {
	return m_handlerProcessor(m_handlers)(args...);
}

template<typename R, typename ...Args> 
void Event<R, Args...>::setHandlerProcessor(Event<R, Args...>::handlerProcessor_t p) {
	m_handlerProcessor = p;
}

template<typename R, typename ...Args> 
void Event<R, Args...>::operator +=(Event<R, Args...>::sharedHandler_t handler) {
	m_handlers.insert(handler);
}


template<typename R, typename ...Args>
//doesn't check if handler is contained
void Event<R, Args...>::operator -=(Event<R, Args...>::sharedHandler_t handler) {
	m_handlers.erase(handler);
}

template class Event<void, int>;
template class Event<int, int>;

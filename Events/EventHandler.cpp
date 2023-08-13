#include <EventHandler.hpp>

template<typename R, typename ...Args>
EventHandler<R, Args...>::EventHandler(EventHandler::function_t f, int id) {
	m_function = f;
	m_id = id;
}

template<typename R, typename ...Args>
EventHandler<R, Args...>::~EventHandler() {}

template<typename R, typename ...Args>
bool EventHandler<R, Args...>::operator ==(EventHandler<R, Args...> other) {
	return this->m_id == other.m_id;
}

template<typename R, typename ...Args>
R EventHandler<R, Args...>::operator()(Args... args) {
	return this->m_function(args...);
}

template class EventHandler<void, int>;
template class EventHandler<int, int>;

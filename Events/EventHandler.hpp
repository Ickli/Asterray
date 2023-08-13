#ifndef ASTERRAY_EVENTHANDLER_HPP_
#define  ASTERRAY_EVENTHANDLER_HPP_

#include <functional>

enum class EventHandlerResult {
	Pass, // handler is successfull or not and doesn't stop other handlers
	Fail, // handler has failed and stops other handlers
	Success, // handler is successfull and stops other handlers
};

// Ideally, handler should always return EventHandlerResult
// but for the sake of polymorphism we emplace generic return type.
template<typename R, typename ... Args>
class EventHandler {
public:
using function_t = std::function<R(Args...)>;
using handler_t = EventHandler<R, Args...>;

	EventHandler(function_t f, int id);
	~EventHandler();

	bool operator ==(handler_t other);

	R operator()(Args... args);

private:
	function_t m_function;
	int m_id;
};

#endif //  ASTERRAY_EVENTHANDLER_HPP_

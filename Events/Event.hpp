#ifndef ASTERRAY_EVENT_HPP
#define ASTERRAY_EVENT_HPP

#include <vector>
#include <memory>
#include <unordered_set>
#include <functional>
#include <type_traits>

#include <EventHandler.hpp>

template<typename R, typename ...Args>
class Event {
public:
using handler_t = typename EventHandler<R, Args...>::handler_t;
using sharedHandler_t = typename std::shared_ptr<handler_t>;
using handlerContainer_t = typename std::unordered_set<sharedHandler_t>;
// (handlers) => (args for handlers) => {}
using handlerProcessor_t = std::function< // outer function
	std::function< // inner function
		R // inner function return type
		(Args...) // inner function args
		>
	(handlerContainer_t&) // outer function args
	>;

	Event();
	~Event();

	R invoke(Args... args);

	void setHandlerProcessor(handlerProcessor_t p);

	void operator +=(sharedHandler_t handler);
	void operator -=(sharedHandler_t handler);
private:
	handlerContainer_t m_handlers;
	handlerProcessor_t m_handlerProcessor = 
		[](handlerContainer_t& cont) { // outer function
			return [&cont](Args... args) { // inner function
				// if R is void, then just iterate over
				if constexpr(std::is_void<R>::value)
					for(auto handler : cont)
						(*handler)(args...);
				else {
					R handlerResult;
					for(auto handler : cont)
						handlerResult = (*handler)(args...);
					return handlerResult;
				}
			}; // inner function end
		}; // outer function end
};

void testfunc();

#endif // ASTERRAY_EVENT_HPP

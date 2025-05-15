#pragma once
#include <functional>

#define EVENT_BIND(Function, Object) std::bind(Function, Object, std::placeholders::_1)
#define EVENT_BIND2(Function, Object) std::bind(Function, Object, std::placeholders::_2)

template<typename EventInfoType>
class Event final
{
	using DelegateType = std::function<void(EventInfoType)>;

	std::vector<DelegateType> _functions;
public:

	void subscribe(DelegateType function);
	void invoke(EventInfoType args);

	void operator+=(DelegateType function);
};

template<typename EventInfoType>
inline void Event<EventInfoType>::subscribe(DelegateType function)
{
	_functions.push_back(function);
}

template<typename EventInfoType>
inline void Event<EventInfoType>::invoke(EventInfoType args)
{
	for (size_t i = 0; i < _functions.size(); i++)
	{
		_functions[i](args);
	}
}

template<typename EventInfoType>
inline void Event<EventInfoType>::operator+=(DelegateType function)
{
	subscribe(function);
}

#include "ts_queue.h"

template<typename T, std::size_t Capacity>
TSQueue<T, Capacity>::TSQueue(const TSQueue::Container& cont) {
	c = cont;
}

template<typename T, std::size_t Capacity>
TSQueue<T, Capacity>::TSQueue(TSQueue::Container&& cont) noexcept {
	c = std::move(cont);
}


template<typename T, std::size_t Capacity>
T& TSQueue<T, Capacity>::front() {
	return c.at(queue->front);
}
template<typename T, std::size_t Capacity>
const T& TSQueue<T, Capacity>::front() const {
	return c.at(queue->front);
}

template<typename T, std::size_t Capacity>
T& TSQueue<T, Capacity>::back() {
	return c.at(queue->back);
}
template<typename T, std::size_t Capacity>
const T& TSQueue<T, Capacity>::back() const {
	return c.at(queue->back);
}

template<typename T, std::size_t Capacity>
bool TSQueue<T, Capacity>::empty() const {
	return !queue.has_value();
}

template<typename T, std::size_t Capacity>
std::size_t TSQueue<T, Capacity>::size() const {
	return queue.has_value() ? (queue->back - queue->front + 1) : 0;
}

template<typename T, std::size_t Capacity>
void TSQueue<T, Capacity>::push(const T& value) {
	if (queue.has_value()) {
		if (queue->back + 1 - queue->front == Capacity)
			throw std::overflow_error("queue is full");
		queue->back++;
		queue->shrink_counters();
		c.at(queue->back) = value;
	} else {
		queue.emplace();
		c.at(queue->back) = value;
	}
}
template<typename T, std::size_t Capacity>
void TSQueue<T, Capacity>::push(T&& value) {
	if (queue.has_value()) {
		if (queue->back + 1 - queue->front == Capacity)
			throw std::overflow_error("queue is full");
		queue->back++;
		queue->shrink_counters();
		c.at(queue->back) = std::move(value);
	} else {
		queue.emplace();
		c.at(queue->back) = std::move(value);
	}
}

template<typename T, std::size_t Capacity>
void TSQueue<T, Capacity>::pop() {
	if (queue.has_value()) {
		queue->front++;
		queue->shrink_counters();
		if (queue->front > queue->back)
			queue.reset();
	}
}


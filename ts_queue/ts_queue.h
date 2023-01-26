#include <array>
#include <optional>
#include <stdexcept>

/// A thread-safe queue.
///
/// @tparam T The type of the elements in the queue.
/// @tparam Capacity The maximum number of elements in the queue.
///
/// @note Use as you would use [`std::queue`].
template<typename T, std::size_t Capacity>
class TSQueue {
private:
	using Container = std::array<T, Capacity>;
	Container c;

	struct QueueState {
		/// Index of the first element in the queue.
		std::size_t front = 0;
		/// Index of the last element in the queue.
		std::size_t back = 0;

		void shrink_counters() {
			while (front >= Capacity && back >= Capacity) {
				front -= Capacity;
				back -= Capacity;
			}
		}
	};
	// No value means empty queue
	std::optional<QueueState> queue;

//	void push_back( const T& value );
//	void push_back( T&& value );
//
//	void pop_front();

public:
	TSQueue() = default;
	explicit TSQueue( const Container& cont );
	explicit TSQueue( Container&& cont ) noexcept;
	TSQueue( const TSQueue& other ) = default;
	TSQueue( TSQueue&& other ) noexcept = default;

	~TSQueue() = default;

	TSQueue& operator=( const TSQueue& other ) = default;
	TSQueue& operator=( TSQueue&& other ) noexcept = default;

	T& front();
	const T& front() const;

	T& back();
	const T& back() const;

	[[nodiscard]] bool empty() const;

	[[nodiscard]] std::size_t size() const;

	void push( const T& value );
	void push( T&& value );

	void pop();

//	template<class... Args>
//	decltype(auto) emplace( Args&&... args );
//
//	void swap( TSQueue& other ) noexcept( std::is_nothrow_swappable_v<Container>);
};

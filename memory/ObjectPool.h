/**
 * ObjectPool.h
 *
 *  Created on: Mar 2, 2013
 *      Author: Jeroen Vlek
 *	     Email: jeroenvlek@gmail.com
 *     Website: www.perceptivebits.com
 *     License: Free Beer (Feel free to use it in every
 *              way possible and if you like it, make
 *				sure to give me credit and buy me a drink
 *              if we ever meet ;) )
 */

#ifndef OBJECTPOOL_H_
#define OBJECTPOOL_H_

#include <cmath>
#include <cstdlib>
#include <new>
#include <queue>
#include <boost/thread/mutex.hpp>

namespace memory {

template<typename T>
class ObjectPool {
public:
	enum GrowthPolicy {

		/**
		 * Add space for one object at a time.
		 */
		INCREMENTAL,

		/**
		 * Add space for log(size) objects.
		 */
		LOG,

		/**
		 * Double the space for objects.
		 */
		DOUBLE
	};

	virtual ~ObjectPool();

	static ObjectPool* Instance();

	/**
	 * Allocates numObjects * sizeof(T) bytes of memory. Previously allocated
	 * memory could be relocated.If the required amount of memory is already
	 * allocated, reserve() does nothing.
	 *
	 * @param numObjects Number of objects of type T this pool should accommodate
	 */
	void reserve(std::size_t numObjects);

	/**
	 * Returns a pointer to a piece of memory that can contain an object of type
	 * T. If the necessary memory is not available, the pool is expanded with
	 * an amount determined by the GrowPolicy that is set.
	 *
	 * @return pointer to a piece of memory in the pool
	 */
	T* acquire();

	/**
	 * Adds the pointer back to the pool so that it can be reused.
	 *
	 * @param toBeReused the object which memory will be reused.
	 */
	void yield(T& toBeReused);

	inline GrowthPolicy getGrowthPolicy() { return m_growthPolicy; }
	inline void setGrowthPolicy(GrowthPolicy growthPolicy) { m_growthPolicy = growthPolicy; }


private:
	ObjectPool();

	/**
	 * Grows the pool by calling reserve(). The new size is based on the set growth
	 * policy. Will always grow with at least 1.
	 */
	void grow();

	/**
	 * Converts an offset to an address.
	 *
	 * @param offset
	 * @return pointer to a piece of memory in the pool
	 */
	inline T* offsetToPtr(std::size_t offset) { return m_data + offset; }

	/**
	 * Converts an address to an offset to be used in the queue.
	 *
	 * @param ptr
	 * @return offset for the queue
	 */
	inline std::size_t ptrToOffset(T* ptr) { return ptr - m_data; }

	static ObjectPool* m_Instance;

	GrowthPolicy m_growthPolicy;
	T* m_data;
	std::size_t m_size;
	std::queue<std::size_t> m_offsetQueue;
	boost::mutex m_mutex;
};

template<typename T>
ObjectPool<T>::ObjectPool()
		: m_growthPolicy(INCREMENTAL), m_data(NULL), m_size(0) {
}

template<typename T>
ObjectPool<T>::~ObjectPool() {
	delete m_data;
}

template<typename T>
ObjectPool<T>* ObjectPool<T>::m_Instance = 0;

template<typename T>
ObjectPool<T>* ObjectPool<T>::Instance() {
	if(ObjectPool<T>::m_Instance == 0) {
		ObjectPool<T>::m_Instance = new ObjectPool<T>();
	}
	return ObjectPool<T>::m_Instance;
}

template<typename T>
void ObjectPool<T>::reserve(std::size_t numObjects) {
	boost::mutex::scoped_lock lock(m_mutex);

	if(numObjects < m_size) {
		return;
	}

	T* data = (T*) std::realloc(m_data, numObjects * sizeof(T));
	if(data == NULL) {
		throw new std::bad_alloc;
	}
	m_data = data;

	for(std::size_t i = m_size; i < numObjects; ++i) {
		m_offsetQueue.push(i);
	}
	m_size = numObjects;
}

template<typename T>
T* ObjectPool<T>::acquire() {
	boost::mutex::scoped_lock lock(m_mutex);

	if(m_offsetQueue.empty()) {
		grow();
	}

	std::size_t offset = m_offsetQueue.front();
	m_offsetQueue.pop();
	T* ptr =  offsetToPtr(offset);
	return ptr;
}

template<typename T>
void ObjectPool<T>::yield(T& toBeReused) {
	boost::mutex::scoped_lock lock(m_mutex);

	std::size_t offset = ptrToOffset(&toBeReused);
	m_offsetQueue.push(offset);
}

template<typename T>
void ObjectPool<T>::grow() {
	std::size_t newSize = 0;
	switch(m_growthPolicy) {
	case INCREMENTAL:
		newSize = m_size + 1;
		break;
	case LOG:
		newSize = m_size + log(m_size);
		break;
	case DOUBLE:
		newSize = m_size * 2;
		break;
	}

	if(newSize == 0) {
		newSize = 1;
	}

	reserve(newSize);
}

} /* namespace memory */
#endif /* OBJECTPOOL_H_ */

/*
 * PoolableObject.h
 *
 *  Created on: Mar 3, 2013
 *      Author: jvlek
 */

#ifndef POOLABLEOBJECT_H_
#define POOLABLEOBJECT_H_

#include <new>

#include "ObjectPool.h"

namespace memory {

template<typename T>
class PoolableObject {
public:
	static void reserve(size_t size) { ObjectPool<T>::Instance()->reserve(size); }
	static void setGrowthPolicy(GrowthPolicy growthPolicy) { ObjectPool<T>::Instance()->setGrowthPolicy(growthPolicy); }
	void* operator new(size_t) { return ObjectPool<T>::Instance()->acquire(); }
	void operator delete(void* toBeReused) { ObjectPool<T>::Instance()->yield((T*) toBeReused); }

protected:
	PoolableObject();
	virtual ~PoolableObject();
};

template<typename T>
PoolableObject<T>::PoolableObject() {
}

template<typename T>
PoolableObject<T>::~PoolableObject() {
}

} /* namespace memory */
#endif /* POOLABLEOBJECT_H_ */

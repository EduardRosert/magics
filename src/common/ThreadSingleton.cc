/******************************** LICENSE ********************************

 Copyright 2007 European Centre for Medium-Range Weather Forecasts (ECMWF)

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at 

    http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.

 ******************************** LICENSE ********************************/

#ifndef marsmachine_H
#include "marsmachine.h"
#endif

#ifndef MagExceptions_H
#include "MagExceptions.h"
#endif

#ifndef ThreadSingleton_H
#include "ThreadSingleton.h"
#endif

template<class T> pthread_once_t ThreadSingleton<T>::once_ = PTHREAD_ONCE_INIT;
template<class T> pthread_key_t ThreadSingleton<T>::key_;

template<class T> ThreadSingleton<T>::ThreadSingleton()
{
}

template<class T> ThreadSingleton<T>::~ThreadSingleton()
{
}

template<class T> 
T& ThreadSingleton<T>::instance()
{
	pthread_once(&once_,init);

	T* value = 0;

#ifdef DCE_THREADS
	THRCALL(pthread_getspecific(key_,(void**)&value));
#else
	value = (T*)pthread_getspecific(key_);
#endif
	if(!value)
	{

		value = new T();
		THRCALL(pthread_setspecific(key_,value));
	}
	return *value;
}

template<class T> void ThreadSingleton<T>::cleanUp(void* data)
{
	delete (T*)data;
	pthread_setspecific(key_,0);
}

template<class T> void ThreadSingleton<T>::init()
{
	pthread_key_create(&key_,cleanUp);
}

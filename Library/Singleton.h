#pragma once
#include <memory>


template<class T>
class Singleton
{
public:
	Singleton() {};
	virtual ~Singleton() {};
	inline static std::shared_ptr<T> GetInstance()
	{
		if (nullptr == Instance)
		{
			Instance = std::shared_ptr<T>(new T);
		}
		return Instance;
	}
private:
	static std::shared_ptr<T> Instance;
};


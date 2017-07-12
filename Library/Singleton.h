#pragma once

template<class T>
class Singleton
{
public:
	Singleton() {};
	virtual ~Singleton() {};
	inline static T* GetInstance()
	{
		if (nullptr == Instance)
		{
			Instance = new T {};
		}
		return Instance;
	}
private:
	static T* Instance;
};


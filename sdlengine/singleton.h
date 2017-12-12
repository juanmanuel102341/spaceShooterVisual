#ifndef SINGLETON_H
#define SINGLETON_H

template <class T>
class Singleton
{
	private:
		static T* instance;

	public:
		static T* getInstance();

		virtual void initialize() = 0;
};

template <class T>
T* Singleton<T>::instance = nullptr;

template <class T>
T* Singleton<T>::getInstance()
{
	if (instance == nullptr)
	{
		instance = new T();
	}

	return instance;
}


#endif //SNGLETON_H
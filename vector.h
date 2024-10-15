

template<typename T>
class Vector{

T *arr;
T cs;
T ms;

public:
	Vector(T maxsize=1){
		cs=0;
		ms=maxsize;
		arr = new T[ms];
	}

	void push_back(T d){
		if(cs==ms)
		{
			T *oldarr= arr;
			ms = 2*ms;
			arr = new T[ms];

			//Copy old elemnts to new double size array
			for(int i=0;i<cs;i++)
			{
				arr[i]=oldarr[i];
			}
			delete [] oldarr;
		}
		arr[cs++]=d;
	}

	void pop_back(){
		if(cs>=0)
			cs--;
	}

	bool isEmpty() const{
		return cs==0;
	}

	T front() const{
		return arr[0];
	}

	T back() const{
		return arr[cs-1];
	}

	T at(const int i) const{
		return arr[i];
	}

	int size()const{
		return cs;
	}

	int capacity() const{
		return ms;
	}

	T operator[](const int i) const{
		return arr[i];
	}

};

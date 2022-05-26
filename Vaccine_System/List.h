template<class T>
class List
{
	T* arr;
	int size, count;
public:
	List();
	int Length(); 
	void Append(T); 
	void Expand(); 
	void Delete();
	~List(void);
};

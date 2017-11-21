#include <iostream>


template<class... T>
void Tree(const T... args){
	template <typename U>
	void foo(U value){
	std::cout << value << std::endl;
};

	template<typename U, typename... Args>
	void foo(U value, Args... arg)
	{
		std::cout << value << std::endl;
		foo(arg...);
	};
	foo(args...);
}

int main(){
	Tree(100,200,300,400,500,600,700,800);
	return 0;
};

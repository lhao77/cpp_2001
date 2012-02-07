#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
class Sum {
	int val;
public:
	Sum(int i) :val(i) { }

	//当在需要int的地方，Sum将自动转换为int类型
	//这里是为了方便cout<<Sum的实例；
	operator int() const { return val; } 

	//写在类中的函数代码一般默认为内联代码
	int operator()(int i) { return val+=i; }
};

void f(vector<int> v)
{
	Sum s = 0; //Sum s = 0等价于Sum s(0),不等价于Sum s;s = 0;

	//对vector<int>中的元素求和
	//函数对象被作为实参传递给泛型算法
	s = for_each(v.begin(), v.end(), s); 

	cout << "the sum is " << s << "\n";

	//更简单的写法，定义独立的函数对象实例
	cout << "the sum is " << for_each(v.begin(), v.end(), Sum(0)) << "\n";
}


int main()
{
	vector<int> v;
	v.push_back(3); v.push_back(2); v.push_back(1);
	f(v);
	system("pause");
	return 0;
}

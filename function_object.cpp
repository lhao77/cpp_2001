#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
class Sum {
	int val;
public:
	Sum(int i) :val(i) { }

	//������Ҫint�ĵط���Sum���Զ�ת��Ϊint����
	//������Ϊ�˷���cout<<Sum��ʵ����
	operator int() const { return val; } 

	//д�����еĺ�������һ��Ĭ��Ϊ��������
	int operator()(int i) { return val+=i; }
};

void f(vector<int> v)
{
	Sum s = 0; //Sum s = 0�ȼ���Sum s(0),���ȼ���Sum s;s = 0;

	//��vector<int>�е�Ԫ�����
	//����������Ϊʵ�δ��ݸ������㷨
	s = for_each(v.begin(), v.end(), s); 

	cout << "the sum is " << s << "\n";

	//���򵥵�д������������ĺ�������ʵ��
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

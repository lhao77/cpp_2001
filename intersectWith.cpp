#include <stdio.h>

template<class T>
class vector2d{
public:
	T x;
	T y;
	T getX() {return x;}
	T getY() {return y;}
	vector2d<T> operator-(const vector2d<T>& vl) const
	{
		vector2d<T> o;
		o.x = x-vl.x;
		o.y = y-vl.y;
		return o;
	}

/*
	vector2d<T> operator*(T t) const
	{
		vector2d<T> o;
		o.x = x*t;
		o.y = x*t;
		return o;
	}
*/

	vector2d<T> operator*(float t) const
	{
		vector2d<T> o;
		o.x = x*t;
		o.y = y*t;
		return o;
	}
};

template<class T>
class line2d
{
public:
	vector2d<T> Start;
	vector2d<T> End;

	line2d<T> operator-(const line2d<T> &ll) const
	{
		line2d<T> o;
		o.Start = Start-ll.Start;
		o.End = End-ll.End;
		return o;
	}
};

template<class T>
bool intersectWith(const line2d<T>& s,const line2d<T>& l, vector2d<T>& out)
{
	/*
	s.End - s.Start;	//s是const对象引用，
						//const对象只能调用本类中的const函数及静态函数，访问数据成员，但不能更改变量（除非该变量用mutable修饰过）。
	*/
    vector2d<T> d0 = s.End - s.Start;
    vector2d<T> d1 = l.Start - l.End;

    // check "parallel" lines
    float det = float(d0.getX() * d1.getY() - d0.getY() * d1.getX());
//    if(det > -ROUNDING_ERROR_32 && det < ROUNDING_ERROR_32)
//    {
//            return false;
//    }
    det = 1.0f / det;

    vector2d<T> d01 = l.Start - s.Start;

    // Check intersection with this line
    float t = float(d01.getX() * d1.getY() - d01.getY() * d1.getX()) * det;
    if(t < 0.0f || t > 1.0f)
    {
            return false;
    }

    // check intersection with other line
    t = float(d0.getX() * d01.getY() - d0.getY() * d01.getX()) * det;
    if(t < 0.0f || t > 1.0f)
    {
            return false;
    }

	printf("---d1==%d==%d\n",d1.x,d1.y);
    out = l.Start - d1*t;			//开始问题一直在这里，因为d1*t，之前一直只有vector2d<T> operator*(T t)，t被转换为了T，也就是int型

	printf("d1==%d==%d\n",d1.x,d1.y);
	printf("t==%f\n",t);
	printf("d1 * T(t) ===%f===%f\n",(d1 * T(t)).x,(d1 * T(t)).y);
    return true;
}

void test();

int main()
{
	test();
}

void test()
{
	vector2d<int> vs,vl;
	vs.x = -177,vs.y= 410, vl.x = 512,vl.y = 600;
	line2d<int> ls;
	ls.Start = vs;ls.End = vl;

	vs.x = 102,vs.y= 76, vl.x = 102,vl.y = 691;
	line2d<int> ll;
	ll.Start = vs;ll.End = vl;

	vector2d<int> out;

	intersectWith(ls,ll,out);

	printf("out.x=%d,out.y=%d\n",out.x,out.y);

}
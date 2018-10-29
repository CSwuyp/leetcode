#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> vec;
	//vec.push_front(3);错误因为vector没有push_front函数,可用下面的函数代替，效果是一样的
	vec.insert(vec.begin(), 1);
	vec.insert(vec.begin(), 2);
	vec.insert(vec.end(), 3);//后插法，跟push_back函数一样的效果
	for (auto it=vec.begin();it!=vec.end();)
	{
		if (*it == 3)
		{
			it=vec.erase(it);//记得删除的时候要重新给迭代器赋值
		}//erase函数返回的是一个指向删除元素后一个元素的指针，而删除了迭代器指向的元素后迭代器会失效，此时需要重新给迭代器赋值
		else
		{
			it++;
		}
	}
	for (auto it : vec)
	{
		cout << it << " ";
	}
    return 0;
}


题目描述
给定一个十进制的正整数number，选择从里面去掉一部分数字，希望保留下来的数字组成的正整数最大。
输入描述:
输入为两行内容，第一行是正整数number，1 ≤ length(number) ≤ 50000。第二行是希望去掉的数字数量cnt 1 ≤ cnt < length(number)。
输出描述:
输出保留下来的结果。
示例1
输入
325 1
输出
35
/*解题思想：要想保留最大的数并不是把整数中最小的数字删除掉而应该是删除该位的数值小于后一位的数，
比如7891删除一位时，我们删除1并不能保留最大的数，而应该是删除7才能保留最大的数，即我们从左到右搜索
删除比后一位小的数*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string number;
	int cnt;
	cin >> number >> cnt;
	int n = number.length();
	for (int i = 1; i<=cnt; i++)
	{
		for (int j = 0; j<n - 1; j++)
		{
			if (number[j]<number[j + 1])
			{
				for (int k = j; k < n - 1; k++)
				{
					number[k] = number[k+1];//把j后面一位的值赋给了j，即删除j的值
				}
				break;//做完赋值则退出循环，查看是否需要再进行删除数字
			}
		}
		number[n - i] = '\0';//如果没有出现前一位数值小于后一位则直接删除最后一位，
		//如果出现了也删除最后一位（实际上最后一位已经是赋值给了倒数第二位，所以此时
		//这样做的原因是为了把字符串长度-1）
	}
	cout << number << endl;
	return 0;
}
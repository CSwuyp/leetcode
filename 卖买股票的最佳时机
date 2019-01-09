1.1 问题描述
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

设计一个算法来计算你所能获取的最大利润，并输出获得最大利润时需要对股票做的卖买操作。你可以尽可能地完成更多的交易（多次买卖一支股票）。

在卖买股票的最佳收益的基础上增加卖买股票的时机，即需要计算在哪一天买入股票和在哪一天卖出股票，如果当天要卖出股票则输出-1，如果当天要买入股票则输出1，如果当天不做任何操作则输出0.

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

1.3.1 样例1
输入: [7,1,5,3,6,4]

输出: 0 1 -1 1 -1 0 

解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
    随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。





#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int temp;
	int flag = 0;//记录卖买情况
	vector<int>price;
	vector<int>vec;
	while (cin >> temp)
	{
		price.push_back(temp);
	}
	price.push_back(0);//主动的往价格表最后一天之后加入一个价格为0的股票价格，这样才能对股票价格做一个for循环判断就可以而不需要再对
	//最后一天的股票进行一次单独的判断，0是最低价格则可以使得递增的股票价格也能在最后一天做卖出操作，如果不是递增则最后一天也能进行判断 
	for (int i = 0; i < price.size()-1; i++)
	{
		if (flag == 0)//还未买入
		{
			if (price[i + 1] > price[i])
			{
				flag = 1;
				vec.push_back(1);
			}
			else
			{
				vec.push_back(0);
			}
		}
		else//已经买入
		{
			if (price[i + 1] > price[i])
			{
				vec.push_back(0);
			}
			else
			{
				vec.push_back(-1);
				flag = 0;
			}
		}
	}
	for (auto it : vec)
	{
		cout << it << " ";
	}
	cout << endl;
	return 0;
}

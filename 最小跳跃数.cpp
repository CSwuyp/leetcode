给定一个非负整数数组，假定你的初始位置为数组第一个下标。 数组中的每个元素代表你在那个位置能够跳跃的最大长度。请确认你是否能够跳跃到数组的最后一个下标。 
例如：A = [2,3,1,1,4]A=[2,3,1,1,4] 能够跳跃到最后一个下标，输出true； 
A = [3,2,1,0,4]A=[3,2,1,0,4] 不能跳跃到最后一个下标，输出false。

输入格式 
第一行输入一个正整数 n (1≤n≤500)，接下来的一行 n 个整数，输入数组 A_i。

输出格式 
如果能跳到最后一个下标，输出true，否则输出false。

样例输入 
5 
2 0 2 0 1

样例输出 
true

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int max=0,count;
    int a[500];
    cin>>count;
    for(int i=0;i<count;i++)
        cin>>a[i];
    for(int i=0;i<count;i++)
    {
        if(i>max)
        {
            cout<<"false";
            return 0;
        }
        if((a[i]+i)>max)
            max=i+a[i];
    }
    cout<<"true";
    return 0;
}

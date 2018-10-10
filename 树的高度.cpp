现在有一棵合法的二叉树，树的节点都是用数字表示，现在给定这棵树上所有的父子关系，求这棵树的高度
输入描述:
输入的第一行表示节点的个数n（1 ≤ n ≤ 1000，节点的编号为0到n-1）组成，
下面是n-1行，每行有两个整数，第一个数表示父节点的编号，第二个数表示子节点的编号
输出描述:
输出树的高度，为一个整数
示例1
输入

5
0 1
0 2
1 3
1 4
输出

3

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n,H = 1;
    int f,c, h;
    vector<int> nodes(1000, 0);    //有效节点的高度
    nodes[0] = 1; // 题目说了至少有一个节点，高度只是是1
    vector<int> childnum(1000, 0); //记录节点的孩子数量
    cin >> n;
    while(--n){
        cin >> f >> c;
        //父节点不存在 或者 父节点已有两个子节点 就跳过
        if(nodes[f]==0 || childnum[f] == 2)
            continue;
        childnum[f] += 1;
        h = nodes[f] + 1;
        nodes[c] = h;
        if(h > H) H = h;
    }
    cout << H;
    return 0;
}

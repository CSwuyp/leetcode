class Solution
{//队列是先进先出，栈是后进先出。这个要实现主要要解决的问题是队列的先进先出并且是可以同时进出数据要用两个栈来实现，
    //我们可以把stack1作为缓存栈，stack2作为输出栈，把队列的数据一直存入入栈stack1直到遇到pop操作后我们可以就可以把数据取出再存到stack2中，
    //然后我们根据pop的数量取出相应数量的数据，取完继续往stack1存入数据，当再次遇到pop操作时若是stack2栈未空则继续取出数据，
    //若是为空则把stack1中的数据存入stack2中
    //其实总的来说就是用两个栈把数据做了两次逆转
public:
    void push(int node) {
        stack1.push(node);//先把数据存入stack1中
    }
    int pop() {
        int temp;
        if(stack2.empty())//如果栈stack2空则把栈stack1中的数据存到stack2中
        {
            while(!stack1.empty())
            {
                //temp=stack1.top();
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
            temp=stack2.top();//如果要把stack1中的数据存到栈stack2时stack2非空则要先把stack2中的数据全部取出后才可以再次存入，
            //不然会使得前面存入的数据在后存入的数据的栈下面的位置，根据栈的存取规则则不能实现队列的存取操作
            stack2.pop();
            return temp;
    }
 
private:
    stack<int> stack1;
    stack<int> stack2;
}

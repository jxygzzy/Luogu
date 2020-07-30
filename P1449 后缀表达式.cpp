/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-07-23 13:11:48
 * @LastEditTime: 2020-07-23 13:42:07
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * 题目描述
 * 所谓后缀表达式是指这样的一个表达式：式中不再引用括号，运算符号放在两个运算对象之后，所有计算按运算符号出现的顺序，
 * 严格地由左而右新进行（不用考虑运算符的优先级）。
 * 如：3*(5–2)+7对应的后缀表达式为：3．5．2．-*7．+@。’@’为表达式的结束符号。‘.’为操作数的结束符号。
 * 输入格式
 * 输入：后缀表达式
 * 输出格式
 * 输出：表达式的值
 * @FilePath: \Luogu\P1449 后缀表达式.cpp
 * @居居 <jxygzzy@163.com>
 */

#include<iostream>
#include<string>
#include<stack>
#include<algorithm>


using namespace std;



int main(){
    stack<int> mystack;
    string str;
    cin>>str;

    int firstnum;  //左侧操作数
    int secondnum; //右侧操作数
    int result;    //结果

    for(int i=0; str[i]!='@'; )
    {
        if(str[i]>='0'&&str[i]<='9'){
            int end = str.find_first_of(".",i);   //从i开始查找"."
            string temp=str.substr(i,end);
            int re=atoi(temp.c_str());
            mystack.push(re);
            i=end+1;
        }
        if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            secondnum = mystack.top();    //取当前栈顶元素，由于栈的先进后出特性，当前栈顶元素其实是二元操作符中右侧的操作数，
            mystack.pop();                //如表达式3-2的后缀表达式为“3 2 -”，这里secondnum取得数就是2
            firstnum = mystack.top();
            mystack.pop();
            if(str[i] == '+')   //做运算，并将结果压入栈中
            {
                result = firstnum + secondnum;
                mystack.push(result);
            }
            if(str[i] == '-')
            {
                result = firstnum - secondnum;
                mystack.push(result);
            }
            if(str[i] == '*')
            {
                result = firstnum * secondnum;
                mystack.push(result);
            }
            if(str[i] == '/')
            {
                result = firstnum / secondnum;
                mystack.push(result);
            }
            i++;
        }

    }
    cout<<mystack.top();
}
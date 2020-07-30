#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

//设置操作符优先级，这里考虑到括号（"("、")"）匹配，定义设置左括号"("的优先级最高，且只有在遇到右括号时才弹出左括号
int priority(const string str)
{
    const char *op = str.c_str(); //生成C字符串数组
    switch (*op)                  //设置优先级
    {
    case ')':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    case '(':
        return 4;
    default:
        return -1;
    }
}

string InfixToPostfi(const string &str)
{
    string operatorstr = "*-/+()^"; //用于string搜索
    string numbers = "0123456789";

    //对输入的中缀表达式中每个元素进行切片，每个元素存储到vector<string>Inputvec
    vector<string> Inputvec; //用向量存储切片结果
    for (size_t i = 0; i < str.size();)
    {
        size_t operatorindex = str.find_first_of(operatorstr, i); //搜索str中从i开始的第一个操作符
        if (operatorindex != string::npos)
        {
            //如果从i开始搜索到了操作符
            if (operatorindex == i)
            {
                Inputvec.push_back(str.substr(operatorindex, 1)); //substr参数：起始字符序号，剪切个数
                i = i + 1;
            }
            else
            {
                //将操作数和操作符都加入向量中
                Inputvec.push_back(str.substr(i, operatorindex - i));
                Inputvec.push_back(str.substr(operatorindex, 1));
                i = operatorindex + 1;
            }
        }
        else
        {
            //如果从i开始搜索不到操作符，即输入的中缀表达式以操作数结尾，不是以操作符结尾
            //（其实一个表达式以操作符结尾的情况只可能是以右括号")"结尾，这里就是为防止这种特殊情况）
            Inputvec.push_back(str.substr(i, str.size() - i));
            i = str.size();
        }
    }

    //遍历切片结果vector中每个元素
    stack<string> operatorstack; //创建空栈，用来存储操作符
    vector<string> PostfiOutvec; //存储中缀输出，这里是存储到vector
    for (size_t i = 0; i < Inputvec.size(); i++)
    {
        //如果当前元素是操作符
        if (Inputvec[i].find_first_of(operatorstr) != string::npos)
        {
            if (operatorstack.empty())
            {
                operatorstack.push(Inputvec[i]); //如果操作符栈空，则直接入栈
            }
            else
            {
                if (Inputvec[i] == ")") //如果当前操作符是右括号
                {
                    while (operatorstack.top() != "(")
                    {
                        PostfiOutvec.push_back(operatorstack.top()); //将栈顶操作符输出
                        operatorstack.pop();                         //删除栈顶元素
                    }
                    operatorstack.pop(); //删除栈顶元素（这里是删除左括号"("）
                }
                else
                {
                    int curpri = priority(Inputvec[i]); //获取操作符的优先级

                    //比较当前操作符与栈顶元素优先级，如果小于或等于栈顶元素优先级则弹出栈顶元素，否则当前操作符入栈
                    while (!operatorstack.empty())
                    {
                        string top = operatorstack.top(); //返回栈顶元素
                        int toppor = priority(top);       //栈顶元素优先级

                        if ((curpri <= toppor) && top != "(") //左括号优先级最大，但是它只有遇到右括号才输出
                        {
                            PostfiOutvec.push_back(top);
                            operatorstack.pop(); //删除栈顶元素
                        }
                        else
                            break;
                    }
                    operatorstack.push(Inputvec[i]);
                }
            }
        }
        //如果当前元素是操作数，直接输出
        else
        {
            PostfiOutvec.push_back(Inputvec[i]);
        }
    }
    while (!operatorstack.empty())
    {
        PostfiOutvec.push_back(operatorstack.top()); //输出操作符栈中的其他操作符
        operatorstack.pop();
    }

    //vector输出为string，作为后缀表达式结果返回
    string result;
    for (size_t i = 0; i < PostfiOutvec.size(); i++)
    {
        result += PostfiOutvec[i];
    }

    return result;
}

double postfixExpression(const string &str)
{
    stack<int> mystack;

    int firstnum;  //左侧操作数
    int secondnum; //右侧操作数
    int result;    //结果

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            int re = str[i] - '0';
            mystack.push(re);
        }
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^')
        {
            secondnum = mystack.top(); //取当前栈顶元素，由于栈的先进后出特性，当前栈顶元素其实是二元操作符中右侧的操作数，
            mystack.pop();             //如表达式3-2的后缀表达式为“3 2 -”，这里secondnum取得数就是2
            firstnum = mystack.top();
            mystack.pop();
            if (str[i] == '+') //做运算，并将结果压入栈中
            {
                result = firstnum + secondnum;
                mystack.push(result);
            }
            if (str[i] == '-')
            {
                result = firstnum - secondnum;
                mystack.push(result);
            }
            if (str[i] == '*')
            {
                result = firstnum * secondnum;
                mystack.push(result);
            }
            if (str[i] == '/')
            {
                result = firstnum / secondnum;
                mystack.push(result);
            }
            if (str[i] == '^')
            {
                result = (int)pow(firstnum, secondnum);
                mystack.push(result);
            }
            stack<int> tempstack;
            while (!mystack.empty())
            {
                tempstack.push(mystack.top());
                mystack.pop();
            }
            while (!tempstack.empty())
            {
                int temp = tempstack.top();
                cout << temp << ' ';
                mystack.push(temp);
                tempstack.pop();
            }
            for (int j = i + 1; j < str.size(); j++)
            {
                cout << str[j] << " ";
            }
            cout << '\n';
        }
    }
    return mystack.top();
}

int main()
{
    string str;
    cin >> str;
    str = InfixToPostfi(str);
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i] << " ";
    }
    cout << '\n';
    postfixExpression(str);
    // cout << postfixExpression(str);
}
#include<iostream>
#include<cstring>
#include<algorithm> 
#include<stack>
#include<vector>
using namespace std;
 
/*********************后缀表达式求值（直接利用C++STL提供的Stack实现）**************************/
double postfixExpression(const string &str)
{
	stack<double> mystack;    //栈空间
 
	string s = ".0123456789+-*/";
	string empty = " ";
	string numbers = ".0123456789";
	string c = "+-*/";
 
	double firstnum;
	double secondnum;
	double sum;
 
	for(unsigned int i=0; i<str.size(); )
	{
		string::size_type start = str.find_first_of(s,i);     //查找第一个数字或算术符号
		string::size_type end = str.find_first_of(empty,i);   //查找第一个空格
		string tempstr = str.substr(start, end-start);     //取出这一个元素
 
		//判断元素
		if(tempstr == "+" || tempstr == "-" || tempstr == "*" || tempstr == "/")
		{
			secondnum = mystack.top();    //取当前栈顶元素，由于栈的先进后出特性，当前栈顶元素其实是二元操作符中右侧的操作数，如表达式3-2的后缀表达式为“3 2 -”，这里secondnum取得数就是2
			mystack.pop();
			firstnum = mystack.top();
			mystack.pop();
			if(tempstr == "+")
			{
				sum = firstnum + secondnum;
				mystack.push(sum);
			}
			if(tempstr == "-")
			{
				sum = firstnum - secondnum;
				mystack.push(sum);
			}
			if(tempstr == "*")
			{
				sum = firstnum * secondnum;
				mystack.push(sum);
			}
			if(tempstr == "/")
			{
				sum = firstnum / secondnum;
				mystack.push(sum);
			}
		}
		else
		{
			double num = stod(tempstr);
			mystack.push(num);
		}
 
		//控制迭代
		i = end + 1;
	}
	return mystack.top();
}
//设置操作符优先级，这里考虑到括号（"("、")"）匹配，定义设置左括号"("的优先级最高，且只有在遇到右括号时才弹出左括号
int priority(const string str)  
{
	const char *op = str.c_str();
    switch(*op)  
    {
    case ')':
        return 0;  
    case '+':  
    case '-':  
        return 1;  
    case '*':  
    case '/':  
        return 2; 
	case '(':
		return 3;
    default :  
        return -1;  
    }  
}  
 
/*********************中缀表达式转为后缀表达式**************************/
string InfixToPostfi(const string &str)
{
	string operatorstr = "*-/+()";      //用于string搜索
	string numbers = "0123456789.";
 
	//对输入的中缀表达式中每个元素进行切片，每个元素存储到vector<string>Inputstr
	vector<string> Inputvec;   //存储切片结果
	for(unsigned int i=0; i<str.size(); )
	{
		string::size_type operatorindex = str.find_first_of(operatorstr,i);     //搜索str中从i开始的第一个操作符
		if(operatorindex != string::npos)
		{
			//如果从i开始搜索到了操作符
			if(operatorindex == i)
			{
				//如果是两个连续的操作符，即这种形式的表达式   a*(b+c)+d;
				string tempstr = str.substr(operatorindex,1);
				Inputvec.push_back(tempstr);
				i = i+1;
			}
			else
			{
				Inputvec.push_back(str.substr(i,operatorindex-i));
				Inputvec.push_back(str.substr(operatorindex,1));
				i = operatorindex+1;
			}
		}
		else
		{
			//如果从i开始搜索到了操作符，即输入的中缀表达式以操作数结尾，不是以操作符结尾（其实一个表达式以操作符结尾的情况只可能是以右括号")"结尾，这里就是为防止这种特殊情况）
			Inputvec.push_back(str.substr(i,str.size()-i));
			i = str.size();
		}
	}
 
	//遍历切片结果vector中每个元素
	stack<string> operatorstack;     //创建空栈，用来存储操作符
	vector<string> PostfiOutvec;     //存储中缀输出，这里是存储到vector
	for(int i=0; i<Inputvec.size(); i++)
	{
		//如果当前元素是操作符
		if(Inputvec[i].find_first_of(operatorstr) != string::npos)
		{
			if(operatorstack.empty())     
			{
				operatorstack.push(Inputvec[i]);      //如果操作符栈空，则直接入栈
			}
			else
			{
				if(Inputvec[i] == ")")     //如果当前操作符是右括号
				{
					while(operatorstack.top() != "(")
					{
						PostfiOutvec.push_back(operatorstack.top());     //将栈顶操作符输出
						operatorstack.pop();    //删除栈顶元素
					}
					operatorstack.pop();    //删除栈顶元素（这里是删除左括号"("）
				}
				else
				{
					int curpri = priority(Inputvec[i]);     //获取操作符的优先级
 
					//比较当前操作符与栈顶元素优先级，如果小于或等于栈顶元素优先级则弹出栈顶元素，否则当前操作符入栈
					while(!operatorstack.empty())
					{
						string top = operatorstack.top();     //返回栈顶元素
						int toppor = priority(top);     //栈顶元素优先级
 
						if((curpri <= toppor) && top!="(")       //左括号优先级最大，但是它只有遇到右括号才输出
						{
							PostfiOutvec.push_back(top);
							operatorstack.pop();    //删除栈顶元素
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
	while(!operatorstack.empty())
	{
		PostfiOutvec.push_back(operatorstack.top());      //输出操作符栈中的其他操作符
		operatorstack.pop();
	}
 
	//在输出中插入空格
	vector<string>::const_iterator itr=PostfiOutvec.begin()+1;
	while(itr!=PostfiOutvec.end())
	{
		itr = PostfiOutvec.insert(itr," ");      //这里一定要返回insert之后的指针，因为改变容器的操作会使迭代器失效
		itr+=2;
	}
	
	PostfiOutvec.push_back(" ");     //添加最后一个空格
 
	//vector输出为string，作为后缀表达式结果返回
	string result;
	for(int i=0; i<PostfiOutvec.size(); i++)
	{
		result.append(PostfiOutvec[i]);
	}
 
	return result;
}
int main()
{
    string test = "3-2";
	string Infixstr1 = "4.99*1.06+5.99+6.99*1.06";      //没有括号
	string Infixstr2 = "4.99*1.06+5.99+(6.99*1.06)";    //中缀表达式以操作符结尾（这种情况只能是以右括号结尾）
	string Infixstr3 = "4.99*(1.06+5.99)+6.99*1.06";    //括号在中间
	string Infixstr4 = "4.99*1.06+5.99+()6.99*1.06";    //插入括号，其内没有表达式
    string ptest = InfixToPostfi(test);
	string Postfistr1 = InfixToPostfi(Infixstr1);
	string Postfistr2 = InfixToPostfi(Infixstr2);
	string Postfistr3 = InfixToPostfi(Infixstr3);
	string Postfistr4 = InfixToPostfi(Infixstr4);
    double res = postfixExpression(ptest);
    cout<<"res="<<res<<endl;
	double res1 = postfixExpression(Postfistr1);
	cout << "res1=" << res1 <<endl;
	double res2 = postfixExpression(Postfistr2);
	cout << "res2=" << res2 <<endl;
	double res3 = postfixExpression(Postfistr3);
	cout << "res3=" << res3 <<endl;
	double res4 = postfixExpression(Postfistr4);
	cout << "res4=" << res4 <<endl;
}
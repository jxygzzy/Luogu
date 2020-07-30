#include <stdio.h>

const int M = 19106206; //学号

int Sum(int arr[][8])
{
    int sum = 0;
    for (int i = 0; i < 8; i++) //双重循环结构遍历数组
    {
        for (int j = 0; j < 8; j++)
        {
            sum += arr[i][j];
        }
    }
    return sum;
}

void Print(int arr[][8])
{
    for (int i = 0; i < 8; i++) //双重循环结构遍历数组
    {
        for (int j = 0; j < 8; j++)
        {
            printf("%10d", arr[i][j]);
        }
        printf("\n");
    }
}

void createA(int arr[][8])
{
    for (int i = 0; i < 8; i++) //双重循环结构遍历数组
    {
        for (int j = 0; j < 8; j++)
        {
            if (i == j) //选择分支结构，对不同下标的元素赋值
            {
                arr[i][j] = M;
            }
            else if (i < j)
            {
                arr[i][j] = i + j;
            }
            else
            {
                arr[i][j] = i * j;
            }
        }
    }
}

int main()
{
    

    int arr[8][8] = {0}; //初始化二维数组
    
    createA(arr);

    printf("二维数组如下：\n");

    Print(arr); //打印数组

    printf("二维数组元素求和结果为："); //打印计算结果
    int sum = Sum(arr);
    printf("%d", sum);
}


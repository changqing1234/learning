#include <iostream>
#include <stdlib.h>
using namespace std;

#define MAXSIZE 20

typedef int SElemType;
typedef struct 
{
    SElemType data[MAXSIZE];
    int top1;//ջ1��ջ��ָ��
    int top2;//ջ2��ջ��ָ��
}SqDoubleStack;

/*��ʼ��ջ1��ջ2*/
bool InitStack(SqDoubleStack *ds)
{
    cout << "Init Stack ..." << endl;
    ds->top1 = -1;
    ds->top2 = MAXSIZE;

    return true;
}

/*��ջ���*/
bool ClearStack(SqDoubleStack *ds)
{
    cout << "Clear Stack ..." << endl;
    ds->top1 = -1;
    ds->top2 = MAXSIZE;

    return true;
}

/*�ж�ջ�Ƿ�Ϊ��*/
bool IsStackEmpty(SqDoubleStack ds)
{
    if(ds.top1 == -1 && ds.top2 == MAXSIZE)
    {
        return true;
    }
    return false;
}
/*����ջ��Ԫ�ظ���*/
int StackLength(SqDoubleStack ds)
{
    cout << "Stack Length: ";
    return (ds.top1 + 1) + (MAXSIZE - ds.top2);
}
/*����Ԫ��eΪ�µ�ջ��Ԫ��*/
bool Push(SqDoubleStack *ds, SElemType e, int stackNumber)
{
    if(ds->top1 + 1 == ds->top2)/*ջ����*/
    {
        return false;
    }

    if(stackNumber == 1)
    {
        ds->data[++ds->top1] = e;
    }
    else if(stackNumber == 2)
    {
        ds->data[--ds->top2] = e;
    }

    return true;
}
/*ɾ��ջ��Ԫ�أ���e������ֵ*/
bool Pop(SqDoubleStack *ds, SElemType *e, int stackNumber)
{
    if(stackNumber == 1)
    {
        if(ds->top1 == -1)
        {
            return false;
        } 
        *e = ds->data[ds->top1--];
    }
    else if(stackNumber == 2)
    {
        if(ds->top2 == MAXSIZE)
        {
            return false;
        }
        *e = ds->data[ds->top2++];
    }
    return true;
}
/*��ȡջ��Ԫ��*/
bool GetTop(SqDoubleStack ds, SElemType *e, int stackNumber)
{
    if(stackNumber == 1)
    {
        if(ds.top1 != -1)
        {
            *e = ds.data[ds.top1];
            cout << "Get Top1 Item: " << *e << endl; 
            return true;
        }
        return false;
    }
    else if(stackNumber == 2)
    {
        if(ds.top2 != MAXSIZE)
        {
            *e = ds.data[ds.top2];
            cout << "Get Top2 Item: " << *e << endl; 
            return true;
        }
        return true;
    }
    else
    {
        cout << "Stack Num must be 1 or 2!" << endl;
        return false;
    }
}//GetToop()
/*��������ջ��һ���������Ԫ��*/
bool StackTraverse(SqDoubleStack ds)
{
    cout << "Traverse Stack ..." << endl;
    if(IsStackEmpty(ds))
    {
        return false;
    }
    cout << "Stack 1: ";
    for(int i = ds.top1; i >= 0; i--)
    {
        cout << ds.data[i] << ' ';
    }
    cout << endl;

    cout << "Stack 2: ";
    for(int j = ds.top2; j < MAXSIZE; j++)
    {
        cout << ds.data[j] << ' ';
    }
    cout << endl;
     
    return true;
}

int  main()
{
    SqDoubleStack ds;
    InitStack(&ds);

    for(int i = 0; i < 5; i++)
    {
        Push(&ds, i, 1);
    }
    for(int j = 5; j < 10; j++)
    {
        Push(&ds, j, 2);
    }

    StackTraverse(ds);

    int result;
    Pop(&ds, &result, 1);
    Pop(&ds, &result, 2);
    StackTraverse(ds);
    GetTop(ds, &result, 1);
    GetTop(ds, &result, 2);
    if (!IsStackEmpty(ds))
    {
        cout << StackLength(ds) << endl;
    }
    ClearStack(&ds);

    system("pause");
}

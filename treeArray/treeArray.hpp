#ifndef __TREEARRAYH__
#define __TREEARRAYH__
#include <iostream>
using namespace std;
template <class T>
class treeArray
{
public:
    treeArray(int theLength = 1000)
    {
        this->arr = new T[theLength + 1];
        this->tree = new T[theLength + 1];
        this->length = theLength;
        arrSize = 0;
    }
    void initilize(T *theArr, int theSzie)
    {
        for (int i = 1; i <= theSzie; ++i)
        {
            this->arr[i] = theArr[i];
            this->tree[i] = theArr[i];
            this->arrSize++;
        }
        for (int i = 1; i <= this->arrSize; ++i)
        {
            int j = i + lowbit(i);
            if (j <= this->arrSize)
                tree[j] += this->tree[i];
        }
    }
    int size() { return this->arrSize; }
    void output()
    {
        for (int i = 1; i <= this->arrSize; ++i)
            cout << tree[i] << " ";
        cout << endl;
    }
    void alter(int theIndex, T theNumber)
    {
        if (theIndex > this->arrSize || theIndex <= 0)
        {
            cout << "invalid index parmeter" << endl;
            return;
        }
        this->arr[theIndex] = theNumber;
        T pervious = this->tree[theIndex];
        this->tree[theIndex] = theNumber;
        int pos = theIndex + lowbit(theIndex);
        while (pos <= this->arrSize)
        {
            this->tree[pos] -= pervious;
            this->tree[pos] += theNumber;
            pos += lowbit(pos);
        }
    }
    T intervalQuery(int theLeft, int theRight)
    {
        T ans1 = T();
        T ans2 = T();
        theLeft--;
        while (theLeft > 0)
        {
            ans1 += this->tree[theLeft];
            theLeft -= lowbit(theLeft);
        }
        while (theRight > 0)
        {
            ans2 += this->tree[theRight];
            theRight -= lowbit(theRight);
        }
        return ans2 - ans1;
    }
    void intervalAlter(int theLeft, int theRight, const T &theNunm)
    {
        for (int i = theLeft; i <= theNunm; ++i)
            this->alter(i, theNunm);
    }
    ~treeArray()
    {
        if(this->arr != nullptr)
            delete[] arr;
        if(this->tree != nullptr)
            delete[] tree;
        arr = tree = nullptr;
    }
private:
    T *arr;
    T *tree;
    int length;
    int arrSize;
    int lowbit(int x)
    {
        return x & (-x);
    }
};
#endif
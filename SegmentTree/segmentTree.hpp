#ifndef __SEGMENTTREE__
#define __SEGMENTTREE__
#include <iostream>
template <class T>
class segmentTree
{
private:
    T *larr;
    T *arr;
    T *lazyMark;
    int treeSize;
    int arrSize;

public:
    segmentTree();
    ~segmentTree();
    void initialize(T *tArr, int l, int r);
    void build(int l, int r, int p); // 可以递归建立线段树
    void alter(int theNode, int theNum)
    {
        this->alter(1, this->arrSize, theNode, theNum);
    }
    void intervalAlter(int left, int right, int theNum)
    {
        this->intervalAlter(1, this->arrSize, left, right, theNum);
    }

    T intervalQuery(int left, int right)
    {
        return this->intervalQuery(1, this->arrSize, left, right);
    }
    int size() { return this->treeSize; }
    void outputTree()
    {
        for (int i = 1; i <= this->treeSize; ++i)
            std::cout << this->larr[i] << " ";
        std::cout << std::endl;
    }
    void outputArr()
    {
        for (int i = 1; i <= this->arrSize; ++i)
            std::cout << this->arr[i] << " ";
        std::cout << std::endl;
    }
    void outputLazy()
    {
        for (int i = 1; i <= this->treeSize; ++i)
            std::cout << this->lazyMark[i] << " ";
        std::cout << std::endl;
    }

private:
    void alter(int l, int r, int theNode, int theNum, int p = 1);       // 递归查询，并更改
    void intervalAlter(int l, int r, int tl, int tr, int C, int p = 1); // C为要更改的数
    T intervalQuery(int l, int r, int ql, int qr, int p = 1);
    void putDown(int p, int rn, int ln); // 将当前区间的lazy标记消去，并将该标记传递至p的子节点
};
template <class T>
segmentTree<T>::segmentTree()
{
    this->larr = nullptr;
    this->lazyMark = nullptr;
    this->arr = nullptr;
    this->treeSize = 0;
    this->arrSize = 0;
}
template <class T>
segmentTree<T>::~segmentTree()
{
    if (this->larr != nullptr)
        delete[] this->larr;
    if (this->lazyMark != nullptr)
        delete[] this->lazyMark;
    if (this->arr != nullptr)
        delete[] this->arr;
}
template <class T>
void segmentTree<T>::initialize(T *tArr, int l, int r)
{
    int cap = (r - l + 1) << 2;
    this->larr = new T[cap + 1];
    this->arr = new T[r - l + 10];
    this->lazyMark = new T[cap + 1];
    int cnt = 1;
    for (int i = l; i <= r; ++i, ++cnt)
    {
        this->arr[cnt] = tArr[i];
        ++this->arrSize;
    }
    build(1, this->arrSize, 1);
}
template <class T>
void segmentTree<T>::build(int l, int r, int p)
{
    if (l == r)
    {
        this->larr[p] = arr[l];
        this->lazyMark[p] = 0;
        ++this->treeSize;
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, 2 * p);
    build(mid + 1, r, 2 * p + 1);
    this->larr[p] = this->larr[2 * p] + this->larr[2 * p + 1];
    ++this->treeSize;
    this->lazyMark[p] = T();
}
template <class T>
void segmentTree<T>::alter(int l, int r, int theNode, int theNum, int p)
{
    if (l == r) // 到达叶子结点
    {
        this->larr[p] = theNum;
        this->arr[l] = theNum;
        return;
    }
    int mid = (l + r) >> 1;
    if (theNode >= l && theNode <= mid)
        alter(l, mid, theNode, theNum, 2 * p);
    if (theNode <= r && theNode >= mid + 1)
        alter(mid + 1, r, theNode, theNum, 2 * p + 1);
    this->larr[p] = this->larr[2 * p] + this->larr[2 * p + 1];
}
template <class T>
void segmentTree<T>::putDown(int p, int rn, int ln)
{
    if (lazyMark[p] != 0)
    {
        // std::cout << "---------" << std::endl;
        // std::cout<<"p = "<< p <<std::endl;
        int lazy = this->lazyMark[p];
        this->larr[2 * p] += lazy * ln; // 将两个子节点维护的区间信息从新赋值
        this->larr[2 * p + 1] += lazy * rn;
        this->lazyMark[2 * p] += lazy; // 标记下推
        this->lazyMark[2 * p + 1] += lazy;
        this->lazyMark[p] = 0; // 消除标记
    }
}
template <class T>
void segmentTree<T>::intervalAlter(int l, int r, int tl, int tr, int C, int p)
{
    // std::cout << "l = " << l << " r = " << r << " p = " << p << std::endl;
    if (l >= tl && r <= tr) // 当前区间被完全覆盖
    {
        this->larr[p] += C * (r - l + 1);
        this->lazyMark[p] += C;
        return;
    }
    int mid = (l + r) >> 1;
    putDown(p, r - mid, mid - l + 1); // 将当前节点的lazy标记向子节点下移
    if (mid >= tl && l <= tr)         // 与左子区间有交集
        intervalAlter(l, mid, tl, tr, C, 2 * p);
    if (r >= tl && tr >= mid + 1) // 与右子区间有交集
        intervalAlter(mid + 1, r, tl, tr, C, 2 * p + 1);
    this->larr[p] = this->larr[2 * p] + this->larr[2 * p + 1];
}
template <class T>
T segmentTree<T>::intervalQuery(int l, int r, int ql, int qr, int p)
{
    // std::cout << "l = " << l << " r = " << r << " p = " << p << std::endl;
    if (l >= ql && r <= qr)
    {
        // std::cout << "ans = " << larr[p] << std::endl;
        return this->larr[p];
    }

    int mid = (l + r) >> 1;
    putDown(p, r - mid, mid - l + 1);
    T result1 = T();
    T result2 = T();
    if (ql <= mid && qr >= l)
        result1 = intervalQuery(l, mid, ql, qr, 2 * p);
    // std::cout << "lres = " << result1 << std::endl;
    if (r >= ql && (mid + 1) <= qr)
        result2 = intervalQuery(mid + 1, r, ql, qr, 2 * p + 1);
    // std::cout << "rres = " << result2 << std::endl;
    return result1 + result2;
}
#endif
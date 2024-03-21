// #include <iostream>
// #include <vector>
// #include <stack>
// using namespace std;
// int n;
// const int N = 21;
// int arr[2][N];
// int _arr[2][N] = {0};
// int Graph[22][22] = {0};
// void print(int (*Graph)[22])
// {
//     cout << "Graph:" << endl;
//     for (int i = 0; i <= n + 1; ++i)
//     {
//         for (int j = 0; j <= n + 1; ++j)
//             cout << Graph[i][j] << " ";
//         cout << endl;
//     }
// }
// void print(int *a)
// {
//     for (int i = 0; i < n; ++i)
//         cout << a[i] << " ";
//     cout << endl;
// }
// void pMove(int &i, int &j, int a)
// {
//     if (a == 0)
//         i--;
//     else if (a == 1)
//         j++;
//     else if (a == 2)
//         i++;
//     else if (a == 3)
//         j--;
// }
// void pRmove(int &i, int &j, int a)
// {
//     if (a == 0 || a == 2)
//         pMove(i, j, 2 - a);
//     if (a == 1 || a == 3)
//         pMove(i, j, 4 - a);
// }
// void point(int &i, int &j, int p)
// {
//     i = p / n + 1;
//     j = p % n + 1;
// }
// void setArr(int (*_arr)[N], int row, int col, int select)
// {
//     // cout << "row = " << row << "  col = " << col << endl;
//     _arr[0][col - 1]++;
//     _arr[1][row - 1]++;
// }
// void rSetArr(int (*_arr)[N], int row, int col, int select)
// {
//     // cout << "row = " << row << "  col = " << col << endl;
//     _arr[1][row - 1]--;
//     _arr[0][col - 1]--;
// }
// bool isEnd(int row, int col, int select)
// {
//     pMove(row, col, select);
//     int a = _arr[0][col - 1];
//     int b = _arr[1][row - 1];
//     a++;
//     b++;
//     // print(_arr[0]);
//     // print(_arr[1]);
//     // cout << "a = " << a << "  b = " << b << endl;
//     if (a > arr[0][col - 1] || b > arr[1][row - 1])
//         return false;
//     return true;
// }
// bool judge(int (*_arr)[N]);
// void utiliF(int *p, int count);
// int cPos(int i, int j)
// {
//     return (i - 1) * n + j - 1;
// }
// int main()
// {
//     cin >> n;
//     for (int i = 0; i <= n + 1; i++)
//     {
//         if (i == 0 || i == n + 1)
//             for (int j = 0; j <= n + 1; j++)
//                 Graph[i][j] = 1;
//         else
//             Graph[i][n + 1] = Graph[i][0] = 1;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         int num;
//         cin >> num;
//         arr[0][i] = num;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         int num;
//         cin >> num;
//         arr[1][i] = num;
//     }
//     int count = 1;
//     int path[N * N - 1] = {0};
//     path[0] = 0;
//     int select = 0;
//     int row = 1;
//     int col = 1;
//     Graph[1][1] = 1;
//     _arr[0][0] = 1;
//     _arr[1][0] = 1;
//     stack<int> _stack;
//     while (count != 0)
//     {
//         // print(Graph);
//         // cout << "row = " << row << "  col = " << col << endl;
//         // cout << "select = " << select << endl;
//         if (select < 4)
//         {
//             int tRow = row;
//             int tCol = col;
//             pMove(tRow, tCol, select); // 试探select是否可行

//             if (Graph[tRow][tCol] != 1 && isEnd(row, col, select)) // select可行
//             {
//                 pMove(row, col, select);
//                 setArr(_arr, row, col, select);
//                 // print(_arr[0]);
//                 // print(_arr[1]);
//                 Graph[row][col] = 1;
//                 _stack.push(select);
//                 path[count] = cPos(row, col);
//                 select = 0;
//                 count++;
//                 // 移动之后可能会达到终点
//                 if (row == n && col == n)
//                 {
//                     if (judge(_arr))
//                     {
//                         utiliF(path, count);
//                         break;
//                     }
//                     select = _stack.top();
//                     _stack.pop();
//                     Graph[row][col] = 0;
//                     _arr[1][row - 1]--;
//                     _arr[0][col - 1]--;
//                     pRmove(row, col, select);
//                     select++;
//                     count--;
//                 }
//             }
//             else // select不可行
//                 select++;
//         }
//         if (select == 4) // 上一个点的选择完成
//         {
//             if (_stack.empty())
//                 break;
//             select = _stack.top();
//             _stack.pop();
//             Graph[row][col] = 0;
//             rSetArr(_arr, row, col, select);
//             // print(_arr[0]);
//             // print(_arr[1]);
//             pRmove(row, col, select);
//             // cout << "rRow = " << row << "  rCol = " << col << endl;
//             count--;
//             select++;
//         }
//     }
//     return 0;
// }
// bool judge(int (*_arr)[N])
// {
//     for (int i = 0; i < N; ++i)
//     {
//         if (_arr[0][i] != arr[0][i] || _arr[1][i] != arr[1][i])
//             return false;
//     }
//     return true;
// }
// void utiliF(int *p, int count)
// {
//     for (int i = 0; i < count; i++)
//         cout << p[i] << " ";
//     cout << endl;
// }
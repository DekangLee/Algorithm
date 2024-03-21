
// #include <iostream>
// using namespace std;
// #include <vector>
// #include <stack>
// int _and(int a, int b)
// {
//     if (a == 1 && b == 1)
//         return 1;
//     else
//         return 0;
// }
// int _or(int a, int b)
// {
//     if (a == 1 || b == 1)
//         return 1;
//     else
//         return 0;
// }
// int _ox(int a, int b)
// {
//     if (a == b)
//         return 0;
//     else
//         return 1;
// }
// int ijadd(int &i, int &j)
// {
//     if (j < 3 - i)
//         j++;
//     else
//     {
//         i++;
//         j = 0;
//     }
//     int count = 0;
//     for (int row = 0; row < i; row++)
//     {
//         count += 4 - row;
//     }
//     return count + j + 1;
// }
// int ijsub(int &i, int &j)
// {
//     if (j == 0)
//     {
//         i--;
//         j = 3 - i;
//     }
//     else
//         j--;
//     int count = 0;
//     for (int row = 0; row < i; row++)
//     {
//         count += 4 - row;
//     }
//     return count + j + 1;
// }
// int _Array[5][5];
// int (*_a[5][5])(int, int) = {nullptr};
// int (*_c[3])(int, int) = {_and, _or, _ox};
// int out(int _A[5][5], int (*_a[5][5])(int, int))
// {
//     for (int i = 0; i < 4; i++)
//     {
//         // cout << "i = " << i << endl;
//         for (int j = 0; j < 4 - i; j++)
//         {
//             // cout << "j = " << j << endl;
//             // cout << "_A[i][j] = " << _A[i][j] << " _A[i][j + 1] = " << _A[i][j + 1] << endl;
//             // if (_a[i][j] == nullptr)
//             //     cout << "nullptr" << endl;
//             _A[i + 1][j] = _a[i][j](_A[i][j], _A[i][j + 1]);
//             // cout << "--------" << endl;
//         }
//     }
//     // cout << "_A[4][0] = " << _A[4][0] << endl;
//     return _A[4][0];
// }
// void resetR(bool reach[3])
// {
//     for (int i = 0; i < 3; ++i)
//         reach[i] = false;
// }
// int main()
// {
//     _Array[0][0] = 1;
//     _Array[0][1] = 0;
//     _Array[0][2] = 1;
//     _Array[0][3] = 0;
//     _Array[0][4] = 1;
//     int count = 1;
//     bool reach[11][3] = {false};
//     int row = 0;
//     int col = 0;
//     int res = 0;
//     do
//     {
//         bool flag = true;
//         // cout << "count = " << count << endl;
//         // cout << "row = " << row << "  col = " << col << endl;
//         for (int i = 0; i < 3; i++)
//         {
//             // cout << "i = " << i << endl;
//             if (!reach[count][i])
//             {
//                 _a[row][col] = _c[i];
//                 reach[count][i] = true;
//                 flag = false;
//                 count = ijadd(row, col);
//                 if (count == 11)
//                 {
//                     // cout << "Tcount = " << count << endl;
//                     if (out(_Array, _a) == 1)
//                         res++;
//                     count = ijsub(row,col);
//                     flag = false;
//                 }

//                 break;
//             }
//         }
//         if (flag) // 回溯代码段
//         {
//             // cout << "------------" << endl;
//             resetR(reach[count]);
//             count = ijsub(row, col);
//             // cout << "------------" << endl;
//         }
//     } while (count != 0);
//     cout << res;
//     return 0;
// }
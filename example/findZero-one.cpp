// // 给定仅含有01的数组，查找数组的最大长度使01个数相等
// #include <iostream>
// using namespace std;
// #include <time.h>
// #include <vector>
// #include <map>
// template <class T>
// void print(T *arr, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }
// template <class T>
// void print(vector<T> &v)
// {
//     for (auto elem : v)
//     {
//         cout << elem << " ";
//     }
//     cout << endl;
// }
// // void find()
// // {
// //     int length;
// //     int count0 = 0;
// //     int count1 = 0;
// //     cin >> length;
// //     int *arr = new int[length];
// //     srand(time(0));
// //     for (int i = 0; i < length; i++)
// //     {
// //         int num = rand() % 2;
// //         if (num == 0)
// //             count0++;
// //         else
// //             count1++;
// //         arr[i] = num;
// //     }
// //     print(arr, length);
// //     cout << "count0 = " << count0 << endl;
// //     cout << "count1 = " << count1 << endl;
// //     int i = 0;
// //     int j = length - 1;
// //     while (count0 != count1 && i <= j)
// //     {
// //         if (count0 > count1)
// //         {
// //             if (arr[i] == 0)
// //             {
// //                 i++;
// //                 count0--;
// //             }
// //             else if (arr[j] == 0)
// //             {
// //                 j--;
// //                 count0--;
// //             }
// //             else
// //             {
// //                 i++;
// //                 count1--;
// //             }
// //         }
// //         if (count1 > count0)
// //         {
// //             if (arr[i] == 1)
// //             {
// //                 i++;
// //                 count1--;
// //             }
// //             else if (arr[j] == 1)
// //             {
// //                 j--;
// //                 count1--;
// //             }
// //             else
// //             {
// //                 i++;
// //                 count0--;
// //             }
// //         }
// //     }
// //     cout << "length = " << j - i + 1 << endl;
// //     cout << "i = " << i << endl;
// //     cout << "j = " << j << endl;
// // }
// class Solution
// {
// public:
//     int findMaxLength(vector<int> &nums)
//     {
//         map<int, int> Cur_Pos;
//         int index = 0;
//         Cur_Pos[0] = -1;
//         int cur = 0;
//         int ans = 0;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (nums[i] == 0)
//                 cur += -1;
//             else
//                 cur += 1;
//             if (Cur_Pos.count(cur) == 0)
//             {
//                 Cur_Pos[cur] = i;
//             }
//             else
//             {
//                 int temp = Cur_Pos[cur];
//                 ans = max(i - temp, ans);
//             }
           
//             // cout << "cur = " << cur << endl;
//             // cout << "ans = " << ans << endl;
//         }
//         return ans;
//     }
// };
// void test01()
// {
//     int length;
//     cin >> length;
//     vector<int> nums;
//     srand(time(0));
//     for (int i = 0; i < length; i++)
//     {
//         int num = rand() % 2;
//         // cin >> num;
//         nums.push_back(num);
//     }
//     print(nums);
//     Solution s;
//     cout << s.findMaxLength(nums) << endl;
//     ;
// }
// int main()
// {
//     // find();
//     test01();
//     system("pause");
//     return 0;
// }
// #include <iostream>
// using namespace std;
// #include <ctime>
// template <class T>
// void print(T *array, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         cout << array[i] << " ";
//     }
//     cout << endl;
// }
// template <class T>
// void Fisher_Yates_Shuffle(T *element, int n)
// {
//     T *newElement = new T[n];
//     int *index = new int[n];
//     for (int i = 0; i < n; i++)
//     {
//         index[i] = i;
//     }

//     int rest = n;
//     srand(time(0));
//     for (int i = 0; i < n; i++)
//     {
//         int select = rand() % rest;
//         // cout << "select = " << select << endl;
//         int trueInedx;
//         for (int j = 0; j < n; j++)
//         {
//             if (select == index[j])
//             {
//                 trueInedx = j;
//                 index[j] = -1;
//             }
//             else if (select < index[j])
//             {
//                 index[j]--;
//             }
//         }
//         // cout << "trueIndex = " << trueInedx << endl;
//         rest--;
//         newElement[i] = element[trueInedx];
//         // cout << "index:";
//         // print(index, n);
//     }
//     for (int i = 0; i < n; i++)
//     {
//         element[i] = newElement[i];
//     }
//     delete[] newElement;
// }
// void test01()
// {
//     int *arr = new int[10];
//     srand(time(0));
//     for (int i = 0; i < 10; i++)
//     {
//         arr[i] = i + 1;
//     }
//     print(arr, 10);
//     Fisher_Yates_Shuffle(arr, 10);
//     print(arr, 10);
// }
// int main()
// {
//     test01();
//     system("pause");
//     return 0;
// }
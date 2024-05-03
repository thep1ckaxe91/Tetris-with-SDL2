// #include <bits/stdc++.h>
// using namespace std;
// // int a[];

// // int A[3]={1,2,3,4};
// // int a[]={1,2,3,4};

// // char a[];
// // char a[4]="abcd";
// // char a[]="abcd";
// // char daytab[][12] = {
// //   {31,28,31,30,31,30,31,31,30,31,30,31},
// //   {31,29,31,30,31,30,31,31,30,31,30,31}
// // };
// // char daytab[2][] = {
// //   31,28,31,30,31,30,31,31,30,31,30,31,
// //   31,29,31,30,31,30,30,31,30,31
// // };

// int main()
// {
//     // char a[];
//     // int a[];
//     // int A[N]={1,2,3,4};
//     // int a[]={1,2,3,4};
//     // char a[]="abcd";

//     // char a[2]="abcd";
//     // for(int i=0;i<4;i++) cout << a[i] << " ";
//     // for(int i=0;i<4;i++) cout << A[i] << " ";

//     // cout << sizeof(a);
//     // cout << a[-1];
//     // for(int i=0;i<2;i++){
//     //     for(int j=0;j<12;j++)
//     //     {
//     //         cout << daytab[i][j] << ' ';
//     //     }
//     //     cout<<endl;
//     // }
//     // cout << daytab[1][-1];

// }
// #include <iostream>

// using namespace std;

// int main() {
//   const int N = 10;
//   char str[N + 1];
//   cin.getline(str, N);
//   str[N] = '\0';
//   cout << "_" << str << "_" << endl;
//   return 0;
// }

// #include <iostream>
// #include <cstdlib>
// #include <ctime> 

// using namespace std;

// const int N = 30; 

// int main()
// {
//     srand(time(NULL)); 
//     int arr[N];
//     for (int i = 0; i < N; ++i)
//     {
//         arr[i] = rand() % 100 + 1;
//     }

//     for (int i = 0; i < N; ++i)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//     for (int i = N - 1; i >= 0; --i)
//     {
//         for (int j = 0; j < i; ++j)
//         {
//             if (arr[j] > arr[j + 1])
//             {
//                 swap(arr[j], arr[j + 1]);
//             }
//         }
//     }

//     for (int i = 0; i < N; ++i)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }



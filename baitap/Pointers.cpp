#include <bits/stdc++.h>
using namespace std;

// void f(int a[])
// {
//     cout << sizeof(a) << endl;
// }

int count_even(int *a, int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
        cnt += a[i] % 2 == 0;
    return cnt;
}
int bs(int *a, int n, int val)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (a[mid] == val)
            return mid;
        if (a[mid] > val)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}
// char *weird_string()
// {
//     char c[] = "123345";
//     return c;
// }
// void swap_pointers(char *&x, char *&y)
// {
//     char *tmp;
//     tmp = x;
//     x = y;
//     y = tmp;
// }

int main(int argc, char *argv[])
{
    // cout << argv[1];
    // int a[10]={1,2,3,4,6,7,8,9,11,12};
    // cout << sizeof(a) << endl;
    // f(a);
    // cout<<count_even(a,5)<<endl;
    // cout<<count_even(a+5,5)<<endl;

    // cout << bs(a,10,6) << endl;
    // cout << bs(a,10,5) << endl;
    // strcmp
    // if (argc != 3)
    // {
    // return 1;
    // }

    // char *s1 = argv[1];
    // char *s2 = argv[2];

    // int count = 0;
    // for (int i = 0; s2[i] != '\0'; i++)
    // {
    //     if (strcmp(s1, &s2[i]) == 0)
    //     {
    //         count++;
    //     }
    // }

    // cout << count << endl;

    // char a[] = "I should print second";
    // char b[] = "I should print first";

    // char *s1 = a;
    // char *s2 = b;
    // swap_pointers(s1, s2);
    // cout << "s1 is " << s1 << endl;
    // cout << "s2 is " << s2 << endl;

    //Sua loi

    char **s = new (char *); // s is not init (allocate mem)
    char foo[] = "Hello World";
    *s = foo;
    printf("s is %s\n", *s); // access the value of the pointer s, which is the address of foo
    s[0] = foo; // pointer to pointer, so this is ok
    printf("s[0] is %s\n", s[0]);

    return 0;
}
/*


*/
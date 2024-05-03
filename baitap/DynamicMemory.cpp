#include <bits/stdc++.h>
using namespace std;

char *concat(const char *left, const char *right)
{
    int n = strlen(left);
    int m = strlen(right);
    char *res = (char *)calloc(n + m + 1, sizeof(char));
    for (int i = 0; i < n; i++)
    {
        res[i] = left[i];
    }
    for (int i = n; i < n + m; i++)
    {
        res[i] = right[i - n];
    }
    return res;
}

int main()
{
    // char a[]="Hello ";
    // char b[]="World";
    // char *ab = concat(a,b);
    // printf("%s",ab);
    // free(ab);

    // int *p = new int; //0x123
    // int *p2 = p; //p2 = 0x123
    // *p = 10; // *0x123 = 10
    // delete p; // 0x123 is free
    // *p2 = 100; //???? acess freed mem
    // cout << *p2;
    // delete p2; // free the memory that already freed

    // char *a = new char[10];
    // char *c = a + 3;
    // for (int i = 0; i < 9; i++)
    //     a[i] = 'a';
    // a[9] = '\0';
    // cerr << "a: " << "-" << a << "-" << endl;
    // cerr << "c: " << "-" << c << "-" << endl;
    // delete c; // c have no right to delete like this, since a is controlling the entire 10 bytes by using new
    // use delete on c make the program cause undefined behaviour
    // cerr << "a after deleting c:" << "-" << a << "-" << endl;

    //?? BT08 where
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+2;
/*
 * Complete the 'beautifulStrings' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts STRING s as parameter.
 */

long beautifulStrings(string &s) {
    ll res=0;
    int cnt=0;
    int minus=0;
    int n=s.size();
    s+="    ";
    for(int i=0;i<n;i++)
    {
        res+=s[i]!=s[i+1];
        cnt+=(s[i]==s[i+1] and s[i]!=s[i+2]);
        minus+=(s[i]==s[i+2] and s[i]!=s[i+1]);
    }
    return res*(res-1)/2+cnt-minus;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    
    string s;
    getline(cin, s);

    long result = beautifulStrings(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

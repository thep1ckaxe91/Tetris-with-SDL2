#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
long long res=0;
int a[N];
signed main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		res+=a[i-1];
		a[i]+=a[i-1];
	}
	cout<<res;
}
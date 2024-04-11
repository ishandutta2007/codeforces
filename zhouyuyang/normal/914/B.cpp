#include<bits/stdc++.h>
using namespace std;
int n,a[1000000],d,z[1000000],ff;
signed main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++){if (a[i]!=a[i-1])d++;z[d]++;}
	for (int i=1;i<=d;i++)ff|=z[i]&1;
	if (!ff)puts("Agasa");else puts("Conan");
}
#include<bits/stdc++.h>
using namespace std;
int n, a[22];
int main(){
	cin>>n;
	for (int i=1;i<=n;++i){
		cin>>a[i];
		if (i>1&&abs(a[i]-a[i-1])>=2) return puts("NO"), 0; 
	}
	puts("YES");
}
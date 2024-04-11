#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
	int n;
	static int a[123456];
	cin>>n;
	rep(i,n){
		scanf("%d",a+i);
		while(a[i]%2==0)a[i]/=2;
		while(a[i]%3==0)a[i]/=3;
	}
	sort(a,a+n);
	puts(a[0]==a[n-1]?"Yes":"No");
}
#include<bits/stdc++.h>
using namespace std;
int a[10010],n;
bool chk(int N){
	for(int i=1;i<N;++i)if(abs(a[i]-a[i+1])>=2)return false;
	return true;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i){
		if(!chk(n-i+1))return puts("NO"),0;
		int mx=0,id=0;
		for(int j=1;j<=n-i+1;++j)if(a[j]>mx)mx=a[id=j];
		for(int j=id+1;j<=n;++j)a[j-1]=a[j];
	}
	puts("YES");
}
#include<bits/stdc++.h>
const int N=2e5+5;
int T,n,i;
char d[N],ans[N];
inline bool check(int z){
	int j,mx=0,mn=N,lst=0;
	for(j=1;j<=n;++j)if(d[j]<z){
		if(mx && d[mx]>d[j])return 0;
		mx=j;ans[j]='1';
	}else if(z<d[j]){
		if(lst && d[lst]>d[j])return 0;
		lst=j;if(mn==N)mn=j;ans[j]='2';
	}
	for(j=1;j<=n;++j)if(d[j]==z){
		if(j>mx)ans[j]='1';
			else if(j<mn)ans[j]='2';
					else return 0;
	}
	return 1;
}
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d%s",&n,d+1);
		for(i=1;i<=n;++i)d[i]-='0';
		for(i=0;i<10;++i)if(check(i))break;
		ans[n+1]=0;
		puts(i<10?ans+1:"-");
	}
}
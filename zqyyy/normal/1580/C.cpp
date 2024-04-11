#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,r=0;char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))r=(r<<1)+(r<<3)+(ch&15),ch=getchar();
	return f?r:-r;
}
const int N=2e5+7,M=450;
int n,m,ans,a[N],b[N],s[N],lst[N],sum[M+7][M+7];
inline void work(int t){
	int opt=read(),x=read(),r=a[x]+b[x];
	if(opt==1){
		lst[x]=t;
		if(r<=M) for(int i=t+a[x];i<t+r;i++)sum[r][i%r]++;	
		else for(int i=t+a[x];i<=m;i+=r){
			s[i]++;
			if(i+b[x]<=m)s[i+b[x]]--;
		}
	}else{
		int T=lst[x];
		if(r<=M) for(int i=T+a[x];i<T+r;i++)sum[r][i%r]--;	
		else for(int i=T+a[x];i<=m;i+=r){
			s[i]--;
			if(i+b[x]<=m)s[i+b[x]]++;
			if(i<t && t<=i+b[x])ans--;
		}
	}
	ans+=s[t];int res=ans;
	for(int i=1;i<=M;i++)res+=sum[i][t%i];
	printf("%d\n",res);
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read(),b[i]=read();
	for(int t=1;t<=m;t++)work(t);
	return 0;	
}
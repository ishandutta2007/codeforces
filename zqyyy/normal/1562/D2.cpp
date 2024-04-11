#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))r=(r<<1)+(r<<3)+(ch^48),ch=getchar();
	return f?r:-r;
}
const int N=3e5+7;
int n,Q,s[N];
char str[N];
vector<int>vec[N<<1];
inline void solve(int l,int r){
	int x=s[l-1],sum=s[r]-x;
	x+=(sum>0?1:-1)*(abs(sum)/2+1)+n;
	l=*lower_bound(vec[x].begin(),vec[x].end(),l);
	printf("%d\n",l);
}
inline void work(){
	n=read(),Q=read(),scanf("%s",str+1);
	for(int i=0;i<=n+n;i++)vec[i].clear();
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+(i&1?1:-1)*(str[i]=='+'?1:-1);
		vec[s[i]+n].push_back(i);
	}
	while(Q--){
		int l=read(),r=read();
		if(!(s[r]-s[l-1])){puts("0");continue;}
		if((r-l)&1){
			puts("2");
			int x=s[l-1],sum=s[r]-x;
			x+=(sum>0?1:-1)+n;
			l=*lower_bound(vec[x].begin(),vec[x].end(),l);
			printf("%d ",l),solve(l+1,r);
		}else puts("1"),solve(l,r);
	}
}
int main(){
	int T=read();
	while(T--)work();
	return 0;	
}
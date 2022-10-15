#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=2e5+7;
int n,a[N];
vector<int>ans;
inline void solve(int st,int n){
	for(int i=n-2;i>0;i-=2)ans.push_back(st+i);
	for(int i=1;i<=n-2;i+=2)ans.push_back(st+i);
}
inline void work(){
	n=read();int s=0;
	for(int i=1;i<=n;i++)a[i]=read(),s^=a[i];
	if(s){puts("NO");return;}
	ans.clear();
	if(n&1){
		solve(0,n);
		printf("YES\n%lu\n",ans.size());
		for(int x:ans)printf("%d ",x);
		puts("");
		return;
	}
	s=0;
	for(int i=1;i<=n;i++){
		s^=a[i];
		if((i&1) && !s){
			solve(0,i),solve(i,n-i);
			printf("YES\n%lu\n",ans.size());
			for(int x:ans)printf("%d ",x);
			puts("");
			return;
		}
	}
	puts("NO");
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}
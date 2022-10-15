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
int n,m,Q,ans;
set<int>s[N];
inline void work(){
	n=read(),m=read();
	while(m--){
		int x=read(),y=read();
		if(x>y)swap(x,y);
		if(!s[x].size())ans++;
		s[x].insert(y);
	}
	Q=read();
	while(Q--){
		int op=read();
		if(op==3)printf("%d\n",n-ans);
		else{
			int x=read(),y=read();
			if(x>y)swap(x,y);
			if(op==1){
				if(!s[x].size())ans++;
				s[x].insert(y);
			}else{
				s[x].erase(y);
				if(!s[x].size())ans--;
			}
		}
	}
}
int main(){
	int T=1;
	while(T--)work();
	return 0;	
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=2e5+7;
int n,K;
inline void work(){
	n=read(),K=read();
	map<int,int>h;
	bool fl=0;
	for(int i=1;i<=n;i++){
		int x=read();
		h[x]=1;
		if(h.count(x+K) || h.count(x-K))fl=1;
	}
	puts(fl?"Yes":"No");
}
int main(){
	int test=read();
	while(test--)work();
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
#define fi first
#define se second
const int N=5e5+7;
struct Linear_Basis{
	int a[20],t[20];
	inline void insert(int x,int tim){
		for(int i=19;~i;i--)
			if(x>>i&1){
				if(!a[i]){a[i]=x,t[i]=tim;return;}
				if(t[i]<tim)swap(t[i],tim),swap(a[i],x);
				x^=a[i];
			}
	}
	inline int query(int tim){
		int res=0;
		for(int i=19;~i;i--)
			if(t[i]>=tim && (res^a[i])>res)res^=a[i];
		return res;
	}
}s;
int n,Q,a[N],ans[N];
vector<pair<int,int> >vec[N];
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	Q=read();
	for(int i=1;i<=Q;i++){
		int l=read(),r=read();
		vec[r].push_back({l,i});
	}
	for(int i=1;i<=n;i++){
		s.insert(a[i],i);
		for(auto j:vec[i])
			ans[j.se]=s.query(j.fi);
	}
	for(int i=1;i<=Q;i++)printf("%d\n",ans[i]);
	return 0;
}
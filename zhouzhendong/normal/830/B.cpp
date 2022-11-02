#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while (!isdigit(ch)&&ch!='-')
		ch=getchar();
	if (ch=='-')
		f=0,ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?x:-x;
}
const int N=100005;
int n;
int a[N],c[N];
void add(int x,int d){
	for (;x<=n;x+=x&-x)
		c[x]+=d;
}
int ask(int x){
	int ans=0;
	for (;x;x-=x&-x)
		ans+=c[x];
	return ans;
}
int query(int L,int R){
	return ask(R)-ask(L-1);
}
vector <int> v[N];
int main(){
	n=read();
	for (int i=1;i<=n;i++){
		a[i]=read();
		add(i,1);
		v[a[i]].push_back(i);
	}
	int p=0;
	LL ans=0;
	for (int i=1;i<N;i++){
		if (v[i].empty())
			continue;
		int s=v[i].size();
		int d=upper_bound(v[i].begin(),v[i].end(),p)-v[i].begin();
		for (int j=0;j<s;j++)
			v[i].push_back(v[i][j]);
		int b=p+1,e=v[i][d+s-1];
		if (e<b){
			ans+=query(b,n);
			ans+=query(1,e);
		}
		else
			ans+=query(b,e);
		for (int j=d;j<d+s;j++)
			add(v[i][j],-1);
		p=e;
	}
	cout << ans;
	return 0;
}
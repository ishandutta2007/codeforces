#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL read(){
	LL x=0;
	char ch=getchar();
	while (!isdigit(ch))
		ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
const int N=100005;
int T,n,m;
int a[N],v[N],p[N],vis[N];
int f(int n){
	int ans=0;
	while (ans*(ans+1)<=n*2)
		ans++;
	return ans-1;
}
int c[N];
void Add(int x,int id){
	for (;x<=n;x+=x&-x)
		c[x]=v[c[x]]<v[id]?id:c[x];
}
int Ask(int x){
	int ans=0;
	for (;x;x-=x&-x)
		ans=v[ans]<v[c[x]]?c[x]:ans;
	return ans;
}
vector <vector <int> > ans;
vector <int> vec_empty;
void Main(){
	ans.clear();
	n=read();
	for (int i=1;i<=n;i++)
		a[i]=read();
	m=n;
	while (m>0){
		int k=f(m);
//		cout<<"k="<<k<<endl;
		for (int i=0;i<=n;i++)
			c[i]=0;
		for (int i=1;i<=m;i++){
			vis[i]=0;
			p[i]=Ask(a[i]);
			v[i]=v[p[i]]+1;
			Add(a[i],i);
		}
		int tail=Ask(n),len=v[tail];
		if (len>k){
			ans.push_back(vec_empty);
			for (int i=tail;i;i=p[i])
				vis[i]=1,ans.back().push_back(a[i]);
			reverse(ans.back().begin(),ans.back().end());
			int _m=0;
			for (int i=1;i<=m;i++)
				if (!vis[i])
					a[++_m]=a[i];
			m=_m;
		}
		else {
			int c=(int)ans.size()-1;
			for (int i=1;i<=len;i++)
				ans.push_back(vec_empty);
			for (int i=1;i<=m;i++)
				ans[c+v[i]].push_back(a[i]);
			break;
		}
	}
	printf("%d\n",(int)ans.size());
	for (auto s : ans){
		printf("%d",(int)s.size());
		for (auto v : s)
			printf(" %d",v);
		puts("");
	}
}
int main(){
	T=read();
	while (T--)
		Main();
	return 0;
}
/*
1
16
11 12 13 14 15 16 7 8 9 10 4 5 6 2 3 1
*/
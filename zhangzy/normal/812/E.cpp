#include<bits/stdc++.h>
#define N 101000
#define ll long long
#define s size()
using namespace std;
vector<int>v[2];
int cnt[200*N],n,a[N],fa[N],used[N],b[N],t;
ll ans=0;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=2;i<=n;b[fa[i++]]=1) scanf("%d",&fa[i]);
	for (int i=1;i<=n;i++) if (!b[i]) for (int x=i,d=0;!used[x]&&x;x=fa[x],d^=1) v[d].push_back(a[used[x]=x]);
	for (int i=0;i<(int)v[0].s;cnt[v[0][i++]]++) t^=v[0][i];
	if (!t) ans=(ll)v[0].s*(v[0].s-1)/2+(ll)v[1].s*(v[1].s-1)/2;
	for (int i=0;i<(int)v[1].s;i++) ans+=cnt[v[1][i]^t];
	cout<<ans;
}
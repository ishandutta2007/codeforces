#include<bits/stdc++.h>
#define pa pair<int,int>
#define ll long long
#define N 300005
using namespace std;
int a[3][N];
int p[3][N];
map<pa,int> Mp;
map<ll,int> mp;
ll b[N];
int f[N];
int n;
ll work(int *a,int *p){
	for (int i=1;i<=n;i++)
		b[i]=b[i-1]+a[i];
	while (!mp.empty()) mp.erase(mp.begin());
	mp[0]=0;
	for (int i=1;i<=n;i++){
		p[i]=p[i-1];
		if (mp.count(b[i]))
			p[i]=max(p[i],mp[b[i]]+1);
		mp[b[i]]=i;
	}
}
int calc(int x,int y){
	if (x==-1||y==-1)
		return -1e9;
	if (x==y)
		return f[x];
	if (Mp.count(pa(x,y)))
		return Mp[pa(x,y)];
	int &ans=Mp[pa(x,y)];
	ans=f[min(x,y)];
	if (x>y)
		ans=max(ans,calc(p[0][x]-1,y)+1);
	else
		ans=max(ans,calc(x,p[1][y]-1)+1);
	return ans;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[0][i]);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[1][i]);
	for (int i=1;i<=n;i++)
		a[2][i]=a[1][i]+a[0][i];
	for (int i=0;i<3;i++)
		work(a[i],p[i]);
	for (int i=1;i<=n;i++){
		f[i]=f[i-1];
		if (p[2][i])
			f[i]=max(f[i],f[p[2][i]-1]+1);
		f[i]=max(f[i],calc(p[0][i]-1,i)+1);
		f[i]=max(f[i],calc(i,p[1][i]-1)+1);
	}
	printf("%d",f[n]);
}
#include <bits/stdc++.h>
using namespace std;
const int N=10005;
int n,a[N],cnt=0;
int pcnt=0,prime[N],f[N];
map <int,int> mp;
int tot,v[N],ans[N];
void get_prime(int n){
	for (int i=1;i<=n;i++)
		f[i]=1;
	f[1]=0;
	for (int i=2;i<=n;i++){
		if (!f[i])
			continue;
		prime[++pcnt]=i*i;
		for (int j=i*2;j<=n;j+=i)
			f[j]=0;
	}
}
int main(){
	get_prime(10000);
	scanf("%d",&n);
	mp.clear();
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if (a[i]==0)
			continue;
		for (int j=1;j<=pcnt;j++)
			while (a[i]%prime[j]==0)
				a[i]/=prime[j];
		if (mp[a[i]]==0)
			mp[a[i]]=++cnt;
		a[i]=mp[a[i]];
	}
	for (int i=1;i<=n;i++){
		memset(v,0,sizeof v);
		tot=0;
		for (int j=i;j<=n;j++){
			if (a[j])
				tot+=v[a[j]]==0;
			v[a[j]]++;
			ans[max(tot,1)]++;
		}
	}
	for (int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}
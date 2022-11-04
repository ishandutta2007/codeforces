#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define mo 998244353
#define vi vector<int>
#define For(i,j,k) for (int i=j;i<=k;i++)
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int R[N*10];
void FFT(vi &a,int n,int f){
	for (int i=0;i<n;i++)
		if (i<R[i]) swap(a[i],a[R[i]]);
	for (int d=1;d<n;d<<=1){
		int wn=power(3,(mo-1)/(d<<1));
		if (f==-1) wn=power(wn,mo-2);
		for (int i=0;i<n;i+=(d<<1))
			for (int j=i,w=1;j<i+d;j++){
				int y=1ll*a[j+d]*w%mo;
				a[j+d]=(a[j]+mo-y)%mo;
				a[j]=(a[j]+y)%mo;
				w=1ll*w*wn%mo;
			}
	}
	if (f==-1){
		int v=power(n,mo-2);
		for (int i=0;i<n;i++)
			a[i]=1ll*a[i]*v%mo;
	}
}
vi mul(vi a,vi b){
	int c=1,L=0,old=a.size()+b.size()-1;
	for (;c<old;c<<=1,L++);
	vi tmp;
	a.resize(c);
	b.resize(c);
	tmp.resize(c);
	for (int i=0;i<c;i++)
		R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
	FFT(a,c,1); FFT(b,c,1);
	for (int i=0;i<c;i++)	
		tmp[i]=1ll*a[i]*b[i]%mo;
	FFT(tmp,c,-1);
	tmp.resize(old);
	return tmp;
}
vi solve(int l,int r,const vi &a){
	if (r==l){
		vi ans;
		ans.push_back(1);
		ans.push_back(a[l]);
		return ans;
	}
	int mid=(l+r)/2;
	return mul(solve(l,mid,a),solve(mid+1,r,a));
}
int n,k,ans;
int fac[N],inv[N];
int sz[N],dp[N];
vector<int> e[N];
vector<int> jdb[N];
void dfs(int x,int fa){
	sz[x]=1; vi cur;
	for (int i=0;i<e[x].size();i++){
		int to=e[x][i];
		if (to==fa) continue;
		dfs(to,x);
		cur.push_back(sz[to]);
		sz[x]+=sz[to];
	}
	int hv=cur.size();
	if (cur.size())
		cur=solve(0,hv-1,cur);
	else cur.push_back(1);
	jdb[x]=cur;
	for (int i=0;i<cur.size()&&i<=k;i++)
		dp[x]=(dp[x]+1ll*cur[i]*fac[k]%mo*inv[k-i])%mo;
}
void dfs2(int x,int fa,int hv,int del){
	ans=(ans+mo-1ll*dp[x]*del%mo)%mo;
	ans=(ans+1ll*dp[x]*hv)%mo;
	vi cur=jdb[x];
	cur.push_back(0);
	for (int i=cur.size()-2;i>=0;i--)
		cur[i+1]=(cur[i+1]+1ll*cur[i]*(n-sz[x]))%mo;
	map<int,int> mp;
	for (int i=0;i<e[x].size();i++){
		int to=e[x][i];
		if (to!=fa){
			if (mp.find(sz[to])==mp.end()){
				int	val=0;
				vi tmp=cur;
				for (int j=1;j<tmp.size();j++)
					tmp[j]=(tmp[j]+mo-1ll*tmp[j-1]*sz[to]%mo)%mo;
				for (int j=0;j<tmp.size()&&j<=k;j++)
					val=(val+1ll*tmp[j]*fac[k]%mo*inv[k-j])%mo;
				mp[sz[to]]=val;
			}
		}
	}
	for (int i=0;i<e[x].size();i++){
		int to=e[x][i];
		if (to!=fa)
			dfs2(to,x,(hv+mp[sz[to]])%mo,(del+dp[x])%mo);
	}
}
int main(){
	int u=clock();
	fac[0]=inv[0]=inv[1]=1;
	For(i,2,N-1) inv[i]=1ll*(mo-mo/i)*inv[mo%i]%mo;
	For(i,1,N-1){
		fac[i]=1ll*fac[i-1]*i%mo;
		inv[i]=1ll*inv[i-1]*inv[i]%mo;
	}
	scanf("%d%d",&n,&k);
	if (k==1){
		printf("%lld",1ll*n*(n-1)/2%mo);
		return 0;
	}
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1,0);
	int now=0;
	for (int i=1;i<=n;i++){
		ans=(ans+1ll*now*dp[i])%mo;
		now=(now+dp[i])%mo;
	}
	dfs2(1,0,0,0);
	printf("%d",ans);
}
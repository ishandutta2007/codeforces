#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef uint64_t ull;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=66,M=1<<15|7,mod=1e9+7;
inline void inc(int &x,int y){x+=y-mod,x+=x>>31&mod;}
int pa[N];
int find(int x){return pa[x]^x?pa[x]=find(pa[x]):x;}
int n,sum,ans=1,a[N],id[N],C[N][N],f[N][M],num[M];
bool flg[N];
ull S[N];
inline void solve(int pos){
	int tot=0;vector<int>vec,d;
	for(int i=1;i<=n;i++)
		if(flg[i] && pa[i]==pos)id[i]=tot++,vec.push_back(i);
	int U=(1<<tot)-1,cnt;
	for(int i=1;i<=n;i++)
		if(!flg[i] && pa[i]==pos)d.push_back(i);
	if(d.empty())return;
	cnt=d.size()-1,sum+=cnt,ans=(ll)ans*C[sum][cnt]%mod;
	fill(num,num+U+1,0),memset(f, 0, sizeof f);
	for(int i:d){
		int s=0;
		for(int j:vec)
			if(S[i]>>j&1)s|=1<<id[j];
		S[i]=s,num[s]++,f[0][s]++;
	}
	for(int i=0;i<tot;i++)
		for(int s=0;s<=U;s++)
			if(s>>i&1)num[s]+=num[s^(1<<i)];
	for(int i=0;i<cnt;i++)
		for(int s=0;s<=U;s++){
			int v=f[i][s];
			if(i>num[s])continue;
			inc(f[i+1][s],(ll)v*(num[s]-i-1)%mod);
			for(int j:d){
				int t=S[j]&s;
				if(!t || t==S[j])continue;
				inc(f[i+1][s|S[j]],v);
			}
		}
	ans=(ll)ans*f[cnt][U]%mod;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	C[0][0]=1;
	for(int i=1;i<=n;i++) {
		C[i][0]=1;
		for (int j=1; j<=n; j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	for(int i=1;i<=n;i++){
		flg[i]=true,pa[i]=i;
		for(int j=1;j<=n;j++)
			flg[i]&=i==j || a[i]%a[j]!=0;
	}
	for(int i=1;i<=n;i++){
		if(flg[i])continue;
		int lst=0;
		for(int j=1;j<=n;j++){
			if(i==j || !flg[j])continue;
			if(a[i]%a[j]==0){
				if(!lst)lst=find(j);
				S[i]|=1ull<<j,pa[find(j)]=lst;
			}
		}
	}
	for(int i=1;i<=n;i++)
		if(!flg[i])pa[i]=find(__builtin_ctzll(S[i]));
	for(int i=1;i<=n;i++)pa[i]=find(i);
	for(int i=1;i<=n;i++)
		if(flg[i] && pa[i]==i)solve(i);
	printf("%d\n",ans);
	return 0;
}
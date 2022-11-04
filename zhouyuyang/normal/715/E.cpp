#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int N=255;
const int mo=998244353;
int p[N],q[N],fl[N];
int vis[N],d[N],nxt[N];
int n,no,na,nb,nab,f[N];
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&p[i]);
	For(i,1,n) scanf("%d",&q[i]);
	int ans=1,cnt=0;
	For(i,1,n)
		if (p[i]&&q[i])
			d[q[i]]++,nxt[p[i]]=q[i];
		else if (!p[i]&&!q[i])
			ans=1ll*ans*(++cnt)%mo;
		else if (!q[i]) fl[p[i]]|=1;
		else fl[q[i]]|=2;
	cnt=0;
	For(i,1,n)
		if (!d[i]&&!vis[i]){
			int j=i; vis[i]=1;
			for (;nxt[j]&&!vis[nxt[j]];)
				j=nxt[j],vis[j]=1;
			if (fl[i]&2) fl[j]&1?++nab:++nb;
			else fl[j]&1?++na:++no; 
		}
	For(i,1,n) if (!vis[i]){
		cnt++;
		for (int j=i;!vis[j];j=nxt[j]) vis[j]=1;
	}
	For(i,1,nab) ans=1ll*ans*max(no+1-i,0)%mo;
	f[cnt]=ans;
	For(i,1,no+na){
		Rep(j,n,1) f[j]=(1ll*f[j]*(i-1)+f[j-1])%mo;
		f[0]=0;
	}
	For(i,1,nb){
		Rep(j,n,1) f[j]=(1ll*f[j]*(i-1+no)+f[j-1])%mo;
		f[0]=0;
	}
	For(i,0,n-1) printf("%d ",f[n-i]);
}
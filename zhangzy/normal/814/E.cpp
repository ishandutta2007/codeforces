#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define two (now==2)
#define thr (now==3)
using namespace std;
void U(ll &x,ll y){
	x=(x+y)%mod;
}
void V(ll &x,ll y){
	x=x*y%mod;
}
ll K(ll x,ll y){
	ll t=1; for (;y;y>>=1,V(x,x)) if (y&1) V(t,x); return t;
}

int n,d[233],t,pos,cnt[4],tt,now;
ll ans=0,jc[234],fac[234],f[55][55][55][55],g[55][55][55][55],h[55][55][55];

ll doit(){
	ll res=jc[t];
	for (int i=2;i<=3;i++){
		for (int j=cnt[i];j--;V(res,fac[i]));
	}
	return res;
}

ll C(ll x,int y){
	if (y==1) return x;
	if (y==2) return x*(x-1)/2;
	if (y==3) return x*(x-1)*(x-2)/6;
}


ll dfs(int c1,int c2,int c11){
	if (!c1&&!c2&&!c11) return 1;
	if (h[c1][c2][c11]!=-1) return h[c1][c2][c11];
	ll t=0;
	if (c1>=2)   U(t,dfs(c1-2,c2,c11)  *C(c1,2)   %mod);
	if (c2>=2)   U(t,dfs(c1,c2-2,c11+1)*C(c2,2)   %mod);
	if (c11>=2)  U(t,dfs(c1+2,c2,c11-2)*C(c11,2)*4%mod);
	if (c1&&c2)  U(t,dfs(c1,c2-1,c11)  *c1*c2     %mod);
	if (c11&&c1) U(t,dfs(c1,c2,c11-1)  *c1*c11*2  %mod);
	if (c11&&c2) U(t,dfs(c1+2,c2-1,c11-1)*c2*c11*2%mod);
	return h[c1][c2][c11]=t;
}

int main(){
	memset(h,-1,sizeof h);
	jc[0]=1;
	for (int i=1;i<=233;i++) jc[i]=jc[i-1]*i%mod;
	fac[233]=K(jc[233],mod-2);
	for (int i=233;i>0;i--) fac[i-1]=fac[i]*i%mod;
	
	cin>>n;
	for (int i=1;i<=n;cin>>d[i++]);
	pos=1+d[1]; if (pos>n) return 0*printf("0");
	for (int i=2;i<=pos;i++) cnt[d[i]-1]++;
	memset(f,0,sizeof f);
	f[cnt[1]][cnt[2]][0][0]=1;
	for (int nnd=pos+1;nnd<=n;nnd++){
		now=d[nnd];
		
		for (int i=0;i<=50;i++)
			for (int j=0;j<=50;j++)
				for (int ii=0;ii<=50;ii++)
					for (int jj=0;jj<=50;jj++) if (f[i][j][ii][jj]&&ii+jj)
						U(f[ii][jj][0][0],f[i][j][ii][jj]*dfs(i,j,0)%mod*fac[i/2+j]);
		
		memset(g,0,sizeof g);
		for (int i=0;i<=50;i++){
			for (int j=0;j<=50;j++){
				for (int ii=0;ii<=50;ii++){
					for (int jj=0;jj<=50;jj++) if (f[i][j][ii][jj]){
						if (i) U( g[i-1][j][ii+two][jj+thr]   , f[i][j][ii][jj]*i );
						if (j) U( g[i+1][j-1][ii+two][jj+thr] , f[i][j][ii][jj]*j );
					}
				}
			}
		}
		swap(f,g);
	}
	for (int i=0;i<=50;i++)
		for (int j=0;j<=50;j++)
			for (int ii=0;ii<=50;ii++)
				for (int jj=0;jj<=50;jj++) if (f[i][j][ii][jj])
					U(ans,f[i][j][ii][jj]*dfs(i,j,0)%mod*fac[i/2+j]%mod*dfs(ii,jj,0)%mod*fac[ii/2+jj]%mod);

	cout<<ans;
}
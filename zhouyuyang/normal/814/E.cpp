#include<bits/stdc++.h>
#define mo 1000000007
using namespace std;
const int N=55;
int g[N][N][N];
int f[N][N];
int d[N],sd[N],n;
void upd(int &x,int y){
	(x+=y)>=mo?x-=mo:233;
}
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&d[i]);
	for (int i=1;i<n;i++)
		sd[i+1]=sd[i]+d[i];
	g[0][0][0]=1;
	for (int c0=0;c0<=n;c0++)
		for (int c2=0;c2<=n;c2++)
			for (int c1=0;c1<=n;c1++){
				if (!(c1+c2)) continue;
				if (c2){
					if (c0>1) upd(g[c0][c1][c2],1ll*g[c0-2][c1][c2-1]*c0*(c0-1)/2%mo);//2-0,2-0
					if (c2>1&&c0) upd(g[c0][c1][c2],1ll*g[c0-1][c1+1][c2-2]*(c2-1)*c0%mo);//2-0,2-2
					if (c2>2) upd(g[c0][c1][c2],1ll*g[c0][c1+2][c2-3]*(c2-1)*(c2-2)/2%mo);//2-2,2-2
					if (c1&&c2>1) upd(g[c0][c1][c2],1ll*g[c0][c1][c2-2]*c1*(c2-1)%mo);//2-1,2-2
					if (c1&&c0) upd(g[c0][c1][c2],1ll*g[c0-1][c1-1][c2-1]*c0*c1%mo);//2-1,2-0
					if (c1>1) upd(g[c0][c1][c2],1ll*g[c0][c1-2][c2-1]*c1*(c1-1)/2%mo);//2-1,2-1
				}
				else{
					if (c0) upd(g[c0][c1][c2],1ll*g[c0-1][c1-1][c2]*c0%mo);
					if (c1>1) upd(g[c0][c1][c2],1ll*g[c0][c1-2][c2]*(c1-1)%mo);
				}
			}
	f[n][n-1]=1;
	for (int l=n-1;l;l--)
		for (int r=l;r<n;r++){
			int cnt2=sd[r+1]-sd[l]-2*(r-l+1);
			int cnt1=(r-l+1)-cnt2;
			for (int nxt=0;nxt<=2*cnt2+cnt1&&r+nxt<n;nxt++)
				upd(f[l][r],1ll*f[r+1][r+nxt]*g[nxt][cnt1][cnt2]%mo);
		}
	printf("%d",f[1][d[0]]);
}
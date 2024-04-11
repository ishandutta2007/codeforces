#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

struct R{
	int to,nex;
}r[202000];
int n,all,m,l,hea[101000]={0},cnt=1,f[101000][3][12]={0},ans=0,tmp[3][12];

void U(int &x,int y){
	x+=y; if (x>=mod) x-=mod;
}
void V(int &x,int y){
	x=(ll)x*y%mod;
}

void dfs(int x,int fff){
	int y;
	f[x][0][0]=f[x][1][1]=f[x][2][0]=1;
	for (int i=hea[x];i>0;i=r[i].nex){
		y=r[i].to; if (y==fff) continue;
		dfs(y,x);
		
		memset(tmp,0,sizeof tmp);
		for (int j=0;j<=m;j++){
			for (int jj=0;jj+j<=m;jj++){
				U(tmp[0][j+jj], ((ll)f[y][0][jj]+f[y][1][jj]+f[y][2][jj]) %mod *(ll)f[x][0][j] %mod );
				U(tmp[1][j+jj], ((ll)f[y][0][jj]                        )      *(ll)f[x][1][j] %mod );
				U(tmp[2][j+jj], ((ll)f[y][0][jj]            +f[y][2][jj]) %mod *(ll)f[x][2][j] %mod );
			}
		}
		swap(tmp,f[x]);
	}
	for (int i=0;i<=m;i++){
		V(f[x][0][i],l-1);
		V(f[x][2][i],all-l);
	}
}

int main(){
	scanf("%d%d",&n,&all);
	int x,y;
	for (int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		r[++cnt]=(R){y,hea[x]};hea[x]=cnt;
		r[++cnt]=(R){x,hea[y]};hea[y]=cnt;
	}
	scanf("%d%d",&l,&m);
	dfs(1,0);
	for (int i=0;i<=2;i++) for (int j=0;j<=m;j++) U(ans,f[1][i][j]);
	cout<<ans;
}
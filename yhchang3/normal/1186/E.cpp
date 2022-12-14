#include<bits/stdc++.h>
using namespace std;

string g[1000];
typedef long long int ll;
int n,m,q;
int tot;
int calc(int x){
	if(x==0)	return 0;
	if(x==1)	return 1;
	if(x==2)	return 1;
	int z=__builtin_clz(x);
	z=31-z;
	int y=1<<z;
	return (y>>1)+(x-y-calc(x-y));	
}

int pre[1000][1000];
ll solve(int x,int y){
	if(x<=0||y<=0){
		return 0;
	}
	int xx=x/n,yy=y/m;
	x=x%n,y=y%m;
	int vx=calc(xx),vy=calc(yy);
	bool ix = vx == calc(xx+1);
	bool iy = vy == calc(yy+1);
	ll tmp = 1LL*vx*vy+1LL*(xx-vx)*(yy-vy);
	ll ans = tmp * tot + (n*m-tot)*((ll) xx*yy - tmp);
	if(y!=0){
		int wy = pre[n-1][y-1];
		int invy = n*y - wy;
		if(!iy)
			ans+=1LL*wy*vx+1LL*invy*(xx-vx);
		else
			ans+=1LL*wy*(xx-vx)+1LL*invy*vx;
	}
	if(x!=0){
		int wx = pre[x-1][m-1];
		int invx = m*x - wx;
		if(!ix)
			ans+=1LL*wx*vy+1LL*invx*(yy-vy);
		else
			ans+=1LL*wx*(yy-vy)+1LL*invx*vy;
	}
	if(x!=0&&y!=0){
		int t = pre[x-1][y-1];
		if(ix^iy)	ans+=x*y-t;
		else	ans+=t;
	}
	return ans;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>q;
	for(int i=0;i<n;i++)
		cin>>g[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			pre[i][j]=g[i][j]=='1';
			if(i!=0)	pre[i][j]+=pre[i-1][j];
			if(j!=0)	pre[i][j]+=pre[i][j-1];
			if(i!=0&&j!=0)	pre[i][j]-=pre[i-1][j-1];
		}
	tot=pre[n-1][m-1];
	
	while(q--){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		cout<<solve(x2,y2)-solve(x1-1,y2)-solve(x2,y1-1)+solve(x1-1,y1-1)<<'\n';
	}
}
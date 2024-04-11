#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator

#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define EB emplace_back
#define fi first
#define se second

#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));

#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2

#define INF ((1ll<<60)-233)
#define sqr(x) ((x)*(x))
#define debug puts("wzpkking")
using namespace std;
const int N=32;
int num1[N*N],num2[N*N];
int mp[N][N],ed[N][N],bo[N][N];
int n,m,X,Y,Rotate;
vector<pii > ans;
void trans(int a[N][N],int num[]){
	For(i,1,n) For(j,1,m) num[a[i][j]]++;
	For(i,1,900) num[i]+=num[i-1];
	For(i,1,n) For(j,1,m) a[i][j]=num[a[i][j]]--; 
}
void init(){
	scanf("%d%d",&n,&m);
	For(i,1,n) For(j,1,m)
		scanf("%d",&mp[i][j]);
	For(i,1,n) For(j,1,m)
		scanf("%d",&ed[i][j]);
	trans(mp,num1);
	trans(ed,num2);
	For(i,1,900)
		if (num1[i]!=num2[i]){
			puts("-1"); exit(0);
		}
}
void output(){
	printf("%d\n",ans.size()-1);
	For(i,0,ans.size()-1) printf("%d %d\n",ans[i].fi,ans[i].se);
}
const int d[8][2]={-1,0,1,0,0,-1,0,1,-1,-1,-1,1,1,-1,1,1};

void move(int dir){
	int x=X+d[dir][0];
	int y=Y+d[dir][1];
	swap(mp[x][y],mp[X][Y]);
	X=x; Y=y;
}
void GO(int x,int y){
	int lax=-1,lay=-1;
	for (;;){
		if (x==X&&y==Y) break;
		int mn=1<<30,dd;
		For(i,0,7){
			int nx=X+d[i][0],ny=Y+d[i][1];
			if (nx<1||nx>n||ny<1||ny>m) continue;
			if (bo[nx][ny]||(nx==lax&&ny==lay)) continue;
			int val=abs(nx-x)+abs(ny-y);
			if (val<mn) mn=val,dd=i;
		}
		lax=X; lay=Y; move(dd);
		ans.push_back(pii(X,Y));
	}
}
void work1(){
	For(i,1,m) For(j,1,m) if (i!=j){
		X=1; Y=i;
		ans.clear();
		ans.PB(pii(1,i));
		GO(1,j);
		bool fl=1;
		For(k,1,m) if (mp[1][k]!=ed[1][k]) fl=0;
		if (fl){
			if (Rotate)
				For(i,0,ans.size()-1)
					swap(ans[i].fi,ans[i].se);
			output();
			exit(0);
		}
		GO(1,i);
	}
	puts("-1");
}
pii find(int x){
	For(i,1,n) For(j,1,m)
		if (mp[i][j]==x) return pii(i,j);
}
void push(int &x,int &y,int dir){
	int xx=x+d[dir][0],yy=y+d[dir][1];
	GO(xx,yy); move(dir^1); ans.PB(pii(x,y));
	swap(bo[x][y],bo[xx][yy]);
	x=xx; y=yy;
}
void work2(){
	pii st=find(ed[n][m]);
	X=st.fi; Y=st.se; ans.PB(pii(X,Y));
	For(i,1,n-2) For(j,1,m){
		pii tmp=find(ed[i][j]);
		int x=tmp.fi,y=tmp.se; bo[x][y]=1;
		for (;y<j;push(x,y,3));
		for (;y>j;push(x,y,2));
		for (;x>i;push(x,y,0)); 
	}
	For(j,1,m-2) For(i,n-1,n){
		pii tmp=find(ed[i][j]);
		int x=tmp.fi,y=tmp.se; bo[x][y]=1;
		for (;x<i;push(x,y,1));
		for (;x>i;push(x,y,0));
		for (;y>j;push(x,y,2));
	}
	srand(time(NULL));
	for (;;){
		bool f=1;
		For(i,n-1,n) For(j,m-1,m)	
			if (mp[i][j]!=ed[i][j]) f=0;
		if (f) break;
		int dir=rand()%8;
		int x=X+d[dir][0],y=Y+d[dir][1];
		if ((x==n-1||x==n)&&(y==m-1||y==m))
			move(dir),ans.PB(pii(X,Y));
	}
	output();
}
int main(){
	init();
	if (m==1){
		Rotate=1;
		For(i,1,n)
			mp[1][i]=mp[i][1],
			ed[1][i]=ed[i][1];
		swap(n,m);
	}
	if (n==1) work1();
	else work2();
}
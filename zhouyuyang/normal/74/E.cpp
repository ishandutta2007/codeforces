#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db double
#define pii pair<int,int>
#define pll pair<ll,ll> 
#define pli pair<ll,int>
#define vi vector<int>
#define vpi vector<pii >
#define IT iterator
 
#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define y1 wzpakking 
#define fi first
#define se second
#define BG begin
#define ED end
 
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define SUB(i,j) for (int all=(int)(j+2147483648ll),i=(int)(j);i>=0;i=(i-1)&j) 
#define UPD(x,y) (((x)+=(y))>=mo?(x)-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define sqr(x) (1ll*x*x)
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
#define INF (1<<30)
using namespace std;
char s[10][10];
vector<string> ans;
void work(int x,int y,int fl){
	string v;
	For(i,0,12){
		if (!fl){
			if (i&1){
				v=(i&2?"D":"U");
				v+=char(y+49);
			}
			else v="R",v+=char(x+49);
		}
		else{
			if (i&1){
				v=(i&2?"R":"L");
				v+=char(x+49);
			}
			else v="D",v+=char(y+49);
		}
		ans.push_back(v);
	}
	if (fl) swap(s[x][y],s[x][y+1]);
	else swap(s[x][y],s[x+1][y]);
}
int main(){
	For(i,0,5) scanf("%s",s[i]);
	For(i,0,5) For(j,0,5){
		int p=i*6+j+(i*6+j>9?55:48);
		int x,y;
		For(X,0,5) For(Y,0,5)
			if (s[X][Y]==p) x=X,y=Y;
		for (;y>j;work(x,--y,1));
		for (;y<j;work(x,y++,1));
		for (;x>i;work(--x,y,0));
	}
	printf("%d\n",ans.size());
	For(i,0,ans.size()-1) cout<<ans[i]<<endl;
}
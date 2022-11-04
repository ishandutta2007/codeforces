#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define uint ungigned
#define db long double
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
#define UPD(x,y) (((x)+=(y))>=mo?(x)-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define sqr(x) (1ll*x*x)
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
using namespace std;
const int N=305,M=100005;
struct node{
	int x1,y1,x2,y2;
}ans[2][M*2];
int len[2][N][N];
int n,m,tp[2];
char s[M];
void move(int x1,int y1,int x2,int y2,int id){
	ans[id][++tp[id]]=(node){x1,y1,x2,y2};
	len[id][x1][y1]--;
	len[id][x2][y2]++;
}
void add(int i,int j,int p,int id){
	if (i!=p) move(i,j,p,j,id);
	else move(i,j,i,(j==1?2:1),id);
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) For(j,1,m){
		scanf("%s",s+1);
		int len=strlen(s+1);
		::len[0][i][j]+=len;
		Rep(k,len,1) add(i,j,s[k]-'0'+1,0);
	}
	For(i,1,n) For(j,1,m){
		scanf("%s",s+1);
		int len=strlen(s+1);
		::len[1][i][j]+=len;
		For(k,1,len) add(i,j,s[k]-'0'+1,1);
	}
	For(i,1,2)
		For(j,1,m) if (len[0][i][j]>len[1][i][j])
			For(k,1,m) if (len[0][i][k]<len[1][i][k])
				for (;len[0][i][j]>len[1][i][j]&&len[0][i][k]<len[1][i][k];)
					move(i,j,i,k,0);
	printf("%d\n",tp[0]+tp[1]);
	For(i,1,tp[0]) printf("%d %d %d %d\n",ans[0][i].x1,ans[0][i].y1,ans[0][i].x2,ans[0][i].y2);
	Rep(i,tp[1],1) printf("%d %d %d %d\n",ans[1][i].x2,ans[1][i].y2,ans[1][i].x1,ans[1][i].y1);
}
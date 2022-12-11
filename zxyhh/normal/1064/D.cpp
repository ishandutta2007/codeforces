#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<ctime>
#include<string>
#include<queue>
#include<cmath>
#define rep(x,a,b) for (int x=int(a);x<=(int)(b);x++)
#define drp(x,a,b) for (int x=int(a);x>=(int)(b);x--)
#define cross(x,a) for (int x=hd[a];x;x=nx[x])
#define ll long long
#define ldb long double
using namespace std;
inline ll max(ll zxy_FIR,ll zxy_SEC){return zxy_FIR>zxy_SEC?zxy_FIR:zxy_SEC; }
inline ll min(ll zxy_FIR,ll zxy_SEC){return zxy_FIR>zxy_SEC?zxy_SEC:zxy_FIR; }
inline ll rd(){
    ll x=0;int ch=getchar(); bool f=1;
    while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();
    if (ch=='-'){f=0;ch=getchar();}
    while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return f?x:-x;
}
void write(ll prt_x){ if (prt_x>=10) write(prt_x/10),putchar(prt_x%10+'0'); else putchar(prt_x+'0'); }
inline void wrt(ll prt_x,char prt_c){if (prt_x<0) putchar('-'),prt_x=-prt_x; write(prt_x); if (prt_c) putchar(prt_c);}
const int N = 2010, M = 2000*2000+10;
int n,m,r,c,x,y,id[N][N],size[M];
char s[N][N];
int cnt,tot,hd[M],to[M*4],nx[M*4],co[M*4];
inline void Add(int x,int y,int v){to[++tot]=y,nx[tot]=hd[x],hd[x]=tot,co[tot]=v;}
int h,t,q[M],le[M],ri[M],ans;
bool vis[M];
inline void bfs(int s){
    memset(q,0,sizeof q);
	h=0,q[t=1]=s,vis[s]=1,ans+=size[s];
	while (h<t){
		int u=q[++h];
		cross(i,u){
			int v=to[i];
			q[++t]=v,le[t]=le[h],ri[t]=ri[h];
			if (co[i]==1) le[t]++;
				else ri[t]++;
			if (vis[v]||ri[t]>y||le[t]>x){t--;continue;}
			vis[v]=1,ans+=size[v];
            ans=ans+1-1;
            vis[v]^=0;
		}
	}
}
int main(){
	n=rd(),m=rd(),r=rd(),c=rd(),x=rd(),y=rd();
	rep(i,1,n) scanf("%s",s[i]+1);
	rep(i,1,n)
		rep(j,1,m) 
			if (s[i][j]!='*'&&(s[i+1][j]=='*'||i+1>n)){
				++cnt;int x=i;
				while (s[x][j]=='.'&&x) id[x][j]=cnt,x--,size[cnt]++;
			    x=x+1-1;
            }
	rep(i,1,n)
		rep(j,2,m) if (id[i][j]&&id[i][j-1]) Add(id[i][j],id[i][j-1],1),Add(id[i][j-1],id[i][j],-1);
    rep(i,1,n) ans=0;
	//1?left,-1?right
	bfs(id[r][c]),wrt(ans,'\n');
}
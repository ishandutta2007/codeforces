#include<bits/stdc++.h>
using namespace std;
struct sta{
	int a[8];
	void srt(){sort(a,a+8);}
	sta(){memset(a,0,sizeof(a));}
	sta(int hs){for(int i=7;i>=0;i--)a[i]=hs%5,hs/=5;}
	int& operator[](const int x){return a[x];}
	int hs()const{
		int ans=0;
		for(int i=0;i<8;i++)ans=ans*5+a[i];
		return ans;
	}
	void rd(){for(int i=0;i<8;i++)cin>>a[i];}
};
const int MX=10000005;
#define ll long long
int F[10000005],S[10000005],c=0;
int ans[10000005];
inline int NO(int i,int j){return (i-1)*c+j;}
void dfs(int k,int lst,int hs){
	if(k==8){S[++c]=hs,F[hs]=c;return;}
	for(int i=lst;i<=5;i++)dfs(k+1,i,hs*5+i);
}
struct edge{
	int t,nxt;
}e[10000005];
int hed[10000005],ec;
int q[10000005],ind[10000005];
inline void ade(int f,int t){++ind[t];++ec;e[ec].t=t,e[ec].nxt=hed[f],hed[f]=ec;}
void buildg(){
	for(int i=1;i<=c;i++)
		for(int j=1;j<=c;j++){
			sta a(S[i]),b(S[j]);
			for(int k=7;k>=0&&a[k];k--){
				int vis[5];memset(vis,0,sizeof(vis));
				sta c;
				for(int l=7;l>=0&&b[l];l--)
					vis[(a[k]+b[l])%5]=1;
				for(int l=0,t;l<5;l++)if(vis[l]){
					c=a;c[k]=l;c.srt();
					t=F[c.hs()];
					ade(NO(j,t),NO(i,j));
				}
			}
		}
	int h=0,t=0;
	for(int i=2;i<=c;i++)
		ans[NO(i,1)]=-1,q[++t]=NO(i,1);
	while(h<t){
		int r=q[++h];
		for(int i=hed[r];i;i=e[i].nxt)if(!ans[e[i].t]){
			if(ans[r]==-1)ans[e[i].t]=1,q[++t]=e[i].t;
			else if(--ind[e[i].t]==0)ans[e[i].t]=-1,q[++t]=e[i].t;
		}
	}
}
char _s[3][10]={
	"Bob",
	"Deal",
	"Alice"
};
int main(){
	ios::sync_with_stdio(false);
	dfs(0,0,0);
	buildg();
	int T;cin>>T;
	while(T--){
		int f;cin>>f;
		sta a,b;a.rd(),b.rd();
		if(f)swap(a,b);
		a.srt(),b.srt();
		int r=ans[NO(F[a.hs()],F[b.hs()])];
		if(f)r*=-1;
		cout<<_s[r+1]<<endl;
	}
	return 0;
}
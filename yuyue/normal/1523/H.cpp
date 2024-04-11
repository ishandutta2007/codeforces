#include<bits/stdc++.h>
#define LL long long
#define SZ(x) (int)x.size()-1
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
const int M=2e4+10;
int n,a[M],m;
#define lowbit(x) (x&-x)
#define pii pair<int,int>
#define mp make_pair
pii d[M];
void add(int x,pii y){
	for (;x<=n;x+=lowbit(x)) d[x]=max(d[x],y);
}
pii qry(int x){
	pii ret=mp(0,0);
	for (;x;x-=lowbit(x)) ret=max(ret,d[x]);
	return ret;
}
pii f[15][M][33];
int g[15][M][33],b[M],tw[33],ted[33];
pii nw[33];
int main(){
	n=read(); m=read();
	F(i,1,n) a[i]=read(),b[i]=min(a[i]+i,n);
	DF(i,n,1){
		F(j,0,30) g[0][i][j]=min(n,b[i]+j);	
		add(i,mp(b[i],i));
		f[0][i][0]=qry(b[i]);
		int tmp=f[0][i][0].second;
		F(j,1,30){
			f[0][i][j]=max(f[0][i][j-1],mp(b[min(b[i]+j,n)],min(b[i]+j,n)));
		}
	}
	F(t,1,14){
		F(i,1,n){
			F(j,0,30){
				F(jj,0,j){
					int ps=f[t-1][i][jj].second;
					f[t][i][j]=max(f[t][i][j],f[t-1][ps][j-jj]);
					g[t][i][j]=max(g[t][i][j],g[t-1][ps][j-jj]);
				}
			}
		}
	}
	F(T,1,m){
		int l=read(),r=read(),k=read();
		if (l==r){
			cout<<0<<"\n";
			continue;
		}
		F(i,0,k) nw[i]=mp(b[l],l);
		int ans=1e9,cur=0;
		DF(i,14,0){
			F(j,0,k) tw[j]=nw[j].second,ted[j]=0;
			F(j,0,k){
				F(jj,0,j){
					ted[j]=max(ted[j],g[i][tw[jj]][j-jj]); 
				} 
			}
			int mx=0;
			F(j,0,k) mx=max(mx,ted[j]);
			if (mx>=r){
				ans=min(ans,cur|(1<<i));
			}
			else{
				F(j,0,k){
					F(jj,0,j){
						nw[j]=max(nw[j],f[i][tw[jj]][j-jj]); 
					} 
				}
				cur|=(1<<i);
			}
		}
		cout<<ans<<"\n";
	}
    return 0;
}
/*
100 1
4 6 5 1 6 6 6 5 3 6 4 4 2 1 6 4 2 1 2 1 4 6 6 5 4 5 5 4 4 5 5 4 1 2 3 1 3 5 4 4 5 3 6 5 5 1 4 4 1 5 5 4 5 1 1 5 3 4 4 2 6 6 4 4 5 2 6 6 2 3 1 6 3 4 4 1 2 1 2 2 3 4 1 3 3 4 6 3 2 5 6 6 6 6 4 6 3 2 1 5
19 84 14
*/
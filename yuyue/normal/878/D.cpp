#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
char buf[1<<23],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
#define pii pair<int,int>
#define mp make_pair
const int M=1e5+100,N=(1<<12);
bitset<N> d[M];
int L[M],R[M],m,n,Q,k,ans[M],a[20][M],ty[M],p[20];
vector<pii> v[M];
int main(){
	n=read(); m=k=read(); Q=read();
	F(i,1,k){
		F(j,1,n) a[i][j]=read();
	}
	F(i,1,Q){
		int op=read(),x=read(),y=read();
		if (op==1){
			int o=++m;
			L[o]=x; R[o]=y;
			ty[o]=1;
		}
		if (op==2){
			int o=++m;
			L[o]=x; R[o]=y;
			ty[o]=2; 
		}
		if (op==3){
			v[y].pb(mp(x,i));
		}
	}
	F(i,1,k){
		F(j,0,(1<<k)-1){
			if (j>>(i-1)&1){
				d[i][j]=1;
			}
		}
	}
	F(i,k+1,m){
		if (ty[i]==1){
			d[i]=d[L[i]]|d[R[i]];
		}
		else{
			d[i]=d[L[i]]&d[R[i]];
		}
	}
	F(i,1,n){
		F(j,1,k) p[j]=j;
		sort(p+1,p+k+1,[&](int x,int y){
			return a[x][i]<a[y][i]; 
		});
//		cout<<i<<"  qwq\n";
		F(o,0,SZ(v[i])){
			int id=v[i][o].second,pos=v[i][o].first;
			int msk=(1<<k)-1;
			F(j,1,k){
				msk^=(1<<p[j]-1);
				if (!d[pos][msk]){
					ans[id]=a[p[j]][i];
					break;
				}
			}
		}
	}
	F(i,1,Q) if (ans[i]) cout<<ans[i]<<"\n";
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/
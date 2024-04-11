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
const int M=1e5+10,dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int n,a[M],p[M];
bool cmp(int x,int y){
	return a[x]<a[y];
}
int m,b[M];
void solve(){
	n=read(); m=read();
	F(i,1,n){
		F(j,1,m){
			a[(i-1)*m+j]=read();
			p[(i-1)*m+j]=(i-1)*m+j;
			b[(i-1)*m+j]=0;
		}
	}
	sort(p+1,p+n*m+1,cmp);
	F(i,1,n*m){
		int y=(p[i]-1)%m+1,x=(p[i]-y)/m+1;
		if (b[p[i]]) continue;
		int par=(x+y)&1;
		if (par^(a[p[i]]&1)) continue;
		F(j,0,3){
			int tx=x+dx[j],ty=y+dy[j];
			if (tx && ty && tx<=n && ty<=m){
				int o=(tx-1)*m+ty;
//					cout<<p[i]<<" "<<(tx-1)*m+ty<<" "<<a[p[i]]<<" "<<a[o]<<"   fuck\n";

				if (a[o]==a[p[i]]){
					a[p[i]]++;
					b[p[i]]=1;
					break;
				}
			}
		}
	}
	F(i,1,n){
		F(j,1,m){
			cout<<a[(i-1)*m+j]<<" ";
		}
		cout<<"\n";
	}
}
int main(){
	int T=read(); srand(time(0));
	while (T--){
		 solve();
	}
    return 0;
}
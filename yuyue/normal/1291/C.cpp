#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=3e5+10;
int a[M];
bool f[M],g[M];
int st[M][20];
int lg[M];
int q(int l, int r){
    int k =lg[r-l+1];
    return min(st[l][k],st[r - (1 << k) + 1][k]);
}
void init(int n)
{
    for (int i = 1; i <=n; i++)
        st[i][0] = a[i];

    for (int j = 1; (1 << j) <= n; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <=n; i++)
            st[i][j] = min(st[i][j - 1],st[i + (1 << (j - 1))][j - 1]);
    }
}
int main(){
	int T=read();
	F(i,2,1e5) lg[i]=lg[i>>1]+1;
	while (T--){
		int n=read(),m=read(),k=read();
		F(i,1,n) a[i]=read();
		init(n);
		int ans=0;
		if (k>=m-1){
			F(i,1,m){
				ans=max(ans,max(a[i],a[n-i+1]));
			}
			cout<<ans<<"\n";
			continue;
		}
		F(i,0,k){
			int l=i+1,r=n-(k-i),len=m-k-1;
			int tmp=2e9;
//			cout<<l<<" "<<r<<" "<<len<<"   gg\n";
			F(j,0,len){
//				cout<<max(a[l+j],a[r-(len-j)])<<"   jj\n";
				tmp=min(tmp,max(a[l+j],a[r-(len-j)]));
//				ans=max(ans,min(q(l,l+len),q(r-len,r)));
			}
			ans=max(ans,tmp);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
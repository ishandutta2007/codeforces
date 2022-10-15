#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=107;
struct seg{
    int a,l;
    bool operator <(const seg &q) const {return a<q.a;}
}b[N];
int n,f[N][N][2];
int main(){
#ifndef ONLINE_JUDGE
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
#endif
    n=read();
    for(int i=1;i<=n;i++)b[i].a=read(),b[i].l=read();
    sort(b+1,b+n+1),b[0].l=-2e8;int ans=0;
    for(int i=0;i<=n;i++)
	for(int j=0;j<=i;j++)
	    for(int p=0;p<2;p++){
		ans=max(ans,f[i][j][p]);
		int o=b[j].a+p*b[j].l,mx=-1e8,x=0,y=0;
		for(int k=i+1;k<=n;k++)
		    for(int q=0;q<2;q++){
			int t=b[k].a+q*b[k].l;
			if(t>mx)mx=t,x=k,y=q;
			f[k][x][y]=max(f[k][x][y],f[i][j][p]+min(b[k].l,t-o)+mx-t);
		    }
	    }
    printf("%d\n",ans);
    return 0;
}
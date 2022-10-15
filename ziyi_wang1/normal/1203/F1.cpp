#include<bits/stdc++.h>
using namespace std;
#define re register int
#define Fr(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
#define I inline void
#define IN inline int
typedef long long ll;
I read(int &res){
    re g=1;register char ch=getchar();res=0;
    while(!isdigit(ch)){
        if(ch=='-')g=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        res=(res<<3)+(res<<1)+(ch^48);
        ch=getchar();
    }
    res*=g;
}
typedef pair<int,int>pii;
pii f[110],g[110];
int n,m,a[110],b[110],tot,sum;
int main(){
	read(n);read(m);
	Fr(i,1,n){
		read(a[i]);read(b[i]);
		if(b[i]>=0){
			f[++tot].first=a[i];f[tot].second=b[i];
		}
		else {
			g[++sum].first=max(a[i],-b[i])+b[i];
			g[sum].second=b[i];
		}
	}
	sort(f+1,f+1+tot);
	sort(g+1,g+1+sum);
	Fr(i,1,tot){
		if(m<f[i].first){
			cout<<"NO";
			return 0;
		}
		m+=f[i].second;
	}
	FOR(i,sum,1){
		if(m<g[i].first-g[i].second){
			cout<<"NO";
			return 0;
		}
		m+=g[i].second;
	}
	cout<<"YES";
    return 0;
}
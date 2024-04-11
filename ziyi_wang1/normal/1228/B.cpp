#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
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
int n,m,a[1010],b[1010],f[1010][1010],sn,ans;
const int E=1e9+7;
int main(){
	read(n);read(m);
	memset(f,-1,sizeof(f));
	F(i,1,n){
		read(a[i]);
		F(j,1,a[i]){
			if(!f[i][j])sn=1;
			f[i][j]=1;
		}
		if(f[i][a[i]+1]==1)sn=1;
		f[i][a[i]+1]=0;
	}
	F(i,1,m){
		read(b[i]);
		F(j,1,b[i]){
			if(!f[j][i])sn=1;
			f[j][i]=1;
		}
		if(f[b[i]+1][i]==1)sn=1;
		f[b[i]+1][i]=0;
	}
	if(sn){
		cout<<"0";
		return 0;
	}
	ans=1;
	F(i,1,n){
		F(j,1,m){
			if(f[i][j]==-1)ans=(ans<<1)%E;
		}
	}
	cout<<ans;
    return 0;
}
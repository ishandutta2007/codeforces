#include<bits/stdc++.h>
using namespace std;
#define re register ll
#define F(x,y,z) for(re x=y;x<=z;x++)
#define I inline void
#define IN inline ll
typedef long long ll;
I read(ll &res){
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
ll n,m,a[101000],b[101000],f[101000][3],ans;
IN Max(ll x,ll y){
	return x>y?x:y;
}
int main(){
	read(n);
	F(i,1,n){
		read(a[i]);
	}
	F(i,1,n){
		read(b[i]);
	}
	f[1][0]=0;f[1][1]=a[1];f[1][2]=b[1];
	F(i,2,n){
		f[i][0]=Max(Max(f[i-1][0],f[i-1][1]),f[i-1][2]);
		f[i][1]=Max(f[i-1][0],f[i-1][2])+a[i];
		f[i][2]=Max(f[i-1][0],f[i-1][1])+b[i];
	}
	ans=Max(Max(f[n][0],f[n][1]),f[n][2]);
	cout<<ans;
    return 0;
}
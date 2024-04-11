#include<bits/stdc++.h>
using namespace std;
#define re register ll
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
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
ll n,m,T,a[110],f[3000],sn;

int main(){
	read(T);
	while(T--){
		read(n);
		memset(f,0,sizeof(f));
		F(i,1,n){
			read(a[i]);
			if(a[i]<=2048)f[a[i]]++;
		}
		F(i,0,10){
			f[1<<(i+1)]+=(f[1<<i]>>1);
		}
		if(f[2048])cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define re register ll
#define I inline void
typedef long long ll;
I rea(ll &res){
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
ll n,m,T,p;
int main(){
	rea(T);
	while(T--){
		rea(n);rea(m);
		printf("%I64d\n",m<<1);
	}
    return 0;
}
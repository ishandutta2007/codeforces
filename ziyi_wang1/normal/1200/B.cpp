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
	res=(res<<3)+(res<<1)+(ch^48);;
	ch=getchar();
	}
	res*=g;
}
int n,m,k,T,h[110],sn;
int main(){
    read(T);
    while(T--){
        read(n);read(m);read(k);sn=0;
        Fr(i,1,n){
            read(h[i]);
        }
        Fr(i,1,n-1){
                m+=min((h[i]-h[i+1]+k),h[i]);
                if(m<0){
                    sn=1;
                    break;
                }
        }
        if(sn)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
	return 0;
}
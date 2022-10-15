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
int n,m,a[10],s;
int main(){
	read(n);read(m);
	F(i,n,m){
		memset(a,0,sizeof(a));
		s=i;
		while(s){
			a[s%10]++;
			s/=10;
		}
		s=1;
		F(i,0,9){
			if(a[i]>1)s=0;
		}
		if(s){
			cout<<i;
			return 0;
		}
	}
	cout<<"-1";
    return 0;
}
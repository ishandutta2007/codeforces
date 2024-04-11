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
struct P{
	ll w,id;
	friend bool operator < (P x,P y){
		return x.w>y.w;
	}
}a[202000];
ll n,m,pos,lft,rgt;
int main(){
	read(n);
	F(i,1,n){
		read(a[i].w);a[i].id=i;
	}
	sort(a+1,a+1+n);
	pos=lft=rgt=a[1].id;
	F(i,2,n){
		if(a[i].id<pos){
			if(a[i].id>lft){
				printf("NO");
				return 0;
			}
			lft=a[i].id;
		}
		else{
			if(a[i].id<rgt){
				printf("NO");
				return 0;
			}
			rgt=a[i].id;
		}
	}
	printf("YES");
    return 0;
}
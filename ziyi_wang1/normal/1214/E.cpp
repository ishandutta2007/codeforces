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
struct P{
	int w,l,r;
	friend bool operator < (P x,P y){
		return x.w>y.w;
	}
}p[101000];
int n,m,f[202000],pos,tot;
int main(){
	read(n);
	F(i,1,n){
		read(p[i].w);p[i].l=(i<<1)-1;p[i].r=p[i].l+1;
	}
	sort(p+1,p+1+n);
	F(i,1,n){
		f[i]=p[i].l;
	}
	tot=n;
	F(i,1,n){
		if(i>p[i].w)pos=i-p[i].w+1;
		else pos=i+p[i].w-1;
		if(pos==tot){
			f[++tot]=p[i].r;
		}
		else cout<<p[i].r<<" "<<f[pos]<<endl;
	}
	F(i,1,tot-1){
		cout<<f[i]<<" "<<f[i+1]<<endl;
	}
    return 0;
}
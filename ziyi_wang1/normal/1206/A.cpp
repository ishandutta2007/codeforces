#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define I inline void
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
int n,m,a[1000],b[1010],maxa,maxb;
int main(){
	read(n);maxa=maxb=0;
	F(i,1,n){
		read(a[i]);
		maxa=max(maxa,a[i]);
	}
	read(m);
	F(i,1,m){
		read(b[i]);
		maxb=max(maxb,b[i]);
	}
	cout<<maxa<<" "<<maxb;
    return 0;
}
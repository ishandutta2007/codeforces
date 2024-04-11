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
priority_queue<int>q;
int n,m,a[1010],s[1010],p,ans=0;
int main(){
read(n);read(m);
F(i,1,n){
	read(a[i]);
	s[a[i]]++;
}
F(i,1,m){
	q.push(s[i]);
}
F(i,1,(n+1)>>1){
	p=q.top();
	q.pop();
	if(p>=2)ans+=2,p-=2;
	else ans+=p,p=0;
	q.push(p);
}
cout<<ans;
    return 0;
}
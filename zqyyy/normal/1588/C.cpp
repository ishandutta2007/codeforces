#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
#define fi first
#define se second
int n;
inline void work(){
    n=read();map<ll,int>h;h[0]=1;
    ll sum=0,ans=0;
    for(int i=1;i<=n;i++){
	sum=read()-sum;
	if(i&1){
	    while(!h.empty() && h.rbegin()->fi>sum)h.erase(h.rbegin()->fi);
	    ans+=h[sum]++;
	}else{
	    while(!h.empty() && (-h.begin()->fi)>sum)h.erase(h.begin()->fi);
	    ans+=h[-sum]++;
	}
    }
    printf("%lld\n",ans);
}
int main(){
    int test=read();
    while(test--)work();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
#define fi first
#define se second
const int N=2e5+7;
int n,a[N];
vector<pair<int,int> >ans;
inline void op(int i,int j){
    assert(i!=j);
    ans.push_back({i,j}),a[i]=(a[i]+a[j]-1)/a[j];
}
inline void out(){
    printf("%lu\n",ans.size());
    for(auto x:ans)printf("%d %d\n",x.fi,x.se);
}
inline void work(){
    n=read(),ans.clear();
    for(int i=1;i<=n;i++)a[i]=i;
    int t=ceil(sqrt(n));
    while(n>2){
	for(int i=t+1;i<n;i++)op(i,n);
	op(n,t),op(n,t);
	n=t,t=ceil(sqrt(n));
    }
    out();
}
int main(){
    int T=read();
    while(T--)work();
    return 0;
}
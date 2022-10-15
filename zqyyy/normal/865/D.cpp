#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
int n;
priority_queue<int>q;
int main(){
    n=read();ll ans=0;
    for(int i=1;i<=n;i++){
	int v=read();q.push(-v);
	if(!q.empty() && v+q.top()>0)ans+=v+q.top(),q.pop(),q.push(-v);
    }
    printf("%lld\n",ans);
    return 0;
}
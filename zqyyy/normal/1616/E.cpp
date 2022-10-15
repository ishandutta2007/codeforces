#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
    ll f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=2e5+7;
char s[N],tmp[N],t[N];
vector<int>pos[26];
int n;
struct b1t{
    int c[N];
    inline void clear(){for(int i=1;i<=n;i++)c[i]=0;}
    inline void add(int p,int x){for(;p;p^=p&-p)c[p]+=x;}
    inline int ask(int p){int res=0;for(;p<=n;p+=p&-p)res+=c[p];return res;}
}T;
inline void work(){
    n=read(),scanf("%s%s",s+1,t+1);
    for(int i=1;i<=n;i++)tmp[i]=s[i];
    sort(tmp+1,tmp+n+1);bool ok=0;
    for(int i=1;i<=n && !ok;i++){
	if(tmp[i]>t[i]){puts("-1");return;}
	if(tmp[i]<t[i])ok=1;
    }
    if(!ok){puts("-1");return;}
    T.clear();
    for(int i=0;i<26;i++)pos[i].clear();
    for(int i=n;i;i--)pos[s[i]-'a'].push_back(i);
    ll ans=1e18,sum=0;
    for(int i=1;i<=n;i++){
	int c=t[i]-'a';
	for(int j=0;j<c;j++)
	    if(!pos[j].empty())ans=min(ans,sum+pos[j].back()+T.ask(pos[j].back())-i);
	if(pos[c].empty())break;
	int x=pos[c].back();pos[c].pop_back(),sum+=x+T.ask(x)-i,T.add(x,1);
    }
    printf("%lld\n",ans);
}
int main(){
    int test=read();
    while(test--)work();
    return 0;
}
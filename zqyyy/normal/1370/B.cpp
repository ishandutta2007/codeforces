#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=1007;
int n,a[N];
vector<int>v[2];
inline void work(){
    scanf("%d",&n),v[0].clear(),v[1].clear();
    for(int i=1;i<=n+n;i++)v[read()&1].push_back(i);
    if(v[0].size()&1)v[0].pop_back(),v[1].pop_back();
    else if(v[0].size()>1)v[0].pop_back(),v[0].pop_back();
    else v[1].pop_back(),v[1].pop_back();
    for(int i=0;i<v[0].size();i+=2)printf("%d %d\n",v[0][i],v[0][i+1]);
    for(int i=0;i<v[1].size();i+=2)printf("%d %d\n",v[1][i],v[1][i+1]);
}
int main(){
    int test;scanf("%d",&test);
    while(test--)work();
    return 0;
}
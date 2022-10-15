#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=2e5+7;
vector<int>G[N];
int n,cnt[2];
void dfs(int x,int fa,int col){
    cnt[col]++;
    for(int y:G[x])if(y^fa)dfs(y,x,!col);
}
int main(){
    n=read();
    for(int i=1;i<n;i++){
	int x=read(),y=read();
	G[x].push_back(y),G[y].push_back(x);
    }
    dfs(1,0,0);
    printf("%d\n",min(cnt[0],cnt[1])-1);
    return 0;
}
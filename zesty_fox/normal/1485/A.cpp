#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
inline int solve(int a,int b){
    if(b==1)return 1e9;
    int ans=0;
    while(a)a/=b,ans++;
    return ans;
}
inline void work(){
    int a=read(),b=read(),ans=1e9;
    for(int i=0;i<=100;i++)ans=min(ans,solve(a,i+b)+i);
    printf("%d\n",ans);
}
int main(){
    /*
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    */
    int test=read();
    while(test--)work();
    return 0;
}
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
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int n,a[N],b[40];
inline void work(){
    n=read();
    for(int i=0;i<30;i++)b[i]=0;
    for(int i=1;i<=n;i++){
	int x=read();
	for(int j=29;~j;j--)
	    if(x>>j&1)b[j]++;
    }
    int ans=0;
    for(int i=0;i<30;i++)ans=gcd(ans,b[i]);
    for(int i=1;i<=n;i++)if(ans%i==0)printf("%d ",i);
    puts("");
}
int main(){
//    freopen("1.in","r",stdin);
//    freopen("1.out","w",stdout);
    int test=read();
    while(test--)work();
    return 0;
}
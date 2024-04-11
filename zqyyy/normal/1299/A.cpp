#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=1e5+7;
int n,a[N];
int main(){
    n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+n+1);
    for(int j=29;~j;j--){
	int cnt=0,pos=0;
	for(int i=1;i<=n;i++)
	    if(a[i]>>j&1)cnt++,pos=i;
	if(cnt==1){swap(a[1],a[pos]);break;}
    }
    for(int i=1;i<=n;i++)printf("%d ",a[i]);
    return 0;
}
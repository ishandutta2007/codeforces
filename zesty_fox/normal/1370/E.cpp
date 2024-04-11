#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=1e6+7;
int n,m,a[N],b[N],res[2];
char s[N],t[N];
int main(){
    n=read(),scanf("%s",s+1),scanf("%s",t+1);
    for(int i=1;i<=n;i++){
	int x=s[i]-t[i];
	if(x)a[++m]=x;
    }
    int sum=0,ans=0,ne=0;
    for(int i=1;i<=m;i++){
	sum+=a[i];
	if(sum>0 && ne)ne=0;
	else if(sum<0 && !ne)ne=1;
	res[ne]=max(res[ne],abs(sum));
    }
    ans=res[0]+res[1];
    if(sum)ans=-1;
    printf("%d\n",ans);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=150007,inf=0x3f3f3f3f;
int n[5],id[N],a[N][5],f[N][5];
map<int,bool>h[N][5];
int main(){
    for(int i=1;i<=4;i++)n[i]=read();
    for(int i=1;i<=4;i++)
	for(int j=1;j<=n[i];j++)a[j][i]=read();
    for(int i=2;i<=4;i++){
	int m=read();
	while(m--){
	    int x=read(),y=read();
	    h[y][i][x]=1;
	}
    }
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n[1];i++)f[i][1]=a[i][1];
    for(int i=2;i<=4;i++){
	for(int j=1;j<=n[i-1];j++)id[j]=j;
	sort(id+1,id+n[i-1]+1,[&](int x,int y){return f[x][i-1]<f[y][i-1];});
	for(int j=1;j<=n[i];j++){
	    int p=1;
	    while(h[j][i][id[p]] && p<=n[i-1])p++;
	    if(p<=n[i-1])f[j][i]=min(f[j][i],f[id[p]][i-1]+a[j][i]);
	}
    }
    int ans=inf;
    for(int i=1;i<=n[4];i++)ans=min(ans,f[i][4]);
    if(ans==inf)ans=-1;
    printf("%d\n",ans);
    return 0;
}
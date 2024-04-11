#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=707,mod=1e9+7;
inline void add(int &x,int y){x+=y;if(x>=mod)x-=mod;}
int n,f[N][N][11][2];
char s[N];
int main(){
    scanf("%s",s+1),n=strlen(s+1);
    for(int i=1;i<=9;i++)f[0][0][i][1]=1;
    for(int i=1;i<=n;i++)
	for(int j=0;j<=i;j++)
	    for(int k=1;k<=9;k++)
		for(int l=0;l<2;l++)
		    for(int o=0,lim=l?s[i]-'0':9;o<=lim;o++)
			add(f[i][j+(o>=k)][k][l && o==lim],f[i-1][j][k][l]);
    int ans=0;
    for(int k=1;k<=9;k++)
	for(int j=1,v=1;j<=n;j++,v=(10ll*v+1)%mod)
	    add(ans,1ll*v*(f[n][j][k][0]+f[n][j][k][1])%mod);
    printf("%d\n",ans);
    return 0;
}
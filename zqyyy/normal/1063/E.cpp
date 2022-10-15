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
int n,p[N];
char s[N][N];
bool vis[N];
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	n=read();bool fl=1;
	for(int i=1;i<=n;i++)p[i]=read(),fl&=p[i]==i,fill(s[i]+1,s[i]+n+1,'.');
	printf("%d\n",n-(!fl));
	if(!fl){
		int c=1;
		for(int i=1;i<=n;i++)
			if(!vis[i] && p[i]!=i){
				vector<int>vec;int x=i;
				while(!vis[x])vis[x]=1,vec.push_back(x),x=p[x];
				vec.push_back(i);
				int lst=c;c++;
				for(int j=1;j<(int)vec.size()-1;j++){
					int x=vec[j],y=vec[j+1];
					s[c][x]=s[c][y]=x<y?'/':'\\',c++;
				}
				if(i!=1){
					s[lst][vec[1]]=s[lst][1]='/';
					s[c-1][1]='\\';
				}
			}
	}
	for(int i=1;i<=n;i++,puts(""))
		for(int j=1;j<=n;j++)putchar(s[i][j]);
	return 0;
}
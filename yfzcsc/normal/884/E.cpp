#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
unsigned short f[33000];
char s[5000],t[20000];
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
void uni(int x,int to){
//	printf("[%d(%d),%d(%d)]",x,find(x),to,find(to));
	if(find(x)==find(to))return ;
	ans--;
	f[find(x)]=find(to);
}
int main(){
	scanf("%d%d",&n,&m);
//	n=4096,m=16384;
	for(int i=1;i<=n;++i){
		scanf("%s",s+1);
//		for(int j=1;j<=m/4;++j)s[j]='F';
		for(int j=1;j<=m/4;++j){
			int k=(s[j]<='9'&&s[j]>='0'?s[j]-'0':s[j]-'A'+10);
			for(int l=0;l<4;++l)
				t[(j-1)*4+4-l]=(k>>l&1),ans+=t[(j-1)*4+4-l];
		}
//		for(int j=1;j<=m;++j)putchar('0'+t[j]);puts("");
		for(int j=1;j<=m;++j)
			if(t[j]==1)f[j+m]=j+m;
			else f[j+m]=0;
		for(int j=1;j<=m;++j)if(t[j]){
			if(f[j])uni(j,j+m);
			if(t[j-1])uni(j+m-1,j+m);
		}
		for(int j=1;j<=m;++j)
			if(t[j]==1)f[j]=find(j+m)-m;//,printf("[%d,%d]",f[j],f[j+m]);
			else f[j]=0;
	}
	printf("%d",ans);
}
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
const string s[6]={"####","....","\\#.\\",".//#","\\.#\\","#//."};
int n,m,a,b,c,x,y,tx,ty,ans[120][120],i,j;
void next(){
	y++;
	if(y>m)y-=m,x++;
}
int main(){
	scanf("%d%d%d%d%d",&n,&m,&a,&b,&c);
	x=y=1;
	for(i=1;i<=a;++i,next())ans[x][y]=0;
	for(tx=x,ty=y,i=1;i<=m;++i,next()){
		if(x==tx)ans[x][y]=(y-ty)&1?2:5;
		else ans[x][y]=(y-ty)&1?5:2;
	}
	for(i=1;i<=b;++i,next())ans[x][y]=1;
	for(tx=x,ty=y,i=1;i<=c-m;++i,next()){
		if(y>=ty){
			ans[x][y]=(y-ty)&1?2:1;
			if(x-tx&1)ans[x][y]^=2;
		}else{
			ans[x][y]=(y-ty)&1?1:2;
			if(x-tx-1&1)ans[x][y]^=2;
		}
		ans[x][y]+=2;
	}
	for(i=2;i<=n*2+1;++i){
		for(j=2;j<=m*2+1;++j)printf("%c",s[ans[i/2][j/2]][(i&1)<<1 | (j&1)]);
		puts("");
	}
}
#include<bits/stdc++.h>
const int N=55,f1[4]={1,0,-1,0},f2[4]={0,1,0,-1};
char c[N][N],o[105];
int n,m,i,j,k,l,x,y,a[105],p,len,ans;
bool dfs(int x,int y,int d){
	if(c[x][y]=='E')
		return 1;
	if(d>len)return 0;
	//if(d>len)return c[x][y]=='E';
	int nx=x+f1[a[d]],ny=y+f2[a[d]];
	if(c[nx][ny]=='#')return 0;
	return dfs(nx,ny,d+1);
}
int main(){
	scanf("%d%d",&n,&m);memset(c,'#',sizeof c);
	for(i=1;i<=n;++i){
		scanf("%s",c[i]+1);c[i][m+1]='#';
		for(j=1;j<=m;++j)if(c[i][j]=='S')x=i,y=j;
	}
	scanf("%s",o+1);len=strlen(o+1);
	for(i=0;i<4;++i)
		for(j=0;j<4;++j)
			for(k=0;k<4;++k)
				for(l=0;l<4;++l)
					if(i!=j && i!=k && i!=l && j!=k && j!=l && k!=l){
						for(p=1;p<=len;++p){
							if(o[p]=='0')a[p]=i;
							if(o[p]=='1')a[p]=j;
							if(o[p]=='2')a[p]=k;
							if(o[p]=='3')a[p]=l;
						}
						if(l==1 && k==2 && j==3 && i==0){
							++i,--i;
						}
						ans+=dfs(x,y,1);
					}
	return printf("%d\n",ans),0;
}
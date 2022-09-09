#include<bits/stdc++.h>
using namespace std;
int n,k,i,j,a[4][55],x,y,xx,yy,nx[4][55],ny[4][55],cnt;
vector<vector<int>>ans;
void E(){puts("-1");exit(0);}
bool ck(int x,int y){
	if(!a[x][y])return 1;
	bool ret;
	if(x==1){
		if(a[0][y]==a[1][y])ret=1,ans.push_back({a[1][y],1,y}),++cnt,a[1][y]=0;
			else ret=0;
	}else{
		if(a[3][y]==a[2][y])ret=1,ans.push_back({a[2][y],4,y}),++cnt,a[2][y]=0;
			else ret=0;
	}
	return ret;
}
int main(){
	scanf("%d%d",&n,&k);
	for(i=0;i<4;++i)for(j=1;j<=n;++j)scanf("%d",a[i]+j);
	if(k==n*2){
		for(i=1;i<=n;++i){
			if(a[2][i]==a[3][i]){ans.push_back({a[2][i],4,i});a[2][i]=0;break;}
			if(a[1][i]==a[0][i]){ans.push_back({a[1][i],1,i});a[1][i]=0;break;}
		}
		++cnt;
		if(i>n)E();
	}
	for(i=1;i<3;++i)for(j=1;j<=n;++j)if(!a[i][j])x=i,y=j;
	for(i=1;i<n;++i)nx[1][i]=1,ny[1][i]=i+1;nx[1][n]=2;ny[1][n]=n;
	for(i=n;i>1;--i)nx[2][i]=2,ny[2][i]=i-1;nx[2][1]=1;ny[2][1]=1;
	xx=x;yy=y;
	for(;cnt<k;){
		for(i=1;i<=n*2;++i){
			int xxx=nx[xx][yy],yyy=ny[xx][yy];
			if(!ck(xxx,yyy)){
				ans.push_back({a[xxx][yyy],xx+1,yy});
				a[xx][yy]=a[xxx][yyy];a[xxx][yyy]=0;
			}
			xx=xxx;yy=yyy;
		}
	}
	printf("%d\n",int(ans.size()));
	for(auto u:ans)printf("%d %d %d\n",u[0],u[1],u[2]);
	return 0;
}
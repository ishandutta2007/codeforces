#include<stdio.h>
char mp[502][502];
int f[502][502][502],n,m,k;
inline int Max(int p,int q){return p>q?p:q;}
bool check(int x,int y,int r){
	for(int i=x-r+1;i<=x;i++)if(mp[i][y-r+1]!='R'||mp[i][y+r]!='G')return 0;
	for(int i=x+r;i>x;i--)if(mp[i][y-r+1]!='Y'||mp[i][y+r]!='B')return 0;
	for(int i=y-r+1;i<=y;i++)if(mp[x-r+1][i]!='R'||mp[x+r][i]!='Y')return 0;
	for(int i=y+r;i>y;i--)if(mp[x-r+1][i]!='G'||mp[x+r][i]!='B')return 0;
	return 1;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)scanf("%s",&mp[i][1]);
	for(int i=1;i<n;i++)
		for(int j=1;j<m;j++)
			for(int k=1;check(i,j,k);k++)
				f[i-k+1][j-k+1][k*2]=k*2;
	for(int r=3;r<=n;r++)
		for(int i=1;i<=n-r+1;i++)
			for(int j=1;j<=m-r+1;j++)
			f[i][j][r]=Max(f[i][j][r],Max(Max(f[i][j][r-1],f[i+1][j+1][r-1]),Max(f[i+1][j][r-1],f[i][j+1][r-1])));
	while(k--){
		int a1,b1,a2,b2;
		scanf("%d%d%d%d",&a1,&b1,&a2,&b2);
		if(a2-a1<=b2-b1){
			int r=a2-a1+1,ans=0;
			for(int i=b1;i<=b2-r+1;i++)ans=Max(ans,f[a1][i][r]);
			printf("%d\n",ans*ans);
		}else{
			int r=b2-b1+1,ans=0;
			for(int i=a1;i<=a2-r+1;i++)ans=Max(ans,f[i][b1][r]);
			printf("%d\n",ans*ans);
		}
	}
}
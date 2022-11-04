#include<bits/stdc++.h>
#define For(i,j,k) for (int i=j;i<=k;i++)
using namespace std;
const int N=666;
int a[N][N],fa[N*N];
int id[N][N],reid[N*N];
int n,m,mo;
char s[N][N];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int Det(int n){
	int ans=1;
	For(i,1,n) For(j,1,n)
		a[i][j]=(a[i][j]+mo)%mo;
	For(i,1,n){
		if (!a[i][i]){
			For(j,i+1,n) if (a[j][i]){
				For(k,i,n) swap(a[i][k],a[j][k]);
				ans=mo-ans;
			}
		}
		if (!a[i][i]) return 0;
		ans=1ll*ans*a[i][i]%mo;
		For(j,i+1,n+1){
			int t=1ll*a[j][i]*power(a[i][i],mo-2)%mo;
			For(k,i,n+1) a[j][k]=(a[j][k]+mo-1ll*t*a[i][k]%mo)%mo;
		}
	}
	return ans;
}
int get(int x){
	return fa[x]==x?x:fa[x]=get(fa[x]);
}
int uni(int x,int y){
	x=get(x); y=get(y);
	if (x!=y) return fa[x]=y,1;
	return 0;
}
void adde(int x,int y){
	x=reid[get(x)];
	y=reid[get(y)];
	a[x][x]++; a[y][y]++;
	a[x][y]--; a[y][x]--;
}
int solve(int fl){
	int num=0;
	For(i,0,n) For(j,0,m)
		if ((i+j+fl)%2==0) id[i][j]=++num;
	For(i,1,num) fa[i]=i;
	For(i,1,n) For(j,1,m){
		char wzp=((i+j+fl)%2?'/':'\\');
		if (s[i][j]!=wzp) continue;
		if (wzp=='/'){
			if (!uni(id[i-1][j],id[i][j-1])) return 0;
		}
		else{
			if (!uni(id[i-1][j-1],id[i][j])) return 0;
		}
	}
	int c=0;
	For(i,1,num)
		if (get(i)==i) reid[i]=++c;
	memset(a,0,sizeof(a));
	For(i,1,n) For(j,1,m) if (s[i][j]=='*')
		if ((i+j+fl)%2==1) adde(id[i-1][j],id[i][j-1]);
		else adde(id[i-1][j-1],id[i][j]);
	return Det(c-1);
}
int main(){
	scanf("%d%d%d",&n,&m,&mo);
	For(i,1,n) scanf("%s",s[i]+1);
	printf("%d",(solve(0)+solve(1))%mo);
}
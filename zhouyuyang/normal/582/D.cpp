#include<bits/stdc++.h>
#define For(i,j,k) for (int i=j;i<=k;i++)
using namespace std;
const int mo=1000000007;
const int N=3333;
void upd(int &x,int y){
	(x+=y)>=mo?x-=mo:233;
}
int s[N],f[2][N][2][2][2];
int n,p,q,num;
char A[N];
int main(){
	scanf("%d%d%s",&p,&q,A+1);
	int n=strlen(A+1);
	reverse(A+1,A+n+1);
	for (int i=1;i<=n;i++) A[i]-='0';
	for (;n;){
		long long x=0;
		for (int i=n;i;i--){
			x=x*10+A[i];
			A[i]=x/p;
			x%=p;
		}
		s[++num]=x;
		for (;n&&A[n]==0;n--);
	}
	f[0][0][0][0][0]=1;
	int now=1,pre=0;
	For(i,1,num){
		For(j,0,i-1) For(k,0,1)
			For(l,0,1) For(S,0,1){
				if (!f[pre][j][k][l][S]) continue;
				int val=f[pre][j][k][l][S];
				f[pre][j][k][l][S]=0;
				For(F,0,2){
					int L,R,U,D,E;
					if (!F) L=0,R=s[i]-1;
					else if (F==1) L=R=s[i];
					else L=s[i]+1,R=p-1;
					if (L>R) continue;
					int EQL=R-L+1;
					int DN=1ll*(R-L+1)*(L+R)/2%mo;
					int UP=1ll*(R-L+1)*((p-1-R)+(p-1-L))/2%mo;
					int newk=(F==2)||(k&&F==1);
					upd(f[now][j][newk][0][0],1ll*val*DN%mo);
					upd(f[now][j+S][newk][l][S],1ll*val*EQL%mo);
					upd(f[now][j+1][newk][1][1],1ll*val*UP%mo);
				}
			}
		swap(now,pre);
	}
	int ans=0;
	For(j,q,num) For(k,0,2)
		upd(ans,f[pre][j][0][0][k]);
	printf("%d",ans);
}
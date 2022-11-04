#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
 
#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define EB emplace_back
#define fi first
#define se second
 
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
 
#define inf 2000000000
#define sqr(x) ((x)*(x))
using namespace std;
const int N=2505;
int a[N][N];
int v1[N][N][8];
int v2[N][N][8];
int n,m,k;
ll ans;
void divide(int L,int R,int D,int U){
	if (L==R&&D==U){
		if (k==a[L][D]+1) ans++;
		return;
	}
	if (R-L+1>U-D+1){
		int mid=(L+R)/2;
		For(j,D,U){
			int tp1=0,tp2=0;
			Rep(i,mid,L) if (a[i][j]){
				v1[j][j][++tp1]=i;
				if (tp1>=::k) break;
			}
			For(i,mid+1,R) if (a[i][j]){
				v2[j][j][++tp2]=i;
				if (tp2>=::k) break;
			}
			for (;tp1<::k;) v1[j][j][++tp1]=L-1;
			for (;tp2<::k;) v2[j][j][++tp2]=R+1;
		}
		For(j,D,U) For(k,j+1,U){
			int i1=1,i2=1;
			For(id,1,::k)
				if (v1[j][k-1][i1]>v1[k][k][i2])
					v1[j][k][id]=v1[j][k-1][i1++];
				else v1[j][k][id]=v1[k][k][i2++];
			i1=1,i2=1;
			For(id,1,::k)
				if (v2[j][k-1][i1]<v2[k][k][i2])
					v2[j][k][id]=v2[j][k-1][i1++];
				else v2[j][k][id]=v2[k][k][i2++];
		}
		For(j,D,U) For(k,j,U) For(id,1,::k)
			ans+=max((id==1?mid:v1[j][k][id-1])-v1[j][k][id],0)*
				 max(v2[j][k][::k-(id-1)]-(id!=::k?v2[j][k][::k-(id-1)-1]:mid+1),0);
		divide(L,mid,D,U);
		divide(mid+1,R,D,U);
	}
	else{
		int mid=(U+D)/2;
		For(i,L,R){
			int tp1=0,tp2=0;
			Rep(j,mid,D) if (a[i][j]){
				v1[i][i][++tp1]=j;
				if (tp1>=::k) break;
			}
			For(j,mid+1,U) if (a[i][j]){
				v2[i][i][++tp2]=j;
				if (tp2>=::k) break;
			}
			for (;tp1<::k;tp1++)
				v1[i][i][tp1+1]=D-1;
			for (;tp2<::k;tp2++)
				v2[i][i][tp2+1]=U+1;
		}
		For(j,L,R) For(k,j+1,R){
			int i1=1,i2=1;
			For(id,1,::k)
				if (v1[j][k-1][i1]>v1[k][k][i2])
					v1[j][k][id]=v1[j][k-1][i1++];
				else v1[j][k][id]=v1[k][k][i2++];
			i1=1,i2=1;
			For(id,1,::k)
				if (v2[j][k-1][i1]<v2[k][k][i2])
					v2[j][k][id]=v2[j][k-1][i1++];
				else v2[j][k][id]=v2[k][k][i2++];
		}
		For(j,L,R) For(k,j,R) For(id,1,::k)
			ans+=max((id==1?mid:v1[j][k][id-1])-v1[j][k][id],0)*
				 max(v2[j][k][::k-(id-1)]-(id!=::k?v2[j][k][::k-(id-1)-1]:mid+1),0);
		divide(L,R,D,mid);
		divide(L,R,mid+1,U);
	}
}
char s[N];
int main(){
	scanf("%d%d%d",&n,&m,&k); k++;
	for (int i=1;i<=n;i++){
		scanf("%s",s+1);
		for (int j=1;j<=m;j++)
			a[i][j]=s[j]-'0';
	}
	divide(1,n,1,m);
	printf("%lld\n",ans);
}
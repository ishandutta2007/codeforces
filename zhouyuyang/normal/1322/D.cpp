#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=5005;
int n,m,l[N],s[N],c[N];
int mx[N],top[N],ans;
int q[N][N],qq[N],f[N][N];
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%d",&l[i]);
	For(i,1,n) scanf("%d",&s[i]);
	For(i,1,n+m) scanf("%d",&c[i]);
	For(i,1,n) s[i]=c[l[i]]-s[i];
	int ans=0;//-(1<<30);
	memset(f,233,sizeof(f));
	For(i,1,n+m) f[i][0]=0;
	Rep(i,n,1){
		int L=l[i];
		Rep(j,mx[L],0){
			int val=f[L][j]+s[i],t=j+1;
			//cout<<L<<' '<<j<<' '<<t<<' '<<val<<endl;
			for (int p=L;t;){
				mx[p]=max(mx[p],t);
				f[p][t]=max(f[p][t],val);
				p++; t/=2; val+=c[p]*t;
			}
			ans=max(ans,val);
		}
		For(j,1,n+m) f[j][0]=max(f[j][0],max(f[j-1][0],f[j-1][1]));
		/*q[L][++top[L]]=s[i]; ++mx[L];
		sort(q[L]+1,q[L]+top[L]+1,greater<int>());
		Rep(j,mx[L]-1,0) f[L][j+1]=max(f[L][j+1],f[L][j]+s[i]);
		For(j,L+1,n+m){
			int p1=0,p2=0,l1=mx[j-1]/2,l2=top[j];
			For(k,0,l1) qq[k]=0;
			For(k,0,mx[L-1]) qq[k/2]=max(qq[k/2],f[j-1][k]);
			For(k,0,l1) qq[k]+=1ll*c[j]*k;
			int S=qq[0];
			for (;p1<=l1||p2<=l2;){
				f[j][p1+p2]=S;
				if (p1==l1&&p2==l2) break;
				if (p2==l2||(p1<l1&&qq[p1+1]-qq[p1]>q[j][p2+1]))
					S+=qq[p1+1]-qq[p1],++p1;
				else S+=q[j][++p2];
			}
			mx[j]=l1+l2;
			//cout<<"len "<<i<<' '<<j<<' '<<mx[j]<<' '<<f[j][0]<<' '<<f[j][1]<<endl;
		}*/
	}
	printf("%d\n",ans);
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=2507;
int n,m,K,s[N][N],u[8],d[8];
char ch[N][N];
inline int calc(int l1,int l2,int r1,int r2){
    if(l1>l2 || r1>r2)return 0;
    return s[l2][r2]-s[l1-1][r2]-s[l2][r1-1]+s[l1-1][r1-1];
}
ll ans;
void solve(int l1,int r1,int l2,int r2){
    if(l1>r1 || l2>r2)return;
    if(l1==r1 && l2==r2){ans+=ch[l1][l2]-'0'==K;return;}
    if(r1-l1>=r2-l2){
	int mid=(l1+r1)>>1;
	solve(l1,mid,l2,r2),solve(mid+1,r1,l2,r2);
	for(int l=l2;l<=r2;l++){
	    u[0]=mid+1,d[0]=mid;
	    for(int i=1;i<=K+1;i++)u[i]=l1,d[i]=r1;
	    for(int r=l;r<=r2;r++){
		for(int i=1;i<=K+1;i++){
		    while(calc(u[i],mid,l,r)>=i)u[i]++;
		    while(calc(mid+1,d[i],l,r)>=i)d[i]--;
		}
		for(int i=0;i<=K;i++)ans+=1ll*(u[i]-u[i+1])*(d[K-i+1]-d[K-i]);
	    }
	}
    }else{
	int mid=(l2+r2)>>1;
	solve(l1,r1,l2,mid),solve(l1,r1,mid+1,r2);
	for(int l=l1;l<=r1;l++){
	    u[0]=mid+1,d[0]=mid;
	    for(int i=1;i<=K+1;i++)u[i]=l2,d[i]=r2;
	    for(int r=l;r<=r1;r++){
		for(int i=1;i<=K+1;i++){
		    while(calc(l,r,u[i],mid)>=i)u[i]++;
		    while(calc(l,r,mid+1,d[i])>=i)d[i]--;
		}
		for(int i=0;i<=K;i++)ans+=1ll*(u[i]-u[i+1])*(d[K-i+1]-d[K-i]);
	    }
	}
    }
}
int main(){
    n=read(),m=read(),K=read();
    for(int i=1;i<=n;i++){
	scanf("%s",ch[i]+1);
	for(int j=1;j<=m;j++)
	    s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+ch[i][j]-'0';
    }
    solve(1,n,1,m);
    printf("%lld\n",ans);
    return 0;
}
#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
template<typename T> void read(T &num){
	char c=getchar();T f=1;num=0;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){num=(num<<3)+(num<<1)+(c^48);c=getchar();}
	num*=f;
}
template<typename T> void qwq(T x){
	if(x>9)qwq(x/10);
	putchar(x%10+'0');
}
template<typename T> void write(T x){
	if(x<0){x=-x;putchar('-');}
	qwq(x);putchar('\n');
}
template<typename T> void chkmax(T &x,T y){x=x>y?x:y;}
template<typename T> void chkmin(T &x,T y){x=x<y?x:y;}
int p[200010];int x[200010];
int A[800010];
struct wzy{
	int li,ri,pi;
}co[200010];
long long dif[800010];
int main(){
	int n,m;read(n);read(m);
	rep(i,1,n)read(p[i]);
	rep(i,1,m)read(x[i]);
	sort(x+1,x+m+1);
	
	int pos=0;int len=0;
	rep(i,1,n){
		while(pos<m&&x[pos+1]<=(i-1)*100)pos++;
		int dis=INT_MAX;
		if(pos)chkmin(dis,(i-1)*100-x[pos]);
		if(pos<m)chkmin(dis,x[pos+1]-(i-1)*100);
		
		A[++len]=2*((i-1)*100-dis);A[++len]=2*((i-1)*100-dis)+1;
		A[++len]=2*((i-1)*100+dis);A[++len]=2*((i-1)*100+dis)-1;
		co[i]={A[len-2],A[len],p[i]};
	}
	sort(A+1,A+len+1);len=unique(A+1,A+len+1)-A-1;
	rep(i,1,n){
		co[i].li=lower_bound(A+1,A+len+1,co[i].li)-A;
		co[i].ri=lower_bound(A+1,A+len+1,co[i].ri)-A;
		dif[co[i].li]+=co[i].pi;
		dif[co[i].ri+1]-=co[i].pi;
	}
	rep(i,1,len)dif[i]+=dif[i-1];
	long long ans=0;
	rep(i,1,len)chkmax(ans,dif[i]);
	write(ans);
	return 0;
}
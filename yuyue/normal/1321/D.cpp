#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=2e5+10,mod=998244353;
vector<int> v[M];
int dis[M],num[M];
int n,m,k;
int mi,mx,q[M*10],a[M];
int main(){
	n=read(); m=read();
	F(i,1,m){
		int x=read(),y=read();
		v[y].pb(x);
	}
	k=read();
	F(i,1,k) {
		a[i]=read();
	}
	int l,r; q[l=r=1]=a[k];
	ms(dis,1); dis[a[k]]=0; num[a[k]]=1;
	while (l<=r){
		int x=q[l++];
		F(i,0,SZ(v[x])){
			int y=v[x][i];
			if (dis[y]>dis[x]+1){
				dis[y]=dis[x]+1;
				num[y]=num[x];
				q[++r]=y;
			}
			else {
				if (dis[y]==dis[x]+1){
					num[y]+=num[x]; num[y]%=mod;
				}
			}
		}
	}
	F(i,1,k-1){
		if (dis[a[i+1]]==dis[a[i]]-1){
			if (num[a[i]]!=num[a[i+1]]) mx++;
		}
		else {
			mi++; mx++;
		}
	}
	cout<<mi<<" "<<mx<<"\n";
	return 0;
}
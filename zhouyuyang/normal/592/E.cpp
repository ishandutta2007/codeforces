#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=400006;

struct P{
	ll w,r;
	bool operator <(const P &a)const{
		return (w*a.w<0)^(r*a.w<a.r*w);
	}
	bool operator !=(const P &a)const{
		return w*a.r!=r*a.w;
	}
}s[N];

int n,c,d,m;
int p0,n0,pc,nc;
ll pt,nt,ans;
	
int main(){
	//ri*wj>rj*wi;
	//ri/wi>rj/wj;
	scanf("%d%d%d",&n,&c,&d);
	for (int i=0;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if (y==d){
			if (x>c) p0++;
			else n0++;
		}
		else
			s[m++]=(P){y-d,x-c};
	}
	sort(s,s+m);
	for (int i=0,j=0;i<m;i++){
		if (s[i].w>0)
			ans+=nt+1ll*n0*nc;
		else ans+=pt+1ll*p0*pc;
		if (i+1<m&&s[i]!=s[i+1]){
			int tpc=0,tnc=0;
			for (;j<i+1;j++)
				if (s[j].w>0) tpc++;
				else tnc++;
			nt+=1ll*tnc*pc;
			pt+=1ll*tpc*nc;
			pc+=tpc; nc+=tnc;
		}
	}
	printf("%lld\n",ans);
}
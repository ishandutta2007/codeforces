#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=200005;
ull S(int l,int r){
	return 1ull*(l+r)*(r-l+1)/2;
}
vector<int> e[N];
ull ans,A,B,C,s[N];
const int wzp=1000007;
struct Hashset{
	int head[wzp],nxt[wzp],tot;
	ull val[wzp];
	Hashset(){
		tot=0;
		memset(head,0,sizeof(head));
	}
	void push_back(ull v){
		int tmp=v%wzp;
		val[++tot]=v;
		nxt[tot]=head[tmp];
		head[tmp]=tot;
	}
	bool find(ull v){
		int tmp=v%wzp;
		for (int i=head[tmp];i;i=nxt[i])
			if (val[i]==v) return 1;
		return 0;
	}
}Hash;
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	scanf("%llu%llu%llu",&A,&B,&C);
	for (int i=0;i<n;i++)
		ans+=1ull*A*(n-i-1)*S(0,i-1)+1ull*B*(n-i-1)*i*i+1ull*C*i*S(i+1,n-1);
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if (x>y) swap(x,y);
		ans-=1ull*A*S(0,x-1)+1ull*B*x*x+1ull*C*x*y;
		ans-=1ull*A*(y-x-1)*x+1ull*B*S(x+1,y-1)+1ull*C*(y-x-1)*y;
		ans-=1ull*A*(n-y-1)*x+1ull*B*(n-y-1)*y+1ull*C*S(y+1,n-1);
		e[x].push_back(y);
		e[y].push_back(x);
		Hash.push_back(1ull*x*2333333+y);
	}
	for (int x=0;x<n;x++){
		sort(e[x].begin(),e[x].end());
		int sz=e[x].size();
		for (int j=0;j<=sz;j++) s[j]=0;
		for (int j=0;j<sz;j++)
			s[j]+=e[x][j],s[j+1]+=s[j];
		for (int j=1;j<sz&&e[x][j]<x;j++)
			ans+=1ull*A*s[j-1]+1ll*B*e[x][j]*j+1ll*C*x*j;
		for (int j=sz-2;j>=0&&e[x][j]>x;j--)
			ans+=1ull*A*x*(sz-j-1)+1ll*B*e[x][j]*(sz-j-1)+1ll*C*(s[sz-1]-s[j]);
		int tmp=lower_bound(e[x].begin(),e[x].end(),x)-e[x].begin();
		if (tmp!=0&&tmp!=sz)
			ans+=1ull*A*s[tmp-1]*(sz-tmp)+1ull*B*x*tmp*(sz-tmp)+1ull*C*(s[sz-1]-s[tmp-1])*tmp;
	}
	for (int i=0;i<n;i++)
		for (int j=0;j<e[i].size();j++)
			if (e[i][j]>i){
				int J=e[i][j];
				int id=(e[i].size()<e[J].size()?i:J);
				int tmp=upper_bound(e[id].begin(),e[id].end(),J)-e[id].begin();
				for (int k=tmp;k<e[id].size();k++){
					int K=e[id][k];
					if (Hash.find(1ull*(i+J-id)*2333333+K))
						ans-=1ull*A*i+1ull*B*J+1ull*C*K;
				}
			}
	printf("%llu",ans);
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int M=1e6+10,L=1e8+10;
int A[1000];
vector<int> P[1000];
map<vector<int>,int>st;
int d[1010][1010];
int pri[M],ptr,psz,vis[M],cnt[M],f[910][910][2];
void dfs(ll nw,int lst,vector<int> v){
	int s=1;
	for(auto a:v)s*=a+1;
	st[v]=++ptr;
	P[ptr]=v,A[ptr]=s;
	nw*=pri[v.size()+1];
	for(int i=1;nw<=L&&i<=lst;i++,nw*=pri[v.size()+1]){
		auto O=v;
		O.push_back(i);
		dfs(nw,i,O);
	}
}
int chk(vector<int> A,vector<int> B){
	if(A.size()<B.size())swap(A,B);
	int dis=0;
	for(int i=0;i<A.size();++i)
		dis+=abs(A[i]-(i>=B.size()?0:B[i]));
	return dis;
}
vector<int> get(int a){
	vector<int> ret;
	while(a>1){
		int nw=cnt[a],b=0;
		while(a%nw==0)a/=nw,b++;
		ret.push_back(b);
	}
	sort(ret.begin(),ret.end(),greater<int>());
	return ret;
}
int main(){
	cnt[1]=1;
	for(int i=2;i<=1000000;++i){
		if(!vis[i]){
			pri[++psz]=i;
			vis[i]=1;
			cnt[i]=i;
		}
		for(int j=1;j<=psz&&pri[j]*i<=1000000;++j){
			vis[i*pri[j]]=1;
			cnt[i*pri[j]]=pri[j];
			if(i%pri[j]==0)break;
		}
	}
	dfs(1,30,vector<int>());
	/*
	for(int i=1;i<=ptr;++i){
		printf("{");for(auto c:P[i])printf("%d ",c);puts("}");
	}
	return 0;*/
	for(int i=1;i<=ptr;++i)
		for(int j=1;j<=ptr;++j)
			f[i][j][0]=chk(P[i],P[j]),f[i][j][1]=(A[i]==A[j]?0:1e9);
//	printf("[%d]",f[st[get(2)]][st[get(4)]][0]);
//	return 0;
	for(int i=1;i<=ptr;++i)
		for(int j=1;j<=ptr;++j)
			for(int k=1;k<=ptr;++k){
				f[j][k][0]=min(f[j][k][0],f[j][i][0]+f[i][k][0]);
				f[j][k][1]=min(f[j][k][1],f[j][i][0]+f[i][k][1]);
				f[j][k][1]=min(f[j][k][1],f[j][i][1]+f[i][k][0]);
			}
	int T;
	scanf("%d",&T);
	while(T--){
		ll a,b;
		scanf("%lld%lld",&a,&b);
		auto va=get(a);
		auto vb=get(b);
		int ida=st[va],idb=st[vb];
		printf("%d\n",min(f[ida][idb][0],f[ida][idb][1]));
	}
}
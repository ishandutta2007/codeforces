#include<bits/stdc++.h>
#define maxn 100100
using namespace std;
int n,aa[maxn],a[100],ans=45,b[100];
int pd(vector<int>& v){
	for(auto p:v)
		if(p&1)return 0;
	return 1;
}
void upd(int sum){
	if(ans<=sum)return ;
	ans=sum;
	for(int i=1;i<=sum;++i)b[i]=a[i];
}
void dfs(vector<int>v,int sum,int d){
//	printf("[v.size=%d]",v.size());
//	for(auto p:v)printf("{%d}",p);puts("");
	if(v.empty()||(v.size()==1&&v[0]==0))return upd(sum);
	if(sum>=ans||d>(1<<20))return ;
	if(pd(v)){
		for(auto& p:v)p/=2;
		dfs(v,sum,d*2);
	} else {
		vector<int>nw;
		for(auto p:v){
			if(p&1)p++;
			if(nw.empty()||nw.back()!=p)
				nw.push_back(p);
		}
		a[sum+1]=-d,dfs(nw,sum+1,d);
		nw.clear();
		for(auto p:v){
			if(p&1)p--;
			if(nw.empty()||nw.back()!=p)
				nw.push_back(p);
		}
		a[sum+1]=d,dfs(nw,sum+1,d);
	}
}
int main(){
	vector<int>A;
//	n=500;
	scanf("%d",&n);
//	for(int i=1;i<=n;++i)A.push_back(rand()%5000-2500);
	for(int i=1;i<=n;++i)	
		scanf("%d",&aa[i]),A.push_back(aa[i]);
	sort(A.begin(),A.end());
	A.erase(unique(A.begin(),A.end()),A.end());
	dfs(A,0,1);
	printf("%d\n",ans);
	for(int i=1;i<=ans;++i)printf("%d ",b[i]);
}
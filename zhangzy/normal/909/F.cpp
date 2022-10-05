#include<bits/stdc++.h>
using namespace std;

int n,ans[101000];
int doit(vector<int>a,vector<int>b,int w){
	if (a.size()==1) return ans[b[0]]=a[0];
	vector<int>aa[2],bb[2];
	aa[0].clear(), aa[1].clear(); for (auto o:a) aa[o>>w&1].push_back(o);
	bb[0].clear(), bb[1].clear(); for (auto o:b) bb[o>>w&1].push_back(o);
	if (aa[1].size()>bb[0].size()) return 0;
	for (;aa[1].size()<bb[0].size();) aa[1].push_back(aa[0][aa[0].size()-1]), aa[0].pop_back();
	if (!doit(aa[1],bb[0],w+1)) return 0;
	if (!doit(aa[0],bb[1],w+1)) return 0;
	return 1;
}

void out(int fl){
	if (fl){
		puts("YES");
		for (int j=1;j<=n;++j) printf("%d ",ans[j]);
		puts("");
	}else{
		puts("NO");
	}
}

vector<int>vec[21];
int main(){
	cin>>n;
	vector<int>a,b; a.clear(), b.clear();
	for (int i=1;i<=n;++i) a.push_back(i), b.push_back(i);
	out(n-1&&doit(a,b,0));
	if (n<6) return 0*puts("NO");
	for (int i=2;i<=n;++i)
		for (int j=20;;--j) if (i>>j&1){
			vec[j].push_back(i); break;
		}
	for (int i=0;i<20;++i){
		if (vec[i].size()==1) return 0*puts("NO");
		for (int j=0;j<vec[i].size();++j)
			ans[vec[i][j]]=vec[i][(j+1)%vec[i].size()];
	}
	ans[1]=5,ans[4]=6,ans[5]=1;
	out(1);
}
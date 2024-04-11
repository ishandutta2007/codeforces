#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int N=100005;
int a[N],x,n,i,j,w,d[N];
pair<int,int> c[N];
bool b[N];
vector<int> v[N];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",&x);
		c[i]=make_pair(x,i); 
	}
	sort(c+1,c+n+1);
	for(i=1;i<=n;++i)a[c[i].second]=i;
	for(i=1;i<=n;++i)if(!b[i]){
		++w;
		for(j=i;j^i || v[w].size()==0;j=a[j])b[j]=1,v[w].push_back(j);
		sort(v[w].begin(),v[w].end());
	}
	printf("%d\n",w);
	for(i=1;i<=w;++i){
		printf("%d ",(int)v[i].size());
		for(j=0;j<(int)v[i].size();++j)printf("%d%c",v[i][j],j==(int)v[i].size()-1?'\n':' ');
	}
	return 0;
}
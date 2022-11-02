#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=3005;
LL read(){
	LL x=0;
	char ch=getchar();
	while (!isdigit(ch))
		ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+ch-48,ch=getchar();
	return x;
}
int n,m;
vector <int> id[N],v;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	n=read(),m=read();
	for (int i=1;i<=m;i++)
		id[i].clear();
	for (int i=1;i<=n;i++){
		int ID=read(),c=read();
		id[ID].push_back(c);
	}
	for (int i=1;i<=m;i++)
		sort(id[i].begin(),id[i].end(),cmp);
	LL ans=1LL<<50;
	for (int i=0;i<=n;i++){
		int now=id[1].size();
		LL tot=0;
		v.clear();
		for (int j=2;j<=m;j++){
			int sz=(int)id[j].size();
			for (int k=0;k<sz;k++)
				if (k<i)
					v.push_back(id[j][k]);
				else
					tot+=id[j][k],now++;
		}
		sort(v.begin(),v.end(),cmp);
		while (now<=i&&!v.empty()){
			now++;
			tot+=*--v.end();
			v.pop_back();
		}
		if (now>i)
			ans=min(ans,tot);
	}
	printf("%I64d",ans);
	return 0;
}
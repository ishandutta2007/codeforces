#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL read(){
	LL x=0,f=1;
	char ch=getchar();
	while (!isdigit(ch)&&ch!='-')
		ch=getchar();
	if (ch=='-')
		f=-1,ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
const int N=400005;
int n;
vector <int> v[4];
int main(){
	n=read();
	for (int i=1;i<=n;i++){
		int a=read(),b=read();
		a=(a/10)<<1|(a%10);
		v[a].push_back(b);
	}
	for (int i=0;i<4;i++){
		sort(v[i].begin(),v[i].end());
		reverse(v[i].begin(),v[i].end());
	}
	int ans=0,m=v[3].size();
	for (auto y : v[3])
		ans+=y;
	if (v[1].size()>v[2].size())
		swap(v[1],v[2]);
	int mi=m+v[1].size();
	m+=v[1].size()*2;
	for (int i=0;i<v[1].size();i++)
		ans+=v[1][i]+v[2][i];
	for (int i=v[1].size();i<v[2].size();i++)
		v[0].push_back(v[2][i]);
	sort(v[0].begin(),v[0].end());
	reverse(v[0].begin(),v[0].end());
	int re=mi*2-m;
	for (int i=0;i<min(re,(int)v[0].size());i++)
		ans+=v[0][i];
	cout << ans;
	return 0;
}
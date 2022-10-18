#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
int n,m,a[N],b[N],x,y;
string s;
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>s,s=' '+s;
	for(int i=1;i<=n;i++)
		a[i]=a[i-1]+(s[i]=='0'&&s[i-1]=='0'),b[i]=b[i-1]+(s[i]=='1'&&s[i-1]=='1');
	while(m--&&cin>>x>>y)
		cout<<max(a[y]-a[x],b[y]-b[x])+1<<'\n';
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6;
int n,m,x,y,a[N],s[N],A,l,c;
set<int>p[30];
void C(int i,int x){
	for(;i<=n;i+=i&-i)
		s[i]+=x;
}
int Q(int i){
	x=0;
	for(;i;i-=i&-i)
		x+=s[i];
	return x;
}
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],l=log2(a[i]+1),p[l].insert(i),C(i,a[i]);
	for(;m--&&cin>>x>>y;){
		A=-1,l=log2(a[x]+1),p[l].erase(x),C(x,y-a[x]),a[x]=y,l=log2(y+1),p[l].insert(x);
		for(int i=0;i<30;i++,c=0)
			for(auto j:p[i]){
				c++;
				if(c>2)
					break;
				if(Q(j-1)==a[j])
					A=j;
			}
		cout<<A<<'\n';
	}
}
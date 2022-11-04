#include<bits/stdc++.h>
using namespace std;
int k,m,a[10];
set<int> solve(int l,int r){
	if (l==r){
		set<int> tmp;
		tmp.insert(a[l]);
		tmp.insert(-a[l]);
		return tmp;
	}
	set<int> res;
	for (int md=l;md<r;md++){
		set<int> ls=solve(l,md),rs=solve(md+1,r);
		set<int>::iterator it1,it2;
		for (it1=ls.begin();it1!=ls.end();it1++)
			for (it2=rs.begin();it2!=rs.end();it2++){
				int v1=*it1,v2=*it2;
				res.insert(v1+v2);
				res.insert(v1-v2);
				res.insert(v1*v2);
				//if (v2) res.insert(v1/v2);
			}
	}
	return res;
}
map<int,int> mp;
void dfs(int p){
	if (p==5){
		set<int> tmp=solve(1,4);
		set<int>::iterator it; mp.clear();
		for (it=tmp.begin();it!=tmp.end();it++)
			if (abs(k-*it)<10000){
				if (mp.find(abs(k-*it))!=mp.end()) continue;
				mp[abs(k-*it)]=1;
				m--; printf("%04d",abs(k-*it));
				for (int i=1;i<=4;i++) printf("%d",a[i]);
				if (!m) exit(0); puts("");
			}
		return;
	}
	for (int i=0;i<=9;i++) a[p]=i,dfs(p+1);
}
int main(){
	scanf("%d%d",&k,&m);
	dfs(1);
}
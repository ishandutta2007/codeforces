#include<bits/stdc++.h>
using namespace std;
map<int,int> st;
int cas,b[101000];
int a[100100],anses[101000]; 
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1,x;i<=n;++i){
		scanf("%d",&a[i]);
		st[a[i]]++;
	}
	int flg=1;
	for(auto s:st){
		flg&=s.second%(n-s.first)==0;
	}
	if(!flg){
		puts("Impossible");
		return 0;
	} else puts("Possible");
	for(int i=1;i<=n;++i){
		if(st[a[i]]%(n-a[i])==0)
			b[a[i]]=++cas;
		st[a[i]]--;
		anses[i]=b[a[i]];
	}
	for(int i=1;i<=n;++i)printf("%d ",anses[i]);
}
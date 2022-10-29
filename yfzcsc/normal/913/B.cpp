#include<bits/stdc++.h>
using namespace std;
vector<int>v[100100];
int n;
int chk(int x){
	int ans=0;
	for(auto y:v[x])ans+=chk(y);
	if(v[x].size()&&ans<3)puts("No"),exit(0);
	if(v[x].size()==0)return 1;
	else return 0;
}
int main(){
	scanf("%d",&n);
	for(int i=2,x;i<=n;++i)
		scanf("%d",&x),v[x].push_back(i);
	chk(1);
	puts("Yes");
}
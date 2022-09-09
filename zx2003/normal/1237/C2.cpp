#include<bits/stdc++.h>
using namespace std;
const int N=50005;
vector<int>a[N];
int n,x,y,z,i;
map<int,map<int,map<int,int>>>mp;
void del(int x,int y,int z){
	mp[x][y].erase(z);
	if(mp[x][y].empty()){
		mp[x].erase(y);
		if(mp[x].empty())mp.erase(x);
	}
}
bool usd[N];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d%d%d",&x,&y,&z);
		a[i]={x,y,z,i};
		mp[x][y][z]=i;
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;++i)if(!usd[a[i][3]]){
		usd[a[i][3]]=1;del(a[i][0],a[i][1],a[i][2]);
		auto it=mp.lower_bound(a[i][0]);if(it==mp.end())--it;
		auto it2=it->second.lower_bound(a[i][1]);if(it2==it->second.end())--it2;
		auto it3=it2->second.lower_bound(a[i][2]);if(it3==it2->second.end())--it3;
		printf("%d %d\n",a[i][3],it3->second);
		usd[it3->second]=1;del(it->first,it2->first,it3->first);
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n;
int chkpri(int x){
	for(int i=2;i<x;++i)if(x%i==0)return 0;
	return 1;
}
vector<pii>v;
int main(){
	cin>>n;
	for(int i=1;i<=n;++i)v.push_back(pii(i,i==n?1:i+1));
	int Z=n-n/2+1;
	for(int i=0;i<n/2;++i){
		if(chkpri(v.size()))break;
		v.push_back(pii(i+1,Z+i));
	}
	printf("%d\n",v.size());
	for(auto a:v)printf("%d %d\n",a.first,a.second);
}
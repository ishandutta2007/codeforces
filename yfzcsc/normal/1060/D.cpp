#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<pii>v;
int n;
int main(){
	scanf("%d",&n);
	for(int i=1,l,r;i<=n;++i){
		scanf("%d%d",&l,&r);
		v.push_back(pii(l,0));
		v.push_back(pii(r,1));
	}
	sort(v.begin(),v.end());
	int x=0;
	long long ans=n;
	for(int i=v.size()-1;i>=0;--i){
		if(v[i].second==0){
			if(x<0)x++;
			else x++,ans+=v[i].first;
		} else {
			if(x>0)x--;
			else x--,ans+=v[i].first;
		}
	}
	printf("%lld",ans);
}
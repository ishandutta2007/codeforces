#include<bits/stdc++.h>
using namespace std;
#define LL long long
pair<int,int> a[1000010];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	set<pair<int,int> > s1;
	set<int> s2;
	int tot=0;

	int t;cin>>t;
	while(t--){
		int tag;cin>>tag;
		if(tag==1){
			int mon;cin>>mon;
			++tot;
			s1.insert({mon,-tot}); 
			s2.insert(tot);
			a[tot]={mon,-tot};
		}
		else if(tag==2){
			int now=*s2.begin();
			cout<<now<<" ";
			s2.erase(now);
			s1.erase(a[now]);
		}
		else{
			int now=-(s1.rbegin()->second);
			cout<<now<<" ";
			s2.erase(now);
			s1.erase(a[now]);
		}
	}

	cout<<endl;
}
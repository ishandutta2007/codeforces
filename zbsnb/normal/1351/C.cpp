#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
		int x=0,y=0,ans=0;
		string s;cin>>s;
		map<pair<pair<int,int>,pair<int,int> >,int> mp;
		for(auto &it:s){
			int nowx=x,nowy=y;
			if(it=='S')nowx=x+1;
			if(it=='N')nowx=x-1;
			if(it=='E')nowy=y+1;
			if(it=='W')nowy=y-1;
			pair<int,int> p1={x,y},p2={nowx,nowy};
			if(p1>p2)swap(p1,p2);
			if(mp[make_pair(p1,p2)])ans++;
			else ans+=5,mp[make_pair(p1,p2)]=1;
			x=nowx,y=nowy;
			// cout<<x<<" "<<y<<endl;
		}
		cout<<ans<<endl;
	}
}
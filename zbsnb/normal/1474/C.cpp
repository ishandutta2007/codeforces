#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000010];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=2*n;i++){
			cin>>a[i];
		}
		sort(a+1,a+2*n+1);

		int ff=0;
		for(int k=1;k<=2*n-1;k++){
			vector<pair<int,int> > ans;
			int x=a[k]+a[2*n];

			int flg=0;
			multiset<int,greater<int> > s;
			for(int i=1;i<=2*n;i++) s.insert(a[i]);
			for(int i=1;i<=n;i++){

				auto bg=s.begin();
				int val=*bg;
				s.erase(bg);

				int now=x-val;
				auto tmp=s.find(now);
				if(tmp==s.end()){
					flg=1;
					break;
				}
				else {
					ans.push_back({*tmp,val});
					s.erase(tmp);
					x=val;
				}
			}
			if(flg==0){
				cout<<"YES"<<endl;
				cout<<a[k]+a[2*n]<<endl;
				for(auto &it:ans){
					cout<<it.first<<" "<<it.second<<"\n";
				}
				ff=1;
				break;
			}
		}
		if(ff==0) cout<<"NO"<<endl;
	}
}
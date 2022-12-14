#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n,m;
		cin>>n>>m;
		set<int> up;
		queue<int> st;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			st.emplace(x);
		}
		long long int ans=0;
		for(int i=0,x;i<m;i++){
			cin>>x;
			if(up.count(x)){
				ans++;
				up.erase(x);
			}
			else{
				while(st.front()!=x){
					up.insert(st.front());
					st.pop();
				}
				st.pop();
				ans+=up.size()*2+1;
			}
		}
		cout<<ans<<'\n';
	}
}
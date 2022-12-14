#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int c,sum;
		cin>>c>>sum;
		int ans=0;
		ans+=(sum%c)*(sum/c+1)*(sum/c+1)+(c-sum%c)*(sum/c)*(sum/c);
		cout<<ans<<'\n';
	}
}
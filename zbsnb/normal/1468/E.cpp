#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t;cin>>t;
	while(t--){
		int a[4];
		for(int i=0;i<4;i++) cin>>a[i];
		int b[4]={0,1,2,3};
		LL ans=0;
		do{
			ans=max(ans,1LL*min(a[b[0]],a[b[1]])*min(a[b[2]],a[b[3]]));
		}while(next_permutation(b,b+4));
		cout<<ans<<endl;
	}
}
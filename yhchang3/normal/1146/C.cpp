#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;

	while(t--){
		int n,x;
		cin>>n;
		int ans=0;
		for(int i=0;i<7;i++){
			int cnt1=0,cnt2=0;
			for(int j=0;j<n;j++){
				if((1<<i)&j)
					cnt1++;
				else
					cnt2++;
			}
			if(cnt1==0)	break;
			cout<<cnt1<<' '<<cnt2;
			for(int j=0;j<n;j++){
				if((1<<i)&j)
					cout<<' '<<j+1;
			}
			for(int j=0;j<n;j++){
				if((1<<i)&j);
				else	cout<<' '<<j+1;
			}
			cout<<endl;
			cin>>x;
			ans=max(x,ans);
		}
		cout<<-1<<' '<<ans<<endl;
	}
}
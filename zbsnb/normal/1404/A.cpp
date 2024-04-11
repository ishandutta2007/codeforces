#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int main(){
	int t;cin>>t;
	while(t--){
		int n,k;cin>>n>>k;
		cin>>s+1;
		int cnt0=0,cnt1=0,flg=0;
		for(int i=1;i<=k;i++){
			int f=-1;
			for(int j=i;j<=n;j+=k){
				if(s[j]=='0'){
					if(f!=1)f=0;
					else flg=1;
				}
				if(s[j]=='1'){
					if(f!=0)f=1;
					else flg=1;
				}
			}
			if(flg) break;
			if(f==0)cnt0++;
			if(f==1)cnt1++;
		}
		// cout<<cnt0<<" "<<cnt1<<endl;
		if(flg||cnt0>k/2||cnt1>k/2) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
}
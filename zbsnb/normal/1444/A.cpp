#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		ll a,b;cin>>a>>b;
		if(a<b) cout<<a<<endl;
		else {
			if(a%b!=0) cout<<a<<endl;
			else{
				vector<int> p;
				int tmp=b;
				for(int i=2;i*i<=b;i++){
					if(tmp%i==0){
						p.push_back(i);
						p.push_back(b/i);
						while(tmp%i==0){
							tmp/=i;
						}
					}
				}
				if(tmp!=1) p.push_back(tmp);
				ll ans=1;
				for(auto &it:p){
					int cnta=0,cntb=0;
					ll tmpa=a,tmpb=b;
					while(tmpa%it==0){
						tmpa/=it;
						cnta++;
					}
					while(tmpb%it==0){
						tmpb/=it;
						cntb++;
					}
					for(int i=1;i<=cntb-1;i++){
						tmpa*=it;
					}
					// cout<<it<<" "<<cnta<<" "<<cntb<<endl;
					ans=max(ans,tmpa);
				}
				cout<<ans<<endl;
			}
		}
	}

}
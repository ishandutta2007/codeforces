#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=110001;
int P[maxn],cnt;bool vis[maxn];
void init(){
	for(int i=2;i<maxn;i++){
		if(!vis[i])P[cnt++]=i;
		for(int j=0;j<cnt&&i*P[j]<maxn;j++){
			vis[i*P[j]]=1;
			if(i%P[j]==0) break;
		}
	}
}
int now[maxn];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	init();
 
	// int tot=0;
	// for(int j=0;j<cnt;j++){
	// 	for(ll i=P[j];i<maxn;i*=P[j]){
	// 		tot++;
	// 	}
	// }
	// cout<<tot<<endl;
	
	int n;cin>>n;int cnt=n;
	int j=0;
	for(;P[j]*P[j]<=n;j++){
		cout<<"B "<<P[j]<<endl;
		int tmp;cin>>tmp;
		for(int i=P[j];i<=n;i+=P[j]){
			if(!now[i]) now[i]=1,cnt--;
		}
	}
	cout<<"A 1"<<endl;
	int tmp;cin>>tmp;
 
	if(tmp!=cnt){
		int ans=1;
		for(j=0;P[j]*P[j]<=n;j++){
			int now=1;
			for(ll i=P[j];i<=n;i*=P[j]){
				cout<<"A "<<i<<endl;
				int tmp;cin>>tmp;
				if(tmp==1)now=i;
				else break;
			}
			ans*=now;
		}
		
		for(;1ll*ans*P[j]<=n;j++){
			cout<<"A "<<(ans*P[j])<<endl;
			int tmp;cin>>tmp;
			if(tmp==1) {
				cout<<"C "<<(ans*P[j])<<endl;
				return 0;
			}
		}	
        
        cout<<"A "<<ans<<endl;
		int tmp;cin>>tmp;
		if(tmp==1){
            cout<<"C "<<ans<<endl;
            return 0;
        }
	}
	else{
		auto f=[&]{
			cout<<"A 1"<<endl;
			int tmp;cin>>tmp;
			if(tmp!=cnt){
				for(;j>=-1;j--){
					assert(j>=0);
					cout<<"A "<<P[j]<<endl;
					int tmp;cin>>tmp;
					if(tmp==1){
						cout<<"C "<<P[j]<<endl;
						return 1;
					}
				}
			}
			return 0;
		};
		for(;P[j]<=n;j++){
			cout<<"B "<<P[j]<<endl;
			for(int i=P[j];i<=n;i+=P[j]){
				if(!now[i]) now[i]=1,cnt--;
			}
			int tmp;cin>>tmp;
			if(j%100==0) if(f())return 0;
		}
		j--;
		if(f())return 0;
		cout<<"C 1"<<endl;
	}
}
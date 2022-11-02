#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=500010;
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
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	init();
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int p0=1,p1=-1,p2=-1;
		for(int i=2;i<maxn;i++){
			if(vis[i]) continue;
			if(p1==-1){
				if(i-p0>=n) p1=i;
			}
			else if(i-p1>=n){
				p2=i;
				break;
			}
		}
		cout<<p1*p2<<endl;
	}
}
#include<bits/stdc++.h>
using namespace std;
#define LL long long
int x[2000010];
int n,m,a,b;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);

	int t;cin>>t;
	while(t--){
		cin>>n>>m>>a>>b;
		int d=abs(a-b)-1;
		int rest=b>a?a-1:n-a;
		
		for(int i=1;i<=m;i++){ 
			cin>>x[i];
		}
		sort(x+1,x+m+1);
		int ans=0;
		for(int i=m;i>=1;i--){
			if(ans+x[i]<=d+rest){
				ans++;
			}
		}
		cout<<min(ans,d)<<endl;
	}
}
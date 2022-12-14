#include<bits/stdc++.h>
using namespace std;

bool ok[200001];

int st[200001];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	string s;
	cin>>s;
	int ans=0;
	for(int i=1;i<=n;i++)
		st[i]=s[i-1]-'0';
	for(int i=1;i<=n;i++){
		int g=__gcd(i,n);
		if(g==i){
			bool valid=true;
			for(int j=1;j<=g;j++){
				int cnt=0;
				for(int k=j;k<=n;k+=g)
					cnt+=st[k];
				if(cnt&1){
					valid=false;
					break;
				}
			}
			ok[g]=valid;
		}
		ans+=ok[g];
	}
	cout<<ans<<endl;
}
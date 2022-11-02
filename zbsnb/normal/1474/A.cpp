#include<bits/stdc++.h>
using namespace std;
#define ll long long
char s[1000010];
char ans[1000010];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		cin>>(s+1);
		char pre='3';
		for(int i=1;i<=n;i++){
			if(s[i]=='0'){
				if(pre=='1') ans[i]='0',pre='0';
				else ans[i]='1',pre='1';
			}
			else if(s[i]=='1'){
				if(pre=='2') ans[i]='0',pre='1';
				else ans[i]='1',pre='2';
			}
		}
		ans[n+1]=0;
		cout<<(ans+1)<<"\n";
	}
}
#include <bits/stdc++.h>
using namespace std;

string s;
void solve(){
	int ret=0;
	int cnt[2]={};
	for(int i=0;i<s.size();i++){
		if(s[i]=='(')cnt[0]++;
		else if(s[i]==')'){
			if(cnt[0]>0){
				cnt[0]--;
				ret++;
			}
		}
		else if(s[i]=='[')cnt[1]++;
		else {
			if(cnt[1]>0){
				cnt[1]--;
				ret++;
			}
		}
	}
	printf("%d\n",ret);
}

int main(){
	int t;
	scanf("%d",&t);
	for(;t>0;t--){
		cin>>s;
		solve();
	}
}
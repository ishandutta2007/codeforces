#include<bits/stdc++.h>
using namespace std;


int cnt[26];

string ans[1000];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,l,k,p=0;
	cin>>n>>l>>k;
	k--;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		cnt[s[i]-'a']++;
	int pre=0;
	while(ans[k].size()!=l){
		for(int i=pre;i<=k;i++){
			while(cnt[p]==0){
				p++;
				pre=i;
			}
			cnt[p]--;
			ans[i]+=char('a'+p);
		}
	}
	for(int i=0;i<n;i++){
		while(ans[i].size()!=l){
			while(cnt[p]==0)	p++;
			cnt[p]--;
			ans[i]+=char('a'+p);
		}
	}
	for(int i=0;i<n;i++)
		cout<<ans[i]<<'\n';
}
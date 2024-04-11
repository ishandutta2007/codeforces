#include <bits/stdc++.h>
using namespace std;
string s;
int first[1<<20];
int best[1<<20][21];
int main(){
	cin>>s;
	for(auto &x: s) x-='a';
	for(int i=0; i<(1<<20); i++) first[i]=1e9;
	for(int i=0; i<(1<<20); i++) for(int j=0; j<=20; j++) best[i][j]=1e9;
	for(int i=0; i<s.size(); i++){
		int mask=0;
		for(int j=i; j>=0; j--){
			if((mask>>s[j])&1) break;
			mask|=1<<s[j];
			first[mask]=min(first[mask], i);
		}
	}
	for(int i=0; i<(1<<20); i++) best[i][__builtin_popcount(i)]=first[i];
	for(int i=0; i<(1<<20); i++) for(int j=0; j<20; j++){
		if(((i>>j)&1)==0){
			for(int k=1; k<=20; k++) best[i|(1<<j)][k]=min(best[i|(1<<j)][k], best[i][k]);
		}
	}
	int ans=1;
	for(int i=0; i<s.size(); i++){
		int mask=0;
		int cnt=0;
		for(int j=i; j<s.size(); j++){
			if((mask>>s[j])&1) break;
			mask|=1<<s[j];
			cnt++;
			for(int k=max(0, ans-cnt+1); k<=20; k++){
				if(best[((1<<20)-1)^mask][k]<i){
					ans=k+cnt;
				}
			}
		}
	}
	cout<<ans<<'\n';
}
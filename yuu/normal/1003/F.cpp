#include <bits/stdc++.h>
using namespace std;
int n;
map <string, int> m;
int val[302];
int len[302];
int f[302];
int s[302];
void build_kmp(int len){
	f[1]=0;
	for(int i=2; i<=len; i++){
		f[i]=f[i-1];
		while(f[i]&&(s[i]!=s[f[i]+1])) f[i]=f[f[i]];
		if(s[f[i]+1]==s[i]) f[i]++;
	}
}
int main(){
	cin>>n;
	for(int i=1; i<=n; i++){
		string w;
		cin>>w;
		auto res=m.find(w);
		if(res==m.end()) m[w]=i;
		val[i]=m[w];
		len[i]=w.size();
	}
	int all=accumulate(len+1, len+n+1, 0);
	int ans=all+n-1;
	for(int i=1; i<=n; i++) for(int j=i; j<=n; j++){
		for(int k=i; k<=j; k++) s[k-i+1]=val[k];
		build_kmp(j-i+1);
		int sum=0;
		for(int k=i; k<=j; k++) sum+=len[k];
		int cnt=0;
		int now=0;
		for(int k=1; k<=n; k++){
			while((now)&&(s[now+1]!=val[k])) now=f[now];
			if(s[now+1]==val[k]) now++;
			if(now==j-i+1){
				cnt++;
				now=0;
			}
		}
		if(cnt>1)	ans=min(ans, all-cnt*(sum-1)+n-1);
	}
	cout<<ans<<'\n';
}
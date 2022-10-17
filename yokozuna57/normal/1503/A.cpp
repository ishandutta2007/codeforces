#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

int n;
string s;
void solve(){
	int cnt[2]={};
	for(int i=0;i<n;i++){
		cnt[s[i]-'0']++;
	}
	if(cnt[0]%2==1||cnt[1]%2==1||s[0]=='0'||s[s.size()-1]=='0'){
		puts("NO");
	}
	else {
		puts("YES");
		string a="",b="";
		int c[2]={};
		for(int i=0;i<n;i++){
			if(s[i]=='0'){
				c[0]++;
				if(c[0]&1){
					a+='(';
					b+=')';
				}
				else {
					a+=')';
					b+='(';
				}
			}
			else {
				c[1]++;
				if(c[1]*2<=cnt[1]){
					a+='(';
					b+='(';
				}
				else {
					a+=')';
					b+=')';
				}
			}
		}
		cout<<a<<"\n"<<b<<"\n";
	}
}

int main(){
	int T;
	scanf("%d",&T);
	for(;T>0;T--){
		cin>>n>>s;
		solve();
	}
}
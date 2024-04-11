#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int cnt[256];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	cin>>s;
	for(auto &x: s) cnt[x]++;
	for(int i=0; i<cnt['n']; i++) cout<<"1 ";
	for(int i=0; i<cnt['z']; i++) cout<<"0 ";
}
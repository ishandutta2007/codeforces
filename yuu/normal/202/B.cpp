#include <bits/stdc++.h>
using namespace std;
int n;
int p[4];
string s[4];
string t[4];
int m;
int k[10];
vector <string> a[10];
bool match(vector <string> a){
	int id=0;
	for(auto x: a){
		if(x==s[p[id]]) id++;
		if(id==n) return 1;
	}
	return 0;
}
int main(){
    cin>>n;
    for(int i=0; i<n; i++) cin>>s[i];
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>k[i];
        a[i].resize(k[i]);
        for(auto &x: a[i]) cin>>x;
    }
    int sim=0;
    int ind=m;
    for(int i=0; i<n; i++) p[i]=i;
    int cnt=1;
    for(int j=1; j<=n; j++) cnt*=j;
    for(int i=0; i<cnt; i++){
        int cost=0;
        for(int j=0; j<n; j++) for(int k=j+1; k<n; k++) cost+=(p[k]<p[j]);
        bool matched=0;
        int now=0;
        for(int j=0; j<m; j++) if(match(a[j])){
            matched=1;
            now=j;
            break;
        }
        if(matched){
            if(sim<n*(n-1)/2-cost+1){
                sim=n*(n-1)/2-cost+1;
                ind=now;
            }
            else if(sim==n*(n-1)/2-cost+1){
                ind=min(ind, now);
            }
        }
        next_permutation(p, p+n);
    }
		cerr<<sim<<'\n';
    string ans="[:";
    for(int j=0; j<sim; j++) ans+='|';
    ans+=":]";
    if(ans=="[::]") ans="Brand new problem!";
    else cout<<ind+1<<'\n';
    cout<<ans<<'\n';

}
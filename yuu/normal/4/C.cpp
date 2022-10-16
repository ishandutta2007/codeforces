#include<bits/stdc++.h>
using namespace std;
int main () {
int n; string s;
cin>>n;
map<string, int> m;
while (n--) {
cin>>s;
if(m[s]) cout<<s<<m[s]; else cout<<"OK";
cout<<'\n';
m[s]++;
}
}
#include <bits/stdc++.h>
using namespace std;
int main() {
   string s;
   vector<char> v;
   cin>>s;
   for(int i=0; i<s.size(); i+=2) v.push_back(s[i]);
   sort(v.begin(), v.end());
   for(int i=0; i+1<v.size(); i++) cout<<v[i]<<"+";
   cout<<v[v.size()-1]<<endl;
}
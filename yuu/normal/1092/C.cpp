#include <bits/stdc++.h>
using namespace std;
int n;
string s[200];
string rs[200];
vector <int> with_l[100];
string ans;
bool test_string(string t){
    string rt=t;
    reverse(rt.begin(), rt.end());
    for(int i=1; i<n; i++){
        
        if(t.find(s[with_l[i][0]])!=0) swap(with_l[i][0], with_l[i][1]);
        if(t.find(s[with_l[i][0]])!=0) return 0;
        if(rt.find(rs[with_l[i][1]])!=0) return 0;
        ans[with_l[i][0]]='P';
        ans[with_l[i][1]]='S';
    }
    return 1;
}
int main(){
    cin>>n;
    for(int i=0; i<n*2-2; i++){
        ans+='_';
        cin>>s[i];
        rs[i]=s[i];
        reverse(rs[i].begin(), rs[i].end());
        with_l[s[i].size()].push_back(i);
    }
    if(!test_string(s[with_l[n-1][0]][0]+s[with_l[n-1][1]])) test_string(s[with_l[n-1][1]][0]+s[with_l[n-1][0]]);
    cout<<ans;
}
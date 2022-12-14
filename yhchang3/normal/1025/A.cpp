#include<bits/stdc++.h>
using namespace std;
map<char,int> m;
map<char,int>::iterator iter;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    if(n==1){
        cout<<"YES"<<endl;
        return 0;
    }
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        m[s[i]]++;
    }
    for(iter=m.begin();iter!=m.end();iter++){
        if(iter->second>=2){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}
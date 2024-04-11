#include <bits/stdc++.h>
using namespace std;
int n, k;
string t;
int main(){
    cin>>n>>k>>t;
    ///KMP WeirdChamp
    int best=0;
    for(char c='a'; c<='z'; c++){
        string x=t+c;
        for(int i=0; i<x.size(); i++){
            string a=x.substr(i);
            if(t.find(a)==0) best=max(best, (int)x.size()-i-1);
        }
    }
    string f=t.substr(best);
    cout<<t;
    for(int i=1; i<k; i++) cout<<f;
}
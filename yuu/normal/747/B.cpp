#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
int n;
string s;
int cnt[256];
vector <int> q;
int main(){
//    freopen("B.INP", "r", stdin);
    cin>>n>>s;
    if(n%4){
        cout<<"===";
        return 0;
    }
    n/=4;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='?')
            q.push_back(i);
        else cnt[s[i]]++;
    }
    if(cnt['A']>n){
        cout<<"===";
        return 0;
    }
    else while(cnt['A']<n){
        if(q.empty()){
            cout<<"===";
            return 0;
        }
        s[q.back()]='A';
        q.pop_back();
        cnt['A']++;
    }
    if(cnt['T']>n){
        cout<<"===";
        return 0;
    }
    else while(cnt['T']<n){
        if(q.empty()){
            cout<<"===";
            return 0;
        }
        s[q.back()]='T';
        q.pop_back();
        cnt['T']++;
    }
    if(cnt['G']>n){
        cout<<"===";
        return 0;
    }
    else while(cnt['G']<n){
        if(q.empty()){
            cout<<"===";
            return 0;
        }
        s[q.back()]='G';
        q.pop_back();
        cnt['G']++;
    }
    if(cnt['C']>n){
        cout<<"===";
        return 0;
    }
    else while(cnt['C']<n){
        if(q.empty()){
            cout<<"===";
            return 0;
        }
        s[q.back()]='C';
        q.pop_back();
        cnt['C']++;
    }
    cout<<s;
}
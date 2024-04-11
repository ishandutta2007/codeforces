#include <bits/stdc++.h>
using namespace std;
int h1, h2;
string s1, s2;
int main(){
    cin>>s1>>s2;
    for(auto &c: s1) c-='0';
    for(auto &c: s2) c-='0';
    h1=(10*s1[0]+s1[1])*60+10*s1[3]+s1[4];
    h2=(10*s2[0]+s2[1])*60+10*s2[3]+s2[4];
    int mid=(h1+h2)/2;
    cout<<setw(2)<<setfill('0')<<mid/60<<':'<<setw(2)<<setfill('0')<<mid%60;
}
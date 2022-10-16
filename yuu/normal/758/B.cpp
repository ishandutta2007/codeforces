#include <iostream>
#include <stdio.h>
using namespace std;
string s;
string a="RGBY";
int pos[256];
int cnt[256];
int main(){
//    freopen("B.INP", "r", stdin);
    cin>>s;
    string ss=s;
    for(int i=0; i<s.size(); i++)
        pos[s[i]]=i;
    for(int i=0; i<4; i++){
        int j=pos[a[i]];
        for(int k=j; k<s.size(); k+=4)
            s[k]=a[i];
        for(int k=j; k>=0; k-=4)
            s[k]=a[i];
    }
    for(int i=0; i<ss.size(); i++){
        if(ss[i]=='!')
            cnt[s[i]]++;
    }
    cout<<cnt['R']<<' '<<cnt['B']<<' '<<cnt['Y']<<' '<<cnt['G'];
}
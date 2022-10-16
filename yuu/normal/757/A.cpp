#include <iostream>
using namespace std;
string a="Bulbasr";
int c[]={1, 2, 1, 1, 2, 1, 1};
int cnt[256];
int main(){
    string s;
    cin>>s;
    for(int i=0; i<s.size(); i++)
        cnt[s[i]]++;
    int res=9999999;
    for(int i=0; i<a.size(); i++)
        res=min(res, cnt[a[i]]/c[i]);
    cout<<res;
    //
}
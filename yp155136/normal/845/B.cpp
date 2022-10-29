#include <iostream>
#include <stdio.h>
using namespace std;

string to_stringg(int x) {
    string ret="";
    ret.resize(6);
    for (int i=0;6>i;i++) {
        ret[i] = char(x%10 + '0');
        x/=10;
    }
    return ret;
}

bool is_lucky(string s) {
    return s[0]+s[1]+s[2] == s[3]+s[4]+s[5];
}

int dif(string a,string b) {
    int ret=0;
    for (int i=0;6>i;i++) {
        ret += (!(a[i] == b[i]));
    }
    return ret;
}

int main () {
    string s;
    cin >> s;
    int ans=6;
    for (int i=0;1000000>i;i++) {
        string ret=to_stringg(i);
        if (is_lucky(ret)) {
            ans = min(ans,dif(s,ret));
        }
    }
    cout<<ans<<endl;
}
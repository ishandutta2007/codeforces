#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main () {
    string s,t;
    int n,m;
    cin >> n >>m >>s >> t;
    int ans=n;
    vector<int> v;
    for (int i=1;n>=i;i++) v.push_back(i);
    for (int j=0;m-n+1>j;j++) {
        int cnt=0;
        for (int i=0;n>i;i++) {
            if (s[i] != t[j+i]) cnt++;
        }
        if (cnt < ans) {
            ans=cnt;
            v.clear();
            for (int i=0;n>i;i++) {
                if (s[i] != t[j+i]) v.push_back(i+1);
            }
        }
    }
    cout<<ans<<endl;
    for (int i:v) cout<<i<<' ';
    cout<<endl;
}
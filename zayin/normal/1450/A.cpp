#include<bits/stdc++.h>
using namespace std;
int main()  {
    int T;
    cin>>T;
    while (T--) {
        int n;
        string s;
        cin>>n>>s;
        sort(s.begin(),s.end());
        cout<<s<<endl;
    }
    return 0;
}
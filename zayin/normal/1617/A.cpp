#include<bits/stdc++.h>
#define maxc 26
using namespace std;

int cnt[maxc];

int main()  {
    int _;
    cin>>_;
    while (_--) {
        for (int i=0;i<maxc;++i) cnt[i]=0;
        string s,t;
        cin>>s>>t;
        for (char c:s) ++cnt[c-'a'];
        if (t!="abc"||!cnt[0]||!cnt[1]||!cnt[2])   {
            sort(s.begin(),s.end());
            cout<<s<<endl;
        } else {
            cout<<string(cnt[0],'a');
            cout<<string(cnt[2],'c');
            cout<<string(cnt[1],'b');
            for (int i=3;i<maxc;++i)
                cout<<string(cnt[i],'a'+i);
            cout<<endl;
        }
    }
    return 0;
}
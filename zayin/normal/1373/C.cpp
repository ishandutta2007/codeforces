#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()  {
    int T;
    cin>>T;
    while (T--) {
        string s;
        cin>>s;

        LL ans=0,now=0,cur=0;
        for (int i=0;i<s.size();++i)    {
            ans-=now;
            if (s[i]=='+')
                ++cur;
            else
                --cur;
            if (cur<0) ++cur,++now;
            // cout<<i<<":"<<now<<endl;
        }
        cout<<ans+(now+1)*s.size()<<endl;
    }
    return 0;
}
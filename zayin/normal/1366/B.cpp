#include<bits/stdc++.h>
using namespace std;
int main()  {
    int T;
    cin>>T;
    while (T--) {
        int n,x,m;
        cin>>n>>x>>m;
        set<pair<int,int> > s;
        s.insert(make_pair(x,x));
        #define l first
        #define r second
        while (m--) {
            int l,r;
            cin>>l>>r;
            auto p=make_pair(l,r);

            bool flag=0;
            for (auto q:s)  {
                if (p.r<q.l||q.r<p.l) continue;
                flag=1;
                break;
            }
            if (flag)
                s.insert(p);
        }

        int last=-1,ans=0;
        for (auto p:s)  {
            if (last>=p.r) continue;
            if (last>=p.l)
                ans+=p.r-last;
            else
                ans+=p.r-p.l+1;
            last=p.r;
        }
        cout<<ans<<endl;
    }
    return 0;
}
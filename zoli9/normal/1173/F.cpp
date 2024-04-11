#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
vector<pair<pii, pii> > ans;
int n;
int kezds[1009];
int kezdo[1009];
int vegs[1009];
int vego[1009];
int a[1009];
int b[1009];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int ss;
        cin>>ss;
        kezds[i]=i;
        vegs[ss]=i;
        b[i]=i;
    }
    for(int i=1; i<=n; i++)
    {
        int oo;
        cin>>oo;
        kezdo[i]=i;
        vego[oo]=i;
        a[i]=i;
    }
    for(int i=1; i<=n; i++)
    {
        if(a[i]==vego[i] && b[i]==vegs[i]) continue;
        ans.push_back({{i, kezdo[vego[i]]}, {kezds[vegs[i]], i}});
        int aa=a[i];
        int bb=b[i];
        swap(a[i], a[kezdo[vego[i]]]);
        swap(b[i], b[kezds[vegs[i]]]);
        swap(kezdo[vego[i]], kezdo[aa]);
        swap(kezds[vegs[i]], kezds[bb]);
    }
    cout<<ans.size()<<'\n';
    for(pair<pii, pii> p: ans)
    {
        cout<<p.F.F<<" "<<p.F.S<<" "<<p.S.F<<" "<<p.S.S<<'\n';
    }

    return 0;
}
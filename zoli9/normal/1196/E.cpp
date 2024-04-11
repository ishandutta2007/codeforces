#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
vector<pair<ll, pii>> elek;
int test;
bool feherkisebb;
int black, white;
vector<pii> ans, ans2;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>black>>white;
        ans.clear();
        ans2.clear();
        if(white<=black)
        {
            feherkisebb=true;
        }
        else
        {
            feherkisebb=false;
            swap(black, white);
        }
        if(3*white+1<black)
        {
            cout<<"NO"<<endl;
            continue;
        }
        for(int i=1; i<=white; i++)
        {
            ans.push_back({2*i, 2});
        }
        for(int i=1; i<=min(white+1, black); i++)
        {
            ans2.push_back({2*i-1, 2});
        }
        black-=(min(white+1, black));
        for(int i=1; i<=white; i++)
        {
            if(black>0)
            {
                ans2.push_back({2*i, 1});
                black--;
            }
            if(black>0)
            {
                ans2.push_back({2*i, 3});
                black--;
            }
        }
        cout<<"YES"<<endl;
        for(pii p: ans)
        {
            if(feherkisebb)
            {
                cout<<p.F<<" "<<p.S<<endl;
            }
            else
            {
                cout<<p.F+1<<" "<<p.S<<endl;
            }
        }
        for(pii p: ans2)
        {
            if(feherkisebb)
            {
                cout<<p.F<<" "<<p.S<<endl;
            }
            else
            {
                cout<<p.F+1<<" "<<p.S<<endl;
            }
        }
    }

    return 0;
}
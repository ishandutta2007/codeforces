#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//(double)clock() / CLOCKS_PER_SEC;
string s;

void checking(string& z, string& order)
{
    int n=z.size();
    vector<bool> active(n, true);
    string answer="";
    for(int j=0; j<order.size(); j++)
    {
        for(int i=0; i<n; i++)
        {
            if(active[i]) answer+=z[i];
            if(z[i]==order[j]) active[i]=false;
        }
    }
    if(answer==s)
    {
        cout<<z<<" "<<order<<'\n';
    }
    else
    {
        cout<<-1<<'\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        cin>>s;
        int n=s.size();
        vector<bool> seen(26, false);
        vi cnt(26, 0);
        vi cntO(26, 0);
        string order="";
        for(int i=n-1; i>=0; i--)
        {
            cnt[s[i]-'a']++;
            if(!seen[s[i]-'a'])
            {
                seen[s[i]-'a']=true;
                order+=s[i];
            }
        }
        reverse(order.begin(), order.end());
        vi place(26, -1);
        for(int i=0; i<order.size(); i++)
        {
            place[order[i]-'a']=i+1;
            cntO[order[i]-'a']=cnt[order[i]-'a']/(i+1);
        }
        string z="";
        vi currentCnt(26, 0);
        for(int i=0; i<n; i++)
        {
            if(currentCnt[s[i]-'a']==cntO[s[i]-'a'])
            {
                break;
            }
            currentCnt[s[i]-'a']++;
            z+=s[i];
        }
        checking(z, order);
    }
    return 0;
}
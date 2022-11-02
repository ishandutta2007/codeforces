#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
string s;
int n;
vector<char> answer;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    cin>>s;
    int akt=0;
    int ans=0;
    int cnt=1;
    while(cnt<n)
    {
        if(s[cnt]==s[akt])
        {
            cnt++;
            continue;
        }
        answer.push_back(s[akt]);
        answer.push_back(s[cnt]);
        ans++;
        cnt++;
        if(cnt>=n) break;
        akt=cnt;
        cnt++;
    }
    cout<<n-2*ans<<endl;
    for(char cc: answer)
    {
        cout<<cc;
    }
    cout<<endl;
    return 0;
}
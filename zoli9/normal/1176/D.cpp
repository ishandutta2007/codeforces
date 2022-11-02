#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int osszetett[3000009];
int db[3000009];
int hova[200009];
vi prim;
int n;
vi answer;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=2; i<=2800000; i++)
    {
        if(osszetett[i]>0)
        {
            if(i<=200000) hova[i]=i/osszetett[i];
            continue;
        }
        for(int j=2*i; j<=2800000; j+=i)
        {
            if(osszetett[j]==0) osszetett[j]=i;
        }
        prim.push_back(i);
    }
    for(int p: prim)
    {
        if(p<=200000)
        {
            hova[p]=prim[p-1];
        }
    }
    cin>>n;
    for(int i=1; i<=2*n; i++)
    {
        int ss;
        cin>>ss;
        db[ss]++;
    }
    for(int i=200000; i>=2; i--)
    {
        if(!osszetett[i]) continue;
        while(db[i]>0)
        {
            answer.push_back(i);
            db[i]--;
            db[hova[i]]--;
        }
    }
    for(int i=2; i<=200000; i++)
    {
        if(osszetett[i]) continue;
        while(db[i]>0)
        {
            answer.push_back(i);
            db[i]--;
            db[hova[i]]--;
        }
    }
    for(int i: answer)
    {
        cout<<i<<" ";
    }
    cout<<endl;


    return 0;
}
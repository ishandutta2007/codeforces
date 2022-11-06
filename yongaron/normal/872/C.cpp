#include <bits/stdc++.h>


#define forn(n) for(int i = 0; i < n; i++)
#define pb push_back
#define mp make_pair
#define moc 1000000000;
#define llmoc 1000000000000000000;

using namespace std;

typedef long long ll;
typedef vector<int> vei;
typedef pair<int, int> pai;
typedef vector<pair<int, int> > vepai;

int q;

int solve(int a);

int main()
{
    int a;
    cin>>q;
    forn(q)
    {
        cin>>a;
        cout<<solve(a)<<endl;
    }
    return 0;
}

int solve(int a)
{
    if(a == 9)
        return 1;
    if(a == 2 || (a < 13 && a%2 == 1))
        return -1;
    if(a%2 == 0)
        return a/4;
    return a/4-1;
}
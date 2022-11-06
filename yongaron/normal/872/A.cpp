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

int a, b;
int a1[10], b1[10];

int main()
{
    int x;
    cin>>a>>b;
    forn(10)
    {
        a1[i] = 0;
        b1[i] = 0;
    }
    forn(a)
    {
        cin>>x;
        a1[x] = 1;
    }
    forn(b)
    {
        cin>>x;
        b1[x] = 1;
    }
    forn(10)
    {
        if(a1[i] && b1[i])
        {
            cout<<i<<endl;
            return 0;
        }
    }
    int g, h;
    forn(10)
    {
        if(a1[i])
        {
            g = i;
            break;
        }
    }
    forn(10)
    {
        if(b1[i])
        {
            h = i;
            break;
        }
    }
    if(g < h)
    {
        cout<<g<<h<<endl;
        return 0;
    }
    cout<<h<<g<<endl;
    return 0;
}
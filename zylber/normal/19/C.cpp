#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

typedef int xchar;
#define MAXN 1000000
#define forn(a,n) for(int a = 0; a<(n); ++a)

/*int p[MAXN], r[MAXN], t, n;

bool sacmp(int a, int b) { return p[(a+t)%n] < p[(b+t)%n]; }
void bwt(const xchar *s, int nn) {
    n = nn;
    int bc[256];
    memset(bc, 0, sizeof(bc));
    forn(i, n) ++bc[s[i]];
    forn(i, 255) bc[i+1]+=bc[i];
    forn(i, n) r[--bc[s[i]]] = i;
    forn(i, n) p[i]=bc[s[i]];
    
    int lnb, nb = 1;
    for(t = 1; t<n; t*=2) {
        lnb = nb; nb = 0;
        for(int i = 0, j = 1; i < n; i = j++) {
            while(j < n && p[r[j]] == p[r[i]]) ++j;
            if(j-i > 1) {
                sort(r+i, r+j, sacmp);
                int pk, opk = p[(r[i]+t)%n];
                int q = i, v = i;
                for(; i < j; i++) {
                    if(((pk = p[(r[i]+t)%n]) != opk) && !(q <= opk && pk < j)) { opk = pk; v = i;}
                    p[r[i]] = v;
                }
            }
            nb++;
        }
        if(lnb == nb) break;
    }
}

void lcp(const xchar* s, int* h) {
    int q = 0, j;
    forn(i, n) if(p[i]) {
        j = r[p[i]-1];
        while(q < n && s[(i+q)%n] == s[(j+q)%n]) ++q;
        h[p[i]-1] = q;
        if (q>0) --q;
    }
}*/

int arr[100100];
int arrposta[100100];
map<int, int> mapeo;
long long hash[100100];
long long pots[100100];
vector<int> posnum[100100];
map<pair<int, int>, int> lcp;
int n;

int matchean(int i, int j)
{
    if(i>=n || j>=n) return 0;
    if(arr[i]!=arr[j]) return 0;
    
    pair<int, int> rg=make_pair(i,j);
    if(lcp.count(rg)) return lcp[rg];
    
    lcp[rg]=0;
    int &ans=lcp[rg];
    ans=matchean(i+1, j+1)+1;
    return ans;
    
}

vector<pair<int, int> > dobles;

bool compa(pair<int, int> a, pair<int, int> b)
{
    if(a.second-a.first != b.second - b.first) return a.second-a.first < b.second - b.first;
    return a.first < b.first;
}

int main()
{
#ifdef ACMTUYO
    freopen("C.in", "r", stdin);
#endif
    cin >> n;
    
    int cn=0;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
        arrposta[i]=arr[i];
        if(!mapeo.count(arr[i]))
        {
            mapeo[arr[i]]=cn;
            cn++;
        }
        arr[i]=mapeo[arr[i]];
        posnum[arr[i]].push_back(i);
    }
    
    for(int i=0; i<cn; i++)
    {
        for(int j=0; j<posnum[i].size(); j++)
            for(int k=j+1; k<posnum[i].size(); k++)
            {
                int a=posnum[i][j], b=posnum[i][k];
                //cout << a << " " << b << " " << matchean(a,b) << endl;
                if(matchean(a, b)>=b-a) dobles.push_back(make_pair(a,b));
            }
    }
    
    sort(dobles.begin(), dobles.end(), compa);
    
    int queda=0, ds=dobles.size();
    for(int i=0; i<ds; i++)
    {
        if(dobles[i].first>=queda) queda=dobles[i].second;
    }
    
    cout << n-queda << endl;
    for(int i=queda; i<n; i++) 
    {
        if(i!=queda) cout << " ";
        cout << arrposta[i];
    }
    cout << endl;
    return 0;
}
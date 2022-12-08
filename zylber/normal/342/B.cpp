#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

#define forn(a, n) for(int a = 0; a<(n); ++a)
#define forsn(a,s,n) for(int a = (s); a<(n); ++a)

int n, m, s, f;
vector<pair<int, pair<int, int> > > events;

int main()
{
#ifdef ACMTUYO
    freopen("J.in", "r", stdin);
#endif
    cin >> n >> m >> s >> f;
    
    forn(i, m) {
        int ti, li, ri;
        cin >> ti >> li >> ri;
        events.push_back(make_pair(ti, make_pair(li, ri)));
    }
    
    sort(events.begin(), events.end());
    
    int pos = s, ev = 0;
    for(int t = 1; pos != f; ++t) {
        bool puedo = true;
        int np;
        if(pos < f)
            np = pos+1;
        else
            np = pos-1;
            
        for(; ev<events.size(); ++ev) {
            if(events[ev].first > t) break;
            if(events[ev].first < t) continue;
            if((events[ev].second.first <= pos && pos <= events[ev].second.second) ||
               (events[ev].second.first <= np && np <= events[ev].second.second)) {
                puedo = false;
                break;
            }
        }
        if(puedo) {
            if(pos < f){
                cout << "R";
                pos++;
            }else{
                cout << "L";
                pos--;
            }
        }else
            cout << "X";
    }
    cout << endl;
    return 0;
}
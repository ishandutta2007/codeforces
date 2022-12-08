#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define forn(a,n) for(int a = 0; a<(n); ++a)
pair<int, int> arr[104];
int ret[104];
int main() {
#ifdef ACMTUYO
    freopen("A.in", "r", stdin);
#endif
    int n;
    cin >> n;
    
    forn(i,n) {
        cin >> arr[i].first >> arr[i].second;
    }
    
    vector<pair<int, int> > events;
    forn(i,n) events.push_back(make_pair(arr[i].first, i));
    
    vector<int> abi;
    sort(events.begin(), events.end());
    
    int ke = 0, ulti = -1;
    while(true) {
        if(ke == events.size()) break;
        
        //cout << "Meti " << events[ke].second << endl;
        abi.push_back(events[ke++].second);
        
        while(ke < n && events[ke].first == arr[abi[0]].first){
            //cout << "Meti " << events[ke].second << endl;
            abi.push_back(events[ke++].second);
        }
        
        //pongo el mas chico
        while(abi.size() > 0) {
            int nn = 0;
            forn(i,abi.size()) if(arr[abi[nn]].second > arr[abi[i]].second)
                nn = i;
        
            ulti = max(ulti, arr[abi[nn]].first);
            ret[abi[nn]] = ulti;
            ulti++;

            //cout << "Saque " << abi[nn] << endl;
            abi.erase(abi.begin()+nn);
            
            while(ke < n && events[ke].first == ulti){
                //cout << "Meti " << events[ke].second << endl;
                abi.push_back(events[ke++].second);
            }
        }
    }
    
    forn(i, n){
        if(i) cout << " ";
        cout << ret[i];
    }
    return 0;
}
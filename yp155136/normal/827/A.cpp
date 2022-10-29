#include <iostream>
#include <stdio.h>
#include <utility>
using namespace std;

typedef pair<int,int> pii;
const int MAX_N = 2e6 + 6;

pii pos[MAX_N];

string s[MAX_N];

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    int mx=0;
    for (int qq=1;T>=qq;qq++) {
        cin >> s[qq];
        int t;
        cin >>t;
        while (t--) {
            int x;
            cin >> x;
            if (pos[x].second < (int)s[qq].size()) {
                pos[x] = make_pair(qq,s[qq].size());
            }
            mx = max(mx,x+(int)s[qq].size()-1);
        }
    }
    int lastid=0;
    int lastpos=0;
    for (int i=1;mx>=i;i++) {
        if ( i +pos[i].second - 1 >=lastpos +  pos[lastpos].second - 1 && pos[i].second != 0) {
            lastid=0;
            lastpos=i;
        }
        /*cout<<"i = "<<i<<" , id = "<<lastid<<" , pos = "<<lastpos<<endl;
        cout<<pos[lastpos].first <<"jizzzzzz\n";*/
        if (pos[lastpos].second == 0 || lastid == s[pos[lastpos].first ].size()) cout<<'a';
        else cout<<s[pos[lastpos].first ][lastid++];
    }
    cout<<endl;
}
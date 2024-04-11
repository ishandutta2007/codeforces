#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000005;
int min_p[maxn];
int tab[maxn];
int vege[maxn];
typedef long long ll;

void tolt() {
    tab[1] = 0;
    for(int i=2;i<maxn;i++) {
        tab[i] = tab[i-1];
        if(min_p[i] == 0) {
            min_p[i] = i;
            tab[i]++;
            for(ll j = (ll)i*(ll)i;j<(ll)maxn;j+=(ll)i) {
                min_p[j] = i;
            }
        }
    }
    return;
}

int main()
{
    tolt();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin>>test;
    for(int tc=0;tc<test;tc++) {
        int q;
        cin>>q;
        int ans = 1 + tab[q] - tab[(int)sqrt(q)];
        cout<<ans<<'\n';
    }
    return 0;
}
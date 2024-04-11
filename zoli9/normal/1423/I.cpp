#include <bits/stdc++.h>

using namespace std;
#define ll long long int

int lsb[100000];
int msb[100000];
int k,n;

int getbig(ll x) {
    return x>>k;
}

int getsmall(ll x) {
    return x-(getbig(x)<<k);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> k >> n;
    vector<ll> l (n);
    vector<ll> r (n);
    vector<ll> v (n);
    vector<vector<int> > biginsert (100000,vector<int>());
    vector<vector<int> > bigerase (100000,vector<int>());
    vector<vector<int> > smallinsert (100000,vector<int>());
    vector<vector<int> > smallerase (100000,vector<int>());
    for(int i = 0; i < n; i++) {
        cin >> l[i] >> r[i] >> v[i];
        int lbig = getbig(l[i]);
        int rbig = getbig(r[i]);
        int lsmall = getsmall(l[i]);
        int rsmall = getsmall(r[i]);
        biginsert[lbig].push_back(v[i]);
        bigerase[rbig+1].push_back(v[i]);
        if(lbig == rbig) {
            smallinsert[lsmall].push_back(v[i]);
            smallerase[rsmall+1].push_back(v[i]);
        } else if(lbig+1 == rbig && lsmall > rsmall) {
            smallinsert[0].push_back(v[i]);
            smallerase[rsmall+1].push_back(v[i]);
            smallinsert[lsmall].push_back(v[i]);
        } else {
            smallinsert[0].push_back(v[i]);
        }
    }
    vector<vector<int> > smsum(100000);
    vector<vector<int> > bgsum(100000);
    vector<vector<int> > sm(100000);
    vector<vector<int> > bg(100000);
    for(int j = 0; j <= (1<<k); j++) {
        smsum[j].resize(16);
        bgsum[j].resize(16);
        sm[j].resize(16);
        bg[j].resize(16);
        for(int i = 0; i < 16; i++) {
            if(j == 0) {
                smsum[j][i] = bgsum[j][i] = 0;
                sm[j][i] = bg[j][i] = 0;
            } else {
                smsum[j][i] = smsum[j-1][i];
                bgsum[j][i] = bgsum[j-1][i];
                sm[j][i] = sm[j-1][i];
                bg[j][i] = bg[j-1][i];
            }
        }
        for(int x : smallerase[j]) {
            for(int i = 0; i < 16; i++) {
                if(x&(1<<i)) {
                    sm[j][i]--;
                }
            }
        }
        for(int x : bigerase[j]) {
            for(int i = 0; i < 16; i++) {
                if(x&(1<<i)) {
                    bg[j][i]--;
                }
            }
        }
        for(int x : smallinsert[j]) {
            for(int i = 0; i < 16; i++) {
                if(x&(1<<i)) {
                    sm[j][i]++;
                    smsum[j][i]++;
                }
            }
        }
        for(int x : biginsert[j]) {
            for(int i = 0; i < 16; i++) {
                if(x&(1<<i)) {
                    bg[j][i]++;
                    bgsum[j][i]++;
                }
            }
        }
        for(int i = 0; i < 16; i++) {
            if(sm[j][i]) {
                lsb[j]+= (1<<i);
            }
            if(bg[j][i]) {
                msb[j]+= (1<<i);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        int lbig = getbig(l[i]);
        int rbig = getbig(r[i]);
        int lsmall = getsmall(l[i]);
        int rsmall = getsmall(r[i]);
        if(lbig == rbig) {
            int smuni = 0;
            for(int j = 0; j < 16; j++) {
                if(sm[lsmall][j] > 0 || smsum[lsmall][j] < smsum[rsmall][j]) {
                    smuni+= (1<<j);
                }
            }
            if((smuni&msb[lbig]) != v[i]) {
                cout << "impossible";
                return 0;
            }
        } else if(lbig+1 == rbig) {
            int smuni1 = 0;
            for(int j = 0; j < 16; j++) {
                if(sm[lsmall][j] > 0 || smsum[lsmall][j] < smsum[(1<<k)][j]) {
                    smuni1+= (1<<j);
                }
            }
            if((smuni1&msb[lbig]) != v[i]) {
                cout << "impossible";
                return 0;
            }


            int smuni2 = 0;
            for(int j = 0; j < 16; j++) {
                if(sm[0][j] > 0 || smsum[0][j] < smsum[rsmall][j]) {
                    smuni2+= (1<<j);
                }
            }
            if((smuni2&msb[rbig]) != v[i]) {
             //   cout << i << " " << smuni2 << " " << msb[rbig] << endl;
                cout << "impossible";
                return 0;
            }
        } else {
            int smuni1 = 0;
            for(int j = 0; j < 16; j++) {
                if(sm[lsmall][j] > 0 || smsum[lsmall][j] < smsum[(1<<k)][j]) {
                    smuni1+= (1<<j);
                }
            }
            if((smuni1&msb[lbig]) != v[i]) {
                cout << "impossible";
                return 0;
            }


            int smuni2 = 0;
            for(int j = 0; j < 16; j++) {
                if(sm[0][j] > 0 || smsum[0][j] < smsum[rsmall][j]) {
                    smuni2+= (1<<j);
                }
            }
            if((smuni2&msb[rbig]) != v[i]) {
                cout << "impossible";
                return 0;
            }



            int smuni3 = 0;
            for(int j = 0; j < 16; j++) {
                if(sm[0][j] > 0 || smsum[0][j] < smsum[(1<<k)][j]) {
                    smuni3+= (1<<j);
                }
            }
            int bguni = 0;
            for(int j = 0; j < 16; j++) {
                if(bg[lbig+1][j] > 0 || bgsum[lbig+1][j] < bgsum[rbig-1][j]) {
                    bguni+= (1<<j);
                }
            }
            if((smuni3&bguni) != v[i]) {
                cout << "impossible";
                return 0;
            }
        }
    }
    cout << "possible\n";
    for(int j = 0; j < (1<<k); j++) {
        cout << lsb[j] << "\n";
    }
    for(int j = 0; j < (1<<k); j++) {
        cout << msb[j] << "\n";
    }
    return 0;
}
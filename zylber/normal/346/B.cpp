#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define forn(a,n) for(int a = 0; a<(n); ++a)

string s1, s2, virus;

int nv[104];
int nextVirus(int pos) {
    if(nv[pos] != -1) return nv[pos];
    
    int &ret = nv[pos];
    for(ret = pos-1; ret>0; --ret) {
        bool anda = true;
        forn(i, ret){
            if(pos-ret+i >= virus.size()){
                anda = false;
                break;
            }
            if(virus[i] != virus[pos-ret + i]){
                anda = false;
                break;
            }
        }
        if(anda)
            return ret;
    }
    return ret;
}

const int inf = 4000;

int dp[104][104][104][2];
int calc(int posa, int posb, int posv, int matchea) {
    if(posv == virus.size())
        return -inf;
    if(posa == s1.size() || posb == s2.size())
        return 0;
    
    int &ret = dp[posa][posb][posv][matchea];
    if(ret != -1) return ret;
    
    ret = -inf;
    if(s1[posa] == s2[posb]) {
        if(s1[posa] == virus[posv])
            ret = calc(posa+1, posb+1, posv+1, 0)+1;
        else{
            if(posv > 0)
                ret = calc(posa, posb, nextVirus(posv), 1);
            else
                ret = calc(posa+1, posb+1, 0, 0)+1;
        }
    }
    
    if(!matchea)
        ret = max(ret, max(calc(posa+1, posb, posv, 0), calc(posa, posb+1, posv, 0)));
    //cout << posa << " " << posb << " " << posv << " " << ret << endl;
    return ret;
}

int main() {
#ifdef ACMTUYO
    freopen("E.in", "r", stdin);
#endif
    
    cin >> s1 >> s2 >> virus;
    
    memset(dp, -1, sizeof(dp));
    memset(nv, -1, sizeof(nv));
    
    int rr = max(0, calc(0,0,0,0));
    if(rr == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    string ret;
    int posa=0, posb=0, posv=0, matchea=0;
    
    while(posa < s1.size() && posb < s2.size()){
        //cout << ret << " " << posa << " " << posb << " " << posv << endl;
        //cout << s1[posa] << " " << s2[posb] << " " << virus[posv] << endl;
        if(s1[posa] == s2[posb]) {
            if(s1[posa] == virus[posv]){
                
                if(calc(posa+1, posb+1, posv+1, 0)+1 == dp[posa][posb][posv][matchea]) {
                    ret += s1[posa];
                    posa++;
                    posb++;
                    posv++;
                    matchea = 0;
                    continue;
                }
            }else{
                if(posv > 0){
                    if(calc(posa, posb, nextVirus(posv), 1) == dp[posa][posb][posv][matchea]){
                        posv = nextVirus(posv);
                        matchea = 1;
                        continue;
                    }
                }else{
                    if(calc(posa+1, posb+1, 0, 0)+1 == dp[posa][posb][posv][matchea]) {
                        ret += s1[posa];
                        posa++;
                        posb++;
                        matchea = 0;
                        continue;
                    }
                }
            }
        }
        
        matchea = 0;
        if(calc(posa+1, posb, posv, matchea) == dp[posa][posb][posv][matchea])
            posa++;
        else
            posb++;
    }
    cout << ret << endl;
    return 0;
}
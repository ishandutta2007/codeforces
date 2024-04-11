#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

pii ask(pii a){
    pii b;
    cout << "? " << a.first << endl;
    fflush(stdout);
    cin >> b.first;
    cout << "? " << a.second << endl;
    fflush(stdout);
    cin >> b.second;
    return b;
}

int n, m;

const int maxn = 1e5 + 5;
bool vis[maxn];
int res[maxn];

int guess[maxn];

void solve(int l, int r){
    if(res[r] > res[l]){
        int diff = res[r] - res[l];
        for(int i = 1;i <= diff;i++){
            guess[l + i] = res[l] + i;
        }
        for(int i = diff + 1;i < r - l;i++){
            guess[l + i] = res[r];
        }
    }else{
        int diff = res[l] - res[r];
        for(int i = 1;i <= diff;i++){
            guess[l + i] = res[l] - i;
        }
        for(int i = diff + 1;i < r - l;i++){
            guess[l + i] = res[r];
        }
    }
}

int main(){
    cin >> n;
    m = n / 2;
    if(m & 1){
        cout << "! -1" << endl;
        fflush(stdout);
    }else{
        int l = 1, r = m;
        pii ret = ask(make_pair(1, m + 1)); 
        vis[1] = true, vis[m + 1] = true;
        res[1] = ret.first, res[m + 1]=ret.second;
        res[1 + n] = ret.first;
        if(res[1] == res[m + 1]){
            cout << "! 1" << endl;
            fflush(stdout);
        }
        while(l < r){
            int mid = (l + r + 1) / 2;
            ret = ask(make_pair(mid, mid + m));
            vis[mid] = true, vis[mid + m] = true;
            res[mid] = ret.first, res[mid + m] = ret.second;  
            if(res[mid] == res[mid + m]){
                cout << "! " << mid << endl;
                fflush(stdout);
                return 0;
            }
            solve(l, mid);
            solve(mid, r + 1);
            solve(l + m, mid + m);
            solve(mid + m, r + 1 + m);
            bool flag = false;
            for(int i = l + 1;i <= mid - 1;i++){
                //cout << i << " " << guess[i] << " " << guess[i + m] << endl;
                if(guess[i] == guess[i + m]){
                    flag = true;
                }
            }
            //cout << "!!!" << " " << flag << endl;
            if(flag){
                r = mid - 1;
            }else{
                l = mid;
            }
        }
        ret = ask(make_pair(l, l + m));
        if(ret.first == ret.second){
            cout << "! " << l << endl;
            fflush(stdout);
            return 0;
        }else{
            cout << "! -1" << endl;
            fflush(stdout);
        }
    } 
    return 0;
}
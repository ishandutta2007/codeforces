#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

priority_queue<ll> leftq;
priority_queue<ll, vector<ll>, greater<ll>> rightq;
ll sum_all;
ll sum_left;
int s;
ll median(){
    return leftq.top();
}
void add(ll n){
    s++;
    sum_all += n;
    if(s == 1){
        leftq.push(n);
        sum_left += n;
    }else if(n > leftq.top()){
        rightq.push(n);
    }else{
        leftq.push(n);
        sum_left += n;
    }
    if(leftq.size() > (s+1)/2){
        ll top = leftq.top();
        leftq.pop();
        sum_left -= top;
        rightq.push(top);
    }
    if(rightq.size() > (s)/2){
        ll top = rightq.top();
        rightq.pop();
        sum_left += top;
        leftq.push(top);
    }
    // cout << leftq.size() << ' ' << rightq.size() << ' ' << median() << endl;
}

//1-indexed
template <typename T>
struct bit{
    int n;
    vector<T> data;

    bit(int n_){
        n = 1;
        while(n < n_) n *= 2;
        data = vector<T>(n+1);
        for(int i = 0; i <= n; i++) data[i] = 0;
    }
    
    T sum(int i){
        T ret = 0;
        while(i > 0){
            ret += data[i];
            i -= i&-i;
        }
        return ret;
    }

    void add(int i, T x){
        while(i <= n){
            data[i] += x;
            i += i&-i;
        }
    }
};

int N;
int idx[200001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> N;
    for(int i = 1; i <= N; i++){
        int p;
        cin >> p;
        idx[p] = i;
    }
    bit<int> bt(N);
    ll pos = 0;
    for(ll i = 1; i <= N; i++){
        ll all = (i*(i-1))/2;
        bt.add(idx[i], 1);
        pos += bt.sum(idx[i]-1);
        ll inv = all-pos;
        add(idx[i]);
        if(i%2 == 0){
            ll k = i/2;
            cout << sum_all-2*sum_left-k*k+inv << endl;
        }else{
            ll k = i/2;
            cout << sum_all-2*sum_left+median()-k*(k+1)+inv << endl;
            // cout << sum_all-2*sum_left+median()-k*(k+1) << endl;
        }
        // cout << inv << endl;
        // cout << sum_all << ' ' << sum_left << endl;
    }
}
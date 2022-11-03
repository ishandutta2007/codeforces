#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define ALL(x) x.begin(),x.end()
 
template <typename T>
void cetak(T t){cout << t << ')' << endl;}
template <typename T, typename... V>
void cetak(T t, V... v) {cout << t; if (sizeof...(v)) cout << ", "; cetak(v...);}
 
#define debug(x...) cout << '(' << #x << ") = ("; cetak(x) 
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())
typedef int (*func)(int, int);




const int mx = 1e5 + 10;


void solve(int tc){
    int n;
    cin >> n;
    vector<int> a(n * 2);
    for(int i = 0; i < n * 2; i++){
        string ss;
        cin >> ss;
        if(ss == "+") a[i] = 0;
        else cin >> a[i];
    }
    set<int> available;
    vector<int> ans(n * 2, -1);
    stack<int> st;
    for(int i = 0; i < n * 2; i++){
        if(a[i] == 0) available.insert(i);
    }
    for(int i = n * 2 - 1; i >= 0; i--){
        auto x = a[i];
        if(x == 0){
            // debug("masuk", i);
            // available.insert(i);
        }
        else{
            while(!st.empty() && a[st.top()] < x){
                int j = st.top();
                st.pop();
                auto it = available.lower_bound(i);
                if(it == available.end() || *it > j){
                    cout << "NO\n";
                    return;
                }
                int x = *it;
                available.erase(x);
                ans[x] = a[j];
                
            }
            st.push(i);
        }
    }
    while(!st.empty()){
        int j = st.top();
        st.pop();
        auto it = available.upper_bound(j);
        if(it == available.begin()){
            cout << "NO\n";
            return;
        }
        it--;
        int x = *it;
        available.erase(x);
        ans[x] = a[j];
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n * 2; i++){
        if(ans[i] == -1){
            if(pq.empty() || a[i] != pq.top()){
                assert(false);
            }
            pq.pop();
        }
        else{
            pq.push(ans[i]);
        }
    }
    cout << "YES\n";
    for(auto x : ans) if(x != -1) cout << x << ' ';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    int tc = 0;
    while(t--){
        solve(++tc);
    }
}
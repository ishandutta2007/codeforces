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
    string ss;
    cin >> ss;
    stack<char> st;
    for(auto i : ss){
        if(st.empty()) st.push(i);
        else{
            if(i == 'B' && st.top() == 'A'){
                st.pop();
            }
            else st.push(i);
        }
    }
    ss = "";
    while(!st.empty()){
        ss += st.top();
        st.pop();
    }
    reverse(ALL(ss));
    for(auto i : ss){
        if(st.empty()) st.push(i);
        else{
            if(i == 'B' && st.top() == 'B'){
                st.pop();
            }
            else st.push(i);
        }
    }
    cout << st.size() << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    int tc = 0;
    while(t--){
        solve(++tc);
    }
}
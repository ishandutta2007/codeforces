#include <iostream>
#include <stdio.h>
#include <set>
#include <stack>
using namespace std;

const int MAX_N = 3e5 + 6;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int cnt=2*n;
    stack<int> sta;
    set<int> st;
    int ans=0;
    int mn=1;
    while (cnt--) {
        string op;
        cin >> op;
        if (op=="add") {
            int num;
            cin>>num;
            sta.push(num);
            st.insert(num);
        }
        else {
            if (sta.empty()) {
                st.erase(st.begin());
            }
            else if (sta.top() == mn) {
                sta.pop();
                st.erase(st.begin());
            }
            else {
                while (sta.size()) {
                    st.insert(sta.top());
                    sta.pop();
                }
                ans++;
                st.erase(st.begin());
            }
            mn++;
        }
    }
    cout<<ans<<endl;
}
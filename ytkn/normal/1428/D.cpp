#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

using namespace std;
typedef long long ll;

int a[100000];
bool used[100000];
bool ok[100000];
int p[100000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) p[i] = -1;
    stack<int> st;
    for(int i = n-1; i >= 0; i--){
        if(a[i] == 1){
            st.push(i);
        }else if(a[i] == 2){
            if(st.empty()){
                cout << -1 << endl;
                return 0;
            }
            int j = st.top(); st.pop();
            p[i] = j;
            used[j] = true;
        }
    }
    while(!st.empty()){
        st.pop();
    }
    for(int i = n-1; i >= 0; i--){
        if(a[i] >= 1 && a[i] <= 2 && !used[i]){
            st.push(i);
        }else if(a[i] == 3){
            if(st.empty()){
                cout << -1 << endl;
                return 0;
            }
            int j = st.top(); st.pop();
            p[i] = j;
            used[j] = true;
            st.push(i);
        }
    }
    vector<int> x, y;
    int cur = 0;
    for(int i = 0; i < n; i++){
        if(ok[i]) continue;
        if(a[i] == 0) continue;
        if(a[i] == 1){
            x.push_back(i);
            y.push_back(cur);
            cur++;
            ok[i] = true;
        }else if(a[i] == 2){
            x.push_back(i);
            y.push_back(cur);
            x.push_back(p[i]);
            y.push_back(cur);
            cur++;
            ok[p[i]] = true;
        }else if(a[i] == 3){
            int j = p[i];
            if(a[j] == 3){
                x.push_back(i);
                y.push_back(cur);
                x.push_back(j);
                y.push_back(cur);
                cur++;
            }else if(p[j] == -1){
                x.push_back(i);
                y.push_back(cur);
                x.push_back(j);
                y.push_back(cur);
                x.push_back(j);
                y.push_back(cur+1);
                cur += 2;
                ok[j] = true;
            }else{
                int k = p[j];
                x.push_back(i);
                y.push_back(cur);
                x.push_back(j);
                y.push_back(cur);
                x.push_back(j);
                y.push_back(cur+1);
                x.push_back(k);
                y.push_back(cur+1);
                cur += 2;
                ok[j] = true;
                ok[k] = true;
            }
        }
    }
    cout << x.size() << endl;
    for(int i = 0; i < x.size(); i++){
        cout << y[i]+1 << ' ' << x[i]+1 << endl;
    }
}
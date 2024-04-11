#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <stack>
#include <set>
#include <vector>
using namespace std;

const int maxn = 3e5 + 5;
int n;
pair<int,int> s[maxn], t[maxn];
int d[maxn];
vector<pair<pair<int, int>, int> > ans;
int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d", &s[i].first);
        s[i].second = i;
    }
    for(int j = 1;j <= n;j++){
        scanf("%d", &t[j].first);
        t[j].second = j;
    }
    sort(s + 1, s + 1 + n);
    sort(t + 1, t + 1 + n);
    for(int i = 1;i <= n;i++){
        d[i] = s[i].first - t[i].first;
    }
    stack<int> st;
    bool flag = true;
    for(int i = 1;i <= n;i++){
        while(d[i] > 0){
            if(st.empty()){
                flag = false;
                break;
            }
            int id = st.top();st.pop();
            int v = d[id];
            if(d[id] + d[i] < 0){
                ans.push_back(make_pair(make_pair(s[id].second, s[i].second), d[i]));
                d[id] += d[i];
                d[i] = 0;
                st.push(id);
            }else{
                ans.push_back(make_pair(make_pair(s[id].second, s[i].second), -d[id]));
                d[i] += d[id];
                d[id] = 0; 
            }
        }
        if(d[i] < 0){
            st.push(i);
        }
        if(!flag)
            break;
    }
    if(st.size() != 0){
        flag = false;
    }
    if(flag){
        cout << "YES" << endl;
        cout << ans.size() << endl;
        for(int i = 0;i < ans.size();i++){
            int d = ans[i].second;
            int x = ans[i].first.first;
            int y = ans[i].first.second;
            printf("%d %d %d\n", x, y, d);
        }
    }else{
        cout << "NO" << endl;
    }
    return 0;
}
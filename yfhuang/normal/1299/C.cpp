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
int n;

const int maxn = 1e6 + 5;

long long a[maxn];

stack<pair<int, long long> > st;
double b[maxn];
int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        int tmp;
        scanf("%d", &tmp);
        a[i] = tmp; 
    }
    for(int i = 1;i <= n;i++){
        if(st.empty()){
            st.push(make_pair(1, a[i]));
        }else{
            long long avg = a[i];
            int len = 1;
            while(!st.empty() and 1LL * st.top().first * avg <= 1LL * st.top().second * len){
                pair<int, long long> top = st.top(); 
                len += st.top().first;
                avg += st.top().second; st.pop();
            }
            st.push(make_pair(len, avg));
        }
    }
    int now = n + 1;
    while(!st.empty()){
        pair<int, long long> top = st.top(); st.pop();
        double val = 1.0 * top.second / top.first;
        for(int i = now - top.first;i < now;i++){
            b[i] = val;
        }
        now = now - top.first;
    }
    for(int i = 1;i <= n;i++){
        printf("%.10lf\n", b[i]);
    }
    return 0;
}
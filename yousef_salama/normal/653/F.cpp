#include <bits/stdc++.h>
using namespace std;

struct state {
    int len, link;
    map<char, int> next;
};

const int MAXLEN = 500000;
state st[MAXLEN * 2];
int sz, last;

void sa_init() {
    st[0].len = 0;
    st[0].link = -1;
    sz++;
    last = 0;
}
void sa_extend(char c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p = last;
    while (p != -1 && !st[p].next.count(c)) {
        st[p].next[c] = cur;
        p = st[p].link;
    }
    if (p == -1) {
        st[cur].link = 0;
    } else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s;
    cin >> n >> s;

    int sum = 0;
    long long res = 0;
    sa_init();

    stack <int> stk;
    vector < vector <int> > v(2 * n + 1);
    v[n].push_back(-1);
    stk.push(0);

    for(int i = 0; i < n; i++){
        sa_extend(s[i]);

        if(s[i] == '('){
            sum++;
        }else{
            sum--;
        }

        while(!stk.empty() && stk.top() > sum){
            v[stk.top() + n].pop_back();
            stk.pop();
        }

        res += lower_bound(v[sum + n].begin(), v[sum + n].end(), i - st[st[last].link].len) - v[sum + n].begin();
        v[sum + n].push_back(i);
        stk.push(sum);
    }
    printf("%lld\n", res);


    return 0;
}
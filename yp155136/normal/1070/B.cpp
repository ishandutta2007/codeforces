#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
#define F first
#define S second

struct Node {
    Node *lc,*rc;
    int depth;
    bool have_white;
    bool have_black;
    int is_white;
    int is_black;
    Node(int _depth):lc(NULL),rc(NULL),depth(_depth)
    ,have_white(0),have_black(0),is_white(0),is_black(0){}
};

bool White(Node* node) {
    return node?node->have_white:false;
}

bool Black(Node* node) {
    return node?node->have_black:false;
}

void pull(Node* node) {
    if (!node) return;
    node->have_white |= White(node->lc);
    node->have_white |= White(node->rc);
    node->have_black |= Black(node->lc);
    node->have_black |= Black(node->rc);
}

void addd(Node* node,ll num,int cur_depth,int block_depth,int color) {
    if (cur_depth == block_depth) {
        if (color == 0) {
            node->have_black = true;
            node->is_black = 1;
        }
        else {
            node->have_white = true;
            node->is_white = 1;
        }
        return;
    }
    else {
        if ( (num&(1LL<<(cur_depth-1))) > 0) {
            if (node->rc == NULL) {
                node->rc = new Node(cur_depth-1);
            }
            addd(node->rc,num,cur_depth-1,block_depth,color);
        }
        else {
            if (node->lc == NULL) {
                node->lc = new Node(cur_depth-1);
            }
            addd(node->lc,num,cur_depth-1,block_depth,color);
        }
        pull(node);
    }
}

vector<pii> ans;

void get_ans(Node* node,ll now) {
    if (node->depth == 0) {
        if (node->have_white && node->have_black) {
            cout << -1 << endl;
            exit(0);
        }
        if (node->have_black) {
            ans.push_back(make_pair(now,32-node->depth));
        }
        return;
    }
    else if (!node->have_black) return;
    else if (node->is_white) {
        cout << -1 << endl;
        exit(0);
    }
    else if (!node->have_white) {
        ans.push_back(make_pair(now,32-node->depth));
        return;
    }
    if (node->is_black) {
        cout << -1 << endl;
        exit(0);
    }
    if (Black(node->lc)) {
        get_ans(node->lc,now);
    }
    if (Black(node->rc)) {
        get_ans(node->rc,(now|(1<<(node->depth-1))));
    }
}

void have_num(ll x) {
    vector<int> v;
    for (int i=0;i<4;++i) {
        ll y = (x&255);
        v.push_back(y);
        x >>= 8;
    }
    reverse(v.begin(),v.end());
    cout << v[0] << "." << v[1] << "." << v[2] << "." << v[3];
}

void show() {
    cout << (int)ans.size() << endl;
    for (pii p:ans) {
        have_num(p.first);
        cout << "/" << p.second << endl;
    }
    return;
}

int main () {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    Node* root = new Node(32);
    while (n--) {
        string s;
        cin >> s;
        ll num=0;
        s += " ";
        ll tmp=0;
        int tar = 24;
        int x = 0;
        for (int i=1;i<s.size();++i) {
            if ('0' <= s[i] && s[i] <= '9') {
                tmp *= 10;
                tmp += (s[i]-'0');
            }
            else if (tar == -8) {
                x = 32 - tmp;
            }
            else {
                //cout << "tmp = " << tmp << " ,tar = " << tar << endl;
                num |= (tmp<<tar);
                tar -= 8;
                tmp = 0;
            }
        }
        //cout << "num = " << num << endl;
        if (s[0] == '+') addd(root,num,32,x,1);
        else addd(root,num,32,x,0);
    }
    get_ans(root,0);
    show();
}
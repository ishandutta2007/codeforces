#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define F first
#define S second
const int N = 100006;

pii a[N], b[N];
pii c[N], d[N];


struct Node {
    long long int val, tag;
    Node *lc, *rc;
    Node(){
        tag=0;
        val=0;
        lc = NULL;
        rc = NULL;
    }
    void pull () {
        val = lc->val + rc->val;
    }
};


Node* build(int L, int R) {
    Node *node = new Node();
    if (L==R) {
        node->val = 0;
        return node;
    }
    int mid = (L+R) >> 1;
    node->lc = build(L,mid);
    node->rc = build(mid+1,R);
    node->pull();
    return node;
}

void push(Node* node, int L,int R) {
    if (!node->tag) return;
    if (L!=R) {   //check leaf
        int mid= (L+R) >> 1;
        node->lc->tag += node->tag;
        node->rc->tag += node->tag;
        node->lc->val += node->tag * (mid - L +1);   //tag""~~~ 
        node->rc->val += node->tag * (R - mid);
    }
    node->tag = 0;
}

void modify( Node* node, int L, int R, int ql, int qr,long long int d) {    //   |  d : value
    if (ql > R || qr < L) return;
    if (ql<=L && R<=qr) {
        node->tag += d;
        node->val += d*(R-L+1);
        return;
    }
    
    push(node,L,R);
    int mid = (L+R) >> 1;
    modify(node->lc, L,mid,ql,qr,d);
    modify(node->rc,mid+1,R,ql,qr,d);
    node->pull();
}

long long int query(Node* node, int L,int R, int ql, int qr) {
    if (ql > R || qr< L)  return 0;   //mission impossible
    if (ql<=L && R<= qr) return node->val;
    push(node,L,R);
    int mid = (L+R) >> 1;
    return query(node->lc,L,mid,ql,qr) + query(node->rc, mid+1, R ,ql,qr);
}

int n;
void go() {
    vector<int> idx1, idx2;
    multiset<int> ls, rs;
    int magic = 4 * N + 87;
    Node* root = build(1, magic);
    for (int i = 0; i < n; ++i) {
        c[i] = a[i];
        d[i] = b[i];
        ls.insert(b[i].F);
        rs.insert(b[i].S);
        modify(root, 1, magic, b[i].F, b[i].S, 1);
        idx1.push_back(i);
    }
    idx2 = idx1;
    sort(idx1.begin(), idx1.end(), [](const int &x, const int &y) {
        return a[x].S < a[y].S;
    });
    sort(idx2.begin(), idx2.end(), [](const int &x, const int &y) {
        return a[x].F < a[y].F;
    });
    int ptr = 0;
    for (int id: idx1) {
        while (ptr < n && a[ idx2[ptr] ].F <= a[id].S) {
            rs.erase(rs.find(b[ idx2[ptr] ].S));
            ls.erase(ls.find(b[ idx2[ptr] ].F));
            int i = idx2[ptr];
            //cout << "i = " << i << endl;
            modify(root, 1, magic, b[i].F, b[i].S, -1);
            ++ptr;
        }
        if (ptr == n) return;
        int L = b[id].F, R = b[id].S;
        //cout << "L = " << L << " , R = " << R << " , ptr = " << ptr << endl;
        if (query(root, 1, magic, L, R) != 0) {
            //cout << "sum = " << query(root, 1, magic, L, R) << endl;
            cout << "NO" << endl;
            exit(0);
        }
    }
}

int main () {
    scanf("%d", &n);
    vector<int> idx1, idx2;
    vector<int> vv;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d%d", &a[i].F, &a[i].S, &b[i].F, &b[i].S);
        c[i] = a[i];
        d[i] = b[i];
        vv.push_back(a[i].F);
        vv.push_back(a[i].S);
        vv.push_back(b[i].F);
        vv.push_back(b[i].S);
    }
    sort(vv.begin(), vv.end());
    vv.resize(unique(vv.begin(), vv.end()) - vv.begin());
    for (int i = 0; i < n; ++i) {
        int x = a[i].F;
        a[i].F = lower_bound(vv.begin(), vv.end(), x) - vv.begin() + 1;
        x = a[i].S;
        a[i].S = lower_bound(vv.begin(), vv.end(), x) - vv.begin() + 1;
        x = b[i].F;
        b[i].F = lower_bound(vv.begin(), vv.end(), x) - vv.begin() + 1;
        x = b[i].S;
        b[i].S = lower_bound(vv.begin(), vv.end(), x) - vv.begin() + 1;
    }
    go();
    for (int i = 0; i < n; ++i) {
        swap(a[i], b[i]);
    }
    go();
    cout << "YES" << endl;
}
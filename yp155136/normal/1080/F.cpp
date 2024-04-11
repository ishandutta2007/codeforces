#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000007;

struct Node {
    Node *lc,*rc;
    int mn;
    Node():lc(NULL),rc(NULL),mn(0){}
    void pull() {
        mn = max(lc->mn,rc->mn);
    }
};

Node* Build(int L,int R) {
    Node* node = new Node();
    if (L == R) {
        node->mn = INF;
        return node;
    }
    int mid=(L+R)>>1;
    node->lc = Build(L,mid);
    node->rc = Build(mid+1,R);
    node->pull();
    return node;
}

const int N = 300006;

Node* root[N];

Node* getNode(Node* old) {
    //cout << (old != NULL) << " result" << endl;
    Node* node = new Node();
    node->lc = old->lc;
    node->rc = old->rc;
    node->mn = old->mn;
    //cout << "finish" << endl;
    return node;
}

void modify(Node* old,Node* node,int L,int R,int pos,int val) {
    //cout << "L = " << L << " , R = " << R << endl;
    if (L == R) {
        node->mn = min(node->mn,val);
        return;
    }
    int mid=(L+R)>>1;
    if (pos <= mid) {
        //cout << "inn" << endl;
        node->lc = getNode(old->lc);
        //cout << "innn2" << endl;
        modify(old->lc,node->lc,L,mid,pos,val);
    }
    else {
        //cout << "in1" << endl;
        node->rc = getNode(old->rc);
        //cout << "innn2" << endl;
        modify(old->rc,node->rc,mid+1,R,pos,val);
    }
    node->pull();
}

int query(Node* node,int L,int R,int l,int r) {
    if (l>R || L>r) return 0;
    else if (l <= L && R <= r) return node->mn;
    int mid=(L+R)>>1;
    return max( query(node->lc,L,mid,l,r),query(node->rc,mid+1,R,l,r) );
}

typedef pair<int,int> pii;
typedef pair<pii,int> piii;

#define F first
#define S second

void show_ans(bool f) {
    if (f) printf("yes\n");
    else printf("no\n");
    fflush(stdout);
}

int main () {
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for (int i=0;i<N;++i) root[i] = NULL;
    root[k+1] = Build(1,n);
    vector<piii> seg;
    for (int i=1;i<=k;++i) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        seg.push_back( make_pair( make_pair(a,b) , c ) );
    }
    sort(seg.begin(),seg.end());
    for (int i=k;i>=1;--i) {
        //cout << "i = " << i << endl;
        int l = seg[i-1].F.F, r = seg[i-1].F.S, p = seg[i-1].S;
        //cout << "l = " << l << " , r = " << r << " , p = " << p << endl;
        root[i] = getNode(root[i+1]);
        modify(root[i+1],root[i],1,n,p,r);
    }
    while (m--) {
        int a,b,x,y;
        scanf("%d%d%d%d",&a,&b,&x,&y);
        auto iter = lower_bound(seg.begin(),seg.end(),make_pair( make_pair(x,-INF),-INF ));
        if (iter == seg.end()) {
            show_ans(false);
            continue;
        }
        int pos = (iter - seg.begin()) + 1;
        //cout << "pos = " << pos << " , Q = " << query(root[pos],1,n,a,b) << endl;
        if (query(root[pos],1,n,a,b) <= y) show_ans(true);
        else show_ans(false);
    }
}
#include <iostream>
#include <cstdio>
using namespace std;

struct Node {
    Node *lc,*rc;
    int sum;
    Node() {
        lc=rc=NULL;
        sum = 0;
    }
    void pull() {
        sum = lc->sum + rc->sum;
    }
};

const int N = 1e5 + 6;

int a[N];
int v[N];  //value for the first segment tree
int last[N];
int nxt[N];

Node* Build(int L,int R) {
    Node* node = new Node();
    if (L==R) {
        node->sum = v[L];
        return node;
    }
    int mid=(L+R)>>1;
    node->lc=Build(L,mid);
    node->rc=Build(mid+1,R);
    node->pull();
    return node;
}

Node* getNode(Node *old) {
    Node* ret = new Node();
    ret->lc=old->lc;
    ret->rc=old->rc;
    ret->sum = old->sum;
    return ret;
}

void modify(Node* old,Node* nnew,int L,int R,int pos,int val) {
    if(L==R) {
        nnew->sum = val;
        return;
    }
    int mid=(L+R)>>1;
    if(pos <= mid) {
        nnew->lc = getNode(old->lc);
        modify(old->lc,nnew->lc,L,mid,pos,val);
    }
    else {
        nnew->rc = getNode(old->rc);
        modify(old->rc,nnew->rc,mid+1,R,pos,val);
    }
    nnew->pull();
    return;
}

Node* root[N];
const int INF = 1e9 + 7;

int query(Node* node,int L,int R,int val) {
    //cout<<"L = "<<L<<" , R = "<<R<<" , val = "<<val<<endl;
    if (L==R && val+node->sum != 0) return -INF;
    if (L==R) return L;
    int mid = (L+R)>>1;
    if (node->lc->sum > val) return query(node->lc,L,mid,val);
    else if (node->lc->sum == val) return max(mid,query(node->rc,mid+1,R,val-node->lc->sum));
    else return query(node->rc,mid+1,R,val-node->lc->sum);
}

int main () {
    int n;
    scanf("%d",&n);
    for (int i=1;n>=i;i++) {
        scanf("%d",&a[i]);
        if (last[ a[i] ] == 0) {
            v[i] = 1;
            last[ a[i] ] = i;
        }
        else {
            int val=last[ a[i] ];
            nxt[val] = i;
            last[ a[i] ] = i;
        }
    }
    root[1] = Build(1,n);
    for (int i=2;n>=i;i++) {
        root[i] = getNode(root[i-1]);
        modify(root[i-1],root[i],1,n,i-1,0);
        if (nxt[i-1] != 0) {
            modify(root[i],root[i],1,n,nxt[i-1],1);
        }
    }
    for (int k=1;n>=k;k++) {
        int ans=0;
        int now=0;
        while (now != n) {
            ans++;
            now++;
            if (root[now]->sum <= k) break;
            //cout<<"now1 = "<<now<<endl;
            now = query(root[now],1,n,k);
            //cout<<"now2 = "<<now<<endl;
        }
        if (k!=1) printf(" ");
        printf("%d",ans);
    }
    puts("");
}
#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX_N = 1e6 + 6;

struct Node {
    Node *lc;
    Node *rc;
    int cnt;
    Node() {
        lc=rc=NULL;
        cnt=0;
    }
};

int Cnt(Node* t) {
    return t?t->cnt:0;
}

void pull(Node* node) {
    node->cnt = Cnt(node->lc) + Cnt(node->rc);
}

int pre[MAX_N];
int a[MAX_N];
int pow2[32];

void add(Node* node,int k,int id) {   //remember to start from 31
    //cout<<"k = "<<k<<" , id = "<<id<<endl;
    if (k==0) {
        node->cnt++;
        return;
    }
    else {
        if (id >= pow2[k-1]) {
            //digit 1
            if (!node->rc) node->rc= new Node();
            add(node->rc,k-1,id-pow2[k-1]);
        }
        else {
            //digit 0
            if (!node->lc) node->lc = new Node();
            add(node->lc,k-1,id);
        }
        pull(node);
    }
}

int query(Node* node,int k,int id,int depth) {  //depth from 31
    //cout<<"k = "<<k<<" , id = "<<id<<", depth = "<<depth<<endl;
    if (!node) return 0;
    else if (depth == 0) return node->cnt;
    int digitk,digitid;
    if (k >= pow2[depth-1]) digitk=1;
    else digitk=0;
    if (id >= pow2[depth-1]) digitid=1;
    else digitid=0;
    if (digitk==1 && digitid == 1) {
        return query(node->lc,k-pow2[depth-1],id-pow2[depth-1],depth-1);
    }
    else if (digitk == 1 && digitid == 0) {
        return query(node->rc,k-pow2[depth-1],id,depth-1);
    }
    else if (digitk == 0 &&digitid == 1) {
        return Cnt(node->lc) + query(node->rc,k,id-pow2[depth-1],depth-1);
    }
    else {
        return Cnt(node->rc) + query(node->lc,k,id,depth-1);
    }
}

int main () {
    pow2[0]=1;
    for (int i=1;32>i;i++) {
        pow2[i] = pow2[i-1]*2;
    }
    int n,k;
    while (scanf("%d %d",&n,&k) != EOF) {
        Node *root = new Node();
        pre[0]=0;
        for (int x=1;n>=x;x++) {
            scanf("%d",&a[x]);
            pre[x] = pre[x-1] ^ a[x];
        }
        add(root,31,0);
        long long ans=0;
        for (int i=1;n>=i;i++) {
            ans += query(root,k,pre[i],31);
            //cout<<"\n\nans = "<<ans<<"\n\n";
            add(root,31,pre[i]);
        }
        printf("%I64d\n",ans);
    }
}
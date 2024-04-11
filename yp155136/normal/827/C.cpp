#include <iostream>
#include <stdio.h>
#include <vector>
#include <cassert>
using namespace std;

const int MAX_N = 1e5 + 6;
vector<int> v;

struct SegmentTree {
    struct Node {
        Node *lc,*rc;
        int val[4];
        Node() {
            lc=rc=NULL;
            for (int i=0;4>i;i++) val[i]=0;
        }
        void pull() {
            for (int i=0;4>i;i++) val[i] = lc->val[i] + rc->val[i];
        }
    };
    Node* root;
    Node* Build(int L,int R) {
        Node* node = new Node();
        if (L==R) {
            node->val[ v[L] ]=1;
            return node;
        }
        int mid=(L+R)>>1;
        node->lc=Build(L,mid);
        node->rc=Build(mid+1,R);
        node->pull();
        return node;
    }
    int n;
    void init(int _n) {
        n=_n;
        root=Build(0,n);
    }
    void modify(Node* node,int L,int R,int pos,int before,int after) {
        if (L==R) {
            node->val[before]--;
            node->val[after]++;
            return;
        }
        int mid=(L+R)>>1;
        if (pos <= mid) modify(node->lc,L,mid,pos,before,after);
        else modify(node->rc,mid+1,R,pos,before,after);
        node->pull();
        return;
    }
    int query(Node* node,int L,int R,int l,int r,int id) {
        if (l>R || L>r) return 0;
        else if (l<=L && R<=r) return node->val[id];
        int mid=(L+R)>>1;
        return query(node->lc,L,mid,l,r,id) + query(node->rc,mid+1,R,l,r,id);
    }
    void change(int pos,int before,int after) {
        modify(root,0,n,pos,before,after);
    }
    int QQ(int l,int r,int id) {
        return query(root,0,n,l,r,id);
    }
} seg[11][11];

int f(char c) {
    if (c=='A') return 0;
    else if (c=='C') return 1;
    else if (c=='G') return 2;
    else if (c=='T') return 3;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    if (s.size() < 10) {
        int q;
        cin >>q;
        while (q--) {
            int op;
            cin >> op;
            if (op==1) {
                int a;
                char b;
                cin >> a >> b;
                a--;
                s[a]=b;
            }
            else {
                int l,r;
                string ss;
                cin >> l >> r >> ss;
                l--;
                r--;
                int id=0;
                int ans=0;
                for (int i=l;r>=i;i++) {
                    ans += (s[i]==ss[id]);
                    id = (id+1)%(int)ss.size();
                }
                cout<<ans<<endl;
            }
        }
    }
    else {
        for (int len=1;10>=len;len++) {
            for (int start=0;len>start;start++) {
                v.clear();
                int cnt=0;
                for (int i=start;(int)s.size()>i;i+=len) {
                    v.push_back(f(s[i]));
                    cnt++;
                }
                //cout<<"len = "<<len <<", start = "<<start<<" , cnt ="<<cnt<<endl;
                seg[len][start].init( cnt-1 );
            }
        }
        int q;
        cin >> q;
        while (q--) {
            int op;
            cin >> op;
            if (op==1) {
                int pos;
                char c;
                cin >> pos >> c;
                pos--;
                if (s[pos] == c) continue;
                for (int len=1;10>=len;len++) {
                    seg[len][pos%len].change(pos/len,f(s[pos]),f(c));
                }
                s[pos] = c;
            }
            else {
                int l,r;
                string ss;
                cin >> l >> r >> ss;
                l--;
                r--;
                if (r-l+1 < (int)ss.size()) {
                    int id=0;
                    int ans=0;
                    for (int i=l;r>=i;i++) {
                        ans += s[i]==ss[id++];
                    }
                    cout<<ans<<endl;
                }
                else {
                    int ans=0;
                    int len=ss.size();
                    for (int i=0;ss.size()>i;i++) {
                        //cout<<"i = "<<i<<" , ans = "<<ans<<" , l = "<<(l+i)/len<<" , r = "<<r/len<<endl;
                        ans += seg[len][(l+i)%len].QQ((l+i)/len,(r - (l+i)%len)/len,f(ss[i]));
                    }
                    cout<<ans<<endl;
                }
            }
        }
    }
}
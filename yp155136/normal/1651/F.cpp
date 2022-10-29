#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
const int N = 200006;

ll c[N], r[N];
ll over_full[N];

struct Node {
  Node *lc, *rc;
  ll sum;
  Node(): lc(NULL), rc(NULL), sum(0){}
  void pull() {
    sum = lc->sum + rc->sum;
  }
};

Node* Build(int L, int R) {
  Node* node = new Node();
  if (L == R) return node;
  int mid = (L + R) >> 1;
  node->lc = Build(L, mid);
  node->rc = Build(mid + 1, R);
  return node;
}

Node* getNode(Node* old) {
  Node* node = new Node();
  node->lc = old->lc;
  node->rc = old->rc;
  node->sum = old->sum;
  return node;
}

void modify(Node* old, Node* node, int L, int R, int pos, ll del) {
  if (L == R) {
    node->sum += del;
    return;
  }
  int mid = (L + R) >> 1;
  if (pos <= mid) {
    node->lc = getNode(old->lc);
    modify(old->lc, node->lc, L, mid, pos, del);
  }
  else {
    node->rc = getNode(old->rc);
    modify(old->rc, node->rc, mid + 1, R, pos, del);
  }
  node->pull();
  return;
}

ll query(Node* node, int L, int R, int l, int r) {
  if (l > R || L > r) return 0;
  else if (l <= L && R <= r) {
    return node->sum;
  }
  int mid = (L + R) >> 1;
  return query(node->lc, L, mid, l, r) + query(node->rc, mid + 1, R, l, r);
}

Node* root1[N];
Node* root2[N];

struct Seg {
  int l, r; // [l, r]
  int type; // type 1: dead at T = ?, type 2 : survive at T = ?, live = ?, type 3: full live
  ll T;
  ll live;
  Seg(int _l, int _r, int _type, ll _T, ll _live): l(_l), r(_r), type(_type), T(_T), live(_live){}
};

int n;
int nn = 200004;
deque<Seg> dq;
ll pre[N];

ll Sum(ll t, Seg sg) {
  if (sg.type == 3) {
    // return query(root2[sg.r], 1, nn, 1, nn) - query(root2[sg.l - 1], 1, nn, 1, nn);
    return pre[sg.r] - pre[sg.l - 1];
  }
  else if (sg.type == 2) {
    assert(sg.l == sg.r);
    ll now = min(c[sg.l], sg.live + r[sg.l] * (t - sg.T));
    return now;
  }
  else if (sg.type == 1){
    ll del = t - sg.T;
    // ll full_live = query(root2[sg.r], 1, nn, 1, del) - query(root2[sg.l - 1], 1, nn, 1, del);
    // ll slope = query(root1[sg.r], 1, nn, 1, del) - query(root1[sg.l - 1], 1, nn, 1, del);
    ll full_live = query(root2[del], 1, n, sg.l, sg.r);
    ll slope = query(root1[del], 1, n, sg.l, sg.r);
    return full_live + slope * del;
  }
  assert(0);
}

ll bs(Node* r1, Node* r2, int L, int R, ll h, ll pre_live, ll pre_slope, ll del) {
  if (L == R) {
    return L;
  }
  int mid = (L + R) >> 1;
  ll val = (pre_live + r2->lc->sum) + (pre_slope + r1->lc->sum) * del;
  if (val <= h) {
    return bs(r1->rc, r2->rc, mid + 1, R, h, pre_live + r2->lc->sum, pre_slope + r1->lc->sum, del);
  }
  else {
    return bs(r1->lc, r2->lc, L, mid, h, pre_live, pre_slope, del);
  }
}

ll go() {
  ll t, h; cin >> t >> h;
  ll last_dead = 0;
  while ((int)dq.size() > 0) {
    Seg sg = dq.front();
    ll _ = Sum(t, sg);
    if (h >= _) {
      // all defeated
      h -= _;
      dq.pop_front();
      last_dead = sg.r;
    }
    else {
      if (sg.type == 1) {
        /*
        int l = sg.l - 1, r = sg.r;
        while (r - l > 1) {
          int mid = (l + r) >> 1;
          if (Sum(t, Seg(sg.l, mid, sg.type, sg.T, sg.live)) <= h) {
            l = mid;
          }
          else {
            r = mid;
          }
        }
        */
        ll del = t - sg.T;
        ll pre_live = query(root2[del], 1, n, 1, sg.l - 1);
        ll pre_slope = query(root1[del], 1, n, 1, sg.l - 1);
        int l = bs(root1[del], root2[del], 1, n, h, -pre_live, -pre_slope, del) - 1;
        int r = l + 1;
        last_dead = l;
        dq.pop_front();
        if (r + 1 <= sg.r) {
          dq.push_front(Seg(r + 1, sg.r, sg.type, sg.T, sg.live));
        }
        ll left = Sum(t, Seg(sg.l, r, sg.type, sg.T, sg.live)) - h;
        dq.push_front(Seg(r, r, 2, t, left));
      }
      else if (sg.type == 2) {
        dq.pop_front();
        dq.push_front(Seg(sg.l, sg.l, 2, t, _ - h));
      }
      else if (sg.type == 3) {
        int l = sg.l - 1, r = sg.r;
        while (r - l > 1) {
          int mid = (l + r) >> 1;
          if (Sum(t, Seg(sg.l, mid, sg.type, sg.T, sg.live)) <= h) {
            l = mid;
          }
          else {
            r = mid;
          }
        }
        last_dead = l;
        dq.pop_front();
        if (r + 1 <= sg.r) {
          dq.push_front(Seg(r + 1, sg.r, sg.type, sg.T, sg.live));
        }
        ll left = Sum(t, Seg(sg.l, r, sg.type, sg.T, sg.live)) - h;
        dq.push_front(Seg(r, r, 2, t, left));
      }
      h = 0;
      break;
    }
  }
  if (last_dead != 0) {
    dq.push_front(Seg(1, last_dead, 1, t, -1));
  }
  return h;
}

vector<int> v_over[N];

int main () {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  ll r_sum = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> c[i] >> r[i];
    pre[i] = pre[i - 1] + c[i];
    over_full[i] = c[i] / r[i] + 1;
    if (over_full[i] > 200003) {
      over_full[i] = 200003;
    }
    v_over[over_full[i]].push_back(i);
  }
  /*
  root1[0] = Build(1, nn);
  for (int i = 1; i <= n; ++i) {
    root1[i] = getNode(root1[i - 1]);
    modify(root1[i], root1[i], 1, nn, 1, r[i]);
    modify(root1[i], root1[i], 1, nn, over_full[i], -r[i]);
  }
  root2[0] = Build(1, nn);
  for (int i = 1; i <= n; ++i) {
    root2[i] = getNode(root2[i - 1]);
    modify(root2[i], root2[i], 1, nn, over_full[i], c[i]);
  }*/
  root1[0] = Build(1, n);
  for (int i = 1; i <= nn; ++i) {
    root1[i] = getNode(root1[i - 1]);
    if (i == 1) {
      for (int j = 1; j <= n; ++j) {
        modify(root1[i], root1[i], 1, n, j, r[j]);
      }
    }
    else {
      for (int j : v_over[i]) {
        modify(root1[i], root1[i], 1, n, j, -r[j]);
      }
    }
  }
  root2[0] = Build(1, n);
  for (int i = 1; i <= nn; ++i) {
    root2[i] = getNode(root2[i - 1]);
    for (int j : v_over[i]) {
      modify(root2[i], root2[i], 1, n, j, c[j]);
    }
  }
  dq.push_back(Seg(1, n, 3, -1, -1));
  int q; cin >> q;
  ll ans = 0;
  for (int i = 1; i <= q; ++i) {
    ans += go();
  }
  cout << ans << endl;
}
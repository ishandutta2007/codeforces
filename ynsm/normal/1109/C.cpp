#include <bits/stdc++.h>                                                                                                                                                                                      //YaLoh

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e5 + 123, M = (int)2e5 + 123;
const double eps = 1e-10;

struct node{
	bool empty;
	int l, r;
	ll last, need, carry;
	node(){
		empty = 1;
	}
	node(int t, int s){
		empty = 0;
		l = r = t;
		last = s;
		need = carry = 1;
	}
    void Merge(node a, node b){
		if(a.empty && b.empty){
			empty = 1;
			return;
		}
		empty = 0; 
		if(a.empty){
			l = b.l;
			r = b.r;
			last = b.last;
			need = b.need;
			carry = b.carry;
			return;
		}
        if(b.empty){
			l = a.l;
			r = a.r;
			last = a.last;  
			need = a.need;
			carry = a.carry;
			return;
		}
		l = a.l;
		r = b.r;
		last = b.last;
		if(a.last < 0)                     
			b.need -= (b.l - a.r) * a.last;
		else
			a.carry += (b.l - a.r) * a.last;
		if(a.carry >= b.need){
			need = a.need;
			carry = a.carry - b.need + b.carry;
		}else{
			need = a.need + b.need - a.carry;
			carry = b.carry;
		}
	}
} t[M << 2];
int n, q, type[N], ti[N], s[N], l[N], r[N], w[N];
vector< int > vec;

ll ss, tt, cur;
bool was, fnd;
double ans;
void build(int v, int tl, int tr){
	if(tl == tr){
		t[v] = node();
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);
	t[v].Merge(t[v << 1], t[v << 1 | 1]);
}
void upd(int v, int tl, int tr, int pos, int val){
	if(tl == tr){
		t[v] = node(vec[pos - 1], val);
		return;
	}
	int tm = (tl + tr) >> 1;
	if(pos <= tm)                     
		upd(v << 1, tl, tm, pos, val);
	else
		upd(v << 1 | 1, tm + 1, tr, pos, val);
	t[v].Merge(t[v << 1], t[v << 1 | 1]);
}
void del(int v, int tl, int tr, int pos){
	if(tl == tr){
		t[v] = node();
		return;
	}
	int tm = (tl + tr) >> 1;
	if(pos <= tm)                     
		del(v << 1, tl, tm, pos);
	else
		del(v << 1 | 1, tm + 1, tr, pos);
	t[v].Merge(t[v << 1], t[v << 1 | 1]);
}
void get(int v, int tl, int tr, int l){
	if(tr < l || fnd)
		return;
	int tm = (tl + tr) >> 1;
	if(l <= tl){
		if(!t[v].empty){
			if(!was){
				was = 1;
				tt = t[v].l;
				ss = 0;
			}
			if(cur + (t[v].l - tt) * ss < 1){
				fnd = 1;
				ans = tt - 1.0 * cur / ss;	
				return;
			}
			cur += (t[v].l - tt) * ss;
			tt = t[v].l;
			if(cur >= t[v].need){
				tt = t[v].r;
				ss = t[v].last;
				cur = cur - t[v].need + t[v].carry;
				return;
			}
			get(v << 1, tl, tm, l);
			get(v << 1 | 1, tm + 1, tr, l);
		}
		return;
	}
	get(v << 1, tl, tm, l);
	get(v << 1 | 1, tm + 1, tr, l);
}
int main()
{
	scanf("%d", &q);
	for(int i = 1; i <= q; i++){
		scanf("%d", &type[i]);
		if(type[i] == 1){
			scanf("%d%d", &ti[i], &s[i]);
			vec.pb(ti[i]);
		}
        if(type[i] == 2){
        	scanf("%d", &ti[i]);
		}
		if(type[i] == 3){
			scanf("%d%d%d", &l[i], &r[i], &w[i]);
			vec.pb(l[i]);
			vec.pb(r[i]);
		}
	}
	sort(vec.begin(), vec.end());
	n = vec.size();
	build(1, 1, n);
    for(int i = 1; i <= q; i++){
		if(type[i] == 1){
			int id = lower_bound(vec.begin(), vec.end(), ti[i]) - vec.begin() + 1;
			upd(1, 1 , n, id, s[i]);
		}
        if(type[i] == 2){
			int id = lower_bound(vec.begin(), vec.end(), ti[i]) - vec.begin() + 1;
			del(1, 1 , n, id);
		}
		if(type[i] == 3){
			if(w[i] == 0){
				printf("%.10f\n", 0.0 + l[i]); 
				continue;
			}
			int id = lower_bound(vec.begin(), vec.end(), l[i]) - vec.begin() + 1;
			fnd = was = 0;
			cur = w[i];
			get(1, 1, n, id);
			if(!fnd){
				if(was){
					if(ss >= 0)
						ans = 2e9;
					else
						ans = tt - 1.0 * cur / ss;
				}else{
					ans = -1;
				}
			}
			if(ans > r[i])
				ans = -1;
		    if(ans == -1)
		    	printf("-1\n");
			else
				printf("%.10f\n", ans); 
		}
	}
	return 0;
}
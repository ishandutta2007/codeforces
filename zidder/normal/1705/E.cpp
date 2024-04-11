#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void remember(void* p);
void forget(void* p);

struct Lst {
    int l;
    int r;
    // [l, r)
    bool b;
    Lst* nxt=nullptr;
    Lst(int l, int r, bool b): l(l), r(r), b(b) {
        remember(this);
    }
    ~Lst(){
        if (nxt != nullptr) delete nxt;
    }
};

map<int, Lst*> lst;

void addd(int ind) {
    auto it = lst.upper_bound(ind);
    --it;
    Lst* l = it->second;
    if (l->b) {
        int r = l->r;
        if (l->l == ind) {
            forget(l);
            it = lst.upper_bound(ind);
            auto it2 = it;
            --it;
            it->second->r = it2->second->r;
            Lst* l2 = it2->second;
            forget(l2);
            delete l2;
            delete l;
        } else {
            l->r = ind;
            ++it;
            Lst* l2 = it->second;
            forget(l2);
            l2->l = ind;
            remember(l2);
        }
        addd(r);
    } else {
        if (ind == l->l && ind + 1 == l->r) {
            forget(l);
            delete l;
            it = lst.upper_bound(ind); // nxt
            auto itp = it; // prev
            itp--;
            Lst* l2 = it->second;
            forget(l2);
            itp->second->r = l2->r;
            delete l2;
        } else if (ind == l->l) {
            forget(l);
            l->l++;
            remember(l);
            auto it = lst.upper_bound(ind);
            --it;
            it->second->r++;
        } else if (ind + 1 == l->r) {
            l->r--;
            it++;
            Lst* l2 = it->second;
            forget(l2);
            l2->l--;
            remember(l2);
        } else {
            int r = l->r;
            l->r = ind;
            remember(new Lst(ind, ind+1, true));
            remember(new Lst(ind+1, r, false));
        }
    }
}
void subb(int ind) {
    auto it = lst.upper_bound(ind);
    --it;
    Lst* l = it->second;
    if (!(l->b)) {
        int r = l->r;
        if (l->l == ind) {
            forget(l);
            it = lst.upper_bound(ind);
            auto it2 = it;
            --it;
            it->second->r = it2->second->r;
            Lst* l2 = it2->second;
            forget(l2);
            delete l2;
            delete l;
        } else {
            l->r = ind;
            ++it;
            Lst* l2 = it->second;
            forget(l2);
            l2->l = ind;
            remember(l2);
        }
        subb(r);
    } else {
        if (ind == l->l && ind + 1 == l->r) {
            forget(l);
            delete l;
            it = lst.upper_bound(ind); // nxt
            auto itp = it; // prev
            itp--;
            Lst* l2 = it->second;
            forget(l2);
            itp->second->r = l2->r;
            delete l2;
        } else if (ind == l->l) {
            forget(l);
            l->l++;
            remember(l);
            auto it = lst.upper_bound(ind);
            --it;
            it->second->r++;
        } else if (ind + 1 == l->r) {
            l->r--;
            it++;
            Lst* l2 = it->second;
            forget(l2);
            l2->l--;
            remember(l2);
        } else {
            int r = l->r;
            l->r = ind;
            remember(new Lst(ind, ind+1, false));
            remember(new Lst(ind+1, r, true));
        }
    }
}


void remember(void* p){
    auto l = (Lst*) p;
    lst[l->l] = l;
}

void forget(void* p) {
    lst.erase(((Lst*)p)->l);
}

void solve(int test_ind){
    int n, q;
    cin >> n >> q;
    Lst* head = new Lst(0, 200035, 0);
    vector<int> a(n);
    for (int i=0;i<n;++i) {
        scanf("%d", &a[i]);
        // for (auto &p: lst) {
        //     cout << p.second->l << " " << p.second -> r << " " << p.second->b << endl;
        // }
        // cout << endl;
        // cout << a[i] << endl;
        addd(a[i]);
    }
        // for (auto &p: lst) {
        //     cout << p.second->l << " " << p.second -> r << " " << p.second->b << endl;
        // }
        // cout << endl;
    for (int i=0;i<q;++i) {
        int ind, val;
        scanf("%d%d", &ind, &val);
        ind--;
        subb(a[ind]);
        a[ind] = val;
        addd(a[ind]);

        // for (auto &p: lst) {
        //     cout << p.first << " " << p.second->l << " " << p.second -> r << " " << p.second->b << endl;
        // }
        // cout << endl;
        auto it = lst.rbegin();
        // cout << it->first << " " << it->second->r << endl;
        ++it;
        // cout << it->first << " " << it->second->r << endl;
        printf("%d\n", (it->second->r)-1);
    }
    delete head;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}
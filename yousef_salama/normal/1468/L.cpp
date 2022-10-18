#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()

typedef unsigned long long ull;
typedef long long ll;

ull modmul(ull a, ull b, ull M) {
	ll ret = a * b - M * ull(1.L / M * a * b);
	return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull mod) {
	ull ans = 1;
	for (; e; b = modmul(b, b, mod), e /= 2)
		if (e & 1) ans = modmul(ans, b, mod);
	return ans;
}
bool isPrime(ull n) {
	if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
	ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
	    s = __builtin_ctzll(n-1), d = n >> s;
	for (ull a : A) {   // ^ count trailing zeroes
		ull p = modpow(a%n, d, n), i = s;
		while (p != 1 && p != n - 1 && a % n && i--)
			p = modmul(p, p, n);
		if (p != n-1 && i != s) return 0;
	}
	return 1;
}
ull pollard(ull n) {
	auto f = [n](ull x) { return modmul(x, x, n) + 1; };
	ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
	while (t++ % 40 || __gcd(prd, n) == 1) {
		if (x == y) x = ++i, y = f(x);
		if ((q = modmul(prd, max(x,y) - min(x,y), n))) prd = q;
		x = f(x), y = f(f(y));
	}
	return __gcd(prd, n);
}
vector<ull> factor(ull n) {
	if (n == 1) return {};
	if (isPrime(n)) return {n};
	ull x = pollard(n);
	auto l = factor(x), r = factor(n / x);
	l.insert(l.end(), all(r));
	return l;
}   

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    vector <long long> a(n);
    vector < vector <ull> > v(n);
    for(int i = 0; i < n; i++){
        scanf("%lld", &a[i]);

        v[i] = factor(a[i]);
        
        sort(v[i].begin(), v[i].end());
        v[i].resize(unique(v[i].begin(), v[i].end()) - v[i].begin());
    }

    vector < vector <long long> > g;
    vector <long long> w;
    set <long long> primes;

    for(int i = 0; i < n; i++)if(v[i].size() == 1){
        bool found = false;
        for(int j = 0; j < (int)w.size(); j++){
            if(w[j] == v[i][0]){
                g[j].push_back(a[i]);
                found = true;
            }
        }
        if(!found){
            w.push_back(v[i][0]);
            g.push_back(vector <long long> ());
            g.back().push_back(a[i]);
        }
    }
    for(int i = 0; i < (int)w.size(); i++)if(g[i].size() >= 2){
        primes.insert(w[i]);
    }
/*
    for(int i = 0; i < n; i++){
        cout << a[i] << " :: ";
        for(long long x : v[i])
            cout << x << ' ';
        cout << endl;
    }*/

    vector <bool> removed(n, false);

    int mn_ind = -1, mn_size;
    for(int i = 0; i < n; i++)if(v[i].size() > 1){
        for(long long x : v[i]){
            if(!primes.count(x)){
                removed[i] = true;
                break;
            }
        }

        if(!removed[i]){
            if(mn_ind == -1 || mn_size > (int)v[i].size()){
                mn_ind = i;
                mn_size = v[i].size();
            }
        }
    }

    int p3 = -1;
    for(int i = 0; i < (int)w.size(); i++)if(g[i].size() >= 3){
        p3 = i;
        break;
    }

    if(k == 1){
        printf("0\n");
        return 0;
    }

    set <long long> res;

    if(p3 != -1){
        if(k <= (int)g[p3].size()){
            for(int j = 0; j < k; j++)
                res.insert(g[p3][j]);
            k = 0;
        }else{
            for(long long x : g[p3])
                res.insert(x);
            k -= (int)g[p3].size();
            long long to_remove = g[p3][0];

            for(int i = 0; i < (int)w.size(); i++)if(i != p3 && g[i].size() >= 2){
                if(k == 1){
                    res.erase(to_remove);
                    for(int j = 0; j < 2; j++)
                        res.insert(g[i][j]);
                    k = 0;
                    break;
                }else if(k <= (int)g[i].size()){
                    for(int j = 0; j < k; j++)
                        res.insert(g[i][j]);
                    k = 0;
                    break;
                }else{
                    for(long long x : g[i])
                        res.insert(x);
                    k -= (int)g[i].size();
                }
            }
        }
    }else{
        if(mn_ind == -1){
            if(k % 2 == 1){
                printf("0\n");
                return 0;
            }

            for(int i = 0; i < (int)w.size(); i++)if(g[i].size() >= 2){
                if(k <= (int)g[i].size()){
                    for(int j = 0; j < k; j++)
                        res.insert(g[i][j]);
                    k = 0;
                    break;
                }else{
                    for(long long x : g[i])
                        res.insert(x);
                    k -= (int)g[i].size();
                }
            }
        }else{
            vector <bool> vis(w.size(), false);
            for(long long x : v[mn_ind]){
                for(int i = 0; i < (int)w.size(); i++)if(w[i] == x){
                    vis[i] = true;
                    if(k == 1){
                        printf("0\n");
                        return 0;
                    }else if(k <= (int)g[i].size()){
                        for(int j = 0; j < k; j++)
                            res.insert(g[i][j]);
                        k = 0;
                        break;
                    }else{
                        for(long long x : g[i])
                            res.insert(x);
                        k -= (int)g[i].size();
                    }
                }
                if(k == 0)break;
            }

            if(k > 0){
                res.insert(a[mn_ind]);
                long long to_remove = a[mn_ind];
                removed[mn_ind] = true;
                k--;

                for(int i = 0; i < (int)w.size() && k > 0; i++)if(!vis[i] && g[i].size() >= 2){
                    if(k == 1){
                        res.erase(to_remove);
                        for(int j = 0; j < 2; j++)
                            res.insert(g[i][j]);
                        k = 0;
                        break;
                    }else if(k <= (int)g[i].size()){
                        for(int j = 0; j < k; j++)
                            res.insert(g[i][j]);
                        k = 0;
                        break;
                    }else{
                        for(long long x : g[i])
                            res.insert(x);
                        k -= (int)g[i].size();
                    }
                }
            }
        }
    }
    
    for(int i = 0; k > 0 && i < n; i++)if(v[i].size() > 1 && !removed[i]){
        res.insert(a[i]);
        k--;
    }

    if(k != 0)printf("0\n");
    else{
        bool first = true;
        for(long long x : res){
            if(first)first = false;
            else printf(" ");

            printf("%lld", x);
        }
        printf("\n");
    }

    return 0;
}
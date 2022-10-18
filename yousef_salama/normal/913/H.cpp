#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int UNIT = 1000000;
const int LEN = 6;
const int INV_UNIT = 616898040;

long long modpow(long long x, long long p){
    if(p == 0)return 1;
    if(p % 2 == 1)return x * modpow(x, p - 1) % MOD;

    long long r = modpow(x, p / 2);
    return r * r % MOD;
}
long long modinv(long long x){
    return modpow(x, MOD - 2);
}

struct yasser{
    struct term{
        int degree, a, b;
        long long coeff;

        term(){}
        term(int degree, int a, int b): degree(degree), a(a), b(b), coeff(1){}
        term(int degree, int a, int b, long long coeff): degree(degree), a(a), b(b), coeff(coeff){}

        bool operator <(const term& t) const{
            if(b != t.b)return b < t.b;
            else return degree < t.degree;
        }
    };
    
    static void expand(vector <term>& v, const term& t, int d){
        long long coeff_ = t.coeff;
        for(int i = t.degree; i >= 0; i--){
            v.push_back(term(i, t.a, t.b, coeff_));
            if(i > 0){
                coeff_ = coeff_ * d % MOD;
                coeff_ = coeff_ * i % MOD * modinv(t.degree - i + 1) % MOD;
            }
        }
    }

    vector <term> v;
    bool empty;

    yasser(){
        empty = true;
    }

    void convolution(){
        if(empty){
            v.push_back(term(0, 0, UNIT, INV_UNIT));
            empty = false;
            return;
        }

        vector <term> v_;
        for(term& t: v){
            long long coeff_ = t.coeff * modinv(t.degree + 1) % MOD * INV_UNIT % MOD;

            v_.push_back(term(t.degree + 1, t.a, t.b, coeff_));
            v_.push_back(term(0, t.b, t.b + UNIT, coeff_ * modpow(t.b, t.degree + 1) % MOD));

            v_.push_back(term(0, t.a, t.a + UNIT, (MOD - coeff_) * modpow(t.a, t.degree + 1) % MOD));
            expand(v_, term(t.degree + 1, t.a + UNIT, t.b + UNIT, (MOD - coeff_) % MOD), (MOD - UNIT) % MOD);
        }
        v = v_;
    }

    void trim(int x){
        vector <term> v_;
        for(term& t : v){
            if(t.b <= x)v_.push_back(t);
            else if(t.a >= x)continue;
            else v_.push_back(term(t.degree, t.a, x, t.coeff));
        }
        v = v_;
    }
    long long eval(){
        long long res = 0;
        for(term& t : v){
            long long c = t.coeff * modinv(t.degree + 1) % MOD;

            long long cur = (modpow(t.b, t.degree + 1) - modpow(t.a, t.degree + 1) + MOD) % MOD;
            res = (res + c * cur) % MOD;

            //printf("degree = %d, [%d,%d], coeff = %lld || c = %lld, cur = %lld\n", t.degree, t.a, t.b, t.coeff, c, cur);
        }
        return res;
    }
    void normalize_1(){
        vector <term> v_;
        for(term& t : v){
            if(t.a == 0)v_.push_back(t);
            else{
                v_.push_back(term(t.degree, 0, t.b, t.coeff));
                v_.push_back(term(t.degree, 0, t.a, (MOD - t.coeff) % MOD));
            }
        }
        v = v_;
    }
    void normalize_2(){
        sort(v.begin(), v.end());
        
        vector <term> v_;
        for(int i = 0; i < (int)v.size(); ){
            int j = i;
            long long total = 0;

            while(j < (int)v.size() && v[j].b == v[i].b && v[j].degree == v[i].degree){
                total = (total + v[j].coeff) % MOD;    
                j++;
            }
            v_.push_back(term(v[i].degree, v[i].a, v[i].b, total));

            i = j;
        }
        v = v_;
    }
    void fix(){
        normalize_1();
        normalize_2();
    }
    void print(){
        printf("-------BEGIN PRINTING-------\n");
        for(term& t: v){
            printf("degree = %d, [%d,%d], coeff = %lld\n", t.degree, t.a, t.b, t.coeff);
        }
        printf("-------END PRINTING---------\n");
    }
};



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    yasser y;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;

        size_t u = s.find('.');
        int x;

        if(u == string::npos){
            x = UNIT * stoi(s);
        }else{
            int a = (int)s.size() - u - 1;
            int f = 1;
            while(a < LEN){
                f *= 10;
                a++;
            }

            x = UNIT * stoi(s.substr(0, u)) + f * stoi(s.substr(u + 1));
        }

        //printf("x = %d\n", x);
        y.convolution();
        //y.print();
        y.trim(x);
        //y.print();
        y.fix();
        //y.print();
    }
    printf("%lld\n", y.eval());

    return 0;
}
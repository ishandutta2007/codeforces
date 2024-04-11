#include "bits/stdc++.h"
#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<iomanip>
#include<assert.h>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<stack>
#include<complex>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;
	
#define WHATS(var)cout<<__LINE__<<' '<<#var<<"="<<var<<endl;
	
template<class S, class T> ostream& operator <<(ostream &os, const pair<S, T> v){
	os << "( " << v.first << ", " << v.second << ")"; return os;
}
template<class T> ostream& operator <<(ostream &os, const vector<T> &v){
	for(int i = 0; i < v.size(); i++){if(i > 0){os << " ";} os << v[i];} return os;
}
template<class T> ostream& operator <<(ostream &os, const vector<vector<T>> &v){
	for(int i = 0; i < v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}
template<class T> ostream& operator <<(ostream &os, const vector<set<T>> &v){
	for(int i = 0; i < v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}
template<class T> ostream& operator <<(ostream &os, const set<T> &v){
	int i=0;
	for(auto it:v){
		if(i > 0){os << ' ';}
		os << it;
		i++;
	} 
	return os;
}
int xx;

using ll =long long ;
// MAX_N is max size of OUTPUT, DOUBLED INPUT
// MAX_RES_VALUE = MAX_VALUE^2 * MAX_N
// if MAX_N > 2^20, comment out primes!
// NTT {{{
#include <cassert>
#include <cstdint>
#include <vector>

namespace NTT {
using uint = uint_fast32_t;

// NTT_PRIMES {{{
constexpr ll NTT_PRIMES[][2] = {
    {1224736769, 3}, // 2^24 * 73 + 1,
    {1053818881, 7}, // 2^20 * 3 * 5 * 67 + 1
    {1051721729, 6}, // 2^20 * 17 * 59 + 1
    {1045430273, 3}, // 2^20 * 997 + 1
    {1012924417, 5}, // 2^21 * 3 * 7 * 23 + 1
    {1007681537, 3}, // 2^20 * 31^2 + 1
    {1004535809, 3}, // 2^21 * 479 + 1
    {998244353, 3},  // 2^23 * 7 * 17 + 1
    {985661441, 3},  // 2^22 * 5 * 47 + 1
    {976224257, 3},  // 2^20 * 7^2 * 19 + 1
    {975175681, 17}, // 2^21 * 3 * 5 * 31 + 1
    {962592769, 7},  // 2^21 * 3^3 * 17 + 1
    {950009857, 7},  // 2^21 * 4 * 151 + 1
    {943718401, 7},  // 2^22 * 3^2 * 5^2 + 1
    {935329793, 3},  // 2^22 * 223 + 1
    {924844033, 5},  // 2^21 * 3^2 * 7^2 + 1
    {469762049, 3},  // 2^26 * 7 + 1
    {167772161, 3},  // 2^25 * 5 + 1
};
// }}}

// general math {{{
ll extgcd(ll a, ll b, ll &x, ll &y) {
  ll d;
  return b == 0 ? (x = a < 0 ? -1 : 1, y = 0, a < 0 ? -a : a)
                : (d = extgcd(b, a % b, y, x), y -= a / b * x, d);
}
ll modinv(ll a, ll mod) {
  ll x, y;
  extgcd(a, mod, x, y);
  x %= mod;
  return x < 0 ? x + mod : x;
}
ll modpow(ll a, ll b, ll mod) {
  ll r = 1;
  a %= mod;
  while(b) {
    if(b & 1) r = r * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return r;
}
// }}}

// NTT Core {{{
template < int MAX_H >
struct Pool {
  static ll *tmp, *A, *B;
};
template < int MAX_H >
ll *Pool< MAX_H >::tmp = new ll[1 << MAX_H];
template < int MAX_H >
ll *Pool< MAX_H >::A = new ll[1 << MAX_H];
template < int MAX_H >
ll *Pool< MAX_H >::B = new ll[1 << MAX_H];

template < int MAX_H, ll mod, ll primitive >
class Core {
public:
  static_assert((mod & ((1 << MAX_H) - 1)) == 1, "mod is too small; comment out");
  // ord zetaList[i] = 2^(i + 1)
  ll zetaList[MAX_H], zetaInvList[MAX_H];
  // constexpr
  Core() {
    zetaList[MAX_H - 1] = modpow(primitive, (mod - 1) / (1 << MAX_H), mod);
    zetaInvList[MAX_H - 1] = modinv(zetaList[MAX_H - 1], mod);
    for(int ih = MAX_H - 2; ih >= 0; --ih) {
      zetaList[ih] = zetaList[ih + 1] * zetaList[ih + 1] % mod;
      zetaInvList[ih] = zetaInvList[ih + 1] * zetaInvList[ih + 1] % mod;
    }
  }
  void fft(ll *a, uint n, uint nh, bool inverse) const {
    ll *tmp = Pool< MAX_H >::tmp;
    uint mask = n - 1;
    for(uint i = n >> 1, ih = nh - 1; i >= 1; i >>= 1, --ih) {
      ll zeta = inverse ? zetaInvList[nh - 1 - ih] : zetaList[nh - 1 - ih];
      ll powZeta = 1;
      for(uint j = 0; j < n; j += i) {
        for(uint k = 0; k < i; ++k) {
          tmp[j | k] =
              (a[((j << 1) & mask) | k] + powZeta * a[(((j << 1) | i) & mask) | k]) % mod;
        }
        powZeta = powZeta * zeta % mod;
      }
      swap(a, tmp);
    }
    if(nh & 1) {
      swap(a, tmp);
      for(uint i = 0; i < n; ++i) a[i] = tmp[i];
    }
    if(inverse) {
      ll invN = modinv(n, mod);
      for(uint i = 0; i < n; ++i) a[i] = a[i] * invN % mod;
    }
  }
  vector< ll > conv(const vector< ll > &a, const vector< ll > &b) const {
    uint t = a.size() + xx*(b.size() - 1);
    uint n = 1, nh = 0;
    while(n < t) n <<= 1, ++nh;
    return convStrict(a, b, n, nh);
  }
  vector< ll > convStrict(const vector< ll > &a, const vector< ll > &b, uint n,
                          uint nh) const {
    ll *A = Pool< MAX_H >::A, *B = Pool< MAX_H >::B;
    for(uint i = 0; i < n; ++i) A[i] = B[i] = 0;
    copy(a.begin(), a.end(), A);
    copy(b.begin(), b.end(), B);
    fft(A, n, nh, 0), fft(B, n, nh, 0);

    for(uint i = 0; i < n; ++i){
		B[i]=NTT::modpow(B[i],xx,mod);
		A[i] = A[i] * B[i] % mod;
	} 
    fft(A, n, nh, 1);
    return vector< ll >(A, A + n);
  }
};
// }}}

// Convolution With Garner {{{
template < int MAX_H, int I >
class ConvolutionWithGarnerCore {
public:
  static void conv_for(uint n, uint nh, const vector< ll > &a, const vector< ll > &b,
                       vector< ll > &mods, vector< ll > &coeffs,
                       vector< vector< ll > > &constants) {
    static const Core< MAX_H, NTT_PRIMES[I][0], NTT_PRIMES[I][1] > ntt;
    auto c = ntt.convStrict(a, b, n, nh);
    mods[I] = NTT_PRIMES[I][0];
    ConvolutionWithGarnerCore< MAX_H, I - 1 >::conv_for(
        n, nh, a, b, mods, coeffs, constants);
    // garner
    for(size_t i = 0; i < c.size(); ++i) {
      ll v = (c[i] - constants[I][i]) * modinv(coeffs[I], mods[I]) % mods[I];
      if(v < 0) v += mods[I];
      for(size_t j = I + 1; j < mods.size(); ++j) {
        constants[j][i] = (constants[j][i] + coeffs[j] * v) % mods[j];
      }
    }
    for(size_t j = I + 1; j < mods.size(); ++j) {
      coeffs[j] = (coeffs[j] * mods[I]) % mods[j];
    }
  }
};

template < int MAX_H >
class ConvolutionWithGarnerCore< MAX_H, -1 > {
public:
  static void conv_for(uint, uint, const vector< ll > &, const vector< ll > &,
                       vector< ll > &, vector< ll > &, vector< vector< ll > > &) {}
};

template < int MAX_H >
class ConvolutionWithGarner {
public:
  template < int USE >
  static vector< ll > conv(const vector< ll > &a, const vector< ll > &b, ll mod) {
    static_assert(USE >= 1, "USE must be positive");
    static_assert(USE <= sizeof(NTT_PRIMES) / sizeof(*NTT_PRIMES), "USE is too big");
    uint nt = a.size() + xx*int(b.size()) - 1;
    uint n = 1, nh = 0;
    while(n < nt) n <<= 1, ++nh;
    vector< ll > coeffs(USE + 1, 1);
    vector< vector< ll > > constants(USE + 1, vector< ll >(n));
    vector< ll > mods(USE + 1, mod);
    ConvolutionWithGarnerCore< MAX_H, USE - 1 >::conv_for(
        n, nh, a, b, mods, coeffs, constants);
    return constants.back();
  }
};

// }}}

} // namespace NTT
// }}}

// 1st param is MAX_H
NTT::Core< 19, 998244353, 5 > ntt;
using nttconv = NTT::ConvolutionWithGarner< 19 >;
// nttconv::conv< USE >(a, b, mod)
	vector<ll>answer(4e6,0);

int main() {
	ios::sync_with_stdio(false);

	int N,M;cin>>N>>M;
	map<int,int>mp;
	for(int i=0;i<N;++i){
		int a;cin>>a;
		mp[a]++;
	}
	for(int i=0;i<M;++i){
		int K;cin>>K;
		int one_cnt=0,two_cnt=0;
		for(auto m:mp){
			if(m.first>=K)break;
			if(m.second>=2)two_cnt++;
			else one_cnt++;
		}
		vector<ll>pl_one{1,2};
		vector<ll>pl_two{1,2,1};
		vector<ll>start{1};
		 xx=one_cnt;
	    if(xx)start=ntt.conv(start,pl_one);
		xx=two_cnt;
		if(xx)start=ntt.conv(start,pl_two);
		
		for(int k=0;k<start.size();++k){
			answer[2*(K+k+1)]+=start[k];
		}

	}
	int Q;cin>>Q;
	while(Q--){
		int a;cin>>a;
		cout<<answer[a]%998244353<<endl;
	}
	//ntt.conv(3,4);
	return 0;	
}
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



const int mod =1000003;
struct Mod {
public:
	int num;
	Mod() : Mod(0) { ; }
	Mod(long long int n) : num((n % mod + mod) % mod) {
		static_assert(mod<INT_MAX / 2, "mod is too big, please make num 'long long int' from 'int'");
	}
	Mod(int n) : Mod(static_cast<long long int>(n)) { ; }
	operator int() { return num; }
};

Mod operator+(const Mod a, const Mod b) { return Mod((a.num + b.num) % mod); }
Mod operator+(const long long int a, const Mod b) { return Mod(a) + b; }
Mod operator+(const Mod a, const long long int  b) { return b + a; }
Mod operator++(Mod &a) { return a + Mod(1); }
Mod operator-(const Mod a, const Mod b) { return Mod((mod + a.num - b.num) % mod); }
Mod operator-(const long long int a, const Mod b) { return Mod(a) - b; }
Mod operator--(Mod &a) { return a - Mod(1); }
Mod operator*(const Mod a, const Mod b) { return Mod(((long long)a.num * b.num) % mod); }
Mod operator*(const long long int a, const Mod b) { return Mod(a)*b; }
Mod operator*(const Mod a, const long long int b) { return Mod(b)*a; }
Mod operator*(const Mod a, const int b) { return Mod(b)*a; }
Mod operator+=(Mod &a, const Mod b) { return a = a + b; }
Mod operator+=(long long int &a, const Mod b) { return a = a + b; }
Mod operator-=(Mod &a, const Mod b) { return a = a - b; }
Mod operator-=(long long int &a, const Mod b) { return a = a - b; }
Mod operator*=(Mod &a, const Mod b) { return a = a * b; }
Mod operator*=(long long int &a, const Mod b) { return a = a * b; }
Mod operator*=(Mod& a, const long long int &b) { return a = a * b; }
Mod operator^(const Mod a, const int n) {
	if (n == 0) return Mod(1);
	Mod res = (a * a) ^ (n / 2);
	if (n % 2) res = res * a;
	return res;
}
Mod mod_pow(const Mod a, const int n) {
	if (n == 0) return Mod(1);
	Mod res = mod_pow((a * a), (n / 2));
	if (n % 2) res = res * a;
	return res;
}
Mod inv(const Mod a) { return a ^ (mod - 2); }
Mod operator/(const Mod a, const Mod b) {
	assert(b.num != 0);
	return a * inv(b);
}
Mod operator/(const long long int a, const Mod b) {
	return Mod(a) / b;
}
Mod operator/=(Mod &a, const Mod b) {
	return a = a / b;
}

#define MAX_MOD_N 10240000

Mod fact[MAX_MOD_N], factinv[MAX_MOD_N];
void init(const int amax = MAX_MOD_N) {
	fact[0] = Mod(1); factinv[0] = 1;
	for (int i = 0; i < amax - 1; ++i) {
		fact[i + 1] = fact[i] * Mod(i + 1);
		factinv[i + 1] = factinv[i] / Mod(i + 1);
	}
}
Mod comb(const int a, const int b) {
	return fact[a] * factinv[b] * factinv[a - b];
}

/* verified AOJ1327 One-Dimensional Cellular Automaton
~Matrix~
sPvZ
vector iostream cmath cassert K{
Matrix a(VV), b(VV);
s:a*b
XJ:l*a
a:a+b
:a-b
]u:a.transport()
]q:a.cofactor()
s:a.det()
aisj:a.get(i,j)@
aisjk:set(i,j,k)
a[i][j] (a[i][j]=k)
ax:a.pow(x)
n*n{sE:Matrix(n)
m*n 0s:Matrix(m,n)
m*n Svfps:Matrix(m,n,p)
Row^row(m*1s):Matrix(row)
**(s)**
Op:a.triangulate()
N:a.rank()
ts:a.inverse()
//(tsa.det(){a.pre_inverse() )
KEX@:a.rowReduction()
//A
***
*/

#include <vector>
#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

typedef Mod Elem;
typedef vector<Elem> Row;
typedef vector<Row> VV;

typedef long double ld;
const ld EPS = 1e-11;

const bool isZero(const Elem e) {
	return e.num==0;
}

struct Matrix {
	VV matrix;
	int n, m;

	Matrix(const VV &matrix_);
	explicit Matrix(int n_);
	explicit Matrix(const Row &row);
	Matrix(int m_, int n_);
	Matrix(int m_, int n_, Elem e);

	const Elem get(const int i, const int j) const;
	void set(const int x, const int y, const Elem k);

	const Matrix operator + (const Matrix &rhs) const;
	const Matrix operator * (const Matrix &rhs) const;
	const Matrix operator - (const Matrix &rhs) const;
	Matrix &operator += (const Matrix &rhs);
	Matrix &operator *= (const Matrix &rhs);
	Matrix &operator -= (const Matrix &rhs);

	Row &operator[](const int x);

	const Matrix transport() const;
	const Matrix pow(long long x) const;
	const Matrix cofactor(int x, int y) const;
	const Elem det() const;

	const Matrix triangulate() const;
	const int rank() const;

	//tsA(s)*(ts)
	//A:matrix,return det A * A^-1
	const Matrix pre_inverse() const;
	const Matrix inverse() const;
	const Matrix rowReduction() const;
};

const Matrix operator * (const Elem lambda, const Matrix &rhs) {
	Matrix tmp(rhs);
	for (int i = 0; i < rhs.m; i++)
		for (int j = 0; j < rhs.n; j++)
			tmp.set(i, j, tmp.get(i, j) * lambda);
	return tmp;
}

Matrix::Matrix(const VV &matrix_) : matrix(matrix_) {
	m = matrix_.size();
	if (m == 0) n = 0;
	else n = matrix_[0].size();
}
Matrix::Matrix(int n_) : m(n_), n(n_) {
	matrix = VV(n, Row(n, 0));
	for (int i = 0; i < n; ++i)
		set(i, i, 1);
}
Matrix::Matrix(const Row &row) : m(1), n(row.size()), matrix(VV(1, row)) {
	//sizemvector<Elem>mx1s
	(*this) = transport();
}
Matrix::Matrix(int m_, int n_) : m(m_), n(n_) {
	matrix = VV(m, Row(n, 0));
}
Matrix::Matrix(int m_, int n_, Elem e) : m(m_), n(n_) {
	matrix = VV(m, Row(n, e));
}

const Elem Matrix::get(const int i, const int j) const {
	if (0 <= i && i < m && 0 <= j && j < n)
		return matrix[i][j];

	cerr << "get(" << i << "," << j << ")is not exist." << endl;
	throw;
}
void Matrix::set(const int i, const int j, const Elem k) {
	if (0 <= i && i < m && 0 <= j && j < n) {
		*(matrix[i].begin() + j) = k;
		return;
	}
	cerr << "set(" << i << "," << j << ")is not exist." << endl;
	throw;
}

const Matrix Matrix::operator + (const Matrix &rhs) const {
	assert(m == rhs.m && n == rhs.n);

	Matrix tmp(m, n, 0);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			tmp.set(i, j, get(i, j) + rhs.get(i, j));
		}
	}
	return tmp;
}

const Matrix Matrix::operator * (const Matrix &rhs) const {
	assert(n == rhs.m);

	Matrix tmp(m, rhs.n, 0);
	Elem sum;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < rhs.n; j++) {
			sum = 0;
			for (int k = 0; k < n; k++) {
				sum += get(i, k) * rhs.get(k, j);
			}
			tmp.set(i, j, sum);
		}
	return tmp;
}

const Matrix Matrix::operator - (const Matrix &rhs) const {
	return *this + ((Elem)-1 * rhs);
}

Matrix &Matrix::operator += (const Matrix &rhs) {
	return *this = *this + rhs;
}

Matrix &Matrix::operator *= (const Matrix &rhs) {
	return *this = *this * rhs;;
}

Matrix &Matrix::operator -= (const Matrix &rhs) {
	return *this = *this - rhs;
}

Row &Matrix::operator[](const int x) {
	return matrix[x];
}

const Matrix Matrix::transport() const {
	VV tmp;
	for (int i = 0; i < n; i++) {
		Row row;
		for (int j = 0; j < m; j++)
			row.push_back(get(j, i));
		tmp.push_back(row);
	}
	return tmp;
}

const Matrix Matrix::pow(long long x) const {
	Matrix tmp(*this), e(m);
	for (long long i = 1; i <= x; i <<= 1) {
		if ((x & i) > 0)
			e = e * tmp;
		tmp = tmp * tmp;
	}
	return e;
}

const Matrix Matrix::cofactor(int x, int y) const {
	VV tmp;
	for (int i = 0; i < m; i++) {
		if (x == i) continue;
		Row row;
		for (int j = 0; j < n; j++) {
			if (y == j) continue;
			row.push_back(get(i, j));
		}
		tmp.push_back(row);
	}
	return Matrix(tmp);
}

const Elem Matrix::det() const {
	assert(n == m);

	if (m == 1)
		return get(0, 0);
	Elem sum = 0;
	for (int i = 0; i < m; i++) {
		sum += ((i % 2 == 0 ? 1 : -1) * get(i, 0)) * Matrix(cofactor(i, 0)).det();
	}
	return sum;
}

const Matrix Matrix::triangulate() const {
	Matrix tmp(*this);
	Elem e;
	int p = 0;
	for (int i = 0; i < m && p < n; i++, p++) {
		if (isZero(tmp.get(i, p))) {
			tmp.set(i, p, 0);
			bool flag = true;
			for (int j = i + 1; j < m; j++)
				if (!isZero(tmp.get(j, p))) {
					for (int k = 0; k < n; k++)
						tmp.set(i, k, tmp.get(i, k) + tmp.get(j, k));
					//tmp[i].swap(tmp[j]);
					flag = false;
					break;
				}
			if (flag) {
				i--;
				continue;
			}
		}
		for (int j = i + 1; j < m; j++) {
			e = tmp.get(j, p) / tmp.get(i, p);
			for (int k = 0; k < n; k++)
				tmp.set(j, k, tmp.get(j, k) - tmp.get(i, k) * e);
		}
	}
	return tmp;
}

const int Matrix::rank() const {
	Matrix tmp(triangulate());
	for (int i = min(tmp.m - 1, tmp.n - 1); i >= 0; i--) {
		for (int j = tmp.n - 1; j >= i; j--)
			if (isZero(tmp.get(i, j)))
				continue;
			else
				return i + 1;
	}
	return 0;
}

const Matrix Matrix::pre_inverse() const {
	assert(m == n);

	Matrix tmp(m, n, 0);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			tmp.set(i, j, ((i + j) % 2 == 0 ? 1 : -1)*cofactor(i, j).det());
	return tmp.transport();
}

/*O(n!)
const Matrix Matrix::inverse() const {
Matrix tmp(pre_inverse());
Elem e = det();
assert(!isZero(e));
tmp = 1 / e * tmp;
return tmp.transport();
}*/

const Matrix Matrix::inverse() const {
	assert(m == n);

	Matrix tmp(m, n * 2), tmp2(m, n);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			tmp.set(i, j, get(i, j));
	for (int i = 0; i < m; i++)
		tmp.set(i, i + n, 1);

	tmp = tmp.rowReduction();

	//ts`FbN
	for (int i = 0; i < m; i++)
		assert(isZero(tmp.get(i, i) - 1));

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			tmp2.set(i, j, tmp.get(i, j + n));

	return tmp2;
}

/*
a b c j
d e f k
g h i l

ax+by+cz=j;
dx+ey+fz=k;
gx+hy+iz=l;

|
V

1 0 0 x
0 1 0 y
0 0 1 z
E[
*/
const Matrix Matrix::rowReduction() const {
	Matrix tmp(*this);
	Elem e;
	int p = 0;
	for (int i = 0; i < m && p < n; i++, p++) {
		if (isZero(tmp.get(i, p))) {
			tmp.set(i, p, 0);
			bool flag = true;
			for (int j = i + 1; j < m; j++)
				if (!isZero(tmp.get(j, p))) {
					for (int k = 0; k < n; k++)
						tmp.set(i, k, tmp.get(i, k) + tmp.get(j, k));
					//tmp[i].swap(tmp[j]);
					flag = false;
					break;
				}
			if (flag) {
				i--;
				continue;
			}
		}
		e = 1 / tmp.get(i, p);
		tmp.set(i, p, 1);
		for (int k = i + 1; k < n; k++)
			tmp.set(i, k, tmp.get(i, k)*e);
		for (int j = 0; j < m; j++) {
			if (i == j) continue;
			e = tmp.get(j, p);
			for (int k = 0; k < n; k++)
				tmp.set(j, k, tmp.get(j, k) - tmp.get(i, k) * e);
		}
	}
	return tmp;
}
const int X=10;
int main() {
	ios::sync_with_stdio(false);
	int N;cin>>N;
	vector<pair<int,int>>vs;
	for(int i=0;i<N;++i){
		int a;cin>>a;
		vs.emplace_back(a,i);
	}
	sort(vs.begin(),vs.end());
	vector<int>dp(N+1,int(1e9+5e8));
	dp[0]=0;

	for(int i=0;i<N;++i){
		for(int num=3;num<=5;++num){
			if(i+num<=N){
				dp[i+num]=min(dp[i+num],dp[i]+vs[i+num-1].first-vs[i].first);
			}
		}
	}
	int now=N;
	vector<int>anss(N);
	int id=0;
	while(now){
		id++;
		for(int num=3;num<=5;++num){
			if(dp[now-num]+vs[now-1].first-vs[now-num].first==dp[now]){
				for(int x=now-num;x<now;++x){
					anss[vs[x].second]=id;
				}
				now-=num;
				break;
			}
		}

	}
	cout<<dp[N]<<' '<<id<<endl;
	for(int i=0;i<N;++i){
		cout<<anss[i]<<' ';
			}
			cout<<endl;
	return 0;	
}
#include "bits/stdc++.h"
#include<unordered_map>
#pragma warning(disable:4996)
using namespace std;

const int My_Inf=2147483647;
const long long int My_LInf=9223372036854775807;
/*
UBigNum::mulOneDigit Z

UShort mulnum : 
*/
using std::vector;
typedef unsigned short int UShort;
typedef unsigned long int UInt;

#define SHIFT 16
#define NUM (0x1<<SHIFT)

#ifndef SIZE
#define SIZE 1000
#endif

void mul_add(unsigned long *ret, unsigned long *a, unsigned long *b)//@@ret=a+b  reta 
{
	int  i, lr, ls;
	unsigned long  *pr;

	if (a[0] >= b[0]) { lr = a[0]; ls = b[0]; pr = a; }
	else { lr = b[0]; ls = a[0]; pr = b; }

	unsigned long  x = 0;
	for (i = 1; i <= ls; i++) {
		x += a[i] + b[i];
		ret[i] = x & 0xFFFF;                 //ret[i+j-1] = x % NUM
		x = x >> SHIFT;                               //x = x / NUM
	}
	for (; i <= lr; i++) {
		x += pr[i];
		ret[i] = x & 0xFFFF;
		x = x >> SHIFT;
	}
	ret[i] = x;
	ret[0] = lr + x;
}


int mul_cmp(unsigned long *a, unsigned long *b)//a,br 
{
	if (a[0] > b[0]) return 1;
	if (a[0] < b[0]) return -1;

	int  i = a[0];

	while (i > 0) {
		if (a[i] > b[i]) return 1;
		if (a[i] < b[i]) return -1;
		i--;
	}
	return 0;
}


int mul_sub(unsigned long *ret, unsigned long *a, unsigned long *b)//@@ret=a-b  reta
{
	int  i;
	int  la = a[0], lb = b[0];
	unsigned long  x = 0, y;

	int hikaku = mul_cmp(a, b);
	if (hikaku == 0) {
		ret[0] = 0;
		return 0;
	}
	else if (hikaku<0) {
		return 1;
	}

	for (i = 1; i <= lb; i++) {
		x += b[i];
		y = NUM + a[i] - x;
		ret[i] = y & 0xFFFF;                 //ret[i+j-1] = x % NUM
		x = 1 - (y >> SHIFT);                       //0,1] 
	}
	for (; i <= la; i++) {
		y = NUM + a[i] - x;
		ret[i] = y & 0xFFFF;
		x = 1 - (y >> SHIFT);
	}
	while (--i > 0) {
		if (ret[i] != 0) break;
	}
	ret[0] = i;
	return 0;
}


void mul_mul(unsigned long *ret, unsigned long *a, unsigned long *b)//@@ret=a*b  ab 
{
	int  i, j;
	int  la = a[0], lb = b[0];
	unsigned long x;
	unsigned long *reti = ret;

	if (la == 0 || lb == 0) {
		ret[0] = 0;
		return;
	}
	for (i = la + lb; i > 0; i--) ret[i] = 0;

	if (a != b) {
		for (i = 1; i <= lb; i++) {
			x = 0;
			for (j = 1; j <= la; j++) {
				x += reti[j] + a[j] * b[i];
				reti[j] = x & 0xFFFF;                 //ret[i+j-1] = x % NUM
				x = x >> SHIFT;                               //x = x / NUM
			}
			reti[j] += x;
			reti++;
		}

	}
	else {

		for (i = 1; i <= la; i++) {
			x = 0;
			for (j = i + 1; j <= la; j++) {
				x += reti[j] + a[j] * a[i];
				reti[j] = x & 0xFFFF;
				x = x >> SHIFT;
			}
			reti[j] = x;
			reti++;
		}
		for (i = la * 2; i >= 2; i--) {
			ret[i] = ((ret[i] << 1) & 0xFFFF) | (ret[i - 1] >> (SHIFT - 1));
		}
		ret[i] = (ret[i] << 1) & 0xFFFF;

		for (i = 1; i <= la; i++) ret[i + i - 1] += a[i] * a[i];

		x = 0;
		for (i = 1; i < la * 2; i++) {
			x += ret[i];
			ret[i] = x & 0xFFFF;
			x = x >> SHIFT;
		}
		ret[i] += x;
	}

	ret[0] = (x != 0) ? la + lb : la + lb - 1;
}


void mul_smul(unsigned long *ret, unsigned long *a, unsigned long c)//{*16bit  ret=a*c 
{
	int i;
	int  la = a[0];
	unsigned long x;

	x = 0;
	for (i = 1; i <= la; i++) {
		x += a[i] * c;
		ret[i] = x & 0xFFFF;                       //ret[i] = x % NUM
		x = x >> SHIFT;                                 //x = x / NUM
	}
	ret[i] = x;
	ret[0] = (x != 0) ? la + 1 : la;
}


void mul_cpy(unsigned long *ret, unsigned long *a)//abRs[
{
	int i;
	for (i = a[0]; i >= 0; i--) ret[i] = a[i];
}

//@Zp 

int mul_divcmp(unsigned long *a, unsigned long *b, int n)
{
	if (a[0] + n > b[0]) return 1;
	if (a[0] + n < b[0]) return -1;

	int  i = a[0];

	while (i > 0) {
		if (a[i] > b[i + n]) return 1;
		if (a[i] < b[i + n]) return -1;
		i--;
	}
	return 0;
}


void mul_divshift(unsigned long *ret, unsigned long *a, int n)
{
	int i;
	int  lan = a[0] + n;
	for (i = lan; i >= n + 1; i--) ret[i] = a[i - n];
	ret[0] = lan;
}


int mul_shift_ab(unsigned long *a, unsigned long *b)
{
	int i, iti;
	unsigned long flag = 0x1 << (SHIFT - 1);
	for (iti = 0; iti <= SHIFT - 1; iti++) {
		if ((flag & b[b[0]]) != 0) break;
		flag = flag >> 1;
	}
	if (iti != 0) {
		for (i = b[0]; i >1; i--) {
			b[i] = ((b[i] << iti) & 0xFFFF) | (b[i - 1] >> (SHIFT - iti));
		}
		b[1] = (b[1] << iti) & 0xFFFF;

		a[a[0] + 1] = a[a[0]] >> (SHIFT - iti);
		for (i = a[0]; i >1; i--) {
			a[i] = ((a[i] << iti)) & 0xFFFF | (a[i - 1] >> (SHIFT - iti));
		}
		a[1] = (a[1] << iti) & 0xFFFF;
		if (a[a[0] + 1] != 0) a[0]++;
	}
	return iti;
}


void mul_shift_iti(unsigned long *r, unsigned long *aa, int iti)
{
	if (aa[0] == 0) { r[0] = 0; return; }
	int i;
	for (i = 1; i <= aa[0] - 1; i++) {
		r[i] = ((aa[i] & 0xFFFF) >> iti) | ((aa[i + 1] << (SHIFT - iti)) & 0xFFFF);
	}
	r[i] = (aa[i] >> iti);
	r[0] = aa[0];
	if (r[0]>0 && r[r[0]] == 0) r[0]--;
}


void mul_divsub(unsigned long *a, unsigned long *b, int n)
{
	int  i;
	unsigned long  x = 0, y;
	int  la = a[0], lb = b[0] + n;

	for (i = 1 + n; i <= lb; i++) {
		x += b[i - n];
		y = NUM + a[i] - x;
		a[i] = y & 0xFFFF;
		x = 1 - (y >> SHIFT);                 //0,1] 
	}
	for (; i <= la; i++) {
		y = NUM + a[i] - x;
		a[i] = y & 0xFFFF;
		x = 1 - (y >> SHIFT);
	}
	i = i;
	while (--i > 0) {
		if (a[i] != 0) break;
	}
	a[0] = i;
}


void mul_div_0(unsigned long *q, unsigned long *r, unsigned long *bb)
{
	unsigned long bbn = bb[bb[0]];

	int n = r[0] - bb[0];
	int i = n;
	while (i >= 0) {
		unsigned long q0, x, y;
		int iti = bb[0] + i + 1;

		if (r[0] == iti) {
			x = r[iti];
			y = r[iti - 1];
		}
		else if (r[0] == iti - 1) {
			x = 0;
			y = r[iti - 1];
		}
		else {
			x = 0;
			y = 0;
		}
		q0 = ((x << SHIFT) + y) / bbn;
		if (q0>NUM - 1) q0 = NUM - 1;
		if (q0 == 0) {
			q[i + 1] = 0;
		}
		else {
			unsigned long cc[SIZE * 2 + 1];
			mul_smul(cc, bb, q0);
			while (mul_divcmp(cc, r, i)>0) {
				mul_divsub(cc, bb, 0);
				q0--;
			}
			mul_divsub(r, cc, i);
			q[i + 1] = q0;
		}
		i--;
	}

	for (i = n + 1; i >= 0; i--) {
		if (q[i] != 0) break;
	}
	q[0] = i;
}


int mul_div(unsigned long *q, unsigned long *r, unsigned long *a, unsigned long *b)//@ abq]r 
{
	unsigned long aa[SIZE * 2 + 1], bb[SIZE * 2 + 1];
	if (b[0] == 0) return 1;
	int hikaku = mul_cmp(a, b);
	if (hikaku == 0) {
		q[0] = 1;
		q[1] = 1;
		r[0] = 0;
		return 0;
	}
	else if (hikaku<0) {
		q[0] = 0;
		mul_cpy(r, a);
		return 0;
	}
	mul_cpy(aa, a);
	mul_cpy(bb, b);
	int iti = mul_shift_ab(aa, bb);
	mul_div_0(q, aa, bb);
	if (iti != 0) { mul_shift_iti(r, aa, iti); }
	else { mul_cpy(r, aa); }
	return 0;
}


void mul_div_1(unsigned long *r, unsigned long *bb)
{
	unsigned long bbn = bb[bb[0]];

	int i = r[0] - bb[0];
	while (i >= 0) {
		unsigned long q0, x, y;
		int iti = bb[0] + i + 1;

		if (r[0] == iti) {
			x = r[iti];
			y = r[iti - 1];
		}
		else if (r[0] == iti - 1) {
			x = 0;
			y = r[iti - 1];
		}
		else {
			x = 0;
			y = 0;
		}
		q0 = ((x << SHIFT) + y) / bbn;
		if (q0>NUM - 1) q0 = NUM - 1;
		if (q0 != 0) {
			unsigned long cc[SIZE * 2 + 1];
			mul_smul(cc, bb, q0);
			while (mul_divcmp(cc, r, i)>0) {
				mul_divsub(cc, bb, 0);
				q0--;
			}
			mul_divsub(r, cc, i);
		}
		i--;
	}
}


int mul_rem(unsigned long *r, unsigned long *a, unsigned long *b)//] ab ]r 
{
	unsigned long aa[SIZE * 2 + 1], bb[SIZE * 2 + 1];
	if (b[0] == 0) return 1;
	int hikaku = mul_cmp(a, b);
	if (hikaku == 0) {
		r[0] = 0;
		return 0;
	}
	else if (hikaku<0) {
		mul_cpy(r, a);
		return 0;
	}
	mul_cpy(aa, a);
	mul_cpy(bb, b);
	int iti = mul_shift_ab(aa, bb);
	mul_div_1(aa, bb);
	if (iti != 0) { mul_shift_iti(r, aa, iti); }
	else { mul_cpy(r, aa); }
	return 0;
}

#undef NUM
#undef SHIFT

int main() {
	vector<pair<int, int>>ps;
	for (int i = 0; i < 3; ++i) {
		int x, y; cin >> x >> y;
		ps.push_back(make_pair(x, y));
	}
	sort(ps.begin(), ps.end());
	if (ps[0].first == ps[1].first) {
		if (ps[1].first == ps[2].first) {
			cout << 1 << endl;
			return 0;
		}
		else {
			if(ps[0].second<ps[2].second&&ps[2].second<ps[1].second){
				cout << 3 << endl;
				return 0;
			}
			else {
				cout<< 2 << endl;
				return 0;
			}
		}
	}
	else if (ps[1].first == ps[2].first) {
		if (ps[1].second<ps[0].second&&ps[0].second<ps[2].second) {
			cout << 3 << endl;
			return 0;
		}
		else {
			cout << 2 << endl;
			return 0;
		}
	}
	else {
		if (ps[0].second == ps[1].second &&ps[1].second ==ps[2].second) {
			cout << 1 << endl;
			return 0;
		}
		else {
			if (ps[0].second == ps[2].second) {
				cout << 3 << endl;
				return 0;
			}
			else if (ps[0].second == ps[1].second) {
				cout << 2 << endl;
				return 0;
			}
			else if (ps[1].second == ps[2].second) {
				cout << 2 << endl;
				return 0;
			}
			else {
				cout << 3 << endl;
				return 0;
			}
		}
	}



	return 0;

}
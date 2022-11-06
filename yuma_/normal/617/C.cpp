#include "bits/stdc++.h"
#include<unordered_map>
#pragma warning(disable:4996)
using namespace std;

const int My_Inf=2147483647;
const long long int My_LInf=9223372036854775807;
///*
//UBigNum::mulOneDigit Z
//
//UShort mulnum : 
//*/
//using std::vector;
//typedef unsigned short int UShort;
//typedef unsigned long int UInt;
//
//class UBigNum
//{
//public:
//	vector<UShort> number; // 
//	bool NaN;              // Not A NumbertO
//
//	static const UInt maxBit = sizeof(UShort) * CHAR_BIT; // rbg
//	static const UInt maxNum = (1 << maxBit) - 1;       // l
//
//	
//	UInt size() const { return(number.size()); }     // (TCY)
//	void resize(UInt sz) { number.resize(sz, 0); } // (TCY)X
//	void push_upper(UShort i = 0) { number.push_back(i); }   // 
//
//
//
//	bool isNaN() const { return(NaN); } // NaN
//	void clear() { number.clear(); push_upper(); } // 0
//
//												   /* Zqd` */
//	bool operator!() const { return(NaN); } // NaN
//
//	/*
//	RXgN^()
//
//	UInt i : l
//	*/
//	UBigNum::UBigNum(UInt i)
//		: NaN(false)
//	{
//		if (i > maxNum) {
//			push_upper(i & maxNum);
//			push_upper(i >> maxBit);
//		}
//		else {
//			push_upper(i);
//		}
//	}
//	void UBigNum::mulOneDigit(UShort mulnum)
//	{
//		if (mulnum == 0) {
//			clear();
//			return;
//		}
//
//		UInt carry = 0; // J
//		for (UInt i = 0; i < size(); i++) {
//			carry += number[i] * mulnum;
//			number[i] = carry & maxNum;
//			carry >>= maxBit;
//		}
//		// JcZ
//		if (carry > 0) push_upper(carry);
//	}
//};

int main() {
	/*int N; cin >> N;
	vector<bool>nuts;
	for (int i = 0; i < N; ++i) {
		int a; cin >> a;
		nuts.push_back(a);
	}
	int num = 0;
	bool a = false;
	long long int ans = 1;
	UBigNum aa = 1;
	for (int i = 0; i < N; ++i) {
		if (a == false) {
			if (nuts[i]) {
				a = true;
			}
		}
		else {
			if (nuts[i]) {
				aa.mulOneDigit( (num + 1));
				num = 0;
			}
			else {
				num++;
			}
		}
	}
	for (int i = 0; i < aa.number.size(); ++i) {
		cout << aa.number[aa.size() - i - 1] << endl;
	}*/
//	cout << aa << endl;
	int n, x1, y1, x2, y2; cin >> n >> x1 >> y1 >> x2 >> y2;
	vector<vector<long long int >>diss(n,vector<long long int>(2));
	for (int i = 0; i < n; ++i) {
		long long int x, y; cin >> x >> y;
		diss[i][0] = (x - x1)*(x - x1) + (y - y1)*(y - y1);
		diss[i][1] = (x - x2)*(x - x2) + (y - y2)*(y - y2);
	}
	vector<pair<long long int, long long int >>dis1,dis2;
	for (int i = 0; i < n; ++i) {
		dis1.push_back(make_pair(diss[i][0], diss[i][1]));
		//dis2.push_back(make_pair(diss[i][1], i));
	}
	sort(dis1.begin(), dis1.end());
	long long int finans = 100000000000000000;
	{
		long long int ans = 0;
		long long int amax = 0;
		for (int j = 0; j < n; ++j) {
			amax = max(amax, dis1[j].second);
		}
		ans += amax;
		finans = min(ans, finans);
	}
	for (int i = 0; i < n; ++i) {
		//i0
		long long int ans = dis1[i].first;
		long long int amax = 0;
		for (int j = i+1; j < n; ++j) {
			if (dis1[j].first>dis1[i].first)amax = max(amax, dis1[j].second);
		}
		ans += amax;
		finans = min(ans, finans);
	}
	cout << finans << endl;
	return 0;
}
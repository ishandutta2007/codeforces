#include <bits/stdc++.h>

typedef unsigned long long u64;

const u64 table[64] = {
	205420232704ull, 4300726075392ull, 9943141842944ull, 102772080771072ull, 
	234260485308416ull, 723091532955648ull, 1929901949378560ull, 7962145521006592ull, 
	16163718647774208ull, 36001995886165504ull, 72057594037927680ull, 
	144115188075855744ull, 144115188075855744ull, 288230376151711680ull, 
	576460752303423456ull, 576460752303423456ull, 1152921504606846960ull, 
	2305843009213693944ull, 2305843009213693920ull, 576412923518779264ull, 
	71777768313191948ull, 3466203809432795196ull, 9079473177587753214ull, 
	9206058851405956094ull, 9220848794270097406ull, 9197581204444447742ull, 
	18414869574287814655ull, 18420741636752033791ull, 18426746848929380351ull, 
	18415823286090401791ull, 18437647845276217343ull, 18413224286464100351ull, 
	18420404737790451711ull, 18444146654698651647ull, 18438754119921373183ull, 
	18444712607746252799ull, 18442905914206388223ull, 18446482373293113343ull, 
	9222888249038077950ull, 9223372004642521086ull, 9223372024775180286ull, 
	9223372034908618750ull, 4611686010441433084ull, 4611686017353644540ull, 
	2296835806200851448ull, 2271494263009059832ull, 2292441381606829048ull, 
	1150432316586299376ull, 575754606495084512ull, 575406797197246432ull, 
	287974233452855232ull, 144099394269413248ull, 144050217612541824ull, 
	72048513284964096ull, 36027165100998144ull, 18010923323096064ull, 
	9005072994269184ull, 2251791223742464ull, 1125899906826240ull, 
	281474976645120ull, 140737488224256ull, 17592184995840ull, 4398042316800ull, 
	274810798080ull
};

int r, c;

int main() {
	scanf("%d%d", &r, &c);
	puts(table[r] >> c & 1 ? "IN" : "OUT");
	return 0;
}
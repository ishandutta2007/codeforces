#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ

using namespace std;

int FASTBUFFER;

string x[6] = {"+------------------------+", 
"|#.#.#.#.#.#.#.#.#.#.#.|D|)", 
"|#.#.#.#.#.#.#.#.#.#.#.|.|", 
"|#.......................|", 
"|#.#.#.#.#.#.#.#.#.#.#.|.|)", 
"+------------------------+"};

int n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int flag = 0;
		for (int j = 0; j < 23; j++) {
			for (int k = 0; k < 6; k++) {
				if (x[k][j] == '#') {
					x[k][j] = 'O';
					flag = 1;
					break;
				}
			}
			
			if (flag) {
				break;
			}
		}
	}
	
	for (int i = 0; i < 6; i++) {
		printf("%s\n", x[i].c_str());
	}
	
	return 0;
}
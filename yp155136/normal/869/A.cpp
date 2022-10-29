#include <iostream>
#include <cstdio>
using namespace std;

const int MAX_N = 2006;
const int MAX_P = 5000000;

int a[MAX_N],b[MAX_N];

bool used[MAX_P];

int main () {
	int n;
	scanf("%d",&n);
	for (int i=1;n>=i;i++) scanf("%d",&a[i]);
	for (int i=1;n>=i;i++) scanf("%d",&b[i]);
	for (int i=1;n>=i;i++) {
		used[a[i]] = used[b[i]] = 1;
	}
	int cnt=0;
	for (int i=1;n>=i;i++) {
		for (int j=1;n>=j;j++) {
			if (used[(a[i]^b[j])]) cnt++;
		}
	}
	if (cnt&1) puts("Koyomi");
	else puts("Karen");
}
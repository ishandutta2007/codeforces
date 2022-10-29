#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int MAX_N = 100003;

int a[MAX_N];
int sg_val[MAX_N];

//int mex1(int a) {
//	if (a==0) return 1;
//	else return 0;
//}
//int mex2(int a,int b) {
//	int _0=0, _1=0;
//	if (a==0||b==0) _0++;
//	if (a==1||b==1) _1++;
//	if (_0==0) return 0;
//	if (_1==0) return 1;
//	return 2;
//}

int get_sg(int x,int k) {
	if (k%2==0) {
		if (x>=3) {
			if (x%2==0) return 1;
			else return 0;
		}
		else if (x==0) return 0;
		else if (x==1) return 1;
		else if (x==2) return 2;
	}
	else if (k%2==1) {
		if (x>4) {
			if (x%2==1) return 0;
			else {
				if (get_sg(x/2,k) == 1) return 2;
				else return 1;
			}
		}
		else if (x==0) return 0;
		else if (x==1) return 1;
		else if (x==2) return 0;
		else if (x==3) return 1;
		else if (x==4) return 2;
	}
}

int main () {
	int n,k;
	while (scanf("%d %d",&n,&k) != EOF) {
		int maxa=-1;
		for (int x=0;n>x;x++) {
			scanf("%d",&a[x]);
			if (maxa<a[x]) maxa=a[x];
		}
		memset(sg_val,0,sizeof(sg_val));
		//original method
//		for (int x=0;maxa>=x;x++) {
//			if (x==0) sg_val[x]=0;
//			else if (x%2==1) {
//				sg_val[x]=mex1(sg_val[x-1]);
//			}
//			else {
//				//cout << "#"<<k%2 << endl;
//				sg_val[x]=mex2(sg_val[x-1], (k%2) * sg_val[x/2]);
//			}
//		}
//		int SG = sg_val[a[0]];
//		for (int i=1;n>i;i++) {
//			SG = SG ^ sg_val[a[i]];
//		}
		
//		for (int x=0;maxa>=x;x++) cout<< sg_val[x] << ' ';
//		cout << " ==> " << SG <<endl;

		//new method
		
		int SG = get_sg(a[0],k);
		//cout << SG << endl;
		for (int x=1;n>x;x++) {
			int t=get_sg(a[x],k);
			//cout << t << endl;
			SG ^= get_sg(a[x],k);
		}
		
		printf("%s\n",(SG==0?"Nicky":"Kevin"));
		
		
	}
}
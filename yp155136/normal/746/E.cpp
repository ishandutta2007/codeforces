#include <iostream>
#include <stdio.h>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 2e5 + 6;

int a[MAX_N];

int main () {
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
		map<int,int> cnt;
		int _1=0,_2=0;
		for (int i=1;n>=i;i++) {
			scanf("%d",&a[i]);
			if (a[i]&1) _1++;
			else _2++;
			cnt[a[i]]++;
		}
		int need=(max(_1,_2)-min(_1,_2))/2;  //big to how many small
		int __1	=1,__2=2;
		int ans=0;
		if (need != 0) {
			//get need to zero by using repeating numbers
			for (int i=n;i>=1;i--) {
				if (need) {
					if (_1>_2) {
						if (cnt[a[i]]>1 && (a[i]&1)) {
							while (m>=__2&&cnt[__2]!=0) __2+=2;
							cnt[a[i]]--;
							if (cnt[__2]==0&&m>=__2) a[i]=__2;
							else {
								puts("-1");
								return 0;
							}
							cnt[__2]=1;
							__2 += 2;
							need--;
							ans++;
						}
					}
					else if (_2>_1) {
						if (cnt[a[i]]>1 && (!(a[i]&1))) {
							while (m>=__1&&cnt[__1]!=0) __1+=2;
							cnt[a[i]]--;
							if (cnt[__1]==0&&m>=__1) a[i]=__1;
							else {
								puts("-1");
								return 0;
							}
							cnt[__1]=1;
							__1 += 2;
							need--;
							ans++;
						}
					}
				}
			}
		}
		//replacing the small first
		for (int i=1;n>=i;i++) {
			if (_1<_2 && a[i]%2==1) {
				if (cnt[a[i]]>1) {
					while (m>=__1&&cnt[__1]!=0) __1+=2;
					cnt[a[i]]--;
					if (cnt[__1]==0&&m>=__1) a[i]=__1;
					else {
						puts("-1");
						return 0;
					}
					cnt[__1]=1;
					__1 += 2;
					ans++;
				}
			}
			else if (_2<_1 && a[i]%2==0) {
				if (cnt[a[i]]>1) {
					while (m>=__2&&cnt[__2]!=0) __2+=2;
					cnt[a[i]]--;
					if (cnt[__2]==0&&m>=__2) a[i]=__2;
					else {
						puts("-1");
						return 0;
					}
					cnt[__2]=1;
					__2 += 2;
					ans++;
				}
			}
		}
		//replacting big repeat
		if (need==0) {
			for (int i=1;n>=i;i++) {
				if (a[i]%2==1) {
					if (cnt[a[i]]>1) {
						while (m>=__1&&cnt[__1]!=0) __1+=2;
						cnt[a[i]]--;
						if (cnt[__1]==0&&m>=__1) a[i]=__1;
						else {
							puts("-1");
							return 0;
						}
						cnt[__1]=1;
						__1 += 2;
						ans++;
					}
				}
				else if (a[i]%2==0) {
					if (cnt[a[i]]>1) {
						while (m>=__2&&cnt[__2]!=0) __2+=2;
						cnt[a[i]]--;
						if (cnt[__2]==0&&m>=__2) a[i]=__2;
						else {
							puts("-1");
							return 0;
						}
						cnt[__2]=1;
						__2 += 2;
						ans++;
					}
				}
			}
		}
		else {
			for (int i=1;n>=i;i++) {
				if (need) {
					if (_1>_2) {
						if ((a[i]&1)) {
							while (m>=__2&&cnt[__2]!=0) __2+=2;
							cnt[a[i]]--;
							if (cnt[__2]==0&&m>=__2) a[i]=__2;
							else {
								puts("-1");
								return 0;
							}
							cnt[__2]=1;
							__2 += 2;
							need--;
							ans++;
						}
					}
					else if (_2>_1) {
						if (!(a[i]&1)) {
							while (m>=__1&&cnt[__1]!=0) __1+=2;
							cnt[a[i]]--;
							if (cnt[__1]==0&&m>=__1) a[i]=__1;
							else {
								puts("-1");
								return 0;
							}
							cnt[__1]=1;
							__1 += 2;
							need--;
							ans++;
						}
					}
				}
			}
		}
		printf("%d\n",ans);
		for (int i=1;n>=i;i++) {
			if (i!=1) printf(" ");
			printf("%d",a[i]);
		}
		puts("");
	}
}
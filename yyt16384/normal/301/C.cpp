#include <cstdio>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

int main()
{
#ifndef ONLINE_JUDGE
	freopen("8810.in", "r", stdin);
	freopen("8810.out", "w", stdout);
#endif

	for (int i = 0; i < 9; ++i)
		printf("%d\?\?<>%d\n", i, i + 1);
	printf("9\?\?>>\?\?0\n");
	printf("\?\?<>1\n");
	for (int i = 0; i < 10; ++i)
		printf("\?%d>>%d\?\n", i, i);
	printf("\?>>\?\?\n");
	printf(">>\?\n");

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}
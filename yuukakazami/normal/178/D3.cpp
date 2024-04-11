/*
 * d.cpp
 *
 *  Created on: 2012-4-28
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

const int MAX_N = 4;
int n;
int a[MAX_N * MAX_N];

bool used[MAX_N * MAX_N];

bool check(int x[4][4], int n) {
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += x[0][i];
	}

	for (int r = 0; r < n; ++r) {
		if (accumulate(x[r], x[r] + n, 0) != sum) {
			return false;
		}
	}
	for (int c = 0; c < n; ++c) {
		int t = 0;
		for (int r = 0; r < n; ++r) {
			t += x[r][c];
		}
		if (t != sum)
			return false;
	}
	int A = 0, B = 0;
	for (int r = 0; r < n; ++r) {
		A += x[r][r];
		B += x[r][n - 1 - r];
	}
	if (A != sum || B != sum)
		return false;
	return true;
}

void work3() {

	sort(a, a + n * n);
	do {
		int x[4][4];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				x[i][j] = a[i * n + j];
			}
		}
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			sum += x[0][i];
		}

		bool ok = true;
		for (int r = 0; r < n; ++r) {
			if (accumulate(x[r], x[r] + n, 0) != sum) {
				ok = false;
				break;
			}
		}
		for (int c = 0; c < n; ++c) {
			int t = 0;
			for (int r = 0; r < n; ++r) {
				t += x[r][c];
			}
			if (t != sum)
				ok = false;
		}
		int A = 0, B = 0;
		for (int r = 0; r < n; ++r) {
			A += x[r][r];
			B += x[r][n - 1 - r];
		}
		if (A != sum || B != sum)
			ok = false;
		if (ok) {
			cout << sum << endl;
			for (int r = 0; r < n; ++r) {
				for (int c = 0; c < n; ++c) {
					cout << x[r][c] << " ";
				}
				cout << endl;
			}
			cout << endl;
			return;
		}
	} while (next_permutation(a, a + n * n));
}

int main() {
	cin >> n;
	for (int i = 0; i < n * n; ++i) {
		cin >> a[i];
	}
	if (n <= 3) {
		work3();
		return 0;
	}

	//then n=4

	int sum = 0;
	for (int i = 0; i < n * n; ++i) {
		sum += a[i];
	}
	sum /= n;
//	cout << sum << endl;

	bool used[MAX_N * MAX_N] = { };
	int tot = n * n;
#define SEARCH(a) for(int a=0;a<tot;a++)if(!used[a])

	SEARCH(a11) {
		used[a11] = true;
		SEARCH(a22) {
			used[a22] = true;
			SEARCH(a33) {
				used[a33] = true;

				int need44 = sum - (a[a11] + a[a22] + a[a33]);

				//pick a44
				SEARCH(a44)
					if (a[a44] == need44) {
						used[a44] = true;

						SEARCH(a14) {
							used[a14] = true;
							SEARCH(a23) {
								used[a23] = true;
								SEARCH(a32) {
									used[a32] = true;

									int need41 = sum - (a[a14] + a[a23] + a[a32]);

									//pick a41
									SEARCH(a41)
										if (a[a41] == need41) {
											used[a41] = true;

											SEARCH(a12) {
												used[a12] = true;
												//pick a42
												int need42 = sum - (a[a12] + a[a22] + a[a32]);
//												cout << need42 << endl;
												SEARCH(a42)
													if (a[a42] == need42) {
														used[a42] = true;

														//pick a13
														int need13 = sum - (a[a11] + a[a12] + a[a14]);
														SEARCH(a13)
															if (a[a13] == need13) {
																used[a13] = true;

																//pick a43
																int need43 = sum - (a[a41] + a[a42] + a[a44]);
																SEARCH(a43)
																	if (a[a43] == need43) {
																		used[a43] = true;

																		SEARCH(a21) {
																			used[a21] = true;

																			//pick a24
																			int need24 = sum - (a[a21] + a[a22] + a[a23]);
																			SEARCH(a24)
																				if (a[a24] == need24) {
																					used[a24] = true;

																					//pick a31
																					int need31 = sum - (a[a11] + a[a21] + a[a41]);

																					SEARCH(a31)
																						if (a[a31] == need31) {
																							used[a31] = true;

																							int need34 = sum - (a[a31] + a[a32] + a[a33]);
																							SEARCH(a34)
																								if (a[a34] == need34) {
																									used[a34] = true;

																									int y[4][4] = { { a11, a12, a13, a14 }, { a21, a22, a23, a24 }, { a31, a32, a33, a34 }, { a41, a42,
																											a43, a44 } };

																									int x[4][4];

																									for (int r = 0; r < 4; ++r) {
																										for (int c = 0; c < 4; ++c) {
																											x[r][c] = a[y[r][c]];
																										}
																									}

																									if (check(x, 4)) {
																										cout << sum << endl;
																										for (int r = 0; r < n; ++r) {
																											for (int c = 0; c < n; ++c) {
																												cout << x[r][c] << " ";
																											}
																											cout << endl;
																										}
																										cout << endl;
																										return 0;
																									}

																									used[a34] = false;
																									break;
																								}
																							used[a31] = false;
																							break;
																						}

																					used[a24] = false;
																					break;
																				}

																			used[a21] = false;
																		}

																		used[a43] = false;
																		break;
																	}

																used[a13] = false;
																break;
															}

														used[a42] = false;
														break;
													}
												used[a12] = false;
											}

											used[a41] = false;
											break;
										}

									used[a32] = false;
								}
								used[a23] = false;
							}
							used[a14] = false;
						}

						used[a44] = false;
						break;
					}

				used[a33] = false;
			}
			used[a22] = false;
		}
		used[a11] = false;
	}
}
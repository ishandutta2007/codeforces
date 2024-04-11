# include <bits/stdc++.h>
using namespace std;
pair <int, int> in() {
	char input[10];
	scanf("%s", input);
	return make_pair(input[0] - 'a', input[1] - '1');
}
bool attacked[8][8];
void put_rook(pair <int, int> wh, pair <int, int> wking) {
	for (int i = 1; i < 8; ++i) {
		if (wh.first + i >= 8 || make_pair(wh.first + i, wh.second) == wking)
			break;
		attacked[wh.first + i][wh.second] = true;
	}
	for (int i = 1; i < 8; ++i) {
		if (wh.first - i < 0 || make_pair(wh.first - i, wh.second) == wking)
			break;
		attacked[wh.first - i][wh.second] = true;
	}
	for (int i = 1; i < 8; ++i) {
		if (wh.second + i >= 8 || make_pair(wh.first, wh.second + i) == wking)
			break;
		attacked[wh.first][wh.second + i] = true;
	}
	for (int i = 1; i < 8; ++i) {
		if (wh.second - i < 0 || make_pair(wh.first, wh.second - i) == wking)
			break;
		attacked[wh.first][wh.second - i] = true;
	}
}
void put_king(pair <int, int> wh) {
	for (int i = wh.first - 1; i <= wh.first + 1; ++i)
		for (int j = wh.second - 1; j <= wh.second + 1; ++j)
			if (i >= 0 && j >= 0 && i < 8 && j < 8)
				attacked[i][j] = true;
}
bool mated(pair <int, int> wh) {
	for (int i = wh.first - 1; i <= wh.first + 1; ++i)
		for (int j = wh.second - 1; j <= wh.second + 1; ++j)
			if (i >= 0 && j >= 0 && i < 8 && j < 8)
				if (!attacked[i][j])
					return false;
	return true;
}
int main() {
	pair <int, int> rook = in();
	pair <int, int> rook2 = in();
	pair <int, int> wking = in();
	pair <int, int> bking = in();
	put_rook(rook, wking);
	put_rook(rook2, wking);
	put_king(wking);
	if (mated(bking))
		printf("CHECKMATE\n");
	else
		printf("OTHER\n");
}
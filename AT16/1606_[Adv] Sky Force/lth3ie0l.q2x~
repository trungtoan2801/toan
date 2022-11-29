#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SIZE 15

int map[SIZE][SIZE];
int N;
int best;

void resetData() {
	int i, j;
	best = -1;
	for (i = 0; i < SIZE; ++i) {
		for (j = 0; j < 5; ++j) {
			map[i][j] = 0;
		}
	}
}

void move(int row, int col, int coin, int ignoreEnemy, bool have_bomb) {
	if (col < 0 || col > 4) return;

	if (row < 0) {
		if (best < coin) best = coin;
		return;
	}

	//process current cell
	if (map[row][col] == 1) {
		++coin;
	}
	else if (map[row][col] == 2 && ignoreEnemy <= 0) {
		if (coin > 0) --coin;
		else return;
	}

	//scroll down bombed area
	--ignoreEnemy;

	//move up
	move(row - 1, col, coin, ignoreEnemy, have_bomb);

	//use bomb and move up
	if (have_bomb) move(row - 1, col, coin, 5, false);

	//move top-left
	move(row - 1, col - 1, coin, ignoreEnemy, have_bomb);

	//use bomb and move top-left
	if (have_bomb) move(row - 1, col - 1, coin, 5, false);

	//move top-right
	move(row - 1, col + 1, coin, ignoreEnemy, have_bomb);

	//use bomb and move top-right
	if (have_bomb) move(row - 1, col + 1, coin, 5, false);
}

int main() {
#ifdef _CRT_SECURE_NO_WARNINGS
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T, testcase;
	scanf("%d", &T);
	for (testcase = 1; testcase <= T; ++testcase) {
		scanf("%d", &N);
		resetData();
		int i, j, k;
		for (i = 0; i < N; ++i) {
			for (j = 0; j < 5; ++j) {
				scanf("%d", &map[i][j]);
			}
		}

		move(N, 2, 0, 0, true);

		printf("Case #%d\n%d\n", testcase, best);
	}
	return 0;
}
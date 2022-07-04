#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;
int n;
int cnt;


bool isValid(vector<string>& board,int x, int y) {
	for (int i = 0;i < n;i++) {
		if (board[i][y] == 'Q') return false;
	}
	for (int i = x-1, j = y-1;i >= 0 && j >= 0;i--, j--) {
		if (board[i][j] == 'Q') return false;
	}
	for(int i = x-1, j = y+1;i>=0 && j < n;i--, j++) {
		if (board[i][j] == 'Q') return false;
	}
	return true;
}
void backtrack(vector<string>&board, int row) {
	if (row == n) {
		cnt++;
		return;
	}
	for (int col = 0; col < n; col++) {
		if (isValid(board,row, col)) {
			board[row][col] = 'Q';
			backtrack(board,row + 1);
			board[row][col] = '.';
		}
	}
}
int main() {
	cin >> n;
	vector<string> board(n, string(n, '.'));
	backtrack(board,0);
	cout << cnt << endl;
}
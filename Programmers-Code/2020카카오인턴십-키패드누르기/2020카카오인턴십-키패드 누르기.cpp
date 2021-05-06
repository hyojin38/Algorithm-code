#include<iostream>
#include<vector>
#include <queue>
#include <string>
using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int MAP[4][3] = { {1,2,3},
			   {4,5,6},
			   {7,8,9},
			   {-1,0,-1}
};
bool visited[4][3];
queue <pair< pair <int, int >, int > > Q;
struct handpos {
	int x, y;
};
int finddis(int sx, int sy, int Dx, int Dy) {

	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j < 3; j++) {
			visited[i][j] = false;
		}
	}
	while (!Q.empty()) {
		Q.pop();
	}

	Q.push({ {sx, sy},0 });
	visited[sx][sy] = true;


	while (!Q.empty()) {
		int x = Q.front().first.first;
		int y = Q.front().first.second;
		int cnt = Q.front().second;
		//cout << x << y << cnt << endl;
		Q.pop();

		if (x == Dx && y == Dy) {
		//	cout << "!" << cnt;
			return cnt;
		}
		//return cnt;


		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			int ncnt = cnt + 1;

			if (nx < 0 || ny < 0 || nx>3 || ny>2) continue;
			if (visited[nx][ny] == true) continue;

			Q.push({ {nx, ny},ncnt });
			visited[nx][ny] = true;


		}

	}


}
bool Righthand(string hand) {
	if (hand[0] == 'r')
		return true;
	else
		return false;
}
string solution(vector<int> numbers, string hand) {

	string answer = "";

	vector< pair<int, int> > phone;
	phone.push_back({ 3,1 });//0
	phone.push_back({ 0,0 });//1
	phone.push_back({ 0,1 });//2
	phone.push_back({ 0,2 });//3
	phone.push_back({ 1,0 });//4
	phone.push_back({ 1,1 });//5
	phone.push_back({ 1,2 });//6
	phone.push_back({ 2,0 });//7
	phone.push_back({ 2,1 });//8
	phone.push_back({ 2,2 });//9




	bool rightvs = Righthand(hand);
	int num;
	handpos rhand;
	handpos lhand;
	rhand.x = 3; rhand.y = 0;
	lhand.x = 3; lhand.y = 2;

	int x, y;
	int disright;
	int disleft;
	for (int i = 0; i < numbers.size(); i++) {
		num = numbers[i];
		//cout << i << "¹øÂ°:"<<"(" << lhand.x << " " << lhand.y << ")("<<rhand.x<<" "<<rhand.y<<")" << num <<endl ;
		
		int x = phone[num].first;
		int y = phone[num].second;

		if (num == 1 || num == 4 || num == 7) {
			answer += 'L'; lhand.x = x;  lhand.y = y;
		}
		else if (num == 3 || num == 6 || num == 9) {
			answer += 'R'; rhand.x = x; rhand.y = y;
		}
		else {
			disright = finddis(rhand.x, rhand.y, x, y);
			disleft=finddis(lhand.x,lhand.y,x,y);

			if (disright > disleft) {
				answer += 'L';      lhand.x = x;  lhand.y = y;

			}
			else if (disright < disleft) {
				answer += 'R';            rhand.x = x;         rhand.y = y;
			}
			else {
				if (rightvs == true) {
					answer += 'R';            rhand.x = x;         rhand.y = y;
				}
				else {
					answer += 'L';      lhand.x = x;  lhand.y = y;
				}
			}
		}



	}



	return answer;
}



int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	vector <int> numbers;
	numbers.push_back(1);
	numbers.push_back(3);
	numbers.push_back(4);
	numbers.push_back(5);
	numbers.push_back(8);
	numbers.push_back(2);
	numbers.push_back(1);
	numbers.push_back(4);
	numbers.push_back(5);
	numbers.push_back(9);
	numbers.push_back(5);

	string hand = "right";
	string answer=solution(numbers, hand);
	cout << answer;
	return 0;
}
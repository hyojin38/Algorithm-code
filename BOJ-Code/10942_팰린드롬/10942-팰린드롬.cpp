//팰린드롬=회문 거꾸로 읽어도 제대로 읽는것과 같은 문장이나 낱말 숫자 문자열 등
#include<iostream>
#include <vector>

#define endl "\n"
#define MAX 2000+1

using namespace std;

int N,M,S,E;
vector <int> Arr;
int DP[MAX][MAX];

void Input() {
	cin >> N;
	int temp; 
	Arr.push_back(0); //1부터 시작하기 위해

	for (int i = 1; i <= N; i++) {
		cin >> temp;
		Arr.push_back(temp);
	}
	cin >> M;
	
}
void makeDP() {

	for (int i = 1; i <= N; i++)
		DP[i][i] = 1; // 한개는 팰린드롬

	for (int i = 1; i <= N - 1; i++) { //두개짜리 팬린드롬
		if (Arr[i] == Arr[i + 1]) // Arr[1]==Arr[2] 이면 DP[1][2]=1
			DP[i][i + 1] = 1;     // 7 7 8 9 8 8 와 같은 경우 1.2   5.6 은 팰린드롬 
	}


	// 1- 3,4,5
	// 2- 4.5
	// 3- 5

	for (int s = 2; s <= N - S; s++) {
		for (int i = 1; i <= N; i++) {
	
			int j = i + s;
			if (j > N) continue;
			if (DP[i + 1][j - 1] == 1 && Arr[i] == Arr[j]) // 1.3  사이를 확인하기 위해서는 = 2.2가 가 팰린트론인지 && Arr[1]==Arr[3] 인지 확인 필요
				DP[i][j] = 1;
			else { DP[i][j] = 0; }
		}
	}
	//for (int i = 1; i <= N; i++) {
	//	for (int j = i + 2; j <= N; j++) {
	//		if (DP[i + 1][j - 1] == 1 && Arr[i] == Arr[j]) // 1.3  사이를 확인하기 위해서는 = 2.2가 가 팰린트론인지 && Arr[1]==Arr[3] 인지 확인 필요
	//			DP[i][j] = 1;
	//		else DP[i][j] = 0;
	//	}
	//}

	//cout << endl;
	//for (int i = 1; i <= N; i++) {
	//	for (int j = 1; j <= N; j++) {
	//		cout<< DP[i][j]<<" ";
	//	}
	//	cout << endl;
	//}

}
void Solution() {
	cin >> S >> E;

	if (DP[S][E] == 1)
		cout << 1 << endl;
	else
		cout << 0 << endl;

	

}
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	Input();
	
	makeDP();
	for (int i = 0; i < M; i++) {
		Solution();
	}
	return 0;
}
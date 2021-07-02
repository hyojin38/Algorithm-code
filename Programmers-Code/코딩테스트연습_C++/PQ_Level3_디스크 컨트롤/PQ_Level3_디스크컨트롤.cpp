#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> jobs) {

	priority_queue< pair<int, int>, vector < pair <int, int> >, greater<pair<int, int> > > PQ;
	int check = jobs.size();
	int Ans = 0;
	for (int i = 0; i < jobs.size(); i++) {
		PQ.push({ jobs[i][0],jobs[i][1] });
	}

	int T = 0;
	priority_queue< pair<int, int>, vector < pair <int, int> >, greater<pair<int, int> > > PQ2;
	while (check > 0) {

		while (!PQ.empty()) {
			int first = PQ.top().first;
			int second = PQ.top().second;

			if (first <= T) {
				PQ.pop();
				PQ2.push({ second,first }); //6 2 //9 1
				continue;
			}
			else {
				break;
			}
		}

		if (PQ2.empty()) {
			T++;
		}
		else {
			int secondtime = PQ2.top().first;
			int first = PQ2.top().second;
			PQ2.pop();
			check--;
		//	cout << T << ":Input½Ã°£:" << first << "+" << secondtime << endl;
			T = T + secondtime;
		//	cout << T << endl;
			Ans += T - first;
		}
	}

	return Ans / (jobs.size());
}
void main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<vector<int>> jobs = { {0,3},{1,9},{2,6} };

	cout << solution(jobs);

}
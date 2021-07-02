#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include "PQ_Level2_´õ¸Ê°Ô.h"
using namespace std;

int solution(vector<int> scoville, int K) {
	priority_queue < int, vector<int>, greater<int> > pq;

	for (int i = 0; i < scoville.size(); i++) {
		pq.push(scoville[i]);
	}

	int T = 0;
	while (!pq.empty()) {
		int first = pq.top();
		pq.pop();
		if (first >= K) {
			return T;
		}
		else {
			T++;
			if (pq.empty()) {
				return -1;
			}
			else {
				int second = pq.top();
				pq.pop();

				int newfood = first + (second * 2);
				pq.push(newfood);
			}
		}

	}
}
void mainsolution() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<int> scoville = { 1, 2, 3, 9, 10, 12 };
	int K = 7;
	cout<<solution(scoville,K);
	
}
#include<iostream>
#include<vector>

#define MAX 5
using namespace std;

int Arr[MAX];
bool Select[MAX];
vector<int> B;

void DFS(int Idx, int Cnt)
{
	if (Cnt == 3)
	{
		for (int i = 0; i < B.size(); i++)
		{
			cout << B[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = Idx; i < MAX; i++)
	{
		if (Select[i] == true) continue;

		Select[i] = true;
		B.push_back(Arr[i]);
		DFS(i, Cnt + 1);
		Select[i] = false;
		B.pop_back();
	}
}

int main(void)
{
	Arr[0] = 1;
	Arr[1] = 2;
	Arr[2] = 3;
	Arr[3] = 4;
	Arr[4] = 5;

	DFS(0, 0);
}
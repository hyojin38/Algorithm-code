# [BOJ] 17472 다리 만들기 2

### 문제 바로가기

>  https://www.acmicpc.net/problem/17472

### 알고리즘

> - 구현
> -  그래프 이론
> -  그래프 탐색
> -  브루트포스 알고리즘
> - BFS DFS
> -  MST

### 문제 풀이 및 주의

>다시 풀어보기  

```c++
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <stdio.h>
#include <iomanip>
#include <math.h>
#include <map>
#include <list>
#include <numeric>

using namespace std;

int getParent(int parent[], int x)
{
	if (parent[x] == x)	return parent[x];
	return parent[x]= getParent(parent, parent[x]);
}

void unionParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a > b) {
		parent[a] = b;
	}
	else {
		parent[b] = a;
	}
}

int findParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b)	return 1;
	else	return 0;
}

int parent[101];
int arr[11][11];
int check[11][11];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int row, col, n=0;

void bfs(int x, int y)
{
	if (check[x][y] == true)	return;
	n++;
	queue<pair<int, int>> q;
	check[x][y] = true;
	q.push(make_pair(x, y));
	parent[(x - 1) * col + y] = n;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int newX = x + dx[i];
			int newY = y + dy[i];
			if (newX >= 1 && newX <= row && newY >= 1 && newY <= col)
			{
				if (!check[newX][newY] && arr[newX][newY] == 1)
				{
					check[newX][newY] = true;
					parent[(newX - 1) * col + newY] = n;
					q.push(make_pair(newX, newY));
				}
			}
		}
	}
}

class Island {
public:
	int node[2], distance;
	Island(int a, int b, int distance)
	{
		node[0] = a;
		node[1] = b;
		this->distance = distance;
	}
	bool operator<(Island& is) {
		return this->distance < is.distance;
	}
};

int main(void)
{
	cin >> row >> col;
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 0)
			{
				parent[(i - 1) * col + j] = 0;
			}
			else
			{
				parent[(i - 1) * col + j] = (i-1)*col+j;
			}
		}
	}

	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (arr[i][j] == 1)
			{
				bfs(i, j);
			}
		}
	}


	//섬과 섬의 거리를 모두 벡터에다가 저장하도록 하자!!! (단 거리가 1인경우는 Pass)
	vector<Island> v;
	for (int i = 1; i <= row; i++) //좌우로 섬과 섬의 거리를 구해오기
	{
		for (int j = 1; j <= col; j++)
		{
			if (arr[i][j] == 1)
			{
				int distance = 0;
				int a = parent[(i - 1) * col + j];
				int b = 0;
				for (int k = j+1; k <= col; k++) //0인 위치를 찾아내기
				{
					if (k == col)
					{
						j = col;
						break;
					}
					if (arr[i][k] == 1)	continue;
					else {
						j = k;
						break;
					}
				}
				if (j == col)	break;
				for (int k = j; k <= col; k++)
				{
					if (arr[i][k] == 0)	distance++;
					else {
						b = parent[(i - 1) * col + k];
						break;
					}
				}
				if (b == 0) //섬을 발견하지 못한 경우
				{
					j = j + distance - 1;
				}
				else
				{
					if(distance>1)	v.push_back(Island(a, b, distance));
					j = j + distance - 1;
				}
			}
		}
	}

	for (int i = 1; i <= col; i++) //위아래로 섬과 섬의 거리를 구해오기
	{
		for (int j = 1; j <= row; j++)
		{
			if (arr[j][i] == 1)
			{
				int distance = 0;
				int a = parent[(j - 1) * col + i];
				int b = 0;
				for (int k = j + 1; k <= row; k++) //0인 위치를 찾아내기
				{
					if (k == row) {
						j = row;
						break;
					}
					if (arr[k][i] == 1)	continue;
					else {
						j = k;
						break;
					}
				}
				if (j == row)	break;
				for (int k = j; k <= row; k++)
				{
					if (arr[k][i] == 0)	distance++;
					else {
						b = parent[(k - 1) * col + i];
						break;
					}
				}
				if (b == 0) //섬을 발견하지 못한 경우
				{
					j = j + distance - 1;
				}
				else
				{
					if (distance > 1)	v.push_back(Island(a, b, distance));
					j = j + distance - 1;
				}
			}
		}
	}

	sort(v.begin(), v.end());

	for (int i = 1; i <= row*col; i++)
	{
		parent[i] = i;
	}

	int sum = 0;
	int cnt = 1;
	for (int i = 0; i < v.size(); i++)
	{
		int x = v[i].node[0];
		int y = v[i].node[1];
		int distance = v[i].distance;
		if (!findParent(parent, x, y))
		{
			cnt++;
			unionParent(parent, x, y);
			sum += distance;
		}
	}

	if (cnt!=n)
	{
		printf("-1\n");
		return 0;
	}
	printf("%d\n", sum);
	return 0;
}
```




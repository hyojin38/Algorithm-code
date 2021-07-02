# 알고리즘 개념 정리

## 1. 해시

## 2. 스택

## 3. 큐

## 4. Heap

### STL (priority_queue)

```c++
//	priority_queue< 자료형, 구현체 ,비교연산자>
#include <iostream>
#include <queue>

using namespace std;

struct a {
    int start;
    int end;
    int value;
};

struct comp{ //less 역할을 대신 해줌
    bool operator()(a t, a u){
        return t.value < u.value;
    }
};

int main() {

    priority_queue<int, vector<int>, less<int>> pq;// max heap
    // or priority_queue<int> pq;
     priority_queue<int, vector<int>, greater<int>> pq2;// min heap
    priority_queue<a, vector<a>, comp> pq3;
    priority_queue<pair<int,int>> temp;
    // 첫번째 요소로 먼저 비교하고 같은 경우 그 두번째 요소로 비교하는 방식이다.
    
 
	// push(element)
	pq.push(5);
	pq.push(2);
	pq.push(8);
	pq.push(9);
	pq.push(1);
	pq.push(14);

	// pop()
	pq.pop();
	pq.pop();

	// top();
	cout << "pq top: " << pq.top() << '\n';

	// empty(), size()
	if(!pq.empty()) 
        cout << "pq size: " << pq.size() << '\n';

	// pop all
	while(!pq.empty()){
		cout << pq.top() << " ";
		pq.pop();
	}
    return 0;
}
```



### 힙이란?

힙(Heap)은 최댓값 및 최솟값을 찾아내는 연산을 빠르게 하기 위해 고안된 완전이진트리(Complete binary tree)를 기본으로 한 자료구조(tree-based structure)다. 최악의 경우가 생겨도 힙은 완전 이진 트리이므로 항상 O(logN)의 시간에 해결될 수 있도록 해준다.

> **힙을 이용한다면 최댓값 혹은 최솟값을 O(logN)에 찾을 수 있다. (일반 배열 사용시 O(N))**

### 최대 힙. 최소 힙

최대 힙은 완전 이진트리의 root 부분에 최댓값이 항상 존재.

최소 힙은 완전 이진트리의 root 부분에 최솟값이 항상 존재.

- **최대 힙의 특성**

   임의의 subtree에서 root 가 되는 노드를 잡으면 항상 subtree에서의 root 노드는 그 subtree에서 최댓값을 유지한다.

- **최소 힙의 특성** 

   임의의 subtree에서 root가 되는 노드를 잡으면 항상 subtree에서의 root 노드는 그 subtree에서 최솟값을 유지한다.

- 주의해야 할 점 :

  '힙의 자식 노드에서 작은 것이 왼쪽, 큰 것이 오른쪽' 이런 것은 존재하지 않는다. ⇒ 즉, 왼쪽 오른쪽에 무슨 노드가 오던간에 해당하는 subtree에서 루트노드보다 큰 (minheap에서는 작은) 값이면 된다.

실제 구현시, 최소 힙은 최대 힙에서 음수 값으로만 구현해주면 되기 때문에 최대 힙 구현만 알고 있으면 됨.

### 최대 힙 삽입 과정(push) 0(log N)

1. Insert 할 값을 힙의 마지막 위치에 삽입한다.
2. 부모 노드와 비교를 해서 Insert 할 값이 더 크다면 swap 해준다.
3. 2번 과정을 계속 반복한다.

### 최대 힙 삭제 과정(pop) 0(log N)

pop 이기 때문에 root 부터 삭제하면 된다고 이해하면 될듯.

1. 삭제할 값(root)를 빼낸다.
2. 힙에서 마지막에 있는 노드를 root 로 올린다.
3. root로 올린 노드와 그 자식들의 노드를 비교해서 swap 해준다.
4. 2~3번 과정을 반복한다.

### 이진 탐색 트리(Binary Search Tree) 와의 차이점

- 힙은 `자식 노드가 부모 노드보다 크면 오른쪽으로 삽입, 작으면 왼쪽으로 삽입` 과 같은 조건이 존재하지 않는다.
- 하지만 이진 탐색 트리에서의 노드별 값 크기순은 `왼쪽 자식 < 부모 < 오른쪽 자식` 순으로 된다.

## 5. 정렬

## 6. 완전 탐색

## 7. Greedy 탐욕법

## 8. 동적계획법(DP)

## 9. DFS. BFS

## 10. 이분탐색


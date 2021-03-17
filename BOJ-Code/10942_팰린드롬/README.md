# [BOJ] 10942 팰린드롬?

### 문제 바로가기

>  https://www.acmicpc.net/problem/10942

### 알고리즘

> DP.  문자열

### 문제 풀이 및 주의

> **DP**
>
> 1. 2중 for문
>
> 2. 초기화 
>
>    1) 길이가 1인경우
>
>    2) 길이가 2인경우 ex) 1 2 2 3
>
> 3. for문 돌아가는 순서 
>
>    1-3.4.5.6
>
>    2-4.5.6
>
>    3-5.6
>
>    의 순서가 아닌
>
>    1,3 / 2,4/ 3,5
>
>    1,4 / 2,5
>
>    1,5
>
>    와 같은 순서가 되어야 사이에 팰린드롬인지 확인 가능하다  



>**시간초과**
>
>제한 조건을 보고 프로그램이 몇번의 연산을 할지 스스로 측정해보기
>
>질문이 100만줄 일때 2000개의 글자 중 대부분사용 계속 비교는 절대로 통과할 수 없다.



>팰린드롬?
>
>=회문 거꾸로 읽어도 제대로 읽는것과 같은 문장이나 낱말 숫자 문자열 등



> 틀린 코드
>
> 1. 규칙을 찾지 못하고 계속 갱신해야한다고 생각했음
>
> 2.  사이의 수의 갯수를 짝수인지 홀수인지 체크해야한다고 생각했음
>
>    ```c++
>    
>    int N,M,S,E;
>    vector <int> V;
>    vector <int> MAP(MAX);
>    void Input() {
>    	cin >> N;
>    	int temp; 
>    	V.push_back(0); //1부터 시작하기 위해
>    
>    	for (int i = 0; i < N; i++) {
>    		cin >> temp;
>    		V.push_back(temp);
>    	}
>    	cin >> M;
>    }
>    void Solution() {
>    	cin >> S >> E;
>    
>    
>    	if (S == E) {
>    		MAP[S] = E;
>    		cout << 1 <<endl;
>    	}
>    	else if (MAP[S] == E) {
>    		cout << 1 << endl;
>    		return;
>    	}
>    	else if (MAP[S] < S) {
>    
>    		int size = E - S + 1;
>    		int cnt;
>    		if (size % 2 == 1) {//홀수
>    			cnt = (size + 1) / 2;
>    		}
>    		else {
>    			cnt = size / 2;
>    		}
>    
>    		for (int i = 0; i < cnt; i++) {
>    
>    			int s = S + i;
>    			int e = E - i;
>    			if (MAP[s] == e) {
>    				//갱신
>    				for (int j = 0; j < i; j++) {
>    					MAP[S + j] = E - j;
>    				}
>    				cout << 1 << endl;
>    				return;
>    			}
>    			if (V[s] == V[e]) {
>    				continue;
>    			}
>    			else {
>    				cout << 0 << endl;
>    				return;
>    			}
>    		}
>    		cout << 1 << endl;
>    	}
>    
>    }
>    int main() {
>    
>    	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
>    	freopen("Text.txt", "r", stdin);
>    
>    	Input();
>    	for (int i = 0; i < M; i++) {
>    		Solution();
>    	}
>    	return 0;
>    }
>    ```
>
>    
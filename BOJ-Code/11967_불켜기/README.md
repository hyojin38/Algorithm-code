# [BOJ] 11967 불켜기

### 문제 바로가기

>  https://www.acmicpc.net/problem/11967

### 알고리즘

> 구현. 그래프 이론 . 그래프 탐색 . DFS

### 문제 풀이 및 주의

> 1. 메모리초과 - if 문에서 걸러주지 않음
>
> 2. 시간 초과 - 처음 저장할때 . 기존 생각대로  vector<pair(int,int)> 혹은 vector<light> MAP [][][ ] [][][ ] 에 저장 하기
>
> 3. 불을 켠 방을 찾는것. 들어간 방을 찾는 것이 아닙니다.
>
> 4. ```C++
>        for (int i = 0; i < EQ.size(); i++) {
>              int cx = EQ.front().first;
>              int cy = EQ.front().second;
>              EQ.pop();
>              Q.push(make_pair(cx, cy));
>        }
>    ```
>
>    size로  for문을 돌릴때 POP 하면 size가 변한다. 주의하기 ( 오류 코드 )



>***구조체***
>
>```c++
>struct Light{ //구조체 선언 (구조체 이름은 대문자로 시작. 변수와 구분)
>	int x;	//멤버. 필드
>	int y; 
>};   //끝에 세미콜론
>
>Light l1 // 구조체 Light type 변수 l1선언
>l1.x=2; //구조체 멤버 접근은 . (멤버 선택 연산자) 이용
>Light l2={2,28} //초기화( 명시하지 않는 경우 c++ 11 에서는 default로 초기화 )
>
>```



>***pair***
>
>```c++
>LightQ.push({ cx,cy });//	LightQ.push(make_pair(cx, cy));
>```



> ***auto***
>
> ```c++
> 	for (auto pos : ListMap[x][y]) {
> 		int cx = pos.x;
> 		int cy = pos.y;
> 		//cout << cx << ","<<cy<<endl;
> 		if (MAP[cx][cy] == 1 || LightMAP[cx][cy] == true) continue;
> 		LightQ.push({ cx,cy });//	LightQ.push(make_pair(cx, cy));
> 		LightMAP[cx][cy] = true;
> 		Ans++;
> 	}
> ```
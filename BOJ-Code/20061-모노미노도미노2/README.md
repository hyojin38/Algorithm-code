# [BOJ] 20061 모노미노도미노2

### 문제 바로가기

>  https://www.acmicpc.net/problem/20061

### 알고리즘

> 구현. 시뮬
>

### 문제 풀이 및 주의

>**주의1. 블록 내려줄때**
>
>```c++
>// 틀렸습니다
>void blueLineBreak(int t) {
>
>	for (int y = 0; y <= 3; y++) {
>		blue[t][y] = false;
>	}
>
>	if (t != 0) {
>		for (int x = t - 1; x >= 0; x--) {
>
>			for (int y = 0; y <= 3; y++) {
>				if (blue[x][y] == true) {
>					blue[x][y] = false;
>					blue[x + 1][y] = true;
>				}
>			}
>		}
>	}
>}
>```
>
>```c++
>void LineBreak(bool Map[6][4],int t) {// 3.4개 가득 찬경우 없애는 단계
>
>	for (int x = t - 1; x >= 0; x--) {
>		for (int y = 0; y <= 3; y++) {
>			Map[x+1][y] = Map[x][y];
>		}
>	}
>	//맨 위를 정의해주어야한다
>	for (int y = 0; y <= 3; y++) {
>		Map[0][y] = false;
>	}
>}
>```



> **코드 중복 줄이기 **
>
> ```c++
> void transPos(int* t, int* x, int* y) { //블루 그린 변형
> 
> 	//(x.y)->(y,3-x)
> 
> 	int tx = *x;
> 	int ty = *y;
> 
> 	*x = ty, *y = 3 - tx;
> 
> 	if (*t == 2) *t = 3;
> 	else if (*t == 3) {
> 		*t = 2;
> 		*y = *y - 1;
> 	}
> 
> }
> void main(){
> 	int t, x, y;
>     DownBlock(green, t, x, y);
>     transPos(&t, &x, &y); // x,y,t를 바꿀수 있음
>     DownBlock(blue, t, x, y);
> }
> ```
>
> 
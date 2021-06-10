# [BOJ] 21608-상어 초등학교

### 문제 바로가기

>  https://www.acmicpc.net/problem/21608

### 알고리즘

> - [구현](https://www.acmicpc.net/problem/tag/102)

> #### 런타임 에러 (OutOfBounds)
>
> int map[MAX*MAX] 와 같은식으로 배열의 크기 지정할 수 없다
>
> 새로 MAX를 정의해서 선언하여 해결

>#### C++ sort 구조체 정렬
>
>```c++
>#include <algorithm>
>struct Seat{
>  int x,y;  
>};
>bool compare( Seat A, Seat B){
>
>	if(A.x>B.x) return true; //> 오름차순 정렬
>
>	else return false;
>
>}
>
>sort(V.begin(),V.end(),compare);
>```

> #### Vector erase
>
> vector : 맨 뒤에 원소를 추가하거나 제거하는 것은 빠르지만,임의의 위치에 원소를 추가하거나 제거하는 것은 O(n)*O*(*n*) 으로 느리다
>
> - 임의의 위치 원소 접근 (`[], at`) : O(1)*O*(1)
> - 맨 뒤에 원소 추가 및 제거 ([push_back](https://modoocode.com/185)/`pop_back`) : amortized O(1)*O*(1); (평균적으로 O(1)*O*(1) 이지만 최악의 경우 O(n)*O*(*n*) )
> - 임의의 위치 원소 추가 및 제거 (`insert, erase`) : O(n)*O*(*n*)
>
> ```c++
> 	printf("맨 앞 원소 삭제 = ");
>     v.erase(v.begin());
>   
>  
>     printf("두 번째 원소 삭제 = ");
>     v.erase(v.begin() + 1);
> 
>  
>     printf("끝 원소 삭제 = ");
>     v.erase(v.end() - 1);
>  
>     printf("숫자 8 삭제 = ");    
>     for (int i = 0; i < v.size(); i++)
>     {
>         if (v.at(i) == 8)
>         {
>             v.erase(v.begin() + i);
>             break;
>         }
>     }
>    ------------------------------------
>  
>     printf("제일 처음에 숫자 1 삽입 = ");
>     v.insert(v.begin(), 1);
> 
>     printf("제일 끝에 숫자 10 삽입 = ");
>     v.insert(v.end(), 10);
>     
>  
>     printf("3번째에 3 삽입 = ");
>     v.insert(v.begin() + 2, 3); //0,1,2 이므로 0에서 2칸뒤! +2
>  
>  
> ```


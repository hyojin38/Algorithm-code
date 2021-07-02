## Vector

#include <vector>

- 길이 변경 할 수 있는 배열
- array처럼 배열의 길이가 바뀔 때 마다 바뀌는 메모리 신경 쓰지 않아도 된다

```
push_back();
pop_back();
insert(2,3,4); //2번째 위치에 3개의 4값 삽입 나머지는 밀림
insert(2,3); //2번째 위치에 3의 값을 삽입. 삽입한 곳의 iter 반환
erase(v.begin()+1);
erase(v.begin()+2,v.end());
```



## 1. erase : vector 특정 원소 지우기


>#### - erase(int position)
>
>```c++
>v.erase(v.begin()+1);// vector v에서 1번째 원소를 지운다
>```
>
>#### - erase(int start, int end)
>
>```c++
>v.erase(v.begin()+1, v.begin()+3);
>// vector v에서 1번째부터 2번째까지의 원소를 지운다
>// 1번. 2번을 지운다
>// v.begin()+1~ v.begin()+3 전까지 지운다
>```
>
>
>
>```c++
>vector<int> v(5);
>for(int i = 0 ; i < 5; i++) v[i] = i+1; // 1 2 3 4 5
>
> 1. 
> v.erase(v.begin() + 1);
> for(int it : v) cout << it << " "; // 1 3 4 5
>
> 2. 
> v.erase(v.begin() + 1, v.begin() + 3);
> for(int it : v) cout << it << " "; // 1  5
>```



## 2. iterator

> v.begin(), v.end() 입력시 iterator 반환 됨
>
> ```c++
> for(vector<int>::iterator it=v.begin; it != 	v.end(); it++){
> 	cout<<*it<<" ";
> }
> ```


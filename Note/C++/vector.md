## Vector

#####    vector 특정 원소 지우기


>#### - erase(int position)
>
>```c++
>v.erase(v.begin()+1);// vector v에서 1번째 원소를 지운다
>```
>
>#### - erase(int start, int end)
>
>```c++
>v.erase(v.begin()+1, v.begin+3);// vector v에서 1번째부터 2번째까지의 원소를 지운다
>```
>
>
>
>```c++
>vector<int> v(5);
>for(int i = 0 ; i < 5; i++) v[i] = i+1; // 1 2 3 4 5
>
>  1. 
>  v.erase(v.begin() + 1);
>  for(int it : v) cout << it << " "; // 1 3 4 5
>
>  2. 
>  v.erase(v.begin() + 1, v.begin() + 3);
>  for(int it : v) cout << it << " "; // 1 4 5
>```
>
>

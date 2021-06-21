# map

#include < map >

- 특정 키(key)로 데이터 접근, 관리

- 키로 값에 접근하며 삽입.삭제가 빠름

- 자료가 정렬되어 보관됨

  이진탐색트리(Binary search tree)에서 사용되는 키값을 의미 (이진트리가 아님. 최근엔 Red-Black Tree 사용한다고 한다)

  이진 탐색 트리 : 0(log n) 의 속도

## 1. Hashmap

#include <hash_map>

using namespace stdext;

정렬이 필요없으며 빠른 검색을 원할 때

너무 빈번하게 자료를 삽입, 삭제 하지 않는다

- 탐색속도 : O(1) 이상이다. 이는 Key값 분포에 따라 다르다. hashing key값이 랜덤하게 분포되어 있을 때 가장 좋은 성능 발휘함

- 자료를 정렬하지 않음

- hashmap은 STL 공식 컨테이너에 속하지 않고 따로 구현된 STL 라이브러리 사용 (탐색성능이 안정적이지 못해서 STL 공식 컨테이너에 들어가지 못했다)

   \- map, set : 삽입, 삭제, 탐색 모두 O(log n) 보장

   \- list : 삽입, 삭제 O(1), 탐색, 임의 원소 접근 O(n) 보장

   \- vector : 삽입, 삭제, 탐색 O(n), 임의 원소 접근 O(1) 보장



## 2.map

```c++
# include <map>

map < string, int > map1;

int main(){
	map1.insert({"수학",100});
	
	if(map1.count("국어")==0){
		map1.insert({"국어",80});
	}

}
```


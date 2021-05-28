# c++ STL 

## 1. STL: Standard Template Library

c++ 에서 제공하는 표준 라이브러리로 자료구조 알고리즘 등을 편하게 사용하도록 해줌

- 임의 타입의 객체를 보관할 수 있는 컨테이너(container)

- 컨테이너에 보관된 원소에 접근할 수 있는 반복자 (iterator)

  포인터 같은 역할로 원소 순회시 begin, end를 이용하여 사용

- 반복자들을 가지고 일련의 작업을 수항해은 알고리즘(algorithm)

알고리즘, 컨테이너 , 이터레이터, 함수 등으로 이루어져 있다

```
우리는 템플릿 덕분에 int,string과 평범한 것들 뿐만아니라 우리가 만든 임의의 클래스의 객체들이여도 자유롭게 위 라이브러리의 기능을 사용할 수 있다. c였다면 불가능했을 일이다
```



## 2. Container: 객체(데이터)를 저장하는 자료구조 (보관소)

컨테이너는 자신이 보관하는 원소(element)들의 메모리를 관리하며, 각각의 원소에 접근할 수 있도록 멤버 함수를 제공해준다. 컨테이서 상에서 원소에 접근하는 방법으로 크게 두 가지가 있는데, 하나는 직접 함수를 호출해서 접근하는 것이고, 다른 하나는 반복자(iterator) 을 이용해서 접근하는 것이다. 이에 관해서는 나중에 설명하도록 하겠다.

> STL 컨테이터(STL Container)

특히, STL 컨테이너는 클래스 템플릿(class template) 의 형태로 구현되어 있기 때문에 임의의 타입의 원소들을 위한 컨테이너를 만들 수 있다. **물론 한 컨테이너에는 한 가지 종류의 객체들만 보관할 수 있다**

표준 라이브러리에서는 , 여러가지 형태의 컨테이너 제공 ( 동적배열[vector], queue, stack, heap[priority_queue], list, tree[set], 연관컨테이너[map] 등)



> ## 1) Sequence Container 순차 컨테이너
>
> - 자료를 순차적으로 저장
> - 자료가 적은 경우 유리한 구조
> - vector, list, deque(double ended queue) (arrays, forward-list (?))

> ## 2) Associative Container 연관 컨테이너
>
> - 빠르게 검색 할 수 있는 노드기반 이진트리구조
> - set, map, multiset(여러키를 가지는 set), multimap(여러 키를 가지는 map)
> - <u>Associative Container에 bitset이 들어가나???(?)</u>

> ## 3) unordered Associative Container 순서가 없는 연관 컨테이너
>
> - unordered_set, unordered_map,unordered_multiset, numordered_multimap

>## 4) Container adaptor 컨테이너 어댑터
>
>- 다른 컨테이너 클래스들을 상속받아서 다른 컨테이너 클래스의 객체에 특정한 인터페이스를 제공
>
>- 기존 컨테이너의 인터페이스 중 일부만 제공하는 컨테이너 
>
>  stack 이 deque 에 작용한다면, deque에 stack 이 제공하는 top, pop, push 등의 인터페이스를 사용할 수 있게 되는 것이다.
>
>- stack, queue, priority_queue



## 3. < algorithm >



## 4.  STL 정리

### 0) pair 

	- 두 자료형을 하나의 쌍(pair)로 묶는다. 첫번째는 first, 두번째는 second로 접근가능
	- vector, algorithm의 헤더파일에 include 하고 있어서 별토의 utility 헤더를 물릴 필요가 없다



### 1-1) Vector

- 길이 변경 할 수 있는 배열



### 1-2) list



### 1-3) deque



### 2-1) set, map, multiset(여러키를 가지는 set), multimap



### 3-1)stack, queue, priority_queue



## 5. < string >



## 6. < bitset >


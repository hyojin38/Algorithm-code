# SQL  

1. 데이터 베이스 생성 / 삭제 /확인

```sql
create datbase samsung;//데이터베이스 생성
drop database samsung; //데이터베이스 삭제
Show databases; //생성된 데이터 베이스 확인
```

2. 사용하려는 데이터베이스 선택
```sql
use samsung;
```

3. 데이터베이스 내에 생성된 테이블 확인

```sql
show tables;
```

4. 테이블 생성 / 삭제

```sql
create table tableA (attribute1 int);
create table account (account_number char(10),
                     branch_name char(15),
                     balance int);
                     
drop table tableA;                    
                    
```

5. 튜플 생성

```sql
insert into account values ('A101','SW-branch',100000);
```

6.

```sql
select * from account;
select * from account where balance>5000;
select * from account where branch_name like 'SW%';
```





## 1.SELECT문

모든 레코드 조회하기
동물 보호소에 들어온 모든 동물의 정보를 ANIMAL_ID순으로 조회하는 SQL문을 작성해주세요.

```null
SELECT * 
FROM ANIMAL_INS
ORDER BY ANIMAL_ID
```

**정렬 : OREBER BY (거꾸로, DESC)**

역순 정렬하기
동물 보호소에 들어온 모든 동물의 이름과 보호 시작일을 조회하는 SQL문을 작성해주세요.

```null
SELECT NAME, DATETIME 
FROM ANIMAL_INS 
ORDER BY ANIMAL_ID DESC
```

아픈 동물 찾기
동물 보호소에 들어온 동물 중 아픈 동물1의 아이디와 이름을 조회하는 SQL 문을 작성해주세요. 이때 결과는 아이디 순으로 조회해주세요.

```null
SELECT ANIMAL_ID, NAME 
FROM ANIMAL_INS 
WHERE INTAKE_CONDITION='Sick'
```

**특정 조건 해당 행!! 찾기 WHERE 조건**

여러 기준으로 정렬하기
동물 보호소에 들어온 모든 동물의 아이디와 이름, 보호 시작일을 이름 순으로 조회하는 SQL문을 작성해주세요. 단, 이름이 같은 동물 중에서는 보호를 나중에 시작한 동물을 먼저 보여줘야 합니다.

```null
SELECT ANIMAL_ID, NAME, DATETIME 
FROM ANIMAL_INS 
ORDER BY NAME ASC, DATETIME DESC
```

상위 n개 레코드
동물 보호소에 가장 먼저 들어온 동물의 이름을 조회하는 SQL 문을 작성해주세요.

```null
SELECT NAME FROM ANIMAL_INS 
ORDER BY DATETIME 
LIMIT 1
```

**상위 몇개만 보이기 LIMIT 몇개**

## MAX, MIN, COUNT, SUM

최댓값 구하기
가장 최근에 들어온 동물은 언제 들어왔는지 조회하는 SQL 문을 작성해주세요.

```null
SELECT MAX(DATETIME)
FROM ANIMAL_INS
```

최솟값 구하기
동물 보호소에 가장 먼저 들어온 동물은 언제 들어왔는지 조회하는 SQL 문을 작성해주세요.

```null
SELECT MIN(DATETIME) 
FROM ANIMAL_INS
```

동물 수 구하기
동물 보호소에 동물이 몇 마리 들어왔는지 조회하는 SQL 문을 작성해주세요.

```null
SELECT COUNT(ANIMAL_ID) count
FROM ANIMAL_INS
```

**COUNT(열명) 결과창 칼럼명!**

중복 제거하기
동물 보호소에 들어온 동물의 이름은 몇 개인지 조회하는 SQL 문을 작성해주세요. 이때 이름이 NULL인 경우는 집계하지 않으며 중복되는 이름은 하나로 칩니다.

```null
SELECT COUNT(A.NAME) count
FROM 
(SELECT NAME FROM ANIMAL_INS GROUP BY NAME) AS A
# 이름별로 그룹화하여 기존 테이블에서 이름 구한 테이블을 A로 상정
WHERE NAME IS NOT NULL # NULL이 아닌 
```

**NULL이 아닌은 행에 의미하므로 WHERE로
WHERE IS NOT NULL
동명 1개 처리 -> 이름별로 테이블 생성**

## GROUP BY

고양이와 개는 몇 마리 있을까
동물 보호소에 들어온 동물 중 고양이와 개가 각각 몇 마리인지 조회하는 SQL문을 작성해주세요. 이때 고양이가 개보다 먼저 조회해주세요.

```null
SELECT ANIMAL_TYPE, COUNT(*) AS COUNT
FROM ANIMAL_INS 
GROUP BY ANIMAL_TYPE
ORDER BY ANIMAL_TYPE
```

**칼럼명 지정
AS 특정 칼럼명

그룹별 개수 구하기
SELECT COUNT(*)
FROM
GROUP BY 그룹**

동명 동물 수 찾기
동물 보호소에 들어온 동물 이름 중 두 번 이상 쓰인 이름과 해당 이름이 쓰인 횟수를 조회하는 SQL문을 작성해주세요. 이때 결과는 이름이 없는 동물은 집계에서 제외하며, 결과는 이름 순으로 조회해주세요.

```null
SELECT NAME,COUNT(*) COUNT 
FROM ANIMAL_INS 
WHERE NAME IS NOT NULL
GROUP BY NAME
HAVING COUNT > 1
ORDER BY NAME
```

GROUP BY 뒤에 조건절 HAVING으로 조건 걸기

입양 시각 구하기(1)
보호소에서는 몇 시에 입양이 가장 활발하게 일어나는지 알아보려 합니다. 09:00부터 19:59까지, 각 시간대별로 입양이 몇 건이나 발생했는지 조회하는 SQL문을 작성해주세요. 이때 결과는 시간대 순으로 정렬해야 합니다.

```null
SELECT HOUR(DATETIME) , COUNT(*) COUNT
FROM ANIMAL_OUTS
WHERE HOUR(DATETIME) >= 9 AND HOUR(DATETIME) < 20
GROUP BY HOUR(DATETIME)
ORDER BY HOUR(DATETIME)
```

시간 : HOUR

⭐︎⭐︎⭐︎⭐︎
입양 시각 구하기(2)
보호소에서는 몇 시에 입양이 가장 활발하게 일어나는지 알아보려 합니다. 0시부터 23시까지, 각 시간대별로 입양이 몇 건이나 발생했는지 조회하는 SQL문을 작성해주세요. 이때 결과는 시간대 순으로 정렬해야 합니다.

-0~23시 모든 HOUR을 출력하기 위해 변수 사용
-MySQL 변수 선언 방법
SET@변수명 = "값";
("=" mysql에서 대입연산자, 비교연산자로 사용됨 set 명령어에서만 대입연산자 인식)
SET@변수명 := "값";
SET을 제외한 다른 쿼미문은 "=" 비교연산자로 인식하기 때문에, SET이 아닌 쿼리문에서는 반드시 대입연산자 ":="사용

- SET으로 HOUR_LIST변수 선언하고,
  +1씩 하며 0~23시 까지 모든 시간에 대한 COUNT 출력

```null
SET @HOUR_LIST = -1;
SELECT 
	# HOUR_LIST 변수 1씩 증가해가며 
    (@HOUR_LIST := @HOUR_LIST+1) AS HOUR,
    # DATERIME 시간이 HOUR_LIST 변수와 같은 행 개수 세기 (COUNTS처리)
    (SELECT COUNT(*) FROM ANIMAL_OUTS WHERE HOUR(DATETIME)=@HOUR_LIST) AS COUNTS
FROM ANIMAL_OUTS
# HOUR_LIST 변수명이 23까지
WHERE @HOUR_LIST < 23
```

## IS NULL

이름이 없는 동물의 아이디
동물 보호소에 들어온 동물 중, 이름이 없는 채로 들어온 동물의 ID를 조회하는 SQL 문을 작성해주세요. 단, ID는 오름차순 정렬되어야 합니다.

```null
SELECT ANIMAL_ID 
FROM ANIMAL_INS 
WHERE NAME IS NULL
```

**결측값(행) 확인
WHERE 열 IS NULL**

이름이 있는 동물의 아이디
동물 보호소에 들어온 동물 중, 이름이 있는 동물의 ID를 조회하는 SQL 문을 작성해주세요. 단, ID는 오름차순 정렬되어야 합니다.

```null
SELECT ANIMAL_ID 
FROM ANIMAL_INS 
WHERE NAME IS NOT NULL
```

NULL 처리하기
입양 게시판에 동물 정보를 게시하려 합니다. 동물의 생물 종, 이름, 성별 및 중성화 여부를 아이디 순으로 조회하는 SQL문을 작성해주세요. 이때 프로그래밍을 모르는 사람들은 NULL이라는 기호를 모르기 때문에, 이름이 없는 동물의 이름은 No name으로 표시해 주세요.

```null
SELECT ANIMAL_TYPE, IFNULL(NAME, "No name") AS NAME, SEX_UPON_INTAKE 
FROM ANIMAL_INS
```

**NULL인 경우 다른 값으로 대체하기
IFNULL(열, "대체할 값")**
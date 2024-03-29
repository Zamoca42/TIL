# 알고리즘

## 2. 시간 복잡도

### 알고리즘의 분석

- 알고리즘의 분석 기준

  1. 정확도 (값이 얼마나 정확한가)
  2. 코드 복잡도 (코드가 인간이 보기에 얼마나 복잡하게 쓰여 있는가 등)
  3. 공간 복잡도 (RAM, 하드디스크 등의 하드웨어를 얼마나 사용하는가)
  4. 시간 복잡도 (주어진 입력자료에 대해 실행시간이 얼마나 긴 가)

    </br>

  ```
  이 넷 모두 중요한 요소이지만 코드 복잡도는 실제 실행 결과에 큰 영향을 끼치지 않고
  공간 복잡도는 기술의 발달로 하드웨어의 비용이 많이 줄어들어 비교적 덜 중요하게 여겨진다.

  따라서 정확도와 시간 복잡도가 주로 알고리즘에서 제일 중요한 요소로 여겨지는데,
  정확도의 경우에는 문제에 따라 완전히 정확한 참값을 구해야 하는 문제가 있고 근삿값을 구해도 충분한 문제도 있는 등 경우에 따라 다르므로 이 챕터에서는 시간 복잡도 위주로 다루도록 하겠다.
  ```

- 시간 복잡도 표기법

  두 양의 정수 $c$와 $n_0$가 존재하여 $n \ge n_0$인 모든 n에서 $|f(𝑛)| \le c|g(𝑛)|$ 를 만족하면,
  f(n) = O(g(𝑛))이라고 쓰고,
  f(𝑛)은 Big-오 of g(𝑛) 또는 줄여서 오 g(𝑛)이다 라고 읽는다.
  이러한 표기법을 빅-오 표기법(notation)이라고 부른다.
  이 때, 일반적으로 g(𝑛)에 들어가는 함수는 1, log 𝑛, 𝑛, 𝑛 log 𝑛, $n^2$, $𝑛^3$, 𝑛! 등이 있다.

  - 예시

    ```
    본수열 𝑠1,𝑠2,𝑠3,...,𝑠n 에서 최댓값을 출력하는 의사코드 예시.

    Input : s, n
    Output : max(수열에서 가장 큰 값)

    def max(s,n) :
        max <- 𝑠1
        for i <- 2 to n
            if 𝑠𝑖 > max then max <- 𝑠𝑖
    return max
    ```

    위와 같은 코드는 O(n)이다

- 문제 : 다음 f를 빅-오 표현법으로 표현하면?

  1. $f(n) = -n^2 $
     - O($n^2$)
  2. $f(n) = 3n $
     - O($n$)
  3. $f(n) = 5^{10} \log n $
     - O($\log n$)
  4. $f(n) = 5n^5 + 3n^4 + 7n^2 + 3n + 1 $
     - O($n^5$)

- 주의!

  - O($n$) 알고리즘이 항상 O($n^2$) 보다 좋다는 보장은 없다.

    - 예를 들어, O($𝑛$)의 시간복잡도가 10000𝑛이고 O($𝑛^2$)은 그냥 $𝑛^2$라면 전자가 항상 좋다고 말할 수는 없다.  
      다만, 𝑛의 값이 충분히 크다면 전자가 훨씬 적은 시간을 필요로 하므로 𝑛이 충분히 크면 전자가 훨씬 좋은 알고리즘이라고 할 수 있다.

    </br>

  ![1280px-Comparison_computational_complexity](https://user-images.githubusercontent.com/96982072/198215188-9ea488dd-d5e3-42ee-88bd-8e2cfdab29f6.png)

- 추가 문제 : 다음 함수들을 빅-오 표기법으로 표기하시오
  1. $f(n) = \frac{1}{n} + 80 $
     - O($1$)
  2. $f(n) = a n + b n \log n $
     - O($n$)
  3. $f(n) = 10000n + n^2 $
     - O($n^2$)

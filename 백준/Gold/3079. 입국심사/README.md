# [Gold V] 입국심사 - 3079 

[문제 링크](https://www.acmicpc.net/problem/3079) 

### 성능 요약

메모리: 2412 KB, 시간: 48 ms

### 분류

이분 탐색, 매개 변수 탐색

### 제출 일자

2025년 2월 26일 14:09:10

### 문제 설명

<p>The Croatian delegation, consisting of M people, is travelling to IOI 2013 in Australia. They are currently waiting in a queue for check-in at the airport. There are N check-in desks open. Some officials work more efficiently than others, so the desks operate at different speeds. At the k-th desk, T<sub>k</sub> seconds are required to finish check-in of a single passenger, and members of our delegation happen to know the exact numbers.</p>

<p>In the beginning, all desks are ready to accept the next passenger, and the delegation members are the only people in the queue. A person can only occupy (start check-in at) an available desk when all people in front of that person in the queue have left the queue (started, not necessarily finished, check-in) already. At that moment, the person can immediately occupy an available desk (if there is one), but can also choose to wait for another (faster) desk to become available. Our delegation members, being computer science geeks, make this decision in such a way that the moment when all of them have finished check-in is as soon as possible. Your task is finding that moment in time.</p>

<p>Let us describe the scenario from the first example below. There are two desks, with processing times of 7 and 10 seconds, respectively. Out of the six people in the delegation, the first two immediately occupy the two desks. At time 7, the first desk is freed, and the third person occupies it. At time 10, the fourth person occupies the second desk. At time 14, the fifth person occupies the first desk. At time 20, the second desk is freed again, but the sixth person decides to wait another second (time 21) for the first desk to become available, and then occupy it. This way, the check-in is completed by time 28. If the sixth person hadn't waited for the faster desk, the check-in would have taken a total of 30 seconds.</p>

### 입력 

 <p>The first line of input contains two positive integers, N (1 ≤ N ≤ 100 000), the number of desks, and M (1 ≤ M ≤ 1 000 000 000), the number of people in the delegation.</p>

<p>Each of the following N lines contains a number Tk from the problem statement (1 ≤ Tk ≤ 10<sup>9</sup>).</p>

### 출력 

 <p>The first and only line of output must contain the required minimum time in seconds.</p>

<p> </p>


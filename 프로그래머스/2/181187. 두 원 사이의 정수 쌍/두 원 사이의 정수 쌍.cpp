#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

// 1사분면만 구한뒤 *4를 진행.
// x * sqrt(2) <= r 인 최소 x를 구하는것이 목표.
long long answer = 0;
long long solution(int r1, int r2) {
    long long sqr1 = (long long)r1 * r1;
    long long sqr2 = (long long)r2 * r2;
    for(int i=1;i<=r2;i++){
        long long tempsize = (long long)i*i;
        int a = ceil(sqrt(sqr1 - tempsize));
        int b = floor(sqrt(sqr2 - tempsize));
        if (r1 < i)
			a = 0;

		answer += (b - a + 1);
    }
    
    answer *= 4 ;
    return answer;
}
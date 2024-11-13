#include <string>
#include <vector>
#include <iostream>

using namespace std;
int b_min = 1;
int b_max = 100000;
long long howmuchtime(int level, vector<int> diffs, vector<int> times){
    long long time = 0;
    long long time_prev =0;
    for(int i=0;i<diffs.size();i++){
        if(i>=2){
            time_prev -= times[i-2];
        }
        if(diffs[i]<=level){
            time += times[i];
        }
        
        else{
            time += (time_prev + times[i])*(diffs[i] - level) + times[i];       
        }
        
        time_prev += times[i];
    }
    return time;
}
void binary_search(long long time, long long limit, int level){
        if(time>limit){
            b_min = level + 1;
        }
        else{
            b_max = level - 1;
        }
}
int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    while(b_min <= b_max){
        long long level = (b_min + b_max)/2;
        long long temp = howmuchtime(level,diffs,times);
        binary_search(temp,limit,level);
    }
    return b_min;
}
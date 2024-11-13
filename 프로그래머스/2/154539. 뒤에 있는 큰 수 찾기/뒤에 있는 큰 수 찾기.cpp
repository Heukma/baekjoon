#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> numbers) {
    int v_size = numbers.size();
    vector<int> answer (v_size, -1);
    deque<int> d;
    d.push_back(numbers[v_size-1]);
    answer[v_size-1] = -1;
    for(int i=2;i<=v_size;i++){
        int num = numbers[v_size-i];
        while(d.size()!=0){
            if(d[0]>num){
                answer[v_size-i] = d[0];
                break;
            }
            else{
                d.pop_front();
            }
        }
        if(d.size()==0){
            answer[v_size-i] = -1;
        }
        d.push_front(num);
    }
    
    return answer;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int answer = -1;
int solution(int k, vector<vector<int>> d) {
    sort(d.begin(),d.end());
    
    do{
        int stress = k;
        int count = 0;
        for(int i=0;i<d.size();i++){
            if(stress >= d[i][0]){
                stress -= d[i][1];
                count ++;
            }
        }
        
        answer = max(answer, count);
    }while(next_permutation(d.begin(),d.end()));
    
    return answer;
}
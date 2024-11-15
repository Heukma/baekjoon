#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
vector <pair<int,int>> vt;
int done[500001] = {};
int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(targets.begin(),targets.end());
    
    for(int i=targets.size()-1;i!=-1;i--){
        if(done[i] == 0){
            answer ++;
            done[i] = 1;
            double temp = targets[i][0] + 0.5;
            int where;
            for(int j=i;j!=-1;j--){
                if(targets[j][1]>temp){
                    where = j;
                }
                else break;
            }
            i = where;
        }
    }
    
    return answer;
}
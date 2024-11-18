#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;
unordered_set<int> uniqueSums;
vector<int> global_e;
vector<int> solve(vector <int> a, int new_, bool greater){
	vector<int> ret;
    if(greater){
        ret.push_back(new_);
        uniqueSums.insert(new_);
    }
    else{
        a.pop_back();
    }
    for(int i=0;i<a.size();i++){
        ret.push_back(a[i]+new_);
        uniqueSums.insert(a[i]+new_);
    }
    return ret;
}
// 7, 9 16 , 1 10 17 , 1 2 11 18, 4 5 6 15 22, 
// -> 11 12 13, 20 21 , 21, 
int solution(vector<int> elements) {
    global_e = elements;
    vector<int> solvev;
    for(int i=0;i<elements.size();i++){
        solvev = solve(solvev, elements[i], true);
    }
    solvev.pop_back();
    for(int i=0;i<elements.size() - 2;i++){
        solvev = solve(solvev, elements[i], false);
    }
    return uniqueSums.size();
}


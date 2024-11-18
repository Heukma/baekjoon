#include <string>
#include <vector>
#include <iostream>
using namespace std;
int mm[1000000] = {};
int answer = 0;
vector<int> global_e;
vector <int> solve(vector <int> a, int new_){
    vector<int> ret;
    ret.push_back(new_);
    if(mm[new_] == 0){
        answer++;
        //cout << new_ << '\n';
        mm[new_] = 1;
    }
    for(int i=0;i<a.size();i++){
        ret.push_back(a[i]+new_);
        if(mm[a[i]+new_] == 0){
            answer++;
            mm[a[i]+new_] = 1;
            //cout << a[i]+new_ << '\n';
        }
    }
    return ret;
}

vector <int> solve2(vector <int> a, int new_){
    vector<int> ret;
    a.pop_back();
    for(int i=0;i<a.size();i++){
        ret.push_back(a[i]+new_);
        if(mm[a[i]+new_] == 0){
            answer++;
            mm[a[i]+new_] = 1;
            //cout << a[i]+new_ << '\n';
        }
    }
    return ret;
}
// 7, 9 16 , 1 10 17 , 1 2 11 18, 4 5 6 15 22, 
// -> 11 12 13, 20 21 , 21, 
int solution(vector<int> elements) {
    global_e = elements;
    vector<int> solvev;
    for(int i=0;i<elements.size();i++){
        solvev = solve(solvev, elements[i]);
    }
    solvev.pop_back();
    //solvev.pop_back();
    for(int i=0;i<elements.size() - 2;i++){
        solvev = solve2(solvev, elements[i]);
    }
    return answer;
}
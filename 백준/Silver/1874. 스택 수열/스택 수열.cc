#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int N;
deque <int> d;
deque <int> rd;
vector <int> v;
vector <int>::iterator iter;
void pop(){
    // cout << "-\n";
    v.push_back(1);
}
void push(){
    // cout << "-\n";
    v.push_back(-1);
}
int main(){
    cin >> N;
    int index = 1;
    int flag = true;
    for(int i=0;i<N;i++){
        int temp;
        cin >> temp;
        d.push_back(temp);
    }
    while(d.size()!=0){
        int temp = d[0];
        d.pop_front();
        if(index < temp){
            while(index != temp ){
                rd.push_back(index);
                push();
                index ++;
            }
        }
        if(index > temp){
            if(rd.back() != temp){
                flag = false;
            }
            else{
                pop();
                rd.pop_back();
            }
        }
        else if(index == temp){
            push();
            pop();
            index++;
        }
        else{
            flag = false;
        }
    }

    if(flag){
        for(iter = v.begin(); iter!=v.end();iter++){
            if(*iter == -1){
                cout << "+\n";
            }
            else{
                cout << "-\n";
            }
        }
    }
    else{
        cout << "NO";
    }
}
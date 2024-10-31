#include <iostream>
#include <string>
#include <deque>

using namespace std;
string t;
char sentence[101] = {};
int braket = 0;
deque <int> d; 
int main(){
    
    while(1){
        bool flag = false;
        getline(cin, t);
        d.clear();
        for(int i=0;;i++){
            sentence[i] = t[i];
            if(sentence[i] == '.'){
                break;
            }
            
            if(sentence[i] == '['){
                d.push_back(1);
            }
            if(sentence[i] == ']'){
                if(d.empty()){
                    flag = true;
                    break;
                }
                else if(1 == d.back()){
                    d.pop_back();
                }
                else{
                    flag = true;
                    break;
                }
            }
            if(sentence[i] == '('){
                d.push_back(2);
            }
            if(sentence[i] == ')'){
                if(d.empty()){
                    flag = true;
                    break;
                }

                else if(2 == d.back()){
                    d.pop_back();
                }

                else{
                    flag = true;
                    break;
                }
            }
        }
        if(sentence[0] == '.') break;
        if(d.size()!=0){
            flag = true;
        }
        if(flag){
            cout << "no\n";
        }
        else{
            cout << "yes\n";
        }
    }
    
}
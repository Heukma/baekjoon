#include <iostream>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

int ans = (1e9+10) * -1;
string input;
deque <int> num,d;
deque <int> bnum,bd;
deque <pair <int, string> > st;
int claculate(string t){
    num.clear();
    d.clear();
    bnum.clear();
    bd.clear();
    string temp;
    int flag = false;
    for(int i=0;i<t.size();i++){
        if(t[i] == '+'){
            if(!flag){
                if(temp.size()!=0){
                    num.push_back(stoi(temp));
                    temp.clear();
                }
                d.push_back(1);
            }
            else{
                bnum.push_back(stoi(temp));
                temp.clear();
                bd.push_back(1);
            }
        }
        else if(t[i] == '-'){
            if(!flag){
                if(temp.size()!=0){
                    num.push_back(stoi(temp));
                    temp.clear();
                }
                d.push_back(-1);
            }
            else{
                bnum.push_back(stoi(temp));
                temp.clear();
                bd.push_back(-1);
            }
        }
        else if(t[i] == '*'){
            if(!flag){
                if(temp.size()!=0){
                    num.push_back(stoi(temp));
                    temp.clear();
                }
                d.push_back(2);
            }
            else{
                bnum.push_back(stoi(temp));
                temp.clear();
                bd.push_back(2);
            }
        }
        else if(t[i] == '('){
            flag = true;
        }
        else if(t[i] == ')'){
            if(temp.size()!=0) {
                bnum.push_back(stoi(temp));
                temp.clear();
            }
            int cur = bnum[0];
            for(int i=0;i<bnum.size()-1;i++){
                int t = bnum[i+1];
                if(bd[i]== 1){
                    cur += t;
                }
                else if(bd[i] == -1){
                    cur -= t;
                }
                else{
                    cur *= t;
                }
            }
            num.push_back(cur);
            bd.clear();
            bnum.clear();
            flag = false;
        }
        else{
            temp += t[i];
        }
    }
    if(temp.size()>1) {
        num.push_back(stoi(temp));
    }
    int cur = num[0];
    // cout << cur <<'\n';
    for(int i=0;i<num.size()-1;i++){
        // cout << num[i+1] <<'\n';
        int t = num[i+1];
        if(d[i]== 1){
            cur += t;
        }
        else if(d[i] == -1){
            cur -= t;
        }
        else{
            cur *= t;
        }
    }
    return cur;
}
void make_(int index){
    if(index > input.size()){
        return ;
    }
    else{
        int size = st.size();
        for(int i=0;i<size;i++){
            int flag = st[0].first;
            string t = st[0].second;
            st.pop_front();
            if(index%2 != 0){
                st.push_back(make_pair(flag,t+input[index]));
            }
            else{
                if(flag){
                    // ( 가 존재함.
                    st.push_back(make_pair(0,t+input[index]+')'));
                    // st.push_back(make_pair(1,t+input[index]));
                }
                else{
                    // ( 가 존재하지 않음.
                    st.push_back(make_pair(1,t+'('+input[index]));
                    st.push_back(make_pair(0,t+input[index]));
                }
            }
            
        }
    }
    make_(index+1);
}
int main(){
    int trash;
    cin >> trash;
    cin >> input;
    //초기값 설정
    string temp = "(";
    temp += input[0];
    st.push_back(make_pair(1,temp));
    temp = input[0];
    st.push_back(make_pair(0,temp));
    make_(1);
    for(int i=0;i<st.size();i++){
        if(st[i].first) continue;
        // cout << st[i].second << '\n';
        ans = max(claculate(st[i].second),ans);
    }
    // ans = max(claculate(input),ans);
    cout << ans;
}
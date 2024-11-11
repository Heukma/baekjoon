#include <string>
#include <vector>
#include <iostream>

using namespace std;
int video_len_int, pos_int, op_start_int, op_end_int;
void make_int(string video_len, string pos, string op_start, string op_end){
    video_len_int = (video_len[0] - '0') * 1000;
    video_len_int += (video_len[1] - '0') * 100;
    video_len_int += (video_len[3] - '0') * 10;
    video_len_int += (video_len[4] - '0') ;
    
    pos_int = (pos[0] - '0') * 1000;
    pos_int += (pos[1] - '0') * 100;
    pos_int += (pos[3] - '0') * 10;
    pos_int += (pos[4] - '0') ;
    
    op_start_int = (op_start[0] - '0') * 1000;
    op_start_int += (op_start[1] - '0') * 100;
    op_start_int += (op_start[3] - '0') * 10;
    op_start_int += (op_start[4] - '0') ;
    
    op_end_int = (op_end[0] - '0') * 1000;
    op_end_int += (op_end[1] - '0') * 100;
    op_end_int += (op_end[3] - '0') * 10;
    op_end_int += (op_end[4] - '0') ;
}
bool ismiddle(){
    return pos_int >= op_start_int && pos_int<= op_end_int;
}
string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    make_int(video_len, pos, op_start,op_end);
    for(int i=0;i<commands.size();i++){
        if(ismiddle()){
            pos_int = op_end_int;
        }
        if(commands[i] == "next"){
            if(pos_int%100 >=50){
                pos_int += 50;
            }
            else{
                pos_int += 10;
            }
            if(pos_int > video_len_int){
                pos_int = video_len_int;
            }
        }
        else{
            if(pos_int%100 < 10){
                pos_int -= 50;                
            }
            else{
                pos_int -= 10;
            }
            if(pos_int < 0){
                pos_int = 0;
            }
        }
    }
    if(ismiddle()){
        pos_int = op_end_int;
    }
    string answer = "";
    char buffer[6];  // "HH:MM" 형식을 저장할 수 있는 크기
    sprintf(buffer, "%02d:%02d", pos_int / 100, pos_int % 100);
    answer += buffer;
    return answer;
}
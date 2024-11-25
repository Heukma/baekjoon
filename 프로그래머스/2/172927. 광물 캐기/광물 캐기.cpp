#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <deque>
#include <algorithm>

using namespace std;
deque <int> d;
int ans = 0;
int solution(vector<int> picks, vector<string> minerals) {
    int howmuch = 0;
    int dia = 0;
    int iron = 0;
    int stone = 0;
    dia = picks[0];
    iron = picks[1];
    stone = picks[2];
    howmuch = dia+iron+stone;
    
    int temp = minerals.size();
    int mineral_size = min(howmuch * 5 , temp);
    for(int i=0;i<mineral_size;i+=5){
        int count = 0;
        for(int j=0;j<5;j++){
            if(i+j >= mineral_size) break;
            if(minerals[i+j] == "diamond"){
                count +=100;
            }
            else if(minerals[i+j] == "iron"){
                count +=10;
            }
            else if(minerals[i+j] == "stone"){
                count +=1;
            }
        }
        d.push_back(count);
    }
    sort(d.begin(),d.end(),greater<>());
    while(d.size()!=0){
        int temp = d[0];
        d.pop_front();
        if(dia){
            dia --;
            int m_dia = temp /100;
            temp %= 100;
            int m_iron = temp /10;
            temp %= 10;
            int m_stone = temp;
            ans += m_dia + m_iron + m_stone;
        }
        else if(iron){
            iron --;
            int m_dia = temp /100;
            temp %= 100;
            int m_iron = temp /10;
            temp %= 10;
            int m_stone = temp;
            ans += m_dia * 5 + m_iron + m_stone;
        }
        else if(stone){
            stone --;
            int m_dia = temp /100;
            temp %= 100;
            int m_iron = temp /10;
            temp %= 10;
            int m_stone = temp;
            ans += m_dia * 25 + m_iron * 5 + m_stone;
        }
    }
    return ans;
}
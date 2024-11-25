#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 0;
int maxhealth;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int lasttime = attacks[attacks.size()-1][0];
    maxhealth = health ;
    int contin = 0;
    int attack_count = 0;
    for(int i=1;i<=lasttime;i++){
        if(attacks[attack_count][0] == i){
            contin = 0;
            health -= attacks[attack_count][1];
            if(health <=0) answer = -1;
            attack_count ++;
        }
        else{
            contin ++;
            health = min(maxhealth,health + bandage[1]);
            if(contin == bandage[0]){
                contin = 0;
                health = min(maxhealth,health + bandage[2]);
                
            }
        }
    }
    if(answer == -1) return answer;
    else {
        return health;
    }
}
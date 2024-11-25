#include <string>
#include <vector>
#include <iostream>
using namespace std;
int ans = 0;
bool isvalid(int a ,int b, int ra ,int rb){
    if(a>=ra && b >= rb){
        return false;
    }
    else if(a>=rb && b >=ra){
        return false;
    }
    return true;
}
int solution(vector<int> wallet, vector<int> bill) {
    int wala = wallet[0];
    int walb = wallet[1];
    
    int billa = bill[0];
    int billb = bill[1];
    //cout << isvalid(wala,walb,billa,billb) << '\n';
    while(isvalid(wala,walb,billa,billb)){
        ans ++;
        if(billa > billb){
            billa /=2;
        }
        else{
            billb/=2;
        }
    }
    return ans;
}
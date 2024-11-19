#include <iostream>
#include <cmath>

using namespace std;
long long ggg(long long a){
    if(a<=0) return 0;
    long long ret=0;
    double temp;
    for(int i=1;i!=a;i++){
        temp = pow(a,2)-pow(i,2);
        temp = sqrt(temp);
        ret += floor(temp);        
    }
    return ret;
}
int main(){
    long long awn=0;
    long long boundary=0;
    long long w,h,l;
    cin >> w >> h >>l;
    l>w ? (boundary+=l-w):boundary=0;
    l>h ? (boundary+=l-h):boundary+=0;
    boundary+= l*2;

    awn += ggg(l);
    awn *=3;
    awn += ggg(l-w);
    awn += ggg(l-h);
    if(l>w+h){
        for(long long i=w+1;i<l-h;i++){
        awn -= min((long long)sqrt((l-w)*(l-w) - (i-w)*(i-w)) - h, (long long)sqrt((l-h)*(l-h) - i*i));
        }
        cout<< awn+boundary;
    }
    else{
        cout<< awn+boundary;
    }
    return 0;
}
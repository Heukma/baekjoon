#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;
int N , M;
int seset[1000001] = {};
int get_parent(int a){
    if(seset[a] == a){
        return a;
    }
    else{
        return seset[a] = get_parent(seset[a]);
    }
}
void merge_set(int a, int b){
    int parent_a = get_parent(a);
    int parent_b = get_parent(b);

    if(parent_a < parent_b) seset[parent_b] = parent_a;
	else seset[parent_a] = parent_b;
}
bool same_parent(int a, int b) {
    int parent_a = get_parent(a);
    int parent_b = get_parent(b);
			
	if(parent_a == parent_b) return true;
    else return false;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i=0;i<=1000000;i++){
        seset[i] = i;
    }
    for(int i=0;i<M;i++){
        int  t;
        cin >> t;
        int a, b;
        cin >> a >> b;
        if(t == 1){
            if(same_parent(a,b)) cout << "yes\n";
            else cout << "no\n";
        }
        else if(t == 0){
            merge_set(a,b);
        }
    }
    return 0;
}
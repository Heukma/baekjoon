#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	int index;
	int hight;
}mount;
int main() {
	int how ;
	scanf("%d",&how);
	int* awn= (int*)malloc(sizeof(int)*(how+1));
	for(int i =0;i<how;i++){
		scanf("%d",&awn[i]);
	}
	int temp =0;
	int index = 0;
	int* print= (int*)malloc(sizeof(int)*(how+1));
	mount* stack = (mount*)malloc(sizeof(mount)*(how+1));
	stack[0].hight =awn[0];
	stack[0].index =0;
	awn[how]= 100000000;

	for(int i = 1;i<how+1;i++){
	    while(1){
        if(index == -1) break;
		if(awn[i]>stack[index].hight){
			//pop 시키고
			print[stack[index].index]=awn[i];
			index--;
		}
	    else break;
	    }
        index++;
        stack[index].index = i;
        stack[index].hight = awn[i];
		}

	for(int i =0;i<how;i++){
        if(print[i]== 100000000) printf("-1 ");
    else
		printf("%d ",print[i]);
	}
	return 0;
}

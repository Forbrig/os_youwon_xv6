
#include "types.h"      //maybe needed to use some types of variables
#include "user.h"       //functios like printf and syscalls

#define STDOUT 1        //following the standard nomenclature for xv6 output
#define CHILDS 30
#define PAIN 112345678

void nopainnogain(){
    int i=PAIN;
    while(i--){}
    i=PAIN;
    while(i--){}
}

int main(){
    int pid;
    int i;
    for (i=0;i<CHILDS;i++){
        if(i<(CHILDS/3)){
            pid=fork(0);
        }else if(i>=(CHILDS/3) &&  i<(2*(CHILDS/3))    ){
            pid=fork(4);
        }else{
            pid=fork(64);
        }
        
        
        if(pid == 0){
            nopainnogain();
            exit();
        }
        
    }
    //while (wait() != -1);
    while(1){
        pid=wait();
        if(pid<0)break;
        printf(STDOUT,"Child %d finished\n",pid );
        
    }
    
    
    exit();
}

#include<iostream>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

#define N 10

int main(){
    int status;
    int i;
    pid_t pid;
    //创建N个子进程
    for(int i = 0; i < N; i++){
        if((pid = fork()) == 0){
            exit(100 + i);
        }
    }

    while((pid = waitpid(-1, &status, 0)) > 0){
        if(WIFEXITED(status)){
            std::cout << "child " << pid << " terminated exit with status " << WEXITSTATUS(status) << std::endl;
        }else{
            std::cout << "child " << pid << " terminated abnomally" << std::endl;
        }
    }

    if(errno != ECHILD){
        std::cerr << "waitpid error";
    }
    
    return 0;
}
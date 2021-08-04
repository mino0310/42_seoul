#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
// // extern char **environ;

// // int main(void){
// //     char **env;
// //     env = environ;

// //     //environ의 주소를 임시 포인터인 env에 저장한다.     
// //     while(*env){
// //         //env의 주소를 증가시키며 환경 변수를 출력한다.
// //         printf("%s\n", *env);
// //         printf("zzz\n");
// //         env++;
// //     }

// //     return 0;
// // }

// int main(void){
//     int a;

//     //파이프로 연결된 ps -ef | grep han > han.txt 명령을 실행하도록 
//     //system 함수를 호출한다. 
//     //인자로 전달된 명령은 현재 실행 중인 프로세스들에서 'han'을 포함한    
//     //내용을 찾아 han.txt파일에 저장한다.
//     a = system("ps -ef | grep han > han.txt");
//     printf("return value: %d\n", a);

//     return 0;

// }

// int main(void){
//     pid_t pid;

//     switch(pid = fork()){
//         case -1 : /* fork failed */
//             perror("fork");
//             exit(1);
//             break;

//         case 0 : /* child process  */

//         printf("child process - my PID : %d, may parent's PID: %d\n", (int)getpid(), (int)getppid());
//             break;

//         default : /* parent process  */

//         printf("parent process - my PID: %d, My parent's PID: %d, my child's PID:%d\n", (int)getpid(), (int)getppid(), (int)pid);

//         break;
//     }

//     printf("end of fork\n");

//     return 0;
// }

// #include <unistd.h>
// #include <stdlib.h>
// #include <stdio.h>

// int main(void){
//     printf("-->Before exec function\n");

//     if(execlp("ls", "ls", "-a", (char *)NULL) == -1) {
//         perror("execlp");
//         exit(1);

//     }

//     printf("--> After exec function \n");
//     return 0;

// }
// #include <signal.h>si

/*
int main(void)
{
    int a;
    char c;
    a = '4';
    c = '4';
    write(1, &"12345"[2], 1);
    write(1, "\n", 1);
    // write(1, &'1', 1);
    // write(1, &"1"[0], 1);
    // write(1, &a, 1);
    // write(1, (void *)"12345"[3], 1);
    write(1, &"5", 1);
    write(1, &'5', 1);
    return 0;
}*/


int main(void)
{
    int i = 3;
    
    printf("%d", 3 & 0x01);
	return 0;
}

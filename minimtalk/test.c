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
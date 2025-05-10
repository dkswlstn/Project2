#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;
struct tm *time1, *time2;

char *file1 = "text1";
char *file2 = "text2";

void filestat1();
void filestat2();
void filetime1();
void filetime2();
void sizecmp();
void blockcmp();
void datecmp();
void timecmp();

int main(){
    filestat1();
    filestat2();
    filetime1();
    filetime2();
    sizecmp();
    blockcmp();
    datecmp();
    timecmp();
}

//파일 1의 정보를 가져오는 함수 작성
void filestat1(){
    //stat() 함수로 첫번째 파일의 메타데이터를 가져오기
    if(stat(file1, &stat1) == -1) {
        perror("Error reading text1");
        return;
    }
}

//파일 2의 정보를 가져오는 함수 작성
void filestat2(){
    //stat() 함수로 두번째 파일의 메타데이터 가져오기
    if(stat(file2, &stat2) == -1) {
        perror("Error reading text2");
        return;
    }
}

//파일 1의 시간 정보를 가져오는 함수 작성
void filetime1(){
    time1 = localtime(&stat1.st_mtime);
}

//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(){
    time2 = localtime(&stat2.st_mtime);
}

void sizecmp(){
    printf("size compare\n");
    if (stat1.st_size > stat2.st_size){
        printf("%s is bigger\n", file1);
    }
    else if (stat1.st_size < stat2.st_size) {
        printf("%s is bigger\n", file2);
    }
    else {
        printf("sizes are equal\n");
    }
    printf("\n");
}


void blockcmp(){
    printf("block compare\n");
    if (stat1.st_blocks > stat2.st_blocks){
        printf("%s is bigger\n", file1);
    }
    else if (stat1.st_blocks < stat2.st_blocks) {
        printf("%s is bigger\n", file2);
    }
    else{
        printf("sizes are equal\n");
    }
    printf("\n");
}


void datecmp(){
    printf("date compare\n");
    if ((time1->tm_year < time2->tm_year) || (time1->tm_year == time2->tm_year && time1->tm_mon < time2->tm_mon) || (time1->tm_year == time2->tm_year && time1->tm_mon == time2->tm_mon && time1->tm_mday < time2->tm_mday)) {
        printf("%s is early\n", file1);
    }
    else if ((time1->tm_year > time2->tm_year) || (time1->tm_year == time2->tm_year && time1->tm_mon > time2->tm_mon) || (time1->tm_year == time2->tm_year && time1->tm_mon == time2->tm_mon && time1->tm_mday > time2->tm_mday)){
        printf("%s is early\n", file2);
    }
    else {
        printf("same time\n");
    }
    printf("\n");
}


void timecmp(){
    printf("time compare\n");
    if (stat1.st_mtime < stat2.st_mtime) {
        printf("%s is early\n", file1);
    }
    else if (stat1.st_mtime > stat2.st_mtime) {
        printf("%s is early\n", file2);
    }
    else {
        printf("same time\n");
    }
    printf("\n");
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER_SIZE 20
#define NUM_X 5

#if 1
void status_print(char * output){
    puts("Memory status");
    printf("[[ %s ]]\n", output);
}

int FIRST_FIT_ALLOCATION(char* memory_test_input, char data, char data_size){
    //제대로 할당되면 인덱스번호를 출력 그렇지않으면  -1을 출력
    for(int i = 0; i < data_size; i++)
    {
      int val  = 0;
      val = rand()%BUFFER_SIZE; //random 값 할당
      if(memory_test_input[val] == 'X') //해당 인덱스에 X가 있다면 ?
      {
        printf("-1\n"); //이미 값이 있으므로 -1 출력
      }
      else //비어 있는 값이라면
      {
        memory_test_input[val] = 'X'; //해당 인덱스에 X 문자 삽입
        printf("fit index : %d\n",val); //인덱스 번호 출력
      }
    }
    status_print(memory_test_input); //메모리 상태 출력
    return 0;
}

int FIRST_FIT_FREE(char* memory_test_input, char data_index, char data_size){
    for(int i = 0; i < data_size; i++)
    {
      if(memory_test_input[data_index] == 'X') //해당 인덱스값이 X기호라면
      {
        memory_test_input[data_index] = ' '; //공백으로 할당
        printf("free index : %d\n",data_index); //인덱스 번호 출력
      }
      else //해당 인덱스에 X기호가 없다면 -> 엉뚱한 곳 소멸한 것임
      {
        printf("-1\n"); //-1출력
      }
      data_index++; //인덱스++해서 메모리 배열의 인덱스 증가시켜줌
    }
    status_print(memory_test_input);//마찬가지로 현재 상태 출력 함수 호출
    return 0;
}

int BEST_FIT_ALLOCATION(char* memory_test_input, char data, char data_size){

    return 0;
}

int BEST_FIT_FREE(char* memory_test_input, char data_index, char data_size){

    return 0;
}

int main()
{
    //definition
    srand (time(NULL));
    char memory_test[BUFFER_SIZE];
    int i;

    //initialization
    for (i=0;i<BUFFER_SIZE;i++){
        memory_test[i] = ' ';
    }
    memory_test[BUFFER_SIZE-1]='\0';

    //print#1
    status_print(memory_test);

    //random memory setting
    for(i=0;i<NUM_X;i++){
        memory_test[rand()%BUFFER_SIZE] = 'X';
    }

    //print#2
    status_print(memory_test);

    FIRST_FIT_ALLOCATION(memory_test, 'A', 2);
    FIRST_FIT_ALLOCATION(memory_test, 'B', 3);
    FIRST_FIT_ALLOCATION(memory_test, 'C', 4);

    FIRST_FIT_FREE(memory_test, rand()%BUFFER_SIZE, 2);
    FIRST_FIT_FREE(memory_test, rand()%BUFFER_SIZE, 3);
    FIRST_FIT_FREE(memory_test, rand()%BUFFER_SIZE, 4);

    return 0;
}
#endif // 0

#if 0
char* ReadUserName()
{
  char *name = (char *)malloc(sizeof(char)*50);
  printf("What's your name? : ");
  gets(name);
  return name;
}
int main (void)
{
  char* name1;
  char* name2;
  name1 = ReadUserName();
  printf("name1 : %s\n", name1);
  name2 = ReadUserName();
  printf("name2 : %s \n", name2);

  printf("against name1: %s\n",name1);
  printf("against name2: %s\n",name2);
  free(name1);
  free(name2);
  return 0;
}
#endif // 0

#if 0
int main (void)
{
    char *string = (char*)malloc(sizeof(char)*10);
    printf("input string : ");
    fgets(string, 10, stdin); //입력받는 크기를 정해준다.
    printf("%s\n", string);
    free(string);
    printf("%s\n", string); //문자열 찍으면 쓰레기값 나옴 free했기 때문
    return 0;
}
#endif // 1

#if 0
int main(void)
{
    char *string = (char *)malloc(sizeof(char)*5);
    printf("input string : ");
    fgets(string, 6, stdin);  //fgets로써 입력받는 크기를 정해준다. null 포함
    printf("%s\n", string);
    string = realloc(string, 10); //크기를 재설정했을 때
    printf("%s\n", string); //문자열 정보가 남아 있는지 확인 -> 남아 있음
    free(string);
    return 0;
}
#endif // 1

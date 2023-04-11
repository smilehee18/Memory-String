#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER_SIZE 20
#define NUM_X 5

#if 0
void status_print(char * output){
    puts("Memory status");
    printf("[[ %s ]]\n", output);
}

int FIRST_FIT_ALLOCATION(char* memory_test_input, char data, char data_size){
    //����� �Ҵ�Ǹ� �ε�����ȣ�� ��� �׷���������  -1�� ���
    for(int i = 0; i < data_size; i++)
    {
      int val  = 0;
      val = rand()%BUFFER_SIZE; //random �� �Ҵ�
      if(memory_test_input[val] == 'X') //�ش� �ε����� X�� �ִٸ� ?
      {
        printf("-1\n"); //�̹� ���� �����Ƿ� -1 ���
      }
      else //��� �ִ� ���̶��
      {
        memory_test_input[val] = 'X'; //�ش� �ε����� X ���� ����
        printf("fit index : %d\n",val); //�ε��� ��ȣ ���
      }
    }
    status_print(memory_test_input); //�޸� ���� ���
    return 0;
}

int FIRST_FIT_FREE(char* memory_test_input, char data_index, char data_size){
    for(int i = 0; i < data_size; i++)
    {
      if(memory_test_input[data_index] == 'X') //�ش� �ε������� X��ȣ���
      {
        memory_test_input[data_index] = ' '; //�������� �Ҵ�
        printf("free index : %d\n",data_index); //�ε��� ��ȣ ���
      }
      else //�ش� �ε����� X��ȣ�� ���ٸ� -> ������ �� �Ҹ��� ����
      {
        printf("-1\n"); //-1���
      }
      data_index++; //�ε���++�ؼ� �޸� �迭�� �ε��� ����������
    }
    status_print(memory_test_input);//���������� ���� ���� ��� �Լ� ȣ��
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
    fgets(string, 10, stdin); //�Է¹޴� ũ�⸦ �����ش�.
    printf("%s\n", string);
    free(string);
    printf("%s\n", string); //���ڿ� ������ �����Ⱚ ���� free�߱� ����
    return 0;
}
#endif // 1

#if 0
int main(void)
{
    char *string = (char *)malloc(sizeof(char)*5);
    printf("input string : ");
    fgets(string, 6, stdin);  //fgets�ν� �Է¹޴� ũ�⸦ �����ش�. null ����
    printf("%s\n", string);
    string = realloc(string, 10); //ũ�⸦ �缳������ ��
    printf("%s\n", string); //���ڿ� ������ ���� �ִ��� Ȯ�� -> ���� ����
    return 0;
}
#endif // 1

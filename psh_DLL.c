/****** doubly Linked List ******/

#include <stdio.h>
#include <stdlib.h>

typedef struct _double_node
{
  int key;
  struct _double_node *prev;
  struct _double_node *next;
}double_node;

double_node *head, *tail;

void init_dlist(void)
{
  head = (double_node*)malloc(sizeof(double_node));
  tail = (double_node*)malloc(sizeof(double_node));
  head->next = tail;
  head->prev = head;
  tail->next = tail;
  tail->prev = head;
}

/*key 값이 k인 노드를 찾아서 ptr 반환*/
double_node *find_double_node(int k)
{
   double_node *p = head->next;
   while(p!=tail)
   {
      if(p->key == k)
      {
        break;
      }
      p = p->next;
   }
   return p; //tail을 리턴하거나 ptr을 리턴함
}

/*키값이 k인 노드를 리스트에서 삭제*/
int delete_double_node(int k)
{
   double_node *s;
   s = find_double_node(k);
   if(s == tail || s == head) //key값을 찾지 못했다면,
       return 0;
   //s는 double_node ptr형태
   /*remove the double_node s from the list*/
   else
   {
      s->prev->next = s->next;
      s->next->prev = s->prev;
      free(s); return 1;
   }
}

/*t전에 k값을 가진 노드를 삽입한다*/
double_node *insert_double_node(int k, int t)
{
   double_node *s;
   double_node *i = NULL;   //노드 i를 삽입한다
   i = (double_node*)malloc(sizeof(double_node));
   s = find_double_node(t); //키값이 t인 노드를 찾아서 ptr 반환
   //i노드가 s노드 전에 삽입되어야 함
   i->key = k;
   i->next = s;
   i->prev = s->prev;
   s->prev->next = i;
   s->prev = i;
   return i;
}

/*노드를 크기순으로 정렬하여 k를 삽입해 주세요*/
double_node *Insert_double_node_in_order_of_size(int k)
{
    double_node *s = NULL;
    double_node *i = NULL;
    i = (double_node*)malloc(sizeof(double_node));
    if(head->next!=tail) //head, tail, 그리고 노드 1개이상일 때
    {
       s = head->next;
       while(s!=tail) //반복문을 돌면서 i 이전 노드 s를 찾는다 -> 그리고 i와의 관계를 고려해서 연결함.
       {
         if(s->next->key >=k && s->key <=k &&s->next!=tail) //k값이 2개 노드 사이에 있을 때
         {
             if(s->next->next == tail) //tail이전 값이 수정 또는 삭제되었을 때를 방지
             {
                tail->prev->prev = i;  //이렇게 해야 tail이전 값과 정상적으로 연결됨
             }
             i->key = k;
             i->prev = s;
             i->next = s->next;
             s->next = i;
             s->next->prev = i;
             //printf("연결 :%d\n",i->key); //연결 됨 10.
             break;
         }
         else if(s->key >= k && s == head->next) //k가 가장 작은 키값일때
         {
            //printf("small");
            i -> key = k;
            i -> prev = head;
            i -> next = head->next;
            head->next->prev = i;
            head->next = i;
            break;
         }
         else if(s->key <=k && s->next == tail) //s->key값이 k보다 모두 작을 때
         {
            //printf("big");
            i -> key = k;
            i -> prev = tail->prev;
            i -> next = tail;
            tail->prev->next = i;
            tail->prev = i;
            break;
         }
         s = s->next;
       }
     }
    else if(head->next == tail) //노드가 아무것도 없을 때(head tail만 있)
    {
       i->key = k;
       i->next = tail;
       i->prev = head;
       tail->prev = i;
       head->next = i;
       head->next->next = tail;
       tail->prev->prev = head;
    }
    return i;
}

//매개변수 포인터에 해당하는 노드를 지워주세요.
int delete_double_node_ptr(double_node *p)
{
   if(p == head || p == tail) //head거나 tail이면 안되므로 0반환
      return 0;
    p->prev->next = p->next;
    p->next->prev = p->prev;
   free(p);
   return 1;
}

//노드 t값 전에 k값을 가진 노드를 삽입해주세요.
double_node *insert_double_node_ptr(int k, double_node *t)
{
  double_node *i = (double_node*)malloc(sizeof(double_node));
  i->key = k;
  i->prev = t->prev;
  i->next = t;
  t->prev->next = i;
  t->prev = i;
  return i;
}

//double node를 모두 출력해주세요.
void print_all(double_node *p)
{
  while(p!=tail)
  {
    printf("%d    ",p->key);
    p = p->next;
  }
  printf("\n");
}

//모든 노드들을 삭제해주세요.
void delete_all_double_nodes(void)
{
  double_node *p = head->next;
  double_node *q = NULL; //임시 포인터
  for(; p!=tail; p=q) //반복문 돌 때마다 p에 임시로 저장한 p->next값 불러옴
  {
      q = p->next; //p->next값을 q에 임시 저장
      free(p);     //p가 가리키던 메모리 소멸
  }
  head->next = tail; //head와 tail을 서로 이어주어 초기화 시킴
  tail->prev = head;
}

int main(void)
{
  //printf("start!\n");
  double_node *t;
  init_dlist();

  Insert_double_node_in_order_of_size(10);
  Insert_double_node_in_order_of_size(5);
  Insert_double_node_in_order_of_size(8);
  Insert_double_node_in_order_of_size(3);
  Insert_double_node_in_order_of_size(1);
  Insert_double_node_in_order_of_size(7);
  //Insert_double_node_in_order_of_size(12); //12 삽입해도 정상적으로 출력됨
  Insert_double_node_in_order_of_size(8);

  printf("\n  Initial Linked list is\n  ");
  print_all(head->next);

  printf("\n  Finding 4 is %ssuccessful",find_double_node(4) == tail? "un" : "");

  t = find_double_node(5);
  printf("\n  Finding 5 is %ssuccessful", t == tail ? "un" : "");

  printf("\n  Inserting 7 before 5 \n  ");
  insert_double_node_ptr(7, t);
  print_all(head->next);

  t = find_double_node(3);
  printf("\n  Deleting 3 \n  ");
  delete_double_node_ptr(t);
  print_all(head->next);

  printf("\n  Inserting node 2 before 10\n  ");
  insert_double_node(2, 10);
  print_all(head->next);

  printf("\n  Deleting node 2\n  ");
  if(!delete_double_node(2))
  {
    printf("\n  deleting 2 is unsuccessful");
  }
  print_all(head->next);

  printf("\n  Deleting node 1\n  ");
  delete_double_node(1);
  print_all(head->next);

  printf("\n  Inserting 15 at first\n  ");
  insert_double_node_ptr(15, head->next);
  print_all(head->next);

  printf("\n  Deleting all node");
  delete_all_double_nodes();
  print_all(head->next);

  return 0;
}


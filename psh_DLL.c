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

/*key ���� k�� ��带 ã�Ƽ� ptr ��ȯ*/
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
   return p; //tail�� �����ϰų� ptr�� ������
}

/*Ű���� k�� ��带 ����Ʈ���� ����*/
int delete_double_node(int k)
{
   double_node *s;
   s = find_double_node(k);
   if(s == tail || s == head) //key���� ã�� ���ߴٸ�,
       return 0;
   //s�� double_node ptr����
   /*remove the double_node s from the list*/
   else
   {
      s->prev->next = s->next;
      s->next->prev = s->prev;
      free(s); return 1;
   }
}

/*t���� k���� ���� ��带 �����Ѵ�*/
double_node *insert_double_node(int k, int t)
{
   double_node *s;
   double_node *i = NULL;   //��� i�� �����Ѵ�
   i = (double_node*)malloc(sizeof(double_node));
   s = find_double_node(t); //Ű���� t�� ��带 ã�Ƽ� ptr ��ȯ
   //i��尡 s��� ���� ���ԵǾ�� ��
   i->key = k;
   i->next = s;
   i->prev = s->prev;
   s->prev->next = i;
   s->prev = i;
   return i;
}

/*��带 ũ������� �����Ͽ� k�� ������ �ּ���*/
double_node *Insert_double_node_in_order_of_size(int k)
{
    double_node *s = NULL;
    double_node *i = NULL;
    i = (double_node*)malloc(sizeof(double_node));
    if(head->next!=tail) //head, tail, �׸��� ��� 1���̻��� ��
    {
       s = head->next;
       while(s!=tail) //�ݺ����� ���鼭 i ���� ��� s�� ã�´� -> �׸��� i���� ���踦 ����ؼ� ������.
       {
         if(s->next->key >=k && s->key <=k &&s->next!=tail) //k���� 2�� ��� ���̿� ���� ��
         {
             if(s->next->next == tail) //tail���� ���� ���� �Ǵ� �����Ǿ��� ���� ����
             {
                tail->prev->prev = i;  //�̷��� �ؾ� tail���� ���� ���������� �����
             }
             i->key = k;
             i->prev = s;
             i->next = s->next;
             s->next = i;
             s->next->prev = i;
             //printf("���� :%d\n",i->key); //���� �� 10.
             break;
         }
         else if(s->key >= k && s == head->next) //k�� ���� ���� Ű���϶�
         {
            //printf("small");
            i -> key = k;
            i -> prev = head;
            i -> next = head->next;
            head->next->prev = i;
            head->next = i;
            break;
         }
         else if(s->key <=k && s->next == tail) //s->key���� k���� ��� ���� ��
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
    else if(head->next == tail) //��尡 �ƹ��͵� ���� ��(head tail�� ��)
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

//�Ű����� �����Ϳ� �ش��ϴ� ��带 �����ּ���.
int delete_double_node_ptr(double_node *p)
{
   if(p == head || p == tail) //head�ų� tail�̸� �ȵǹǷ� 0��ȯ
      return 0;
    p->prev->next = p->next;
    p->next->prev = p->prev;
   free(p);
   return 1;
}

//��� t�� ���� k���� ���� ��带 �������ּ���.
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

//double node�� ��� ������ּ���.
void print_all(double_node *p)
{
  while(p!=tail)
  {
    printf("%d    ",p->key);
    p = p->next;
  }
  printf("\n");
}

//��� ������ �������ּ���.
void delete_all_double_nodes(void)
{
  double_node *p = head->next;
  double_node *q = NULL; //�ӽ� ������
  for(; p!=tail; p=q) //�ݺ��� �� ������ p�� �ӽ÷� ������ p->next�� �ҷ���
  {
      q = p->next; //p->next���� q�� �ӽ� ����
      free(p);     //p�� ����Ű�� �޸� �Ҹ�
  }
  head->next = tail; //head�� tail�� ���� �̾��־� �ʱ�ȭ ��Ŵ
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
  //Insert_double_node_in_order_of_size(12); //12 �����ص� ���������� ��µ�
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


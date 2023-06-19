#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int number;
  struct node *next;
}node;

int main(void){
  //list의 초기화.
  //연결리스트의 첫번째 값을 가리킬 것이다.
  node *list = NULL;
  //새로운 노드 추가 값은 1
  node *n = malloc(sizeof(node));
  if(n != NULL){
    n->number = 1;
    n->next = NULL;
  }
  list = n;
  //  list -> 1

  //또 다른 노드를 연결하려고 한다. 
  //메모리 재할당
  n = malloc(sizeof(node));
  if(n != NULL){
    n->number = 2;
    n->next = NULL;
  }
  list->next = n;
  //  list -> 1 -> 2 

  //마지막 node에 값 4 을 추가하기.
  n = malloc(sizeof(node));
  if(n != NULL){
    n->number = 4;
    n->next = NULL;
  }
  //마지막 노드를 추적한다.
  node *tmp = list;
  while(tmp->next != NULL){
    tmp = tmp->next;
  }
  tmp->next = n;
  //list->1->2->4


  //맨 앞에 값 0 을 넣고 싶다.
  n = malloc(sizeof(node));
  if(n != NULL){
    n->number = 0;
    n->next = NULL;
  }
  //지금 넣어준 값 node의 next가 첫번째 값의 주소를 가리키도록.
  n->next = list;
  //그리고 첫번째 값을 가리키는 list가 새로 넣어준 값의 주소를 가리키도록.
  list = n;
  //list->0->1->2->4


  //중간에 3을 넣고 싶다.
  n = malloc(sizeof(node));
  if(n != NULL){
    n->number = 3;
    n->next = NULL;
  }
  //tmp(임시주소저장소)
  tmp = list;
  while(tmp->number+1 < n->number ){
    tmp = tmp->next;
  }//이러면 tmp는 지금 2를 가리키고 있을 것.
  n->next = tmp->next;
  tmp->next = n;

  //연결리스트 출력하기
  for(node *tmp = list ; tmp != NULL ; tmp = tmp->next){
    printf("%i ", tmp->number);
  }
  printf("\n");

  //메모리 해제
  while(list != NULL){
    node *tmp = list->next;
    free(list);
    list = tmp;
  }

  return 0;
}
#include <stdio.h>
#include <stdlib.h>

int stupid_mallocfunc(void);
int reallocfunc(void);

int main(void){
  stupid_mallocfunc();
  reallocfunc();

  return 0;
}



int stupid_mallocfunc(void){
  int *list = malloc(3*sizeof(int));
  if(list == NULL){ return 1; }
  
  list[0] = 1;
  list[1] = 2;
  list[2] = 3;
  
  int *tmp = malloc(4*sizeof(int));
  if(tmp == NULL){return 1;}

  for(int i=0; i<3; i++){
    tmp[i] = list[i];
  }
  tmp[3] = 4;
//memory는 풀어주고
  free(list);
//이름을 연결해줌
  list = tmp;

  for(int i=0; i<4; i++){
    printf("%i \n", list[i]);
  }

  return 0;
}


int reallocfunc(void){
  int *list = malloc(3*sizeof(int));
  if(list == NULL){ return 1; }
  
  list[0] = 1;
  list[1] = 2;
  list[2] = 3;
  

  //임시메모리변수를 할당하지 않고 기존의 메모리 변수에 재할당하여 사용한다면
  //기존의 메모리들이 갖고 있는 값이 사라지게 된다.
  int *tmp = realloc(list,4*sizeof(int));
  if(tmp == NULL){
    return 1;
  }

  list = tmp;
  tmp[3]=4;

  for(int i=0; i<4; i++){
    printf("%i \n", list[i]);
  }

  free(list);
  return 0;
}
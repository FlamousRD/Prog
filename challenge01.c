//[Daily Problem] Add two numbers as linked lists
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//node definition
typedef struct node {
  int element;
  struct node * next;
}nodeL;

//functions
nodeL *initList(nodeL *List){
  List = NULL;
  return List;
}

nodeL *addElement(nodeL *List, int number){
    nodeL *newNode, *aux;
    newNode = (nodeL *)malloc(sizeof(nodeL));
    if(newNode !=NULL){ //iamFull verification
    newNode->element=number;
    newNode->next = NULL;

    if(List == NULL){ //Empty
      List = newNode;
    }else{
      aux = List;
      while(aux->next != NULL){
        aux = aux->next;
      }
      aux->next = newNode;
    }
  }else{
    perror("Memory overflow");
  }
    return List;
}

void showList(nodeL *List){
  nodeL *aux;

  aux=List;

   while (aux !=NULL) {
     printf("%i",aux->element);
     if(aux->next != NULL){
       printf("->");
     }
     aux=aux->next;

  }
}

void dataRequest(nodeL *List1,nodeL *List2){

int data;

  printf("Insert digit-by-digit to numbers to add. Negatives numbers will count as exit methods\n");
  printf("Insert each digit of the 1st number\n");
    scanf("%i",&data);

  while (data>=0){
    List1= addElement(List1,data);
    scanf("%i",&data);
  }

  printf("Insert each digit of the 2nd number\n");
    scanf("%i",&data);

  while(data>=0){
    List2= addElement(List2,data);
    scanf("%i",&data);
  }

  printf(" Your numbers are: \n");
  showList(List1);
  printf("\n");
  showList(List2);
  printf("\n\n");
}

nodeL *addLists(nodeL *List1,nodeL *List2){
  //creating result list and its own managament node
  nodeL *ListR= NULL,*auxR;
  ListR= initList(ListR);
  auxR= ListR;

  // creating two auxiliars for managing the adding
  nodeL *auxL1, *auxL2;
  auxL1=List1;
  auxL2=List2;
  bool carry =false; //bool for node overflow(bigger than 9)

  while(auxL1 != NULL || auxL2 != NULL ){

    if(auxL1 == NULL){
      auxR->element=auxL2->element;
    }else{
      if(auxL2 == NULL){
        auxR->element=auxL1->element;
      }
    }

    if(auxL1 !=NULL && auxL2 !=NULL){
      auxR->element=auxL1->element + auxL2->element;
    }
    if(carry == true){
      auxR->element=auxR->element+1;
      carry=false;
    }
    if(auxR->element >9){
      auxR->element= auxR->element-10;
      carry=true;
    }

  }
  return ListR;
  }

//main function
int main(){

  nodeL *List1= NULL;
  nodeL *List2 = NULL;
  nodeL *ListResult;

  //Lists
  List1= initList(List1);
  List2= initList(List2);
  dataRequest(List1,List2);
  ListResult= addLists(List1,List2);
  showList(ListResult);

  return 0;
}

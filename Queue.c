#include <stdio.h>
#include <stdlib.h>
#include <time.h> 


// Queue Node 
struct node {
    int data;
    struct node *next;
};

// Front & Rear 
struct node *front = NULL;
struct node *rear = NULL;

// Enqueue
int enqueue(int data){
    // Queue is empty 
    if(front==NULL){
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->data = data;
        new->next = NULL;

        front = rear = new;
    }
    // Queue is not empty
    else {
        struct node *new= (struct node *)malloc(sizeof(struct node));
        new->data = data;
        new->next = NULL;
        rear->next = new;
        rear = new;
    }

    return 1;
}

// Display Queue
int display(){

    // Queue is empty
    if(front==NULL){
        printf("Queue is empty \n");
        return 1;
    }
    printf("\n");
    printf("Queue: ");
    struct node *index = front;
    while(index!=NULL){
        printf("%d - ", index->data);
        index = index->next;
    }

    printf("\n");

    return 1;
}
//Searching in queue
int search(int arananSayi) {
    struct node *index = front;
    
    int max=100;
  while(max--){
      if (arananSayi == index->data) {
      printf("\n%d sayısı bulundu", index->data);
      printf(" %d.sıra  \n", 100-max);
      break;
    }
    index=index->next;
  }
}
// Main
int main(){
    int max=100;
 while (max--) {
    int random = rand() % 1000 + 1;
    enqueue(random);
  }
    int girilenSayi;
  printf("0-1000 arasında bir sayı giriniz:");
  scanf("%d", &girilenSayi);
  search(girilenSayi);
    display();
}
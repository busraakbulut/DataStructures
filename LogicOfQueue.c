#include <stdio.h>
#define BOYUT 5
int kuyruk[BOYUT], front = -1 , rear =-1; // front en öndeki eleman; rear en arkadaki eleman;
	
	void enQueue(int veri){
		
		if(rear == BOYUT-1){
			printf("\nQueue is full");
		}
		else {
			if(front == -1){
				front = 0;
				rear = rear +1;
				kuyruk[rear] = veri;	
		}
		}
	}
	
	void deQueue(){
	if (front == rear || front > rear){
		printf("\nqueue is empty");
		front = -1;
		rear = -1;
	}
	else {
		front = front+1;
	}
	
	}
	void yazdir(){
		int i;
		for ( i = front; i<= rear ; i++){
			printf("%d ", kuyruk[i]);
		}
		
		
	}
	int main(){
		int secim,veri;
		printf("\n1-enQueue");
		printf("\n2-deQueue");
		
		while(1==1){
			printf("\nYapmak istediginiz islemi seciniz:");
			scanf("%d" , &secim);
			if(secim == 1){
			printf("\nEklemek istediginiz veriyi girin:");
			scanf("%d", &veri);
			enQueue(veri);
			yazdir();
		}
			if(secim == 2){
				deQueue();
				yazdir();
			}
			}
		
		return 0;
	}

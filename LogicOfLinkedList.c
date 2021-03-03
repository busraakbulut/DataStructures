#include<stdio.h>
#include<stdlib.h>

	struct node{
		int data;
		struct node *next;
	};
	
		struct node* start = NULL;
		struct node* temp = NULL;
		struct node* q = NULL;


	void sonaEkle(int veri){
		struct node* eklenecek = (struct node*)malloc(sizeof(struct node));
		eklenecek->data = veri;
		eklenecek->next= NULL;
		// iki farklý case var bu durumda ya linked list boþtur ve biz ilk elemaný
		// atarýz ya da varolan linked listte sona ekleme yaparýz :)
		if(start == NULL){ // bu durumda baþa atarýz yani linked listin boþ olduðu durumdur
			start = eklenecek;
		}
		else{ // linked listin sonuna ekleme yaptýðýmýz durumda burasý iþler.
			temp = start ;
			while (temp->next != NULL){
				temp = temp->next;}
				temp->next = eklenecek;	
		}
	}
	
	
	
	void basaEkle(int basa){ // basa eleman ekleyen kod
		struct node *basaGelecek = (struct node*)malloc(sizeof(struct node));
		basaGelecek->data = basa;		
		basaGelecek->next = start;
		start = basaGelecek;
	}
	
	
	void arayaEkle(int x, int y){ // bir int araya eklenecek veri,diðeri de hangi araya ekleneceðini gösteren.
		struct node* arayaEklenecek = (struct node*) malloc(sizeof(struct node));
		arayaEklenecek->data = y;
		temp = start;
		while ( temp->next->data != x){
			temp = temp->next;
		}
		struct node* onune =(struct node*)malloc(sizeof(struct node));
		onune = temp->next;
		temp->next = arayaEklenecek;
		arayaEklenecek->next = onune;
	}
	void sondanSil(){
		temp = start;
		while (temp->next->next != NULL){
		temp = temp->next;
		}	
		free(temp->next);
		temp->next= NULL;	
	}
	void bastanSil(){
		struct node* ikinci = NULL;
		ikinci = start->next;
		free(start);
		start = ikinci;		
	}
	void aradanSil(int ara){
		if (start->data == ara){
			bastanSil();
		}
		struct node *onceki = NULL;
		struct node *sonraki = NULL;
		// bir önceki düðümü bulduran döngü
		temp = start;
		while (temp->next->data != ara){
		temp = temp->next;
		}	
		if(temp->next == NULL){
			sondanSil();
		}
		onceki = temp;
		sonraki = temp->next->next;
		free(temp->next);
		onceki->next= sonraki;
	}
	void yazdir(){	// yazdýrma kodu
	q= start;
	while( q->next != NULL){
		printf("%d =>  ",q->data);
		q = q->next;
	}
	printf("%d", q->data);
}

	int main (){
		int secim , sona, basa, x , y,z;
		while(1==1){
		printf("\n1- Sona Eleman Ekleme");
		printf("\n2- Basa Eleman Ekleme");
		printf("\n3- Araya Eleman Ekleme");
		printf("\n4- Sondan Eleman Silme");
		printf("\n5- Bastan Eleman Silme");
		printf("\n6- Aradan Eleman Silme");
		printf("\nYapmak istediginiz islemi secin:\n");
		scanf("%d", &secim);
		
	switch(secim)
	{ // caselere göre iþlem yapmamýzý saðlayan switchcase yapýsý
		case 1:
			printf("Sona eklemek istediginiz sayiyi giriniz:\n");
			scanf("%d", &sona);
			sonaEkle(sona);
			yazdir();
			break;
			
		case 2:
			printf("Basa eklemek istediðiniz sayiyi giriniz:\n");
			scanf("%d",&basa);
			basaEkle(basa);
			yazdir();
			break;
			
		case 3:	
			printf("Hangi sayinin onune ekleme yapacaksiniz?\n");
			scanf("%d", &x);
			printf("Hangi sayiyi ekleyeceksiniz?\n");
			scanf("%d", &y);
			arayaEkle(x , y);
			yazdir();
			break;	
			
		case 4:
			sondanSil();
			yazdir();
			break;
			
		case 5:
			bastanSil();
			yazdir();
			break;		
		
		case 6:
		printf("Hangi sayiyi silmek istersiniz?\n");
		scanf("%d",&z);
		aradanSil(z);
		yazdir();
		break;		
	}
	}
	return 0;
	}

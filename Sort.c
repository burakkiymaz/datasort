/* 
 * File:   main.c
 * Author: burak
 *
 * Created on December 14, 2015, 9:45 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define LISTE 10
typedef struct linkedList llist;
/*
 * 
 */
struct linkedList{
    int data;
    struct linkedList* next;
    struct linkedList* back;
};

llist* head = NULL;
llist* end = NULL;
llist* temp = NULL;// geçiçi olarak tutucu eleman
llist* slc = NULL;// seçilmiş eleman
llist* explorer = NULL;// gezici eleman
int veri;

void basla();
void sayiAl();
void ekle(int);
void sil(int);
void listele();
void selectionSort();
void bubbleSort();
void sort();


int main(int argc, char** argv) {
    basaDon:
    basla();
    sayiAl();
    /*ekle(7);// bu kısım manuel ekleme yapılan kısım
    ekle(3);
    ekle(5);
    ekle(8);
    ekle(2);
    ekle(9);
    ekle(4);
    ekle(15);
    ekle(6);*/
    listele();
    sort();
    goto basaDon; // sıralama bittikten sonra başa dönmesi için başa dön komutu yazıldı.
    
    
    return (EXIT_SUCCESS);
}

void basla(){
    head = (llist*)malloc(sizeof(llist)); // tüm listemiz boş olduğu için head ve end i tutan bir alan ayrıldı.
    head->data = NULL;
    head->back = NULL;
    head->next = NULL;
    end = head;

}
void sayiAl(){// kullanıcıdan sayı alınacak kısım
    int i,datauser;
    for(i=0;i<LISTE;i++){
        printf("10 / %d. sayiyi giriniz: ",i+1);
        scanf("%d",&datauser);
        ekle(datauser);
    }
}

void ekle(int sayi){
    if (head->data == NULL){// eğer head->data NULL ise hiç eleman eklenmemiş demektir yani boş listedir. ilk eleman eklenir.
        head->data = sayi;
        printf("eleman eklendi\n");
    }
    else{// eğer öncesinde listede eleman varsa eleman en başa eklenir ve head kaydırılır.
        temp = (llist*)malloc(sizeof(llist));
        head->next = temp;
        temp->back = head;
        head = temp;
        head->data = sayi;
        printf("eleman eklendi\n");
    }
}

void listele(){// listeyi kullanıcıya göstermeye yarayan fonksiyon
    temp = head;
    printf("\n--------Liste--------\n");
    while(temp != NULL){
        printf("%d\n",temp->data);
        temp = temp->back;
    }
    
}
void sort(){// bu fonksiyonla kullanıcıya hangi sırala yöntemiyle sıralanmasını istediği sorulacak
    listele();
    int gelen;
    printf("\n\n\t1 -> Selection Sort\n\t2 -> Bubble Sort\nBu listeyi hangi siralama yontemiyle siralamak istesiniz?\n-> ");
    scanf("%d",&gelen);
    switch(gelen){
        case 1: 
            selectionSort();
            listele();
            break;
        case 2: 
            bubbleSort();
            listele();
            break;
        default:
            printf("Hatali giris yaptiniz...");
            break;
    }
    
}

void selectionSort(){
    printf("\nSelection Sort\n");
    
    slc = head;
    
    while(slc != NULL){// slc NULL değilse hala listede eleman var demektir.
        explorer = slc;
        temp = slc;
        while(explorer != NULL){// tüm elemanları gezerek en küçük elemanı bulmaya çalışıyoruz
            if (explorer->data < temp->data)
                temp = explorer;
            explorer = explorer->back;
        }
        
        veri = temp->data;// veri bulduğumuz en küçük elemanın data kısmı
        temp->data = slc->data;// bu kısmı slc ile seçilen elemanın data sı ile değiştiriyoruz
        slc->data = veri;
        slc = slc->back;// slc yi bir ileri taşıyoruz.
    }
    
}


void bubbleSort(){
    printf("\nBubble Sort\n");
    slc = head;// slc yi ilk eleman olarak tanımladık
    while(slc!=NULL){//slc NULL değilse hala listede eleman var demektir.
        
        explorer = head->back;
        temp = head;
        while(explorer !=NULL){
            if (explorer->data < temp->data){//eğer explorer temp den küçükse yer değiştirme yapılır
                veri = explorer->data;
                explorer->data = temp-> data;
                temp->data = veri;
            }
            temp = temp->back;
            explorer = explorer->back;// temp ve explorer bir sonraki değere taşınır.
            
        }
        slc = slc->back;// slc bir sonraki değere taşınır
    }
}



























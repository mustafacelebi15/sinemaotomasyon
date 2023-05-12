#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

enum matine{kirmizi=1, mavi, yesil}a;

struct Denemex{
int matine;
int filmnum;
int koltuknum;
int ogrtam;
int kirmizimatine[4][49];
int yesilmatine[4][49];
int mavimatine[4][49];
}kullanicilar[750];

char kullaniciadi[50];
char sifre[50];
int kulsif, kulsif2;
int sayac;
int sayac1;
int toplamhasilat;
int hasilatiste;
int kackis;
int kackisa;
int sayackontrol(){

   FILE *sayacinki;
   sayacinki=fopen("sayac.txt","r+");
    if(sayacinki==NULL){
        return 0;
        exit(1);
    }
    fscanf(sayacinki,"%d",&sayac1);
    fclose(sayacinki);
    return sayac1;

}
void sifreyial(){
    FILE *pdosya;

    pdosya=fopen("sifre.txt", "w+");
    if(pdosya==NULL){
        printf("dosya acilamadi");
        exit(1);
    }
    printf("Lutfen kullanici adinizi giriniz.\n");
    scanf("%s",kullaniciadi);
    printf("lutfen sifreinizi giriniz.\n");
    scanf("%s",sifre);
    fprintf(pdosya,"%s\n%s ",kullaniciadi,sifre);
    fclose(pdosya);
    return 0;
}
void sifrekontrol(){
char kulll[50];
char sifff[50];
char kulll2[50];
char sifff2[50];
FILE *pDosya;
pDosya=fopen("sifre.txt", "r");
if(pDosya == NULL){
    printf("Dosya okunamadi");
    exit(1);
}
fscanf(pDosya, "%s\n%s",kulll,sifff);
hadi:
printf("Lutfen kullanici adinizi giriniz.\n");
scanf("%s",kulll2);
printf("Lutfen sifrenizi giriniz.\n");
scanf("%s",sifff2);
kulsif = strcmp(kulll2,kulll);
kulsif2 = strcmp(sifff2,sifff);
if(kulsif2==0 && kulsif==0){
        menugeldi();
    }
     else{
        printf("Giris yapilamadi tekrar deneyiniz.\n");
        goto hadi;
    }
}


int main()
{
int dada;
dada=sayackontrol();
if(dada>0){
    sifrekontrol();
}
else{
    kackisyazdir();
    hasilatyazdir();
    girisfonksiyon();
}
    return 0;
}


void girisfonksiyon(){
    gelbura:
    sayaciyazdir();
    sayacioku();
if(sayac1 == 0){
    sifreyial();
    printf("Ilk giris oldugu icin sifreniz kaydedilmistir.\n");
goto gelbura;
}
else{
    sifrekontrol();
    if(kulsif2==0 && kulsif==0){
        menugeldi();
    }
    else{
        printf("Giris yapilamadi tekrar deneyiniz.\n");
        goto gelbura;
    }
}
return 0;
}
void sayaciyazdir(){

    FILE *sayacinki;
   sayacinki = fopen("sayac.txt", "w+");
    if(sayacinki == NULL){
        printf("dosya acilamadi");
        exit(1);
    }
    fprintf(sayacinki,"%d", sayac);
    fclose(sayacinki);
    sayac++;
    return 0;
}
void sayacioku(){
   FILE *sayacinki;
   sayacinki=fopen("sayac.txt","r+");
    if(sayacinki==NULL){
        printf("dosya acilamadi");
        exit(1);
    }
    fscanf(sayacinki,"%d",&sayac1);
    fclose(sayacinki);
    return 0;
}
void menugeldi(){
int son;
int *ps;
int i;
int sayi;
int ucretgiris;
    printf("---------------Sinema Salonumuza Hos Geldiniz.---------------\n");
    hasilatoku();
    printf("\t1-Kirmizi matine\n");
    printf("\t2-Mavi matine\n");
    printf("\t3-Yesil matine\n");
    printf("\tLutfen secmek istediginiz matineyi seciniz\n");
    scanf("%d",&kullanicilar[kackisa].matine);
a=kullanicilar[kackisa].matine;
    printf("Lutfen 1-5 arasi gitmek istediginiz filmi seciniz.\n");
    scanf("%d",&kullanicilar[kackisa].filmnum);
yenidenkoltuk:
srand(time(NULL));
    for (i=0;i<1;i++){
     sayi=rand()%50;
    }
    for(i=0;i<50;i++){
        kullanicilar[kackisa].kirmizimatine[1][i]=0;
         kullanicilar[kackisa].kirmizimatine[2][i]=0;
          kullanicilar[kackisa].kirmizimatine[3][i]=0;
    }
     switch(a){
case kirmizi:
    ps=&kullanicilar[kackisa].kirmizimatine[a][sayi]; //koltuk adresini atadim bunu kontrol edicem bos mu diye
    if(*ps != 0){
        goto yenidenkoltuk;
    }
    else{
    kullanicilar[kackisa].kirmizimatine[a][sayi]=1; //bu adrese sayi tanimladik ve artik bos degil
    printf("Koltuk numaraniz %d dir.\n",sayi);
    printf("Kirmizi matine %d. film %d. koltukta oturuyorsunuz.\n",kullanicilar[kackisa].filmnum,sayi);
    }
    break;
case mavi:
    ps = &kullanicilar[kackisa].mavimatine[a][sayi]; //koltuk adresini atadim bunu kontrol edicem bos mu diye
    if(*ps != 0){
        goto yenidenkoltuk;
    }
    else{
    kullanicilar[kackisa].mavimatine[a][sayi]=1; //bu adrese sayi tanimladik ve artik bos degil
    printf("Koltuk numaraniz %d dir.\n",sayi);
    printf("Mavi matine %d. film %d. koltukta oturuyorsunuz.\n",kullanicilar[kackisa].filmnum,sayi);
    }
    break;
case yesil:
    ps=&kullanicilar[kackisa].yesilmatine[a][sayi]; //koltuk adresini atadim bunu kontrol edicem bos mu diye
    if(*ps != 0){
         goto yenidenkoltuk;
}
    else{
            kullanicilar[kackisa].yesilmatine[a][sayi]=1; //bu adrese sayi tanimladik ve artik bos degil
            printf("Koltuk numaraniz %d dir.\n",sayi);
            printf("Yesil matine %d. film %d. koltukta oturuyorsunuz.\n",kullanicilar[kackisa].filmnum,sayi);
    }
    break;
    }
    printf("Ogrenci iseniz 1 tuslayip para girisi yapiniz.\n");
    printf("Tam ucret odeyecekseniz 2 tuslayip para girisi yapiniz.\n");
    scanf("%d",&ucretgiris);
    switch(ucretgiris){
case 1:
    toplamhasilat= toplamhasilat + 20;
    hasilatiste= hasilatiste + 20;
    break;
    case 2:
     toplamhasilat= toplamhasilat + 30;
     hasilatiste= hasilatiste + 30;
     break;
    }
if (sayac1>0)
 hasilatiyaz();
  else
   hasilatyazdir();
kackisoku();
kackisa++;
kackisiyaz();
    printf("Giris menusune donmek icin 2 yi tuslayin.(bunun haricinde bir tuslama programi sonlandirir)\n");
    scanf("%d",&son);
  if(son==2)
    menugeldi();
else{
    return 0;
}
    return 0;

}
void hasilatiyaz(){
FILE *hasilat;
   hasilat=fopen("hasilat.txt","r+");
    if(hasilat==NULL){
        printf("dosya acilamadi");
        exit(1);
    }
    fprintf(hasilat,"%d", hasilatiste);
    fclose(hasilat);
}
void hasilatyazdir(){
FILE *hasilat;
   hasilat=fopen("hasilat.txt","w+");
    if(hasilat==NULL){
        printf("dosya acilamadi");
        exit(1);
    }
    fprintf(hasilat,"%d", toplamhasilat);
    fclose(hasilat);
}
void hasilatoku(){
FILE *hasilat;
   hasilat=fopen("hasilat.txt","r+");
    if(hasilat==NULL){
        printf("dosya acilamadi");
        exit(1);
    }
    fscanf(hasilat,"%d",&hasilatiste);
    fclose(hasilat);
    printf("Toplam hasilat %d dir\n",hasilatiste);
}
void kackisyazdir(){
FILE *kackisi;
   kackisi=fopen("kackisi.txt","w+");
    if(kackisi==NULL){
        printf("dosya acilamadi");
        exit(1);
    }
    fprintf(kackisi,"%d", kackis);
    fclose(kackisi);
}
void kackisoku(){
FILE *kackisi;
   kackisi=fopen("kackisi.txt","r+");
    if(kackisi==NULL){
        printf("dosya acilamadi");
        exit(1);
    }
    fscanf(kackisi,"%d",&kackisa);
    printf("\n--------------Sinema salonumuzda bulunan insan sayisi %d dir--------------\n",kackisa+1);
    fclose(kackisi);
}
void kackisiyaz(){
FILE *kackisi;
   kackisi=fopen("kackisi.txt","r+");
    if(kackisi==NULL){
        printf("dosya acilamadi");
        exit(1);
    }
    fprintf(kackisi,"%d", kackisa);
    fclose(kackisi);
}

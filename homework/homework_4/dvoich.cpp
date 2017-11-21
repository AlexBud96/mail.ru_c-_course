#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct bit_pole//объявляем новый тип данных типа структура, в которой объявлены 8 битовых полей 
    {                             //по 1 биту каждое
    unsigned a1 = rand() % 1;
    unsigned a2:1;
    unsigned a3:1;
    unsigned a4:1;
    unsigned a5:1;
    unsigned a6:1;
    unsigned a7:1;
    unsigned a8:1;
	/*unsigned a1:;
    unsigned a2:1;
    unsigned a3:1;
    unsigned a4:1;
    unsigned a5:1;
    unsigned a6:1;
    unsigned a7:1;
    unsigned a8:1;*/
    }bit_pole;
    
typedef union dvoich// объявляем объединение 1-байтового числа и структуры с бит. полями.
   {                          //теперь можно записав в переменную "с" какое-нибудь число, вывести его     
    char ll;                 //побитовое представление в памяти(двоичный код)
    bit_pole bits;
   }dvoich;

int main()
 {

  srand (time(NULL));
  dvoich ch;// объявляем переменную типа объединение
  ch.ll=5;// присваиваем полю "с" объединения значение 5
  printf("ch.ll=%d\n",ch.ll);// выводим поле "с". будет выведено "ch.c=5"
  printf("dvoichniy kod chisla %d raven %d%d%d%d%d%d%d%d\n",ch.ll,ch.bits.a8,ch.bits.a7,ch.bits.a6,ch.bits.a5,ch.bits.a4,ch.bits.a3,ch.bits.a2,ch.bits.a1);// выводим битовые поля с конца, что связано с архитектурой intel-овских процессоров(число записывается задом наперед). будет выведено "00000101"
  return 0;
 }

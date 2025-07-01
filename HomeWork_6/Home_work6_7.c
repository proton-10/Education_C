// Перевод числа N из 10 в P-ичную 

#include <stdio.h>

unsigned long long int conv_num(unsigned long long int num, unsigned char basis);

int main(void)
{
    unsigned int num = 0;
    unsigned char basis = 0;
    scanf("%u%hhu", &num, &basis);
    
    printf("%llu", conv_num(num, basis));
    return 0;
}

// ф-ция перевода числа в другую систему счисления
unsigned long long int conv_num(unsigned long long int num, unsigned char basis) // заголовок ф-ции с двумя параметрами на вход и типо результата int
{
    unsigned long long int j = num, size = 0;
    num = 0;
    while (j>0)
    {
        num = num*10 + j%basis;
        size++;
        printf("%llu: j = %llu, j%%base = %llu,  j/base= %llu, num = %llu \n", size, j, j%basis, j/basis, num);
        j/=basis;
    }
    
    j = num, num = 0;
    
    while (size>0)
    {
        num = num*10 + j%10;
        size--;
        printf("%llu: j = %llu, j%%10 = %llu,  j/10= %llu, num = %llu \n", size, j, j%10, j/10, num);
        j/=10;
    }

    return num;
}

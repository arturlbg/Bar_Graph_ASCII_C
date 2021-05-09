# include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int maior_valor(int array[], int length){
    int maior=0;
    for (int i=0; i<length; i++){
        if (array[i]>maior){
            maior=array[i];
        }
    }
    return maior;
}

int digitos(int n){
    if(n<0) n = -n;
    return n<10?1:
             n<100?2:
             n<1000?3:
             n<10000?4:
             n<100000?5:
             n<1000000?6:
             n<10000000?7:
             n<100000000?8:
             n<1000000000?9:
             10;
}


void sort(int array[], int n)
{
    int i,key,j;
    for (i=1;i<n;i++)
    {
        key=array[i];
        j=i-1;

        while (j>=0 && array[j]>key)
        {
            array[j+1]=array[j];
            j=j-1;
        }
        array[j+1]=key;
    }
}

void test(int a[], int b[], int n){
    int maior, qntd, value, value2;
    maior = maior_valor(b, n);

    if (maior>100){

        qntd = digitos(maior) - 2;
        value=pow(10,qntd);

        for(int i=0; i<n; i++){
            b[i] = b[i]/value;
        }
    }

    for (int i=0; i<n; i++) {
        value2=digitos(a[i]);
        printf("  %d",a[i]);
        for (int j=7-value2; j>0;j--){
                printf(" ");
                }
        printf("❚");
        if (maior<=10){
            for(int j=0; j<b[i];j++){
                printf("■");
        }}
        if (maior>10){
            for(int j=0; j<b[i];j+=2){
                printf("■");
        }
        }
        printf("\n");

    }
    printf("         ");
    if (maior<=10){
        for (int i=0; i<n; i++){
            printf("▬▬");
    }}
    if (maior>10){
        for (int i=0; i<n; i++){
            printf("▬▬▬▬▬▬");
    }
    }
    printf("\n");

    sort(a,n);
    sort(b,n);

    if (maior<=10){
        printf("         ");
        for (int i=0; i<=10; i++){
            if (i%2==0){
                printf("%d",i);
            }
            else{
                printf(" ");
            }

    }

}
    if (maior>10){
        printf("         0    ");
        for (int i=0; i<=100; i+=2){
            if (i!=0 && i%10==0){
                printf("%d",i);
                printf("   ");
            }


    }
    if (maior>100){
        printf("(*%d)",value);
    }
}}

int main(void) {
    int year1[6]={2016,2017,2018,2019,2020,2021},quantidade1[6]={2,2,6,4,1,8},length1=0;
    int year2[8]={2015,2016,2017,2018,2019,2020,2021,2022},quantidade2[8]={15,20,80,45,30,55,90,65},length2=0;
    int year3[10]={2015,2016,2017,2018,2029,2020,2021,2022,2023,2024},quantidade3[10]={1500,2500,2500,8000,4000,1500,4500,4000,5000,3000},length3=0;
    length1=sizeof(year1)/sizeof(year1[0]);
    length2=sizeof(year2)/sizeof(year2[0]);
    length3=sizeof(year3)/sizeof(year3[0]);
    
    printf("Gráfico quando o maior valor é 10:\n");
    test(year1,quantidade1, length1);
    printf("\n\n");
    
    printf("Gráfico quando o maior valor é 100:\n");
    test(year2,quantidade2, length2);
    printf("\n\n");
    
    printf("Gráfico quando o maior valor é maior que 100:No canto inferior direito é mostrado o quanto o valor é multiplicado, ficando acessível para qualquer valor alto.\n");
    test(year3,quantidade3, length3);
    printf("\n\n");

    return 0;

}
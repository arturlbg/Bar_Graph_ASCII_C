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

void sort(int array[], int n){
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


void barra_vertical(int a[], int b[], int n){
    int maior, qntd, value,value2, x[n];
    
    for (int i=0; i<n;i++){
        x[i] = b[i];
    }
    
    
    sort(b, n);
    maior = maior_valor(b, n);
    
    qntd = digitos(maior) - 2;
    value2=pow(10,qntd);
    
    if (maior<=10){
        for (int i=10;i>0;i--){
            value=digitos(i);
            if (i%2==0){
                printf("%d",i);
                for (int j=7-value; j>0;j--){
                    printf(" ");
                }
                printf("❚");
                for (int k=0; k<n; k++){
                    if (i <= x[k]){
                        printf("   ▪   ");
                    }
                    else{
                        printf("       ");
                    }
                }
                printf("\n");
            }
            else{
                printf("       ❚");
                for (int k=0; k<n; k++){
                    if (i <= x[k]){
                        printf("   ▪   ");
                    }
                    else{
                        printf("       ");
                    }
                }
                printf("\n");
            }
        }
    }
    if (maior>10){
        if (maior>100){
        printf("*(%d)\n",value2);
        for(int i=0; i<n; i++){
            x[i] = x[i]/value2;
        
        }}
        for (int i=100; i>0;i-=5){
            value=digitos(i);
            
            printf("%d",i);
            for (int j=7-value; j>0;j--){
                printf(" ");
                }
            printf("❚");
            for (int k=0; k<n; k++){
                    if (i <= x[k]){
                        printf("   ▪   ");
                    }
                    else{
                        printf("       ");
                    }
            
        }
        printf("\n");
    }}
    
    
    printf("0      ▬▬▬▬▬▬▬▬▬");
    for (int i=0; i<n; i++){
        printf("▬▬▬▬▬▬");
    }
    printf("\n");
    printf("      ");
    
    for (int i=0; i<n; i++){
        value=digitos(a[i]);
            for (int j=7-value; j>0;j--){
                printf(" ");
                }
        printf("%d",a[i]);
    }
}


int main(void) {
    int year1[8]={2014,2015,2016,2017,2018,2019,2020,2021},quantidade1[8]={2,3,1,5,9,1,4,4},length1=0;
    int year2[6]={2014,2015,2016,2017,2018,2019},quantidade2[6]={50,10,15,90,95,50},length2=0;
    int year3[10]={2013,2014,2015,2016,2017,2018,2019,2020,2021,2022},quantidade3[10]={2500,1500,9000,6000,5000,4000,5500,6000,7500,1000},length3=0;
    length1=sizeof(year1)/sizeof(year1[0]);
    length2=sizeof(year2)/sizeof(year2[0]);
    length3=sizeof(year3)/sizeof(year3[0]);
    
    printf("Gráfico quando o maior valor é 10:\n\n");
    barra_vertical(year1,quantidade1, length1);
    printf("\n\n");
    
    printf("Gráfico quando o maior valor é 100:\n\n");
    barra_vertical(year2,quantidade2, length2);
    printf("\n\n");
    
    printf("Gráfico quando o maior valor é maior que 100: No lado superior esquerdo é mostrado o quanto o valor é multiplicado, ficando acessível para qualquer valor alto.\n\n");
    barra_vertical(year3,quantidade3, length3);
    printf("\n\n");

    return 0;

}
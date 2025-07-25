#include <stdio.h>
#include<stdlib.h>

#define VOLTAS 100

int main(){
    float susp = 1.0, comb = 1.0;
    int temp = 80, i = 1;

    for(i; i <= VOLTAS; i++){

        susp -= 0.02;
        comb -= 0.015;
        temp ++;
        if(i%10 == 0 && i>0){
            susp -= 0.03;
            temp += 5;
        }
        if(susp < 0 || comb < 0)
        {
            if(susp < 0 && comb > 0)
            {
                printf("Corrida encerrada na volta %d, por problemas na suspensão. \n", i);
                break;
            }
            if(susp > 0 && comb < 0){
                printf("Corrida encerrada na vola %d, por falta de combustivel \n", i);
                break;
            }
            printf("Corrida encerrada na volta %d, por problemas na suspensão e falta de combustível \n", i);
            break;
        }
        if(susp < 0.2 || temp > 115)
            printf("Alerta!! Temperatura do motor: %dºC, \t Suspensão em %.2f%% \n",temp,susp*100);
        if(i%20 == 0 && i>0)
            printf("Relatorio da volta: %d, Suspensão em: %.2f%%, Combustivel em: %.2f%%, \n Temperatura de: %dºC \n", i, susp*100, comb*100, temp);
    }
    printf("\n RESULTADO FINAL: \n Numero de voltas: %d, Combustivel restante: %.2f%%, Suspensão restante: %.2f%%, Temperatura: %dºC", i, comb*100,susp*100, temp);

    }
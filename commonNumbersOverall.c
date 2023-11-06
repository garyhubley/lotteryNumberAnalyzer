/* File: Lotto Numbers.c
This program reads the Lotto Numbers in "main draw.txt" and tells the user
the most common lotto numbers used.

programmer: Gary Hubley    
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 20000

/*prototype functions*/
void setcount(int count[], int n, int num[]);
void algor(int count[], int n, int common[], int num[]);
int checkforvalue(int count, int common[]);

int main(void)
{
    int num[N], count[51]={0}, n, i, j;
    int common[8]={0};
    FILE *maindraw, *maxmil;
    maindraw = fopen("main draw.txt", "r");

    n=0;
    while(fscanf(maindraw, "%d", &num[n]) != EOF){
        n++;
    }
    
    setcount(count, n, num);
     for( j=1; j<51; j++){
            printf("%d ", count[j]);
            if((j)%10 == 0)
                printf("\n");
        }system("pause");

     for(i=0; i<51; i++){
         if(count[i] > count[common[0]] ){
             common[0] = i;
             i=0;
         }else if(count[i] > count[common[1]] && checkforvalue(i, common) != 0){
             common[1] = i;
             i=0;
         }else if(count[i] > count[common[2]] && checkforvalue(i, common) != 0){
             common[2] = i;
             i=0;
         }else if(count[i] > count[common[3]] && checkforvalue(i, common) != 0){
             common[3] = i;
             i=0;
         }else if(count[i] > count[common[4]] && checkforvalue(i, common) != 0){
             common[4] = i;
             i=0;
         }else if(count[i] > count[common[5]] && checkforvalue(i, common) != 0){
             common[5] = i;
             i=0;
         }else if(count[i] > count[common[6]] && checkforvalue(i, common) != 0){
             common[6] = i;
             i=0;
         }else if(count[i] > count[common[7]] && checkforvalue(i, common) != 0){
             common[7] = i;
             i=0;
         }
     }

    for(i=0; i<8; i++){
        printf("%d common %d with %d occurances\n", i+1, common[i], count[common[i]]);
    }
    
    system("pause");
    return 0;
}

int checkforvalue(int i, int common[])
{
    int k;
    for(k=0; k<8; k++){
        if(i == common[k]){
            return 0;
        }
    }
    return 1;
}

void setcount(int count[], int n, int num[])
{
    int i;

    for(i=0; i<n; i++){
        
        switch(num[i]){
            case 1:
                count[1]++;
                break;
            case 2:
                count[2]++;
                break;
            case 3:
                count[3]++;
                break;
            case 4:
                count[4]++;
                break;
            case 5:
                count[5]++;
                break;
            case 6:
                count[6]++;
                break;
            case 7:
                count[7]++;
                break;
            case 8:
                count[8]++;
                break;
            case 9:
                count[9]++;
                break;
            case 10:
                count[10]++;
                break;
            case 11:
                count[11]++;
                break;
            case 12:
                count[12]++;
                break;
            case 13:
                count[13]++;
                break;
            case 14:
                count[14]++;
                break;
            case 15:
                count[15]++;
                break;
            case 16:
                count[16]++;
                break;
            case 17:
                count[17]++;
                break;
            case 18:
                count[18]++;
                break;
            case 19:
                count[19]++;
                break;
            case 20:
                count[20]++;
                break;
            case 21:
                count[21]++;
                break;
            case 22:
                count[22]++;
                break;
            case 23:
                count[23]++;
                break;
            case 24:
                count[24]++;
                break;
            case 25:
                count[25]++;
                break;
            case 26:
                count[26]++;
                break;
            case 27:
                count[27]++;
                break;
            case 28:
                count[28]++;
                break;
            case 29:
                count[29]++;
                break;
            case 30:
                count[30]++;
                break;
            case 31:
                count[31]++;
                break;
            case 32:
                count[32]++;
                break;
            case 33:
                count[33]++;
                break;
            case 34:
                count[34]++;
                break;
            case 35:
                count[35]++;
                break;
            case 36:
                count[36]++;
                break;
            case 37:
                count[37]++;
                break;
            case 38:
                count[38]++;
                break;
            case 39:
                count[39]++;
                break;
            case 40:
                count[40]++;
                break;
            case 41:
                count[41]++;
                break;
            case 42:
                count[42]++;
                break;
            case 43:
                count[43]++;
                break;
            case 44:
                count[44]++;
                break;
            case 45:
                count[45]++;
                break;
            case 46:
                count[46]++;
                break;
            case 47:
                count[47]++;
                break;
            case 48:
                count[48]++;
                break;
            case 49:
                count[49]++;
                break;
            case 50:
                count[50]++;
                break;
            default:
                count[0]++;
        }
    }
    return;
}



/* File: Lotto Numbers.c
This program reads the Lotto Numbers in "main draw.txt" and tells the user
the most common lotto numbers used.

programmer: Gary Hubley    
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 20000
#define T 8

/*prototype functions*/
void setcount(int count[], int n, int num[]);
void algor(int count[], int n, int common[], int num[]);
int checkforvalue(int count, int common[]);
void tallyupnumbers(int count[], int common[]);
int PrintCommonNumbers(int common[], int j, int count[]);

int main(void)
{
    int filechoice;
    int TotalEntriesRead, NumberOfDraws, count[51]={0}, n, i, j=1;
    /*Variables for most common lotto numbers in each position*/
    int common1[T]={0}, common2[T]={0}, common3[T]={0}, common4[T]={0};
    int common5[T]={0}, common6[T]={0}, common7[T]={0}, common8[T]={0};
    /*Variables for storing each number from corrosponding position*/
    int num1[N], num2[N], num3[N], num4[N];
    int num5[N], num6[N], num7[N], num8[N], AllNum[N];
    /*Variables for frequency of number in each position*/
    int count1[N]={0}, count2[N]={0}, count3[N]={0}, count4[N]={0};
    int count5[N]={0}, count6[N]={0}, count7[N]={0}, count8[N]={0};
    /*Pointers for files used*/
    FILE *maindraw;
    
    printf("Choose which file you would like to use: \n1: main draw.txt\n2: maxmil.txt");
    scanf("%d", &filechoice);
    
    switch filechoice

    /*Open the files being used*/
    maindraw = fopen("main draw.txt", "r");

    /*Scan for the numbers in the file*/
    n=0;
    while(fscanf(maindraw, "%d", &AllNum[n]) != EOF){
        n++;
    }

    /*Notify the number of draws and the total number of entries*/
    TotalEntriesRead = n;
    NumberOfDraws = TotalEntriesRead/8;
    
    /*Sort all numbers into corrosponding slot (1,2,3,4,5,6,7,8)*/
    i=0;
    for(n=0; n<TotalEntriesRead; n++){
        switch(n%8){
                case 0:
                    num1[i] = AllNum[n];
                    break;
                case 1:
                    num2[i] = AllNum[n];
                    break;
                case 2:
                    num3[i] = AllNum[n];
                    break;
                case 3:
                    num4[i] = AllNum[n];
                    break;
                case 4:
                    num5[i] = AllNum[n];
                    break;
                case 5:
                    num6[i] = AllNum[n];
                    break;
                case 6:
                    num7[i] = AllNum[n];
                    break;
                case 7:
                    num8[i] = AllNum[n];
                    i++;
                    break;
                default:
                    break;
        }
    }               
    
    /*Count the recurrences of a specific number in each individual slot*/
    setcount(count1, NumberOfDraws, num1);
    setcount(count2, NumberOfDraws, num2);
    setcount(count3, NumberOfDraws, num3);
    setcount(count4, NumberOfDraws, num4);
    setcount(count5, NumberOfDraws, num5);
    setcount(count6, NumberOfDraws, num6);
    setcount(count7, NumberOfDraws, num7);
    setcount(count8, NumberOfDraws, num8);

    tallyupnumbers(count1, common1);
    tallyupnumbers(count2, common2);
    tallyupnumbers(count3, common3);
    tallyupnumbers(count4, common4);
    tallyupnumbers(count5, common5);
    tallyupnumbers(count6, common6);
    tallyupnumbers(count7, common7);
    tallyupnumbers(count8, common8);
    
    j = PrintCommonNumbers(common1, j, count1);
    j = PrintCommonNumbers(common2, j, count2);
    j = PrintCommonNumbers(common3, j, count3);
    j = PrintCommonNumbers(common4, j, count4);
    j = PrintCommonNumbers(common5, j, count5);
    j = PrintCommonNumbers(common6, j, count6);
    j = PrintCommonNumbers(common7, j, count7);
    j = PrintCommonNumbers(common8, j, count8);
    
    system("pause");
    return 0;
}

int PrintCommonNumbers(int common[], int j, int count[])
{
    int i, k;
    k=j;
    printf("The common numbers in the %d slot are: \n", k);
    for(i=0; i<8; i++){
        printf("%2d with %d occurances\n", common[i], count[common[i]]);
    }
    k++;
    return k;
}
void tallyupnumbers(int count[], int common[])
{
    int i;
    for(i=0; i<51; i++){
         if(count[i] > count[common[0]] ){
             common[0] = i;
             i=0;
         }else if(count[i] > count[common[1]] && i != common[0]){
             common[1] = i;
             i=0;
         }else if(count[i] > count[common[2]] && i != common[0] && i != common[1]){
             common[2] = i;
             i=0;
         }else if(count[i] > count[common[3]] && i != common[0] && i != common[1]
         && i != common[2]){
             common[3] = i;
             i=0;
         }else if(count[i] > count[common[4]] && i != common[0] && i != common[1]
         && i != common[2] && i != common[3]){
             common[4] = i;
             i=0;
         }else if(count[i] > count[common[5]] && i != common[0] && i != common[1]
         && i != common[2] && i != common[3] && i != common[4]){
             common[5] = i;
             i=0;
         }else if(count[i] > count[common[6]] && i != common[0] && i != common[1]
         && i != common[2] && i != common[3] && i != common[4] && i != common [5]){
             common[6] = i;
             i=0;
         }else if(count[i] > count[common[7]] && i != common[0] && i != common[1]
         && i != common[2] && i != common[3] && i != common[4] && i != common [5]
         && i != common[6]){
             common[7] = i;
             i=0;
         }
     }
}

void setcount(int count[], int NumberOfDraws, int num[])
{
    int i;

    for(i=0; i<NumberOfDraws; i++){    
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



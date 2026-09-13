
#include <stdio.h>
#include <string.h>

struct Goods{
    char Code[10];
    char Name[100];
    float Price;
    };
int main(){
    char a[100];
    int b=0; 
    
    struct Goods market[3]={
        {"001","cola",3.50},
        {"002","lollipop",0.50},
        {"003","noodles",6.00}
    };
    while (b==0){
        
        int panding=0;
        scanf("%s",a);
        if (strcmp(a,"prices")==0){
            printf("%-20s %s %s\n","Item","No.", "Pri.");
            printf("---------\n");
            for (int i=0;i<3;i++){
            
                printf("%-20s %s %.2f\n",market[i].Name,market[i].Code,market[i].Price);}
        }
        else if (strcmp(a,"exit")==0){
            b=1;
        }
        else{
            for (int i=0;i<3;i++){
                if (strcmp(a,market[i].Code)==0){
                    printf("%s,%.2f\n",market[i].Name,market[i].Price);
                    panding=1;

                    break;
                }
            }
                if(panding==0){
                    printf("error\n");
                }
        }
        }
    
    return 0;
}
     

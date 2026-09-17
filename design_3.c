#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Goods{
    char Code[10];
    char Name[100];
    float Price;
    int Num;
    int Totol_num;
    };
int main(){
    char a[100];
    int b=0; 
    int c;
    float total=0.00;
    
    
    struct Goods market[3]={
        {"001","cola",3.50,0,0},
        {"002","lollipop",0.50,0,0},
        {"003","noodles",6.00,0,0}
    };
    while (b==0){
        
        printf(">");
        while (1){
            int ret=scanf ("%s",a);
            if (ret!=1){
                break;
            }
            int panding=0;
            int sub=0;//加减判断
            char* p;
    
            
            
            
        if (isalpha(a[0])){
            break;
        }
        
        
        else{
            if (a[0]=='-'){
                sub=1;
                p=a+1;
            }
            else{
                p=a;
            }
            for (int i=0;i<3;i++){
                if (strcmp(p,market[i].Code)==0){
                    if (sub){
                        market[i].Num-=1;
                    
                    }
                    else {
                        market[i].Num+=1;
                    }
                    
                    panding=1;
                    break;

                    
                }
            }
                if(panding==0){
                    printf("error\n");
                }

        }
        c = getchar();
            if(c == '\n'){
                // 下一个字符是回车，说明本组所有内容读完，跳出内层循环
                break;
            }else{
                // 下一个字符是空格，把它放回缓冲区，留给下一次scanf读取
                ungetc(c, stdin);
    }}
    if (strcmp(a,"prices")==0){
            printf("%-20s %s %s\n","Item","No.", "Pri.");
            printf("--------------------------------\n");
            for (int i=0;i<3;i++){
            
                printf("%-20s %s %.2f\n",market[i].Name,market[i].Code,market[i].Price);}
        }
        else if (strcmp(a,"exit")==0){
            b=1;
        }
    
        
    
    

    if (strcmp(a,"checkout")==0){
        printf("%s\n%-20s %s   %s %s\n","receipt","Item", "Pri.","Qty","Amount");
        printf("--------------------------------\n");
        for (int i=0;i<3;i++){
            if (market[i].Totol_num!=0){
            

                printf("%-20s %.2f x %d = %.2f\n",market[i].Name,market[i].Price,market[i].Totol_num,market[i].Price*market[i].Totol_num);
                total+=market[i].Price*market[i].Totol_num;
                market[i].Totol_num=0;
            }

        }
        printf("--------------------------------\n");
        printf("%s                %.2f\n","Total",total);
        total=0.0;
        continue;
    }
    if (strcmp(a,"drop")==0){
        
        for (int i=0;i<3;i++){
            if (market[i].Totol_num!=0){
            
                market[i].Totol_num=0;
            }

        }
        continue;
    
    }
    if (strcmp(a,"print")==0){
        printf("%s\n%-20s %s   %s %s\n","receipt","Item", "Pri.","Qty","Amount");
        printf("--------------------------------\n");
        for (int i=0;i<3;i++){
            if (market[i].Totol_num!=0){
            

                printf("%-20s %.2f x %d = %.2f\n",market[i].Name,market[i].Price,market[i].Totol_num,market[i].Price*market[i].Totol_num);
                total+=market[i].Price*market[i].Totol_num;
            
            }

        }
        printf("--------------------------------\n");
        printf("%s                %.2f\n","Total",total);
        total=0.0;
        continue;
    
    }
    for (int i=0;i<3;i++){
            if (market[i].Num!=0){
                market[i].Totol_num+=market[i].Num;
                market[i].Num=0;

                printf("%-20s %.2f x %d = %.2f\n",market[i].Name,market[i].Price,market[i].Totol_num,market[i].Price*market[i].Totol_num);
                
            }
        }

}
    return 0;
}
     

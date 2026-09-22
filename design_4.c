#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
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
    int day=1;
    int no=1;//订单号
    char date[10];
    
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
            for (int i=0;i<3;i++){//总结计数
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
    for (int i=0;i<3;i++){
            if (market[i].Num!=0){
                market[i].Totol_num+=market[i].Num;
                market[i].Num=0;

                printf("%-20s %.2f x %d = %.2f\n",market[i].Name,market[i].Price,market[i].Totol_num,market[i].Price*market[i].Totol_num);
                
            }}
    if (strcmp(a,"newdays")==0){
        
        sprintf(date,"sale_%d.csv",day);//day是数！！
        rename("sale.csv",date);
        remove(date);
        FILE *fp=fopen("sale.csv","w");//fp是指向文件地址的指针
        if (fp!=NULL){
            fclose(fp);
        }
        day+=1;
        no=1;
    }
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
        FILE *fp=fopen("sale.csv","a");
        time_t now=time(NULL);//获得时间指针
        struct tm *p=localtime(&now);
        char time_n[30];
        strftime(time_n,sizeof(time_n),"%H:%M:%S",p);
        fprintf(fp,"%d,%s,",no,time_n);
        no++;
        printf("%s\n%-20s %s   %s %s\n","receipt","Item", "Pri.","Qty","Amount");
        printf("--------------------------------\n");
        for (int i=0;i<3;i++){
            if (market[i].Totol_num!=0){
            

                printf("%-20s %.2f x %d = %.2f\n",market[i].Name,market[i].Price,market[i].Totol_num,market[i].Price*market[i].Totol_num);
                total+=market[i].Price*market[i].Totol_num;
                fprintf(fp,"%s x %d;",market[i].Name,market[i].Totol_num);//本来考虑符号分割，但放入内容不够简便，决定读取时换行分割
                market[i].Totol_num=0;
            }

        }
        printf("--------------------------------\n");
        printf("%s                %.2f\n","Total",total);
        fprintf(fp,",%.2f\n",total);
        fclose(fp);
        total=0.0;
        continue;
    }
    if (strncmp(a,"sale",4)==0){
        if (strlen(a)<5){FILE *fp=fopen("sale.csv","r");
            if (fp == NULL) {
        printf("当日暂无销售记录。\n");
        continue;
    }

    char line[200];
    float totall=0.0;
    printf("Date: %d\n",day);
    printf("No.\tTime\t\tItems\t\t\tAment\n");
    printf("------------------------------------------------------\n");

    while (fgets(line, sizeof(line), fp) != NULL) {
        // 解析一行数据 (假设格式严格为 id,time,items,amount)
        int id = 0;
        char tim[20] = {0};
        char items[100] = {0};
        float amount = 0.0;
        
        
        // 利用 sscanf 解析逗号分隔的内容
        // 注意：%[^,] 表示读取直到遇到逗号
        if (sscanf(line, "%d,%[^,],%[^,],%f", &id, tim, items, &amount) == 4) {
    int fenhaoshu = 0;
    int address = -1;
    // 先统计分号数量，找到最后一个分号的位置
    for (int i=0; items[i]!='\0';i++){
        if(items[i]==';'){
            fenhaoshu++;
            address = i;
        }
        // 识别到最后一个分号刚好在字符串末尾，直接把它替换成结束符，删掉多余的尾部分号
    if(address != -1 && items[address + 1] == '\0'){
        items[address] = '\0';
        fenhaoshu--;
}

    }
    // 第一行先输出No.和Time
    printf("%-5d %-10s ", id, tim);
    // 第二次遍历字符，替换分号
    for (int i=0; items[i]!='\0';i++){
        if(items[i]==';'){
            // 所有分号都替换成换行+缩进
            printf("\n%20s", "");
        }else{
            
            putchar(items[i]);
        }
    }
    
    printf("%30.2f\n", amount);
    totall+=amount;
}

    }
    printf("------------------------------------------------------\n");
    printf("Daily: %.2f\n", totall); 
    totall=0.0;
    fclose(fp);

        
        }
        else{int saleday = atoi(a+5); // 跳过前4个字符"sale"，把后面的数字转成整数
            sprintf(date,"sale_%d.csv",saleday);
            FILE *fp=fopen(date,"r");
            if (fp == NULL) {
        printf("当日暂无销售记录。\n");
        continue;
    }

    char line[200];
    float totall=0.0;
    printf("Date: %d\n",saleday);
    printf("No.\tTime\t\tItems\t\t\tAment\n");
    printf("------------------------------------------------------\n");

    while (fgets(line, sizeof(line), fp) != NULL) {
        // (假设格式严格为 id,time,items,amount)
        int id = 0;
        char tim[20] = {0};
        char items[100] = {0};
        float amount = 0.0;
        
        
        // 利用 sscanf 解析逗号分隔的内容
        // 注意：%[^,] 表示读取直到遇到遇到逗号
         if (sscanf(line, "%d,%[^,],%[^,],%f", &id, tim, items, &amount) == 4) {
    int fenhaoshu = 0;
    int address = -1;
    // 先统计分号数量，找到最后一个分号的位置
    for (int i=0; items[i]!='\0';i++){
        if(items[i]==';'){
            fenhaoshu++;
            address = i;
        }
        // 识别到最后一个分号刚好在字符串末尾，直接把它替换成结束符，删掉多余的尾部分号
    if(address != -1 && items[address + 1] == '\0'){
        items[address] = '\0';
        fenhaoshu--;
}

    }
    // 第一行先输出No.和Time
    printf("%-5d %-10s ", id, tim);
    // 第二次遍历字符，替换分号
    for (int i=0; items[i]!='\0';i++){
        if(items[i]==';'){
            // 所有分号都替换成换行+缩进
            printf("\n%20s", "");
        }else{
            
            putchar(items[i]);
        }
    }
    
    printf("%30.2f\n", amount);
    totall+=amount;
}
    }
        printf("------------------------------------------------------\n");
        printf("Daily: %.2f\n", totall); 
        totall=0.0;

        
        fclose(fp);}
    }
    if (strcmp(a,"drop")==0){
        
        for (int i=0;i<3;i++){
            if (market[i].Totol_num!=0){
            
                market[i].Totol_num=0;
            }

        }
        
    
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
    
        

}
    return 0;
}
     

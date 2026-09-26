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
    int Stock;
    };
int main(){
    char a[100];
    int b=0; 
    int c;
    float total=0.00;
    int day=1;
    int no=1;//订单号
    char date[20];
    int model=0;
    int goodnum=3;
    char newcode[10];
    float newprice=0.00;
    char newname[100];
    int newstock=0;
    char turepassword[20]="admin123";
    struct Goods market[20]={
        {"001","cola",3.50,0,0,70},
        {"002","lollipop",0.50,0,0,80},
        {"003","noodles",6.00,0,0,20}
    };
    while (b==0){
        if (model==1){
            printf("admin>");
            scanf("%s",a);
            if (strcmp(a,"setprice")==0){
                
                scanf("%s %f",newcode,&newprice);
                for (int i=0;i < goodnum;i++){
                    if (strcmp(market[i].Code,newcode)==0){
                        market[i].Price=newprice;
                        printf("price updated");

                    }
                
                }
            }
        else if (strcmp(a,"back")==0){
            printf("bye\n");
            model=0;
        }
        else if (strcmp(a,"change")==0){
            printf("new password:");
            scanf("%s",turepassword);
            model=0;
            printf("password change,please log in again\n");
        }
        else if (strcmp(a,"itemadd")==0){
                
                scanf("%s %s %f",newcode,newname,&newprice);
                market[goodnum].Price=newprice;
                strcpy(market[goodnum].Code, newcode);
                strcpy(market[goodnum].Name, newname);
                market[goodnum].Num = 0;
                market[goodnum].Totol_num = 0;
                market[goodnum].Stock = 0;
                printf("%s added",market[goodnum].Name);
                goodnum++;
        }
        else if (strcmp(a,"itemdel")==0){
            int pos = -1;
            scanf("%s",newcode);
    for(int i=0; i<goodnum; i++) {
        if(strcmp(market[i].Code, newcode) == 0) {
            pos = i;
            break;
        }
    }
    printf("%s removed",market[pos].Name);
    if(pos == -1) {
        printf("未找到条码%s的商品\n", newcode);
        return -1;
    }
    for(int i=pos; i < goodnum -1; i++) {
        market[i] = market[i+1];
    }
        goodnum--;
        

        }
        else if (strcmp(a,"restock")==0){
            scanf("%s %d",newcode,&newstock);
            for (int i=0;i < goodnum;i++){
                    if (strcmp(market[i].Code,newcode)==0){
                        market[i].Stock+=newstock;

                    }
                
                }
            
        }
        else if (strcmp(a,"setstock")==0){
            scanf("%s %d",newcode,&newstock);
            for (int i=0;i < goodnum;i++){
                    if (strcmp(market[i].Code,newcode)==0){
                        market[i].Stock=newstock;

                    }
                
                }
            
        }
        else if (strcmp(a,"prices")==0){
            printf("%-20s %s %s %s\n","Item","No.", "Pri.","Stock");
            printf("--------------------------------\n");
            for (int i=0;i<goodnum;i++){
            
                printf("%-20s %s %.2f %d\n",market[i].Name,market[i].Code,market[i].Price,market[i].Stock);}
        }
        }
        
    
        else{
        printf(">");
        while (1){
            scanf ("%s",a);
            
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
            for (int i=0;i<goodnum;i++){//总结计数
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
                    printf("ERROR: code not found\n");
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
    if (strcmp(a,"admin")==0){
        printf("password:");
        char password[20];
        scanf("%s",password);
        if (strcmp(password,turepassword)==0){
            model=1;}}
    for (int i=0;i<goodnum;i++){
            if (market[i].Num>0){
                market[i].Totol_num+=market[i].Num;
                market[i].Num=0;

                printf("%-20s %.2f x %d = %.2f\n",market[i].Name,market[i].Price,market[i].Totol_num,market[i].Price*market[i].Totol_num);
                
            }
        if (market[i].Num<0){
                printf("error:不能去除未购买的商品,该商品购买数已为您清零");
                market[i].Num=0;
                
            }
        
        
        }
    if (strcmp(a,"newday")==0){
        
        sprintf(date,"sale_%d.csv",day);//day是数！！
        remove(date);
        rename("sale.csv",date);
        
        FILE *fp=fopen("sale.csv","w");//fp是指向文件地址的指针
        if (fp!=NULL){
            fclose(fp);
        }
        day+=1;
        no=1;
        printf("New day started. Today's sales records cleared.");
    }
    if (strcmp(a,"prices")==0){
            printf("%-20s %s %s\n","Item","No.", "Pri.");
            printf("--------------------------------\n");
            for (int i=0;i<goodnum;i++){
            
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
        for (int i=0;i<goodnum;i++){
            if (market[i].Totol_num!=0){
            
                if (market[i].Stock-market[i].Totol_num<0){
                    market[i].Totol_num=market[i].Stock;
                    printf("库存不足，请尽快补充");
                }
                else if (market[i].Stock==market[i].Totol_num){
                    
                    printf("库存耗尽");
                }
                printf("%-20s %.2f x %d = %.2f\n",market[i].Name,market[i].Price,market[i].Totol_num,market[i].Price*market[i].Totol_num);
                total+=market[i].Price*market[i].Totol_num;
                fprintf(fp,"%s x %d;",market[i].Name,market[i].Totol_num);//为了数据整洁，还是符号分割
                market[i].Stock-=market[i].Totol_num;
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
    if (strncmp(a,"sales",5)==0){
        //输入格式为sales [day]
    int saleday=0;
        c = getchar();
            if(c == '\n'){
                // 下一个字符是回车，
                strcpy(date, "sale.csv");
            saleday=day;}
                // 下一个字符是空格，把它放回缓冲区，留给下一次scanf读取
                
        
        else{
            scanf("%d",&saleday);
            
            sprintf(date,"sale_%d.csv",saleday);
        }
        FILE *fp=fopen(date,"r");
            if (fp == NULL) {
        printf("当日暂无销售记录。\n");
        continue;
    }

    char line[200];
    float totall=0.0;
    printf("Date: %d\n",saleday);
    printf("%-5s %-10s %-22s %s\n", "No.", "Time", "Items", "Ament");
    printf("------------------------------------------------------\n");

    while (fgets(line, sizeof(line), fp) != NULL) {
        // 解析数据 (假设格式严格为 id,time,items,amount)
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
        // 把末尾的分号替换成结束符，删掉多余的尾部分号
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
            printf("\n%17s", "");
        }else{
            
            putchar(items[i]);
        }
    }
    
    printf("%10s\t%.2f\n", "",amount);
    totall+=amount;
    }
    }
    printf("------------------------------------------------------\n");
    printf("Daily: %.2f\n", totall); 
    totall=0.0;
    fclose(fp);
}

    if (strcmp(a,"drop")==0){
        
        for (int i=0;i<goodnum;i++){
            if (market[i].Totol_num!=0){
            
                market[i].Totol_num=0;
            }
        }
    
    }
    if (strcmp(a,"print")==0){
        printf("%s\n%-20s %s   %s %s\n","receipt","Item", "Pri.","Qty","Amount");
        printf("--------------------------------\n");
        for (int i=0;i<goodnum;i++){
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
    
}}
    return 0;
}
     


#include <stdio.h>

char* my_itoa(int n){
    //思路：记录位数，然后反向抄写一遍
    
    // t取余数 sign表示正负（默认为正数） num 表示数字有效位
    int i=0,t,sign=1,num=0;
    char s[100];
    
    if(n==0){
        num++;//有效位数 1位
        s[0]='0';
    }

    if(n<0){
        n=-n;
        sign=-1;
        num++;
    }

    while (n>0) {
        t=n%10;
        n=n/10;
        s[i]='0'+t;
        i++;
        num++;//得到数字位数
    }
    
    if(sign<0){
        s[num]='-';//有负号时添加-，b并把位数+1
    }
    
    printf("位数是：%d \n",num);
    printf("最后一位是：%c \n",s[num]);
    
    //开始反向抄写
    char b[num];//定义新字符数组,
    int tempnum=num;//tempnum变量仅用于for循环
    for(int j=0;tempnum>0;j++){
        if(sign<0){//因为上面n=-n;去掉了负号，这里手动添加负号
            b[0]='-';
            j=1;
            sign=1;//处于循环体中的
        }
        b[j]=s[tempnum-1];
        tempnum--;
    }
    printf("第1位是：%c \n",b[0]);
    printf("第2位是：%c \n",b[1]);
    b[num]='\0';//给最后一位添加结束符
    
//    printf("字符串是：%s \n",b);
    
    char *p=b;//定义返回指针
    return p;//返回指针地址
}

int main() {
//测试1234、0、101、01234、1230
//    18:17  存在问题：返回指针 pass
//    19:30   存在问题：0123  ...
//    int test=0123;
//    printf("print test %d",test);
    
    int i=-123;
    char *s=my_itoa(i);
    printf("The string is %s \n",s);
    return 0;
}

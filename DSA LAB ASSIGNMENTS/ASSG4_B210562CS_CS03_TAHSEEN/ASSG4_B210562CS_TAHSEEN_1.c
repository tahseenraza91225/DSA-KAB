#include<stdio.h>
int compare(char [],char []);

struct student {
    char name[50];
    int marks;
};
 
int main() {
    int n, i, j;
    scanf("%d", &n);
    struct student s[n];

    for(i = 0; i < n; i++) {
        scanf("%s %d",&s[i].name, &s[i].marks);
    }

    char cr[50];
    scanf("%s", &cr);

    for(i = 0; i < n; i++) {
        if(compare(cr, s[i].name) == 0) {
            j = i;
        }
    }

    for(i = 0 ; i < n; i++) {
        if(s[i].marks < s[j].marks )
        printf("%s ",s[i].name);
    }

    printf("%s ",s[j].name);

    for(i = 0; i < n; i++) {
        if(s[i].marks > s[j].marks )
        printf("%s ",s[i].name);
    }

    return 0;
}

int compare(char a[],char b[]) {  
    int flag=0,i=0; 
    while(a[i]!='\0' &&b[i]!='\0') {  
       if(a[i]!=b[i]) {  
           flag=1;  
           break;  
       }  
       i++;  
    }  
    if(flag==0)  
    return 0;  
    else  
    return 1;  
}  
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

int n;
int a[MAX], b[MAX];

int hash[MAX];

int check_similar()
{
    memset(hash, 0, sizeof(hash));

    for (int i = 0; i < n; i++) {
        hash[a[i]]++;
    }

    for (int i = 0; i < n; i++) {
        if (--hash[b[i]] < 0)
            return 0;
    }

    return 1;
}

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    if (check_similar())
        printf("1\n");
    else
        printf("0\n");

    return 0;
}
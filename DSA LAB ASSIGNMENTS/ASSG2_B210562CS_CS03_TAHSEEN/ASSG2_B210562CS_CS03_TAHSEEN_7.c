#include <stdio.h>
#include <stdlib.h>
void sort(int a[], int n){
	int i;
	int j;
	int k;
	i = 1;
	while(i<n){
		j = i-1;
		k = a[i];
		for(; j>=0 && a[j]<k; ){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = k;
	        i++;
	}
}
int main(){
	int *a;
	a = (int*)malloc(100000*sizeof(int));
	int c = 0;
	char ch;
	scanf("%c", &ch);
	for(; ch!='e'; ){
		if(ch=='i'){
			int p;
			scanf("%d", &p);
			*(a+c) = p;
			c++;
			sort(a, c);
		}
		else if(ch=='c'){
			int d = 0, p, i;
			scanf("%d", &p);
			for(i = 0; i<c; i++){
				if(a[i]>p) d++;
			}
			printf("%d\n", d);
			for(i = c-1; i>=0; i--){
				if(a[i]>p) printf("%d ", a[i]);
			}
			printf("\n");
		}
		scanf("%c", &ch);
	}
}

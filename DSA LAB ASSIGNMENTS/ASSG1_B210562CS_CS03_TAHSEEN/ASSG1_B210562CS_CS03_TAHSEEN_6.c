#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

void print_range(char tree[], int x, int y, int pos) {
    if (tree[pos] == '\0')
        return;
    if (tree[pos] == '(') {
        int key = 0, i;
        for (i = pos + 1; tree[i] != ','; i++)
            key = key * 10 + tree[i] - '0';
        if (key > x)
            print_range(tree, x, y, pos + 1);
        if (key >= x && key <= y)
            printf("%d ", key);
        for (i++; tree[i] != ')'; i++) {
            if (tree[i] == '(')
                print_range(tree, x, y, i);
        }
        if (key < y)
            print_range(tree, x, y, i + 1);
    }
}

int main() {
    char tree[MAX_SIZE];
    int x, y;
    //printf("Enter Parenthesis Representation of BST: ");
    scanf("%s", tree);
    //printf("Enter range (x y): ");
    scanf("%d %d", &x, &y);
    printf("%d %d ", x, y);
    print_range(tree, x, y, 0);
return 0;}
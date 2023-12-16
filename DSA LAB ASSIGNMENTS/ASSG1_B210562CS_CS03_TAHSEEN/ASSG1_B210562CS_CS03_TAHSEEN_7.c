#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

bool print_ancestors(char tree[], int pos, int k) {
    if (tree[pos] == '\0')
        return false;
    if (tree[pos] == '(') {
        int key = 0, i;
        for (i = pos + 1; tree[i] != ','; i++)
            key = key * 10 + tree[i] - '0';
        if (key == k) {
            printf("%d ", key);
            return true;
        }
        if (print_ancestors(tree, pos + 1, k) || print_ancestors(tree, i + 1, k)) {
            printf("%d ", key);
            return true;
        }
    }
    return false;
}

int main() {
    char tree[MAX_SIZE];
    int k;
    // printf("Enter Parenthesis Representation of BST: ");
    scanf("%s", tree);
    // printf("Enter key value of node: ");
    scanf("%d", &k);
    printf( "%d", k);
    if (!print_ancestors(tree, 0, k))
        printf("Node not found in the tree.");
    return 0;
}
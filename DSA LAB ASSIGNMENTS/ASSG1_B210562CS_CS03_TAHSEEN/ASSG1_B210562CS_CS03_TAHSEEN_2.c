#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

bool is_leaf(char tree[], int pos) {
    // Check if the current node is a leaf node
    if (tree[pos] == '(') {
        int i;
        for (i = pos + 1; tree[i] != ')'; i++) {
            if (tree[i] == '(')
                return false;
        }
        return true;
    }
    return false;
}

int count_nodes(char tree[], int pos, int grandparent) {
    int count = 0;
    if (tree[pos] == '\0')
        return count;
    if (tree[pos] == '(') {
        int key = 0, i;
        for (i = pos + 1; tree[i] != ','; i++)
            key = key * 10 + tree[i] - '0';
        if (grandparent != -1) {
            for (i++; tree[i] != ')'; i++) {
                if (tree[i] == '(')
                    count += count_nodes(tree, i, key);
            }
        }
        if (grandparent != -1 && is_leaf(tree, pos)) {
            count++;
        }
    }
    return count;
}

int main() {
    char tree[MAX_SIZE];
    //printf("Enter Parenthesis Representation of tree: ");
    scanf("%s", tree);
    int count = count_nodes(tree, 0, -1);
    printf(" %d\n", count);
    return 0;
}
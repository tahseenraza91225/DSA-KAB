#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODE_VAL 1000000

// Node structure
typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
} Node;

// Helper function to create a new node
Node *newNode(int val) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Helper function to parse the parenthesis representation of the tree
Node *parseTree(char *tree) {
    int i = 0, val = 0;
    Node *root = NULL, *node = NULL;
    while (tree[i]) {
        if (tree[i] == '(') {
            if (root == NULL) {
                val = 0;
                while (tree[++i] != ' ') {
                    val = val * 10 + tree[i] - '0';
                }
                root = newNode(val);
                node = root;
            } else {
                val = 0;
                while (tree[++i] != ' ') {
                    val = val * 10 + tree[i] - '0';
                }
                if (val != 0) {
                    Node *child = newNode(val);
                    if (node->left == NULL) {
                        node->left = child;
                    } else {
                        node->right = child;
                    }
                    node = child;
                } else {
                    node = node->left ? node->left : node->right;
                }
            }
        } else if (tree[i] == ')') {
            node = node->left ? node->left : node->right;
        }
        i++;
    }
    return root;
}

// Helper function to find the node with key value x
Node *findNode(Node *root, int x) {
    if (!root) {
        return NULL;
    }
    if (root->val == x) {
        return root;
    }
    Node *left = findNode(root->left, x);
    if (left) {
        return left;
    }
    return findNode(root->right, x);
}

// Helper function to print the descendants of a node at a distance of k
void printDescendants(Node *node, int k) {
    if (!node) {
        return;
    }
    if (k == 1) {
        printf("%d ", node->val);
    } else {
        printDescendants(node->left, k - 1);
        printDescendants(node->right, k - 1);
    }
}

int main() {
    char tree[1000001];
    scanf("%s", tree);
    Node *root = parseTree(tree);
    int x, k;
    scanf("%d %d", &x, &k);
    Node *node = findNode(root, x);
    printDescendants(node, k);
    printf("\n");
     return 0;
}
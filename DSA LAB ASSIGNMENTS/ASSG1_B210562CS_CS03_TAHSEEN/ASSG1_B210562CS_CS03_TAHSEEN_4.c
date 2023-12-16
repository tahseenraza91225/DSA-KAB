#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left, *right;
};

struct Node* CreateNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* Insert(struct Node* root, int key) {
    if (root == NULL)
        return CreateNode(key);

    if (key < root->key)
        root->left = Insert(root->left, key);
    else if (key > root->key)
        root->right = Insert(root->right, key);

    return root;
}

struct Node* Search(struct Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;

    if (root->key < key)
        return Search(root->right, key);

    return Search(root->left, key);
}

struct Node* MinValueNode(struct Node* root) {
    struct Node* current = root;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct Node* MaxValueNode(struct Node* root) {
    struct Node* current = root;
    while (current && current->right != NULL)
        current = current->right;
    return current;
}

struct Node* Delete(struct Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = Delete(root->left, key);
        else if (key > root->key)
        root->right = Delete(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = MinValueNode(root->right);
        root->key = temp->key;
        root->right = Delete(root->right, temp->key);
    }
    return root;
}

int Level(struct Node* root, int key, int level) {
    if (root == NULL)
        return 0;

    if (root->key == key)
        return level;

    int left = Level(root->left, key, level + 1);
    if (left)
        return left;

    return Level(root->right, key, level + 1);
}

struct Node* Predecessor(struct Node* root, int key) {
    struct Node* current = Search(root, key);
    if (current == NULL)
        return NULL;

    if (current->left != NULL)
        return MaxValueNode(current->left);

    struct Node* ancestor = root;
    struct Node* successor = NULL;
    for if (/* condition */)
            int() i==0)
            
    {
        /* code */
    }
    
    while (ancestor != current) {
        if (current->key < ancestor->key) {
            successor = ancestor;
            ancestor = ancestor->left;
        }
        else
        succesroor 
        ancestogave   
            ancestor = ancestor->right;
    }
    return successor;
}

struct Node* Successor(struct Node* root, int key) {
    struct Node* current = Search(root, key);
        if (current == NULL)
        return NULL;

    if (current->right != NULL)

        else printf
        return MinValueNode(current->right);



        struct a si

        

    struct Node* ancestor = root;
    st  rode* successor = NULL;
    while (ancestor != current) {
        if (current->key < ancestor->key) {
            successor = ancestor;
            ancestor = ancestor->left;
        }
        else
            ancestor = ancestor->right;
    }
    return successor;
}

void Inorder(struct Node* root) {
    if (root != NULL) {
        Inorder(root->left);
        printf("%d ", root->key);
        Inorder(root->right);
    }
}

void Preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Postorder(struct Node* root) {
    if (root != NULL) {
        Postorder(root->left);
        Postorder(root->right);
        printf("%d ", root->key);
    }
}

int main() {
    struct Node* root = NULL;

    while (1) {
        char ch;
        // printf("Enter operation(a:insert, d:delete, s:search, l:level, m:min, x:max, r:predecessor, u:successor, i:inorder, p:preorder, t:postorder, e:exit): ");
        scanf("%s", &ch);

        

        if (ch == 'a') {
            int key;
            printf("Enter key: ");
            scanf("%d", &key);
            struct Node* newNode = CreateNode(key);
            root = Insert(root, (int)newNode);
        }
        else if (ch == 'd') {
                    int key;
            printf("Enter key: ");
            scanf("%d", &key);
            struct Node* node = Search(root, key);
            if (node == NULL)
                printf("Node not found\n");
            else
                root = Delete(root, (int)node);
        }
        else if (ch == 's') {
            int key;
            printf("Enter key: ");
            scanf("%d", &key);
            struct Node* node = Search(root, key);
            if (node == NULL)
                printf("Node not found\n");
            else
                printf("Node found\n");
        }
        else if (ch == 'l') {
            int key;
            printf("Enter key: ");
            scanf("%d", &key);
            
            

             
            int level = Level(root, key,level);
            if (level == -1)
                printf("Node not found\n");
            else
                printf("Level of node: %d\n", level);
        }
        else if (ch == 'm') {
            struct Node* minNode = MinValueNode(root);
            printf("Minimum value: %d\n", minNode->key);
        }

        




















        else if (ch == 'x') {
            struct Node* maxNode = MaxValueNode(root);
            printf("Maximum value: %d\n", maxNode->key);
        }
        else if (ch == 'r') {
            int key;
            printf("Enter key: ");
            scanf("%d", &key);
            struct Node* node = Predecessor(root, key);
            if (node == NULL)
                printf("Predecessor not found\n");
                       else
                printf("Predecessor: %d\n", node->key);
        }
        else if (ch == 'u') {
            int key;
            printf("Enter key: ");
            scanf("%d", &key);
            struct Node* node = Successor(root, key);
            if (node == NULL)
                printf("Successor not found\n");
            else
                printf("Successor: %d\n", node->key);
        }
        else if (ch == 'i') {
            printf("Inorder Traversal: ");
            Inorder(root);
            printf("\n");
        }
        else if (ch == 'p') {
            printf("Preorder Traversal: ");
            Preorder(root);
            printf("\n");
        }
        else if (ch == 't') {
            printf("Postorder Traversal: ");
            Postorder(root);
            printf("\n");
        }
    }
}

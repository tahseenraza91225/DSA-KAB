#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node
{
    struct Node *lchild;
    int data;
    int height;
    struct Node *rchild;
} *root = NULL;

int height(struct Node *p);

struct Node *Inpreccedor(struct Node *p);
 
struct Node *InSuccedor(struct Node *p);

int BF(struct Node *p);

struct Node *left_left_rotation(struct Node *p);

struct Node *left_Right_rotation(struct Node *p);

struct Node *Right_Right_rotation(struct Node *p);

struct Node *Right_left_rotation(struct Node *p);

struct Node *createNode(int key);

struct Node *RInsert(struct Node *p, int key);

struct Node *Search(int key);

void PRINT(struct Node *root);

struct Node *Delete(struct Node *p, int key);

int main()
{
    struct Node *temp;
    char ch;
    int q;
    do
    {
        scanf("%c", &ch);
        switch (ch)
        {
        case 'i':
            scanf("%d", &q);
            root = RInsert(root, q);
            break;
        case 's':
            scanf("%d", &q);
            temp = Search(q);
            if (temp != NULL)
                printf("TRUE\n");
            else
                printf("FALSE\n");
            break;
        case 'e':
            return 0;
            break;
        case 'b':
            scanf("%d", &q);
            temp = Search(q);
            if(temp==NULL)
            printf("FALSE\n");
            else
            printf("%d\n", BF(temp));
            break;
        case 'p':
            PRINT(root);
            printf("\n");
            break;
        case 'd':
            scanf("%d", &q);
            temp = Search(q);
            if (temp == NULL)
                printf("FALSE\n");
            else
            {
                printf("%d\n", temp->data);
                Delete(root,q);
            }
            break;
        }
    } while (ch != 'e');
    return 0;
}


int height(struct Node *p)
{
    int x = 0, y = 0;
    if (!p)
        return 0;
    x = height(p->lchild);
    y = height(p->rchild);
    return x > y ? x + 1 : y + 1;
}

struct Node *Inpreccedor(struct Node *p) {
    while (p && p->rchild != NULL){
        p = p->rchild;
    }
    return p;
}
 
struct Node *InSuccedor(struct Node *p) {
    while (p && p->lchild != NULL){
        p = p->lchild;
    }
    return p;
}

int BF(struct Node *p) {
    int hl;
    int hr;
    
    if(root==NULL)
    return 0;
    else
    {
        hl=height(p->lchild);
        hr=height(p->rchild);
        return hl-hr;
    }
}

struct Node *left_left_rotation(struct Node *p) {
    struct Node* pl = p->lchild;
    struct Node* plr = pl->rchild;
 
    pl->rchild = p;
    p->lchild = plr;
    p->height = height(p);
    pl->height = height(pl);
    if (root == p){
        root = pl;
    }
    return pl;
}
struct Node *left_Right_rotation(struct Node *p) {
    struct Node* pl = p->lchild;
    struct Node* plr = pl->rchild;
 
    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;
 
    plr->lchild = pl;
    plr->rchild = p;

    pl->height = height(pl);
    p->height = height(p);
    plr->height = height(plr);
 
    if (p == root){
        root = plr;
    }
    return plr;
}
struct Node *Right_Right_rotation(struct Node *p) {
    struct Node* pr = p->rchild;
    struct Node* prl = pr->lchild;
 
    pr->lchild = p;
    p->rchild = prl;

    p->height = height(p);
    pr->height = height(pr);

    if (root == p){
        root = pr;
    }
    return pr;
}
struct Node *Right_left_rotation(struct Node *p) {
    struct Node* pr = p->rchild;
    struct Node* prl = pr->lchild;
 
    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;
 
    prl->rchild = pr;
    prl->lchild = p;

    pr->height = height(pr);
    p->height = height(p);
    prl->height = height(prl);

    if (root == p){
        root = prl;
    }
    return prl;
}


struct Node *createNode(int key)
{
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=key;
    temp->height=1;
    temp->lchild=NULL;
    temp->rchild=NULL;
    return temp;
}

struct Node *RInsert(struct Node *p, int key)
{
    struct Node *t;
   if (p == NULL){
return createNode(key);
    }
 
    if (key < p->data){
        p->lchild = RInsert(p->lchild, key);
    } else if (key > p->data){
        p->rchild = RInsert(p->rchild, key);
    }

    p->height = height(p);
 
    if (BF(p) == 2 && BF(p->lchild) == 1) {
        return left_left_rotation(p);
    } else if (BF(p) == 2 && BF(p->lchild) == -1){
        return left_Right_rotation(p);
    } else if (BF(p) == -2 && BF(p->rchild) == -1){
        return Right_Right_rotation(p);
    } else if (BF(p) == -2 && BF(p->rchild) == 1){
        return Right_left_rotation(p);
    }
 
    return p;
}


void Inorder(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        Inorder(p->lchild);
        Inorder(p->rchild);
    }
}
struct Node *Search(int key)
{
    struct Node *t = root;
    while (t != NULL)
    {
        if (key == t->data)
            return t;
        else if (key < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    }
    return NULL;
}

void PRINT(struct Node *root)
{
    printf("( ");
    if (root == NULL)
    {
        printf(") ");
        return;
    }
    printf("%d ", root->data);
    PRINT(root->lchild);
    PRINT(root->rchild);
    printf(") ");
}

struct Node *Delete(struct Node *p, int key) {
    if (p == NULL){
        return NULL;
    }
 
    if (p->lchild == NULL && p->rchild == NULL){
        if (p == root){
            root = NULL;
        }
        free(p);
        return NULL;
    }
 
    if (key < p->data){
        p->lchild = Delete(p->lchild, key);
    } else if (key > p->data){
        p->rchild = Delete(p->rchild, key);
    } else {
        struct Node* q;
        if (height(p->lchild) > height(p->rchild)){
            q = Inpreccedor(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        } else {
            q = InSuccedor(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }

    p->height = height(p);

    if (BF(p) == 2 && BF(p->lchild) == 1) {
        return left_left_rotation(p);
    } else if (BF(p) == 2 && BF(p->lchild) == -1){
        return left_Right_rotation(p);
    } else if (BF(p) == -2 && BF(p->rchild) == -1){
        return Right_Right_rotation(p);
    } else if (BF(p) == -2 && BF(p->rchild) == 1){
        return Right_left_rotation(p);
    } else if (BF(p) == 2 && BF(p->lchild) == 0){
        return left_left_rotation(p);
    } else if (BF(p) == -2 && BF(p->rchild) == 0){
        return Right_Right_rotation(p);
    }
 
    return p;
}
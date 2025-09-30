#include <stdio.h>
#include <stdlib.h>

// ==========================
// Structures de données
// ==========================
typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct DNode {
    int data;
    struct DNode *prev, *next;
} DNode;

typedef struct CNode {
    int data;
    struct CNode *next;
} CNode;

typedef struct DCNode {
    int data;
    struct DCNode *prev, *next;
} DCNode;

// ==========================
// Fonctions utilitaires
// ==========================
Node* createNode(int data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

DNode* createDNode(int data) {
    DNode *newNode = (DNode*) malloc(sizeof(DNode));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

CNode* createCNode(int data) {
    CNode *newNode = (CNode*) malloc(sizeof(CNode));
    newNode->data = data;
    newNode->next = newNode;
    return newNode;
}

DCNode* createDCNode(int data) {
    DCNode *newNode = (DCNode*) malloc(sizeof(DCNode));
    newNode->data = data;
    newNode->prev = newNode->next = newNode;
    return newNode;
}

// ==========================
// 1. Suppression des occurrences
// ==========================
void deleteOccurrences(Node **head, int key) {
    Node *temp = *head, *prev = NULL;

    while (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        temp = *head;
    }

    while (temp != NULL) {
        while (temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) return;

        prev->next = temp->next;
        free(temp);
        temp = prev->next;
    }
}

void display(Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// ==========================
// 2. Insertion liste simple triée
// ==========================
void insertSorted(Node **head, int data) {
    Node *newNode = createNode(data);
    Node *current;

    if (*head == NULL || (*head)->data >= data) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    current = *head;
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

// ==========================
// 3. Insertion liste double triée
// ==========================
void insertSortedD(DNode **head, int data) {
    DNode *newNode = createDNode(data);
    DNode *current = *head;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    if (data <= (*head)->data) {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }

    newNode->next = current->next;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
    newNode->prev = current;
}

void displayD(DNode *head) {
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// ==========================
// 4. Liste simplement circulaire
// ==========================
void insertHeadC(CNode **head, int data) {
    CNode *newNode = createCNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    CNode *temp = *head;
    while (temp->next != *head) temp = temp->next;
    temp->next = newNode;
    newNode->next = *head;
    *head = newNode;
}

void insertTailC(CNode **head, int data) {
    CNode *newNode = createCNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    CNode *temp = *head;
    while (temp->next != *head) temp = temp->next;
    temp->next = newNode;
    newNode->next = *head;
}

void displayC(CNode *head) {
    if (head == NULL) return;
    CNode *temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(retour au début)\n");
}

// ==========================
// 5. Liste doublement circulaire
// ==========================
void insertHeadDC(DCNode **head, int data) {
    DCNode *newNode = createDCNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    DCNode *tail = (*head)->prev;
    newNode->next = *head;
    newNode->prev = tail;
    tail->next = newNode;
    (*head)->prev = newNode;
    *head = newNode;
}

void insertTailDC(DCNode **head, int data) {
    DCNode *newNode = createDCNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    DCNode *tail = (*head)->prev;
    newNode->next = *head;
    newNode->prev = tail;
    tail->next = newNode;
    (*head)->prev = newNode;
}

void displayDC(DCNode *head) {
    if (head == NULL) return;
    DCNode *temp = head;
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(retour au début)\n");
}

// ==========================
// Programme principal
// ==========================
int main() {
    Node *list = NULL;
    DNode *dlist = NULL;
    CNode *clist = NULL;
    DCNode *dclist = NULL;
    int choice, val;

    do {
        printf("\n===== MENU INF 231 =====\n");
        printf("1. Supprimer occurrences (liste simple)\n");
        printf("2. Insertion triée (liste simple)\n");
        printf("3. Insertion triée (liste double)\n");
        printf("4. Insertion tete/queue (liste circulaire simple)\n");
        printf("5. Insertion tete/queue (liste circulaire double)\n");
        
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Entrer valeur a inserer (liste simple) : ");
                scanf("%d", &val);
                insertSorted(&list, val);
                printf("Liste simple : ");
                display(list);

                printf("Entrer valeur a supprimer : ");
                scanf("%d", &val);
                deleteOccurrences(&list, val);
                printf("Liste apres suppression : ");
                display(list);
                break;

            case 2:
                printf("Entrer valeur a inserer (liste simple triee) : ");
                scanf("%d", &val);
                insertSorted(&list, val);
                printf("Liste simple triee : ");
                display(list);
                break;

            case 3:
                printf("Entrer valeur a inserer (liste double triee) : ");
                scanf("%d", &val);
                insertSortedD(&dlist, val);
                printf("Liste double triee : ");
                displayD(dlist);
                break;

            case 4:
                printf("1. Inserer tete | 2. Inserer queue : ");
                scanf("%d", &val);
                if (val == 1) {
                    printf("Entrer valeur : ");
                    scanf("%d", &val);
                    insertHeadC(&clist, val);
                } else {
                    printf("Entrer valeur : ");
                    scanf("%d", &val);
                    insertTailC(&clist, val);
                }
                printf("Liste circulaire simple : ");
                displayC(clist);
                break;

            case 5:
                printf("1. Inserer tete | 2. Inserer queue : ");
                scanf("%d", &val);
                if (val == 1) {
                    printf("Entrer valeur : ");
                    scanf("%d", &val);
                    insertHeadDC(&dclist, val);
                } else {
                    printf("Entrer valeur : ");
                    scanf("%d", &val);
                    insertTailDC(&dclist, val);
                }
                printf("Liste circulaire double : ");
                displayDC(dclist);
                break;

            case 0:
                printf("Fin du programme.\n");
                break;

            default:
                printf("Choix invalide !\n");
        }
    } while (choice != 0);

    return 0;
}

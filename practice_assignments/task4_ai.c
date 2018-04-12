#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct llist{
    int key;
    char info[265];
    struct llist * positive;
    struct llist * negative;
};
typedef struct llist llist;

struct llist_core{
    int size;
    llist * root;
};
typedef struct llist_core llist_core;

llist_core * create_list(){
    llist_core * list = (llist_core*) malloc(sizeof(llist_core));
    list->root = NULL;
    list->size = 0;
    return list;
}

void llist_search(llist_core * list){

}

int is_empty(llist_core * activelist){
    return  activelist->size == 0;
}

void insert_llist(llist_core * activelist, llist * current){
    char _answer[64];
    char _question[256];

    printf("Please give us the colour you were thinking of: ");
    scanf(" %[^\n]%*c", _answer);
    printf("\n\nPlease give a question that positively answers to your colour: ");
    scanf(" %[^\n]%*c", _question);

    if(is_empty(activelist) == 1){
        llist * node = (llist *) malloc(sizeof(llist));
        node->key = 2;
        strcpy(node->info, _answer);
        node->negative = node->positive = NULL;

        current = (llist *) malloc(sizeof(llist));
        current->key = 1;
        strcpy(current->info, _question);
        current->positive = node;
        current->negative = NULL;
        printf("%s", current->info);

        activelist->size = activelist->size + 2;
    }
    else{
        llist * node = (llist *) malloc(sizeof(llist));
        llist * nodenew = (llist *) malloc(sizeof(llist));

        node->key = activelist->size;
        strcpy(node->info, _question);
        printf("%s");
        node->negative = current;
        activelist->size++;

        nodenew->key = activelist->size;
        strcpy(nodenew->info, _answer);;
        nodenew->negative = nodenew->positive = NULL;

        current = node;
        printf("%s", current->info);

    }

}
/*struct bin_tree{
    int key;
    struct bin_tree * positive;
    struct bin_tree * negative;
};
typedef struct bin_tree bin_tree;

struct tree{
    bin_tree * root;
    int size;
};
typedef struct tree tree;

tree * create_tree(){
    tree * quiz = (tree *) malloc(sizeof(tree));
    quiz-> root = NULL;
    quiz-> size = 0;
    return quiz;
}
int is_empty(tree * quiz){
    return quiz->size == 0;
}
void insert_tree(bin_tree * curr){
    char *_answer[64];
    char *_question[256];

    printf("Please give us the colour you were thinking of: ");
    scanf("%s", _answer);
    printf("\n\nPlease give a question that positively answers to your colour: ");
    scanf("%s", _question);

    bin_tree * node = (bin_tree *) malloc(sizeof(bin_tree));
    node -> negative = curr;
    strcpy(node -> positive, _answer);
    strcpy(node -> key, _question);

    curr  = node;
}

*/
void guessing_game_main(){
    llist_core * activelist = create_list();
    llist * current = activelist->root;

    insert_llist(activelist, current);
}

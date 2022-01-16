#include "networking.h"

struct node {
    int fd1;
    int fd2;
    struct node *next;
};

struct node * insert_node(struct node* start, int fd1, int fd2);
struct node * search(struct node* start, int fd);
struct node * remove_node(struct node* start, struct node* node);
int opponent(struct node* start, int fd);
int main();

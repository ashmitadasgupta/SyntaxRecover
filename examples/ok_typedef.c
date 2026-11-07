#include <stdio.h>
#include <stddef.h>
typedef struct node {
 int value;
struct node *next;
} Node;
typedef enum { RED, GREEN = 5, BLUE } Color;
struct flags {
unsigned int ready : 1;
unsigned int mode : 3;
};
static size_t count(Node *head)
{
size_t n = 0;
while (head != NULL) {
n++;
head = head->next;
}
return n;
}
int main(void)
{
Node a;
Color c = GREEN;
a.value = (int)sizeof(Node);
printf("%d %d\n", a.value, c);
return 0;
}

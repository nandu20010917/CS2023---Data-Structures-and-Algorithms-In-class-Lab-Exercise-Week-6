#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 20
using namespace std;
using namespace std::chrono;

struct node {
    int data;
    struct node* link;
} *top = NULL;

void push(int data){
    struct node* newNode;
    newNode = new node;

    if (newNode == NULL)
    {
        printf("Stack Overflow");
        exit(1);
    }
    newNode->data = data;
    newNode->link = NULL;

    newNode->link = top;
    top = newNode;
}

int isEmpty(){
    if (top == NULL)
    return 1;
    else
    return 0;
}

int pop(){
    struct node* temp;
    int val;
    if(isEmpty()){
        printf("Stack Underflow");
        exit(1);
    }
    temp = top;
    val = temp->data;
    top = top->link;
    free(temp);
    temp = NULL;
    return val;
}

void display(){
    struct node* temp;
    temp = top;
    while (temp){
        printf("%d", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main(){
    auto start = high_resolution_clock::now();

    push(8);
    push(10);
    push(5);
    push(11);
    push(15);
    push(20);
    push(9);
    push(7);
    push(30);
    push(4);
    display();
    pop();
    pop();
    pop();
    pop();
    pop();
    display();
    push(9);
    push(10);
    push(18);
    push(42);
    display();

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

}

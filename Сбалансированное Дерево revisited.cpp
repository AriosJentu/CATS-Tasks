#include <iostream>
#include <algorithm>
#include <vector>
 
#define HASHSIZE 100000
#define MAXINT 9898989888

using namespace std;
 
typedef long long l_int;

typedef struct self {

    l_int data;
    struct self* next;

} list;
 
list* hash_tab[HASHSIZE];
 
int hash_func(l_int v) {
    return (v % HASHSIZE);
}
 
void append(list* head, l_int value) {

    while (true) {

        if (!head->next or head->next->data > value) {
            
            list* element = new list;
            element->data = value;
            element->next = head->next;
            head->next = element;
            return;

        } else if (head->next->data == value) {
            
            return;

        } else {

            head = head->next;
        }
    }
}
 
void remove(list* head, l_int data) {
    list* element; 
    list* tmp;

    element = head;
    
    while (element and element->data != data) {
        tmp = element;
        element = element->next;
    }
    
    if (!element) {

        return;
    } 
    if (element->data == data) {
        
        do {
        
            element = element->next;
            tmp->next = element;
            tmp = element;
        
        } while (element);
    
    } else {
        return;
    }
}
void answer(vector <l_int> &array){
    list* element;
    list* tmp = new list;
 
    for (int i = 0; i < HASHSIZE; i++) {

        tmp = hash_tab[i]->next;
        
        while (tmp) {
        
            array.push_back(tmp->data);
            element = tmp;
            tmp = element->next;
        }
    }
}
int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    l_int key;
    int hasht;
 
    for (int i = 0; i < HASHSIZE; i++) {

        hash_tab[i] = new list;
        hash_tab[i]->data = MAXINT;
        hash_tab[i]->next = NULL;
    
    }
 
    cin >> key;
    while (key) {

        hasht = hash_func(abs(key));
        
        if (key > 0) {
           
            append(hash_tab[hasht], key);
        
        } else if (key < 0) {

            remove(hash_tab[hasht], -key);
        }
        cin >> key;
    }
 
 
    vector <l_int> result;
    answer(result);

    if (result.size() > 0){
        sort(result.begin(), result.end());
        
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
    }
}
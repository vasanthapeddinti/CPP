#include <iostream>
using namespace std;

typedef struct Structure {
    int i;
    char c;
} Structure;

int main() {
    
    Structure s1;
    
    Structure* sp1 = (Structure*) malloc(sizeof(s1));
    sp1->i = 3;
    sp1->c = 'b';
    
    cout << sp1->i << endl;
    cout << sp1->c << endl;
    
    Structure s2;
    
    Structure* sp2 = &s2;
    
    sp2->i = 4;
    sp2->c = 'f';
    
    cout << sp2->i << endl;
    cout << sp2->c << endl;
    
}




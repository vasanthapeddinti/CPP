#include <iostream>
using namespace std;

struct Structure {
  int i;
  char c;
};

typedef struct Structure2{
    int j;
    char d;
}Structure2;


typedef struct Structure3 {
  int i;
  char c;
  Structure3* sr;
}Structure3;


int main() {

    struct Structure s1;
    s1.i = 19;
    s1.c = 'e';
    
    cout << s1.i << endl;
    cout << s1.c << endl;
    
    Structure2 s2;
    s2.j = 5;
    s2.d = 'f';
    
    cout << s2.j << endl;
    cout << s2.d << endl;
 
    Structure3 s3;
    Structure3 s4;
    
    
    s3.i = 56;
    s3.c = 'o';
    s3.sr = &s4;

    cout << s3.i << endl;
    cout << s3.c << endl;
    cout << s3.sr << endl;
    
    s4.i = 1234;
    s4.c = 't';
    s4.sr = &s3;
    
    
}




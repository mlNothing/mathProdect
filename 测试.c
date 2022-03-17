#include <stdio.h>
#include <stdlib.h>
int main(){
    sqQueue S;
    initSQ(&S);
    pushSQ(&S);
    pushSQ(&S);
    pushSQ(&S);
    pushSQ(&S);
    pushSQ(&S);
    while (isqueueempty(&S)==0)
    {
       popSQ(&S);
    }
    return 0;
}
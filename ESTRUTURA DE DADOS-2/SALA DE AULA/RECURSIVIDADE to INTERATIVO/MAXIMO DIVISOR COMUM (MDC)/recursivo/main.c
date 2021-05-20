#include <stdio.h>

int mdc(int x, int y){
    if((y <= x) && (x%y == 0)) return y;
    else if(x < y) return mdc(y, x);
    else return mdc(y, x%y);

}

int main(int argc, char** argv){
    printf("%d\n", mdc(30,42));
    return 0;
}

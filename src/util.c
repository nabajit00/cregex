#include "util.h"

char isOperator(char c){
    if(c == '*' || c == '|') return 1;
    return 0;
}
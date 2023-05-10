#ifndef REGEXIN_H
#define REGEXIN_H
#include "./parser.h"

//Internal

void goToNextNodes(Node *node,int *count,Node* nodeArr,int *pos,char *str);

char shouldGoToNextNode(Conn c,int count,int *pos, char *str);

void isEpsilon(Conn *conn);

void isCharMatch(Conn *conn, char ch);

#endif
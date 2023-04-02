#ifndef PARSER_H
#define PARSER_H
#include "./char.h"

struct Conn;

struct Node{
    struct Conn *conn1;
    struct Conn *conn2;
    char isFinal;
};
typedef struct Node Node;

struct Conn{
    char consumes;
    Node *next;
};
typedef struct Conn Conn;

//NFA structure
struct Parser{
    Node *startNode;
    Node *endNode;
};

typedef struct Parser Parser;

Parser* newSymbolParser(char chr){
    Node* node = newNode();
    Parser *parser = newParser();
    node->conn1 = newConn(chr);
    node->conn1->next = newNode();

    parser->startNode = node;
    parser->endNode = node->conn1->next;
    return parser;
}


/**
 * These new parsers frees parsers sent by param and returns a new one.
 */

Parser* newUnionParser(Parser *p1,Parser *p2);

Parser* newKleeneParser(Parser *p);

Parser* newConcatParser(Parser *p1,Parser *p2);

#endif
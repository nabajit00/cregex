/**
 * @file parser.c
 * @brief NFA parser
 * 
 */
#include "parser.h"
#include <stdlib.h>

Node* newNode(){
    Node *node = malloc(sizeof(Node));
    node->conn1 = NULL;
    node->conn2 = NULL;
    return node;
}

Conn* newConn(char chr){
    Conn* conn = malloc(sizeof(conn));
    conn->consumes = chr;
    return conn;
}

Parser* newParser(){
    return (Parser*)malloc(sizeof(Parser));
}

void epsilonTransition(Node *from, Node* to){
    Conn *conn = newConn(-1);
    conn->next = to;
    if(from->conn1 == NULL){
        from->conn1 = conn;
    }else{
        from->conn2 = conn;
    }
}

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

Parser* newUnionParser(Parser *p1,Parser *p2){
    Parser *parser = newParser();
    Node *newStartNode = newNode();
    Node *newEndNode = newNode();

    epsilonTransition(newStartNode,p1->startNode);
    epsilonTransition(newStartNode,p2->startNode);
    epsilonTransition(p1->endNode,newEndNode);
    epsilonTransition(p2->endNode,newEndNode);

    parser->startNode = newStartNode;
    parser->endNode = newEndNode;

    free(p1);
    free(p2);
    return parser;
}

Parser* newKleeneParser(Parser *p){
    Parser *parser = newParser();
    Node *newStartNode = newNode();
    Node *newEndNode = newNode();

    epsilonTransition(newStartNode,p->startNode);
    epsilonTransition(p->endNode,newEndNode);
    epsilonTransition(newStartNode,newEndNode);
    epsilonTransition(p->endNode,p->startNode);

    parser->startNode = newStartNode;
    parser->endNode = newEndNode;

    free(p);
    return parser;
}

Parser* newConcatParser(Parser *p1,Parser *p2){
    Parser *parser = newParser();

    epsilonTransition(p1->endNode,p2->startNode);

    free(p1);
    free(p2);

    return parser;
}
/**
 * @file postfix.c
 * @brief Shunting Yard Algorithm to convert regex expression string to postfix notation 
 */
#include<stdlib.h>
#include<string.h>
#include "./DS/stack/stack.h"
#include "./postfix.h"
/**
 * @brief Convert to postfix expression postfix
 * 
 * @param *charStruct 
 * @return *charStruct
 */
CharStruct* toPostfix(CharStruct *charStruct){
    int i=0,j;
    Char charT;
    Stack* stack = createStack(charStruct->len);
    CharStruct *postfixCharStruct = newCharStruct(charStruct->len);
    for(;i<charStruct->len;i++){
        charT = getChar(charStruct,i);
        if(charT.isSpecial){
            if(charT.ch == '(') stackPush(stack,i);
            
            else if(charT.ch == ')') {
                //add until (
                while(!isStackEmpty(stack)){
                    j = stackPop(stack);
                    charT = getChar(charStruct,j);
                    if(charT.ch == '(') break;
                    addChar(postfixCharStruct,charT.ch,charT.isSpecial);
                }
            }

            // * has higher precedance then |
            else if(charT.ch == '*'){
                //add until same or higher precendence operator or () met. (right now no higher precendence then *)
                if(getChar(charStruct,peekStack(stack)).ch != '*'){
                    stackPush(stack,i);
                    continue;1
                }
                while (!isStackEmpty(stack)){
                    j = stackPop(stack);
                    charT = getChar(charStruct,j);
                    if(charT.ch == '*') addChar(postfixCharStruct,charT.ch,charT.isSpecial);
                    else break;
                }
            } else if(charT.ch == '|'){
                //add until same or higher precendence operator or () met. right now * or itself |.
                if(getChar(charStruct,peekStack(stack)).ch != '*' || getChar(charStruct,peekStack(stack)).ch != '|'){
                    stackPush(stack,i);
                    continue;
                }
                while (!isStackEmpty(stack)){
                    j = stackPop(stack);
                    charT = getChar(charStruct,j);
                    if(charT.ch == '*' || charT.ch == '|') addChar(postfixCharStruct,charT.ch,charT.isSpecial);
                    else break;
                }
            }
        } else{
            addChar(postfixCharStruct,charT.ch,charT.isSpecial);
        }
    }
    while (!isStackEmpty(stack)){
        //add remaining
        j = stackPop(stack);
        charT = getChar(charStruct,j);
        addChar(postfixCharStruct,charT.ch,charT.isSpecial);
    }
    freeStack(stack);
    freeCharStruct(charStruct);
    return postfixCharStruct;
}
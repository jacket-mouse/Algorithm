//
// Created by l1491 on 2024/9/27.
//

#ifndef TOKEN_H
#define TOKEN_H
enum {
    T_PLUS, T_MINUS, T_STAR, T_SLASH, T_INTLIT
};
struct token {
    int token;
    int intvalue;
};
#endif //TOKEN_H

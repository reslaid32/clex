#include "ctok.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ctok_t ctok_make_token(ctok_type_t type, const char *start, size_t length) {
    ctok_t token;
    token.type = type;
    if (start && length > 0) {
        token.token.string = (char *)malloc(length + 1);
        if (token.token.string) {
            strncpy(token.token.string, start, length);
            token.token.string[length] = '\0';
            token.token.length = length;
        } else {
            // Handle allocation failure if needed
            token.token.length = 0;
        }
    } else {
        token.token.length = 0;
    }
    return token;
}

void ctok_display_token_type(ctok_type_t type) {
    switch (type) {
        case CTOK_TYPE_STRING:       printf("String");      break;
        case CTOK_TYPE_INTEGER:      printf("Integer");     break;
        case CTOK_TYPE_FLOAT:        printf("Float");       break;
        case CTOK_TYPE_IDENTIFIER:   printf("Identifier");  break;
        case CTOK_TYPE_KEYWORD:      printf("Keyword");     break;
        case CTOK_TYPE_OPERATOR:     printf("Operator");    break;
        case CTOK_TYPE_PUNCTUATION:  printf("Punctuation"); break;
        case CTOK_TYPE_COMMENT:      printf("Comment");     break;
        case CTOK_TYPE_WHITESPACE:   printf("Whitespace");  break;
        case CTOK_TYPE_NEWLINE:      printf("Newline");     break;
        case CTOK_TYPE_EOF:          printf("EOF");         break;
        default:                     printf("Unknown token"); break;
    }
}
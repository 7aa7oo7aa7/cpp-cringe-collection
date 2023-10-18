#include "cstring.h"

size_t Strlen(const char* str) {
    // '\0'
    size_t length = 0;
    for (size_t i = 0; str[i] != '\0'; ++i) {
        ++length;
    }
    return length;
}

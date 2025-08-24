#ifndef FIELD_INFO_H
#define FIELD_INFO_H

#include <stddef.h>
#include <stdlib.h>

typedef struct FieldInfo {

    void *(*create)();

    void (*free)(void* s);

    void *(*concat)(void* result, void* s1, void* s2);

    void *(*substring)(void* s, size_t start, size_t end);

    void (*find_sensitive)(void* s1, void* s2);

    void (*find_unsensitive)(void* s1, void* s2);

    void *(*print)(void* s);

} FieldInfo;


FieldInfo *setting(void *(*create)(),
                 void (*free)(void* s),
                 void *(*concat)(void* result, void* s1, void* s2),
                 void *(*substring)(void* s, size_t start, size_t end),
                 void (*find_sensitive)(void* s1, void* s2),
                 void (*find_unsensitive)(void* s1, void* s2),
                 void *(*print)(void* s));

#endif
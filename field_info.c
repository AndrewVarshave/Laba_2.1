#include "field_info.h"

FieldInfo *setting(void *(*create)(),
                 void (*free)(void* s),
                 void *(*concat)(void* result, void* s1, void* s2),
                 void *(*substring)(void* s, size_t start, size_t end),
                 void (*find_sensitive)(void* s1, void* s2),
                 void (*find_unsensitive)(void* s1, void* s2),
                 void *(*print)(void* s)) {

    FieldInfo  *info = (FieldInfo *) malloc(sizeof(FieldInfo));
    info->create = create;
    info->free = free;
    info->concat = concat;
    info->substring = substring;
    info->find_sensitive = find_sensitive;
    info->find_unsensitive = find_unsensitive;
    info->print = print;
    return info;

}

#pragma once

#include <stdint.h>

/* ECG_NODE: esprof_callgraph_node */
typedef struct _ECG_NODE {
    uint64_t time_total; /* accumulated time (ns) */
    uint64_t time_max; /* max time (ns) */
    uint64_t time_min; /* max time (ns) */
    uint64_t count; /* number of start/stop calls */
    uint64_t nrecurse; /* number of recursive start/stop calls */
    void     *address; /* Function address */
    struct _ECG_NODE *children;
    uint64_t nchildren;
} _ECG_NODE;

typedef struct {
    struct _ECG_NODE *parent;
    struct _ECG_NODE *current;
} _ECG_TLS;


#define _ECG_THREAD_ENTER(ADDRESS) \
    _ECG_TLS *__ecg_tls = _ecg_get_my_tls(); \
    __ecg_tls->parent = _ecg_alloc_nodes(2); \
    __ecg_tls->parent->address = NULL; \
    __ecg_tls->parent->children = __ecg_tls->parent + 1; \
    __ecg_tls->parent->nchildren = 1; \
    __ecg_tls->current = __ecg_tls->parent->children; \
    __ecg_tls->current->address = ADDRESS; \
    __ecg_tls->current->count = 1; \
    __ecg_tls->current->time_min = _ecg_get_time();

#define _ECG_THREAD_EXIT() \
    __ecg_tls->current = __ecg_tls->parent->children; \
    __ecg_tls->current->time_total = _ecg_get_time() - __ecg_tls->current->time_min; \
    __ecg_tls->current->time_min = __ecg_tls->current->time_total; \
    __ecg_tls->current->time_max = __ecg_tls->current->time_total;

#define _ECG_FUNCTION_ENTER(ADDRESS, NCHILDREN, INIT_CODE) \
    bool __ecg_skip = true; /* skip by default */ \
    _ECG_TLS *__ecg_tls = _ecg_get_my_tls(); \
    _ECG_NODE *__ecg_parent = __ecg_tls->parent; \
    _ECG_NODE *__ecg_children; /* only used when not skip */ \
    if (__ecg_parent->address == (ADDRESS)) { \
        __ecg_parent->nrecurse++; \
    } else if (__ecg_tls->current->address == (ADDRESS)) { /* Necessary if two calls in the same line */ \
        _ECG_NODE *__ecg_current = __ecg_tls->current; \
        if (__ecg_current->children == NULL) { \
            __ecg_current->children = _ecg_alloc_nodes((NCHILDREN)); \
            __ecg_current->nchildren = (NCHILDREN); \
            for (uint64_t i = 0; i < (NCHILDREN); i++) { \
                __ecg_current->children[i].time_min = 0xffffffffffffffffU; \
            } {INIT_CODE;} \
        } \
        __ecg_skip = false; \
        __ecg_tls->parent = __ecg_current; \
        __ecg_children = __ecg_current->children; \
    }

#define _ECG_FUNCTION_EXIT() \
    if (!__ecg_skip) { \
        __ecg_tls->parent = __ecg_parent; \
    }

#define _ECG_CALLEE_BEFORE(INDEX) \
    { \
        _ECG_NODE *__ecg_child; \
        uint64_t __ecg_time_start; \
        if (!__ecg_skip) { \
            __ecg_time_start = _ecg_get_time(); \
            __ecg_child = &__ecg_children[INDEX]; \
            __ecg_child->count++; \
            __ecg_tls->current = __ecg_child; \
        }

#define _ECG_CALLEE_AFTER() \
        if (!__ecg_skip) { \
            uint64_t __ecg_time = _ecg_get_time() - __ecg_time_start; \
            __ecg_child->time_total += __ecg_time; \
            if (__ecg_time > __ecg_child->time_max) __ecg_child->time_max = __ecg_time; \
            if (__ecg_time < __ecg_child->time_min) __ecg_child->time_min = __ecg_time; \
        } \
    }

// Required Interface
#if !defined(_ECG_OMIT_INTERFACE)
_ECG_TLS  *_ecg_get_my_tls();
_ECG_NODE *_ecg_alloc_nodes(uint64_t num);
uint64_t   _ecg_get_time();
#endif


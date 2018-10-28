#pragma once

#define _ECG_OMIT_INTERFACE
#include "../esprof-callgraph-common.h"

// Implemented Interface
#ifdef __cplusplus
extern "C" {
#endif

static inline _ECG_TLS *_ecg_get_my_tls() {
	return (_ECG_TLS*)(__insn_mfspr(0x2383/*SPR_SAVE_P_RUNTSK*/) + 72U);
}

static inline uint64_t _ecg_get_time() { // can be any unit, ns is recommend.
    return __insn_mfspr(0x2781/*SPR_CYCLE*/);
}

_ECG_NODE *_ecg_alloc_nodes(uint64_t num);

#ifdef __cplusplus
}
#endif


/**
 * PARSEC helper for TOPPERS/FMP Kernel
 *
 * Copyright (C) 2016 by Yixiao Li (liyixiao@ertl.jp)
 *
 *  The above copyright holders grant permission gratis to use,
 *  duplicate, modify, or redistribute (hereafter called use) this
 *  software (including the one made by modifying this software),
 *  provided that the following four conditions (1) through (4) are
 *  satisfied.
 *
 *  (1) When this software is used in the form of source code, the above
 *      copyright notice, this use conditions, and the disclaimer shown
 *      below must be retained in the source code without modification.
 *
 *  (2) When this software is redistributed in the forms usable for the
 *      development of other software, such as in library form, the above
 *      copyright notice, this use conditions, and the disclaimer shown
 *      below must be shown without modification in the document provided
 *      with the redistributed software, such as the user manual.
 *
 *  (3) When this software is redistributed in the forms unusable for the
 *      development of other software, such as the case when the software
 *      is embedded in a piece of equipment, either of the following two
 *      conditions must be satisfied:
 *
 *    (a) The above copyright notice, this use conditions, and the
 *        disclaimer shown below must be shown without modification in
 *        the document provided with the redistributed software, such as
 *        the user manual.
 *
 *    (b) How the software is to be redistributed must be reported to the
 *        TOPPERS Project according to the procedure described
 *        separately.
 *
 *  (4) The above copyright holders and the TOPPERS Project are exempt
 *      from responsibility for any type of damage directly or indirectly
 *      caused from the use of this software and are indemnified by any
 *      users or end users of this software from any and all causes of
 *      action whatsoever.
 *
 *  THIS SOFTWARE IS PROVIDED "AS IS." THE ABOVE COPYRIGHT HOLDERS AND
 *  THE TOPPERS PROJECT DISCLAIM ANY EXPRESS OR IMPLIED WARRANTIES,
 *  INCLUDING, BUT NOT LIMITED TO, ITS APPLICABILITY TO A PARTICULAR
 *  PURPOSE. IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS AND THE
 *  TOPPERS PROJECT BE LIABLE FOR ANY TYPE OF DAMAGE DIRECTLY OR
 *  INDIRECTLY CAUSED FROM THE USE OF THIS SOFTWARE.
 */

#include <kernel.h>
#include <t_syslog.h>
#include "hv/hypervisor.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "kernel/kernel_impl.h"
#include "esprof-callgraph.h"

#define NODES_PER_CORE (1024)
#define MAX_THREADS_PER_CORE (128)

typedef struct nodes_control_block {
    _ECG_NODE *current;
    uint64_t  left;
    uint64_t  nthread;
    _ECG_NODE *threads[MAX_THREADS_PER_CORE];
} _ECG_NCB;

/* [[[cog
import cog, pass0
for i in range(1, pass0.core_number + 1):
    cog.outl(f'static _ECG_NODE nodes_prc{i}[NODES_PER_CORE] __attribute__ ((section(".local_cached_prc{i}.bss")));')
cog.outl(f'static _ECG_NCB ncb_table[{pass0.core_number}] = {{')
for i in range(1, pass0.core_number + 1):
    cog.outl(f'    {{nodes_prc{i}, NODES_PER_CORE}},')
cog.outl(f'}};')
]]] */
static _ECG_NODE nodes_prc1[NODES_PER_CORE] __attribute__ ((section(".local_cached_prc1.bss")));
static _ECG_NODE nodes_prc2[NODES_PER_CORE] __attribute__ ((section(".local_cached_prc2.bss")));
static _ECG_NODE nodes_prc3[NODES_PER_CORE] __attribute__ ((section(".local_cached_prc3.bss")));
static _ECG_NODE nodes_prc4[NODES_PER_CORE] __attribute__ ((section(".local_cached_prc4.bss")));
static _ECG_NODE nodes_prc5[NODES_PER_CORE] __attribute__ ((section(".local_cached_prc5.bss")));
static _ECG_NODE nodes_prc6[NODES_PER_CORE] __attribute__ ((section(".local_cached_prc6.bss")));
static _ECG_NODE nodes_prc7[NODES_PER_CORE] __attribute__ ((section(".local_cached_prc7.bss")));
static _ECG_NODE nodes_prc8[NODES_PER_CORE] __attribute__ ((section(".local_cached_prc8.bss")));
static _ECG_NODE nodes_prc9[NODES_PER_CORE] __attribute__ ((section(".local_cached_prc9.bss")));
static _ECG_NODE nodes_prc10[NODES_PER_CORE] __attribute__ ((section(".local_cached_prc10.bss")));
static _ECG_NODE nodes_prc11[NODES_PER_CORE] __attribute__ ((section(".local_cached_prc11.bss")));
static _ECG_NODE nodes_prc12[NODES_PER_CORE] __attribute__ ((section(".local_cached_prc12.bss")));
static _ECG_NODE nodes_prc13[NODES_PER_CORE] __attribute__ ((section(".local_cached_prc13.bss")));
static _ECG_NODE nodes_prc14[NODES_PER_CORE] __attribute__ ((section(".local_cached_prc14.bss")));
static _ECG_NODE nodes_prc15[NODES_PER_CORE] __attribute__ ((section(".local_cached_prc15.bss")));
static _ECG_NODE nodes_prc16[NODES_PER_CORE] __attribute__ ((section(".local_cached_prc16.bss")));
static _ECG_NODE nodes_prc17[NODES_PER_CORE] __attribute__ ((section(".local_cached_prc17.bss")));
static _ECG_NODE nodes_prc18[NODES_PER_CORE] __attribute__ ((section(".local_cached_prc18.bss")));
static _ECG_NODE nodes_prc19[NODES_PER_CORE] __attribute__ ((section(".local_cached_prc19.bss")));
static _ECG_NODE nodes_prc20[NODES_PER_CORE] __attribute__ ((section(".local_cached_prc20.bss")));
static _ECG_NODE nodes_prc21[NODES_PER_CORE] __attribute__ ((section(".local_cached_prc21.bss")));
static _ECG_NODE nodes_prc22[NODES_PER_CORE] __attribute__ ((section(".local_cached_prc22.bss")));
static _ECG_NODE nodes_prc23[NODES_PER_CORE] __attribute__ ((section(".local_cached_prc23.bss")));
static _ECG_NODE nodes_prc24[NODES_PER_CORE] __attribute__ ((section(".local_cached_prc24.bss")));
static _ECG_NODE nodes_prc25[NODES_PER_CORE] __attribute__ ((section(".local_cached_prc25.bss")));
static _ECG_NODE nodes_prc26[NODES_PER_CORE] __attribute__ ((section(".local_cached_prc26.bss")));
static _ECG_NODE nodes_prc27[NODES_PER_CORE] __attribute__ ((section(".local_cached_prc27.bss")));
static _ECG_NODE nodes_prc28[NODES_PER_CORE] __attribute__ ((section(".local_cached_prc28.bss")));
static _ECG_NODE nodes_prc29[NODES_PER_CORE] __attribute__ ((section(".local_cached_prc29.bss")));
static _ECG_NODE nodes_prc30[NODES_PER_CORE] __attribute__ ((section(".local_cached_prc30.bss")));
static _ECG_NODE nodes_prc31[NODES_PER_CORE] __attribute__ ((section(".local_cached_prc31.bss")));
static _ECG_NODE nodes_prc32[NODES_PER_CORE] __attribute__ ((section(".local_cached_prc32.bss")));
static _ECG_NODE nodes_prc33[NODES_PER_CORE] __attribute__ ((section(".local_cached_prc33.bss")));
static _ECG_NODE nodes_prc34[NODES_PER_CORE] __attribute__ ((section(".local_cached_prc34.bss")));
static _ECG_NODE nodes_prc35[NODES_PER_CORE] __attribute__ ((section(".local_cached_prc35.bss")));
static _ECG_NODE nodes_prc36[NODES_PER_CORE] __attribute__ ((section(".local_cached_prc36.bss")));
static _ECG_NCB ncb_table[36] = {
    {nodes_prc1, NODES_PER_CORE},
    {nodes_prc2, NODES_PER_CORE},
    {nodes_prc3, NODES_PER_CORE},
    {nodes_prc4, NODES_PER_CORE},
    {nodes_prc5, NODES_PER_CORE},
    {nodes_prc6, NODES_PER_CORE},
    {nodes_prc7, NODES_PER_CORE},
    {nodes_prc8, NODES_PER_CORE},
    {nodes_prc9, NODES_PER_CORE},
    {nodes_prc10, NODES_PER_CORE},
    {nodes_prc11, NODES_PER_CORE},
    {nodes_prc12, NODES_PER_CORE},
    {nodes_prc13, NODES_PER_CORE},
    {nodes_prc14, NODES_PER_CORE},
    {nodes_prc15, NODES_PER_CORE},
    {nodes_prc16, NODES_PER_CORE},
    {nodes_prc17, NODES_PER_CORE},
    {nodes_prc18, NODES_PER_CORE},
    {nodes_prc19, NODES_PER_CORE},
    {nodes_prc20, NODES_PER_CORE},
    {nodes_prc21, NODES_PER_CORE},
    {nodes_prc22, NODES_PER_CORE},
    {nodes_prc23, NODES_PER_CORE},
    {nodes_prc24, NODES_PER_CORE},
    {nodes_prc25, NODES_PER_CORE},
    {nodes_prc26, NODES_PER_CORE},
    {nodes_prc27, NODES_PER_CORE},
    {nodes_prc28, NODES_PER_CORE},
    {nodes_prc29, NODES_PER_CORE},
    {nodes_prc30, NODES_PER_CORE},
    {nodes_prc31, NODES_PER_CORE},
    {nodes_prc32, NODES_PER_CORE},
    {nodes_prc33, NODES_PER_CORE},
    {nodes_prc34, NODES_PER_CORE},
    {nodes_prc35, NODES_PER_CORE},
    {nodes_prc36, NODES_PER_CORE},
};
/* [[[end]]] */

_ECG_NODE *_ecg_alloc_nodes(uint64_t num) {
    _ECG_NODE *rv = NULL;
	SIL_PRE_LOC;
	SIL_LOC_INT();
    _ECG_NCB *p_ncb = &ncb_table[x_prc_index()];
    if (p_ncb->left > num) {
        rv = p_ncb->current;
        p_ncb->current += num;
        p_ncb->left -= num;
    }
	SIL_UNL_INT();
    assert(rv != NULL);
    return rv;
}


static char profiler_log[1024 * 1024];
static char *profiler_log_pointer;

#define fprintf(fp,...) do { \
    int bytes = sprintf(profiler_log_pointer, __VA_ARGS__); \
    profiler_log_pointer += bytes; \
} while(0)
#define printf(...) fprintf(NULL, __VA_ARGS__)


static double cyc2sec;
static uint64_t total_calls;

static void print_node_tree(_ECG_NODE *root, int level) {
    static char buf[128];
    char *p_buf = buf;
    for (int i = 0; i < level; i++) {
        p_buf += sprintf(p_buf, "  ");
    }
    if (root->count == 0) {
        root->time_min = 0;
        return; // NOTE: ignore
    }
    total_calls += root->count;
    printf("%s%x %lu %lu %8.2e %8.2e %8.2e\n", buf, root->address, root->count, root->nrecurse, root->time_total * cyc2sec, root->time_max * cyc2sec, root->time_min * cyc2sec);
    for (int i = 0; i < root->nchildren; i++) {
        print_node_tree(root->children + i, level + 1);
    }
}

void _ecg_dump() {
    profiler_log_pointer = profiler_log;
    cyc2sec = 1.0 / hv_sysconf(HV_SYSCONF_CPU_SPEED);
    int n = 0;
    for (int core = 0; core < 36; core++) {
        _ECG_NODE *node = ncb_table[core].current - (NODES_PER_CORE - ncb_table[core].left);
        for(; node < ncb_table[core].current; node++) {
            if (node->address == NULL) {
                printf("Stats for thread %d:\n", n);
                printf("           Called  Recurse Wallclock max       min      \n");
                total_calls = 0;
                print_node_tree(node->children, 1);
                printf("Total calls  = %lu\n", total_calls);
                n++;
            }
        }
    }
    syslog(LOG_NOTICE, "%s", profiler_log);
}

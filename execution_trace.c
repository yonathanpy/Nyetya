#include "execution_trace.h"
#include <stdio.h>
#include <time.h>

void trace_init() {
    printf("[TRACE] initialized\n");
}

void trace_log(const char *module, const char *event) {
    time_t t = time(NULL);
    printf("[TRACE][%ld][%s] %s\n", t, module, event);
}

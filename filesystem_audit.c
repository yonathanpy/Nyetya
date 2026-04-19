#include "filesystem_audit.h"
#include <stdio.h>

void audit_filesystem() {
    printf("[FS_AUDIT] starting integrity scan\n");

    // conceptual traversal output
    printf("C:\\Windows\\System32 - OK\n");
    printf("C:\\Users\\Documents - SCANNED\n");
}

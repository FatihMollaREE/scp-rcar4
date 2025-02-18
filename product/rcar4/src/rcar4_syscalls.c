/*
*
* License
*
*/

#include <fwk_arch.h>
#include <fwk_macros.h>

#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#if FWK_HAS_INCLUDE(<sys / features.h>)
#    include <sys/features.h>
#endif

extern char __HEAP_START__;
extern char __HEAP_END__;

/*!
 * \brief Architecture memory manager context.
 */
static struct arch_mm_ctx {
    uintptr_t heap_break;
    uintptr_t heap_end;
} arch_mm_ctx = {
    .heap_break = (uintptr_t)(&__HEAP_START__),
    .heap_end = (uintptr_t)(&__HEAP_END__),
};

int _write(int file, char *ptr, int len) {
    return len;  // Placeholder für den Schreibvorgang
}

int _close(int file) {
    return -1;  // Placeholder für das Schließen
}

int _lseek(int file, int ptr, int dir) {
    return 0;  // Placeholder für die Datei-Offset-Bewegung
}

int _read(int file, char *ptr, int len) {
    return 0;  // Placeholder für das Lesen
}

void *_sbrk(intptr_t increment)
{
    if (increment == 0) {
        return (void *)arch_mm_ctx.heap_break;
    } else {
        uintptr_t heap_old = FWK_ALIGN_NEXT(arch_mm_ctx.heap_break, 16);
        uintptr_t heap_new = heap_old + increment;

        if (heap_new > arch_mm_ctx.heap_end) {
            return (void *)-1;
        } else {
            arch_mm_ctx.heap_break = heap_new;

            return (void *)heap_old;
        }
    }
}

void _exit(int status) {
    while (1);  // Endlosschleife als Abbruch
}

int _fstat(int file, int *st) {
    return 0;  // Placeholder für die Dateistatistik
}

int _isatty(int file) {
    return 1;  // Placeholder: immer als Terminal
}

int _kill(int pid, int sig) {
    return -1;  // Placeholder für den Kill-Aufruf
}

int _getpid(void) {
    return 1;  // Placeholder: Rückgabe einer fiktiven PID
}

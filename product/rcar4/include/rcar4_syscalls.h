#ifndef SYSCALLS_H
#define SYSCALLS_H

//#include <sys/stat.h>  // Für die Verwendung von struct stat

// Deklarationen der Systemaufruf-Stubs
int _write(int file, char *ptr, int len);
int _close(int file);
int _lseek(int file, int ptr, int dir);
int _read(int file, char *ptr, int len);
void *_sbrk(int incr);
void _exit(int status);
int _fstat(int file, struct stat *st);
int _isatty(int file);
int _kill(int pid, int sig);
int _getpid(void);

#endif // SYSCALLS_H

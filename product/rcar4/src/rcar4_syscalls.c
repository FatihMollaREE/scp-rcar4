/*
*
* License
*
*/

#include <unistd.h>

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

void *_sbrk(int incr) {
    return (void *)-1;  // Placeholder für den Speicherzuwachs
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

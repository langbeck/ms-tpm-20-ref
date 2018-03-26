#include "windows.h"
#include "winsock.h"
#include <pthread.h>

HANDLE CreateThread(LPVOID attr, DWORD stack, LPVOID start, LPVOID param, DWORD flags, LPDWORD tid) {
    pthread_t thr;
    if (pthread_create(&thr, NULL, start, param)) {
        return 0;
    }

    return (HANDLE) thr;
}

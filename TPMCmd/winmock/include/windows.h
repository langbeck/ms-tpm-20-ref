#ifndef _WINDOWS_H
#define _WINDOWS_H

#include <stdint.h>


#define RpcMgmtStopServerListening(a0)    (0)
#define RpcServerUnregisterIf(a0, a1, a2) (0)

#define WINAPI

typedef uint16_t        WORD;
typedef uint32_t        DWORD;
typedef DWORD          *LPDWORD;
typedef void           *LPVOID;
typedef void           *LPTHREAD_START_ROUTINE;


typedef uint8_t     BOOL;
typedef uint8_t     BYTE;
typedef int32_t     INT32;
typedef uint32_t    UINT32;
typedef uintptr_t   INT_PTR;
typedef LPVOID      HANDLE;
#define FALSE 0
#define TRUE  1

typedef int         RPC_STATUS;
#define RPC_S_OK    0

#define ZeroMemory(dst, len)    memset((dst), 0, (len))


HANDLE CreateThread(LPVOID attr, DWORD stack, LPVOID start, LPVOID param, DWORD flags, LPDWORD tid);

#endif /* _WINDOWS_H */

#ifndef _WINSOCK_H
#define _WINSOCK_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include "windows.h"

#define SOCKET_ERROR    (-1)
#define INVALID_SOCKET  (-1)

typedef struct{} WSADATA;
typedef WSADATA *LPWSADATA;

#define WSAStartup(a0, a1)  (0)
#define WSAGetLastError()   (errno)
#define closesocket(s)      (close(s))

#endif // _WINSOCK_H

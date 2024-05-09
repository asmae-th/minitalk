#include "minitalk.h"


// int main()
// {
//     int j = 0;
//     while (j < 8)
//     {
//         printf(" client %d\n", (72 >> j) & 1);
//         j++;
//     }
//     // printf(" srveur %d\n", (0 << 1));
//     //  printf(" srveur2 %d\n", (1 << 1) | 1);

// }

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handle_signal(int signal) {
  if (signal == SIGUSR1)
    {
        write(STDOUT_FILENO, "ana 0\n", 6);
    }
    else if (signal == SIGUSR2)
    {
        write(STDOUT_FILENO, "ana 1\n", 6);
    }
    else
    printf("hta wahd");
}

int main() {
    struct sigaction sa;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sa.sa_handler = handle_signal;

       printf("Je suis le serveur, mon PID est : %d\n", getpid());
    while (1) {
        sigaction(SIGUSR1, &sa, NULL);
    }

    return 0;
}

// Voici comment cela fonctionne pour le caractère "H" :

// 1ère itération (j = 0) :

// current_char >> j : 01001000 >> 0 = 01001000
// (current_char >> j) & 1 : 01001000 & 00000001 = 00000000 (bit 0)
// 2ème itération (j = 1) :

// current_char >> j : 01001000 >> 1 = 00100100
// (current_char >> j) & 1 : 00100100 & 00000001 = 00000000 (bit 0)
// 3ème itération (j = 2) :

// current_char >> j : 01001000 >> 2 = 00010010
// (current_char >> j) & 1 : 00010010 & 00000001 = 00000000 (bit 0)
// 4ème itération (j = 3) :

// current_char >> j : 01001000 >> 3 = 00001001
// (current_char >> j) & 1 : 00001001 & 00000001 = 00000001 (bit 1)
// 5ème itération (j = 4) :

// current_char >> j : 01001000 >> 4 = 00000100
// (current_char >> j) & 1 : 00000100 & 00000001 = 00000000 (bit 0)
// 6ème itération (j = 5) :

// current_char >> j : 01001000 >> 5 = 00000010
// (current_char >> j) & 1 : 00000010 & 00000001 = 00000000 (bit 0)
// 7ème itération (j = 6) :

// current_char >> j : 01001000 >> 6 = 00000001
// (current_char >> j) & 1 : 00000001 & 00000001 = 00000001 (bit 1)
// 8ème itération (j = 7) :

// current_char >> j : 01001000 >> 7 = 00000000
// (current_char >> j) & 1 : 00000000 & 00000001 = 00000000 (bit 0)
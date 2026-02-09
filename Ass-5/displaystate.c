#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

void print(int fd);

int main()
{
    int ret = fork();

    if (ret > 0) {
        // parent
        sleep(50);
        printf("child is zombie\n");

        int ret2 = fork();

        if (ret2 > 0) {
            // parent exits
            return 0;
        }
        else if (ret2 == 0) {
            // child2 (orphan checker)

            int pid1 = getppid();
            sleep(2);
            int pid2 = getppid();

            if (pid1 != pid2) {
                char ps[16];
                char file[64] = "/proc/";

                snprintf(ps, sizeof(ps), "%d", getpid());
                strcat(file, ps);
                strcat(file, "/status");

                int fd_1 = open(file, O_RDONLY);
                if (fd_1 >= 0) {
                    print(fd_1);
                    close(fd_1);
                }
            }
        }
    }
    else if (ret == 0) {
        // child
        printf("The parent pid is -> %d\n", getppid());

        char ps[16];
        char file[64] = "/proc/";

        snprintf(ps, sizeof(ps), "%d", getpid());
        strcat(file, ps);
        strcat(file, "/status");

        int fd_1 = open(file, O_RDONLY);
        if (fd_1 >= 0) {
            print(fd_1);
            close(fd_1);
        }

        sleep(25);
    }

    return 0;
}

void print(int fd)
{
    char buf[256];
    int bytes, lines = 0;

    while ((bytes = read(fd, buf, sizeof(buf))) > 0) {
        for (int i = 0; i < bytes; i++) {
            write(STDOUT_FILENO, &buf[i], 1);

            if (buf[i] == '\n') {
                lines++;
                if (lines == 3)
                    return;   // print only 3 lines
            }
        }
    }
}


#include <errno.h>
#include <stdio.h>
#include <sys/sysmacros.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
        errno = 0;

	unsigned long dev = makedev(1, 7);


        syscall(__NR_mknod, "mknod.c", S_IFCHR | 024, dev);

        if (errno != EEXIST) {
                perror("mknod");
                exit(1);
        }

        return 0;
}

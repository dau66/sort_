#include <libc.h>

__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}

int main()
{
	char *s;

    s = "hello world";
    puts(s);
	// free(s);
	// s = NULL;
    return (0);
}
#include <stdio.h>
#include <string.h>

#ifndef PROJ_NAME
#define PROJ_NAME "program"
#endif

void arg_help(void)
{
#ifdef COPYRIGHT
	printf("%s\n", COPYRIGHT);
#endif
#ifdef GIT_ORIGIN
	printf("origin: %s\n\n", GIT_ORIGIN);
#endif
	printf("Usage: %s [options] <file>\nOptions:\n", PROJ_NAME);
	printf(" -h/--help\t\tDisplay this message.\n");
	printf(" -v/--version\t\tDisplays version info.\n");
}

void arg_version(void)
{
#ifdef COPYRIGHT
	printf("%s\n", COPYRIGHT);
#endif
#ifdef BUILD
	printf("BUILD:\t\t%s\n", BUILD);
#endif
#ifdef BUILD_TIME
	printf("BUILD_TIME:\t%s\n", BUILD_TIME);
#endif
#ifdef GIT_VERSION
	printf("VERSION:\t%s\n", GIT_VERSION);
#endif
#ifdef GIT_ORIGIN
	printf("ORIGIN:\t\t%s\n", GIT_ORIGIN);
#endif
#ifdef DEFINES_STRING
	printf("%s\n", DEFINES_STRING);
#endif
}

int main(int argc, char **argv)
{
    if (argc <= 1) 
	{
		arg_help();
		return 0;
	}
	
	for (int i = 1; i < argc; i++)
	{
		if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0)
		{
			arg_help();
			return 0;
		}
		else if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--version") == 0)
		{
			arg_version();
			return 0;
		}
		else
		{
			printf("invalid argument: %s\n", argv[i]);
			return 1;
		}
	}

    return 0;
}
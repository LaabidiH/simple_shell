#include "shell.h"
#include <cstdio>
#include <cstring>
#include <unistd.h>

int myExit(info_t *info)
{
    int exitCheck;

    if (info->argv[1]) {
        exitCheck = std::stoi(info->argv[1]);
        if (exitCheck == -1) {
            info->status = 2;
            printf("Illegal number: %s\n", info->argv[1]);
            return 1;
        }
        info->errNum = std::stoi(info->argv[1]);
        return -2;
    }
    info->errNum = -1;
    return -2;
}

int myCd(info_t *info)
{
    char *currentDir, *dir, buffer[1024];
    int chdirRet;

    currentDir = getcwd(buffer, 1024);
    if (!currentDir)
        printf("TODO: >>getcwd failure emsg here<<\n");
    if (!info->argv[1]) {
        dir = getenv(info, "HOME=");
        if (!dir)
            chdirRet = chdir((dir = getenv(info, "PWD=")) ? dir : "/");
        else
            chdirRet = chdir(dir);
    } else if (strcmp(info->argv[1], "-") == 0) {
        if (!getenv(info, "OLDPWD=")) {
            printf("%s\n", currentDir);
            return 1;
        }
        printf("%s\n", getenv(info, "OLDPWD="));
        chdirRet = chdir((dir = getenv(info, "OLDPWD=")) ? dir : "/");
    } else {
        chdirRet = chdir(info->argv[1]);
    }
    if (chdirRet == -1) {
        printf("can't cd to %s\n", info->argv[1]);
    } else {
        setenv(info, "OLDPWD", getenv(info, "PWD="));
        setenv(info, "PWD", getcwd(buffer, 1024));
    }
    return 0;
}

int myHelp(info_t *info)
{
    char **argArray;

    argArray = info->argv;
    printf("help call works. Function not yet implemented\n");
    if (0)
        printf("%s\n", *argArray); // temp att_unused workaround
    return 0;
}

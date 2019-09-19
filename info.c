#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "info.h"

void
createfile(char *path)
{
    FILE *file = fopen(path, "w");
    fprintf(file, "0");
    fclose(file);
}

void
initinfodir()
{
    char *dirs[3] = {"/tmp/info/wm", "/tmp/info/wm/borders", "/tmp/info/wm/groups"};
    for (int i = 0; i < 3; i++) {
    puts("creating dir");
        mkdir(dirs[i], 0777);
    }

    char *bor[3] = {"size", "selcol", "normcol"};
    char buf[256];
    for (int i = 0; i < 3; i++) {
        snprintf(buf, sizeof buf, "/tmp/info/wm/borders/%s", bor[i]);
        snprintf(buf, sizeof buf, "/tmp/info/wm/borders/o%s", bor[i]);
        createfile(buf);
    puts("creating borders");
    }

    puts("creating groups");
    createfile("/tmp/info/wm/groups/num");
}

/* internal borders */

void
infobordersize(int bordersize)
{
    FILE* file = fopen("/tmp/info/wm/borders/size", "w");
    fprintf(file, "%d", bordersize);
    fclose(file);
}

void
infoborderselcol(int col)
{
    FILE* file = fopen("/tmp/info/wm/borders/selcol", "w");
    fprintf(file, "#%x", col);
    fclose(file);
}

void
infobordernormcol(int col)
{
    FILE* file = fopen("/tmp/info/wm/borders/normcol", "w");
    fprintf(file, "#%x", col);
    fclose(file);
}

/* external borders */

void
infoobordersize(int bordersize)
{
    FILE* file = fopen("/tmp/info/wm/borders/osize", "w");
    fprintf(file, "%d", bordersize);
    fclose(file);
}

void
infooborderselcol(int col)
{
    FILE* file = fopen("/tmp/info/wm/borders/oselcol", "w");
    fprintf(file, "#%x", col);
    fclose(file);
}

void
infoobordernormcol(int col)
{
    FILE* file = fopen("/tmp/info/wm/borders/onormcol", "w");
    fprintf(file, "#%x", col);
    fclose(file);
}

void
infosetgroupnum(int num)
{
    FILE* file = fopen("/tmp/info/wm/groups/num", "w");
    fprintf(file, "%d", num);
    fclose(file);
}

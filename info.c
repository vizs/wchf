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
    for (int i = 0; i < 3; i++)
        mkdir(dirs[i], 0777);

    char *bor[3] = {"size", "selcol", "normcol"};
    char buf[256];
    for (int i = 0; i < 3; i++) {
        snprintf(buf, sizeof buf, "/tmp/info/wm/borders/%s", bor[i]);
        createfile(buf);
    }

    char *grp[2] = {"num", "cur"};
    for (int i = 0; i < 2; i++) {
        snprintf(buf, sizeof buf, "/tmp/info/wm/groups/%s", grp[i]);
        createfile(buf);
    }
}

void
infobordersize(int bordersize)
{
    FILE *file = fopen("/tmp/info/wm/borders/size", "w");
    fprintf(file, "%d", bordersize);
    fclose(file);
}

void
infoborderselcol(int col)
{
    FILE *file = fopen("/tmp/info/wm/borders/selcol", "w");
    fprintf(file, "#%x", col);
    fclose(file);
}

void
infobordernormcol(int col)
{
    FILE *file = fopen("/tmp/info/wm/borders/normcol", "w");
    fprintf(file, "#%x", col);
    fclose(file);
}

void
infosetgroupnum(int num)
{
    FILE *file = fopen("/tmp/info/wm/groups/num", "w");
    fprintf(file, "%d", num);
    fclose(file);
}

void
infosetactivegroup(int num)
{
    FILE *file = fopen("/tmp/info/wm/groups/cur", "w");
    fprintf(file, "%d", num);
    fclose(file);
}

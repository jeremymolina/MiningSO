//
// Created by jeremymolina on 11/4/19.
//

#ifndef MININGSO_CPU_H
#define MININGSO_CPU_H

#include <cstdio>
#include <cstdlib>

int getCpuUsage(void)
{
    long double a[4], b[4], loadavg, calcGB;
    FILE *fp;

        fp = fopen("/proc/stat","r");
        fscanf(fp,"%*s %Lf %Lf %Lf %Lf",&b[0],&b[1],&b[2],&b[3]);
        fclose(fp);

        loadavg = ((b[0]+b[1]+b[2]) - (a[0]+a[1]+a[2])) / ((b[0]+b[1]+b[2]+b[3]) - (a[0]+a[1]+a[2]+a[3]));

    return loadavg;
}

#endif //MININGSO_CPU_H

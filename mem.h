//
// Created by jeremymolina on 11/4/19.
//



#ifndef MININGSO_MEM_H
#define MININGSO_MEM_H

#include <sys/resource.h>
#include <stdio.h>

int getMemUsage() {
    struct rusage r_usage;
    getrusage(RUSAGE_SELF,&r_usage);

    return r_usage.ru_maxrss;
}

#endif //MININGSO_MEM_H

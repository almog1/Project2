//
// Created by almogg on 1/3/19.
//

#ifndef PROJECT2_FILECACHEMANAGER_H
#define PROJECT2_FILECACHEMANAGER_H

#include "CacheManager.h"

template <class P,class S>
//cache manager of files
class FileCacheManager : public CacheManager<P,S> {
    bool isSolutionExist(P prob);

    S getSolution(P prob);

    bool saveSolution(P prob, S sol);
};

#endif //PROJECT2_FILECACHEMANAGER_H

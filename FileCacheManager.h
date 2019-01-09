//
// Created by almogg on 1/3/19.
//

#ifndef PROJECT2_FILECACHEMANAGER_H
#define PROJECT2_FILECACHEMANAGER_H

#include "CacheManager.h"
#include <string>
using namespace std;

template <class P,class S>
//cache manager of files
class FileCacheManager : public CacheManager<P,S>{
public:
    FileCacheManager();
    bool isSolutionExist(P prob) override;
    S getSolution(P prob) override;
    bool saveSolution(P prob, S sol) override;
};

#endif //PROJECT2_FILECACHEMANAGER_H

//
// Created by almogg on 1/3/19.
//

#ifndef PROJECT2_CACHEMANAGER_H
#define PROJECT2_CACHEMANAGER_H

//interface for caching the solutions
class CacheManager {
    //check if the solution exist in this cache
    virtual bool isSoultionExist();

    //return the solution for this problem
    template<typename Solution>
    Solution getSolution();
    //todo check why cant virtual

    //save the specific solution in this cache
    template<typename Solution>
    void saveSolution();

};

#endif //PROJECT2_CACHEMANAGER_H

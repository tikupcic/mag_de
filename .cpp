//
// Created by Timi on 5. 07. 2017.
//
#pragma once

template<class T>
void destroyVar(T var) {
    delete var;
}

template<class T>
void destroyArray(T var) {
    delete[] var;
}

template<class T>
void destroy2dArray(T var) {
    for (int i = 0; i < sizeof(var) / sizeof(T); i++) {
        delete[] var[i];
    }
    delete[] var;
}

template<class T>
void destroy3dArray(T var) {
    for (int i = 0; i != sizeof(var) / sizeof(T); ++i) {
        for (int j = 0; j != sizeof(var[i]) / sizeof(typeof(var[i])); ++j) {
            delete[] var[i][j];
        }
        delete[] var[i];
    }
    delete[] var;
}
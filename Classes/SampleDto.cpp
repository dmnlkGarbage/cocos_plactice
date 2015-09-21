//
//  SampleDto.cpp
//  SampleCocos
//
//  Created by dmnlk on 2015/09/22.
//
//

#include "SampleDto.h"
#include <iostream>

using std::cout;
SampleDto::SampleDto():count(0) {
    cout <<  "sampledto const\n";
}

SampleDto::~SampleDto() {
    cout << "sample dto dest\n";
}

int SampleDto::load() {
    cout << "loading\n";
    count++;
    return count;
}
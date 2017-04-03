//
// Created by kirill on 03.04.17.
//

//#include "StdAfx.h"
#include "NetActivity.h"
#include <iostream>

using namespace std;

NetActivity::NetActivity(void)
{}


NetActivity::~NetActivity(void)
{}

// Puts the na network actitivty to the out stream
// The format is: "mary218 msdn.com"
ostream & operator<<(ostream & out, const NetActivity & na)
{
    out << na.m_user << " " << na.m_host;
    return out;
}

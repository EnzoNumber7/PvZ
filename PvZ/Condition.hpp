#pragma once

class Entity;

class Condition 
{
public:
    virtual bool Test(Entity* entity) = 0;
};

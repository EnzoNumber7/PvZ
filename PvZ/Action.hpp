#pragma once

class Entity;

class Action
{
public:
    virtual void Start(Entity* entity) = 0;
    virtual void Update(Entity* entity) = 0;
    virtual void End(Entity* entity) = 0;
};

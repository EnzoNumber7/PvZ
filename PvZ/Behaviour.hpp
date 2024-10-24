#pragma once

#include "Context.hpp"
#include <map>
#include <vector>

class Action;
class Entity;
class Transition;

class Behaviour
{
    std::map<Context::State, std::vector<Action*>> mActions;
    std::map<Context::State, std::vector<Transition*>> mTransitions;
public:
    Behaviour();
    ~Behaviour();

    void Start(Entity* entity);
    void Update(Entity* entity);
    void End(Entity* entity);

    void AddAction(Context::State key, Action* value);
    void AddTransition(Context::State key, Transition* value);
};

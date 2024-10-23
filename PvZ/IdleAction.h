#pragma once
#include "Action.hpp"

class IdleAction : Action
{
public:
    void Start(Plant* Plant) override;
    void Update(Plant* Plant) override;
    void End(Plant* Plant) override;
};


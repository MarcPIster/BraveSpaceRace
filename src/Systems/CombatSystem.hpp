#ifndef BRAVESPACERACE_COMBATSYSTEM_HPP
#define BRAVESPACERACE_COMBATSYSTEM_HPP

#include "../ECS/ISystem.hpp"


class CombatSystem : public ISystem {
public:
    CombatSystem(std::shared_ptr<EntityManager> t_em);
    ~CombatSystem();

    virtual void update();
    virtual void updateData(SystemData &t_data);
};



#endif//BRAVESPACERACE_COMBATSYSTEM_HPP

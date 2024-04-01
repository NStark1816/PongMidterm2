#pragma once
#include <string>
#include <vector>
#include <Canis/ScriptableEntity.hpp>
#include <Canis/ECS/Components/RectTransformComponent.hpp>

class ScoreDisplay : public Canis::ScriptableEntity
{
private:
   
public:
    
    void OnCreate()
    {
        
    }

    void OnReady()
    {
        
    }
    
    void OnDestroy()
    {

    }

    void OnUpdate(float _dt)
    {
        using namespace Canis;
    }
};

bool DecodeScoreDisplay(const std::string &_name, Canis::Entity &_entity)
{
    if (_name == "ScoreDisplay")
    {
        Canis::ScriptComponent scriptComponent = {};
        scriptComponent.Bind<ScoreDisplay>();
        _entity.AddComponent<Canis::ScriptComponent>(scriptComponent);
        return true;
    }
    return false;
}
#pragma once
#include <string>
#include <vector>
#include <Canis/ScriptableEntity.hpp>
#include <Canis/ECS/Components/RectTransformComponent.hpp>

class Background : public Canis::ScriptableEntity
{
private:
    glm::vec2   m_direction;
    float       m_speed;
    float       m_timeBetweenAnimation = 3.0f;
    float       m_countDown = 0.0f;
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
        Canis::Entity leftPaddle = entity.GetEntityWithTag("LEFTPADDLE");
        Canis::Entity rightPaddle = entity.GetEntityWithTag("RIGHTPADDLE");
        auto& rectLeftPaddle = leftPaddle.GetComponent<Canis::RectTransformComponent>();
        auto& rectRightPaddle = rightPaddle.GetComponent<Canis::RectTransformComponent>();
        auto& colorLeftPaddle = leftPaddle.GetComponent<Canis::ColorComponent>();
        auto& rect = GetComponent<Canis::RectTransformComponent>();
        auto& colorComp = GetComponent<Canis::ColorComponent>();

        
    }
};

bool DecodeBackground(const std::string &_name, Canis::Entity &_entity)
{
    if (_name == "Background")
    {
        Canis::ScriptComponent scriptComponent = {};
        scriptComponent.Bind<Background>();
        _entity.AddComponent<Canis::ScriptComponent>(scriptComponent);
        return true;
    }
    return false;
}